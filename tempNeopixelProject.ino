#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>
#include <Adafruit_NeoPixel.h>

const char* ssid = "The one";
const char* password = "Wataruwatari5";

#define LED_PIN 5
#define LED_NUM 60

Adafruit_NeoPixel neo(LED_NUM, LED_PIN, NEO_GRB + NEO_KHZ800);

WebServer server(80);

// ===== Global state =====
bool ledStatusGlobal = false;
int brightnessGlobal = 100;
String colorStrGlobal = "white";
String effectGlobal = "normal";
bool christmasState = false;
unsigned long lastChristmasTime = 0;
const int christmasInterval = 400;

// rainbow control
uint8_t rainbowHue = 0;
unsigned long lastEffectTime = 0;

// blinking control
bool blinkState = false;
unsigned long lastBlinkTime = 0;
const int blinkInterval = 500; // ms

uint32_t hexToColor(String hex) {
  if (hex[0] == '#') hex.remove(0, 1);

  long number = strtol(hex.c_str(), NULL, 16);

  uint8_t r = (number >> 16) & 0xFF;
  uint8_t g = (number >> 8) & 0xFF;
  uint8_t b = number & 0xFF;

  return neo.Color(r, g, b);
}

// Apply LED state (NO direct show in blinky mode)
void applyLED(bool ledState, int brightness, String colorStr, String effect, const char* source) {
  ledStatusGlobal = ledState;
  brightnessGlobal = constrain(brightness, 0, 100);
  colorStrGlobal = colorStr;
  effectGlobal = effect;

  Serial.print("Updated state from ");
  Serial.println(source);
}

// render LED output
void renderLED(bool on) {
  uint32_t baseColor = hexToColor(colorStrGlobal);

  uint8_t r = (baseColor >> 16) & 0xFF;
  uint8_t g = (baseColor >> 8) & 0xFF;
  uint8_t b = baseColor & 0xFF;

  r = (r * brightnessGlobal) / 100;
  g = (g * brightnessGlobal) / 100;
  b = (b * brightnessGlobal) / 100;

  uint32_t finalColor = neo.Color(r, g, b);

  if (on) {
    for (int i = 0; i < LED_NUM; i++) {
      neo.setPixelColor(i, finalColor);
    }
  } else {
    for (int i = 0; i < LED_NUM; i++) {
      neo.setPixelColor(i, 0);
    }
  }

  neo.show();
}

// POST JSON handler
void handleData() {
  if (!server.hasArg("plain")) {
    server.send(400, "application/json", "{\"error\":\"no body\"}");
    return;
  }

  String body = server.arg("plain");

  StaticJsonDocument<256> doc;
  DeserializationError error = deserializeJson(doc, body);

  if (error) {
    server.send(400, "application/json", "{\"error\":\"invalid json\"}");
    return;
  }

  bool ledState = doc["ledStatus"] | false;
  int brightness = doc["brightness"] | 100;
  String colorStr = doc["color"] | "white";
  String effect = doc["effect"] | "normal";

  applyLED(ledState, brightness, colorStr, effect, "POST");

  server.send(200, "application/json", "{\"status\":\"ok\"}");
}

// GET handler
void handleGet() {
  String json =
    "{"
    "\"brightness\":" + String(brightnessGlobal) + "," +
    "\"color\":\"" + colorStrGlobal + "\"," +
    "\"effect\":\"" + effectGlobal + "\"," +
    "\"ledStatus\":" + String(ledStatusGlobal ? "true" : "false") +
    "}";

  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(115200);

  neo.begin();
  neo.show();

  WiFi.begin(ssid, password);
  Serial.println(WiFi.localIP());

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.println(WiFi.localIP());

  server.on("/led", HTTP_POST, handleData);
  server.on("/led", HTTP_GET, handleGet);

  server.begin();
}

void loop() {
  server.handleClient();

  if (!ledStatusGlobal) {
    renderLED(false);
    return;
  }

  unsigned long now = millis();

  if (effectGlobal == "normal") {
    renderLED(true);
  }

  else if (effectGlobal == "blinky") {
    if (now - lastBlinkTime >= blinkInterval) {
      lastBlinkTime = now;
      blinkState = !blinkState;
      renderLED(blinkState);
    }
  }

  else if (effectGlobal == "rainbow") {
    if (now - lastEffectTime >= 20) {
      lastEffectTime = now;

      rainbowHue += 2;

      for (int i = 0; i < LED_NUM; i++) {
        uint32_t color = neo.gamma32(neo.ColorHSV(rainbowHue * 256));
        neo.setPixelColor(i, color);
      }

      neo.show();
    }
  }
  else if (effectGlobal == "christmas") {
    unsigned long now = millis();

    if (now - lastChristmasTime >= christmasInterval) {
      lastChristmasTime = now;
      christmasState = !christmasState;

      uint32_t baseColor = hexToColor(colorStrGlobal);

      uint8_t r = (baseColor >> 16) & 0xFF;
      uint8_t g = (baseColor >> 8) & 0xFF;
      uint8_t b = baseColor & 0xFF;

      r = (r * brightnessGlobal) / 100;
      g = (g * brightnessGlobal) / 100;
      b = (b * brightnessGlobal) / 100;

      uint32_t finalColor = neo.Color(r, g, b);

      for (int i = 0; i < LED_NUM; i++) {

        bool isOdd = (i % 2 == 1);

        if (christmasState) {
          // state A: odd ON, even OFF
          neo.setPixelColor(i, isOdd ? finalColor : 0);
        } else {
          // state B: even ON, odd OFF
          neo.setPixelColor(i, isOdd ? 0 : finalColor);
        }
      }

      neo.show();
    }
  }
}
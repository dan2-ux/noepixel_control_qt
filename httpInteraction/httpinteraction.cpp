#include <httpinteraction.h>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include <QDebug>

HttpInteraction::HttpInteraction(QObject *parent):
    QObject(parent), m_ledStatus(false), m_color("white"), m_brightness(100) {}

bool HttpInteraction::ledStatus() const{
    return m_ledStatus;
}

QString HttpInteraction::color() const{
    return m_color;
}

int HttpInteraction::brightness() const{
    return m_brightness;
}

QString HttpInteraction::effect() const{
    return m_effect;
}

void HttpInteraction::setLedStatus(bool ledStatus){
    if(m_ledStatus != ledStatus){
        m_ledStatus = ledStatus;
        emit ledStatusChanged();
    }
}

void HttpInteraction::setColor(QString color){
    if(m_color != color){
        m_color = color;
        emit colorChanged();
    }
}

void HttpInteraction::setBrightness(int brightness){
    if(m_brightness != brightness){
        m_brightness = brightness;
        emit brightnessChanged();
    }
}

void HttpInteraction::setEffect(QString e){
    if(m_effect != e){
        m_effect = e;
        emit effectChanged();
    }
}

void HttpInteraction::changeLedStatus(bool ls){
    setLedStatus(ls);
}
void HttpInteraction::changeColor(QString c){
    setColor(c);
}
void HttpInteraction::changeBrightness(int b){
    setBrightness(b);
}
void HttpInteraction::changeEffect(QString e){
    setEffect(e);
}

void HttpInteraction::getJson(){
    QUrl url("http://192.168.100.85/led");
    QNetworkRequest req(url);

    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = m_man.get(req);

    connect(reply, &QNetworkReply::finished, this, [this, reply](){
        if(reply->error() == QNetworkReply::NoError){
            QByteArray data = reply->readAll();
            QJsonDocument doc = QJsonDocument::fromJson(data);

            QJsonObject rawJson = doc.object();

            setLedStatus(rawJson["ledStatus"].toBool());
            setColor(rawJson["color"].toString());
            setBrightness(rawJson["brightness"].toInt());
            setEffect(rawJson["effect"].toString());
            qDebug() << "Data: " << rawJson;
        }
        else{
            qDebug() << "Error: " << reply->errorString();
        }
        reply->deleteLater();
    });

}

void HttpInteraction::postJson(){
    QUrl url("http://192.168.100.85/led");
    QNetworkRequest req(url);

    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["ledStatus"] = m_ledStatus;
    json["brightness"] = m_brightness;
    json["color"] = m_color;
    json["effect"] = m_effect;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    QNetworkReply *reply = m_man.post(req, data);
    connect(reply, &QNetworkReply::finished,
            this, [this, reply]()
            {
                if (reply->error() == QNetworkReply::NoError)
                {
                    getJson();
                    emit ledStatusChanged();
                    emit colorChanged();
                    emit brightnessChanged();
                }
                else
                {
                    qDebug() << "Error:" << reply->errorString();
                }

                reply->deleteLater();
            });
}
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs
import QtQuick.Window

ApplicationWindow{
    id: mainWindow;
    width: 600;
    height: 600;
    visible: true;
    title: "Neo-Pixel Controler App"

    Component.onCompleted: {
        httpInteraction.getJson();
    }

    Rectangle{
        width: 400;
        height: 500;
        radius: 50
        anchors.centerIn: parent;
        color: "grey";

        ColumnLayout{
            spacing: 30;
            anchors.fill: parent;

            Label {
                Layout.topMargin: 50;
                text: "Neo-Pixel Setup"
                font.bold: true;
                font.pixelSize: 40;
                font.family: "Times New Roman"
                Layout.alignment: Qt.AlignCenter;
            }
            Button {
                text: httpInteraction.effect
                font.bold: true
                font.family: "Times New Roman"
                font.pixelSize: 15
                Layout.alignment: Qt.AlignCenter

                onClicked: menu.open()
                Layout.preferredHeight: 50
                Layout.preferredWidth: 150

                Menu {
                    id: menu

                    MenuItem {
                        text: "normal"
                        font.bold: true
                        font.family: "Times New Roman"
                        font.pixelSize: 15
                        onClicked:  {
                            httpInteraction.changeEffect("normal")
                            httpInteraction.postJson();
                        }
                    }

                    MenuItem {
                        text: "blinky"
                        font.bold: true
                        font.family: "Times New Roman"
                        font.pixelSize: 15
                        onClicked:  {
                            httpInteraction.changeEffect("blinky")
                            httpInteraction.postJson();
                        }
                    }

                    MenuItem {
                        text: "rainbow"
                        font.bold: true
                        font.family: "Times New Roman"
                        font.pixelSize: 15
                        onClicked:  {
                            httpInteraction.changeEffect("rainbow")
                            httpInteraction.postJson();
                        }
                    }

                    MenuItem {
                        text: "christmas"
                        font.bold: true
                        font.family: "Times New Roman"
                        font.pixelSize: 15
                        onClicked:  {
                            httpInteraction.changeEffect("christmas")
                            httpInteraction.postJson();
                        }
                    }
                }
            }
            Rectangle{
                width: parent.width - 50;
                height: 100;
                color: httpInteraction.color;
                Layout.alignment: Qt.AlignCenter
                radius: 50;

                MouseArea{
                    anchors.fill: parent;
                    hoverEnabled: true;
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        colorD.open();
                    }
                }
            }
            ColorDialog {
                id: colorD;
                title: "Pick the Color";

                onAccepted: {
                    httpInteraction.changeColor(colorD.selectedColor.toString());
                    httpInteraction.postJson();
                }
            }

            Button{
                id: stateButton;
                width: 80;
                height: 40;
                text: httpInteraction.ledStatus ? "Led On" : "Led Off";
                Layout.alignment: Qt.AlignHCenter;

                contentItem: Text {
                    text: stateButton.text;
                    color: httpInteraction.ledStatus ? "lightgreen" : "lightcoral";
                    font.bold: true;
                    font.family: "Times New Roman"
                    font.pixelSize: 20;
                    horizontalAlignment: Text.AlignHCenter;
                    verticalAlignment: Text.AlignVCenter;
                }
                background: Rectangle{
                    radius: 5;
                }
                onClicked: {
                    httpInteraction.changeLedStatus(!httpInteraction.ledStatus);
                    httpInteraction.postJson();
                }
            }

            ColumnLayout{
                height: 100;
                Layout.alignment: Qt.AlignCenter
                Layout.bottomMargin: 100;
                Text{
                    text: "Brightness: " + brightnessSeclector.value
                    Layout.alignment: Qt.AlignCenter;
                    font.bold: true
                    font.pixelSize: 30;
                    font.family: "Times New Roman"
                }

                Slider{
                    from: 0
                    to: 100
                    Layout.fillWidth: true
                    Layout.leftMargin: 50;
                    Layout.rightMargin: 50;
                    value: httpInteraction.brightness
                    focusPolicy: Qt.NoFocus
                    id: brightnessSeclector
                    Layout.alignment: Qt.AlignCenter;
                    stepSize: 10;
                    onPressedChanged: {
                        httpInteraction.changeBrightness(brightnessSeclector.value)
                        httpInteraction.postJson();
                    }
                }
            }
        }
    }
}


#pragma once

#include <QObject>
#include <QNetworkAccessManager>

class HttpInteraction : public QObject{
    Q_OBJECT
    Q_PROPERTY(bool ledStatus READ ledStatus WRITE setLedStatus NOTIFY ledStatusChanged)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged FINAL)
    Q_PROPERTY(int brightness READ brightness  WRITE setBrightness  NOTIFY brightnessChanged FINAL)
    Q_PROPERTY(QString effect READ effect WRITE setEffect NOTIFY effectChanged FINAL)

public:
    explicit HttpInteraction(QObject *parent = nullptr);

    bool ledStatus() const;
    QString color() const;
    int brightness() const;
    QString effect() const;

    void setLedStatus(bool ledStatus);
    void setColor(QString color);
    void setBrightness(int brightness);
    void setEffect(QString effect);

    Q_INVOKABLE void getJson();
    Q_INVOKABLE void postJson();
    Q_INVOKABLE void changeLedStatus(bool ls);
    Q_INVOKABLE void changeColor(QString c);
    Q_INVOKABLE void changeBrightness(int b);
    Q_INVOKABLE void changeEffect(QString e);

signals:
    void ledStatusChanged();
    void colorChanged();
    void brightnessChanged();
    void effectChanged();

private:
    bool m_ledStatus;
    QString m_effect;
    QString m_color;
    int m_brightness;
    QNetworkAccessManager m_man;
};

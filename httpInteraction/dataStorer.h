#pragma once

#include <QObject>
#include <QSettings>

class DataStorer : public QObject {
    Q_OBJECT;

public:
    explicit DataStorer(QObject *parent = nullptr);

    Q_INVOKABLE QString getURL(){
        QSettings settings;
        return settings.value("webURL", "http://192.168.100.84/led").toString();
    }
};

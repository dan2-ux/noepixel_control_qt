#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <httpinteraction.h>
#include <QQmlContext>
#include <QIcon>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon("Q:/Qt Projects/httpInteraction/uk_flag.png"));

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    HttpInteraction httpInteraction;

    engine.rootContext()->setContextProperty("httpInteraction", &httpInteraction);

    engine.loadFromModule("httpInteraction", "Main");

    return QCoreApplication::exec();
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "dirhelper.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<DirHelper>("me.kandz.dirhelper", 1, 0, "DirHelper");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/CPPQML-ImageViewer/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <cppsignalsender.h>
#include<QQmlContext>
#include<cppsignalreciver.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    cppsignalreciver reciver;

    engine.rootContext() -> setContextProperty("ITI_Reciver",&reciver);


    cppSignalSender sender;
    engine.rootContext() -> setContextProperty("ITI",&sender);


    const QUrl url(QStringLiteral("qrc:/CPPtoQml/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

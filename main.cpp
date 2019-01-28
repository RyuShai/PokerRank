#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtNetwork/QNetworkInterface>
#include "gamedatacontroler.h"
#include "gamedatamodel.h"

QString getMacAddress()
{
    foreach(QNetworkInterface interface, QNetworkInterface::allInterfaces())
    {
        // Return only the first non-loopback MAC Address
        if (!(interface.flags() & QNetworkInterface::IsLoopBack))
            return interface.hardwareAddress();
        QString text = interface.hardwareAddress();
        qDebug() << text;
    }
    return QString();
}
int main(int argc, char *argv[])
{
    GameDataControler controller;
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    if(getMacAddress()!="70:85:C2:89:01:CD")
        return -1;

    QQmlApplicationEngine engine;

    qmlRegisterType<GameDataModel>("GameModel",1,0,"GameModel");
    engine.rootContext()->setContextProperty("controller",&controller);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

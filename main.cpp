#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "gamedatacontroler.h"
#include "gamedatamodel.h"

int main(int argc, char *argv[])
{
    GameDataControler controller;
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<GameDataModel>("GameModel",1,0,"GameModel");
    engine.rootContext()->setContextProperty("controller",&controller);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

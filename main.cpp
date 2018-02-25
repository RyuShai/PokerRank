#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "playercontroller.h"
#include <QQmlContext>
#include <QDebug>
#include <QtWidgets/QApplication>
#include <QList>
#include <QDir>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    qDebug()<<"PATH: "<<QDir::currentPath();
    QApplication app(argc, argv);
    PlayerController player;
//    QList<QObject*> myModel;
//    for(int i=0; i<player.playerData().size();i++)
//    {
//        myModel.append(player.playerData().at(i));
//    }

//    qDebug()<<"debug: "<<myModel.at(0)->getValue().at(0);
    QQmlApplicationEngine engine;
//    engine.rootContext()->setContextProperty("myModel",QVariant::fromValue(player.playerData()));
    engine.rootContext()->setContextProperty("playerControl",&player);
//    qDebug()<<player->getValue().size();
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

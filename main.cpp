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
    QList<PlayerModel*> listPlayer;
    QList<QObject*> myModel;
    listPlayer.append(new PlayerModel("test1", {1,2,3},{QDate::currentDate()}));
    listPlayer.append(new PlayerModel("test2", {4,5,6},{QDate::currentDate()}));

    for(int i=0; i<player.playerData().size();i++)
    {
        myModel.append(player.playerData().at(i));
    }

//    qDebug()<<"debug: "<<myModel.at(0)->getValue().at(0);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("myModel",QVariant::fromValue(myModel));
//    qDebug()<<player->getValue().size();
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H
#include "playermodel.h"
#include <QObject>
#include <QList>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>

class PlayerController :public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> playerData READ playerData WRITE setPlayerData NOTIFY playerDataChanged)
    Q_PROPERTY(QString game READ game WRITE setGame NOTIFY gameChanged)
public:
    Q_INVOKABLE void InsertPlayerValue(QString playerName, QString playerValue,QString game);
    Q_INVOKABLE void InsertPlayerName(QString playerName);
    Q_INVOKABLE void DeletePlayer(int index);
    Q_INVOKABLE void AddPlayer(QString playerName);
    PlayerController();
    void setPlayerData(QList<QObject*> newPlayer);
    QList<QObject*> playerData(){return myModel;}
    //load player data from sqlite
    void LoadPlayerModel(QString path);
    void LoadListModel();
    QString game();
    void setGame(QString  value){_game =  value;}

signals:
    void playerDataChanged();
    void gameChanged();
private:
    QSqlDatabase mDatabase;
    QList<QString> listPlayerName;
    QList<QList<int>> listPlayerValue;
    QList<QList<QString>> listPlayerDate;
    QList<QList<int>> listPlayerGame;
    QList<PlayerModel*> listModel;
    QList<QObject*> myModel;
    QString path2Database;
    QString _game;

    void LoadPlayerName();
    void LoadPlayerValue();
    void LoadPlayerDate();
    void LoadPlayerGame();


};

#endif // PLAYERCONTROLLER_H

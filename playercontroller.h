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
public:
    Q_INVOKABLE void InsertPlayerValue(QString playerName, int playerValue,int game);
    Q_INVOKABLE void InsertPlayerName(QString playerName);
    PlayerController();
    void setPlayerData(QList<QObject*> newPlayer);
    QList<QObject*> playerData(){return myModel;}
    //load player data from sqlite
    void LoadPlayerModel(QString path);
    void LoadListModel();
    void AddPlayer2Database(QString playeName, int playerValue, int game);

signals:
    void playerDataChanged();
private:
    QSqlDatabase mDatabase;
    QList<QString> listPlayerName;
    QList<QList<int>> listPlayerValue;
    QList<QList<QString>> listPlayerDate;
    QList<PlayerModel*> listModel;
    QList<QObject*> myModel;
    QString path2Database;

    void LoadPlayerName();
    void LoadPlayerValue();
    void LoadPlayerDate();


};

#endif // PLAYERCONTROLLER_H

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
//    Q_PROPERTY(QList<PlayerModel> playerData READ playerData WRITE setPlayerData NOTIFY playerDataChanged)
public:
    Q_INVOKABLE void InsertPlayerValue();
    PlayerController();
    void setPlayerData(PlayerModel* newPlayer);
    QList<PlayerModel*> playerData(){return listModel;}
    //load player data from sqlite
    void LoadPlayerModel(QString path);
    void LoadListModel();


signals:
    void playerDataChanged();
private:
    QSqlDatabase mDatabase;
    QList<QString> listPlayerName;
    QList<QList<int>> listPlayerValue;
    QList<QList<QDate>> listPlayerDate;
    QList<PlayerModel*> listModel;

    void LoadPlayerName();
    void LoadPlayerValue();
    void LoadPlayerDate();

};

#endif // PLAYERCONTROLLER_H

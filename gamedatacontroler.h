#ifndef GAMEDATACONTROLER_H
#define GAMEDATACONTROLER_H

#include <QObject>
#include <QList>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QDate>

#define db(msg) qDebug()<<Q_FUNC_INFO<<msg
struct PlayerInfo{
    QString name;
    int chip;
    QDate date;
    int gameCount;
};
class GameDataControler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int playerCount READ playerCount NOTIFY playerCountChanged)
public:

    explicit GameDataControler(QObject *parent = nullptr);
    Q_INVOKABLE void loadDataModel(QString databaseName = "");

    Q_INVOKABLE QString getPlayerName(int pos);

    Q_INVOKABLE void updateDayGame(QString playerName, int totalValue);
    int reloadPlayerCount();
    int playerCount(){return listPlayername.count();}
    QList<PlayerInfo> getPlayerData() const;

signals:
    void playerCountChanged();
public slots:
private:
    QSqlDatabase mDatabase;
    QList<PlayerInfo> playerData;
    QList<PlayerInfo> dayGameData;
    QString databaseName;
    QList<QString> listPlayername;
    int lastGameCount=0;
};

#endif // GAMEDATACONTROLER_H

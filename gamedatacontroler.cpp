#include "gamedatacontroler.h"

GameDataControler::GameDataControler(QObject *parent) : QObject(parent)
{
    mDatabase = QSqlDatabase::addDatabase("QSQLITE");
    databaseName = "/home/ryu/Documents/Project/Qt/Ranker/PlayerData.db";
    loadDataModel();

}

void GameDataControler::loadDataModel(QString databaseName)
{
    if(databaseName=="")
    {
        mDatabase.setDatabaseName(this->databaseName);
    }
    else{
        mDatabase.setDatabaseName(databaseName);
    }

    if(mDatabase.open()){
        db("database opened");
        QString sqlCmd ="SELECT * FROM PlayerValue";
        QSqlQuery query(sqlCmd);
        PlayerInfo pi;
        while(query.next())
        {
            pi.name = query.value("name").toString();
            pi.chip = query.value("value").toInt();
            pi.date = query.value("date").toDate();
            pi.gameCount = query.value("Game").toInt();
            if(pi.gameCount > lastGameCount)
                lastGameCount= pi.gameCount;
            playerData.push_back(pi);
//            db(pi.name<<" "<<pi.chip<<" "<<pi.date<<" "<<pi.gameCount);

        }
        db("player count: "<<reloadPlayerCount());
        mDatabase.close();
    }
    else{
        db("cant open database");
    }
}

QString GameDataControler::getPlayerName(int pos)
{
    return listPlayername.at(pos);
}

void GameDataControler::updateDayGame(QString playerName, int totalValue)
{
    db("player: "<<playerName);
    foreach(PlayerInfo item,dayGameData)
    {
        if(item.name == playerName)
        {
            db("found old player");
            item.chip = totalValue;
            return;
        }
    }
    //not found name
    db("add new player");
    PlayerInfo newPlayer;
    newPlayer.name = playerName;
    newPlayer.chip = totalValue;
    newPlayer.date = QDate::currentDate();
    newPlayer.gameCount = lastGameCount+1;

    dayGameData.push_back(newPlayer);
}

int GameDataControler::reloadPlayerCount()
{
    listPlayername.clear();
    foreach (PlayerInfo pi, playerData) {
        bool existing = false;
        foreach (QString name, listPlayername)
        {
            if(pi.name == name)
            {
                existing = true;
                break;
            }
        }
        if(!existing)
            listPlayername.push_back(pi.name);
    }
    return listPlayername.count();
}

QList<PlayerInfo> GameDataControler::getPlayerData() const
{
    return playerData;
}



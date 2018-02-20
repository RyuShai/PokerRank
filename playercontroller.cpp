#include "playercontroller.h"



PlayerController::PlayerController()
{
    LoadPlayerModel("/home/ryu/Documents/Project/Qt/PokerRank/PlayerData");
}

void PlayerController::setPlayerData(PlayerModel* newPlayer)
{
    listModel.append(newPlayer);
}

void PlayerController::LoadPlayerModel(QString path)
{
    mDatabase = QSqlDatabase::addDatabase("QSQLITE");
    mDatabase.setDatabaseName(path);
    if(!mDatabase.open())
    {
        qDebug("open database failed");
    }
    else
    {
        qDebug("open database success");
        LoadPlayerName();
        LoadListModel();
        mDatabase.close();
    }
}

void PlayerController::LoadListModel()
{
    for(int i=0; i<listPlayerName.size();i++)
    {
        PlayerModel* playerModel = new PlayerModel();
        playerModel->setName(listPlayerName.at(i));
        playerModel->setValue(listPlayerValue.at(i));
        playerModel->setDate(listPlayerDate.at(i));
        listModel.append(playerModel);
    }
    qDebug()<<"listmodel size: "<<listModel.size();
}

void PlayerController::InsertPlayerValue()
{

}

void PlayerController::LoadPlayerName()
{
    QSqlQuery query("SELECT name FROM PlayerName");
    int idName = query.record().indexOf("name");
    //get
    while (query.next())
    {
       QString name = query.value(idName).toString();
       listPlayerName.append(name);
       qDebug() << name;
    }
    LoadPlayerValue();
    LoadPlayerDate();
}

void PlayerController::LoadPlayerValue()
{
    int numberPlayer = listPlayerName.size();
    for(int i=0; i<numberPlayer;i++)
    {
        QString sqlCmd ="SELECT value FROM PlayerValue WHERE name = '"+listPlayerName.at(i)+"'";
        QSqlQuery query(sqlCmd);
        QList<int> playerValue;
        while(query.next())
        {
            int value = query.value("value").toInt();
            playerValue.append(value);

        }
        listPlayerValue.append(playerValue);
    }

//    //test
//    for(int i= 0; i<listPlayerValue.size();i++)
//    {
//        QList<int> player = listPlayerValue.at(i);
//        QDebug dbug = qDebug();
//        for(int j=0; j<player.size();j++)
//        {
//            dbug<<player.at(j)<<" ";
//        }

    //    }
}

void PlayerController::LoadPlayerDate()
{
    for(int i=0; i<listPlayerName.size();i++)
    {
        QString sqlCmd ="SELECT date FROM PlayerValue WHERE name = '"+listPlayerName.at(i)+"'";
        QSqlQuery query(sqlCmd);
        QList<QDate> playerDate;
        while(query.next())
        {
            QDate value = query.value("date").toDate();
            playerDate.append(value);

        }
        listPlayerDate.append(playerDate);
    }

        //test
//        for(int i= 0; i<listPlayerDate.size();i++)
//        {
//            QList<QDate> player = listPlayerDate.at(i);
//            QDebug dbug = qDebug();
//            for(int j=0; j<player.size();j++)
//            {
//                dbug<<player.at(j).<<" ";
//            }

//            }
}

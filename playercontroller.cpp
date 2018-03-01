#include "playercontroller.h"
#include <QtGlobal>
#include <QSqlField>

void PlayerController::InsertPlayerValue(QString playeName, QString playerValue, QString game)
{
    mDatabase.setDatabaseName(path2Database);
    if(!mDatabase.open())
    {
        qDebug("open database failed");
    }
    else
    {
        qDebug("open database success");
        QString insertPlayerValue = "INSERT INTO PlayerValue (name,date,value,Game) VALUES ('"+playeName+"','"+QDate::currentDate().toString("yyyy-MM-dd")+"',"+playerValue+","+game+")";
////        QString insertPlayerValue = "INSERT INTO PlayerValue (name,date,value,Game) VALUES ('"+playeName+"','"+"2018-02-02"+"',"+playerValue+","+game+")";
        qDebug()<<insertPlayerValue;
        QSqlQuery query(insertPlayerValue);
        query.exec();
        mDatabase.close();
    }
}

void PlayerController::InsertPlayerName(QString playerName)
{
    mDatabase.setDatabaseName(path2Database);
    if(!mDatabase.open())
    {
        qDebug("open database failed");
    }
    else
    {
        qDebug("open database success");
        QString inserPlayerName = "INSERT INTO PlayerName (name) VALUES ('"+playerName+"')";
        qDebug()<<"inserPlayerName: "<<inserPlayerName;
        QSqlQuery query;
        query.prepare(inserPlayerName);
        if(query.exec())
        {
            qDebug()<<"insert name success";
            mDatabase.close();
            LoadPlayerModel(path2Database);

        }
        else
        {
            qDebug()<<"insert name fail";
        }

    }

}

void PlayerController::DeletePlayer(int index)
{
    myModel.removeAt(index);
    emit playerDataChanged();
}

void PlayerController::AddPlayer(QString playerName)
{
    qDebug()<<"current date: "<<QDate::currentDate().toString("yyyy-mm-dd");
    PlayerModel* player = new PlayerModel(playerName,{200},{QDate::currentDate().toString("yyyy-mm-dd")});
    myModel.append(player);
    emit playerDataChanged();
}

PlayerController::PlayerController()
{
    _game="-1";
    mDatabase = QSqlDatabase::addDatabase("QSQLITE");
#ifdef Q_OS_LINUX
    LoadPlayerModel("../PokerRank/PlayerData.db");
    #endif
#if defined(Q_OS_ANDROID)
    LoadPlayerModel("/storage/emulated/0/PlayerData.db");
#endif
    //    LoadPlayerModel(":/PlayerData.db");
}

void PlayerController::setPlayerData(QList<QObject *> newPlayer)
{

}


void PlayerController::LoadPlayerModel(QString path)
{
    qDebug()<<path;
    if(path2Database.isEmpty()||path2Database!=path)
    {
        path2Database = path;
    }

    myModel.clear();
    listPlayerDate.clear();
    listPlayerName.clear();
    listPlayerValue.clear();
    mDatabase.setDatabaseName(path2Database);
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
        playerModel->setGame(listPlayerGame.at(i));
//        listModel.append(playerModel);
        myModel.append(playerModel);
    }
//    setPlayerData(listModel);
    qDebug()<<"MyModel size: "<<myModel.size()<<endl;
   emit playerDataChanged();
}


QString PlayerController::game()
{
    mDatabase.setDatabaseName(path2Database);
    if(!mDatabase.open())
    {
        qDebug("open database failed");
    }
    else
    {
        qDebug("open database success");
        QString getMaxGame = "SELECT MAX(Game) FROM PlayerValue";
        QSqlQuery query;
//        QSqlRecord rec = query.record();
        query.exec(getMaxGame);
        query.first();
        qDebug()<<"collum: "<<query.value("MAX(Game)").toInt()+1;
        _game = QString::number((query.value("MAX(Game)").toInt())+1);
    }
    return _game;
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
//       qDebug() << name;
    }
    LoadPlayerValue();
    LoadPlayerDate();
    LoadPlayerGame();
}

void PlayerController::LoadPlayerValue()
{
    int numberPlayer = listPlayerName.size();
    for(int i=0; i<numberPlayer;i++)
    {
        QString sqlCmd ="SELECT value FROM PlayerValue WHERE name = '"+listPlayerName.at(i)+"' ORDER BY Game ASC";
        QSqlQuery query(sqlCmd);
        QList<int> playerValue;
        while(query.next())
        {
            int value = query.value("value").toInt();
            qDebug()<<"name: "+listPlayerName.at(i)+" VALUE: "<<value;
            playerValue.append(value);
//            qDebug()<<"value: "<<value;

        }
        listPlayerValue.append(playerValue);
    }

}

void PlayerController::LoadPlayerDate()
{
    for(int i=0; i<listPlayerName.size();i++)
    {
        QString sqlCmd ="SELECT date FROM PlayerValue WHERE name = '"+listPlayerName.at(i)+"' ORDER BY date ASC";
        QSqlQuery query(sqlCmd);
        QList<QString> playerDate;
        while(query.next())
        {
            QString value = query.value("date").toString();
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

void PlayerController::LoadPlayerGame()
{
    for(int i=0; i<listPlayerName.size();i++)
    {
        QString sqlCmd ="SELECT Game FROM PlayerValue WHERE name = '"+listPlayerName.at(i)+"' ORDER BY date ASC";
        QSqlQuery query(sqlCmd);
        QList<int> playerGame;
        while(query.next())
        {
            int value = query.value("Game").toInt();
            playerGame.append(value);

        }
        listPlayerGame.append(playerGame);
    }
}

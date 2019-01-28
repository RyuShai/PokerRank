#include "gamedatamodel.h"

GameDataModel::GameDataModel()
{

}

int GameDataModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid() || !mModel)
    {
        db("invalid");
        return 0;
    }

    return mModel->playerCount();
}

QVariant GameDataModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    const PlayerInfo item = mModel->getPlayerData().at(index.row());
    switch (role) {
      case PlayerName:
        return QVariant(item.name);
    case PlayerChip:
        return QVariant(item.chip);
    case PlayDate:
        return QVariant(item.date);
    case GameCount:
        return QVariant(item.gameCount);
    }
    return QVariant();
}

QHash<int, QByteArray> GameDataModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[PlayerName] = "name";
    names[PlayerChip]= "chip";
    names[PlayDate] = "date";
    names[GameCount] = "game";
    return names;
}

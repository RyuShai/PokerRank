#include "playermodel.h"
#include <QDebug>
PlayerModel::PlayerModel(QObject *parent) : QObject(parent)
{
}

PlayerModel::PlayerModel(QString name, QList<int> addvalue, QList<QDate> adddate)
{
    mname = name;
    value = addvalue;
    date = adddate;
}

void PlayerModel::setName(QString _name){mname = _name;}

void PlayerModel::setValue(QList<int> _value){value = _value;}

void PlayerModel::setDate(QList<QDate> _date)
{
    date = _date;
}



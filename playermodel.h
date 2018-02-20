#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#include <QObject>
#include <QList>
#include <QDate>

class PlayerModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QList<int> value READ getValue WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QList<QDate> date READ getDate WRITE setDate NOTIFY dateChanged)

public:
    explicit PlayerModel(QObject *parent = nullptr);
    PlayerModel(QString name, QList<int> addvalue, QList<QDate> adddate);
    QString getName(){return mname;}
    QList<int> getValue(){return value;}
    QList<QDate> getDate(){return date;}

    void setName(QString _name);
    void setValue(QList<int> _value);
    void addValue(int _value){value.append(_value);}
    void setDate(QList<QDate> _date);
signals:
    void valueChanged();
    void nameChanged();
    void dateChanged();

public slots:
private:
    QList<int> value;
    QString mname;
    QList<QDate> date;
};

#endif // PLAYERDATA_H

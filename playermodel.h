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
    Q_PROPERTY(QList<QString> date READ getDate WRITE setDate NOTIFY dateChanged)
    Q_PROPERTY(QList<int> game READ game WRITE setGame NOTIFY gameChanged)

public:
    explicit PlayerModel(QObject *parent = nullptr);
    PlayerModel(QString name, QList<int> addvalue, QList<QString> adddate);
    QString getName(){return mname;}
    QList<int> getValue(){return value;}
    QList<QString> getDate(){return date;}

    void setName(QString _name);
    void setValue(QList<int> _value);
    void addValue(int _value){value.append(_value);}
    void setDate(QList<QString> _date);
    QList<int> game(){return _game;}
    void setGame(QList<int> value){_game = value;}

signals:
    void valueChanged();
    void nameChanged();
    void dateChanged();
    void gameChanged();
public slots:
private:
    QList<int> value;
    QString mname;
    QList<QString> date;
    QList<int> _game;
};

#endif // PLAYERDATA_H

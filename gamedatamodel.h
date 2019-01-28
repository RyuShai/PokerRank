#ifndef GAMEDATAMODEL_H
#define GAMEDATAMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <gamedatacontroler.h>
class GameDataModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(GameDataControler *list READ list WRITE setList);
public:
    enum {
        PlayerName = Qt::UserRole,
        PlayerChip,
        PlayDate,
        GameCount
    };
    GameDataModel();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    GameDataControler *list() const{return mModel;}
    void setList(GameDataControler *list){mModel=list;}
private:
    GameDataControler* mModel;


};

#endif // GAMEDATAMODEL_H

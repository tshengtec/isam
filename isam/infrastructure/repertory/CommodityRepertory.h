#ifndef CommodityRepertory_H
#define CommodityRepertory_H

#include <QObject>
#include "Commodity.h"

class CommodityRepertory : public QObject
{
    Q_OBJECT
public:
    static CommodityRepertory* instance();
    QList<Commodity *> getList();

    Commodity *get(QString id);

    void add(Commodity *commodity);
    void remove(QString id);
    void update(Commodity *commodity);

private:
    CommodityRepertory();

private:
    void save();//Todo
    void reload();
    QString generateRandomId(); //Todo

private:
    static CommodityRepertory* _instance;
    QList<Commodity* > m_commodityList;
};

#endif // CommodityRepertory_H

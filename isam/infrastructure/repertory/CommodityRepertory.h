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

    void add(Commodity *musicBase);
    void remove(QString id);
    void update(Commodity *musicBase);

private:
    CommodityRepertory();

private:
    void save();
    void reload();
    QString generateRandomId();

private:
    static CommodityRepertory* _instance;
    QList<Commodity* > m_commodity;
};

#endif // CommodityRepertory_H

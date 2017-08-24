#ifndef SALESCOMMODITYSERVICE_H
#define SALESCOMMODITYSERVICE_H

#include "Commodity.h"

class SalesCommodityService : public QObject
{
    Q_OBJECT
public:
    SalesCommodityService();

    static SalesCommodityService* instance();

    QList<Commodity *> getList();
    Commodity *get(QString id);
    bool add(QString id);
    bool remove(QString id);
    bool update(Commodity *commodity);

signals:
    void listChanged();

private:
    static SalesCommodityService* _instance;
    QList<Commodity* > m_commodityList;
};

#endif // SALESCOMMODITYSERVICE_H

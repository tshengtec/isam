#ifndef COMMODITYSERVICE_H
#define COMMODITYSERVICE_H

#include "CommodityRepertory.h"

class CommodityService : public QObject
{
    Q_OBJECT
public:
    CommodityService();

    static CommodityService* instance();

    QList<Commodity *> getList();
    Commodity *get(QString id);

private:
    static CommodityService* _instance;
};

#endif // COMMODITYSERVICE_H

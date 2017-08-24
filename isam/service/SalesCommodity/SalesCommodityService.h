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

private:
    static SalesCommodityService* _instance;
};

#endif // SALESCOMMODITYSERVICE_H

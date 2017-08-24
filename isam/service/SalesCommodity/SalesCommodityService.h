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

    void isPendingOperation();
    void isGettingOperation();
    bool getIsPendingStatus();

private:
    void setList(QList<Commodity *> list);

signals:
    void listChanged();

private:
    static SalesCommodityService* _instance;
    QList<Commodity* > m_commodityList;
    QList<Commodity* > m_CommodityPendingList;
};

#endif // SALESCOMMODITYSERVICE_H

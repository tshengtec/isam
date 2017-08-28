#ifndef SALESCOMMODITYSERVICE_H
#define SALESCOMMODITYSERVICE_H

#include "Commodity.h"
#include "SalesNote.h"
/*
 * This class is used for the current sales of goods,
 * including the services provided by the register and the receipt.
*/
class SalesCommodityService : public QObject
{
    Q_OBJECT
public:
    SalesCommodityService();

    static SalesCommodityService* instance();

    QList<Commodity *> getList();
    QList<Commodity *> getPendingList();
    QList<SalesNote *> getSalesList();

    Commodity *get(QString id);
    bool add(QString id);
    bool remove(QString id);
    bool update(Commodity *commodity);
    bool removeAll(); //removeAll m_commodityList
    bool settleMent();

    QString onPendingOperation(); //Press the functionality, return Pending operating state.
    QString onGettingOperation(); //Press the functionality, return Getting operating state.

private:
    QList<Commodity* > copyList(QList<Commodity* > list);
    void removeList(QList<Commodity* >& removeList); // removeAll List

signals:
    void listChanged();

private:
    static SalesCommodityService* _instance;
    QList<Commodity* > m_commodityList;
    QList<Commodity* > m_CommodityPendingList;
    QList<SalesNote *> m_SalesList;
};

#endif // SALESCOMMODITYSERVICE_H

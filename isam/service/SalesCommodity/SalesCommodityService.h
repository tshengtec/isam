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

    /*A list of goods for which a sales document is obtained.(获取某一销售单据的商品列表)*/
    QList<Commodity *> getList();

    /*Get the list of commodity to be registered.*/
    QList<Commodity *> getPendingList();

    /*Get sales Documents.(获取销售单据列表)*/
    QList<SalesNote *> getSalesList();

    /*Get sales amount.*/
    float getSales();

    Commodity *get(QString id);
    bool add(QString id);
    bool remove(QString id);
    bool update(Commodity *commodity);
    bool removeAll(); //removeAll m_commodityList

    /*settlement operation*/
    bool settleMent();

    /*Press the functionality, return Pending operating state.*/
    QString onPendingOperation();

    /*Press the functionality, return Getting operating state.*/
    QString onGettingOperation();

private:
    QList<Commodity* > copyList(QList<Commodity* > list);
    void removeList(QList<Commodity* >& removeList); // removeAll List

signals:
    void listChanged();

private:
    static SalesCommodityService* _instance;
    QList<Commodity* > m_commodityList;
    QList<Commodity* > m_CommodityPendingList;
    /*Current sales items list documents.*/
    SalesNote* m_salesNote;
    /*Pending sales items list documents.*/
    SalesNote* m_pendingSalesNote;
    /*All sales list.*/
    QList<SalesNote *> m_SalesList;
};

#endif // SALESCOMMODITYSERVICE_H

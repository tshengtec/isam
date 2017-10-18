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
    SalesNote getSalesNote();

    /*Get the list of commodity to be registered.*/
    SalesNote getPendingSalesNote();

    /*Get sales Documents.(获取销售单据列表)*/
    QList<SalesNote *> getSalesList();

    /*Get sales amount.*/
    float getSales();

    /*Commodity id*/
    QVariantMap get(QString id);
    bool add(QString id); /*Commodity id*/
    bool remove(QString id); /*Commodity id*/
    bool update(QVariantMap commodity);
    bool removeAll(); /*removeAll m_commodityList*/

    /*settlement operation*/
    bool settleMent();

    /*Press the functionality, return Pending operating state.*/
    QString onPendingOperation();

    /*Press the functionality, return Getting operating state.*/
    QString onGettingOperation();

    bool postSellingDoc();

private:
    SalesNote* copySalesNote(SalesNote* salesNote);
    void removeSalesNote(SalesNote* salesNote);

signals:
    void listChanged();

private:
    static SalesCommodityService* _instance;
    /*Current sales items list documents.*/
    SalesNote m_salesNote;
    /*Pending sales items list documents.*/
    SalesNote m_pendingSalesNote;
    /*All sales list.*/
    QList<SalesNote *> m_SalesList;
};

#endif // SALESCOMMODITYSERVICE_H

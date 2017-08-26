#ifndef SALESQUERYSERVICE_H
#define SALESQUERYSERVICE_H
#include "CommodityRepertory.h"
#include "QueryCommodityCondition.h"

/*
 * This class is used for all commodity query functions.
*/
class SalesQueryService : public QObject
{
    Q_OBJECT
public:
    SalesQueryService();

    static SalesQueryService* instance();

    QList<Commodity *> getList();
    QList<Commodity *> getList(QueryCommodityCondition condition);

    Commodity *get(QString id);
    Commodity *getFuzzy(QString target); //Fuzzy Search

private:
    static SalesQueryService* _instance;
};

#endif // SALESQUERYSERVICE_H

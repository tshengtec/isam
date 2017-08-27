#ifndef COMMIDITYQUERYSERVICE_H
#define COMMIDITYQUERYSERVICE_H
#include "CommodityRepertory.h"
#include "QueryCommodityCondition.h"
#include "FuzzySearchTool.h"
/*
 * This class is used for all commodity query functions.
*/
class CommidityQueryService : public QObject
{
    Q_OBJECT
public:
    CommidityQueryService();

    static CommidityQueryService* instance();

    QList<Commodity *> getList();
    QList<Commodity *> getList(QueryCommodityCondition condition);

    Commodity *get(QString id);
    Commodity *getFuzzy(QString target); //Fuzzy Search

private:
    static CommidityQueryService* _instance;
    FuzzySearchTool m_fuzzySearchTool;
};

#endif // COMMIDITYQUERYSERVICE_H

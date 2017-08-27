#ifndef COMMIDITYQUERYSERVICE_H
#define COMMIDITYQUERYSERVICE_H
#include "CommodityRepertory.h"
#include "CommodityQueryCondition.h"
#include "FuzzySearchTool.h"
/*
 * This class is used for all commodity query functions.
*/
class CommodityQueryService : public QObject
{
    Q_OBJECT
public:
    CommodityQueryService();

    static CommodityQueryService* instance();

    QList<Commodity *> getList();
    QList<Commodity *> getList(CommodityQueryCondition condition);

    Commodity *get(QString id);
    Commodity *getFuzzy(QString target); //Fuzzy Search

private:
    static CommodityQueryService* _instance;
    FuzzySearchTool m_fuzzySearchTool;
};

#endif // COMMIDITYQUERYSERVICE_H

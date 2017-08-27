#ifndef SALESQUERYSERVICE_H
#define SALESQUERYSERVICE_H
#include "CommodityRepertory.h"
#include "FuzzySearchTool.h"
/*
 * This class is used for all commodity query functions.
*/
class SalesQueryService : public QObject
{
    Q_OBJECT
public:
    SalesQueryService();

    static SalesQueryService* instance();

private:
    static SalesQueryService* _instance;
};

#endif // SALESQUERYSERVICE_H

#include "SalesQueryService.h"
#include "SalesCommodityService.h"
#include <QDebug>
#include <QString>

SalesQueryService * SalesQueryService::_instance = NULL;


SalesQueryService::SalesQueryService()
{
}

SalesQueryService *SalesQueryService::instance()
{
    if (_instance == NULL) {
        _instance = new SalesQueryService();
    }
    return _instance;
}

QList<SalesNote *> SalesQueryService::getList(SalesQueryCondition condition)
{
    QList<SalesNote *> allSalesList = SalesCommodityService::instance()->getSalesList();
    return allSalesList;
}

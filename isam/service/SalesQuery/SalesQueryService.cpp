#include "SalesQueryService.h"

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

QList<Commodity *> SalesQueryService::getList()
{
    return CommodityRepertory::instance()->getList();
}

QList<Commodity *> SalesQueryService::getList(QueryCommodityCondition condition)
{

}

Commodity *SalesQueryService::get(QString id)
{
    return CommodityRepertory::instance()->get(id);
}

Commodity *SalesQueryService::getFuzzy(QString target)
{
    QList<Commodity *> list = this->getList();


}

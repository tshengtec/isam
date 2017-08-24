#include "SalesCommodityService.h"

SalesCommodityService * SalesCommodityService::_instance = NULL;


SalesCommodityService::SalesCommodityService()
{

}

SalesCommodityService *SalesCommodityService::instance()
{
    if (_instance == NULL) {
        _instance = new SalesCommodityService();
    }
    return _instance;
}

QList<Commodity *> SalesCommodityService::getList()
{
//    return CommodityRepertory::instance()->getList();
}

Commodity *SalesCommodityService::get(QString id)
{
//    return CommodityRepertory::instance()->get(id);
}

#include "CommodityService.h"

CommodityService * CommodityService::_instance = NULL;


CommodityService::CommodityService()
{

}

CommodityService *CommodityService::instance()
{
    if (_instance == NULL) {
        _instance = new CommodityService();
    }
    return _instance;
}

QList<Commodity *> CommodityService::getList()
{
    return CommodityRepertory::instance()->getList();
}

Commodity *CommodityService::get(QString id)
{
    return CommodityRepertory::instance()->get(id);
}

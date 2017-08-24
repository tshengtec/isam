#include "SalesCommodityService.h"
#include "CommodityRepertory.h"

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
    return m_commodityList;
}

Commodity *SalesCommodityService::get(QString id)
{
    for (int i = 0; i < m_commodityList.count(); i++) {
        if (m_commodityList.at(i)->getId() == id) {
            return m_commodityList.at(i);
        }
    }

    return NULL;
}

bool SalesCommodityService::add(QString id)
{
    Commodity *commodity = CommodityRepertory::instance()->get(id);
    if (commodity == NULL)
        return false;

    Commodity *newCommodity = new Commodity(commodity);
    m_commodityList.append(newCommodity);
    emit listChanged();
    return true;
}

bool SalesCommodityService::remove(QString id)
{
    for (int i = 0; i < m_commodityList.count(); i++) {
        if (m_commodityList.at(i)->getId() == id) {
            m_commodityList.removeAt(i);
            emit listChanged();
            return true;
        }
    }
    return false;
}

bool SalesCommodityService::update(Commodity *commodity)
{
    if (commodity == NULL)
        return false;

    for (int i = 0; i < m_commodityList.count(); i++) {
        Commodity * oldCommodity = m_commodityList.at(i);
        if (oldCommodity->getId() == commodity->getId()) {
            delete oldCommodity;
            m_commodityList.replace(i, commodity);
            emit listChanged();
            return true;
        }
    }

    return false;
}

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

QList<Commodity *> SalesCommodityService::copyList(QList<Commodity *> list)
{
    QList<Commodity *> newList = QList<Commodity *>();
    for (int i = 0; i < list.count(); i++) {
        Commodity *newCommodity = new Commodity(list.at(i));
        newList.append(newCommodity);
    }

    return newList;
}

void SalesCommodityService::removeList(QList<Commodity *>& removeList)
{
    while (removeList.count()) {
        Commodity * oldCommodity = removeList.last();
        removeList.removeLast();
        delete oldCommodity;
    }
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
        QString commodityId = m_commodityList.at(i)->getId();
        if (commodityId == id) {
            m_commodityList.removeAt(i);
            delete m_commodityList.at(i);
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

bool SalesCommodityService::removeAll()
{
    this->removeList(this->m_commodityList);
    emit listChanged();
    return true;
}

QString SalesCommodityService::onPendingOperation()
{
    if (m_commodityList.count() == 0)
        return "挂单失败，没有商品！";
    if (m_CommodityPendingList.count() != 0)
        return "挂单失败，<取单>未取走";

    m_CommodityPendingList = copyList(m_commodityList);
    this->removeList(m_commodityList);
    emit listChanged();
    return "";
}

QString SalesCommodityService::onGettingOperation()
{
    if (m_CommodityPendingList.count() == 0)
        return "取单失败，<取单>没有商品！";
    if (m_commodityList.count() != 0)
        return "取单失败，请先结算当前商品！";

    m_commodityList = copyList(m_CommodityPendingList);
    this->removeList(m_CommodityPendingList);
    emit listChanged();
    return "";
}

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

SalesNote SalesCommodityService::getSalesNote()
{
    return m_salesNote;
}

SalesNote SalesCommodityService::getPendingSalesNote()
{
    return m_pendingSalesNote;
}

QList<SalesNote *> SalesCommodityService::getSalesList()
{
    return m_SalesList;
}

float SalesCommodityService::getSales()
{
    float sales = 0;
    for (int i = 0; i < m_SalesList.count(); i++) {
        SalesNote* salesNote = m_SalesList.at(i);
        for (int j = 0; salesNote != NULL && j < salesNote->getList().count(); j++) {
            Commodity* commodity = salesNote->getList().at(j);
            if (commodity != NULL) {
                sales += commodity->getRetailPrice()*commodity->getCount();
            }
        }
    }
    return sales;
}

SalesNote *SalesCommodityService::copySalesNote(SalesNote *salesNote)
{
    SalesNote *newSalesNote = new SalesNote(salesNote);
    return newSalesNote;
}

void SalesCommodityService::removeSalesNote(SalesNote *salesNote)
{
    delete salesNote;
    salesNote = NULL;
}

Commodity *SalesCommodityService::get(QString id)
{
    Commodity* commodity = m_salesNote.get(id);
    return commodity;
}

bool SalesCommodityService::add(QString id)
{
    bool isSuccess = m_salesNote.add(id);
    if (isSuccess)
        emit listChanged();
    return isSuccess;
}

bool SalesCommodityService::remove(QString id)
{
    bool isSuccess = m_salesNote.remove(id);
    if (isSuccess)
        emit listChanged();
    return isSuccess;
}

bool SalesCommodityService::update(Commodity *commodity)
{
    bool isSuccess = m_salesNote.update(commodity);
    if (isSuccess)
        emit listChanged();
    return isSuccess;
}

bool SalesCommodityService::removeAll()
{
    bool isSuccess = m_salesNote.removeAll();
    if (isSuccess)
        emit listChanged();
    return isSuccess;
}

bool SalesCommodityService::settleMent()
{
    SalesNote* salesNote = new SalesNote(&m_salesNote);
    salesNote->setDateTime(QDateTime::currentDateTime());
    m_SalesList.append(salesNote);
    this->removeAll();
    return true;
}

QString SalesCommodityService::onPendingOperation()
{
    if (m_salesNote.getList().count() == 0)
        return "挂单失败，没有商品！";
    if (m_pendingSalesNote.getList().count() != 0)
        return "挂单失败，<取单>未取走";

    m_pendingSalesNote.setList(m_salesNote.copyMyselfList());
    m_salesNote.removeAll();
    emit listChanged();
    return "挂单成功";
}

QString SalesCommodityService::onGettingOperation()
{
    if (m_pendingSalesNote.getList().count() == 0)
        return "取单失败，<取单>没有商品！";
    if (m_salesNote.getList().count() != 0)
        return "取单失败，请先结算当前商品！";


    m_salesNote.setList(m_pendingSalesNote.copyMyselfList());
    m_pendingSalesNote.removeAll();
    emit listChanged();
    return "取单成功";
}

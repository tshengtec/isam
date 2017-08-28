#include "SalesCommodityEditModel.h"

SalesCommodityEditModel::SalesCommodityEditModel()
{
    m_errorStr = "";
}

bool SalesCommodityEditModel::add(QString id)
{
    return SalesCommodityService::instance()->add(id);
}

bool SalesCommodityEditModel::remove(QString id)
{
    return SalesCommodityService::instance()->remove(id);
}

bool SalesCommodityEditModel::removeAll()
{
    return SalesCommodityService::instance()->removeAll();
}

bool SalesCommodityEditModel::update(Commodity *commodity)
{
    return SalesCommodityService::instance()->update(commodity);
}

bool SalesCommodityEditModel::settleMent()
{
    if (SalesCommodityService::instance()->getList().count() > 0)
        return SalesCommodityService::instance()->settleMent();
    else
        return false;
}

void SalesCommodityEditModel::onPendingOperation()
{
    QString errorStr = SalesCommodityService::instance()->onPendingOperation();
    m_errorStr = errorStr;
    emit statusChanged();
}

void SalesCommodityEditModel::onGettingOperation()
{
    QString errorStr = SalesCommodityService::instance()->onGettingOperation();
    m_errorStr = errorStr;
    emit statusChanged();
}

QString SalesCommodityEditModel::getErrorStr()
{
    return m_errorStr;
}

void SalesCommodityEditModel::setErrorStr(QString errorStr)
{
    m_errorStr = errorStr;
    emit statusChanged();
}

bool SalesCommodityEditModel::getIsPendingStatus()
{
    return (SalesCommodityService::instance()->getPendingList().count() == 0 ? false : true);
}



#include "SalesCommodityEditModel.h"

SalesCommodityEditModel::SalesCommodityEditModel()
{
    m_isPending = false;
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

void SalesCommodityEditModel::onPendingOperation()
{
    SalesCommodityService::instance()->onPendingOperation();
}

void SalesCommodityEditModel::onGettingOperation()
{
    SalesCommodityService::instance()->onGettingOperation();
}

bool SalesCommodityEditModel::getIsPending()
{
    return m_isPending;
}

void SalesCommodityEditModel::setIsPending(bool status)
{
    m_isPending = status;
    emit statusChanged();
}

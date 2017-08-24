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

bool SalesCommodityEditModel::update(Commodity *commodity)
{
    return SalesCommodityService::instance()->update(commodity);
}

void SalesCommodityEditModel::isPendingOperation()
{
    if (!getIsPending()) {
        SalesCommodityService::instance()->isPendingOperation();
        setIsPending(SalesCommodityService::instance()->getIsPendingStatus());
    }
}

void SalesCommodityEditModel::isGettingOperation()
{
    if (getIsPending()) {
        SalesCommodityService::instance()->isGettingOperation();
        setIsPending(SalesCommodityService::instance()->getIsPendingStatus());
    }
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

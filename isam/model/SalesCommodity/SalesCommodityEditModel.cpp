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

void SalesCommodityEditModel::onPendingOperation()
{
//    if (!getIsPending()) {
        SalesCommodityService::instance()->onPendingOperation();
//        setIsPending(SalesCommodityService::instance()->getIsPendingStatus());
//    }
}

void SalesCommodityEditModel::onGettingOperation()
{
//    if (getIsPending()) {
//        SalesCommodityService::instance()->onGettingOperation();
//        setIsPending(SalesCommodityService::instance()->getIsPendingStatus());
//    }
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

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

bool SalesCommodityEditModel::isPendingOperation()
{
    bool status = (SalesCommodityService::instance()->isPendingOperation());
    setIsPending(status);
    return status;
}

bool SalesCommodityEditModel::isGettingOperation()
{
    bool status = SalesCommodityService::instance()->isGettingOperation();
    setIsPending(false);
    return status;
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

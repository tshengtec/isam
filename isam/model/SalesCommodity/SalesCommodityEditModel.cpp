#include "SalesCommodityEditModel.h"

SalesCommodityEditModel::SalesCommodityEditModel()
{
    m_errorStr = "";
    emit statusChanged(); /*Init update date.*/
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

bool SalesCommodityEditModel::update(QVariantMap commodity)
{
    return SalesCommodityService::instance()->update(commodity);
}

bool SalesCommodityEditModel::settleMent()
{
    if (SalesCommodityService::instance()->getSalesNote().getList().count() > 0)
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
    int pendingSalesCommodityCount = SalesCommodityService::instance()->getPendingSalesNote().getList().count();
    bool pendingStatus = (pendingSalesCommodityCount == 0 ? false : true);
    return pendingStatus;
}



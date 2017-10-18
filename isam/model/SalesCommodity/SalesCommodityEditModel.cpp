#include "SalesCommodityEditModel.h"

SalesCommodityEditModel::SalesCommodityEditModel()
{
    m_errorStr = "";
    /* payway type -> 1.cash 2.alipay 3.wxpay */
    m_payway = "cash";
    m_authCode = "0";
    m_paywayTotal = 0;

    connect(this, SIGNAL(statusChanged()), this, SLOT(setPayInfo()));

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

QString SalesCommodityEditModel::getPayway()
{
    return m_payway;
}

void SalesCommodityEditModel::setPayway(QString payway)
{
    m_payway = payway;
    emit statusChanged();
}

QString SalesCommodityEditModel::getAuthCode()
{
    return m_authCode;
}

void SalesCommodityEditModel::setAuthCode(QString authCode)
{
    m_authCode = authCode;
    emit statusChanged();
}

float SalesCommodityEditModel::getPaywayTotal()
{
    return m_paywayTotal;
}

void SalesCommodityEditModel::setPaywayTotal(float paywayTotal)
{
    m_paywayTotal = paywayTotal;
    emit statusChanged();
}

bool SalesCommodityEditModel::getIsPendingStatus()
{
    int pendingSalesCommodityCount = SalesCommodityService::instance()->getPendingSalesNote().getList().count();
    bool pendingStatus = (pendingSalesCommodityCount == 0 ? false : true);
    return pendingStatus;
}

void SalesCommodityEditModel::setPayInfo()
{
    QVariantMap map;
    map["payway"] = this->getPayway();
    map["authCode"] = this->getAuthCode();
    map["paywayTotal"] = this->getPaywayTotal();
    SalesCommodityService::instance()->setPayInfo(map);
}



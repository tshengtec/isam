#include "SalesDocumentsModel.h"

SalesDocumentsModel::SalesDocumentsModel(QObject *parent) :
    BaseItemModel(parent)
{
    m_id = "";
    m_time = QTime::currentTime();
    m_amountMoney = "0.00";
}

QString SalesDocumentsModel::getId()
{
    return m_id;
}

void SalesDocumentsModel::setId(QString id)
{
    m_id = id;
    emit statusChanged();
}

QTime SalesDocumentsModel::getTime()
{
    return m_time;
}

void SalesDocumentsModel::setTime(QTime time)
{
    m_time = time;
    emit statusChanged();
}

QString SalesDocumentsModel::getAmountMoney()
{
    return m_amountMoney;
}

void SalesDocumentsModel::setAmountMoney(QString money)
{
    m_amountMoney = money;
    emit statusChanged();
}

void SalesDocumentsModel::operator=(const SalesDocumentsModel &model)
{
    this->m_id = model.m_id;
    this->m_time = model.m_time;
    this->m_amountMoney = model.m_amountMoney;

    emit statusChanged();
}

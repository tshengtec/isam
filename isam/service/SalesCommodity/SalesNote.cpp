#include "SalesNote.h"
#include "CommodityRepertory.h"

SalesNote::SalesNote()
{
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    m_id = QString::number(date.year()) + QString::number(date.month()) + QString::number(date.day()) +
           QString::number(time.hour()) + QString::number(time.minute())+ QString::number(time.second()) +
           QString::number(time.msec());
    m_owner = "admin";
    m_dateTime = QDateTime::currentDateTime();
    m_payMap.clear();
}

SalesNote::SalesNote(SalesNote *salesNote)
{
    m_id = salesNote->getId();
    m_owner = salesNote->getOwner();
    m_dateTime = salesNote->getDateTime();
    m_payMap = salesNote->getPayMap();
    m_commodityList = this->copyList(salesNote->getList());
}

SalesNote::~SalesNote()
{
}

QList<Commodity *> SalesNote::getList()
{
    return m_commodityList;
}

void SalesNote::setList(QList<Commodity *> list)
{
    this->removeList(m_commodityList);
    m_commodityList = list;
}

Commodity *SalesNote::get(QString id)
{
    for (int i = 0; i < m_commodityList.count(); i++) {
        if (m_commodityList.at(i)->getId() == id) {
            return m_commodityList.at(i);
        }
    }

    return NULL;
}

bool SalesNote::add(QString id)
{
    Commodity *commodity = CommodityRepertory::instance()->get(id);
    if (commodity == NULL)
        return false;

    Commodity *newCommodity = new Commodity(commodity);
    m_commodityList.append(newCommodity);
    return true;
}

bool SalesNote::remove(QString id)
{
    for (int i = 0; i < m_commodityList.count(); i++) {
        Commodity* commodity = m_commodityList.at(i);
        if (commodity == NULL)
            return false;

        if (commodity->getId() == id) {
            m_commodityList.removeAt(i);
            delete commodity;
            return true;
        }

    }
    return false;
}

bool SalesNote::update(Commodity *commodity)
{
    if (commodity == NULL)
        return false;

    for (int i = 0; i < m_commodityList.count(); i++) {
        Commodity * oldCommodity = m_commodityList.at(i);
        if (oldCommodity->getId() == commodity->getId()) {
            delete oldCommodity;
            m_commodityList.replace(i, commodity);
            return true;
        }
    }

    return false;
}

bool SalesNote::removeAll()
{
    this->removeList(this->m_commodityList);
    bool isSuccess = (m_commodityList.count() == 0);
    return isSuccess;
}

QString SalesNote::getId()
{
    return m_id;
}

void SalesNote::setId(QString id)
{
    m_id = id;
}

QString SalesNote::getOwner()
{
    return m_owner;
}

void SalesNote::setOwner(QString owner)
{
    m_owner = owner;
}

QDateTime SalesNote::getDateTime()
{
    return m_dateTime;
}

void SalesNote::setDateTime(QDateTime dateTime)
{
    m_dateTime = dateTime;
}

QVariantMap SalesNote::getPayMap()
{
    return m_payMap;
}

void SalesNote::setPayMap(QVariantMap map)
{
    m_payMap.clear();
    m_payMap = map;
}

float SalesNote::getRealIncome()
{
    float count = 0;
    for (int i = 0; i < this->m_commodityList.count(); i++) {
        Commodity* commodity = this->m_commodityList.at(i);
        count += (commodity->getRetailPrice()*commodity->getCount());
    }

    return count;
}

QList<Commodity *> SalesNote::copyMyselfList()
{
    return copyList(this->getList());
}

QList<Commodity *> SalesNote::copyList(QList<Commodity *> list)
{
    QList<Commodity *> newList = QList<Commodity *>();
    for (int i = 0; i < list.count(); i++) {
        Commodity *newCommodity = new Commodity(list.at(i));
        newList.append(newCommodity);
    }

    return newList;
}

void SalesNote::removeList(QList<Commodity *> &removeList)
{
    while (removeList.count()) {
        Commodity * oldCommodity = removeList.last();
        removeList.removeLast();
        delete oldCommodity;
    }
}


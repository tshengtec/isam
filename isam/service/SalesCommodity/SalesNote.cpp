#include "SalesNote.h"

SalesNote::SalesNote()
{
    m_owner = "";
    m_dateTime = QDateTime::currentDateTime();
}

QList<Commodity *> SalesNote::getList()
{
    return m_salesBaseNote;
}

void SalesNote::setList(QList<Commodity *> list)
{
    this->removeList(m_salesBaseNote);
    m_salesBaseNote = list;
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

void SalesNote::removeList(QList<Commodity *> &removeList)
{
    while (removeList.count()) {
        Commodity * oldCommodity = removeList.last();
        removeList.removeLast();
        delete oldCommodity;
    }
}


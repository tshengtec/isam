#include "SalesNote.h"

SalesNote::SalesNote()
{
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    m_id = QString::number(date.year()) + QString::number(date.month()) + QString::number(date.day()) +
           QString::number(time.hour()) + QString::number(time.minute())+ QString::number(time.second()) +
           QString::number(time.msec());
    m_owner = "";
    m_dateTime = QDateTime::currentDateTime();
}

SalesNote::~SalesNote()
{
    removeList(this->m_salesBaseNote);
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

void SalesNote::removeList(QList<Commodity *> &removeList)
{
    while (removeList.count()) {
        Commodity * oldCommodity = removeList.last();
        removeList.removeLast();
        delete oldCommodity;
    }
}


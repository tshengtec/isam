#include "SalesNote.h"
#include "CommodityRepertory.h"
#include "GlobalDefinition.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QDebug>

SalesNote::SalesNote()
{
    QTime time = QTime::currentTime();
    QDate date = QDate::currentDate();
    m_id = QString::number(date.year()) + QString::number(date.month()) + QString::number(date.day()) +
           QString::number(time.hour()) + QString::number(time.minute())+ QString::number(time.second()) +
           QString::number(time.msec());
    m_owner = "admin";
    m_dateTime = QDateTime::currentDateTime();
    m_paymentMethodsAndAmout["cash"] = "0";
    m_paymentMethodsAndAmout["wxpay"] = "0";
    m_paymentMethodsAndAmout["alipay"] = "0";
    m_paymentMethodsAndAmout["authCode"] = "0";
}

SalesNote::SalesNote(SalesNote *salesNote)
{
    m_id = salesNote->getId();
    m_owner = salesNote->getOwner();
    m_dateTime = salesNote->getDateTime();
    m_paymentMethodsAndAmout = salesNote->getPaymentMethodsAndAmout();
    m_commodityList = this->copyList(salesNote->getList());
}

SalesNote::~SalesNote()
{
}

QList<QVariantMap> SalesNote::getList()
{
    return m_commodityList;
}

void SalesNote::setList(QList<QVariantMap> list)
{
    this->removeList(m_commodityList);
    m_commodityList = list;
}

QVariantMap SalesNote::get(QString id)
{
    QString _id;
    for (int i = 0; i < m_commodityList.count(); i++) {
        _id = m_commodityList.at(i).value("barCode").toString();
        if (_id == id) {
            return m_commodityList.at(i);
        }
    }

    return QVariantMap();
}

bool SalesNote::add(QString id)
{
    QSqlDatabase db;
    if (QSqlDatabase::contains(GOODS_DB_FILE_NAME))
    {
        db = QSqlDatabase::database(GOODS_DB_FILE_NAME);
        qDebug()<<"Exist GOODS_DB_FILE_NAME!";
    }
    else {
        db = QSqlDatabase::addDatabase("QSQLITE", GOODS_DB_FILE_NAME);//添加数据库驱动
        db.setDatabaseName(GOODS_DB_FILE_NAME); //数据库连接命名
        qDebug()<<"UnExist GOODS_DB_FILE_NAME!";
    }
    QSqlQuery sqlQuery = QSqlQuery(db);

    if (!sqlQuery.exec("SELECT * FROM person WHERE id LIKE '%"+ id +"%'")) {
        qDebug()<<sqlQuery.lastError()<<"bool SalesNote::add(QString id)";
    }

    QVariantMap map;

    if (!sqlQuery.first())
        return false;

    for (int i = 0; i < (sizeof(goodsFields)/sizeof(goodsFields[0])); i++) {
        map.insert(goodsFields[i], sqlQuery.value(goodsFields[i]));
    }

    map.insert("quantity", 1);
    float discountedPrice = map.value("sellingPrice").toDouble() * map.value("discount").toInt() / 100;
    map.insert("discountedPrice", discountedPrice);

    float subtotal = map.value("quantity").toInt() * discountedPrice;
    map.insert("subtotal", subtotal);

    if (!isRepeatedAdd(map))
        m_commodityList.append(map);
    return true;
}

bool SalesNote::remove(QString id)
{
    QString _id;
    for (int i = 0; i < m_commodityList.count(); i++) {
        QVariantMap commodity = m_commodityList.at(i);
        if (commodity.isEmpty())
            return false;
        _id = commodity.value("id").toString();
        if (_id == id) {
            m_commodityList.removeAt(i);
            return true;
        }

    }
    return false;
}

bool SalesNote::update(QVariantMap commodity)
{
    if (commodity.isEmpty())
        return false;

    QString oldId, newId;
    for (int i = 0; i < m_commodityList.count(); i++) {
        QVariantMap oldCommodity = m_commodityList.at(i);

        oldId = oldCommodity.value("barCode").toString();
        newId = commodity.value("barCode").toString();
        if (oldId == newId) {
            m_commodityList.replace(i, QVariantMap(commodity));
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

QVariantMap SalesNote::getPaymentMethodsAndAmout()
{
    return m_paymentMethodsAndAmout;
}

void SalesNote::setPaymentMethodsAndAmout(QVariantMap map)
{
    QMapIterator<QString, QVariant> i(map);
    while (i.hasNext()) {
        i.next();
        m_paymentMethodsAndAmout.insert(i.key(), i.value());
    }
}

float SalesNote::getRealIncome()
{
    float count = 0;
    for (int i = 0; i < this->m_commodityList.count(); i++) {
        QVariantMap commodity = this->m_commodityList.at(i);
        float sellingPrice = commodity.value("discountedPrice").toDouble();
        int quantity = commodity.value("quantity").toInt();

        count += sellingPrice * quantity;
    }

    return count;
}

int SalesNote::getTotalQuantity()
{
    float quantity = 0;
    for (int i = 0; i < this->m_commodityList.count(); i++) {
        QVariantMap commodity = this->m_commodityList.at(i);
        int _quantity = commodity.value("quantity").toInt();

        quantity += _quantity;
    }

    return quantity;
}

QList<QVariantMap> SalesNote::copyMyselfList()
{
    return copyList(this->getList());
}

QList<QVariantMap> SalesNote::copyList(QList<QVariantMap> list)
{
    QList<QVariantMap> newList = QList<QVariantMap>();
    for (int i = 0; i < list.count(); i++) {
        QVariantMap newCommodity = list.at(i);
        newList.append(newCommodity);
    }

    return newList;
}

void SalesNote::removeList(QList<QVariantMap> &removeList)
{
    while (removeList.count()) {
        removeList.removeLast();
    }
}

bool SalesNote::isRepeatedAdd(QVariantMap map)
{
    for (int i = 0; i < m_commodityList.count(); i++) {
        QVariantMap goods = m_commodityList.at(i);
        if (goods.value("id").toLongLong() == map.value("id").toLongLong()) {
            goods["quantity"] = goods["quantity"].toLongLong() + 1;
            m_commodityList.replace(i, goods);
            return true;
        }
    }
    return false;
}


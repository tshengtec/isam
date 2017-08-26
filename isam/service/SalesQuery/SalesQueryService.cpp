#include "SalesQueryService.h"
#include <QRegExp>
#include <QDebug>
#include <QString>

SalesQueryService * SalesQueryService::_instance = NULL;


SalesQueryService::SalesQueryService()
{
}

SalesQueryService *SalesQueryService::instance()
{
    if (_instance == NULL) {
        _instance = new SalesQueryService();
    }
    return _instance;
}

QList<Commodity *> SalesQueryService::getList()
{
    return CommodityRepertory::instance()->getList();
}

QList<Commodity *> SalesQueryService::getList(QueryCommodityCondition condition)
{
    QList<Commodity *> list = this->getList();
    QString str;
    str.append("^(.*");
    str.append("12346");
    str.append(".*)$");
    QRegExp reg(str);

    for (int i = 0; i < list.count(); i++) {
        int index = reg.indexIn(list.at(i)->getId());
        qDebug()<<list.at(i)->getId();
        if (index != -1) {
            qDebug()<<11<<list.at(i)->getId();
        }
    }
}

Commodity *SalesQueryService::get(QString id)
{
    return CommodityRepertory::instance()->get(id);
}

Commodity *SalesQueryService::getFuzzy(QString target)
{
    QList<Commodity *> list = this->getList();


}

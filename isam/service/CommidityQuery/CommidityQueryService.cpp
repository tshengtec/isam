#include "CommidityQueryService.h"
#include <QRegExp>
#include <QDebug>
#include <QString>

CommidityQueryService * CommidityQueryService::_instance = NULL;


CommidityQueryService::CommidityQueryService()
{
}

CommidityQueryService *CommidityQueryService::instance()
{
    if (_instance == NULL) {
        _instance = new CommidityQueryService();
    }
    return _instance;
}

QList<Commodity *> CommidityQueryService::getList()
{
    return CommodityRepertory::instance()->getList();
}

QList<Commodity *> CommidityQueryService::getList(QueryCommodityCondition condition)
{
    QList<Commodity *> list = this->getList();
    QList<Commodity *> newlist = QList<Commodity *>();

    m_fuzzySearchTool.setFuzzyStr(condition.getFuzzyStr());

    for (int i = 0; i < list.count(); i++) {
        Commodity* commodity = list.at(i);

        if (condition.getCommodityType() == commodity->getCommodityType()) {
            if (m_fuzzySearchTool.indexIn(commodity->getId())   != -1 ||
                m_fuzzySearchTool.indexIn(commodity->getName()) != -1) {
                newlist.append(commodity);
            }
        }
    }

    return newlist;
}

Commodity *CommidityQueryService::get(QString id)
{
    return CommodityRepertory::instance()->get(id);
}

Commodity *CommidityQueryService::getFuzzy(QString target)
{
    QList<Commodity *> list = this->getList();


}

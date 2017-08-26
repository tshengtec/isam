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

Commodity *SalesQueryService::get(QString id)
{
    return CommodityRepertory::instance()->get(id);
}

Commodity *SalesQueryService::getFuzzy(QString target)
{
    QList<Commodity *> list = this->getList();


}

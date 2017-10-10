#include "CommodityQueryService.h"
#include "GoodsSqlRepo.h"

#include <QRegExp>
#include <QDebug>
#include <QString>

CommodityQueryService * CommodityQueryService::_instance = NULL;


CommodityQueryService::CommodityQueryService()
{
}

CommodityQueryService *CommodityQueryService::instance()
{
    if (_instance == NULL) {
        _instance = new CommodityQueryService();
    }
    return _instance;
}

QList<Commodity *> CommodityQueryService::getList()
{
    return CommodityRepertory::instance()->getList();
}

QList<Commodity *> CommodityQueryService::getList(CommodityQueryCondition condition)
{
    QList<Commodity *> list = this->getList();
    QList<Commodity *> newlist = QList<Commodity *>();

    m_fuzzySearchTool.setFuzzyStr(condition.getFuzzyStr());

    for (int i = 0; i < list.count(); i++) {
        Commodity* commodity = list.at(i);

        if (condition.getCommodityType() == "all" || condition.getCommodityType() == commodity->getCommodityType()) {
            if (condition.getFuzzyStr() == "" && !condition.getIsNotStrSearchAll())
                break;

            if (m_fuzzySearchTool.indexIn(commodity->getId())   != -1 ||
                m_fuzzySearchTool.indexIn(commodity->getName()) != -1) {
                newlist.append(commodity);
            }
        }
    }

    return newlist;
}

QList<QVariantMap> CommodityQueryService::getList(QString target, int page, int pageNum)
{
    return GoodsSqlRepo::instance()->getList(target, page, pageNum);
}

Commodity *CommodityQueryService::get(QString id)
{
    return CommodityRepertory::instance()->get(id);
}

Commodity *CommodityQueryService::getFuzzy(QString target)
{
    QList<Commodity *> list = this->getList();


}

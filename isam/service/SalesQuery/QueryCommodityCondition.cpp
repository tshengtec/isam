#include "QueryCommodityCondition.h"

QueryCommodityCondition::QueryCommodityCondition()
{
    m_commodityType = EC::ALL;
}

QString QueryCommodityCondition::getCommodityType()
{
    return m_commodityType;
}

void QueryCommodityCondition::setCommodityType(QString typeStr)
{
    m_commodityType = typeStr;
}

QString QueryCommodityCondition::getFuzzyStr()
{
    return m_fuzzyStr;
}

void QueryCommodityCondition::setFuzzyStr(QString fuzzyStr)
{
    m_fuzzyStr = fuzzyStr;
}

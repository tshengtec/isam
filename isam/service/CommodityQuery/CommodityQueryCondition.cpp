#include "CommodityQueryCondition.h"

CommodityQueryCondition::CommodityQueryCondition()
{
    m_commodityType = EC::ALL;
}

QString CommodityQueryCondition::getCommodityType()
{
    return m_commodityType;
}

void CommodityQueryCondition::setCommodityType(QString typeStr)
{
    m_commodityType = typeStr;
}

QString CommodityQueryCondition::getFuzzyStr()
{
    return m_fuzzyStr;
}

void CommodityQueryCondition::setFuzzyStr(QString fuzzyStr)
{
    m_fuzzyStr = fuzzyStr;
}

#include "CommidityQueryCondition.h"

CommidityQueryCondition::CommidityQueryCondition()
{
    m_commodityType = EC::ALL;
}

QString CommidityQueryCondition::getCommodityType()
{
    return m_commodityType;
}

void CommidityQueryCondition::setCommodityType(QString typeStr)
{
    m_commodityType = typeStr;
}

QString CommidityQueryCondition::getFuzzyStr()
{
    return m_fuzzyStr;
}

void CommidityQueryCondition::setFuzzyStr(QString fuzzyStr)
{
    m_fuzzyStr = fuzzyStr;
}

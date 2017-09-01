#include "CommodityQueryCondition.h"

CommodityQueryCondition::CommodityQueryCondition()
{
    m_commodityType = commodityTypeList[0];
    m_fuzzyStr = "";
    m_isNotStrSearchAll = false;
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

bool CommodityQueryCondition::getIsNotStrSearchAll()
{
    return m_isNotStrSearchAll;
}

void CommodityQueryCondition::setIsNotStrSearchAll(bool status)
{
    m_isNotStrSearchAll = status;
}

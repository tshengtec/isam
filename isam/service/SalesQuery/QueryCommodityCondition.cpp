#include "QueryCommodityCondition.h"

QueryCommodityCondition::QueryCommodityCondition()
{
    m_commodityType = EC::ALL;
}

EC::CommodityClassification QueryCommodityCondition::getCommodityType()
{
    return m_commodityType;
}

void QueryCommodityCondition::setCommodityType(EC::CommodityClassification type)
{
    m_commodityType = type;
}

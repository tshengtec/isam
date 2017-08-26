#ifndef QUERYCOMMODITYCONDITION_H
#define QUERYCOMMODITYCONDITION_H

#include "EnumComplete.h"

class QueryCommodityCondition
{
public:
    QueryCommodityCondition();

    EC::CommodityClassification getCommodityType();
    void setCommodityType(EC::CommodityClassification);

private:
    EC::CommodityClassification m_commodityType;
};

#endif // QUERYCOMMODITYCONDITION_H

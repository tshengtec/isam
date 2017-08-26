#ifndef QUERYCOMMODITYCONDITION_H
#define QUERYCOMMODITYCONDITION_H

#include "EnumComplete.h"
#include <QString>

class QueryCommodityCondition
{
public:
    QueryCommodityCondition();

    QString getCommodityType();
    void setCommodityType(QString strType);

    QString getFuzzyStr();
    void setFuzzyStr(QString fuzzyStr);

private:
    QString m_commodityType;
    QString m_fuzzyStr;
};

#endif // QUERYCOMMODITYCONDITION_H

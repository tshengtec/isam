#ifndef COMMIDITYQUERYCONDITION_H
#define COMMIDITYQUERYCONDITION_H
#include "EnumComplete.h"
#include <QString>

class CommodityQueryCondition
{
public:
    CommodityQueryCondition();

    QString getCommodityType();
    void setCommodityType(QString strType);

    QString getFuzzyStr();
    void setFuzzyStr(QString fuzzyStr);

private:
    QString m_commodityType;
    QString m_fuzzyStr;
};
#endif // COMMIDITYQUERYCONDITION_H

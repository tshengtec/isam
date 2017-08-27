#ifndef COMMIDITYQUERYCONDITION_H
#define COMMIDITYQUERYCONDITION_H
#include "EnumComplete.h"
#include <QString>

class CommidityQueryCondition
{
public:
    CommidityQueryCondition();

    QString getCommodityType();
    void setCommodityType(QString strType);

    QString getFuzzyStr();
    void setFuzzyStr(QString fuzzyStr);

private:
    QString m_commodityType;
    QString m_fuzzyStr;
};
#endif // COMMIDITYQUERYCONDITION_H

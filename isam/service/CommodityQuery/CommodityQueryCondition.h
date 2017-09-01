#ifndef COMMIDITYQUERYCONDITION_H
#define COMMIDITYQUERYCONDITION_H
#include "EnumComplete.h"
#include <QString>

const QString commodityTypeList[] = {
    "all", "default"
};
const QString commodityTypeListTr[] = {
    "全部分类", "默认分类"
};

class CommodityQueryCondition
{
public:
    CommodityQueryCondition();

    QString getCommodityType();
    void setCommodityType(QString strType);

    QString getFuzzyStr();
    void setFuzzyStr(QString fuzzyStr);

    bool getIsNotStrSearchAll(); //is not str search all.
    void setIsNotStrSearchAll(bool status);

private:
    QString m_commodityType;
    QString m_fuzzyStr;
    bool m_isNotStrSearchAll;
};
#endif // COMMIDITYQUERYCONDITION_H

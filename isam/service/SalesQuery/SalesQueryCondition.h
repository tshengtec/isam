#ifndef SALESQUERYCONDITION_H
#define SALESQUERYCONDITION_H

#include <QString>

class SalesQueryCondition
{
public:
    SalesQueryCondition();

    QString getQueryType();
    void setQueryType(QString strType);

private:
    QString m_queryType;
};

#endif // SALESQUERYCONDITION_H

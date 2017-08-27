#include "SalesQueryCondition.h"

SalesQueryCondition::SalesQueryCondition()
{

}

QString SalesQueryCondition::getQueryType()
{
    return m_queryType;
}

void SalesQueryCondition::setQueryType(QString strType)
{
    m_queryType = strType;
}

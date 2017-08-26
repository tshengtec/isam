#include "FuzzySearchTool.h"

FuzzySearchTool::FuzzySearchTool()
{
}

void FuzzySearchTool::setFuzzyStr(QString str)
{
    QString strValue;
    strValue.append("^(.*");
    strValue.append(str);
    strValue.append(".*)$");
    m_regExp.setPattern(strValue);
}

int FuzzySearchTool::indexIn(QString str)
{
    return m_regExp.indexIn(str);
}


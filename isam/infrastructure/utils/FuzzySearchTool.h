#ifndef FUZZYSEARCHTOOL_H
#define FUZZYSEARCHTOOL_H
#include <QRegExp>
/*
 * Fuzzy search utility class.
*/
//"^(?!.*(转发)).*$"

class FuzzySearchTool
{
public:
    FuzzySearchTool();
    void setFuzzyStr(QString str);
    int indexIn(QString str);

private:
    QRegExp m_regExp;
    QString m_fuzzySearch;
};

#endif // FUZZYSEARCHTOOL_H

#ifndef SALESQUERYSERVICE_H
#define SALESQUERYSERVICE_H

#include "SalesNote.h"
#include "SalesQueryCondition.h"
/*
 * This class is used for all commodity query functions.
*/
class SalesQueryService : public QObject
{
    Q_OBJECT
public:
    SalesQueryService();

    static SalesQueryService* instance();
    QList<SalesNote *> getList(SalesQueryCondition condition);

private:
    static SalesQueryService* _instance;
};

#endif // SALESQUERYSERVICE_H

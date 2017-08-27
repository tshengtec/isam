#ifndef SALESNOTE_H
#define SALESNOTE_H
#include "Commodity.h"
#include <QDateTime>

class SalesNote
{
public:
    SalesNote();
    QList<Commodity *> getList();
    void setList(QList<Commodity *> list);

    QString getOwner();
    void setOwner(QString owner);

    QDateTime getDateTime();
    void setDateTime(QDateTime dateTime);

private:
    void removeList(QList<Commodity* >& removeList); // removeAll List

private:
    QList<Commodity* > m_salesBaseNote;
    QString m_owner;
    QDateTime m_dateTime; //Time for selling
};

#endif // SALESNOTE_H

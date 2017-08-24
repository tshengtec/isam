#ifndef Commodity_H
#define Commodity_H

#include <QString>
#include <QObject>
#include "DomainObject.h"

class Commodity : public QObject, public DomainObject
{
    Q_OBJECT
public:
    Commodity();
    Commodity(Commodity* commodity);
    virtual ~Commodity();

    void fromJson(const QJsonObject data);
    QJsonObject toJson();

    QString getId();
    void setId(QString id);

    QString getName();
    void setName(QString name);

    int getCount();
    void setCount(int count);

    int getRetailPrice();
    void setRetailPrice(int retailprice);

private:
    QString m_id; /*条形码ID*/
    QString m_name; /**/
    int m_count;
    int m_retailPrice;
};

#endif // Commodity_H

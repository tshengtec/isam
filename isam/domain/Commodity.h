#ifndef Commodity_H
#define Commodity_H

#include <QString>
#include <QObject>
#include <QVariantMap>
#include "DomainObject.h"

class Commodity : public QObject, public DomainObject
{
    Q_OBJECT
public:
    Commodity();
    Commodity(Commodity* commodity);
    Commodity(Commodity& commodity);
    virtual ~Commodity();

    void fromJson(const QJsonObject data);
    QJsonObject toJson();

    QString getId();
    void setId(QString id);

    QString getName();
    void setName(QString name);

    int getCount();
    void setCount(int count);

    float getRetailPrice();
    void setRetailPrice(float retailprice);

    QString getCommodityType();
    void setCommodityType(QString typeStr);

    void fromMap(QVariantMap map);

private:
    QString m_id; /*条形码ID*/
    QString m_name; /**/
    int m_count;
    float m_retailPrice;
    QString m_commodityType;
};

#endif // Commodity_H

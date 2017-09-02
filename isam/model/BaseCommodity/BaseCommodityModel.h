#ifndef BASEBaseCommodityModel_H
#define BASEBaseCommodityModel_H
#include "BaseItemModel.h"
#include "Commodity.h"

class BaseCommodityModel : public BaseItemModel
{
    Q_OBJECT
public:
    BaseCommodityModel(QObject* parent = NULL);
    BaseCommodityModel(Commodity* commodity, QObject* parent = NULL);
    Q_PROPERTY(QString id READ getId NOTIFY statusChanged)
    Q_PROPERTY(QString name READ getName NOTIFY statusChanged)
    Q_PROPERTY(int count READ getCount NOTIFY statusChanged)
    Q_PROPERTY(float retailprice READ getRetailPrice NOTIFY statusChanged)

    QString getId();
    void setId(QString id);

    QString getName();
    void setName(QString name);

    int getCount();
    void setCount(int count);

    float getRetailPrice();
    void setRetailPrice(float retailprice);

    void operator=(const BaseCommodityModel& model);

signals:
    void statusChanged();

private:
    QString m_id;
    QString m_name;
    int m_count;
    float m_retailPrice;
};

#endif // BASEBaseCommodityModel_H

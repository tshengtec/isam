#ifndef BASEBaseCommodityModel_H
#define BASEBaseCommodityModel_H
#include "BaseItemModel.h"
#include "Commodity.h"

#include <QVariantMap>

class BaseCommodityModel : public BaseItemModel
{
    Q_OBJECT
public:
    BaseCommodityModel(QObject* parent = NULL);
    BaseCommodityModel(Commodity* commodity, QObject* parent = NULL);
    Q_PROPERTY(QString id READ getId NOTIFY statusChanged)
    Q_PROPERTY(QString barCode READ getBarCode NOTIFY statusChanged)
    Q_PROPERTY(QString name READ getName NOTIFY statusChanged)
    Q_PROPERTY(QString unitName READ getUnitName NOTIFY statusChanged)
    Q_PROPERTY(int count READ getCount NOTIFY statusChanged)
    /*The same sellingPrice.*/
    Q_PROPERTY(float retailprice READ getRetailPrice NOTIFY statusChanged)
    /*discount 0 - 100*/
    Q_PROPERTY(int discount READ getDiscount NOTIFY statusChanged)
    /*Discounted unit price*/
    Q_PROPERTY(float discountedPrice READ getDiscountedPrice NOTIFY statusChanged)
    Q_PROPERTY(float subtotal READ getSubtotal NOTIFY statusChanged)
    Q_PROPERTY(QVariantMap map READ getMap NOTIFY statusChanged)

    QString getId();
    void setId(QString id);

    QString getBarCode();
    void setBarCode(QString barCode);

    QString getName();
    void setName(QString name);

    int getCount();
    void setCount(int count);

    QString getUnitName();
    void setUnitName(QString unitName);

    float getRetailPrice();
    void setRetailPrice(float retailprice);

    int getDiscount();
    void setDiscount(int discount);

    float getDiscountedPrice();

    float getSubtotal();

    QVariantMap getMap();

    void fromMap(QVariantMap map);

    void operator=(const BaseCommodityModel& model);

signals:
    void statusChanged();

private:
    QString m_id;
    QString m_barCode;
    QString m_name;
    QString m_unitName;
    float m_retailPrice;
    int m_discount;
    int m_count;
    QVariant m_map;
};

#endif // BASEBaseCommodityModel_H

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

    Q_PROPERTY(QVariantMap map READ getMap NOTIFY statusChanged)

    QVariantMap getMap();

    void fromMap(QVariantMap map);

    void operator=(const BaseCommodityModel& model);

signals:
    void statusChanged();

private:
    QVariantMap m_map;
};

#endif // BASEBaseCommodityModel_H

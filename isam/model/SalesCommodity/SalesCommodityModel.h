#ifndef SALESCOMMODITYMODEL_H
#define SALESCOMMODITYMODEL_H
#include "BaseItemModel.h"
#include "Commodity.h"

class SalesCommodityModel : public BaseItemModel
{
    Q_OBJECT
public:
    SalesCommodityModel(QObject* parent = NULL);
    SalesCommodityModel(Commodity* commodity, QObject* parent = NULL);

    Q_PROPERTY(QString id READ getId NOTIFY statusChanged)
    Q_PROPERTY(QString name READ getName NOTIFY statusChanged)

    QString getId();
    void setId(QString id);

    QString getName();
    void setName(QString name);

    void operator=(const SalesCommodityModel& model);

signals:
    void statusChanged();

private:
    QString m_id;
    QString m_name;
};


#endif // SALESCOMMODITYMODEL_H

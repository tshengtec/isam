#ifndef COMMODITYMODEL_H
#define COMMODITYMODEL_H
#include "BaseItemModel.h"

class CommodityModel : public BaseItemModel
{
    Q_OBJECT
public:
    CommodityModel(QObject* parent = NULL);
    Q_PROPERTY(QString id READ getId NOTIFY statusChanged)
    Q_PROPERTY(QString name READ getName NOTIFY statusChanged)

    QString getId();
    void setId(QString id);

    QString getName();
    void setName(QString name);

    void operator=(const CommodityModel& model);

signals:
    void statusChanged();

private:
    QString m_id;
    QString m_name;
};

#endif // COMMODITYMODEL_H

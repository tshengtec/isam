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

    QString getId();
    void setId(QString id);

    QString getName();
    void setName(QString name);

    void operator=(const BaseCommodityModel& model);

signals:
    void statusChanged();

private:
    QString m_id;
    QString m_name;
};

#endif // BASEBaseCommodityModel_H

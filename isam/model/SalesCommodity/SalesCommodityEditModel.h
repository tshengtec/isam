#ifndef SALESCOMMODITYEDITMODEL_H
#define SALESCOMMODITYEDITMODEL_H

#include "SalesCommodityModel.h"
#include "SalesCommodityService.h"

class SalesCommodityEditModel : public SalesCommodityModel
{
    Q_OBJECT
public:
    SalesCommodityEditModel();

    Q_INVOKABLE bool add(QString id);
    Q_INVOKABLE bool remove(QString id);
    Q_INVOKABLE bool update(Commodity *commodity);
    Q_INVOKABLE bool isPendingOperation();
    Q_INVOKABLE bool isGettingOperation();

    Q_PROPERTY(bool isPending READ getIsPending WRITE setIsPending NOTIFY statusChanged)

    bool getIsPending();
    void setIsPending(bool status);

signals:
    void statusChanged();

private:
    bool m_isPending;
};

#endif // SALESCOMMODITYEDITMODEL_H

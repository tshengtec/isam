#ifndef SALESCOMMODITYEDITMODEL_H
#define SALESCOMMODITYEDITMODEL_H

#include "BaseCommodityModel.h"
#include "SalesCommodityService.h"

class SalesCommodityEditModel : public BaseCommodityModel
{
    Q_OBJECT
public:
    SalesCommodityEditModel();

    Q_INVOKABLE bool add(QString id);
    Q_INVOKABLE bool remove(QString id);
    Q_INVOKABLE bool removeAll();
    Q_INVOKABLE bool update(Commodity *commodity);
    Q_INVOKABLE void onPendingOperation();
    Q_INVOKABLE void onGettingOperation();

    Q_PROPERTY(bool isPending READ getIsPending WRITE setIsPending NOTIFY statusChanged)

    bool getIsPending();
    void setIsPending(bool status);

signals:
    void statusChanged();

private:
    bool m_isPending;
};

#endif // SALESCOMMODITYEDITMODEL_H

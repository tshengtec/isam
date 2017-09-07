#ifndef GLOBALMODEL_H
#define GLOBALMODEL_H

#include <QObject>
#include <QVariant>

class GlobalModel : public QObject
{
    Q_OBJECT
public:
    GlobalModel();
    Q_PROPERTY(QVariant window READ getWindow WRITE setWindow NOTIFY statusChanged)

    QVariant getWindow();
    void setWindow(QVariant window);

signals:
    void statusChanged();

private:
    QVariant m_window;
};

#endif // GLOBALMODEL_H

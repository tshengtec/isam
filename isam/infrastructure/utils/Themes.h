#ifndef THEMES_H
#define THEMES_H

#include <QObject>
#include <QVariant>

class Themes : public QObject
{
    Q_OBJECT
public:
    Themes();
    Q_PROPERTY(QString backgroundColor READ getBackgroundColor WRITE setBackgroundColor NOTIFY statusChanged)
    Q_PROPERTY(QVariant windowObj READ getWindowObj WRITE setWindowObj NOTIFY statusChanged)

    QString getBackgroundColor();
    void setBackgroundColor(QString color);

    QVariant getWindowObj();
    void setWindowObj(QVariant obj);

signals:
    void statusChanged();

private:
    QString m_backgroundColor;
    QVariant m_windowObj;
};

#endif // THEMES_H

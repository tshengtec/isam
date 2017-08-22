#ifndef THEMES_H
#define THEMES_H

#include <QObject>

class Themes : public QObject
{
    Q_OBJECT
public:
    Themes();
    Q_PROPERTY(QString backgroundColor READ getBackgroundColor WRITE setBackgroundColor NOTIFY statusChanged)

    QString getBackgroundColor();
    void setBackgroundColor(QString color);

signals:
    void statusChanged();

private:
    QString m_backgroundColor;
};

#endif // THEMES_H

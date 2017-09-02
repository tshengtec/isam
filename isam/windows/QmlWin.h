#ifndef QMLWIN_H
#define QMLWIN_H
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QtQml>
#include <QDebug>

class QmlWin : public QQmlApplicationEngine
{
    Q_OBJECT
public:
    QmlWin();
};

#endif // QMLWIN_H

#ifndef _CPP_DECLARATIVE_WINDOW_H
#define _CPP_DECLARATIVE_WINDOW_H

#include "Window.h"
#include <QTimer>
#ifdef QT5VERSION
#include <QtQml>
#include <QQuickView>
#include <QQuickItem>
#else
class QDeclarativeView;
#endif

class DeclarativeWindow : public Window
{
    Q_OBJECT
public:
    DeclarativeWindow();
    DeclarativeWindow(QString name, QUrl qmlSource);
    ~DeclarativeWindow();

    void enter_win();
    void enterWin(QVariant args);
    void exit_win();

private:
    void init(QUrl qmlSource);

private:
#ifdef QT5VERSION
    QQuickView *m_view;
#else
    QDeclarativeView * m_view;
#endif
    QTimer*  m_delayCreatQml;
    QUrl m_qmlSource;
};

#endif // DECLARATIVEWINDOW_H

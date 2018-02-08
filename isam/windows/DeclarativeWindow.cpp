#include "DeclarativeWindow.h"
#include <stdio.h>

using namespace std;

DeclarativeWindow::DeclarativeWindow()
    : Window("")
{
}

DeclarativeWindow::DeclarativeWindow(QString name, QUrl qmlSource)
    : Window(name)
{
    m_qmlSource = qmlSource;
    init(m_qmlSource);
}

void DeclarativeWindow::init(QUrl qmlSource)
{
#ifdef QT5VERSION
    m_view = new QQuickView();
    m_view->installEventFilter(this);

    QWidget *container = QWidget::createWindowContainer(m_view, this);
    container->setWindowFlags(Qt::FramelessWindowHint);
    container->setAttribute(Qt::WA_TranslucentBackground);
    container->setStyleSheet("background:transparent;");
    container->resize(this->size());
#else
    m_view = new QDeclarativeView(this);
    m_view->setWindowFlags(Qt::FramelessWindowHint);
    m_view->setAttribute(Qt::WA_TranslucentBackground);
    m_view->setAttribute(Qt::WA_OpaquePaintEvent);
    m_view->setAttribute(Qt::WA_NoSystemBackground);
    m_view->viewport()->setAttribute(Qt::WA_OpaquePaintEvent);
    m_view->viewport()->setAttribute(Qt::WA_NoSystemBackground);
    m_view->setStyleSheet("background:transparent;");
    m_view->resize(this->size());
#endif

    if (! qmlSource.isEmpty())
        m_view->setSource(qmlSource);
}

DeclarativeWindow::~DeclarativeWindow()
{
    if (m_view != NULL) {
        delete m_view;
        m_view = NULL;
    }
}


void DeclarativeWindow::enter_win()
{
    QMetaObject::invokeMethod(m_view->rootObject(), "enterWin");
}

void DeclarativeWindow::enterWin(QVariant args)
{
    QMetaObject::invokeMethod(m_view->rootObject(), "enterWinWithArgs", Q_ARG(QVariant, args));
}

void DeclarativeWindow::exit_win()
{
    QMetaObject::invokeMethod(m_view->rootObject(), "exitWin");
}


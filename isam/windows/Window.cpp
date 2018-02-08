/*
 * File  : Window.cpp
 * Breif : Implementation of Window.h
 */

#include "Window.h"
#include "WinManager.h"

Window::Window(QString name)
    : m_index(0),
      m_name(name)
{
//    QRect rect = WinManager::instance()->get_window_area();
//    setGeometry(rect.x(), rect.y(), rect.width(), rect.height());
//    setAutoFillBackground(true);
//    QPalette pal(palette());
//    pal.setColor(QPalette::Window, QColor(Qt::black));
//    setPalette(pal);
}

Window::~Window()
{
}

int Window::getIndex()
{
    return m_index;
}

void Window::setIndex(int index)
{
    m_index = index;
}

QString Window::getName()
{
    return m_name;
}

void Window::enter_win() {
    /* do nothing */
}

void Window::enterWin(QVariant args) {
    Q_UNUSED(args);
    /* do nothing */
}

void Window::exit_win() {
    /* do nothing */
}

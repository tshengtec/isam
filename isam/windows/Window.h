/*
 * File  : Window.h
 * Breif : The base class of windows.
 */

#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <QWidget>

class Window : public QWidget {
    friend class WinManager;
public:
    Window(QString name);
    ~Window();

    int getIndex();
    QString getName();

    virtual void enter_win();
    virtual void enterWin(QVariant args);
    virtual void exit_win();

protected:
    /* WARNING: Do not call! It is called by WinManager */
    void setIndex(int index);

private:
    int m_index;
    QString m_name;
};

#endif

/*
 * Brief: Manager all the windows. It is a singleton!
 */

#ifndef _WIN_MANAGER_H_
#define _WIN_MANAGER_H_

#include "DeclarativeWindow.h"
#include <QObject>
#include <QTimer>
#include <QVariant>

class WinManager : public QWidget 
{
    Q_OBJECT
public:
    static WinManager *instance();

    /* window switch */
    Q_INVOKABLE void goto_win(QString name);
    Q_INVOKABLE void goto_win_with_args(QString name, QVariant args);
    Q_INVOKABLE void back();

    void start_win(Window *win);

    /* window manager */
    void add_win(DeclarativeWindow *win);


protected:
    WinManager(QWidget *parent = 0);
    ~WinManager();

private:
    static WinManager   *_instance;

};

#endif

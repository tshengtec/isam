#ifndef MYGUIAPPLICATION_H
#define MYGUIAPPLICATION_H
#include <QGuiApplication>
#include <QDebug>
#include <QCloseEvent>

class MyGuiApplication : public QGuiApplication
{
public:
    MyGuiApplication(int &argc, char **argv, int flags = ApplicationFlags);
};

#endif // MYGUIAPPLICATION_H

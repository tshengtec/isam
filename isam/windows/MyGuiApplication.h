#ifndef MYGUIAPPLICATION_H
#define MYGUIAPPLICATION_H
#include <QGuiApplication>

class MyGuiApplication : public QGuiApplication
{
public:
    MyGuiApplication(int &argc, char **argv, int flags = ApplicationFlags);
};

#endif // MYGUIAPPLICATION_H

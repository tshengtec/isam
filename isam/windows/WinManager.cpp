/*
 * File  : WinManager.cpp
 */


#include "WinManager.h"
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>

using namespace std;

WinManager *WinManager::_instance = 0;

WinManager::WinManager(QWidget *parent)
    : QWidget(parent)
{

}

WinManager::~WinManager() {
}

WinManager *WinManager::instance() {
    if (_instance == 0) {
        _instance = new WinManager();
    }
    return _instance;
}

void WinManager::add_win(DeclarativeWindow *win) {
    assert(win);
}

void WinManager::goto_win(QString name) {

}

void WinManager::goto_win_with_args(QString name, QVariant args){

}

void WinManager::start_win(Window *win) {
    assert(win);
}

void WinManager::back() {

}



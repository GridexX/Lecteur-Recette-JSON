#include "mainwindow.h"
#include "mainwindowlaunchdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowLaunchDialog w;
    w.show();
    return a.exec();
}

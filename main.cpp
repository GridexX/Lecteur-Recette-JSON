#include "mainwindow.h"
#include "mainwindowlaunchdialog.h"
#include "recette.h"

#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowLaunchDialog w;
    Recette r;
    w.show();
    return a.exec();

}

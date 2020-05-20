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
    //QObject::connect(r,SIGNAL(envoieNom(QString)),w,SLOT(modifNom(QString)));
    return a.exec();


}

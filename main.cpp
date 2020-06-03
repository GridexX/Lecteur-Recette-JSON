/**
 *   \file main.cpp
 *   \author Pollet Lucas - Fougerouse Arsène
 *
 *   \brief Classe principale qui permet de lancer la première fenetre
 */
#include "mainwindow.h"
#include "mainwindowlaunchdialog.h"
#include "recette.h"

#include <QApplication>
#include <QObject>

/**
 * \fn int main
 * \brief Fonction de lancement d'instance d'une MainWindow
 *
 * \param argc int
 * \param argv pointeur sur char
 * \return int
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowLaunchDialog w;

    w.show();
    return a.exec();
}

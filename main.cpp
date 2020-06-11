/**
 *   \file main.cpp
 *   \author Pollet Lucas - Fougerouse Arsène
 *   \date mai 2020
 *   \brief Fichier main qui instancie la classe MainWindowLaunchDialog
 */
#include "mainwindow.h"
#include "mainwindowlaunchdialog.h"
#include "recette.h"

#include <QApplication>
#include <QObject>

/**
 * \fn int main(int argc, char *argv[])
 * \brief Fonction dans laquelle le programme sera executé. Instancie la MainWindowLaunchDialog qu peremet à l'utilisateur de sélectionner un fichier de recette
 *
 * \param argc: entier
 * \param argv: pointeur sur caractères
 * \return Un entier correspondant à l'état d'execution du programme
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowLaunchDialog w;

    w.show();
    return a.exec();
}

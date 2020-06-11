/**
 *   \file mainwindowlaunchdialog.h
 *   \author Pollet Lucas - Fougerouse Arsène
 *   \date mai 2020
 *   \brief Classe d'affichage permettant l'importation d'un fichier de recette
 */
#ifndef MAINWINDOWLAUNCHDIALOG_H
#define MAINWINDOWLAUNCHDIALOG_H

#include <QDropEvent>
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QMimeData>

#include "ui_mainwindowlaunchdialog.h"
#include "transmission.h"

namespace Ui {
class MainWindowLaunchDialog;
}

class MainWindowLaunchDialog : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * \fn MainWindowLaunchDialog(QWidget *parent)
     * \param parent : précise si le widget hérite d'une autre fenêtre
     * \brief Constructeur de la classe MainWindowLaunchDialog
     */
    explicit MainWindowLaunchDialog(QWidget *parent = nullptr);
    /**
      * \fn ~MainWindowLaunchDialog()
      * \brief Destructeur de la fonction MainWindowLaunchDialog
      */
    ~MainWindowLaunchDialog();
    /**
     * \fn on_actionOuvrir_un_fichier_triggered()
     * \brief Fonction qui réagit quand le bouton pour choisir un fichier est cliqué
     */
    void on_actionOuvrir_un_fichier_triggered();
signals:
    /**
     * \sa envoyerNomFichier(QString path)
     * \brief Signal qui envoie le nom du fichier Json
     * \param path : le chemin du fichier json
     */
    void envoyerNomFichier(QString path);

private slots:
    /**
     * \fn on_pushButton_clicked()
     * \brief Fonction qui réagit quand le bouton pour choisir un fichier est cliqué
     */
    void on_pushButton_clicked();

    /**
     * \fn on_actionQuitter_triggered()
     * \brief Fonction qui permet de quitter l'application au clique
     */
    void on_actionQuitter_triggered();

    /**
     * \fn on_actionDe_Qt_triggered()
     * \brief Fonction qui permet d'ouvrir la fenêtre d'info sur Qt au clique
     */
    void on_actionDe_Qt_triggered();

    /**
     * \fn on_actionDes_developpeurs_triggered()
     * \brief Fonction qui permet d'ouvrir la fenêtre d'info sur les développeurs au clique
     */
    void on_actionDes_developpeurs_triggered();

private:
    Ui::MainWindowLaunchDialog *ui; /*!< Ui::MainWindowLaunchDialog *ui : variable d'instance de la fenêtre ui */

    Transmission *t; /*!< Transmission *t: pointeur sur la classe Transmission */

    /**
     * \fn dropEvent(QDropEvent *event)
     * \brief Fonction qui permet de gérer le glisser/déposer de fichier
     * \param event: instance de l'événement
     */
    void dropEvent(QDropEvent *event);
    /**
     * \fn dragEnterEvent(QDragEnterEvent *event);
     * \brief Fonction qui permet d'accepter les fichiers entrant avec le glisser/déposer
     * \param event: instance de l'événement
     */
    void dragEnterEvent(QDragEnterEvent *event);
};

#endif // MAINWINDOWLAUNCHDIALOG_H

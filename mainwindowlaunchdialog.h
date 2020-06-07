/**
 *   \file mainwindowlaunchdialog.h
 *   \author Pollet Lucas - Fougerouse Arsène
 *
 *   \brief Classe de la fenêtre permettant le choix du fichier json de recette
 */
#ifndef MAINWINDOWLAUNCHDIALOG_H
#define MAINWINDOWLAUNCHDIALOG_H

#include <QDropEvent>
#include <QMainWindow>

namespace Ui {
class MainWindowLaunchDialog;
}

class MainWindowLaunchDialog : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * \fn MainWindowLaunchDialog
     * \param Qwidget *parent
     * \brief Constructeur de la fenêtre de lancement
     */
    explicit MainWindowLaunchDialog(QWidget *parent = nullptr);
    /**
      * \fn ~MainWindowLaunchDialog()
      * \brief Destructeur de la fonction MainWindowLaunchDialog
      */
    ~MainWindowLaunchDialog();

private slots:
    /**
     * \fn on_pushButton_clicked()
     * \brief Fonction qui réagit quand le bouton pour choisir un fichier est cliqué
     */
    void on_pushButton_clicked();

    /**
     * \fn on_actionOuvrir_un_fichier_triggered()
     * \brief Fonction qui réagit quand le bouton pour choisir un fichier est cliqué
     */
    void on_actionOuvrir_un_fichier_triggered();

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

    /**
     * \fn dropEvent(QDropEvent *event)
     * \brief Fonction qui permet de gérer le drop de fichier
     * \param QDropEvent: instance de l'évent
     */
    void dropEvent(QDropEvent *event);
    /**
     * \fn dragEnterEvent(QDragEnterEvent *event);
     * \brief Fonction qui permet d'accepter les fichiers entrant avec le drag and drop
     * \param QDragEnterEvent: instance de l'évent
     */
    void dragEnterEvent(QDragEnterEvent *event);
};

#endif // MAINWINDOWLAUNCHDIALOG_H

//commentaire pour générer la page d'accueil du doxyfile
/*! \mainpage Documentation du Projet Recette
 *
 * \section Mentions légales
 *
 * Copyright(C)2020-2021 Lucas Pollet et Arsène Fougerouse
 *
 * This is the introduction.
 *
 * \section A quoi sert ce programme ?
 *
 * Cette application s'inscrit dans le cadre du projet d'Interface
 * Homme-Machine. Ce projet à été commandité par Mr. Raffin dans le cadre
 * du semestre 2 de DUT Informatique sur le site d'Arles.
 *
 * Cette application fonctionne sous Linux et Windows à condition d'avoir
 * d'avoir un compilateur c++/ Qt Creator d'installé.
 *
 * Au lancement de l'application, l'utilisateur est amené à choisir un fichier
 * de recette au format json qu'il viendra déposer / sélectionner via le pushbouton
 * en bas. L'application ouvre ensuite une autre fenêtre affichant les informations
 * relatives afin de réaliser la recette.
 *
 * \subsection Référence des classes
 * Les classes sont référencées dans l'onglet classes en haut de cette page.
 * La conception à été spécialement pensé dans le but de la MVC.
 */

/**
 *   \file mainwindow.h
 *   \author Pollet Lucas - Fougerouse Arsène
 *
 *   \brief Classe de la fenêtre permettant l'affichage de la recette
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStateMachine>
#include <QDebug>
#include <QEvent>
#include <QMessageBox>
#include <QState>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    /**
      * @fn MainWindow(QWidget *parent)
      * @brief constructeur de la fonction MainWindow
      * @param parent : précise si le widget hérite d'une autre fenêtre
      */
    MainWindow(QWidget *parent = nullptr);

    /**
      * @fn ~MainWindow()
      * @brief destructeur de la fonction MainWindow
      */
    ~MainWindow();

private slots:
    /**
      * @fn nextInstruct()
      * @brief fonction qui permet de passer à l'instruction suivante
      */
    void nextInstruct();
    /**
      * @fn lastInstruct()
      * @brief fonction qui permet de passer à l'instruction précédente
      */
    void lastInstruct();
    /**
      * @fn updateStep()
      * @brief fonction qui met à jour l'instruction affiché à l'écran
      */
    void updateStep();

    void on_actionOuvir_triggered();

    void on_actionQuitter_triggered();

signals:
    /**
      * @sa endChangeState()
      * @brief signal qui annonce la fin du changement d'état
      */
    void endChangeState();

private:
    Ui::MainWindow *ui; /*!< ui: MainWindow contenant l'ui */
    QStateMachine *machine; /*!< machine: machine à état quand on appuie sur les boutons*/
    QStringList listEtapes; /*!< listEtapes: liste de string contenant la liste des étapes*/
    int currentstate = 0; /*!< int currentstate: variable du numero de l'instruction actuelle */

public slots :
    //slots pour modifs les labels
    /**
     * @fn modifNom(QString)
     * @brief slot qui modifie le nom de la recette
     * @param le nom sous forme de chaine de caractère
     */
    void modifNom(QString);

    /**
     * @fn modifDesc(QString)
     * @brief slot qui modifie la description
     * @param la description sous forme de chaine de caractère
     */
    void modifDesc(QString);

     /**
     * @fn modifMotsCles(QString)
     * @brief slot qui modifie les mots cles
     * @param les mots cles sous forme de chaine de caractère
     */
    void modifMotsCles(QString);

    /**
     * @fn modifIng(QStringList)
     * @brief slot qui modifie la liste des ingrédients
     * @param les ingrédients sous forme de liste de chaine de caractere
     */
    void modifIng(QStringList);

    /**
     * @fn modifEtapes(QStringList)
     * @brief slot qui modifie le la liste des etapes
     * @param les étapes sous formes de liste de chaine de caractere
     */
    void modifEtapes(QStringList);

    /**
     * @fn modifTemps(QStringList)
     * @brief slot qui modifie le temps nécessaire pour préparer la recette
     * @param les différents temps sous forme de liste de chaine de caractère
     */
    void modifTemps(QString);

    /**
     * @fn modifURL(QString)
     * @brief slot qui modifie l'url pour accéder à la recette
     * @param l'url sous forme de chaine de caractère
     */
    void modifURL(QString);
};
#endif // MAINWINDOW_H


/**
 *   \file mainwindow.h
 *   \author Pollet Lucas - Fougerouse Arsène
 *   \date mai 2020
 *   \brief Classe qui affiche les informations nécessaires pour préparer la recette
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

    /**
     * @fn on_actionOuvir_triggered()
     * @brief fonction permettant l'ouverture d'un autre fichier en cliquant depuis le menu de la fenêtre
     */
    void on_actionOuvir_triggered();

    /**
     * @fn on_actionOuvir_triggered()
     * @brief fonction permettant la fermeture de l'application en cliquant depuis le menu de la fenêtre
     */
    void on_actionQuitter_triggered();

signals:
    /**
      * @sa endChangeState()
      * @brief signal qui annonce la fin du changement d'état de la machine
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
     * @param nom: le nom sous forme de chaine de caractère
     */
    void modifNom(QString nom);

    /**
     * @fn modifDesc(QString)
     * @brief slot qui modifie la description
     * @param desc: la description sous forme de chaine de caractère
     */
    void modifDesc(QString desc);

     /**
     * @fn modifMotsCles(QString)
     * @brief slot qui modifie les mots cles
     * @param motsCLes: les mots cles sous forme de chaine de caractère
     */
    void modifMotsCles(QString motsCLes);

    /**
     * @fn modifIng(QStringList)
     * @brief slot qui modifie la liste des ingrédients
     * @param listIng: les ingrédients sous forme de liste de chaine de caractere
     */
    void modifIng(QStringList listIng);

    /**
     * @fn modifEtapes(QStringList)
     * @brief slot qui modifie le la liste des etapes
     * @param listEtapes: les étapes sous formes de liste de chaine de caractere
     */
    void modifEtapes(QStringList listEtapes);

    /**
     * @fn modifTemps(QString)
     * @brief slot qui modifie le temps nécessaire pour préparer la recette
     * @param temps: les différents temps sous forme de chaine de caractère
     */
    void modifTemps(QString temps);

    /**
     * @fn modifURL(QString)
     * @brief slot qui modifie l'url pour accéder à la recette
     * @param url: l'url sous forme de chaine de caractère
     */
    void modifURL(QString url);
};
#endif // MAINWINDOW_H

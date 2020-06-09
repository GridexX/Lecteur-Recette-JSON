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
    void nextInstruct();
    void lastInstruct();
    void updateStep();

signals:
    void endChangeState();

private:
    Ui::MainWindow *ui; /*!< ui: MainWindow contenant l'ui */
    QStateMachine *machine; /*!< machine: machine à état quand on appuie sur les boutons*/
    QStringList listEtapes; /*!< listEtapes: liste de string contenant la liste des étapes*/
    int currentstate = 0;

public slots :
    //slots pour modifs les labels
    void setImage(QString);
    void setImageWhenIsUpload(QNetworkReply *);

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

/**
 *   \file transmission.h
 *   \author Pollet Lucas - Fougerouse Arsène
 *
 *   \brief Classe permettant le transmission des données
 */
#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#include <QObject>

#include "mainwindow.h"
#include "traitement.h"

//nouvelle classe pour faire la transmission des données entre traitement et affichage
//lancé par la mainwindow

class Transmission : public QObject
{
Q_OBJECT
public:
    /**
     * @fn Transmission(QObjet *parent)
     * @brief Constructeur de la fonction Transmission
     * @param parent : objet parent de transmission
     */
    explicit Transmission(QObject *parent = nullptr);

    /**
      * @fn ~Transmission()
      * @brief Destructeur de la fonction Transmission
      */
    ~Transmission();
    /**
     * @fn void setFilePath(QString _filePath)
     * @brief Fonction qui permet de set le chemin du fichier
     * @param QString _filePath
     */
    inline void setFilePath(QString _filePath) { filePath=_filePath; }
    inline Traitement *getTraitement() { return t; }

private:
    Traitement *t; /*!< Traitement *t: Pointeur sur la classe Traitement pour pouvoir l'instancier */
    MainWindow *w; /*!< MainWindow *w: Pointeur sur la classe MainWindow pour pouvoir l'instancier */
    QString filePath=""; /*!< QString filePath: variable qui stocke le chemin du fichier json */
    /**
     * @fn void envoyerDonnees()
     * @brief Fonction qui permet d'envoyer les informations de la recette
     */


public slots:
    /**
     * @fn void recevoirNomFichier(QString)
     * @brief Fonction qui permet de récupérer le chemin du fichier Json
     * @param QString : chemin d'accès du fichier Json
     */
    void envoyerDonnees();

signals:
    /**
     * @fn envoieNomFichier(QString);
     * @brief Sinal qui Fonction qui permet d'envoyer le chemin d'accès du fichier Json
     * @param QString : chemin d'accès du fichier Json
     */


};

#endif // TRANSMISSION_H

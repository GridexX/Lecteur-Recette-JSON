/**
 *   \file transmission.h
 *   \author Pollet Lucas - Fougerouse Arsène
 *   \mai 2020
 *   \brief Classe permettant le transmission des données
 */
#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#include <QObject>

#include "mainwindow.h"
#include "traitement.h"

//nouvelle classe pour faire la transmission des données entre traitement et affichage
//lancée par la mainwindow

class Transmission : public QObject
{
Q_OBJECT
public:
    /**
     * @fn Transmission(QObjet *parent)
     * @brief Constructeur de la fonction Transmission
     * @param parent: précise si le widget hérite d'un autre object
     */
    explicit Transmission(QObject *parent = nullptr);

    /**
      * @fn ~Transmission()
      * @brief Destructeur de la fonction Transmission
      */
    ~Transmission();

    /**
     * @fn void setFilePath(QString _filePath)
     * @brief Fonction qui permet de définir le chemin du fichier
     * @param QString _filePath
     */
    inline void setFilePath(QString _filePath) { filePath=_filePath; }

    /**
     * @fn getTraitement()
     * @brief Fonction getter pour obtenir l'instance de la classe Traitement
     * @return Un pointeur sur Traitement
     */
    inline Traitement *getTraitement() { return t; }

private:
    Traitement *t; /*!< Traitement *t: Pointeur sur la classe Traitement pour pouvoir l'instancier */
    MainWindow *w; /*!< MainWindow *w: Pointeur sur la classe MainWindow pour pouvoir l'instancier */
    QString filePath=""; /*!< QString filePath: variable qui stocke le chemin du fichier json */


public slots:
    /**
     * @fn void envoyerDonnees
     * @brief Fonction qui envoie les attributes de la classe Recette à la MainWindow
     */
    void envoyerDonnees();

signals:


};

#endif // TRANSMISSION_H

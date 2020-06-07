/**
 *   \file traitement.h
 *   \author Pollet Lucas - Fougerouse Arsène
 *
 *   \brief Classe permettant le traitement json
 */
#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "recette.h"
#include "mainwindow.h"

class traitement
{
public :
    /**
     * \fn traitement(QJsonDocument)
     * \brief Constructeur du traitemment json
     * \param QJsonDocument : chemin d'accès du fichier json de la recette
     */
    traitement(QJsonDocument);
    /**
     * \fn setRecette()
     * \brief Fonction qui permet de lire le fichier et enregistrer la recette
     */
    void setRecette();
    /**
     * \fn connection()
     * \brief Fonction qui permet d'initialiser l'instance et la connexion
     */
    void connection();

private :
    QJsonDocument docJson; /*!< docJson: le chemin d'accès du fichier json */
    Recette *recette; /*!< Recette *recette: pointeur sur la variable recette */
    MainWindow *w;  /*!< Mainwindow *w: pointeur sur la fenetre principale */

};

#endif // TRAITEMENT_H

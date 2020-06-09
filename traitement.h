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
#include <QObject>
#include "recette.h"
#include "lecture_json.h"

class Traitement : public QObject
{
Q_OBJECT
public :

    /**
     * \fn traitement(QJsonDocument)
     * \brief Constructeur du traitemment json
     * \param QJsonDocument : chemin d'accès du fichier json de la recette
     */
    explicit Traitement(QObject *parent = nullptr);
    /**
     * \fn setRecette()
     * \brief Fonction qui permet de lire le fichier et enregistrer la recette
     */

    inline Recette *getRecette() { return recette; }

private :

    Recette *recette; /*!< Recette *recette: pointeur sur la variable recette */
    lecture_json *lecJson;                 /*!< Mainwindow *w: pointeur sur la fenetre principale */


signals:
    /**
        * @sa envoieNom(QString)
        * @brief fonction pour envoyer le nom à la classe MainWindow (voir classe MainWindow)
        * @param nom : le nom à transmettre
        */
       void envoieNom(QString);

       /**
        * @sa envoieDesc(QString)
        * @brief fonction pour envoyer la description à la classe MainWindow (voir classe MainWindow)
        * @param desc : la description à transmettre
        */
       void envoieDesc(QString);

       /**
        * @sa envoieMotsCles(QString)
        * @brief fonction pour envoyer les mots cles à la classe MainWindow (voir classe MainWindow)
        * @param MotsCles : les mots cles à transmettre
        */
       void envoieMotsCles(QString);

       /**
        * @sa envoieIng(QStringList)
        * @brief fonction pour envoyer la liste des ingrédients à la classe MainWindow (voir classe MainWindow)
        * @param ingredients : la liste des ingrédients à transmettre
        */
       void envoieIng(QStringList);

       /**
        * @sa envoieEtapes(QStringList)
        * @brief fonction pour envoyer la liste des étapes à la classe MainWindow (voir classe MainWindow)
        * @param étapes : la liste des étapes à transmettre
        */
       void envoieEtapes(QStringList);

       /**
        * @sa envoieTemps(QStringList)
        * @brief fonction pour envoyer les temps à la classe MainWindow (voir classe MainWindow)
        * @param temps : la liste des temps à transmettre
        */
       void envoieTemps(QStringList);

       /**
        * @sa envoieURL(QStringList)
        * @brief fonction pour envoyer l'url à la classe MainWindow (voir classe MainWindow)
        * @param url : l'url du site web de la recette à transmettre
        */
       void envoieURL(QString);

       //void envoieDocJson(QJsonDocument);

       void envoieNomFichier(QString);

public slots :

       void recevoirNomFichier(QString);
       void recevoirDocJson(QJsonDocument);
};

#endif // TRAITEMENT_H

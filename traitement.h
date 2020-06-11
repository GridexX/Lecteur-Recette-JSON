/**
 *   \file traitement.h
 *   \author Pollet Lucas - Fougerouse Arsène
 *   \date mai 2020
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
     * \fn Traitement(QObject *parent)
     * \brief Constructeur de la classe Traitement
     * \param parent : précise si le widget hérite d'une autre fenêtre
     */
    explicit Traitement(QObject *parent = nullptr);

    /**
     * \fn ~Traitement()
     * \brief Destructeur de la classe Traitement
     */
    ~Traitement();

    /**
     * @fn getRecette()
     * @brief Fonction getter pour obtenir l'instance de la classe Recette
     * @return Un pointeur sur Recette
     */
    inline Recette *getRecette() { return recette; }

    /**
     * @fn getLecture()
     * @brief Fonction getter pour obtenir l'instance de la classe lecture_json
     * @return Un pointeur sur lecture_json
     */
    inline lecture_json *getLecture() { return lecJson; }

private :

    Recette *recette;         /*!< Recette *recette: pointeur sur la variable recette */
    lecture_json *lecJson;    /*!< Mainwindow *w: pointeur sur la fenetre principale */


signals:
    /**
        * @sa envoieNom(QString nom)
        * @brief Fonction (signal) pour envoyer le nom à la classe MainWindow (voir classe MainWindow)
        * @param nom: le nom à transmettre
        */
       void envoieNom(QString nom);

       /**
        * @sa envoieDesc(QString desc)
        * @brief Fonction (signal) pour envoyer la description à la classe MainWindow (voir classe MainWindow)
        * @param desc: la description à transmettre
        */
       void envoieDesc(QString desc);

       /**
        * @sa envoieMotsCles(QString motsCles)
        * @brief Fonction (signal) pour envoyer les mots cles à la classe MainWindow (voir classe MainWindow)
        * @param MotsCles: les mots cles à transmettre
        */
       void envoieMotsCles(QString motsCles);

       /**
        * @sa envoieIng(QStringList listIng)
        * @brief Fonction (signal) pour envoyer la liste des ingrédients à la classe MainWindow (voir classe MainWindow)
        * @param listIng: la liste des ingrédients à transmettre
        */
       void envoieIng(QStringList listIng);

       /**
        * @sa envoieEtapes(QStringList listEtapes)
        * @brief Fonction (signal) pour envoyer la liste des étapes à la classe MainWindow (voir classe MainWindow)
        * @param listEtapes: la liste des étapes à transmettre
        */
       void envoieEtapes(QStringList listEtapes);

       /**
        * @sa envoieTemps(QString temps)
        * @brief Fonction (signal) pour envoyer les temps à la classe MainWindow (voir classe MainWindow)
        * @param temps: les temps à transmettre
        */
       void envoieTemps(QString temps);

       /**
        * @sa envoieURL(QString url)
        * @brief Fonction (signal) pour envoyer l'url à la classe MainWindow (voir classe MainWindow)
        * @param url: l'url du site web de la recette à transmettre
        */
       void envoieURL(QString url);

       /**
        * @sa finTraitement
        * @brief Fonction (signal) qui est émis quand le traitement est terminé
        */
       void finTraitement();

public slots :

       /**
        * @sa recevoirDocJson(QJsonDocument docJson)
        * @brief Fonction qui recoit le document JSON pour le traiter et lire ses données
        * @param docJson :le document JSON à traiter
        */
       void recevoirDocJson(QJsonDocument docJson);
};

#endif // TRAITEMENT_H

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
 *   \file lecture_json.h
 *   \author Pollet Lucas - Fougerouse Arsène
 *
 *   \brief Classe gérant la lecture du fichier json
 */
#ifndef LECTURE_JSON_H
#define LECTURE_JSON_H

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QObject>

class lecture_json : public QObject
{
    Q_OBJECT
public:
    /**
     * @fn lecture_json(QString path)
     * @brief fonction permettant l'initialisation de la lecture du fichier json
     * @param path : QString qui renvoie le chemin du fichier
     */
    explicit lecture_json(QObject *parent = nullptr);
private:
    QString path; /*!< path: chemin d'accès du fichier json */

public slots:
    /**
     * @fn recevoirNomFichier(QString)
     * @brief fonction qui permet de vérifier le fichier json et de d'envoyer une demande de traitement
     * @param QString path : QString qui renvoie le chemin du fichier
     */
    void recevoirNomFichier(QString);
signals :
    /**
     * @sa envoieDocJson(QJsonDocument)
     * @brief signal d'envoie du document Json
     * @param QJSonDocument : qui renvoie le document Json
     */
    void envoieDocJson(QJsonDocument);
};

#endif // LECTURE_JSON_H

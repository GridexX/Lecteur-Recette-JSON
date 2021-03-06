//commentaire pour générer la page d'accueil du doxyfile
/*! \mainpage Documentation du Projet Recette IHM
 * Cette application s'inscrit dans le cadre du projet d'Interface
 * Homme-Machine. Ce projet à été commandité par Mr. Raffin dans le cadre
 * du semestre 2 de DUT Informatique sur le site d'Arles.
 *
 * \section utilite A quoi sert ce programme ?
 *
 *
 * Au lancement de l'application, l'utilisateur est amené à choisir un fichier
 * de recette au format json qu'il viendra déposer / sélectionner via le pushbouton
 * en bas.<br> L'application ouvre ensuite une autre fenêtre affichant les informations
 * relatives afin de réaliser la recette. <br>
 * <strong>Prérequis :</strong>
 * Le programme nécessite d'être lancé sur un ordinateur <i>Windows</i> ou <i>Linux</i> et
 * d'avoir un compilateur C++/ Qt Creator d'installé. Voir la doc <a href=http://www.mingw.org>MinGW</a> pour plus d'informations.
 *
 *
 * \section mentions Mentions légales
 *
 * Copyright(C) 2020-2021 <a href = " mailto: lucas.pollet@etu.univ-amu.fr">Lucas Pollet</a> et <a href = " mailto: arsene.fougerouse@etu.univ-amu.fr">Arsène Fougerouse</a>
 *
 *
 *
 * \subsection references Référence des classes
 * Les classes sont référencées <a href=file:///home/gridexx/projet-recette-json/doc/html/annotated.html>ici</a>.
 * Pour plus de précision, veuillez voir la liste déroulante de l'onglet classe ou la documentation pdf.<br>
 * La conception a été spécialement pensé dans le but de la MVC.
 */

/**
 *   \file lecture_json.h
 *   \author Pollet Lucas - Fougerouse Arsène
 *   \date mai 2020
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
     * @fn lecture_json(QObject *parent)
     * @brief constructeur de la fonction lecture_json
     * @param parent : précise si le widget hérite d'un autre object
     */
    explicit lecture_json(QObject *parent = nullptr);


private:
    QString path; /*!< path: chemin d'accès du fichier json */

    /**
     * @fn verifFichier
     * @brief fonction qui vérifie si le fichier est lisible et interpretable.
     */
    void verifFichier();

public slots:
    /**
     * @fn recevoirNomFichier(QString path)
     * @brief slot qui modifie la donnée membre path
     * @param path : QString qui spécifie le chemin du fichier
     */
    void recevoirNomFichier(QString path);
signals :
    /**
     * @sa envoieDocJson(QJsonDocument docJson)
     * @brief signal qui envoie le fichier de recette
     * @param docJson : le document au format json
     */
    void envoieDocJson(QJsonDocument docJson);
};

#endif // LECTURE_JSON_H

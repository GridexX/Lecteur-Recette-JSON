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

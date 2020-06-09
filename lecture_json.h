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
    QString path;

public slots:
    void recevoirNomFichier(QString);
signals :
    void envoieDocJson(QJsonDocument);
};

#endif // LECTURE_JSON_H

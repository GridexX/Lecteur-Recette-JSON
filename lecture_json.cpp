/**
 *   \file lecture_json.cpp
 *   \author Pollet Lucas - Fougerouse Arsène
 *
 *   \brief Classe gérant la lecture du fichier json
 */
#include "lecture_json.h"


lecture_json::lecture_json(QObject *parent) : QObject(parent)

{
}

void lecture_json::recevoirNomFichier(QString path)
{
    QFile fichier(path);
    QJsonParseError error;

    //Ouverture du fichier en lecture uniquement
    if(fichier.open(QFile::ReadOnly)) {
       //Récupération du contenu du fichier
       QByteArray donnees = fichier.readAll();

       //Interprétation du fichier JSON
       QJsonDocument doc = QJsonDocument::fromJson(donnees, &error);
       if(error.error != QJsonParseError::NoError)
           qCritical() << "Impossible d’interpréter le fichier : " << error.errorString();

       else
            emit(envoieDocJson(doc));

    }
    else
        qCritical() << "Impossible de lire le fichier : " << error.errorString();
}

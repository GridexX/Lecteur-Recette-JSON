#include "lecture_json.h"
#include "mainwindow.h"

#include <QFile>
#include <QJsonDocument>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>

//classe permettant la lecture du fichier JSON selectionné
lecture_json::lecture_json(QString path)
{
    recette = new Recette();

    QFile fichier(path);
    QJsonParseError error;

    //Ouverture du fichier en lecture uniquement
    if(fichier.open(QFile::ReadOnly)) {
       //Récupération du contenu du fichier
       QByteArray donnees = fichier.readAll();

       //Interprétation du fichier JSON
       QJsonDocument doc = QJsonDocument::fromJson(donnees, &error);
       if(error.error != QJsonParseError::NoError)
       {
           qCritical() << "Impossible d’interpréter le fichier : " << error.errorString();
       }
       else
       {
          QJsonObject obj=doc.object();

            recette->setNom(obj.value("name").toString());
            recette->setDescription(obj.value("description").toString());

            QJsonValue val = obj.value("recipeIngredient");
            QJsonArray valArray = val.toArray();

            QStringList ingredient;
            for (auto value: valArray)
                ingredient.append(value.toString());

            recette->setListeIngredients(ingredient);

           val = obj.value("recipeInstructions");
           valArray = val.toArray();

           QStringList instruction;
           for (auto value: valArray)
               instruction.append(value.toString());

           recette->setListeEtapes(instruction);

           recette->setTotalTime(obj.value("totalTime").toString());

           recette->setURL(obj.value("url").toString());

           //ouverture de la fenetre principale
           MainWindow * w = new MainWindow(nullptr, instruction.size());
           w->show();
       }
    }
    else {
        qCritical() << "Impossible de lire le fichier : " << error.errorString();
    }
}

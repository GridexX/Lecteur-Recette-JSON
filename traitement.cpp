/**
 *   \file traitement.cpp
 *   \author Pollet Lucas - Fougerouse Arsène
 *
 *   \brief Classe permettant le traitement json
 */
#include "traitement.h"

Traitement::Traitement(QObject *parent)
    : QObject(parent), recette(nullptr), lecJson(nullptr)
{
    recette = new Recette;
    lecJson = new lecture_json;

    //connect pour envoyer le chemin du fichier à la lecture
    QObject::connect(this,SIGNAL(envoieNomFichier(QString)),lecJson,SLOT(recevoirNomFichier(QString)));

    //connect pour récupérer le doc au format JSON depuis la lecture
    QObject::connect(lecJson,SIGNAL(envoieDocJson(QJsonDocument)),this,SLOT(recevoirDocJson(QJsonDocument)));
}



void Traitement::recevoirDocJson(QJsonDocument docJson)
{
    QJsonObject obj=docJson.object();


    recette->setNom(obj.value("name").toString());
    recette->setDescription(obj.value("description").toString());
    recette->setMotsCles(obj.value("keywords").toString());

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
    QStringList temps ;
    temps << (obj.value("prepTime")).toString();
    temps << (obj.value("cookTime")).toString();
    temps << (obj.value("totalTime")).toString();

    recette->setTemps(temps);

    recette->setURL(obj.value("url").toString());

}


void Traitement::recevoirNomFichier(QString chemin)
{
    emit(envoieNomFichier(chemin));
}

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
    //QObject::connect(this,SIGNAL(envoieNomFichier(QString)),lecJson,SLOT(recevoirNomFichier(QString)));

    //connect pour récupérer le doc au format JSON depuis la lecture
    QObject::connect(lecJson,SIGNAL(envoieDocJson(QJsonDocument)),this,SLOT(recevoirDocJson(QJsonDocument)));
}

Traitement::~Traitement()
{
    delete recette;
    delete lecJson;
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

    QString tempsPrep=temps[0];
    QString tempsCuis=temps[1];
    QString strTP, strTC, strTT;
    bool doitAfficheTT=true;
    QRegExp calcM("([0-9]*)M");
    QRegExp calcH("([0-9]*)H");

    calcM.indexIn(tempsPrep);
    calcH.indexIn(tempsPrep);

    if (calcH.cap(1).toInt() != 0 || calcM.cap(1).toInt() != 0)
        strTP = ("Temps de préparation : " + calcH.cap(1) + "h" + calcM.cap(1));
    else{
        strTP="";
        doitAfficheTT=false;
    }
    int tempsTotalH = calcH.cap(1).toInt();
    int tempsTotalM = calcM.cap(1).toInt();

    calcM.indexIn(tempsCuis);
    calcH.indexIn(tempsCuis);
    tempsTotalH += calcH.cap(1).toInt();
    tempsTotalM += calcM.cap(1).toInt();

    if (calcH.cap(1).toInt() != 0 || calcM.cap(1).toInt() != 0)
        strTC =  " | Temps de cuisson : " + calcH.cap(1) + "h" + calcM.cap(1);
    else {
        strTC="";
        doitAfficheTT=false;
    }
    if(doitAfficheTT)
        strTT =  " | Temps total : " + QString::number(tempsTotalH) + " h" + QString::number(tempsTotalM);
    else
        strTT="";

    QString allTime = strTP + strTC + strTT;
    recette->setTemps(allTime);

    recette->setURL(obj.value("url").toString());


    emit(finTraitement());
}


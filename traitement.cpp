/**
 *   \file traitement.cpp
 *   \author Pollet Lucas - Fougerouse Arsène
 *   \date mai 2020
 *   \brief Classe permettant le traitement json
 */
#include "traitement.h"

Traitement::Traitement(QObject *parent)
    : QObject(parent), recette(nullptr), lecJson(nullptr)
{
    recette = new Recette;
    lecJson = new lecture_json;

    //connect pour récupérer le doc au format JSON depuis la lecture
    QObject::connect(lecJson,SIGNAL(envoieDocJson(QJsonDocument)),this,SLOT(recevoirDocJson(QJsonDocument)));
}

Traitement::~Traitement()
{
    delete recette;
    delete lecJson;
}

void Traitement::recevoirDocJson(QJsonDocument docJson) //fonction qui parse le json
{
    QJsonObject obj=docJson.object();

    //conversion en un object json puis remplissage des champs de la recette
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


    //partie relative aux calculs des temps
    QString tempsPrep=(obj.value("prepTime")).toString(); //extrait les valeurs correspondantes
    QString tempsCuis=(obj.value("cookTime")).toString();
    QString strTP, strTC, strTT;
    bool doitAfficheTT=true;
    QRegExp calcM("([0-9]*)M"); //indiquer l'expression régulière pour trouver l'heure
    QRegExp calcH("([0-9]*)H"); //indiquer l'expression régulière pour trouver les minutes

    calcM.indexIn(tempsPrep);  //récupérer l'indice des minutes dans la variable
    calcH.indexIn(tempsPrep);  //récupérer l'indice des heures dans la variable

    if (calcH.cap(1).toInt() != 0 || calcM.cap(1).toInt() != 0) //ajoute à la chaine de caracteres le temps s'in n'est pas nul
        strTP = ("Temps de préparation : " + calcH.cap(1) + "h" + calcM.cap(1)); //permet d'ajouter que les temps positif
    else{
        strTP="";
        doitAfficheTT=false;
    }
    int tempsTotalH = calcH.cap(1).toInt(); //on calcule le temps total 'a la main"
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
    if(doitAfficheTT) //ajoute le temps total uniquement si les temps de cuisson et de préparation ont des valeurs positives
        strTT =  " | Temps total : " + QString::number(tempsTotalH) + " h" + QString::number(tempsTotalM);
    else
        strTT="";

    QString allTime = strTP + strTC + strTT; //renvoie une string contenant les différents temps
    recette->setTemps(allTime);

    recette->setURL(obj.value("url").toString());


    emit(finTraitement());  //envoie un signal de fin de Traitement pour que la classe Transmission envoie les données
}


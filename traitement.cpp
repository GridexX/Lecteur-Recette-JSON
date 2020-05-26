#include "traitement.h"

traitement::traitement(QJsonDocument _doc)
    : docJson(_doc)
{
}


void traitement::connection()
{
    //Initialisation de la fenetre et de la classe recette
    recette = new Recette;
    w = new MainWindow;

    //connection entre les classes pour signaux/slots
    QObject::connect(recette,SIGNAL(envoieNom(QString)),w,SLOT(modifNom(QString)));
    QObject::connect(recette,SIGNAL(envoieDesc(QString)),w,SLOT(modifDesc(QString)));
    QObject::connect(recette,SIGNAL(envoieIng(QStringList)),w,SLOT(modifIng(QStringList)));
    QObject::connect(recette,SIGNAL(envoieEtapes(QStringList)),w,SLOT(modifEtapes(QStringList)));
    QObject::connect(recette,SIGNAL(envoieTemps(QStringList)),w,SLOT(modifTemps(QStringList)));
    QObject::connect(recette,SIGNAL(envoieURL(QString)),w,SLOT(modifURL(QString)));
    QObject::connect(recette,SIGNAL(envoieMotsCles(QString)),w,SLOT(modifMotsCles(QString)));

    //appel de la fonction de parsage du json
    this->setRecette();
}


void traitement::setRecette()
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

     //ouverture de la fenetre principale une fois le traitement terminé

    w->show();
}


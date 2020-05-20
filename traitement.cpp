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
    QObject::connect(recette,SIGNAL(envoieTemps(QString)),w,SLOT(modifTemps(QString)));
    // a ajouter QObject::connect(recette,SIGNAL(envoieURL(QString)),w,SLOT(modifURL(QUrl)));

    //appel de la fonction de parsage du json
    this->setRecette();
}


void traitement::setRecette()
{
    QJsonObject obj=docJson.object();


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

    //recette->setURL(obj.value("url").toUrl); //a modif
    //QUrl *url=new QUrl(obj.value("url"));
    //recette->setURL(obj.value("url").setUrl);



     //ouverture de la fenetre principale une fois le traitement terminé

    w->show();
}


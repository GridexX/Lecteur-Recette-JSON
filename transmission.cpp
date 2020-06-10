/**
 *   \file transmission.cpp
 *   \author Pollet Lucas - Fougerouse Arsène
 *
 *   \brief Classe permettant le transmission des données
 */
#include "transmission.h"

Transmission::Transmission(QObject *parent)
    : QObject(parent)
{
    t = new Traitement;
    w = new MainWindow;

    //connection entre cette classe et le traitement pour envoyer le nom du fichier
    //connect(this,SIGNAL(envoieNomFichier(QString)),t,SLOT(recevoirNomFichier(QString)));
   connect(t->getLecture(),SIGNAL(envoieDocJson(QJsonDocument)),t,SLOT(recevoirDocJson(QJsonDocument)));
   connect(t,SIGNAL(finParsing()),this,SLOT(envoyerDonnees()));

    //connection entre signaux de la classe traitement et mainwindow
    connect(t,SIGNAL(envoieNom(QString)),w,SLOT(modifNom(QString)));
    connect(t,SIGNAL(envoieDesc(QString)),w,SLOT(modifDesc(QString)));
    connect(t,SIGNAL(envoieIng(QStringList)),w,SLOT(modifIng(QStringList)));
    connect(t,SIGNAL(envoieEtapes(QStringList)),w,SLOT(modifEtapes(QStringList)));
    connect(t,SIGNAL(envoieTemps(QString)),w,SLOT(modifTemps(QString)));
    connect(t,SIGNAL(envoieURL(QString)),w,SLOT(modifURL(QString)));
    connect(t,SIGNAL(envoieMotsCles(QString)),w,SLOT(modifMotsCles(QString)));

}


Transmission::~Transmission()
{
}

void Transmission::envoyerDonnees()
{
    //envoie le nom du fichier au traitement
   // emit(envoieNomFichier(filePath));

    emit(t->envoieNom(t->getRecette()->getNom()));
    emit(t->envoieDesc(t->getRecette()->getDescription()));
    emit(t->envoieIng(t->getRecette()->getListeIngredients()));
    emit(t->envoieEtapes(t->getRecette()->getListeEtapes()));
    emit(t->envoieTemps(t->getRecette()->getTemps()));
    emit(t->envoieURL(t->getRecette()->getURL()));
    emit(t->envoieMotsCles(t->getRecette()->getMotsCles()));

    w->show();
}

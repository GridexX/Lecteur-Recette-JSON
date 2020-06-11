/**
 *   \file transmission.cpp
 *   \author Pollet Lucas - Fougerouse Arsène
 *   \date mai 2020
 *   \brief Classe permettant le transmission des données
 */
#include "transmission.h"

Transmission::Transmission(QObject *parent)
    : QObject(parent)
{
    t = new Traitement;
    w = new MainWindow;

    //connection entre cette classe et le traitement pour envoyer les données
    QObject::connect(t,SIGNAL(finTraitement()),this,SLOT(envoyerDonnees()));

    //connection entre signaux de la classe traitement et mainwindow pour changer les champs
    QObject::connect(t,SIGNAL(envoieNom(QString)),w,SLOT(modifNom(QString)));
    QObject::connect(t,SIGNAL(envoieDesc(QString)),w,SLOT(modifDesc(QString)));
    QObject::connect(t,SIGNAL(envoieIng(QStringList)),w,SLOT(modifIng(QStringList)));
    QObject::connect(t,SIGNAL(envoieEtapes(QStringList)),w,SLOT(modifEtapes(QStringList)));
    QObject::connect(t,SIGNAL(envoieTemps(QString)),w,SLOT(modifTemps(QString)));
    QObject::connect(t,SIGNAL(envoieURL(QString)),w,SLOT(modifURL(QString)));
    QObject::connect(t,SIGNAL(envoieMotsCles(QString)),w,SLOT(modifMotsCles(QString)));


}

Transmission::~Transmission()
{
    delete t;
    delete w;
}


void Transmission::envoyerDonnees()
{

    emit(t->envoieNom(t->getRecette()->getNom()));
    emit(t->envoieDesc(t->getRecette()->getDescription()));
    emit(t->envoieIng(t->getRecette()->getListeIngredients()));
    emit(t->envoieEtapes(t->getRecette()->getListeEtapes()));
    emit(t->envoieTemps(t->getRecette()->getTemps()));
    emit(t->envoieURL(t->getRecette()->getURL()));
    emit(t->envoieMotsCles(t->getRecette()->getMotsCles()));

    //ouverture de la fenêtre une fois les opérations terminées
    w->show();
}

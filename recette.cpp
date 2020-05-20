#include "recette.h"

Recette::Recette(QObject *parent) : QObject(parent)
{

}

QString Recette::getNom() const
{
    return nom;
}

void Recette::setNom(const QString &value)
{
    emit envoieNom(value);
}

QString Recette::getDescription() const
{
    return description;
}

void Recette::setDescription(const QString &value)
{
    emit envoieDesc(value);
}

QStringList Recette::getListeIngredients() const
{
    return listeIngredients;
}

void Recette::setListeIngredients(const QStringList &value)
{
    emit envoieIng(value);
}

QStringList Recette::getListeEtapes() const
{
    return listeEtapes;
}

void Recette::setListeEtapes(const QStringList &value)
{
    emit envoieEtapes(value);
}

QString Recette::getTotalTime() const
{
    return totalTime;
}

void Recette::setTotalTime(const QString &value)
{
    emit envoieTemps(value);
}


/*
 *
 * A MODIF
QString Recette::getURL() const
{
    return URL;
}

void Recette::setURL(const QString &value)
{
    URL = value;
}*/

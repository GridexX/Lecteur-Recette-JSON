/**
 *   \file recette.cpp
 *   \author Pollet Lucas - Fougerouse Arsène
 *   \date mai 2020
 *   \brief Classe permettant la gestion et le stockage de la recette
 */
#include "recette.h"

Recette::Recette(QObject *parent) : QObject(parent)
{

}

QString Recette::getNom() const
{
    return nom;
}

void Recette::setNom(const QString &_nom)
{
    nom=_nom;
}

QString Recette::getDescription() const
{
    return description;
}

void Recette::setDescription(const QString &_description)
{
    description=_description;
}

QStringList Recette::getListeIngredients() const
{
    return listeIngredients;
}

void Recette::setListeIngredients(const QStringList &_listeIngredients)
{
    listeIngredients=_listeIngredients;
}

QStringList Recette::getListeEtapes() const
{
    return listeEtapes;
}

void Recette::setListeEtapes(const QStringList &_listeEtapes)
{
    listeEtapes=_listeEtapes;
}

QString Recette::getTemps() const
{
    return temps;
}

void Recette::setTemps(const QString &_temps)
{
    temps=_temps;
}

QString Recette::getURL() const
{
    return URL;
}

void Recette::setURL(const QString &_URL)
{
    URL=_URL;
}

QString Recette::getMotsCles() const
{
    return motsCles;
}

void Recette::setMotsCles(const QString &_motsCles)
{
    motsCles=_motsCles;
}

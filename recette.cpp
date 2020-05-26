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

QStringList Recette::getTemps() const
{
    return temps;
}

void Recette::setTemps(const QStringList &value)
{
    emit envoieTemps(value);
}

QString Recette::getURL() const
{
    return URL;
}

void Recette::setURL(const QString &value)
{
    emit envoieURL(value);
}

QString Recette::getMotsCles() const
{
    return motsCles;
}

void Recette::setMotsCles(const QString &value)
{
    emit envoieMotsCles(value);
}

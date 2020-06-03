/**
 *   \file recette.h
 *   \author Pollet Lucas - Fougerouse Arsène
 *
 *   \brief Classe permettant la gestion et le stockage de la recette
 */
#ifndef RECETTE_H
#define RECETTE_H

#include <QObject>

class Recette : public QObject
{
    Q_OBJECT
public:
    explicit Recette(QObject *parent = nullptr);
    QString getNom() const;
    void setNom(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    QStringList getListeIngredients() const;
    void setListeIngredients(const QStringList &value);

    QStringList getListeEtapes() const;
    void setListeEtapes(const QStringList &value);

    QStringList getTemps() const;
    void setTemps(const QStringList &value);

    QString getURL() const;
    void setURL(const QString &value);

    QString getMotsCles() const;
    void setMotsCles(const QString &value);

private:
    QString nom;
    QString description;
    QString motsCles;
    QStringList listeIngredients;
    QStringList listeEtapes;
    QStringList temps;
    QString URL;

signals:
    void envoieNom(QString);
    void envoieDesc(QString);
    void envoieMotsCles(QString);
    void envoieIng(QStringList);
    void envoieEtapes(QStringList);
    void envoieTemps(QStringList);
    void envoieURL(QString);
};

#endif // RECETTE_H

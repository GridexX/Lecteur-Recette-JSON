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

    QString getTotalTime() const;
    void setTotalTime(const QString &value);

    QUrl * getURL() const;
    void setURL(const QUrl *value);

private:
    QString nom;
    QString description;
    QStringList listeIngredients;
    QStringList listeEtapes;
    QString totalTime;
    QUrl *URL;


signals:
    void envoieNom(QString);
    void envoieDesc(QString);
    void envoieIng(QStringList);
    void envoieEtapes(QStringList);
    void envoieTemps(QString);
    void envoieURL(QUrl *);

};

#endif // RECETTE_H

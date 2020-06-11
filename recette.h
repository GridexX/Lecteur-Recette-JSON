/**
 *   \file recette.h
 *   \author Pollet Lucas - Fougerouse Arsène
 *   \date mai 2020
 *   \brief Classe qui stocke sous forme d'attribut les informations d'une recette
 */
#ifndef RECETTE_H
#define RECETTE_H

#include <QObject>

class Recette : public QObject
{
    Q_OBJECT
public:
    /**
     * @fn Recette(QObject *parent)
     * @brief Constructeur de la classe Recette
     * @param parent : précise si le widget hérite d'un autre object
     */
    explicit Recette(QObject *parent = nullptr);

    /**
     * @fn getNom()
     * @brief Fonction getter pour obtenir le nom de la recette
     * @return Le nom en chaine de caractères
     */
    QString getNom() const;

    /**
     * @fn setNom(const QString &nom)
     * @brief fonction setter pour modifier le nom de la recette
     * @param nom: le nom de la recette de cuisine
     */
    void setNom(const QString &nom);

    /**
     * @fn getDescription() const
     * @brief Fonction getter pour obtenir la description de la recette
     * @return La description
     */
    QString getDescription() const;

    /**
     * @fn setDescription(const QString &desc)
     * @brief fonction setter pour modifier le nom de la recette
     * @param desc: la description de la recette de cuisine
     */
    void setDescription(const QString &desc);

    /**
     * @fn getListeIngredients()
     * @brief Fonction getter pour obtenir la liste des ingrédient de la recette
     * @return La liste des ingrédients
     */
    QStringList getListeIngredients() const;

    /**
     * @fn setListeIngredients(const QStringList &listeIng)
     * @brief Fonction setter pour modifier le nom de la recette
     * @param listeIng: la liste d'ingrédient de la recette de cuisine
     */
    void setListeIngredients(const QStringList &listeIng);

    /**
     * @fn getListeEtapes()
     * @brief Fonction getter pour obtenir la liste des étapes de la recette
     * @return La liste des étapes
     */
    QStringList getListeEtapes() const;

    /**
     * @fn setListeEtapes(const QStringList &listeEtapes)
     * @brief Fonction setter pour modifier la liste des étapes de la recette
     * @param listEtapes: la liste d'étapes de la recette de cuisine
     */
    void setListeEtapes(const QStringList &listeEtapes);

    /**
     * @fn getTemps()
     * @brief Fonction getter pour obtenir les différents temps de la recette
     * @return Les temps de préparation, cuisson et totaux
     */
    QString getTemps() const;

    /**
     * @fn setTemps(const QString &temps)
     * @brief Fonction setter pour modifier les différents temps de la recette
     * @param temps: les différents temps de la recette de cuisine
     */
    void setTemps(const QString &temps);

    /**
     * @fn getURL()
     * @brief Fonction getter pour obtenir l'url de la recette
     * @return L'url du site web
     */
    QString getURL() const;

    /**
     * @fn setURL(const QString &url)
     * @brief Fonction setter pour modifier les différents temps de la recette
     * @param url: l'url de la recette de cuisine
     */
    void setURL(const QString &url);

    /**
     * @fn getMotsCles()
     * @brief Fonction getter pour obtenir les mots-clés de la recette
     * @return Les mots-clés
     */
    QString getMotsCles() const;

    /**
     * @fn setMotsCles(const QString &motsCles)
     * @brief Fonction setter pour modifier les mots clés de la recette
     * @param motsCles: les mots clés de la recette de cuisine
     */
    void setMotsCles(const QString &motsCles);

private:
    QString nom; /*!< nom: Le nom de la recette */
    QString description; /*!< description: La description de la recette */
    QString motsCles; /*!< motsCles: Les mots-clefs  de la recette */
    QStringList listeIngredients; /*!< listeIngredients: La liste des ingrédients de la recette */
    QStringList listeEtapes; /*!< listeEtapes: La liste des étapes de la recette */
    QString temps; /*!< temps: les différents temps pour réaliser la recette */
    QString URL; /*!< URL: L'url pour accéder à la page web de la recette */

};

#endif // RECETTE_H

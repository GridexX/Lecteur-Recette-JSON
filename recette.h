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
    /**
     * @fn Recette(QObject *parent)
     * @brief constructeur de la classe Recette
     * @param parent : précise si le widget hérite d'une autre fenêtre
     */
    explicit Recette(QObject *parent = nullptr);

    /**
     * @fn getNom()
     * @brief fonction getter pour obtenir le nom de la recette
     */
    QString getNom() const;

    /**
     * @fn setNom(const QStringList &)
     * @brief fonction setter pour modifier le nom de la recette
     * @param value : le nom de la recette de cuisine
     */
    void setNom(const QString &value);

    /**
     * @fn getDescription() const
     * @brief fonction getter pour obtenir la description de la recette
     */
    QString getDescription() const;

    /**
     * @fn setDescription(const QStringList &)
     * @brief fonction setter pour modifier le nom de la recette
     * @param value : la description de la recette de cuisine
     */
    void setDescription(const QString &value);

    /**
     * @fn getListeIngredients()
     * @brief fonction getter pour obtenir la liste des ingrédient de la recette
     */
    QStringList getListeIngredients() const;

    /**
     * @fn setListeIngredients(const QStringList &)
     * @brief fonction setter pour modifier le nom de la recette
     * @param value : la liste d'ingrédient de la recette de cuisine
     */
    void setListeIngredients(const QStringList &value);

    /**
     * @fn getListeEtapes()
     * @brief fonction getter pour obtenir la liste des étapes de la recette
     */
    QStringList getListeEtapes() const;

    /**
     * @fn setListeEtapes(const QStringList &)
     * @brief fonction setter pour modifier la liste des étapes de la recette
     * @param value : la liste d'étapes de la recette de cuisine
     */
    void setListeEtapes(const QStringList &value);

    /**
     * @fn getTemps()
     * @brief fonction getter pour obtenir les différents temps de la recette
     */
    QStringList getTemps() const;

    /**
     * @fn setTemps(const QStringList &)
     * @brief fonction setter pour modifier les différents temps de la recette
     * @param value : les différents temps de la recette de cuisine
     */
    void setTemps(const QStringList &value);

    /**
     * @fn getURL()
     * @brief fonction getter pour obtenir l'url de la recette
     */
    QString getURL() const;

    /**
     * @fn setURL(const QString &)
     * @brief fonction setter pour modifier les différents temps de la recette
     * @param value : l'url de la recette de cuisine
     */
    void setURL(const QString &value);

    /**
     * @fn getMotsCles()
     * @brief fonction getter pour obtenir les mots clés de la recette
     */
    QString getMotsCles() const;

    /**
     * @fn setMotsCles(const QString &)
     * @brief fonction setter pour modifier les mots clés de la recette
     * @param value : les mots clés de la recette de cuisine
     */
    void setMotsCles(const QString &value);

private:
    QString nom; /*!< nom: Le nom de la recette */
    QString description; /*!< description: La description de la recette */
    QString motsCles; /*!< motsCles: Les mots-clefs  de la recette */
    QStringList listeIngredients; /*!< listeIngredients: La liste des ingrédients de la recette */
    QStringList listeEtapes; /*!< listeEtapes: La liste des étapes de la recette */
    QStringList temps; /*!< temps: les différents temps pour réaliser la recette */
    QString URL; /*!< URL: L'url pour accéder à la page web de la recette */

};

#endif // RECETTE_H

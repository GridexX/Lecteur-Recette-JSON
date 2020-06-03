/**
 *   \file lecture_json.h
 *   \author Pollet Lucas - Fougerouse Arsène
 *
 *   \brief Classe gérant la lecture du fichier json
 */
#ifndef LECTURE_JSON_H
#define LECTURE_JSON_H

#include "recette.h"

class lecture_json
{
public:
    /**
     * @fn lecture_json(QString path)
     * @brief fonction permettant l'initialisation de la lecture du fichier json
     * @param path : QString qui renvoie le chemin du fichier
     */
    lecture_json(QString path);
private:
    Recette * recette; /*!< Variable permettant l'accès à l'objet Recette */
};

#endif // LECTURE_JSON_H

#ifndef LECTURE_JSON_H
#define LECTURE_JSON_H

#include "recette.h"

class lecture_json
{
public:
    lecture_json(QString path);
private:
    Recette * recette;
};

#endif // LECTURE_JSON_H

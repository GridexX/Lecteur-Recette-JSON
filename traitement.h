#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "recette.h"
#include "mainwindow.h"

class traitement
{
public :
    traitement(QJsonDocument);
    void setRecette();
    void connection();

private :
    QJsonDocument docJson;
    Recette *recette;
    MainWindow *w;

};

#endif // TRAITEMENT_H

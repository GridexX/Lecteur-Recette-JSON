#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#include <QObject>

#include "mainwindow.h"
#include "traitement.h"

//nouvelle classe pour faire la transmission des données entre traitement et affichage
//lancé par la mainwindow

class Transmission : public QObject
{
Q_OBJECT
public:
    explicit Transmission(QObject *parent = nullptr);
    ~Transmission();
    inline void setFilePath(QString _filePath) { filePath=_filePath; }

private:
    Traitement *t;
    MainWindow *w;
    QString filePath="";
    void envoyerDonnees();

public slots:
    void recevoirNomFichier(QString);

signals :
    void envoieNomFichier(QString);

};

#endif // TRANSMISSION_H

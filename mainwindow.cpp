/**
 *   \file mainwindow.cpp
 *   \author Pollet Lucas - Fougerouse Arsène
 *
 *   \brief Classe de la fenêtre permettant l'affichage de la recette
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QEvent>
#include <QMessageBox>
#include <QState>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(750,550);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::modifNom(QString str)
{
    ui->nameLabel->setText(str);
}

void MainWindow::modifDesc(QString str)
{
    ui->descLabel->setWordWrap(true);
    ui->descLabel->setText(str);
}


void MainWindow::modifTemps(QStringList tempsList)
{
    QString tempsPrep=tempsList[0];
    QString tempsCuis=tempsList[1];
    QString strTP, strTC, strTT;
    bool doitAfficheTT=true;
    QRegExp calcM("([0-9]*)M");
    QRegExp calcH("([0-9]*)H");                                                                     // Expréssion régulière pour récupérer les heures

    calcM.indexIn(tempsPrep);
    calcH.indexIn(tempsPrep);

    if (calcH.cap(1).toInt() != 0 || calcM.cap(1).toInt() != 0)
        strTP = ("Temps de préparation : " + calcH.cap(1) + "h" + calcM.cap(1));
    else{
        strTP="";
        doitAfficheTT=false;
    }
    int tempsTotalH = calcH.cap(1).toInt();
    int tempsTotalM = calcM.cap(1).toInt();

    calcM.indexIn(tempsCuis);
    calcH.indexIn(tempsCuis);
    tempsTotalH += calcH.cap(1).toInt();
    tempsTotalM += calcM.cap(1).toInt();

    if (calcH.cap(1).toInt() != 0 || calcM.cap(1).toInt() != 0)
        strTC =  " | Temps de cuisson : " + calcH.cap(1) + "h" + calcM.cap(1);
    else {
        strTC="";
        doitAfficheTT=false;
    }
    if(doitAfficheTT)
        strTT =  " | Temps total : " + QString::number(tempsTotalH) + " h" + QString::number(tempsTotalM);
    else
        strTT="";
    ui->timeLabel->setText(strTP + strTC + strTT);
}


void MainWindow::modifMotsCles(QString str)
{
    ui->keywordLabel->setWordWrap(true);
    ui->keywordLabel->setText(str);
}

void MainWindow::modifIng(QStringList l)
{
    QString str = l.join("\n");
    ui->lIngLabel->setText(str);
}

void MainWindow::modifURL(QString url)
{
    ui->label_url->setOpenExternalLinks(true);
    ui->label_url->setTextInteractionFlags(Qt::TextBrowserInteraction);

    ui->label_url->setText("URL de la recette: <a href='"+url+"'>"+url+"</a>");
}


void MainWindow::modifEtapes(QStringList list)
{
    ui->listeEtapes->setWordWrap(true);

    //création QStateMachine pour les étapes de préparation
    int size_list = list.size()-1;

    machine = new QStateMachine(this);

    QList<QState *> statelist;

    for(int i=0; i <= size_list; i++){
        QState * state = new QState();

        state->assignProperty(ui->listeEtapes, "text",  list.at(i));
        state->assignProperty(ui->label_8, "text", "étape "+QString::number(i+1) + "/" + QString::number(list.size()));

        machine->addState(state);
        statelist.append(state);

        if(i == 0){
            machine->setInitialState(state);
            connect(state, SIGNAL(entered()), this, SLOT(first_state()));
            connect(state, SIGNAL(exited()), this, SLOT(first_state_exit()));
        }
        if(i == size_list){
            connect(state, SIGNAL(entered()), this, SLOT(last_state()));
            connect(state, SIGNAL(exited()), this, SLOT(last_state_exit()));
        }
    }
    for(int i=0; i <= size_list; i++){
        if(i != size_list){
            statelist[i]->addTransition(ui->button_suivant, SIGNAL(clicked()), statelist[i+1]);
         }
         if(i != 0){
            statelist[i]->addTransition(ui->button_preced, SIGNAL(clicked()), statelist[i-1]);
         }
    }

    machine->start();
}

void MainWindow::first_state()
{
    ui->button_preced->hide();
}

void MainWindow::last_state()
{
    ui->button_suivant->hide();
}

void MainWindow::first_state_exit()
{
    ui->button_preced->show();
}

void MainWindow::last_state_exit()
{
    ui->button_suivant->show();
}

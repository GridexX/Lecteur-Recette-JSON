/**
 *   \file mainwindow.cpp
 *   \author Pollet Lucas - Fougerouse Arsène
 *   \date mai 2020
 *   \brief Classe de la fenêtre permettant l'affichage de la recette
 */
#include "mainwindow.h"
#include "mainwindowlaunchdialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Votre recette");
    setFixedSize(750,550);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete machine;
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


void MainWindow::modifTemps(QString temps)
{
    ui->timeLabel->setText(temps);
}


void MainWindow::modifMotsCles(QString str)
{
    ui->keywordLabel->setWordWrap(true);
    ui->keywordLabel->setText(str);
}

void MainWindow::modifIng(QStringList l)
{
    QString str = l.join("\n");
    ui->Ing_label->setText(str);
}

void MainWindow::modifURL(QString url)
{
    ui->label_url->setOpenExternalLinks(true);
    ui->label_url->setTextInteractionFlags(Qt::TextBrowserInteraction);

    ui->label_url->setText("URL de la recette: <a href='"+url+"'>"+url+"</a>");
}

//Fonctions relatives à la machine à états
void MainWindow::modifEtapes(QStringList list)
{
    ui->listeEtapes->setWordWrap(true);

    listEtapes=list;

    machine = new QStateMachine();

    QState *stateStart = new QState();
    QState *stateRunning = new QState();
    QState *stateEnd = new QState();
    QState *stateInRunningBefore = new QState();
    QState *stateInRunningAfter = new QState();

    stateRunning->addTransition(ui->button_suivant, SIGNAL(clicked()), stateInRunningAfter);
    stateRunning->addTransition(ui->button_preced, SIGNAL(clicked()), stateInRunningBefore);

    stateInRunningAfter->addTransition(this, SIGNAL(endChangeState()), stateRunning);
    stateInRunningBefore->addTransition(this, SIGNAL(endChangeState()), stateRunning);

    stateRunning->addTransition(this, SIGNAL(endChangeState()), stateRunning);
    stateEnd->addTransition(ui->button_preced, SIGNAL(clicked()), stateRunning);

    stateStart->addTransition(ui->button_suivant, SIGNAL(clicked()), stateRunning);
    stateStart->assignProperty(ui->noEtapes, "text", "Appuyez sur suivant pour commencer les instructions.");
    stateStart->assignProperty(ui->listeEtapes, "text", "");

    machine->addState(stateStart);
    machine->addState(stateRunning);
    machine->addState(stateEnd);
    machine->addState(stateInRunningBefore);
    machine->addState(stateInRunningAfter);

    machine->setInitialState(stateStart);

    ui->button_preced->setDisabled(true);

    connect(stateRunning, SIGNAL(entered()), this, SLOT(updateStep()));
    connect(stateInRunningAfter, SIGNAL(entered()), this, SLOT(nextInstruct()));
    connect(stateInRunningBefore, SIGNAL(entered()), this, SLOT(lastInstruct()));

    machine->start();
}

void MainWindow::nextInstruct()
{
    ui->button_suivant->setDisabled(false);
    ui->button_preced->setDisabled(false);

    if(currentstate < listEtapes.size()-1){
        currentstate++;
        emit endChangeState();

        if(currentstate == listEtapes.size()-1)
            ui->button_suivant->setDisabled(true);
    }
    updateStep();
}

void MainWindow::lastInstruct()
{
    ui->button_suivant->setDisabled(false);
    ui->button_preced->setDisabled(false);

    if(currentstate > 0){
        currentstate--;
        emit endChangeState();
    }
    if(currentstate == 0)
        ui->button_preced->setDisabled(true);

    updateStep();
}

void MainWindow::updateStep()
{
    ui->listeEtapes->setText(listEtapes[currentstate]);
    ui->noEtapes->setText("étape "+QString::number(currentstate+1) + "/" + QString::number(listEtapes.size()));
}

void MainWindow::on_actionOuvir_triggered()
{
    MainWindowLaunchDialog firstwindow;
    firstwindow.on_actionOuvrir_un_fichier_triggered();
}

void MainWindow::on_actionQuitter_triggered()
{
    QApplication::quit();
}

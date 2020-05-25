#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QEvent>
#include <QMessageBox>
#include <QState>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(750,550);  //fixe la taille de la fenêtre
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::modifNom(QString str)
{
    ui->nameLabel->setText(str);
    setWindowTitle("Votre recette: "+str);
}

void MainWindow::modifDesc(QString str)
{
    ui->descLabel->setWordWrap(true);
    ui->descLabel->setText(str);
}

void MainWindow::modifTemps(QString str)
{
    ui->timeLabel->setText(str);
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
    listEtapes=list;

    int size_list = list.size();

    for(int i=0; i < size_list; i++){
        //modification de la liste en fonction du nombre d'étapes
        ui->comboEtapes->addItem("Aller à l'étape "+QString::number(i+1));
    }

    //création QStateMachine pour les étapes de préparation
    initializeNewMachine(list, 0);
}

void MainWindow::on_comboEtapes_currentIndexChanged(int i)
{
    ui->listeEtapes->setText(listEtapes.at(i));
    ui->label_8->setText(QString::number(i+1) + "/" + QString::number(listEtapes.size()));

    if(i==0){
        first_state();
        last_state_exit();
    }
    else if(i==listEtapes.size()-1){
        last_state();
        first_state_exit();
    }
    else
    {
        first_state_exit();
        last_state_exit();
    }

    if(isEtapesInit){
        machine->stop();
        initializeNewMachine(listEtapes, i);
        isEtapesInit=false;
    }
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

void MainWindow::initializeNewMachine(QStringList list, int first_state)
{
    machine = new QStateMachine(this);

    int size_list = list.size();

    statelist.clear();

    for(int i=0; i < size_list; i++){
        //modification de la liste en fonction du nombre d'étapes
        QState * state = new QState();

        state->assignProperty(ui->listeEtapes, "text",  list.at(i));
        state->assignProperty(ui->label_8, "text", QString::number(i+1) + "/" + QString::number(list.size()));

        statelist.append(state);
    }

    for(int i=0; i < size_list; i++){
        machine->addState(statelist[i]);

            if(i != list.size()-1)
                statelist[i]->addTransition(ui->button_suivant, SIGNAL(clicked()), statelist[i+1]);

            if(i != 0)
                statelist[i]->addTransition(ui->button_preced, SIGNAL(clicked()), statelist[i-1]);
    }

     connect(statelist[0], SIGNAL(entered()), this, SLOT(first_state()));
     connect(statelist[0], SIGNAL(exited()), this, SLOT(first_state_exit()));
     connect(statelist[list.size()-1], SIGNAL(entered()), this, SLOT(last_state()));
     connect(statelist[list.size()-1], SIGNAL(exited()), this, SLOT(last_state_exit()));

    if(!isEtapesInit) isEtapesInit=true;

    machine->setInitialState(statelist[first_state]);
    machine->start();
}

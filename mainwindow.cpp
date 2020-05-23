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

    //création QStateMachine pour les étapes de préparation
    int size_list = list.size()-1;

    listEtapes=list;

    machine = new QStateMachine(this);

    QList<QState *> statelist;

    for(int i=0; i <= size_list; i++){
        QState * state = new QState();

        state->assignProperty(ui->listeEtapes, "text",  list.at(i));
        state->assignProperty(ui->label_8, "text", QString::number(i+1) + "/" + QString::number(list.size()));

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

    //modification de la liste en fonction du nombre d'étapes
    for(int i=0; i<list.size(); i++){
        ui->comboEtapes->addItem("Aller à l'étape "+QString::number(i+1));
    }
}

void MainWindow::on_comboEtapes_currentIndexChanged(int i)
{
    ui->listeEtapes->setText(listEtapes.at(i));
    ui->label_8->setText(QString::number(i+1) + "/" + QString::number(listEtapes.size()));

    if(i==0)
        first_state();
    else if(i==listEtapes.size()-1)
        last_state();
    else
    {
        first_state_exit();
        last_state_exit();
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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QEvent>

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


void MainWindow::on_comboEtapes_currentIndexChanged(int index)
{
    qDebug()<<index;
}

void MainWindow::modifNom(QString str)
{
    ui->nameLabel->setText(str);
}

void MainWindow::modifDesc(QString str)
{
    ui->descLabel->setText(str);
}

void MainWindow::modifTemps(QString str)
{
    ui->timeLabel->setText(str);
}

void MainWindow::modifIng(QStringList l)
{
    QString str = l.join("\n");
    ui->lIngLabel->setText(str);
}


void MainWindow::modifEtapes(QStringList l)
{
    QString str = l.join("\n");
    ui->listeEtapes->setText(str);

    //modification de la liste en fonction du nombre d'étapes
    for(int i=0; i<l.length(); i++){
        ui->comboEtapes->addItem("Aller à l'étape "+QString::number(i+1));
    }
}

void MainWindow::modifURL(QUrl *url)
{
//A rajouter
}




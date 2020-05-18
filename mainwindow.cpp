#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QEvent>

MainWindow::MainWindow(QWidget *parent, int _nbEtapes)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , nbEtapes(_nbEtapes)
{
    ui->setupUi(this);
    for(int i=0; i<nbEtapes; i++){
        ui->comboEtapes->addItem("Aller à l'étape "+QString::number(i+1));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboEtapes_currentIndexChanged(int index)
{
    qDebug()<<index;
}

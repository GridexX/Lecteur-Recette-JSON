#include "mainwindow.h"
#include "mainwindowlaunchdialog.h"
#include "ui_mainwindowlaunchdialog.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <lecture_json.h>

MainWindowLaunchDialog::MainWindowLaunchDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowLaunchDialog)
{
    ui->setupUi(this);
}

MainWindowLaunchDialog::~MainWindowLaunchDialog()
{
    delete ui;
}

void MainWindowLaunchDialog::on_pushButton_clicked()
{

    QString filePathName = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier JSON"), "/home/", tr("JSON Files (*.json)"));

    QFile fichier(filePathName);

    if(!(fichier.open(QFile::ReadOnly) || fichier.exists())) {
        QMessageBox::warning(this, "Erreur", "Pas de fichier selectionné ou impossible de le lire");
        return;
    }

    //Si le fichier est correcte -> lecture du fichier JSON

     hide();
     lecture_json json(filePathName);

   // aff->enregistrerRecette(filePathName);
}

void MainWindowLaunchDialog::on_actionOuvrir_un_fichier_triggered()
{
    on_pushButton_clicked();
}

void MainWindowLaunchDialog::on_actionQuitter_triggered()
{
    QApplication::quit();
}

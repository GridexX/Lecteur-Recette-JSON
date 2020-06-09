/**
 *   \file mainwindowlaunchdialog.cpp
 *   \author Pollet Lucas - Fougerouse Arsène
 *
 *   \brief Classe de la fenêtre permettant le choix du fichier json de recette
 */
#include "mainwindowlaunchdialog.h"

MainWindowLaunchDialog::MainWindowLaunchDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowLaunchDialog)
{
    ui->setupUi(this);
    setAcceptDrops(true);

    setFixedSize(750,550);  //fixe la taille de la fenêtre
    setWindowTitle("Lecteur de recettes JSON");

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
     t = new Transmission;
     connect(this,SIGNAL(envoyerNomFichier(QString)),t,SLOT(recevoirNomFichier(QString)));
     emit(envoyerNomFichier(filePathName));
}

void MainWindowLaunchDialog::on_actionOuvrir_un_fichier_triggered()
{
    on_pushButton_clicked();
}

void MainWindowLaunchDialog::on_actionQuitter_triggered()
{
    QApplication::quit();
}

void MainWindowLaunchDialog::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls()) {
          event->acceptProposedAction();
      }
}

void MainWindowLaunchDialog::dropEvent(QDropEvent* event){
        foreach (const QUrl &url, event->mimeData()->urls()) {
           QString fileName = url.toLocalFile();

           if(QFileInfo(fileName).suffix() != "json") return;

           hide();
           t = new Transmission;
           connect(this,SIGNAL(envoyerNomFichier(QString)),t,SLOT(recevoirNomFichier(QString)));
           emit(envoyerNomFichier(fileName));
       }
}

void MainWindowLaunchDialog::on_actionDe_Qt_triggered()
{
    QMessageBox::information(this, "Qt", "texte d'info");
}

void MainWindowLaunchDialog::on_actionDes_developpeurs_triggered()
{
    QMessageBox::information(this, "Développeurs", "texte d'info");
}

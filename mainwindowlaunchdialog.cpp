/**
 *   \file mainwindowlaunchdialog.cpp
 *   \author Pollet Lucas - Fougerouse Arsène
 *   \date mai 2020
 *   \brief Classe de la fenêtre permettant le choix du fichier json de recette
 */
#include "mainwindowlaunchdialog.h"

MainWindowLaunchDialog::MainWindowLaunchDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowLaunchDialog)
{
    ui->setupUi(this);
    setAcceptDrops(true);  //autorise le glisser-déposer de fichier

    setFixedSize(750,550);  //fixe la taille de la fenêtre
    setWindowTitle("Lecteur de recettes JSON");

}

MainWindowLaunchDialog::~MainWindowLaunchDialog()
{
    delete ui;
    delete t;
}

void MainWindowLaunchDialog::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier JSON"), "/home/", tr("JSON Files (*.json)"));

    QFile fichier(fileName);

    if(!(fichier.open(QFile::ReadOnly) || fichier.exists())) {
        QMessageBox::warning(this, "Erreur", "Pas de fichier selectionné ou impossible de le lire");
        return;
    }     
     envoieEtTransmission(fileName);
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
           envoieEtTransmission(fileName);
       }
}

void MainWindowLaunchDialog::envoieEtTransmission(QString fileName)
{
    //Quand le programme arrive à lire le fichier, il instancie la classe Transmission et transmet le nom à la classe lecture avec un signal
     hide();
     t = new Transmission;
     connect(this,SIGNAL(envoyerNomFichier(QString)),t->getTraitement()->getLecture(),SLOT(recevoirNomFichier(QString)));
     emit(envoyerNomFichier(fileName));
}

void MainWindowLaunchDialog::on_actionDe_Qt_triggered()
{
    QMessageBox::information(this, "Qt", "texte d'info");
}

void MainWindowLaunchDialog::on_actionDes_developpeurs_triggered()
{
    QMessageBox::information(this, "Développeurs", "texte d'info");
}

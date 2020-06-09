/**
 *   \file mainwindow.cpp
 *   \author Pollet Lucas - Fougerouse Arsène
 *
 *   \brief Classe de la fenêtre permettant l'affichage de la recette
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Votre recette: ");
    setFixedSize(750,550);
    //setImage("https://static.750g.com/images/600-600/7b88d90630c62991df12b34c692aff0d/sucre-vanille-express.jpg");
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
/*
void MainWindow::setImage(QString url)
{
    if(url != ""){
        QNetworkAccessManager *acces = new QNetworkAccessManager(this);
        connect(acces, SIGNAL(finished(QNetworkReply*)), this, SLOT(setImageWhenIsUpload(QNetworkReply*)));

        const QUrl url_image = QUrl(url);
        QNetworkRequest request(url_image);
        acces->get(request);
    }
}

void MainWindow::setImageWhenIsUpload(QNetworkReply *reply)
{
    QPixmap pixmap;
    pixmap.loadFromData(reply->readAll());
    ui->image->setPixmap(pixmap);
}
*/
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
    ui->IngLabel->setText(str);

}

void MainWindow::modifURL(QString url)
{
    ui->label_url->setOpenExternalLinks(true);
    ui->label_url->setTextInteractionFlags(Qt::TextBrowserInteraction);

    ui->label_url->setText("URL de la recette: <a href='"+url+"'>"+url+"</a>");
}

/* Machine à état */
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

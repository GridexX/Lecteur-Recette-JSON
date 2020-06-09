/********************************************************************************
** Form generated from reading UI file 'mainwindowlaunchdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWLAUNCHDIALOG_H
#define UI_MAINWINDOWLAUNCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowLaunchDialog
{
public:
    QAction *actionDe_Qt;
    QAction *actionDes_developpeurs;
    QAction *actionOuvrir_un_fichier;
    QAction *actionQuitter;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuA_Propos;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowLaunchDialog)
    {
        if (MainWindowLaunchDialog->objectName().isEmpty())
            MainWindowLaunchDialog->setObjectName(QString::fromUtf8("MainWindowLaunchDialog"));
        MainWindowLaunchDialog->resize(750, 550);
        actionDe_Qt = new QAction(MainWindowLaunchDialog);
        actionDe_Qt->setObjectName(QString::fromUtf8("actionDe_Qt"));
        actionDes_developpeurs = new QAction(MainWindowLaunchDialog);
        actionDes_developpeurs->setObjectName(QString::fromUtf8("actionDes_developpeurs"));
        actionOuvrir_un_fichier = new QAction(MainWindowLaunchDialog);
        actionOuvrir_un_fichier->setObjectName(QString::fromUtf8("actionOuvrir_un_fichier"));
        actionQuitter = new QAction(MainWindowLaunchDialog);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralwidget = new QWidget(MainWindowLaunchDialog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 110, 716, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(11);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 450, 161, 41));
        MainWindowLaunchDialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowLaunchDialog);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 750, 20));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuA_Propos = new QMenu(menubar);
        menuA_Propos->setObjectName(QString::fromUtf8("menuA_Propos"));
        MainWindowLaunchDialog->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowLaunchDialog);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowLaunchDialog->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuA_Propos->menuAction());
        menuFichier->addAction(actionOuvrir_un_fichier);
        menuFichier->addAction(actionQuitter);
        menuA_Propos->addAction(actionDe_Qt);
        menuA_Propos->addAction(actionDes_developpeurs);

        retranslateUi(MainWindowLaunchDialog);

        QMetaObject::connectSlotsByName(MainWindowLaunchDialog);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowLaunchDialog)
    {
        MainWindowLaunchDialog->setWindowTitle(QApplication::translate("MainWindowLaunchDialog", "MainWindow", nullptr));
        actionDe_Qt->setText(QApplication::translate("MainWindowLaunchDialog", "De Qt", nullptr));
        actionDes_developpeurs->setText(QApplication::translate("MainWindowLaunchDialog", "Des d\303\251veloppeurs", nullptr));
        actionOuvrir_un_fichier->setText(QApplication::translate("MainWindowLaunchDialog", "Ouvrir un fichier", nullptr));
        actionQuitter->setText(QApplication::translate("MainWindowLaunchDialog", "Quitter", nullptr));
        label->setText(QApplication::translate("MainWindowLaunchDialog", "Bienvenue sur le programme d'affichage de recettes JSON.", nullptr));
        label_2->setText(QApplication::translate("MainWindowLaunchDialog", "Veuillez choisir un fichier json pour commencer", nullptr));
        pushButton->setText(QApplication::translate("MainWindowLaunchDialog", "Choisir Fichier", nullptr));
        menuFichier->setTitle(QApplication::translate("MainWindowLaunchDialog", "Fichier", nullptr));
        menuA_Propos->setTitle(QApplication::translate("MainWindowLaunchDialog", "A Propos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowLaunchDialog: public Ui_MainWindowLaunchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWLAUNCHDIALOG_H

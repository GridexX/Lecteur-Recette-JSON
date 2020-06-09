/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *Infos_2;
    QWidget *Infos;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *nameLabel;
    QLabel *label_3;
    QLabel *descLabel;
    QLabel *label;
    QLabel *keywordLabel;
    QLabel *label_5;
    QLabel *timeLabel;
    QLabel *label_url;
    QWidget *tab_2;
    QLabel *lIngLabel;
    QLabel *label_4;
    QWidget *tab;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QLabel *listeEtapes;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button_preced;
    QPushButton *button_suivant;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(750, 550);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Infos_2 = new QTabWidget(centralwidget);
        Infos_2->setObjectName(QString::fromUtf8("Infos_2"));
        Infos_2->setGeometry(QRect(20, 10, 691, 501));
        Infos = new QWidget();
        Infos->setObjectName(QString::fromUtf8("Infos"));
        verticalLayoutWidget = new QWidget(Infos);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 20, 581, 391));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(11);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        nameLabel = new QLabel(verticalLayoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(nameLabel);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        descLabel = new QLabel(verticalLayoutWidget);
        descLabel->setObjectName(QString::fromUtf8("descLabel"));
        descLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(descLabel);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        keywordLabel = new QLabel(verticalLayoutWidget);
        keywordLabel->setObjectName(QString::fromUtf8("keywordLabel"));
        keywordLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(keywordLabel);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);

        timeLabel = new QLabel(verticalLayoutWidget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(timeLabel);

        label_url = new QLabel(Infos);
        label_url->setObjectName(QString::fromUtf8("label_url"));
        label_url->setGeometry(QRect(60, 425, 431, 21));
        Infos_2->addTab(Infos, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        lIngLabel = new QLabel(tab_2);
        lIngLabel->setObjectName(QString::fromUtf8("lIngLabel"));
        lIngLabel->setGeometry(QRect(100, 60, 489, 341));
        QFont font1;
        font1.setPointSize(9);
        lIngLabel->setFont(font1);
        lIngLabel->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 0, 489, 101));
        QFont font2;
        font2.setPointSize(12);
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);
        Infos_2->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayoutWidget_3 = new QWidget(tab);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(60, 50, 551, 271));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);
        label_8->setLayoutDirection(Qt::LeftToRight);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_8);

        listeEtapes = new QLabel(verticalLayoutWidget_3);
        listeEtapes->setObjectName(QString::fromUtf8("listeEtapes"));
        listeEtapes->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(listeEtapes);

        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(60, 370, 551, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        button_preced = new QPushButton(horizontalLayoutWidget);
        button_preced->setObjectName(QString::fromUtf8("button_preced"));

        horizontalLayout_2->addWidget(button_preced);

        button_suivant = new QPushButton(horizontalLayoutWidget);
        button_suivant->setObjectName(QString::fromUtf8("button_suivant"));

        horizontalLayout_2->addWidget(button_suivant);

        Infos_2->addTab(tab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 750, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Infos_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Nom", nullptr));
        nameLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Description", nullptr));
        descLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QApplication::translate("MainWindow", "Mots-clefs", nullptr));
        keywordLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Temps", nullptr));
        timeLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_url->setText(QApplication::translate("MainWindow", "URL", nullptr));
        Infos_2->setTabText(Infos_2->indexOf(Infos), QApplication::translate("MainWindow", "Infos", nullptr));
        lIngLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Ingr\303\251dients :", nullptr));
        Infos_2->setTabText(Infos_2->indexOf(tab_2), QApplication::translate("MainWindow", "Liste ingr\303\251dients", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "nb/total", nullptr));
        listeEtapes->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        button_preced->setText(QApplication::translate("MainWindow", "Pr\303\251d\303\251cent", nullptr));
        button_suivant->setText(QApplication::translate("MainWindow", "Suivant", nullptr));
        Infos_2->setTabText(Infos_2->indexOf(tab), QApplication::translate("MainWindow", "\303\211tapes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

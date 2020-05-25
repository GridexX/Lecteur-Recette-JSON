#ifndef MAINWINDOWLAUNCHDIALOG_H
#define MAINWINDOWLAUNCHDIALOG_H

#include <QDropEvent>
#include <QMainWindow>

namespace Ui {
class MainWindowLaunchDialog;
}

class MainWindowLaunchDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowLaunchDialog(QWidget *parent = nullptr);
    ~MainWindowLaunchDialog();

private slots:
    void on_pushButton_clicked();

    void on_actionOuvrir_un_fichier_triggered();

    void on_actionQuitter_triggered();

    //slots pour modifs infos


    void on_actionDe_Qt_triggered();

    void on_actionDes_developpeurs_triggered();

private:
    Ui::MainWindowLaunchDialog *ui;
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
};

#endif // MAINWINDOWLAUNCHDIALOG_H

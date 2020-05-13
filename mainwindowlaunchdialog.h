#ifndef MAINWINDOWLAUNCHDIALOG_H
#define MAINWINDOWLAUNCHDIALOG_H

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

private:
    Ui::MainWindowLaunchDialog *ui;
};

#endif // MAINWINDOWLAUNCHDIALOG_H

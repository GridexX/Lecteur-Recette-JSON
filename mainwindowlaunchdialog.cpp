#include "mainwindowlaunchdialog.h"
#include "ui_mainwindowlaunchdialog.h"

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

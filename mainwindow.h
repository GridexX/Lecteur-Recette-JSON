#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, int _nbEtapes=0);
    ~MainWindow();
    //inline void setEtapes(int _nbEtapes){nbEtapes=_nbEtapes;}
    //inline int getEtapes(){return nbEtapes;}

private slots:
    void on_comboEtapes_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

    int nbEtapes;


};
#endif // MAINWINDOW_H

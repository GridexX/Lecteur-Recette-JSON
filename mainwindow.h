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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_comboEtapes_currentIndexChanged(int index);




private:
    Ui::MainWindow *ui;

public slots :
    //slots pour modifs les labels

    void modifNom(QString);
    void modifDesc(QString);
    void modifIng(QStringList);
    void modifEtapes(QStringList);
    void modifTemps(QString);
    void modifURL(QUrl *);

};
#endif // MAINWINDOW_H

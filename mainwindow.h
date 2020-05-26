#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStateMachine>

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
    void first_state();
    void last_state();
    void first_state_exit();
    void last_state_exit();

    void initializeNewMachine(QStringList, int);


private:
    Ui::MainWindow *ui;
    QStateMachine *machine;
    QStringList listEtapes;

    QList<QState *> statelist;
    bool isEtapesInit = false;

public slots :
    //slots pour modifs les labels

    void modifNom(QString);
    void modifDesc(QString);
    void modifMotsCles(QString);
    void modifIng(QStringList);
    void modifEtapes(QStringList);
    void modifTemps(QStringList);
    void modifURL(QString);

signals:
    void signal_state();
};
#endif // MAINWINDOW_H

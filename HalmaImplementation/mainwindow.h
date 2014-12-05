#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <battlefield.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    battlefield lava;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_playerOneAI_clicked();

    void on_playerOneHuman_clicked();

    void on_playerTwoAI_clicked();

    void on_playerTwoHuman_clicked();



private:
    Ui::MainWindow *ui;
    bool isOneHuman;
    bool isTwoHuman;
    QString playerOneName;
    QString playerTwoName;
    QString playerOneURL;
    QString playerTwoURL;
};

#endif // MAINWINDOW_H

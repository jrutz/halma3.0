#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    isOneHuman = true;
    isTwoHuman = true;

    ui->setupUi(this);
    ui->playerOneHuman->click();
    ui->playerTwoHuman->click();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   playerOneName = ui->namePlayerOne->text();
   playerTwoName = ui->namePlayerTwo->text();
   //send player names
   lava.setTeamNameText(playerOneName,playerTwoName);

   //send player types and set that up
   lava.setTeamOneType(isOneHuman);
   lava.setTeamTwoType(isTwoHuman);

   if(isOneHuman == false) {
    lava.setTeamOneURL(ui->playerOneURL->text());
   }

   if(isTwoHuman == false) {
    lava.setTeamTwoURL(ui->playerTwoURL->text());
   }

   lava.setBaseValues();
    //send the URL(s)
    lava.show();

    ui->centralWidget->setDisabled(true);
}


void MainWindow::on_playerOneAI_clicked()
{
    isOneHuman = false;
}

void MainWindow::on_playerOneHuman_clicked()
{
    isOneHuman = true;
}


void MainWindow::on_playerTwoAI_clicked()
{
    isTwoHuman = false;
}

void MainWindow::on_playerTwoHuman_clicked()
{
   isTwoHuman = true;
}



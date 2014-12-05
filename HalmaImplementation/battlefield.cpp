#include "battlefield.h"
#include "ui_battlefield.h"
#include "qdebug.h"



battlefield::battlefield(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::battlefield)
{

    ui->setupUi(this);
    QIcon blank = QIcon("/images/empty.png");


    lightRed = QColor(246, 101, 101);
    medRed = QColor(230, 8, 8);
    darkRed = QColor(178, 11, 11);
    black = QColor(8, 36, 0);
    grey= QColor(224, 224, 224);
    lightBlue = QColor(132, 215, 255);
    medBlue = QColor(0, 110, 255);
    darkBlue = QColor(11, 94, 202);
    green = QColor(102, 204, 0);
    pinkish = QColor(204, 0, 102);


    initializeEverything();


}

battlefield::~battlefield()
{
    delete ui;
}

void battlefield :: initializeEverything()
{
    oneChecked = false;
    twoChecked = false;

    int row = 18;
    int column = 18;

    for(int i=0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            int team = boardManager.gameBoard[j][i];
            QTableWidgetItem *newItem = new QTableWidgetItem();
            ui->battleTable->setItem(i,j,newItem);

            if(team == 1)
                ui->battleTable->item(i,j)->setBackgroundColor(medRed);

            else if(team ==2)
                ui->battleTable->item(i,j)->setBackgroundColor(medBlue);

            else
                ui->battleTable->item(i,j)->setBackgroundColor(grey);
        }
    }



}


void battlefield::setTeamNameText(QString one, QString two)
{
    ui->nameOne->setText(one);
    ui->nameTwo->setText(two);
}


void battlefield:: setTeamOneType(bool type)
{
    isOneHuman = type;
    if(type == true) {

        ui->oneType->setText("Human");
    }

    else {
        ui->oneType->setText("Robot");

    }
}

void battlefield:: setTeamTwoType(bool type)
{
    isTwoHuman = type;

    if(type ==true) {

        ui->twoType->setText("Human");
    } else {

        ui->twoType->setText("Robot");
    }
}


void battlefield::  setTeamOneURL(QString url)
{
    teamOneURL = url;

}
void battlefield:: setTeamTwoURL(QString url)
{

    teamTwoURL = url;
}

void battlefield:: setBaseValues()
{
    ui->moveNumOne->setText("0");
    ui->moveNumTwo->setText("0");
}



void battlefield::on_battleTable_cellClicked(int row, int column)
{
   QTableWidgetItem* current = ui->battleTable->item(row,column);



   if (twoChecked == true && oneChecked == true) {
          oneChecked = false;
          twoChecked = false;
      }

   else if(oneChecked == false) {
       firstCellClicked = current;
       oneChecked = true;

       if(firstCellClicked->backgroundColor()== medRed)
           firstCellClicked->setBackgroundColor(darkRed);

       if(firstCellClicked->backgroundColor() == medBlue)
           firstCellClicked->setBackgroundColor(darkBlue);
   }

   else if (twoChecked == false) {
       secondCellClicked = current;
       twoChecked = true;

       if(firstCellClicked->backgroundColor()==darkRed)
       {    secondCellClicked->setBackgroundColor(medRed);
           firstCellClicked->setBackgroundColor(grey);}

       else if (firstCellClicked->backgroundColor()==darkBlue)
            {secondCellClicked->setBackgroundColor(medBlue);
            firstCellClicked->setBackgroundColor(grey);}

       oneChecked = false;
       twoChecked = false;
   }

   qDebug() << "oneChecked: " << oneChecked;
   qDebug() << "twoChecked: " << twoChecked;
   qDebug() << "   ";

}

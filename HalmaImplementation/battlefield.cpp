#include "battlefield.h"
#include "ui_battlefield.h"



battlefield::battlefield(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::battlefield)
{

    ui->setupUi(this);
    QIcon blank = QIcon("/images/empty.png");
    QColor fuck = QColor(8, 36, 0);

    int row = 18;
    int column = 18;

    for(int i=0; i < row; i++) {

        for(int j = 0; j < column; j++) {
            QTableWidgetItem *newItem = new QTableWidgetItem();
            ui->battleTable->setItem(i,j,newItem);
            ui->battleTable->item(i,j)->setBackgroundColor(fuck);
        }
    }

    setTeams();


}

battlefield::~battlefield()
{
    delete ui;
}

void battlefield :: setTeams()
{

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

void battlefield::on_battleTable_cellPressed(int row, int column)
{

}

void battlefield::on_battleTable_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{

}

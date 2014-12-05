#include "battlefield.h"
#include "ui_battlefield.h"



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
    playerTurn = 1;

    playerOneMoves = 0;
    playerTwoMoves = 0;

    int row = 18;
    int column = 18;

    for(int i=0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            int team = boardManager.gameBoard[j][i]->player;
            QTableWidgetItem *newItem = new QTableWidgetItem();
            ui->battleTable->setItem(i,j,newItem);

            if(team == 1)
                ui->battleTable->item(i,j)->setBackgroundColor(medRed);

            else if(team == 2)
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

       if(firstCellClicked->backgroundColor()== medRed && playerTurn == 1)
           firstCellClicked->setBackgroundColor(darkRed);

       if(firstCellClicked->backgroundColor() == medBlue && playerTurn == 2)
           firstCellClicked->setBackgroundColor(darkBlue);
   }

   else if (twoChecked == false) {
       secondCellClicked = current;
       twoChecked = true;
       if (firstCellClicked == secondCellClicked){
           if(firstCellClicked->backgroundColor()==darkRed)
               firstCellClicked->setBackgroundColor(medRed);

           if(firstCellClicked->backgroundColor()==darkBlue)
               firstCellClicked->setBackgroundColor(medBlue);
       }

       //ERROR CORRECTING CASES
       else if(secondCellClicked->backgroundColor() != grey) {
               ui->moveName->setText("You're an idiot, try again");
               if(playerTurn == 1 && firstCellClicked->backgroundColor()==darkRed){
                   firstCellClicked->setBackgroundColor(medRed);
               }

               else if (playerTurn == 2 && firstCellClicked->backgroundColor()==darkBlue) {
                   firstCellClicked->setBackgroundColor(medBlue);
               }

               oneChecked = false;
               twoChecked = false;
       }

       else if(abs(secondCellClicked->row()-firstCellClicked->row()) > 1 || abs(secondCellClicked->column()-firstCellClicked->column()) > 1)
       {
           if(playerTurn == 1){
               ui->moveName->setText(teamTwoName+" (team 1 made an illegal move)");

               firstCellClicked->setBackgroundColor(medRed);
               oneChecked = false;
               twoChecked = false;
              //playerTurn = 2;
           }

           if(playerTurn == 2) {
               ui->moveName->setText(teamOneName+" (team 2 made an illegal move)");
               firstCellClicked->setBackgroundColor(medBlue);
               oneChecked = false;
               twoChecked = false;
               //playerTurn = 1;
           }


       }

       else if(firstCellClicked->backgroundColor()==darkRed) {
           secondCellClicked->setBackgroundColor(medRed);
           firstCellClicked->setBackgroundColor(grey);
           ui->moveName->setText(teamTwoName);

           boardManager.makeMove(playerTurn, firstCellClicked->column(), firstCellClicked->row(), secondCellClicked->column(), secondCellClicked->row());

           playerTurn = 2;
       }

       else if (firstCellClicked->backgroundColor()==darkBlue) {
           secondCellClicked->setBackgroundColor(medBlue);
           firstCellClicked->setBackgroundColor(grey);
            ui->moveName->setText(teamOneName);
            boardManager.makeMove(playerTurn, firstCellClicked->column(), firstCellClicked->row(), secondCellClicked->column(), secondCellClicked->row());

            playerTurn = 1;
       }

       if(playerTurn == 2 && isOneHuman == true) {
           playerOneMoves +=1;
           ui->moveNumOne->setText(QString::number(playerOneMoves));
       }

       if(playerTurn == 1 && isTwoHuman == true) {
           playerTwoMoves +=1;
           ui->moveNumTwo->setText(QString::number(playerTwoMoves));
       }

       oneChecked = false;
       twoChecked = false;


   }

}

void battlefield::on_makeMove_clicked()
{
    //QString lol2 = "http://lyle.smu.edu/~tbgeorge/cse4345/a1/getMove.php";

    //std::string fuck = teamTwoURL.toStdString();
    //char* hopefully = new char[fuck.length()+1];
    //std::strcpy(hopefully,fuck.c_str());
    //char* whatTheFuck = std::strcpy(hopefully,fuck.c_str());
    if(!isOneHuman && playerTurn==1) {
        int* moves = boardManager.makeAIMove(1, teamOneURL);
        int fromX = moves[1];
        int fromY = moves[0];
        int toX = moves[3];
        int toY = moves[2];

        on_battleTable_cellClicked(fromX, fromY);
        on_battleTable_cellClicked(toX, toY);

        playerOneMoves+=1;
        ui->moveNumOne->setText(QString::number(playerOneMoves));
    }

    if(!isTwoHuman && playerTurn==2) {
        int* moves = boardManager.makeAIMove(2, teamTwoURL);
        int fromX = moves[1];
        int fromY = moves[0];
        int toX = moves[3];
        int toY = moves[2];

        on_battleTable_cellClicked(fromX, fromY);
        on_battleTable_cellClicked(toX, toY);

        playerTwoMoves +=1;
        ui->moveNumTwo->setText(QString::number(playerTwoMoves));
    }





            //first 2 = from, last 2 = destination
}

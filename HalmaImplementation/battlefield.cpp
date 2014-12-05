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

//checking if jumps are valid, must be a jump in order to be here
bool battlefield :: checkSpatialValidity(int firstRow, int firstColumn, int destRow, int destColumn) {
    ui->moveName->setText(QString::number(destRow) +" "+QString::number(destColumn));
    if(ui->battleTable->item(destRow,destColumn)->backgroundColor() !=grey){
          ui->moveName->setText("You're trying to jump on another piece");
        return false;}

    //Totally normal looking move
    if(abs(firstRow-destRow) <= 1 && abs(firstColumn-destColumn) <= 1) {
        ui->moveName->setText("Normal move within bounds");
        return true;
     }
    //Is it obviously more than one skip space
    if(abs(firstRow-destRow) > 2 || abs(firstColumn-destColumn) > 2) {
        ui->moveName->setText("You're way out of bounds");
        return false;
     }
    //In case of diagonal jumps
    if(abs(firstRow-destRow) == 2 && abs(firstColumn-destColumn) == 2) {
        //Upper Right Diagonal
        if((firstRow-destRow) == -2 && (firstColumn-destColumn) == 2){
            if(ui->battleTable->item(firstRow+1,firstColumn-1)->backgroundColor() != grey)
                return false;
            else
                return true;
        }//Upper Left Diagonal
        else if((firstRow-destRow) == 2 && (firstColumn-destColumn) == 2){
            if(ui->battleTable->item(firstRow-1,firstColumn-1)->backgroundColor() != grey)
                return false;
            else
                return true;
        }//Lower Right Diagonal
        else if((firstRow-destRow) == -2 && (firstColumn-destColumn) == -2){
            if(ui->battleTable->item(firstRow+1,firstColumn+1)->backgroundColor() != grey)
                return false;
            else
                return true;
        }//Lower Left Diagonal
        else if((firstRow-destRow) == 2 && (firstColumn-destColumn) == -2) {
            if(ui->battleTable->item(firstRow-1,firstColumn+1)->backgroundColor() != grey)
                return false;
            else
                return true;
        }

     //In case of horizontal jumps
    } else if (firstRow == destRow) {
       //destination is to the right first
        if((firstRow-destRow) == -2) {
            if(ui->battleTable->item(firstRow+1,firstColumn)->backgroundColor() != grey)
                return false;
            else
                return true;  }

        //destination is to the left of first
        if((firstRow-destRow) == 2) {
            if(ui->battleTable->item(firstRow-1,firstColumn)->backgroundColor() != grey)
                return false;
            else
                return true;  }

     //In case of Vertical jumps
    } else if (firstColumn == destColumn) {
            //destination is below the first one
             if((firstColumn-destColumn) == -2) {
                 if(ui->battleTable->item(firstRow,firstColumn+1)->backgroundColor() != grey)
                     return false;
                 else
                     return true;  }

             //destination is above
             if((firstColumn-destColumn) == 2) {
                 if(ui->battleTable->item(firstRow,firstColumn-1)->backgroundColor() != grey)
                     return false;
                 else
                     return true;  }

    }

    else
        return false;
}

bool battlefield:: checkTeamValidity(int player, QColor pieceColor) {
    if((playerTurn == 1 && pieceColor != medRed) && (playerTurn == 1 && pieceColor != darkRed))
        return false;
    else if((playerTurn == 2 && pieceColor != medBlue) && (playerTurn == 2 && pieceColor != darkBlue))
        return false;
    else
        return true;
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

void battlefield :: clickPieceAndMove(QTableWidgetItem* first,QTableWidgetItem* second) {
    QTableWidgetItem* original = first;
    QTableWidgetItem* destination = second;

    if(original->backgroundColor() == darkRed) {
        original->setBackgroundColor(grey);
        destination->setBackgroundColor(medRed);

    } else if (original == destination && original->backgroundColor()== darkRed){
        original->setBackgroundColor(medRed);

    }

     else if(original->backgroundColor() == darkBlue){
            original->setBackgroundColor(grey);
            destination->setBackgroundColor(medBlue);
    }

    else if(original==destination && original->backgroundColor() ==darkBlue){
            original->setBackgroundColor(medBlue);
    }
}

void battlefield :: clickFirstPiece(QTableWidgetItem* original) {
    if(original->backgroundColor() == medRed)
        original->setBackgroundColor(darkRed);

     else if(original->backgroundColor() == medBlue)
            original->setBackgroundColor(darkBlue);

    else if(original->backgroundColor() == darkBlue)
           original->setBackgroundColor(medBlue);

    else if(original->backgroundColor() == darkRed)
           original->setBackgroundColor(medRed);

}


void battlefield :: endTurn() {
    if(playerTurn == 1)
        playerTurn = 2;
    else if(playerTurn == 2)
        playerTurn = 1;

}

void battlefield::on_battleTable_cellClicked(int row, int column)
{
   QTableWidgetItem* current = ui->battleTable->item(row,column);

   //Two things have already been checked, reset all values
   if (twoChecked == true && oneChecked == true) {
          oneChecked = false;
          twoChecked = false;
      }


   else if(oneChecked == false) {
       //Establish the first click
       firstCellClicked = current;

       if(checkTeamValidity(playerTurn,firstCellClicked->backgroundColor()) == true)
       {
            //Make sure click is valid
            oneChecked = true;

            if(playerTurn == 1)
                clickFirstPiece(firstCellClicked);

             if(playerTurn == 2)
                    clickFirstPiece(firstCellClicked);
        }
       else
           ui->moveName->setText("This isn't a valid first click");
   }

   //Select the second object
   else if (twoChecked == false) {
                secondCellClicked = current;
                twoChecked = true;

       //If the click is not spatially valid, reset all values
       if(checkSpatialValidity(firstCellClicked->row(),firstCellClicked->column(),secondCellClicked->row(),secondCellClicked->column()) == true) {
          clickPieceAndMove(firstCellClicked, secondCellClicked);
          boardManager.makeMove(playerTurn, firstCellClicked->column(), firstCellClicked->row(), secondCellClicked->column(), secondCellClicked->row());
          endTurn();
          oneChecked = false;
          twoChecked = false;
       } else {
           if((playerTurn == 1 && isOneHuman == true) || (playerTurn == 2 && isTwoHuman == true))
                clickFirstPiece(firstCellClicked);
           else{
               clickFirstPiece(firstCellClicked);
               boardManager.makeMove(playerTurn, firstCellClicked->column(), firstCellClicked->row(), firstCellClicked->column(), firstCellClicked->row());
               endTurn();
           }
            oneChecked = false;
            twoChecked = false;
       }

       /* //If they click on the same cell
       if (firstCellClicked == secondCellClicked){
           clickPieceAndMove(firstCellClicked, secondCellClicked);
       }*/
}
       //ERROR CORRECTING CASES
       /*else if(secondCellClicked->backgroundColor() != grey) {
               ui->moveName->setText("You're an idiot, try again");
               if(playerTurn == 1 && firstCellClicked->backgroundColor()==darkRed){
                   firstCellClicked->setBackgroundColor(medRed);
               }

               else if (playerTurn == 2 && firstCellClicked->backgroundColor()==darkBlue) {
                   firstCellClicked->setBackgroundColor(medBlue);
               }

               oneChecked = false;
               twoChecked = false;
       }*/
/*
       else if(abs(secondCellClicked->row()-firstCellClicked->row()) > 1 || abs(secondCellClicked->column()-firstCellClicked->column()) > 1)
       {
           if(playerTurn == 1){
               //ui->moveName->setText(teamTwoName+" (team 1 made an illegal move)");

               firstCellClicked->setBackgroundColor(medRed);
               oneChecked = false;
               twoChecked = false;
              //playerTurn = 2;
           }

           if(playerTurn == 2) {
               //ui->moveName->setText(teamOneName+" (team 2 made an illegal move)");
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
*/
}

void battlefield::on_makeMove_clicked()
{

    for(int i = 0; i < 70; i++) {
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
    }





            //first 2 = from, last 2 = destination
}

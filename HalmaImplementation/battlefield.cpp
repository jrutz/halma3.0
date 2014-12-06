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
    suicidal = 0;

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

    if(ui->battleTable->item(destRow,destColumn)->backgroundColor() !=grey){
         sendMessage("You're literally trying to jump on top of another piece");
        return false;}

    //Totally normal looking move
    if(abs(firstRow-destRow) <= 1 && abs(firstColumn-destColumn) <= 1) {
        sendMessage("Simple but solid move");
        return true;
     }
    //Is it obviously more than one skip space
    if(abs(firstRow-destRow) > 2 || abs(firstColumn-destColumn) > 2) {
        sendMessage("You're over-reaching your bounds there");
        return false;
     }

    //In case of diagonal jumps
    if(abs(firstRow-destRow) == 2 && abs(firstColumn-destColumn) == 2) {
        sendMessage("Moving diagonally eh? I like your style");

        //Upper Right Diagonal
        if((firstRow-destRow) == 2 && (firstColumn-destColumn) == -2){
           if(ui->battleTable->item(destRow+1,destColumn-1)->backgroundColor() != grey)
                return true;
            else
                return false;
        }//Upper Left Diagonal
        else if((firstRow-destRow) == 2 && (firstColumn-destColumn) == 2){
            if(ui->battleTable->item(destRow+1,destColumn+1)->backgroundColor() != grey)
                return true;
            else
                return false;
        }//Lower Right Diagonal
        else if((firstRow-destRow) == -2 && (firstColumn-destColumn) == -2){
             if(ui->battleTable->item(destRow-1,destColumn-1)->backgroundColor() != grey)
                return true;
            else
                return false;
        }//Lower Left Diagonal
        else if((firstRow-destRow) == -2 && (firstColumn-destColumn) == 2) {
           if(ui->battleTable->item(destRow-1,destColumn+1)->backgroundColor() != grey)
                return true;
            else
                return false;
        }

     //In case of Horizontal jumps
    } else if (firstRow == destRow) {

        sendMessage("That's some nice horizontal action");
       //destination is to the right first
        if((firstColumn-destColumn) == -2) {
            if(ui->battleTable->item(destRow,destColumn-1)->backgroundColor() != grey)
                return true;
            else
                return false;  }

        //destination is to the left of first
        else if((firstColumn-destColumn) == 2) {
            if(ui->battleTable->item(destRow,destColumn+1)->backgroundColor() != grey)
                return true;
            else
                return false;  }

     //In case of Vertical jumps
    } else if (firstColumn == destColumn) {
        sendMessage("I like the vertical motion, moving up in the world");
            //destination is below the first one
             if((firstRow-destRow) == -2) {
                 if(ui->battleTable->item(destRow-1,destColumn)->backgroundColor() != grey)
                     return true;
                 else
                     return false;  }

             //destination is above
             else if((firstRow-destRow) == 2) {
                 if(ui->battleTable->item(destRow+1,destColumn)->backgroundColor() != grey)
                     return true;
                 else
                     return false;  }
    }

    else
        return false;

    sendMessage("I have no idea what you did there");
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
        if(isOneHuman == true)
            playerOneMoves ++;



    } else if (original == destination && original->backgroundColor()== darkRed){
        original->setBackgroundColor(medRed);

    }

     else if(original->backgroundColor() == darkBlue){
            original->setBackgroundColor(grey);
            destination->setBackgroundColor(medBlue);
            if(isTwoHuman == true)
                playerTwoMoves++;
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
    QString teamName;
    if(playerTurn == 1)
        teamName = teamOneName;
    if(playerTurn == 2)
        teamName = teamTwoName;

    if(didTheyWin(playerTurn) == true) {
        sendMessage("Good job "+teamName+" you really crushed this game.");
        playerTurn = 0;

    }

    else{
        if(playerTurn == 1)
            playerTurn = 2;
        else if(playerTurn == 2)
             playerTurn = 1;}

}

void battlefield::sendMessage(QString message) {

    ui->moveName->setText(message);
}

void battlefield::on_battleTable_cellClicked(int row, int column)
{
    if(playerTurn == 0) {

        sendMessage("Someone won, yo");
        return;
    }

   if(row < 0 || row > 17 || column < 0 || column > 17){
       sendMessage("Are you trying to escape off the board?");
       return;
   }

   QTableWidgetItem* current = ui->battleTable->item(row,column);

   //Two things have already been checked, reset all values
   if (twoChecked == true && oneChecked == true) {
          oneChecked = false;
          twoChecked = false;
      }


   else if(oneChecked == false) {
       //Establish the first click
       firstCellClicked = current;

       if(checkTeamValidity(playerTurn,firstCellClicked->backgroundColor()) == true) {
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

          ui->moveNumOne->setText(QString::number(playerOneMoves));
          ui->moveNumTwo->setText(QString::number(playerTwoMoves));
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

   }
}

void battlefield::on_makeMove_clicked()
{
    for(int i = 0; i < 70; i++) {
    //QString lol2 = "http://lyle.smu.edu/~tbgeorge/cse4345/a1/getMove.php";


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

}


//Returns true if player wins, false if they did not
bool battlefield :: didTheyWin(int player)
{

    if(player == 1) {
        for(int i=0; i < 3; i++) {
            for(int j = 15; j < 18; j++) {
                if(ui->battleTable->item(i,j)->backgroundColor() != medRed || ui->battleTable->item(i,j)->backgroundColor() != darkRed){
                   return false;
                }
            }
        }
}


    if(player == 2) {
        for(int i=0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(ui->battleTable->item(i,j)->backgroundColor() != medBlue || ui->battleTable->item(i,j)->backgroundColor() != darkBlue){
                   return false;
                }
            }
        }
    }


    return true;

}





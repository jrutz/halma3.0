#include "cellmanager.h"

cellManager::cellManager()
{

   for(int i=0; i < 18; i++) {
       for(int j=0; j<18; j++){
           gameBoard[i][j] = new cell();
           if(i<3 && j > 13)
               gameBoard[i][j]->player = 1;
           else if(i>14 && j>13)
               gameBoard[i][j]->player = 2;

           if(i>14 && j<3)
               gameBoard[i][j]->dest = 1;
           if(i<3 && j<3)
               gameBoard[i][j]->dest = 2;

       }
   }

}

bool cellManager::makeMove(int player, int fromX, int fromY, int toX, int toY)
{
    if(gameBoard[fromX][fromY]->player == player) {

        //if the destination is another players piece
        if(gameBoard[toX][toY]->player != 0  && gameBoard[toX][toY]->player != player) {
            //do nothing
            return false;
        }
        else if(gameBoard[toX][toY]->player == player) {
            //do nothing
            return false;
        }
        else if(gameBoard[toX][toY]->player == 0){
            gameBoard[fromX][fromY]->player = 0;
            gameBoard[toX][toY]->player = player;
            return true;
        }
    }

    return false;
}

int* cellManager::makeAIMove(int player, char* AiLocation)
{
    //char* sampleAI = "http://lyle.smu.edu/~tbgeorge/cse4345/a1/getMove.php";
    RemoteAI ai(AiLocation);
    int piecesCounter = 0;
    int enemyCounter = 0;
    int destCounter = 0;
    int enemyDestCounter = 0;

    int piecesX[12];
    int enemyX[12];
    int destX[9];
    int enemyDestX[9];

    int piecesY[12];
    int enemyY[12];
    int destY[9] ;
    int enemyDestY[9];

    for(int i=0; i < 18; i++) {
        for(int j=0; j<18; j++){
            if(gameBoard[i][j]->player == player) {
                piecesX[piecesCounter] = i;
                piecesY[piecesCounter] = j;
                piecesCounter++;
            }
            else if(gameBoard[i][j]->player != player && gameBoard[i][j]->player != 0) {
                enemyX[enemyCounter] = i;
                enemyY[enemyCounter] = j;
                enemyCounter++;
            }
            else if(gameBoard[i][j]->dest == player) {
                destX[destCounter] = i;
                destY[destCounter] = j;
                destCounter++;
            }
            else if(gameBoard[i][j]->dest != player && gameBoard[i][j]->dest != 0) {
                enemyDestX[enemyDestCounter] = i;
                enemyDestY[enemyDestCounter] = j;
                enemyDestCounter++;
            }

        }
    }

    int* results = ai.PostJsonData(12, 9, piecesX, piecesY, destX, destY, enemyX, enemyY, enemyDestX, enemyDestY);

    makeMove(player, results[0], results[1], results[2], results[3]);

    return results;

}

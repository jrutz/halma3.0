#include "cellmanager.h"

cellManager::cellManager()
{
   for(int i=0; i < 18; i++) {
       for(int j=0; j<18; j++){
           if(i<3 && j > 13)
               gameBoard[i][j] = 1;
           else if(i>14 && j>13)
               gameBoard[i][j] = 2;
           else
               gameBoard[i][j] = 0;
       }
   }

}

bool cellManager::makeMove(int player, int fromX, int fromY, int toX, int toY)
{

    if(gameBoard[fromX][fromY] == player) {

        //if the destination is another players piece
        if(gameBoard[toX][toY] != 0  && gameBoard[toX][toY] != player) {
            //do nothing
            return false;
        }
        else if(gameBoard[toX][toY] == player) {
            //do nothing
            return false;
        }
        else if(gameBoard[toX][toY] == 0){
            gameBoard[fromX][fromY] = 0;
            gameBoard[toX][toY] = player;
            return true;
        }
    }

    return false;
>>>>>>> FETCH_HEAD
}

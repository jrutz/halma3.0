#ifndef CELLMANAGER_H
#define CELLMANAGER_H

#include <cell.h>
#include <remoteai.h>

class cellManager
{
public:

    cell* gameBoard[18][18];

    cellManager();
    bool makeMove(int player, int fromX, int fromY, int toX, int toY);
<<<<<<< HEAD
=======
    int* makeAIMove(int player, char* AiLocation);
>>>>>>> FETCH_HEAD
};

#endif // CELLMANAGER_H

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
    int* makeAIMove(int player, QString AiLocation);

};

#endif // CELLMANAGER_H

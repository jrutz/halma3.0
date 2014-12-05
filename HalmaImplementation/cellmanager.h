#ifndef CELLMANAGER_H
#define CELLMANAGER_H

#include <cell.h>

class cellManager
{
public:

    int gameBoard[18][18];

    cellManager();
    void makeMove(int player, int fromX, int fromY, int toX, int toY);
};

#endif // CELLMANAGER_H

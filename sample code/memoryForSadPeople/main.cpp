#include "gamewindow.h"
#include <QApplication>
#include "memoryhandler.h"
#include "memorylogic.h"


/*
*
*Program written by Johna Rutz
*Game of concentration using pictures from John Campbell's webcomic PicturesForSadChildren.com
*(And pictures of coffee in the harder levels)
*
*
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow w;
    w.show();
    
    return a.exec();
}

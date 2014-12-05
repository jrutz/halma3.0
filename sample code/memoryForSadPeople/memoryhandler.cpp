#include "memoryhandler.h"
#include "memorylogic.h"
#include "gamewindow.h"

#include <QString>
#include <iostream>
/*NEEDS TO:
Translate array value to QString
Adjust QString to numberValue
Match shit up
Send a message to the UI telling us that we need to freeze that pair
*/


memoryLogic logical;

memoryHandler::memoryHandler()
{

    logical.randomizeArray();
}

//Sets and randomizes an easy array
void memoryHandler:: randomizeEasy()
{
    logical.setArray();
    logical.randomizeArray();
}

//Sets and randomizes a new hard array
void memoryHandler::randomizeHard()
{
    logical.setArray();
    logical.randomizeHardArray();
}

//Returns the string for the button depending on level and button number
QString memoryHandler :: textForButton(int x, int level)
{
    int num;
    QString pictureString;
    if(level == 1)
        num = logical.sendEasyNumber(x);

    if(level == 2)
        num = logical.sendHardNumber(x);

    if(num == 1)
        pictureString = ":/easy/pic1";
    if(num == 2)
        pictureString = ":/easy/pic2";
    if(num == 3)
        pictureString = ":/easy/pic3";
    if(num == 4)
        pictureString = ":/easy/pic4";
    if(num == 5)
        pictureString = ":/easy/pic5";
    if(num == 6)
        pictureString = ":/easy/pic6";
    if(num == 7)
        pictureString = ":/easy/pic7";
    if(num == 8)
        pictureString = ":/easy/pic8";
    if(num == 9)
        pictureString= ":/hard/hardpic1";
    if(num == 10)
        pictureString = ":/hard/hardpic2";
    if(num == 11)
        pictureString = ":/hard/hardpic3";
    if(num == 12)
        pictureString = ":/hard/hardpic4";

return pictureString;
}



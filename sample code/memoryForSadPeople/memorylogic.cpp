#include "memorylogic.h"
#include <QTime>
#include <QGlobal.h>


/* All this knows is:
 * Randomize arrays
*/

memoryLogic::memoryLogic()
{

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    setArray();

}

//Sets an easy array and hard array as well as fills the shuffled arrays to zero
void memoryLogic :: setArray()
{
    for (int i = 0; i < 16; i ++)
    {
        if(i == 0 || i == 1)
            numbers[i] = 1;
        if(i == 2 || i == 3)
            numbers[i] = 2;
        if(i == 4 || i == 5)
            numbers[i] = 3;
        if(i == 6 || i == 7)
            numbers[i] = 4;
        if(i == 8 || i == 9)
            numbers[i] = 5;
        if(i == 10 || i == 11)
            numbers[i] = 6;
        if(i == 12 || i == 13)
            numbers[i] = 7;
        if(i == 15 || i ==14)
            numbers[i] = 8;

        shuffledArray[i] = 0;
    }


    for (int i = 0; i < 24 ; i++)
    {
        if(i == 0 || i ==1)
            hardNumbers[i]=1;
        if(i == 2 || i ==3)
            hardNumbers[i]=2;
        if(i == 4 || i ==5)
            hardNumbers[i]=3;
        if(i == 6 || i ==7)
            hardNumbers[i]=4;
        if(i == 8 || i ==9)
            hardNumbers[i]=5;
        if(i == 10 || i ==11)
            hardNumbers[i]=6;
        if(i == 12 || i ==13)
            hardNumbers[i]=7;
        if(i == 14 || i ==15)
            hardNumbers[i]=8;
        if(i == 16 || i ==17)
            hardNumbers[i]=9;
        if(i == 18 || i ==19)
            hardNumbers[i]=10;
        if(i == 20 || i ==21)
            hardNumbers[i]=11;
        if(i == 22 || i == 23)
            hardNumbers[i]=12;

        shuffledHard[i]= 0;
    }
}


//Randomizes the smaller array
void memoryLogic:: randomizeArray()
{
    int shuffleNum = 0;
    while (shuffleNum < 16)
    {
        int choice = qrand() % 16;

        if(shuffledArray[choice] == 0)
        {
            shuffledArray[choice] = numbers[shuffleNum];
            shuffleNum++;
        }
    }
}

//Randomizes the large array
void memoryLogic::randomizeHardArray()
{
    int shuffleNum = 0;
    while(shuffleNum < 24)
    {
        int choice = qrand() % 24;
        if(shuffledHard[choice]==0)
        {
            shuffledHard[choice] = hardNumbers[shuffleNum];
            shuffleNum++;
        }
    }
}

//Sends the number in the easy array associated with the picture
int memoryLogic::sendEasyNumber(int arraySpot)
{
    int arrayNumber;
    arrayNumber = shuffledArray[arraySpot-1];
    return arrayNumber;
}

//Sends the associated text number (for the button) for the large array
int memoryLogic::sendHardNumber(int arraySpot)
{
    int arrayNumber;
    arrayNumber = shuffledHard[arraySpot-1];
    return arrayNumber;
}

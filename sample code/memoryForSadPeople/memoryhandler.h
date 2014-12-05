#ifndef MEMORYHANDLER_H
#define MEMORYHANDLER_H
#include <memorylogic.h>


#include <QString>

class memoryHandler
{
public:
    memoryHandler();

QString textForButton(int x, int level);
void randomizeHard();
void randomizeEasy();


private:
    QString primaryPictureString;
    QString secondaryPictureString;

    int buttonPressed;

    memoryLogic a;

};

#endif // MEMORYHANDLER_H

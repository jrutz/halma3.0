#ifndef MEMORYLOGIC_H
#define MEMORYLOGIC_H


class memoryLogic
{
public:
    memoryLogic();
    void randomizeArray();
    int sendEasyNumber(int);
    int sendHardNumber(int);
    void randomizeHardArray();

    void setArray();

    int numbers[16];
    int shuffledArray[16];

    int hardNumbers[24];
    int shuffledHard[24];

};

#endif // MEMORYLOGIC_H

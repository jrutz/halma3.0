#include "cell.h"

cell::cell()
{
    player = 0;
    dest = 0;
}

cell::cell(int p, int d)
{
    player = p;
    dest = d;
}

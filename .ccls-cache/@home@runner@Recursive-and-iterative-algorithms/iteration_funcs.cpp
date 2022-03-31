#include "iteration_funcs.h"



unsigned long long int GCDIterative(unsigned long long int x, unsigned long long int y)
{
    while(x != y) {
    if(x > y)
      x -= y;
    else
      y -= x;
    }
    return x;
}
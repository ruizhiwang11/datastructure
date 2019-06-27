#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SNode *PtrToSNode;
struct SNode
{
    int begin;
    char src,bri,dst;

    /* data */

};

struct oprt
{
    int begin, end; char src, bri, dst; 
    oprt(){} 
    oprt(int _begin, int _end, char _src, char _bri, char _dst) :begin(_begin), end(_end), src(_src), bri(_bri), dst(_dst){} 

};


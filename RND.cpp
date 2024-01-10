#include "RND.h"

int RND::rnd(){
    //srand(_seed);
    return rand() % (_end - _start + 1) + _start;
}

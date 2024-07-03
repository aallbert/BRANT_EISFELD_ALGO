#include "helperFile.h"

int customPow(int base, int exp){
    int res = 1;
    for(int i = 0; i < exp; i++){
        res *= base;
    }
    return res;
}

int biggerInt(int a, int b){
    if (a > b) return a;
    return b;
}

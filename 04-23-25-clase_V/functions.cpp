#include "functions.h"

REAL directo(int N){
    REAL term = 0.0;
    for(int ii = 1; ii <= N; ii++){
        term += 1.0 / ii;
    }
    return term;
}

REAL inverso(int N){
    REAL term = 0.0;
    for(int ii = N; ii >= 1; ii--){
        term += 1.0 / ii;
    }
    return term;
}
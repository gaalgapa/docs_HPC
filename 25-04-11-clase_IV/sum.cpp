#include <iostream>
#include <cmath>

typedef float REAL;

REAL directo(int N);
REAL inverso(int N);

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

int main(void){
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    REAL dir = 0.0, inv = 0.0, diff = 0.0;
    for(int N = 0; N <= 1e6; N += 50){
        dir = directo(N);
        inv = inverso(N);
        diff = std::abs(1.0 - dir / inv);
        std::cout << N << "\t" << dir << "\t" << inv << "\t" << diff << "\n";
    }
}
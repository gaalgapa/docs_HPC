#include <iostream>
#include <cmath>

#include "functions.h"

int main(void){
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    REAL dir = 0.0, inv = 0.0, diff = 0.0;
    for(int N = 0; N <= 1e4; N++){
        dir = directo(N);
        inv = inverso(N);
        diff = std::abs(1.0 - dir / inv);
        std::cout << N << "\t" << dir << "\t" << inv << "\t" << diff << "\n";
    }
}
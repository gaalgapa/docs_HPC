#include <iostream>
#include <cmath>

typedef float REAL;

REAL V1(int N);
REAL V2(int N);
REAL V3(int N);

REAL V1(int N){
    REAL term = 0.0;
    for(int ii = 1; ii <= 2*N; ii++){
        term += std::pow(-1.0,ii) * ii / (ii + 1.0);
    }
    return term;
}

REAL V2(int N){
    REAL term1 = 0.0, term2 = 0.0, sum;
    for(int ii = 1; ii <= N; ii++){
        term1 += (2.0 * ii - 1.0) / (2.0 * ii);
        term2 += 2.0 * ii / (2.0 * ii + 1.0);
    }
    return term2 - term1;
}

REAL V3(int N){
    REAL term = 0.0;
    for(int ii = 1; ii <= N; ii++){
        term += 1.0 / (2.0 * ii * (2.0 * ii + 1.0));
    }
    return term;
}

int main(void){
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    for(int N = 1; N <=1000; ++N){
        std::cout << N << "\t" << V1(N)<< "\t" << V2(N)<< "\t" << V3(N)<< "\n";
    }
}
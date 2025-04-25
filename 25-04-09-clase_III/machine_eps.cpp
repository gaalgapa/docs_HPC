#include <iostream>
#include <cstdlib>

typedef float REAL;

int main(int argc, char **argv)
{
    std::cout.precision(20);
    std::cout.setf(std::ios::scientific);
    int N = std::atoi(argv[1]);
    REAL eps = 1.0, one = 1.0;

    for(int ii = 0; ii < N; ++ii){
        eps = eps/2.0;
        one = 1 + eps;
        std::cout << ii << "\t" << eps << "\t" << one << "\n";
    }

    return 0;

    //TODO
}
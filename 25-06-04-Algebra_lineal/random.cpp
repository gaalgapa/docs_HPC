#include <iostream>
#include <cstdlib>
#include <eigen3/Eigen/Dense>

int main(int argc, char **argv)
{
    const int SEED = std::atoi(argv[1]);
    srand(SEED); // controlar la semilla, vacío para que la semilla sea aleatoria
    Eigen::MatrixXd m = Eigen::MatrixXd::Random(5,5);
    std::cout << m << std::endl;

    return 0;
}
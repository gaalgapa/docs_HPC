#include <iostream>
#include <eigen3/Eigen/Dense>

int main(int argc, char **argv)
{
    const int SEED = std::atoi(argv[1]);
    const int L = std::atoi(argv[2]);
    srand(SEED);
    Eigen::MatrixXd A = Eigen::MatrixXd::Random(L,L);
    Eigen::VectorXd b = Eigen::VectorXd::Random(L);
    //A << 1,2,3,  4,5,6,  7,8,10;
    //b << 3, 3, 4;
    //std::cout << "Here is the matrix A:\n" << A << std::endl;
    //std::cout << "Here is the vector b:\n" << b << std::endl;
    Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);
    //std::cout << "The solution is:\n" << x << std::endl;

    std::cout << "Verification:\n" << (A*x - b).norm() << std::endl;

    return 0;
}
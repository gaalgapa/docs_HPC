#include <iostream>
#include <eigen3/Eigen/Dense>
#include <chrono>
#include <ctime>

void stats(const int size, const int reps, // input parameters
               double & mean_wtime, double & sigma_wtime, // output
               double & mean_ctime, double & sigma_ctime); // output

int main(int argc, char ** argv)
{
    const int M = atoi(argv[1]); // Matrix size
    const int R = atoi(argv[2]); // Repetitions

    double mean_wtime, sigma_wtime;
    double mean_ctime, sigma_ctime;
    stats(M, R, mean_wtime, sigma_wtime, mean_ctime, sigma_ctime);
    std::cout << M
                << "\t" << mean_wtime << "\t" << sigma_wtime
                << "\t" << mean_ctime << "\t" << sigma_ctime
                << std::endl;
        
    return 0;
}

void stats(const int size, const int reps, // input parameters
               double & mean_wtime, double & sigma_wtime, // output
               double & mean_ctime, double & sigma_ctime) // output
{
    // definir variables para sumar los tiempos
    double suma_wtime = 0.0; 
    double suma_wtime2 = 0.0;
    double suma_ctime = 0.0; 
    double suma_ctime2 = 0.0;

    // llamar/copiar codigo reps veces a solvesystem y medir su tiempo
    std::clock_t c_start, c_end;
    std::chrono::duration<double> diff;

    for (int ii = 0; ii < reps; ++ii) {
        Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
        Eigen::MatrixXd b = Eigen::MatrixXd::Random(size, 1);
        // cronometro para wtime y para cpu time

        auto start = std::chrono::steady_clock::now();
        c_start = std::clock();
        Eigen::MatrixXd x = A.partialPivLu().solve(b);
        auto end = std::chrono::steady_clock::now();
        c_end = std::clock();
        
        // anhadir a suma_wtime, suma_wtime2...
        std::chrono::duration<double> elapsedw{end - start};
        double auxw = elapsedw.count();
        suma_wtime += auxw;
        suma_wtime2 += auxw * auxw;

        double auxc = (c_end - c_start)/double(CLOCKS_PER_SEC);
        suma_ctime += auxc;
        suma_ctime2 += auxc * auxc;

        std::cerr << x(0, 0) << "\n";
    }


    // calcular las estadisticas y retornar/guardar sus valores 
    mean_wtime = suma_wtime/reps;
    sigma_wtime = std::sqrt(reps*(suma_wtime2/reps - mean_wtime*mean_wtime)/(reps-1));
    mean_ctime = suma_ctime/reps; 
    sigma_ctime = std::sqrt(reps*(suma_ctime2/reps - mean_ctime*mean_ctime)/(reps-1));

}
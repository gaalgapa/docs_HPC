#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv)
{
  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const double MU = std::atof(argv[3]);
  const double SIGMA = std::atof(argv[4]);
  const double XMIN = std::atof(argv[5]);
  const double XMAX = std::atof(argv[6]);
  const int NBINS = std::atoi(argv[7]);

  compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};

  std::vector<int> histograma(nbins, 0);
  // Dominio de cada bin (rango de valores que acepta el bin)
  double bin_l = (xmax - xmin) / nbins;

  for(int n = 0; n < nsamples; ++n) {
    double r = dis(gen);
    // Contador +1 si el valor aleatorio esta dentro del rango
    if (r >= xmin && r < xmax){
        int bin = static_cast<int>((r - xmin) / bin_l);
        histograma[bin]++;
    }
  }
  // TODO: compute and print the pdf
  for (int i = 0; i < nbins; ++i){
    // Posición del centro de cada bin
    double pos_bin = xmin + (i + 0.5) * bin_l;
    //normaliza la densidad de cada bin
    double densidad = static_cast<double>(histograma[i]) / (nsamples * bin_l);
    std::cout << pos_bin << "\t" << densidad << "\n";  
  }
}
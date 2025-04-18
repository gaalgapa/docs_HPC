#include <iostream>
#include <cmath>

typedef double REAL;

int factorial(int n);
REAL fnaive(REAL x, int N);
REAL fsmart(REAL x, int N);

int main(void)
{
  std::cout.precision(16); std::cout.setf(std::ios::scientific);
  REAL x = 1.234534534;
  const REAL exact = std::exp(-x);
  for (int NMAX = 0; NMAX <= 100; ++NMAX) {
    std::cout << NMAX
              << "\t" << fnaive(x, NMAX)
              << "\t" << std::fabs(fnaive(x, NMAX) - exact)/exact
              << "\t" << fsmart(x, NMAX)
              << "\t" << std::fabs(fsmart(x, NMAX) - exact)/exact
              << std::endl;
  }
  return 0;
}

REAL fnaive(REAL x, int N)
{
    REAL term = 0, suma = 0;
    for(int ii = 0; ii <= N; ++ii){
        term = std::pow(-x, ii) / factorial(ii);
        suma += term;
    }
    return suma;
    
}

/*
term(ii) = std::pow(-x,ii)/factorial(ii);
term(ii+1) = std::pow(-x, ii+1)/factorial(ii+1) = - (-x) * std::pow(-x, ii) / ((ii+1) * factorial(ii));
term(ii+1) = (-x / (ii+1)) * std::pow(-x, ii) / factorial(ii) = (-x / (ii+1)) * term(ii)
*/

int factorial(int n)
{
  if (n <= 0) return 1;
  return n*factorial(n-1);
}

REAL fsmart(REAL x, int N)
{
    REAL term = 1, suma = 1;
    for(int ii = 0; ii <= N; ++ii){
        term = -x / (ii+1) * term;
        suma += term;
    }
    return suma;
}
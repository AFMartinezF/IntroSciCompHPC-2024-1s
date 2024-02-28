#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cmath>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);
void print_real_pdf(int points, double xmin, double xmax, double mu, double sigma);

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
  print_real_pdf(50, XMIN, XMAX, MU, SIGMA); //computing pdf with the exact formula for comparison
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins){
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};
  // histogram stuff
  std::vector<int> hist(nbins);
  double dx=(xmax-xmin)/nbins;
  double x_i = xmin;
  double x_f = xmin+dx;

//fill here the counting histogram stuff
  double sum = 0.0;
  for(int n = 0; n < nsamples; ++n){
    double r = dis(gen);
    int i=0;
    for (double x_i = xmin; x_i < xmax; x_i=x_i+dx){
      if (r >= x_i && r <= x_i+dx){
        hist[i] += 1;
        sum += 1;
        }
        i++;
    } 
  }

  //compute and print the pdf 
  for (auto x : hist){
    std::cout<<(x_i+x_f)/2<<"\t"<<x/(sum*dx)<<std::endl;
    x_i = x_f;
    x_f += dx;
  }
}


void print_real_pdf(int points, double xmin, double xmax, double mu, double sigma)
{
    double dx=(xmax-xmin)/points;
    std::ofstream outFile("realPDF.txt"); 

    if (!outFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo para escritura.\n";
        return;
    }

    for (int i =  0; i < points; ++i) {
        double x = xmin + i*dx;
        double y =  1.0/(std::sqrt(2*M_PI)*sigma)*std::exp(-0.5*std::pow((x-mu)/sigma, 2));
        outFile << x << "\t" << y << "\n"; 
    }

    outFile.close(); 
}

 /*
  double x_i = xmin;
  double x_f = xmin+dx;
  int N = 0;
  double sum = 0.0;
  double calculated_mu = 0.0;
  double calculated_sigma = 0.0;
  for (auto x : hist) {
    N += x;
    sum += x*((x_i+x_f)/2);
    //std::cout << std::fixed <<std::setprecision(4)<< x_i << "\t" << std::setprecision(4)<< x_f << "\t" << x <<"\n";
    x_i = x_f;
    x_f += dx;    
  }
  calculated_mu = sum/N;
  double dif = 0.0;
  x_i = xmin;
  x_f = xmin+dx;
  for (auto x : hist) {
  dif += ((((x_i+x_f)/2)-calculated_mu)*(((x_i+x_f)/2)-calculated_mu))*x;
  x_i = x_f;
  x_f += dx;   
  }

  calculated_sigma = std::sqrt(dif/(N-1));
  //std::cout << "The number of dif is: " << dif << "\n";
  //std::cout << "The number of samples is: " << N << "\n";
  //std::cout << "The sum is: " << sum << "\n";
  //std::cout << "The mean is: " << calculated_mu << "\n";
  //std::cout << "The standard deviation is: " << calculated_sigma << "\n";
  // TODO: compute and print the pdf
  //print_pdf(1000, xmin, xmax, mu, sigma);
}
void print_pdf(int points, double xmin, double xmax, double mu, double sigma)
{
  double dx=(xmax-xmin)/points;
  for (int i = 0; i < points; ++i) {
    double x = xmin + i*dx;
    double y = 1.0/(std::sqrt(2*M_PI)*sigma)*std::exp(-0.5*std::pow((x-mu)/sigma, 2));
    std::cout << x << "\t" << y << "\n";
  }
}*/

/*
void print_pdf(int points, double xmin, double xmax, double mu, double sigma)
{
  double dx=(xmax-xmin)/points;
  for (int i = 0; i < points; ++i) {
    double x = xmin + i*dx;
    double y = 1.0/(std::sqrt(2*M_PI)*sigma)*std::exp(-0.5*std::pow((x-mu)/sigma, 2));
    std::cout << x << "\t" << y << "\n";
  }
}*/
    


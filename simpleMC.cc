// Program to illustrate use of ROOT random number and histogram classes
// Glen Cowan, RHUL, Physics, November 2007

#include <iostream>
#include <cmath>
#include <TH1D.h>
#include <TFile.h>
#include <TRandom3.h>

using namespace std;

int main(){

// Open output file (apparently needs to be done before booking)

  TFile* file = new TFile("simpleMC.root", "recreate");

// Book histograms
// histograms for exercise 1
  TH1D* h_a = new TH1D("h_a", "h_a", 100,-1.0, 1.0);
  TH1D* h_b = new TH1D("h_b", "h_b", 100,-2.0,2.0);
  TH1D* h_c = new TH1D("h_c", "h_c", 100, -6.0, 6.0);
// histograms for exercise 2
  TH1D* h_2a = new TH1D("h_2a", "h_2a", 100, 0.0, 1.0);
  TH1D* h_2b = new TH1D("h_2b","h_2b", 100, 0.0, 1.0);
// Create a TRandom3 object to generate random numbers

  int seed = 12345;
  TRandom3* ran = new TRandom3(seed);

// Generate some random numbers and fill histograms

  const int numValues = 10000000;

  for (int i=0; i<numValues; ++i){
    double r1 = ran -> Rndm();
    double r2 = ran -> Rndm();
    double x1 = r1 + r2 - 1;  
    h_a -> Fill(x1);
    double rsum = 0;
    double x2 = 0;
    for(int j = 0; j < 4; j++){
      double rj = ran -> Rndm();
      rsum = rsum + rj;
    }
    x2 = rsum - 2;
    h_b -> Fill(x2);

    double rsum2 = 0;
    double x3 = 0;
    for(int k = 0; k < 12; k++){
      double rk = ran -> Rndm();
      rsum2 = rsum2 + rk;
    }
    x3 = rsum2 - 6;
    h_c -> Fill(x3);

  }
//Exercise 2a and 2b 
  double xmax = 1.0;
  for (int i = 0; i < numValues; i++) {
    double r = ran -> Rndm();
    double x = sqrt(xmax*xmax - r);
    h_2a -> Fill(x); 
    double u = ran -> Rndm();
    if (u < x) { //acceptance criteria
      h_2b -> Fill(x);
    }
  }

// Store all histograms in the output file and close up

  file->Write();
  file->Close();

  return 0;
}

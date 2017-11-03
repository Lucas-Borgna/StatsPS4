// Simple ROOT macro to plot a pair of histogram.
// Modify arguments as needed.
// To execute, type .X plot2Hist.C
{

  // Set some defaults
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gStyle->SetCanvasBorderMode(0); // turn off canvas borders

  // Open the file and list its contents
  TFile* f = new TFile("simpleMC.root");
  f->ls();

  // Get a couple of histograms
  TH1D* h1 = (TH1D*)f -> Get("h_a");
  TH1D* h2 = (TH1D*)f -> Get("h_b");
  TH1D* h3 = (TH1D*)f -> Get("h_c");
  TH1D* h4 = (TH1D*)f -> Get("h_2a");
  TH1D* h5 = (TH1D*)f -> Get("h_2b");

  // Create a canvas, divide into two windows, 
  TCanvas *c1 = new TCanvas("c1", "Canvas 1", 400, 10, 600, 700);
  c1->Divide(1,5);

  // Plot the uniform numbers in upper plot
  c1->cd(1);
  //h1->SetMinimum(-1.0);
  //h1->SetMaximum(1.0);  // use default or set as appropriate     
  h1->SetXTitle("r");
  h1->SetYTitle("f(r)");
  h1->Draw();

  // Plot the exponential numbers in lower plot
  c1->cd(2);
  //h2->SetMinimum(-2.0);
  //h2->SetMaximum(2.0);  // use default or set as appropriate
  h2->SetXTitle("x");
  h2->SetYTitle("f(x;#xi)");
  h2->Draw();

  c1 -> cd(3);
  //h3 -> SetMinimum(-6.0);
  //h3 -> SetMaximum(6.0);
  h3 -> SetXTitle("x");
  h3 -> SetYTitle("f(x;#xi");
  h3 -> Draw();

  c1 -> cd(4);
  h4 -> SetXTitle("x");
  h4 -> SetYTitle("f(x)");
  h4 -> Draw();

  c1 -> cd(5);
  h5 -> SetXTitle("x");
  h5 -> SetYTitle("f(x)");
  h5 -> Draw();
} 

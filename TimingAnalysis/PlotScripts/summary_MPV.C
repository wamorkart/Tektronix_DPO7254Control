#include "TCanvas.h"
#include "TMultiGraph.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TAxis.h"
#include "TLatex.h"
#include "TStyle.h"
#include <cmath>

#include "tdrStyle.h"

void summary_MPV(){
  setTDRStyle();

  vector<string> name;
  vector<vector<double> > yval;
  vector<vector<double> > yvalErr;
  vector<vector<double> > V;
  vector<vector<double> > VErr;
  // cout << "1" << endl;

  // name.push_back("W4 prerad 1.3 x 1.3 mm^{2}");

  // name.push_back("W5 8e14 1.3 x 1.3 mm^{2}");

  // name.push_back("W5 1.5e15 1.3 x 1.3 mm^{2}");
  int is = -1;

  // V.push_back(vector<double>());
  // yval.push_back(vector<double>());
  // name.push_back("W5 prerad 3x1 mm^{2}");
  // V[is].push_back(155.);
  // V[is].push_back(165.);
  // V[is].push_back(200.);
  // V[is].push_back(200.);
  // V[is].push_back(200.);
  // V[is].push_back(205.);
  // V[is].push_back(205.);
  // yval[is].push_back(48.5 );
  // yval[is].push_back(47. );
  // yval[is].push_back(43.8 );
  // yval[is].push_back(43. );
  // yval[is].push_back(42. );
  // yval[is].push_back(41.5 );
  // yval[is].push_back(40.7 );

  is++;
  V.push_back(vector<double>());
  VErr.push_back(vector<double>());
  yval.push_back(vector<double>());
  yvalErr.push_back(vector<double>());
  name.push_back("W5 8e14 3x1 mm^{2}");


// cout << "1a" << endl;

  V[is].push_back(315.);
  VErr[is].push_back(0);
  V[is].push_back(335.);
  VErr[is].push_back(0);
  V[is].push_back(355.);
  VErr[is].push_back(0);
  V[is].push_back(365.);
  VErr[is].push_back(0);
  V[is].push_back(375.);
  VErr[is].push_back(0);
  V[is].push_back(380.);
  VErr[is].push_back(0);
  V[is].push_back(390.);
  VErr[is].push_back(0);
  V[is].push_back(395.);
  VErr[is].push_back(0);
  V[is].push_back(400.);
  VErr[is].push_back(0);


  yval[is].push_back(2.25252e-02 );
  yvalErr[is].push_back(1.64969e-04);
  yval[is].push_back(2.55813e-02 );
  yvalErr[is].push_back(1.88229e-04);
  yval[is].push_back(2.91893e-02  );
  yvalErr[is].push_back(2.06974e-04);
  yval[is].push_back(3.10914e-02 );
  yvalErr[is].push_back(1.61677e-04 );
  yval[is].push_back(3.36447e-02 );
  yvalErr[is].push_back(1.16514e-04);
  yval[is].push_back(3.49611e-02 );
  yvalErr[is].push_back(1.92131e-04 );
  yval[is].push_back(3.59310e-02);
  yvalErr[is].push_back(4.77501e-04 );
  yval[is].push_back(3.59053e-02 );
  yvalErr[is].push_back(4.46575e-04 );
  // yval[is].push_back(3.09809e-02  );
  // yvalErr[is].push_back(3.06719e-04);

  for (auto& t : yval[is])
    t = 1e3*t;

  is++;
  V.push_back(vector<double>());
  VErr.push_back(vector<double>());
  yval.push_back(vector<double>());
  yvalErr.push_back(vector<double>());
  name.push_back("W5 1.5e15 3x1 mm^{2}");

// cout << "1b" << endl;
  V[is].push_back(350.);
  VErr[is].push_back(0);
  V[is].push_back(370.);
  VErr[is].push_back(0);
  V[is].push_back(390.);
  VErr[is].push_back(0);
  V[is].push_back(400.);
  VErr[is].push_back(0);
  V[is].push_back(410.);
  VErr[is].push_back(0);
  V[is].push_back(415.);
  VErr[is].push_back(0);
  V[is].push_back(425.);
  VErr[is].push_back(0);
  V[is].push_back(435.);
  VErr[is].push_back(0);
  V[is].push_back(445.);
  VErr[is].push_back(0);
  V[is].push_back(455.);
  VErr[is].push_back(0);
  V[is].push_back(465.);
  VErr[is].push_back(0);
  V[is].push_back(485.);
  VErr[is].push_back(0);



  yval[is].push_back(1.31070e-02 );
  yvalErr[is].push_back(7.24291e-05 );
  yval[is].push_back(1.42109e-02);
  yvalErr[is].push_back(1.03516e-04 );
  yval[is].push_back(1.53623e-02 );
  yvalErr[is].push_back(1.08565e-04 );
  yval[is].push_back(1.61414e-02 );
  yvalErr[is].push_back(8.76676e-05 );
  yval[is].push_back(1.68517e-02);
  yvalErr[is].push_back(1.15587e-04 );
  yval[is].push_back(1.71044e-02 );
  yvalErr[is].push_back(1.08391e-04 );
  yval[is].push_back(1.79184e-02 );
  yvalErr[is].push_back(1.22456e-04);
  yval[is].push_back(1.90364e-02  );
  yvalErr[is].push_back(1.32178e-04  );
  yval[is].push_back(2.05360e-02 );
  yvalErr[is].push_back(1.76395e-04 );
  yval[is].push_back(2.10836e-02);
  yvalErr[is].push_back(1.66263e-04 );
  yval[is].push_back(2.24543e-02);
  yvalErr[is].push_back(1.58089e-04 );
  yval[is].push_back(2.99671e-02 );
  yvalErr[is].push_back(3.35493e-07);

  for (auto& t : yval[is])
    t = 1e3*t;

  is++;
  V.push_back(vector<double>());
  VErr.push_back(vector<double>());
  yval.push_back(vector<double>());
  yvalErr.push_back(vector<double>());
  name.push_back("W5 prerad 3x1 mm^{2}");

  V[is].push_back(165.);
  VErr[is].push_back(0);
  V[is].push_back(175.);
  VErr[is].push_back(0);
  V[is].push_back(185.);
  VErr[is].push_back(0);
  V[is].push_back(195.);
  VErr[is].push_back(0);
  V[is].push_back(200.);
  VErr[is].push_back(0);
  V[is].push_back(205.);
  VErr[is].push_back(0);

  yval[is].push_back(2.76008E-02 );
  yvalErr[is].push_back(1.34845E-04);
  yval[is].push_back(3.22510E-02 );
  yvalErr[is].push_back(2.06303E-04 );
  yval[is].push_back(3.54740E-02  );
  yvalErr[is].push_back(1.87669E-04);
  yval[is].push_back(4.04749E-02 );
  yvalErr[is].push_back(2.75637E-04 );
  yval[is].push_back(4.30925E-02 );
  yvalErr[is].push_back(3.18254E-04);
  yval[is].push_back(4.61990E-02 );
  yvalErr[is].push_back(2.87924E-09 );

  for (auto& t : yval[is])
    t = 1e3*t;



  // cout << "2" << endl;


  int Nsensor = name.size();

  int N[Nsensor];
  double X[Nsensor][20];
  double Y[Nsensor][20];
  double XErr[Nsensor][20];
  double YErr[Nsensor][20];

  vector<TGraphErrors*> gr;
  TMultiGraph* mg = new TMultiGraph();

  for(int i = 0; i < Nsensor; i++){
    // cout << "3" << endl;
    N[i] = 0;
    for(int j = 0; j < yval[i].size(); j++){
      // cout << "4" << endl;
      N[i]++;
      X[i][j] = V[i][j];
      Y[i][j] = yval[i][j];
      // Y[i][j] = sqrt(pow(yval[i][j],2) - 100); //time yval. w photek precision
      XErr[i][j] = VErr[i][j];
      YErr[i][j] = yvalErr[i][j];
      // cout << Y[i][j] << endl;
    }
    gr.push_back( new TGraphErrors(N[i], X[i], Y[i], XErr[i], YErr[i]));
    // cout << "5" << endl;
    if(i/3 == 0){
      gr[i]->SetMarkerStyle(22);
    } else {
      gr[i]->SetMarkerStyle(21);
    }
    if(i%3 == 0){ // prerad
      gr[i]->SetMarkerColor(kRed+2);
      gr[i]->SetLineColor(kRed+2);
    }
    if(i%4 == 0){ // 8e14
      gr[i]->SetMarkerColor(kGreen+2);
      gr[i]->SetLineColor(kGreen+2);
    }
    if(i%2 == 1){ // 1.5e15
      gr[i]->SetMarkerColor(kBlue+2);
      gr[i]->SetLineColor(kBlue+2);
    }
    gr[i]->SetMarkerSize(2);
    gr[i]->SetFillColor(kWhite);
    // gr[i]->SetLineWidth(0);
    // gr[i]->SetLineColor(kWhite);
    mg->Add(gr[i]);
    // cout << "6" << endl;
  }

  TCanvas* cv = new TCanvas("cv_mpv","cv_mpv",800,600);
  cv->SetTopMargin(0.09);
  cv->SetGrid();
// cout << "7" << endl;
  mg->Draw("ap");

  TLegend* leg1,*leg2;

  // leg1 = new TLegend(0.476,0.70,0.645,0.89);
  // //leg1->SetHeader("DUT Name","C");
  // leg1->AddEntry(tg_W8,"FBK W8","p");
  // leg1->AddEntry(tg_W6,"FBK W6","p");
  // leg1->AddEntry(tg_W1,"FBK W1","p");
  // leg1->AddEntry(tg_HPK,"HPK 35#mum","p");
  // leg1->SetTextSize(0.033);
  // leg1->Draw("same");

  leg2 = new TLegend(0.2,0.69,0.475,0.88);
  //width: .237
  //leg2->SetHeader("Fluence (n_{eq}/cm^{2})","C");
  for(int i = 0; i < Nsensor; i++){
    leg2->AddEntry(gr[i],name[i].c_str());
  }
  leg2->SetTextSize(0.033);
  leg2->Draw("same");

  TLatex l;
  l.SetTextFont(132);
  l.SetNDC();
  l.SetTextSize(0.035);
  l.SetTextFont(42);
  l.DrawLatex(0.47,0.943,"Fermilab TB Nov. 2018 FBK LGAD *Preliminary*");
  l.SetTextSize(0.04);
  l.SetTextFont(61);
  l.DrawLatex(0.16,0.943,"CMS");
  l.SetTextFont(52);
  l.DrawLatex(0.23,0.943,"Preliminary");


  cv->Update();
// cout << "8" << endl;
  // TLine *line = new TLine(0., 30., 95., 30.);
  // line->SetLineStyle(9);
  // line->SetLineWidth(2);
  // //line->Draw();
  // //cv->Update();

  mg->GetXaxis()->SetTitle("Bias Voltage [V]");
  mg->GetXaxis()->CenterTitle();
  mg->GetXaxis()->SetTitleOffset(1.15);
  mg->GetXaxis()->SetTitleSize(0.04);
  mg->GetYaxis()->SetTitle("Most Probable Value [mV]");
  mg->GetYaxis()->CenterTitle();
  mg->GetYaxis()->SetTitleOffset(1.2);
  mg->GetYaxis()->SetTitleSize(0.04);
  mg->GetXaxis()->SetLimits(100,500);
  mg->GetXaxis()->SetRangeUser(100,500);
  mg->GetYaxis()->SetRangeUser(0,80);
  gPad->Modified();

  // CMSmark("Fermilab TB Dec. '17 - Apr. '18 LGAD Summary");

  // cv->SaveAs("moneyplottest.pdf");

}

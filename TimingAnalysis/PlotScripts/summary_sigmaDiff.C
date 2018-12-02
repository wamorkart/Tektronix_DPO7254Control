#include "TCanvas.h"
#include "TMultiGraph.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TAxis.h"
#include "TLatex.h"
#include "TStyle.h"
#include <cmath>

#include "tdrStyle.h"

void summary_sigmaDiff(){
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


  yval[is].push_back(46.4438 );
  yvalErr[is].push_back(1.17134);
  yval[is].push_back(45.4057 );
  yvalErr[is].push_back(1.16992);
  yval[is].push_back(43.6634 );
  yvalErr[is].push_back(1.09434);
  yval[is].push_back(40.7761 );
  yvalErr[is].push_back(0.772206);
  yval[is].push_back(41.7737 );
  yvalErr[is].push_back(0.551223);
  yval[is].push_back(39.8184 );
  yvalErr[is].push_back(0.834218);
  yval[is].push_back(42.5196 );
  yvalErr[is].push_back(0.206727);
  yval[is].push_back(39.8544 );
  yvalErr[is].push_back(1.0621);
  yval[is].push_back(42.0533 );
  yvalErr[is].push_back(1.24288);

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



  yval[is].push_back(48.999 );
  yvalErr[is].push_back(1.19095);
  yval[is].push_back(48.5973 );
  yvalErr[is].push_back(1.23562);
  yval[is].push_back(48.4654 );
  yvalErr[is].push_back(1.21399);
  yval[is].push_back(48.3089 );
  yvalErr[is].push_back(0.979101);
  yval[is].push_back(47.5185 );
  yvalErr[is].push_back(0.657261);
  yval[is].push_back(46.3252 );
  yvalErr[is].push_back(0.931516);
  yval[is].push_back(45.6495 );
  yvalErr[is].push_back(1.18478);
  yval[is].push_back(43.9925 );
  yvalErr[is].push_back(1.07501);
  yval[is].push_back(48.6965 );
  yvalErr[is].push_back(1.20004);
  yval[is].push_back(46.2849);
  yvalErr[is].push_back(1.14169);
  yval[is].push_back(41.2738 );
  yvalErr[is].push_back(0.982247);
  yval[is].push_back(43.8357);
  yvalErr[is].push_back(0.224068);

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

  yval[is].push_back(46.5875 );
  yvalErr[is].push_back(0.834218);
  yval[is].push_back(45.1345 );
  yvalErr[is].push_back(1.17157);
  yval[is].push_back(43.0609 );
  yvalErr[is].push_back(0.866089);
  yval[is].push_back(41.4334 );
  yvalErr[is].push_back(0.577254);
  yval[is].push_back(42.6893 );
  yvalErr[is].push_back(0.594459);
  yval[is].push_back(43.352 );
  yvalErr[is].push_back(0.21591);




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
    // gr[i]->SetLineWidth(0);
    // gr[i]->SetLineColor(kWhite);
    mg->Add(gr[i]);
    // cout << "6" << endl;
  }

  TCanvas* cv = new TCanvas("cv_sigmaDiff","cv_sigmaDiff",800,600);
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
  mg->GetYaxis()->SetTitle("Sigma of time difference with MCP-PMT [ps]");
  mg->GetYaxis()->CenterTitle();
  mg->GetYaxis()->SetTitleOffset(1.2);
  mg->GetYaxis()->SetTitleSize(0.04);
  mg->GetXaxis()->SetLimits(100,500);
  mg->GetXaxis()->SetRangeUser(100,500);
  mg->GetYaxis()->SetRangeUser(35,60);
  gPad->Modified();

  // CMSmark("Fermilab TB Dec. '17 - Apr. '18 LGAD Summary");

  // cv->SaveAs("moneyplottest.pdf");

}

#define step3p5_cxx
#include "step3p5.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void step3p5::Loop(){

   if (inputTree == 0) return;

   inputTree->SetBranchStatus("*",1);

   outputFile->cd();
   TTree *outputTree = inputTree->CloneTree(0);
   
   std::pair<float,float> JER_Epair;

   Long64_t nentries = inputTree->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = inputTree->GetEntry(jentry);   nbytes += nb;    

      //JER Energy Correction
      JER_Epair = JERenergyCorrection(jentry,hJet_pt[0],hJet_pt[1],inputTreeNom);
      hJet_e[0] = JER_Epair.first;
      hJet_e[1] = JER_Epair.second;
      
      outputTree->Fill();
   }
   
   outputTree->Write();

}


std::pair<float,float> step3p5::JERenergyCorrection(Long64_t entry, float pt0, float pt1, TTree *t)
{
  float E0Corr = 1.,E1Corr=1.;
  std::pair<float,float> r(E0Corr,E1Corr);
  if(!t) return std::pair<float,float>(-99,-99);

  Float_t hJet_e_Nom[2],hJet_pt_Nom[2];

  t->SetBranchAddress("hJet_pt",&hJet_pt_Nom);
  t->SetBranchAddress("hJet_e",&hJet_e_Nom);

  t->GetEntry(entry);

  E0Corr = hJet_e_Nom[0] * (pt0/hJet_pt_Nom[0]);
  E1Corr = hJet_e_Nom[1] * (pt1/hJet_pt_Nom[1]);
  r.first = E0Corr;
  r.second = E1Corr;
  return (r);
}


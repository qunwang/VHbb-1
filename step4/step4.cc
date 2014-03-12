#define step4_cxx
#include "step4.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include "METzCalculator.h"

void step4::Loop(){

   if (inputTree == 0) return;

   inputTree->SetBranchStatus("*",0);

   //Specify branches to keep
   inputTree->SetBranchStatus("aJet_eta",1);
   inputTree->SetBranchStatus("aJet_id",1);
   inputTree->SetBranchStatus("aJet_pt",1);
   inputTree->SetBranchStatus("aJet_puJetIdL",1);
   inputTree->SetBranchStatus("aLepton_pt",1);
   inputTree->SetBranchStatus("aLepton_eta",1);
   inputTree->SetBranchStatus("aLepton_pfCorrIso",1);
   inputTree->SetBranchStatus("cschaloFlag",1);
   inputTree->SetBranchStatus("ecalFlag",1);
   inputTree->SetBranchStatus("eebadscFlag",1);
   inputTree->SetBranchStatus("effectiveLumi",1);
   inputTree->SetBranchStatus("EVENT",1);
   //inputTree->SetBranchStatus("EVENT.json",1);
   //inputTree->SetBranchStatus("EVENT.run",1);
   inputTree->SetBranchStatus("H",1);
   inputTree->SetBranchStatus("hbhe",1);
   inputTree->SetBranchStatus("hcallaserFlag",1);
   inputTree->SetBranchStatus("hJet_csv",1);
   inputTree->SetBranchStatus("hJet_csvReshapedNew",1);
   inputTree->SetBranchStatus("hJet_csv_downBC",1);
   inputTree->SetBranchStatus("hJet_csv_downL",1);
   inputTree->SetBranchStatus("hJet_csv_nominal",1);
   inputTree->SetBranchStatus("hJet_csv_upBC",1);
   inputTree->SetBranchStatus("hJet_csv_upL",1);
   inputTree->SetBranchStatus("hJet_e",1);
   inputTree->SetBranchStatus("hJet_eta",1);
   inputTree->SetBranchStatus("hJet_flavour",1);
   inputTree->SetBranchStatus("hJet_id",1);
   inputTree->SetBranchStatus("hJet_phi",1);
   inputTree->SetBranchStatus("hJet_pt",1);
   inputTree->SetBranchStatus("hJet_ptCorr",1);
   inputTree->SetBranchStatus("hJet_puJetIdL",1);
   inputTree->SetBranchStatus("HVdPhi",1);
   inputTree->SetBranchStatus("isBadHcalEvent",1);
   inputTree->SetBranchStatus("lMETdPhi",1);
   inputTree->SetBranchStatus("METtype1corr",1);
   inputTree->SetBranchStatus("naJets",1);
   inputTree->SetBranchStatus("nalep",1);
   inputTree->SetBranchStatus("PUweight",1);
   inputTree->SetBranchStatus("PUweightM",1);
   inputTree->SetBranchStatus("PUweightP",1);
   inputTree->SetBranchStatus("trackingfailureFlag",1);
   inputTree->SetBranchStatus("triggerFlags",1);
   inputTree->SetBranchStatus("V",1);
   inputTree->SetBranchStatus("vLepton_charge",1);
   inputTree->SetBranchStatus("vLepton_eta",1);
   inputTree->SetBranchStatus("vLepton_id80",1);
   inputTree->SetBranchStatus("vLepton_pfCorrIso",1);
   inputTree->SetBranchStatus("vLepton_mass",1);
   inputTree->SetBranchStatus("vLepton_phi",1);
   inputTree->SetBranchStatus("vLepton_pt",1);
   inputTree->SetBranchStatus("vLepton_type",1);
   inputTree->SetBranchStatus("vLepton_wp80",1);
   inputTree->SetBranchStatus("Vtype",1);
   inputTree->SetBranchStatus("weightSignalEWK",1);
   inputTree->SetBranchStatus("weightSignalQCD",1);
   inputTree->SetBranchStatus("weightTrig2012A");
   inputTree->SetBranchStatus("weightTrig2012SingleEle",1);
   inputTree->SetBranchStatus("weightTrig2012SingleMuon",1);
   inputTree->SetBranchStatus("x_costheta1",1);
   inputTree->SetBranchStatus("x_costheta2",1);
   inputTree->SetBranchStatus("x_costhetastar",1);
   inputTree->SetBranchStatus("x_mVH",1);
   inputTree->SetBranchStatus("x_phi",1);
   inputTree->SetBranchStatus("x_phi1",1);
   inputTree->SetBranchStatus("x_phi2",1);
   inputTree->SetBranchStatus("x_rapidityVH",1);

   outputFile->cd();
   TTree *outputTree = inputTree->CloneTree(0);

   //Get the 4-vect of Hbb, Wlv
   TLorentzVector bjet0;
   TLorentzVector bjet1;
   TLorentzVector chargelep;
   TString lep_type;
   TLorentzVector met;
   TLorentzVector neutrino;
   TLorentzVector higgs;
   TLorentzVector wlep;

   Long64_t nentries = inputTree->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = inputTree->GetEntry(jentry);   nbytes += nb;
      
      if (Cut(ientry) != 1) continue;  //Pre-selection

      //Get the 4-vect of Hbb, Wlv                                                                                                                                                              
      bjet0.SetPtEtaPhiE(hJet_pt[0],hJet_eta[0], hJet_phi[0],hJet_e[0]);
      bjet1.SetPtEtaPhiE(hJet_pt[1],hJet_eta[1], hJet_phi[1],hJet_e[1]);

      chargelep.SetPtEtaPhiM(vLepton_pt[0], vLepton_eta[0], vLepton_phi[0], vLepton_mass[0]);
      if(vLepton_type[0]==11){ lep_type="electron";}
      else{
	if(vLepton_type[0]==13){ lep_type="muon";
	} 
      }

      //use MET type1 corr                                                                                                                                                                      
      met.SetPtEtaPhiE(METtype1corr_et, 0, METtype1corr_phi, METtype1corr_et);
      neutrino=getNeutrino(chargelep, met, lep_type, 0);
      
      higgs=bjet0+bjet1;
      wlep=chargelep+neutrino;

      lMETdPhi=fabs(chargelep.DeltaPhi(met));

      //I assume you have the following four four-vectors:                                                                                                                                      
      //fs_f0 is the four-vector of the fermion particle                                                                                                                                        
      //fs_f1 is the four-vector of the fermion ***anti***-particle                                                                                                                             
      //fs_b0 is the four-vector of the b jet with the higher pT                                                                                                                                
      //fs_b1 is the four-vector of the b jet with the lower pT                                                                                                                                 
      //(Note: we use pT since we don't know which b jet is the particle or anti particle)                                                                                                      
      TLorentzVector fs_f0;
      TLorentzVector fs_f1;
      TLorentzVector fs_b0;
      TLorentzVector fs_b1;
      if(vLepton_charge[0]==1){
	fs_f0=neutrino;
	fs_f1=chargelep;
      }else{
	if(vLepton_charge[0]==-1){
	  fs_f0=chargelep;
	  fs_f1=neutrino;
	}
      }
      fs_b0=bjet0; fs_b1=bjet1;

      TLorentzVector p4_Vff = fs_f0 + fs_f1; //Four-vector of V that decays to two fermions                                                                                                     
      TLorentzVector p4_Hbb = fs_b0 + fs_b1; //Four-vector of H                                                                                                                                 
      TLorentzVector p4_VH = p4_Vff + p4_Hbb; //Four-vector of off-shell V that decays to VH                                                                                                    

      Double_t a_costheta1, a_costheta2, a_costhetastar, a_Phi, a_Phi1, a_Phi2;
      computeAngles( p4_VH, p4_Vff, fs_f0, fs_f1, p4_Hbb, fs_b0, fs_b1,
		     a_costheta1, a_costheta2, a_Phi, a_costhetastar, a_Phi1, a_Phi2);

      //remap to convention of arXiv:1309.4819
      x_costheta1 = (float) a_costheta1;
      x_costheta2 = (float) a_costhetastar;
      x_phi = (float) a_Phi1;
      x_costhetastar = TMath::Abs( (float) a_costheta2);
      x_phi1 = (float) a_Phi;
      //x_phi2 = TMath::Pi() - x_phi1 - x_phi;
      x_phi2 = (float) a_Phi2;
      x_mVH = (float) p4_VH.M();
      x_rapidityVH = (float) p4_VH.Rapidity();

      outputTree->Fill();
   }
   
   outputTree->Write();

}


TLorentzVector getNeutrino(TLorentzVector chargelep, TLorentzVector met, TString lep_type, Int_t diffMode)//diffMode: different neutrino vz                                                                                                                                               
{

  TLorentzVector p4_neutrino;
  METzCalculator metzcal;
  metzcal.SetMET(met);
  metzcal.SetLepton(chargelep);
  if(lep_type=="electron" || lep_type=="muon") metzcal.SetLeptonType(lep_type.Data());
  Double_t pzNu1=metzcal.Calculate(diffMode);
  //Double_t pzNu2=metzcal.getOther();

  //Double_t energy=TMath::Sqrt(met.E()*met.E()+pzNu1*pzNu1);
  Double_t energy = TMath::Sqrt(met.Px()*met.Px() + met.Py()*met.Py() + pzNu1*pzNu1 );
  p4_neutrino.SetPxPyPzE(met.Px(), met.Py(), pzNu1, energy);

  if(metzcal.IsComplex()){

    double event_met_pfmetPhi = met.Phi();
    double b_nvpz = pzNu1;

    double nu_pt1 = metzcal.getPtneutrino(1);
    double nu_pt2 = metzcal.getPtneutrino(2);
    TLorentzVector tmpp1;
    tmpp1.SetPxPyPzE(nu_pt1 * cos(event_met_pfmetPhi), nu_pt1 * sin(event_met_pfmetPhi), b_nvpz, sqrt(nu_pt1*nu_pt1 + b_nvpz*b_nvpz) );
    //tmpp1.SetPxPyPzE(nu_pt1 * cos(event_metMVA_metPhi), nu_pt1 * sin(event_metMVA_metPhi), b_nvpz, sqrt(nu_pt1*nu_pt1 + b_nvpz*b_nvpz));//Move to MVA MET Later
    TLorentzVector tmpp2;
    tmpp2.SetPxPyPzE(nu_pt2 * cos(event_met_pfmetPhi), nu_pt2 * sin(event_met_pfmetPhi), b_nvpz, sqrt(nu_pt2*nu_pt2 + b_nvpz*b_nvpz) );
    //tmpp2.SetPxPyPzE(nu_pt2 * cos(event_metMVA_metPhi), nu_pt2 * sin(event_metMVA_metPhi), b_nvpz, sqrt(nu_pt2*nu_pt2 + b_nvpz*b_nvpz) ); //Move to MVA MET Later

    //b_nvp = tmpp1; if ( fabs((mup+tmpp1).M()-80.4) > fabs((mup+tmpp2).M()-80.4) )  b_nvp = tmpp2;
    p4_neutrino = tmpp1;
    if ( fabs((chargelep+tmpp1).M()-80.4) > fabs((chargelep+tmpp2).M()-80.4) )  p4_neutrino= tmpp2;


  }

  //if(metzcal.IsComplex())p4_neutrino.SetPxPyPzE(0.,0.,0.,-10);
  return p4_neutrino;
}


//////////////////////////////////
//// P A P E R 4 - V E C T O R D E F I N I T I O N O F P H I A N D P H I 1
//////////////////////////////////
void computeAngles(TLorentzVector thep4H, TLorentzVector thep4Z1, TLorentzVector thep4M11, TLorentzVector thep4M12, TLorentzVector thep4Z2, TLorentzVector thep4M21, TLorentzVector thep4M22, double& costheta1, double& costheta2, double& Phi, double& costhetastar, double& Phi1, double& Phi2){

  ///////////////////////////////////////////////
  // check for z1/z2 convention, redefine all 4 vectors with convention
  ///////////////////////////////////////////////
  TLorentzVector p4H, p4Z1, p4M11, p4M12, p4Z2, p4M21, p4M22;
  p4H = thep4H;

  p4Z1 = thep4Z1; p4M11 = thep4M11; p4M12 = thep4M12;
  p4Z2 = thep4Z2; p4M21 = thep4M21; p4M22 = thep4M22;
  //// costhetastar
  TVector3 boostX = -(thep4H.BoostVector());
  TLorentzVector thep4Z1inXFrame( p4Z1 );
  TLorentzVector thep4Z2inXFrame( p4Z2 );
  thep4Z1inXFrame.Boost( boostX );
  thep4Z2inXFrame.Boost( boostX );
  TVector3 theZ1X_p3 = TVector3( thep4Z1inXFrame.X(), thep4Z1inXFrame.Y(), thep4Z1inXFrame.Z() );
  TVector3 theZ2X_p3 = TVector3( thep4Z2inXFrame.X(), thep4Z2inXFrame.Y(), thep4Z2inXFrame.Z() );
  costhetastar = theZ1X_p3.CosTheta();

  //// --------------------------- costheta1
  TVector3 boostV1 = -(thep4Z1.BoostVector());
  TLorentzVector p4M11_BV1( p4M11 );
  TLorentzVector p4M12_BV1( p4M12 );
  TLorentzVector p4M21_BV1( p4M21 );
  TLorentzVector p4M22_BV1( p4M22 );
  p4M11_BV1.Boost( boostV1 );
  p4M12_BV1.Boost( boostV1 );
  p4M21_BV1.Boost( boostV1 );
  p4M22_BV1.Boost( boostV1 );

  TLorentzVector p4V2_BV1 = p4M21_BV1 + p4M22_BV1;
  //// costheta1
  costheta1 = -p4V2_BV1.Vect().Dot( p4M11_BV1.Vect() )/p4V2_BV1.Vect().Mag()/p4M11_BV1.Vect().Mag();

  //// --------------------------- costheta2
  TVector3 boostV2 = -(thep4Z2.BoostVector());
  TLorentzVector p4M11_BV2( p4M11 );
  TLorentzVector p4M12_BV2( p4M12 );
  TLorentzVector p4M21_BV2( p4M21 );
  TLorentzVector p4M22_BV2( p4M22 );
  p4M11_BV2.Boost( boostV2 );
  p4M12_BV2.Boost( boostV2 );
  p4M21_BV2.Boost( boostV2 );
  p4M22_BV2.Boost( boostV2 );

  TLorentzVector p4V1_BV2 = p4M11_BV2 + p4M12_BV2;
  //// costheta2
  costheta2 = -p4V1_BV2.Vect().Dot( p4M21_BV2.Vect() )/p4V1_BV2.Vect().Mag()/p4M21_BV2.Vect().Mag();

  //// --------------------------- Phi and Phi1
  // TVector3 boostX = -(thep4H.BoostVector());
  TLorentzVector p4M11_BX( p4M11 );
  TLorentzVector p4M12_BX( p4M12 );
  TLorentzVector p4M21_BX( p4M21 );
  TLorentzVector p4M22_BX( p4M22 );

  p4M11_BX.Boost( boostX );
  p4M12_BX.Boost( boostX );
  p4M21_BX.Boost( boostX );
  p4M22_BX.Boost( boostX );

  TVector3 tmp1 = p4M11_BX.Vect().Cross( p4M12_BX.Vect() );
  TVector3 tmp2 = p4M21_BX.Vect().Cross( p4M22_BX.Vect() );

  TVector3 normal1_BX( tmp1.X()/tmp1.Mag(), tmp1.Y()/tmp1.Mag(), tmp1.Z()/tmp1.Mag() );
  TVector3 normal2_BX( tmp2.X()/tmp2.Mag(), tmp2.Y()/tmp2.Mag(), tmp2.Z()/tmp2.Mag() );

  //// Phi
  TLorentzVector p4Z1_BX = p4M11_BX + p4M12_BX;
  double tmpSgnPhi = p4Z1_BX.Vect().Dot( normal1_BX.Cross( normal2_BX) );
  double sgnPhi = tmpSgnPhi/fabs(tmpSgnPhi);
  Phi = sgnPhi * acos( -1.*normal1_BX.Dot( normal2_BX) );

  ////////////// 

  TVector3 beamAxis(0,0,1);
  TVector3 tmp3 = (p4M11_BX + p4M12_BX).Vect();

  TVector3 p3V1_BX( tmp3.X()/tmp3.Mag(), tmp3.Y()/tmp3.Mag(), tmp3.Z()/tmp3.Mag() );
  TVector3 tmp4 = beamAxis.Cross( p3V1_BX );
  TVector3 normalSC_BX( tmp4.X()/tmp4.Mag(), tmp4.Y()/tmp4.Mag(), tmp4.Z()/tmp4.Mag() );

  //// Phi1
  double tmpSgnPhi1 = p4Z1_BX.Vect().Dot( normal1_BX.Cross( normalSC_BX) );
  double sgnPhi1 = tmpSgnPhi1/fabs(tmpSgnPhi1);
  Phi1 = sgnPhi1 * acos( normal1_BX.Dot( normalSC_BX) );

  //// Phi2
  TLorentzVector p4Z2_BX = p4M21_BX + p4M22_BX;
  double tmpSgnPhi2 = p4Z2_BX.Vect().Dot( normal2_BX.Cross( normalSC_BX) );
  double sgnPhi2 = tmpSgnPhi2/fabs(tmpSgnPhi2);
  Phi2 = sgnPhi2 * acos( normal2_BX.Dot( normalSC_BX) );


}

//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Feb 23 13:16:03 2014 by ROOT version 5.32/00
// from TTree tree/myTree
// found on file: /eos/uscms/store/user/sethzenz/fromdcache/Ntuple_Step1V42_Step2Tag_EDMV42_Step2_V6_MC_varsAddedSummed_v19/nominal/Step2_WHiggs0P_M-125p6_8TeV-JHUGenV4-private_000_varsBDTsAdded.root
//////////////////////////////////////////////////////////

#ifndef step4_h
#define step4_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <math.h>

#include "METzCalculator.h"
#include "KDcalcPPWH.cc"
#include "RooRealVar.h"

typedef struct 
{
  float et; 
  float sumet;   
  float sig;
  float phi;
} METInfo;

typedef struct
{
  int HiggsFlag;
  float mass;
  float pt;
  float eta;
  float phi;
  float dR;
  float dPhi;
  float dEta;
} HiggsInfo;

typedef struct 
{
  float mass;  //MT in case of W
  float pt;
  float eta;
  float phi;
} TrackInfo;

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class step4 {
public :
   TTree          *inputTree;   //!pointer to the analyzed TTree or TChain
   TFile          *inputFile, *outputFile;
   Int_t           fCurrent; //!current Tree number in a TChain

   //File and tree for electron trigger correction (weightEleTrigger)
   TTree          *treeEleTrigger;
   TFile          *fileEleTrigger;

   Float_t x_costheta1;
   Float_t x_costheta2;
   Float_t x_phi;
   Float_t x_costhetastar;
   Float_t x_phi1;
   Float_t x_phi2;
   Float_t x_mVH;
   Float_t x_rapidityVH;

   KDcalcPPWH *KDCalc;
   Float_t MELA_SM;
   Float_t MELA_PS;
   Float_t MELA_HO;

   Float_t lMETdPhi;
   
   Float_t weightWpt_WJets;
   Float_t weightWpt_TTbar;

   Float_t weightEleTrigger;

   // Declaration of leaf types
   Float_t         lheV_pt;
   Float_t         lheHT;
   Float_t         lheNj;
   Int_t           nPdf;
   Float_t         PDFweight[1];   //[nPdf]
   Float_t         genZ_mass;
   Float_t         genZ_pt;
   Float_t         genZ_eta;
   Float_t         genZ_phi;
   Float_t         genZ_status;
   Float_t         genZ_charge;
   Float_t         genZ_momid;
   Float_t         genW_mass;
   Float_t         genW_pt;
   Float_t         genW_eta;
   Float_t         genW_phi;
   Float_t         genW_status;
   Float_t         genW_charge;
   Float_t         genW_momid;
   Float_t         genWstar_mass;
   Float_t         genWstar_pt;
   Float_t         genWstar_eta;
   Float_t         genWstar_phi;
   Float_t         genWstar_status;
   Float_t         genWstar_charge;
   Float_t         genWstar_momid;
   Float_t         genH_mass;
   Float_t         genH_pt;
   Float_t         genH_eta;
   Float_t         genH_phi;
   Float_t         genH_status;
   Float_t         genH_charge;
   Float_t         genH_momid;
   Int_t           nhJets;
   Int_t           naJets;
   Float_t         weightMCProd;
   Float_t         hJet_eta[2];   //[nhJets]
   Float_t         hJet_phi[2];   //[nhJets]
   Float_t         hJet_csv[2];   //[nhJets]
   Float_t         hJet_csv_nominal[2];   //[nhJets]
   Float_t         hJet_csv_upBC[2];   //[nhJets]
   Float_t         hJet_csv_downBC[2];   //[nhJets]
   Float_t         hJet_csv_upL[2];   //[nhJets]
   Float_t         hJet_csv_downL[2];   //[nhJets]
   Float_t         hJet_csv_nominal4p[2];   //[nhJets]
   Float_t         hJet_csv_upBC4p[2];   //[nhJets]
   Float_t         hJet_csv_downBC4p[2];   //[nhJets]
   Float_t         hJet_csv_nominal1Bin[2];   //[nhJets]
   Float_t         hJet_csvivf[2];   //[nhJets]
   Float_t         hJet_cmva[2];   //[nhJets]
   Float_t         hJet_cosTheta[2];   //[nhJets]
   Int_t           hJet_numTracksSV[2];   //[nhJets]
   Float_t         hJet_chf[2];   //[nhJets]
   Float_t         hJet_nhf[2];   //[nhJets]
   Float_t         hJet_cef[2];   //[nhJets]
   Float_t         hJet_nef[2];   //[nhJets]
   Float_t         hJet_nch[2];   //[nhJets]
   Float_t         hJet_nconstituents[2];   //[nhJets]
   Float_t         hJet_flavour[2];   //[nhJets]
   Int_t           hJet_isSemiLept[2];   //[nhJets]
   Int_t           hJet_isSemiLeptMCtruth[2];   //[nhJets]
   Int_t           hJet_SoftLeptpdgId[2];   //[nhJets]
   Int_t           hJet_SoftLeptIdlooseMu[2];   //[nhJets]
   Int_t           hJet_SoftLeptId95[2];   //[nhJets]
   Float_t         hJet_SoftLeptPt[2];   //[nhJets]
   Float_t         hJet_SoftLeptdR[2];   //[nhJets]
   Float_t         hJet_SoftLeptptRel[2];   //[nhJets]
   Float_t         hJet_SoftLeptRelCombIso[2];   //[nhJets]
   Float_t         hJet_genPt[2];   //[nhJets]
   Float_t         hJet_genEta[2];   //[nhJets]
   Float_t         hJet_genPhi[2];   //[nhJets]
   Float_t         hJet_JECUnc[2];   //[nhJets]
   Float_t         hJet_vtxMass[2];   //[nhJets]
   Float_t         hJet_vtxPt[2];   //[nhJets]
   Float_t         hJet_vtxEta[2];   //[nhJets]
   Float_t         hJet_vtxPhi[2];   //[nhJets]
   Float_t         hJet_vtxE[2];   //[nhJets]
   Float_t         hJet_vtx3dL[2];   //[nhJets]
   Float_t         hJet_vtx3deL[2];   //[nhJets]
   UChar_t         hJet_id[2];   //[nhJets]
   UChar_t         hJet_SF_CSVL[2];   //[nhJets]
   UChar_t         hJet_SF_CSVM[2];   //[nhJets]
   UChar_t         hJet_SF_CSVT[2];   //[nhJets]
   UChar_t         hJet_SF_CSVLerr[2];   //[nhJets]
   UChar_t         hJet_SF_CSVMerr[2];   //[nhJets]
   UChar_t         hJet_SF_CSVTerr[2];   //[nhJets]
   Float_t         hJet_ptLeadTrack[2];   //[nhJets]
   Float_t         hJet_puJetIdL[2];   //[nhJets]
   Float_t         hJet_puJetIdM[2];   //[nhJets]
   Float_t         hJet_puJetIdT[2];   //[nhJets]
   Float_t         hJet_puJetIdMva[2];   //[nhJets]
   Float_t         hJet_charge[2];   //[nhJets]
   Float_t         aJet_eta[14];   //[naJets]
   Float_t         aJet_phi[14];   //[naJets]
   Float_t         aJet_csv[14];   //[naJets]
   Float_t         aJet_csv_nominal[14];   //[naJets]
   Float_t         aJet_csv_upBC[14];   //[naJets]
   Float_t         aJet_csv_downBC[14];   //[naJets]
   Float_t         aJet_csv_upL[14];   //[naJets]
   Float_t         aJet_csv_downL[14];   //[naJets]
   Float_t         aJet_csv_nominal4p[14];   //[naJets]
   Float_t         aJet_csv_upBC4p[14];   //[naJets]
   Float_t         aJet_csv_downBC4p[14];   //[naJets]
   Float_t         aJet_csv_nominal1Bin[14];   //[naJets]
   Float_t         aJet_csvivf[14];   //[naJets]
   Float_t         aJet_cmva[14];   //[naJets]
   Float_t         aJet_cosTheta[14];   //[naJets]
   Int_t           aJet_numTracksSV[14];   //[naJets]
   Float_t         aJet_chf[14];   //[naJets]
   Float_t         aJet_nhf[14];   //[naJets]
   Float_t         aJet_cef[14];   //[naJets]
   Float_t         aJet_nef[14];   //[naJets]
   Float_t         aJet_nch[14];   //[naJets]
   Float_t         aJet_nconstituents[14];   //[naJets]
   Float_t         aJet_flavour[14];   //[naJets]
   Int_t           aJet_isSemiLept[14];   //[naJets]
   Int_t           aJet_isSemiLeptMCtruth[14];   //[naJets]
   Int_t           aJet_SoftLeptpdgId[14];   //[naJets]
   Int_t           aJet_SoftLeptIdlooseMu[14];   //[naJets]
   Int_t           aJet_SoftLeptId95[14];   //[naJets]
   Float_t         aJet_SoftLeptPt[14];   //[naJets]
   Float_t         aJet_SoftLeptdR[14];   //[naJets]
   Float_t         aJet_SoftLeptptRel[14];   //[naJets]
   Float_t         aJet_SoftLeptRelCombIso[14];   //[naJets]
   Float_t         aJet_puJetIdL[14];   //[naJets]
   Float_t         aJet_puJetIdM[14];   //[naJets]
   Float_t         aJet_puJetIdT[14];   //[naJets]
   Float_t         aJet_puJetIdMva[14];   //[naJets]
   Float_t         aJet_charge[14];   //[naJets]
   Float_t         aJet_genPt[14];   //[naJets]
   Float_t         aJet_genEta[14];   //[naJets]
   Float_t         aJet_genPhi[14];   //[naJets]
   Float_t         aJet_JECUnc[14];   //[naJets]
   Float_t         aJet_vtxMass[14];   //[naJets]
   Float_t         aJet_vtx3dL[14];   //[naJets]
   Float_t         aJet_vtx3deL[14];   //[naJets]
   UChar_t         aJet_id[14];   //[naJets]
   UChar_t         aJet_SF_CSVL[14];   //[naJets]
   UChar_t         aJet_SF_CSVM[14];   //[naJets]
   UChar_t         aJet_SF_CSVT[14];   //[naJets]
   UChar_t         aJet_SF_CSVLerr[14];   //[naJets]
   UChar_t         aJet_SF_CSVMerr[14];   //[naJets]
   UChar_t         aJet_SF_CSVTerr[14];   //[naJets]
   Float_t         deltaPullAngle;
   Float_t         weightSignalEWK;
   Float_t         weightSignalQCD;
   Float_t         weightTrig;
   Float_t         weightTrigMay;
   Float_t         weightTrigV4;
   Float_t         weightTrigMET;
   Float_t         weightTrigOrMu30;
   Float_t         weightEleRecoAndId;
   Float_t         weightEleTrigJetMETPart;
   Float_t         weightEleTrigElePart;
   Float_t         weightEleTrigEleAugPart;
   Float_t         weightTrigMET80;
   Float_t         weightTrigMET100;
   Float_t         weightTrig2CJet20;
   Float_t         weightTrigMET150;
   Float_t         weightTrigMET802CJet;
   Float_t         weightTrigMET1002CJet;
   Float_t         weightTrigMETLP;
   Float_t         weightTrig2012A;
   Float_t         weightTrig2012ADiMuon;
   Float_t         weightTrig2012ADiEle;
   Float_t         weightTrig2012ASingleMuon;
   Float_t         weightTrig2012ASingleEle;
   Float_t         weightTrig2012AMuonPlusWCandPt;
   Float_t         weightTrig2012;
   Float_t         weightTrig2012DiMuon;
   Float_t         weightTrig2012DiEle;
   Float_t         weightTrig2012SingleMuon;
   Float_t         weightTrig2012SingleEle;
   Float_t         weightTrig2012MuonPlusWCandPt;
   Float_t         weightTrig2012AB;
   Float_t         weightTrig2012ABDiMuon;
   Float_t         weightTrig2012ABDiEle;
   Float_t         weightTrig2012ABSingleMuon;
   Float_t         weightTrig2012ABSingleEle;
   Float_t         weightTrig2012ABMuonPlusWCandPt;
   Float_t         weightTrig2012DiJet30MHT80;
   Float_t         weightTrig2012PFMET150;
   Float_t         weightTrig2012SumpT100MET100;
   Float_t         weightTrig2012APFMET150orDiJetMET;
   Float_t         weightTrig2012BPFMET150orDiJetMET;
   Float_t         weightTrig2012CPFMET150orDiJetMET;
   Float_t         PUweight;
   Float_t         PUweightP;
   Float_t         PUweightM;
   Float_t         PUweightAB;
   Float_t         PUweight2011B;
   Float_t         PUweight1DObs;
   Int_t           eventFlav;
   Int_t           Vtype;
   Float_t         HVdPhi;
   Int_t           nvlep;
   Int_t           nalep;
   Float_t         vLepton_mass[2];   //[nvlep]
   Float_t         vLepton_pt[2];   //[nvlep]
   Float_t         vLepton_eta[2];   //[nvlep]
   Float_t         vLepton_phi[2];   //[nvlep]
   Float_t         vLepton_aodCombRelIso[2];   //[nvlep]
   Float_t         vLepton_pfCombRelIso[2];   //[nvlep]
   Float_t         vLepton_photonIso[2];   //[nvlep]
   Float_t         vLepton_neutralHadIso[2];   //[nvlep]
   Float_t         vLepton_chargedHadIso[2];   //[nvlep]
   Float_t         vLepton_chargedPUIso[2];   //[nvlep]
   Float_t         vLepton_particleIso[2];   //[nvlep]
   Float_t         vLepton_dxy[2];   //[nvlep]
   Float_t         vLepton_dz[2];   //[nvlep]
   Int_t           vLepton_type[2];   //[nvlep]
   Float_t         vLepton_id80[2];   //[nvlep]
   Float_t         vLepton_id95[2];   //[nvlep]
   Float_t         vLepton_vbtf[2];   //[nvlep]
   Float_t         vLepton_id80NoIso[2];   //[nvlep]
   Float_t         vLepton_genPt[2];   //[nvlep]
   Float_t         vLepton_genEta[2];   //[nvlep]
   Float_t         vLepton_genPhi[2];   //[nvlep]
   Float_t         vLepton_charge[2];   //[nvlep]
   Float_t         vLepton_pfCorrIso[2];   //[nvlep]
   Float_t         vLepton_pfCorrIsoHCP[2];   //[nvlep]
   Float_t         vLepton_id2012tight[2];   //[nvlep]
   Float_t         vLepton_idMVAnotrig[2];   //[nvlep]
   Float_t         vLepton_idMVAtrig[2];   //[nvlep]
   Float_t         vLepton_idMVApresel[2];   //[nvlep]
   Float_t         vLepton_innerHits[2];   //[nvlep]
   Float_t         vLepton_photonIsoDoubleCount[2];   //[nvlep]
   Float_t         vLepton_wpHWW[2];   //[nvlep]
   Float_t         vLepton_wp95[2];   //[nvlep]
   Float_t         vLepton_wp90[2];   //[nvlep]
   Float_t         vLepton_wp85[2];   //[nvlep]
   Float_t         vLepton_wp80[2];   //[nvlep]
   Float_t         vLepton_wp70[2];   //[nvlep]
   Float_t         aJet_selectedTauDR[14];   //[naJets]
   Float_t         aLepton_mass[37];   //[nalep]
   Float_t         aLepton_pt[37];   //[nalep]
   Float_t         aLepton_eta[37];   //[nalep]
   Float_t         aLepton_phi[37];   //[nalep]
   Float_t         aLepton_aodCombRelIso[37];   //[nalep]
   Float_t         aLepton_pfCombRelIso[37];   //[nalep]
   Float_t         aLepton_photonIso[37];   //[nalep]
   Float_t         aLepton_neutralHadIso[37];   //[nalep]
   Float_t         aLepton_chargedHadIso[37];   //[nalep]
   Float_t         aLepton_chargedPUIso[37];   //[nalep]
   Float_t         aLepton_particleIso[37];   //[nalep]
   Float_t         aLepton_dxy[37];   //[nalep]
   Float_t         aLepton_dz[37];   //[nalep]
   Int_t           aLepton_type[37];   //[nalep]
   Float_t         aLepton_id80[37];   //[nalep]
   Float_t         aLepton_id95[37];   //[nalep]
   Float_t         aLepton_vbtf[37];   //[nalep]
   Float_t         aLepton_id80NoIso[37];   //[nalep]
   Float_t         aLepton_genPt[37];   //[nalep]
   Float_t         aLepton_genEta[37];   //[nalep]
   Float_t         aLepton_genPhi[37];   //[nalep]
   Float_t         aLepton_charge[37];   //[nalep]
   Float_t         aLepton_pfCorrIso[37];   //[nalep]
   Float_t         aLepton_pfCorrIsoHCP[37];   //[nalep]
   Float_t         aLepton_id2012tight[37];   //[nalep]
   Float_t         aLepton_idMVAnotrig[37];   //[nalep]
   Float_t         aLepton_idMVAtrig[37];   //[nalep]
   Float_t         aLepton_idMVApresel[37];   //[nalep]
   Float_t         aLepton_innerHits[37];   //[nalep]
   Float_t         aLepton_photonIsoDoubleCount[37];   //[nalep]
   Float_t         aLepton_wpHWW[37];   //[nalep]
   Float_t         aLepton_wp95[37];   //[nalep]
   Float_t         aLepton_wp90[37];   //[nalep]
   Float_t         aLepton_wp85[37];   //[nalep]
   Float_t         aLepton_wp80[37];   //[nalep]
   Float_t         aLepton_wp70[37];   //[nalep]
   Float_t         rho25;
   Int_t           nPVs;
   Float_t         METtype1diff_et;
   Float_t         METtype1diff_sumet;
   Float_t         METtype1diff_sig;
   Float_t         METtype1diff_phi;
   UChar_t         triggerFlags[54];
   Int_t           EVENT_run;
   Int_t           EVENT_lumi;
   Int_t           EVENT_event;
   Int_t           EVENT_json;
   UChar_t         hbhe;
   Float_t         effectiveLumi;
   Int_t           sampleNum;
   Float_t         TopM;
   Float_t         TopPt;
   Float_t         TopEta;
   Float_t         TopPhi;
   Float_t         TopEtaLepJet;
   Float_t         TopEtaTopJet;
   Float_t         TopM_regres;
   Float_t         TopPt_regres;
   Float_t         Top2M;
   Float_t         Top2Pt;
   Float_t         Top3M;
   Float_t         Top3Pt;
   Float_t         Top2M_regres;
   Float_t         Top2Pt_regres;
   Float_t         Top3M_regres;
   Float_t         Top3Pt_regres;
   Float_t         mWH;
   Float_t         mTWH;
   Float_t         pWH;
   Float_t         pTWH;
   Float_t         hJet_csvReshapedNew[2];   //[nhJets]
   Float_t         aJet_csvReshapedNew[14];   //[naJets]
   Float_t         hJet_ptCorr[2];   //[nhJets]
   Float_t         hJet_Et[2];   //[nhJets]
   Float_t         hJet_Mt[2];   //[nhJets]
   Float_t         dPhiAJetMET;
   Float_t         dRAJetLept;
   Float_t         hJet_closestAJetPt[2];   //[nhJets]
   Float_t         hJet_closestAJetDR[2];   //[nhJets]
   Float_t         METnoreg_et;
   Float_t         METnoreg_sumet;
   Float_t         METnoreg_sig;
   Float_t         METnoreg_phi;
   Int_t           H_HiggsFlag;
   Float_t         H_mass;
   Float_t         H_pt;
   Float_t         H_eta;
   Float_t         H_phi;
   Float_t         H_dR;
   Float_t         H_dPhi;
   Float_t         H_dEta;
   Float_t         H_massCorr;
   Float_t         H_ptCorr;
   Float_t         V_mass;
   Float_t         V_pt;
   Float_t         V_eta;
   Float_t         V_phi;
   Float_t         hJet_pt[2];   //[nhJets]
   Float_t         hJet_e[2];   //[nhJets]
   Float_t         aJet_pt[14];   //[naJets]
   Float_t         aJet_e[14];   //[naJets]
   Float_t         hJet_ptRaw[2];   //[nhJets]
   Float_t         METtype1corr_et;
   Float_t         METtype1corr_sumet;
   Float_t         METtype1corr_sig;
   Float_t         METtype1corr_phi;
   Float_t         BDT_8TeV_H110Sig_LFHFWjetsNewTTbarVVBkg_newCuts4;
   Float_t         BDT_8TeV_H115Sig_LFHFWjetsNewTTbarVVBkg_newCuts4;
   Float_t         BDT_8TeV_H120Sig_LFHFWjetsNewTTbarVVBkg_newCuts4;
   Float_t         BDT_8TeV_H125Sig_0b1b2bWjetsBkg_newCuts4;
   Float_t         BDT_8TeV_H125Sig_LFHFWjetsNewTTbarVVBkg_newCuts4;
   Float_t         BDT_8TeV_H125Sig_NewTTbarBkg_newCuts4;
   Float_t         BDT_8TeV_H125Sig_VVBkg_newCuts4;
   Float_t         BDT_8TeV_H130Sig_LFHFWjetsNewTTbarVVBkg_newCuts4;
   Float_t         BDT_8TeV_H135Sig_LFHFWjetsNewTTbarVVBkg_newCuts4;
   Float_t         BDT_8TeV_H140Sig_LFHFWjetsNewTTbarVVBkg_newCuts;
   Float_t         BDT_8TeV_H145Sig_LFHFWjetsNewTTbarVVBkg_newCuts;
   Float_t         BDT_8TeV_H150Sig_LFHFWjetsNewTTbarVVBkg_newCuts;
   Float_t         BDT_8TeV_VVSig_0b1b2bWjetsBkg_newCuts4;
   Float_t         BDT_8TeV_VVSig_0b1b2bWjetsNewTTbarBkg_newCuts4;
   Float_t         BDT_8TeV_VVSig_NewTTbarBkg_newCuts4;

   TBranch *b_x_costheta1;
   TBranch *b_x_costheta2;
   TBranch *b_x_phi;
   TBranch *b_x_costhetastar;
   TBranch *b_x_phi1;
   TBranch *b_x_phi2;
   TBranch *b_x_mVH;
   TBranch *b_x_rapidityVH;

   TBranch *b_MELA_SM;
   TBranch *b_MELA_PS;
   TBranch *b_MELA_HO;
   
   TBranch *b_lMETdPhi;

   TBranch *b_weightWpt_WJets;
   TBranch *b_weightWpt_TTbar;

   TBranch *b_weightEleTrigger;

   // List of branches
   TBranch        *b_lheV_pt;   //!
   TBranch        *b_lheHT;   //!
   TBranch        *b_lheNj;   //!
   TBranch        *b_nPdf;   //!
   TBranch        *b_PDFweight;   //!
   TBranch        *b_genZ;   //!
   TBranch        *b_genW;   //!
   TBranch        *b_genWstar;   //!
   TBranch        *b_genH;   //!
   TBranch        *b_nhJets;   //!
   TBranch        *b_naJets;   //!
   TBranch        *b_weightMCProd;   //!
   TBranch        *b_hJet_eta;   //!
   TBranch        *b_hJet_phi;   //!
   TBranch        *b_hJet_csv;   //!
   TBranch        *b_hJet_csv_nominal;   //!
   TBranch        *b_hJet_csv_upBC;   //!
   TBranch        *b_hJet_csv_downBC;   //!
   TBranch        *b_hJet_csv_upL;   //!
   TBranch        *b_hJet_csv_downL;   //!
   TBranch        *b_hJet_csv_nominal4p;   //!
   TBranch        *b_hJet_csv_upBC4p;   //!
   TBranch        *b_hJet_csv_downBC4p;   //!
   TBranch        *b_hJet_csv_nominal1Bin;   //!
   TBranch        *b_hJet_csvivf;   //!
   TBranch        *b_hJet_cmva;   //!
   TBranch        *b_hJet_cosTheta;   //!
   TBranch        *b_hJet_numTracksSV;   //!
   TBranch        *b_hJet_chf;   //!
   TBranch        *b_hJet_nhf;   //!
   TBranch        *b_hJet_cef;   //!
   TBranch        *b_hJet_nef;   //!
   TBranch        *b_hJet_nch;   //!
   TBranch        *b_hJet_nconstituents;   //!
   TBranch        *b_hJet_flavour;   //!
   TBranch        *b_hJet_isSemiLept;   //!
   TBranch        *b_hJet_isSemiLeptMCtruth;   //!
   TBranch        *b_hJet_SoftLeptpdgId;   //!
   TBranch        *b_hJet_SoftLeptIdlooseMu;   //!
   TBranch        *b_hJet_SoftLeptId95;   //!
   TBranch        *b_hJet_SoftLeptPt;   //!
   TBranch        *b_hJet_SoftLeptdR;   //!
   TBranch        *b_hJet_SoftLeptptRel;   //!
   TBranch        *b_hJet_SoftLeptRelCombIso;   //!
   TBranch        *b_hJet_genPt;   //!
   TBranch        *b_hJet_genEta;   //!
   TBranch        *b_hJet_genPhi;   //!
   TBranch        *b_hJet_JECUnc;   //!
   TBranch        *b_hJet_vtxMass;   //!
   TBranch        *b_hJet_vtxPt;   //!
   TBranch        *b_hJet_vtxEta;   //!
   TBranch        *b_hJet_vtxPhi;   //!
   TBranch        *b_hJet_vtxE;   //!
   TBranch        *b_hJet_vtx3dL;   //!
   TBranch        *b_hJet_vtx3deL;   //!
   TBranch        *b_hJet_id;   //!
   TBranch        *b_hJet_SF_CSVL;   //!
   TBranch        *b_hJet_SF_CSVM;   //!
   TBranch        *b_hJet_SF_CSVT;   //!
   TBranch        *b_hJet_SF_CSVLerr;   //!
   TBranch        *b_hJet_SF_CSVMerr;   //!
   TBranch        *b_hJet_SF_CSVTerr;   //!
   TBranch        *b_hJet_ptLeadTrack;   //!
   TBranch        *b_hJet_puJetIdL;   //!
   TBranch        *b_hJet_puJetIdM;   //!
   TBranch        *b_hJet_puJetIdT;   //!
   TBranch        *b_hJet_puJetIdMva;   //!
   TBranch        *b_hJet_charge;   //!
   TBranch        *b_aJet_eta;   //!
   TBranch        *b_aJet_phi;   //!
   TBranch        *b_aJet_csv;   //!
   TBranch        *b_aJet_csv_nominal;   //!
   TBranch        *b_aJet_csv_upBC;   //!
   TBranch        *b_aJet_csv_downBC;   //!
   TBranch        *b_aJet_csv_upL;   //!
   TBranch        *b_aJet_csv_downL;   //!
   TBranch        *b_aJet_csv_nominal4p;   //!
   TBranch        *b_aJet_csv_upBC4p;   //!
   TBranch        *b_aJet_csv_downBC4p;   //!
   TBranch        *b_aJet_csv_nominal1Bin;   //!
   TBranch        *b_aJet_csvivf;   //!
   TBranch        *b_aJet_cmva;   //!
   TBranch        *b_aJet_cosTheta;   //!
   TBranch        *b_aJet_numTracksSV;   //!
   TBranch        *b_aJet_chf;   //!
   TBranch        *b_aJet_nhf;   //!
   TBranch        *b_aJet_cef;   //!
   TBranch        *b_aJet_nef;   //!
   TBranch        *b_aJet_nch;   //!
   TBranch        *b_aJet_nconstituents;   //!
   TBranch        *b_aJet_flavour;   //!
   TBranch        *b_aJet_isSemiLept;   //!
   TBranch        *b_aJet_isSemiLeptMCtruth;   //!
   TBranch        *b_aJet_SoftLeptpdgId;   //!
   TBranch        *b_aJet_SoftLeptIdlooseMu;   //!
   TBranch        *b_aJet_SoftLeptId95;   //!
   TBranch        *b_aJet_SoftLeptPt;   //!
   TBranch        *b_aJet_SoftLeptdR;   //!
   TBranch        *b_aJet_SoftLeptptRel;   //!
   TBranch        *b_aJet_SoftLeptRelCombIso;   //!
   TBranch        *b_aJet_puJetIdL;   //!
   TBranch        *b_aJet_puJetIdM;   //!
   TBranch        *b_aJet_puJetIdT;   //!
   TBranch        *b_aJet_puJetIdMva;   //!
   TBranch        *b_aJet_charge;   //!
   TBranch        *b_aJet_genPt;   //!
   TBranch        *b_aJet_genEta;   //!
   TBranch        *b_aJet_genPhi;   //!
   TBranch        *b_aJet_JECUnc;   //!
   TBranch        *b_aJet_vtxMass;   //!
   TBranch        *b_aJet_vtx3dL;   //!
   TBranch        *b_aJet_vtx3deL;   //!
   TBranch        *b_aJet_id;   //!
   TBranch        *b_aJet_SF_CSVL;   //!
   TBranch        *b_aJet_SF_CSVM;   //!
   TBranch        *b_aJet_SF_CSVT;   //!
   TBranch        *b_aJet_SF_CSVLerr;   //!
   TBranch        *b_aJet_SF_CSVMerr;   //!
   TBranch        *b_aJet_SF_CSVTerr;   //!
   TBranch        *b_deltaPullAngle;   //!
   TBranch        *b_weightSignalEWK;   //!
   TBranch        *b_weightSignalQCD;   //!
   TBranch        *b_weightTrig;   //!
   TBranch        *b_weightTrigMay;   //!
   TBranch        *b_weightTrigV4;   //!
   TBranch        *b_weightTrigMET;   //!
   TBranch        *b_weightTrigOrMu30;   //!
   TBranch        *b_weightEleRecoAndId;   //!
   TBranch        *b_weightEleTrigJetMETPart;   //!
   TBranch        *b_weightEleTrigElePart;   //!
   TBranch        *b_weightEleTrigEleAugPart;   //!
   TBranch        *b_weightTrigMET80;   //!
   TBranch        *b_weightTrigMET100;   //!
   TBranch        *b_weightTrig2CJet20;   //!
   TBranch        *b_weightTrigMET150;   //!
   TBranch        *b_weightTrigMET802CJet;   //!
   TBranch        *b_weightTrigMET1002CJet;   //!
   TBranch        *b_weightTrigMETLP;   //!
   TBranch        *b_weightTrig2012A;   //!
   TBranch        *b_weightTrig2012ADiMuon;   //!
   TBranch        *b_weightTrig2012ADiEle;   //!
   TBranch        *b_weightTrig2012ASingleMuon;   //!
   TBranch        *b_weightTrig2012ASingleEle;   //!
   TBranch        *b_weightTrig2012AMuonPlusWCandPt;   //!
   TBranch        *b_weightTrig2012;   //!
   TBranch        *b_weightTrig2012DiMuon;   //!
   TBranch        *b_weightTrig2012DiEle;   //!
   TBranch        *b_weightTrig2012SingleMuon;   //!
   TBranch        *b_weightTrig2012SingleEle;   //!
   TBranch        *b_weightTrig2012MuonPlusWCandPt;   //!
   TBranch        *b_weightTrig2012AB;   //!
   TBranch        *b_weightTrig2012ABDiMuon;   //!
   TBranch        *b_weightTrig2012ABDiEle;   //!
   TBranch        *b_weightTrig2012ABSingleMuon;   //!
   TBranch        *b_weightTrig2012ABSingleEle;   //!
   TBranch        *b_weightTrig2012ABMuonPlusWCandPt;   //!
   TBranch        *b_weightTrig2012DiJet30MHT80;   //!
   TBranch        *b_weightTrig2012PFMET150;   //!
   TBranch        *b_weightTrig2012SumpT100MET100;   //!
   TBranch        *b_weightTrig2012APFMET150orDiJetMET;   //!
   TBranch        *b_weightTrig2012BPFMET150orDiJetMET;   //!
   TBranch        *b_weightTrig2012CPFMET150orDiJetMET;   //!
   TBranch        *b_PUweight;   //!
   TBranch        *b_PUweightP;   //!
   TBranch        *b_PUweightM;   //!
   TBranch        *b_PUweightAB;   //!
   TBranch        *b_PUweight2011B;   //!
   TBranch        *b_PUweight1DObs;   //!
   TBranch        *b_eventFlav;   //!
   TBranch        *b_Vtype;   //!
   TBranch        *b_HVdPhi;   //!
   TBranch        *b_nvlep;   //!
   TBranch        *b_nalep;   //!
   TBranch        *b_vLepton_mass;   //!
   TBranch        *b_vLepton_pt;   //!
   TBranch        *b_vLepton_eta;   //!
   TBranch        *b_vLepton_phi;   //!
   TBranch        *b_vLepton_aodCombRelIso;   //!
   TBranch        *b_vLepton_pfCombRelIso;   //!
   TBranch        *b_vLepton_photonIso;   //!
   TBranch        *b_vLepton_neutralHadIso;   //!
   TBranch        *b_vLepton_chargedHadIso;   //!
   TBranch        *b_vLepton_chargedPUIso;   //!
   TBranch        *b_vLepton_particleIso;   //!
   TBranch        *b_vLepton_dxy;   //!
   TBranch        *b_vLepton_dz;   //!
   TBranch        *b_vLepton_type;   //!
   TBranch        *b_vLepton_id80;   //!
   TBranch        *b_vLepton_id95;   //!
   TBranch        *b_vLepton_vbtf;   //!
   TBranch        *b_vLepton_id80NoIso;   //!
   TBranch        *b_vLepton_genPt;   //!
   TBranch        *b_vLepton_genEta;   //!
   TBranch        *b_vLepton_genPhi;   //!
   TBranch        *b_vLepton_charge;   //!
   TBranch        *b_vLepton_pfCorrIso;   //!
   TBranch        *b_vLepton_pfCorrIsoHCP;   //!
   TBranch        *b_vLepton_id2012tight;   //!
   TBranch        *b_vLepton_idMVAnotrig;   //!
   TBranch        *b_vLepton_idMVAtrig;   //!
   TBranch        *b_vLepton_idMVApresel;   //!
   TBranch        *b_vLepton_innerHits;   //!
   TBranch        *b_vLepton_photonIsoDoubleCount;   //!
   TBranch        *b_vLepton_wpHWW;   //!
   TBranch        *b_vLepton_wp95;   //!
   TBranch        *b_vLepton_wp90;   //!
   TBranch        *b_vLepton_wp85;   //!
   TBranch        *b_vLepton_wp80;   //!
   TBranch        *b_vLepton_wp70;   //!
   TBranch        *b_aJet_selectedTauDR;   //!
   TBranch        *b_aLepton_mass;   //!
   TBranch        *b_aLepton_pt;   //!
   TBranch        *b_aLepton_eta;   //!
   TBranch        *b_aLepton_phi;   //!
   TBranch        *b_aLepton_aodCombRelIso;   //!
   TBranch        *b_aLepton_pfCombRelIso;   //!
   TBranch        *b_aLepton_photonIso;   //!
   TBranch        *b_aLepton_neutralHadIso;   //!
   TBranch        *b_aLepton_chargedHadIso;   //!
   TBranch        *b_aLepton_chargedPUIso;   //!
   TBranch        *b_aLepton_particleIso;   //!
   TBranch        *b_aLepton_dxy;   //!
   TBranch        *b_aLepton_dz;   //!
   TBranch        *b_aLepton_type;   //!
   TBranch        *b_aLepton_id80;   //!
   TBranch        *b_aLepton_id95;   //!
   TBranch        *b_aLepton_vbtf;   //!
   TBranch        *b_aLepton_id80NoIso;   //!
   TBranch        *b_aLepton_genPt;   //!
   TBranch        *b_aLepton_genEta;   //!
   TBranch        *b_aLepton_genPhi;   //!
   TBranch        *b_aLepton_charge;   //!
   TBranch        *b_aLepton_pfCorrIso;   //!
   TBranch        *b_aLepton_pfCorrIsoHCP;   //!
   TBranch        *b_aLepton_id2012tight;   //!
   TBranch        *b_aLepton_idMVAnotrig;   //!
   TBranch        *b_aLepton_idMVAtrig;   //!
   TBranch        *b_aLepton_idMVApresel;   //!
   TBranch        *b_aLepton_innerHits;   //!
   TBranch        *b_aLepton_photonIsoDoubleCount;   //!
   TBranch        *b_aLepton_wpHWW;   //!
   TBranch        *b_aLepton_wp95;   //!
   TBranch        *b_aLepton_wp90;   //!
   TBranch        *b_aLepton_wp85;   //!
   TBranch        *b_aLepton_wp80;   //!
   TBranch        *b_aLepton_wp70;   //!
   TBranch        *b_rho25;   //!
   TBranch        *b_nPVs;   //!
   TBranch        *b_METtype1diff;   //!
   TBranch        *b_triggerFlags;   //!
   TBranch        *b_EVENT;   //!
   TBranch        *b_hbhe;   //!
   TBranch        *b_effectiveLumi;   //!
   TBranch        *b_sampleNum;   //!
   TBranch        *b_TopM;   //!
   TBranch        *b_TopPt;   //!
   TBranch        *b_TopEta;   //!
   TBranch        *b_TopPhi;   //!
   TBranch        *b_TopEtaLepJet;   //!
   TBranch        *b_TopEtaTopJet;   //!
   TBranch        *b_TopM_regres;   //!
   TBranch        *b_TopPt_regres;   //!
   TBranch        *b_Top2M;   //!
   TBranch        *b_Top2Pt;   //!
   TBranch        *b_Top3M;   //!
   TBranch        *b_Top3Pt;   //!
   TBranch        *b_Top2M_regres;   //!
   TBranch        *b_Top2Pt_regres;   //!
   TBranch        *b_Top3M_regres;   //!
   TBranch        *b_Top3Pt_regres;   //!
   TBranch        *b_mWH;   //!
   TBranch        *b_mTWH;   //!
   TBranch        *b_pWH;   //!
   TBranch        *b_pTWH;   //!
   TBranch        *b_hJet_csvReshapedNew;   //!
   TBranch        *b_aJet_csvReshapedNew;   //!
   TBranch        *b_hJet_ptCorr;   //!
   TBranch        *b_hJet_Et;   //!
   TBranch        *b_hJet_Mt;   //!
   TBranch        *b_dPhiAJetMET;   //!
   TBranch        *b_dRAJetLept;   //!
   TBranch        *b_hJet_closestAJetPt;   //!
   TBranch        *b_hJet_closestAJetDR;   //!
   TBranch        *b_METnoreg;   //!
   TBranch        *b_H;   //!
   TBranch        *b_V;   //!
   TBranch        *b_hJet_pt;   //!
   TBranch        *b_hJet_e;   //!
   TBranch        *b_aJet_pt;   //!
   TBranch        *b_aJet_e;   //!
   TBranch        *b_hJet_ptRaw;   //!
   TBranch        *b_METtype1corr;   //!
   TBranch        *b_BDT_8TeV_H110Sig_LFHFWjetsNewTTbarVVBkg_newCuts4;   //!
   TBranch        *b_BDT_8TeV_H115Sig_LFHFWjetsNewTTbarVVBkg_newCuts4;   //!
   TBranch        *b_BDT_8TeV_H120Sig_LFHFWjetsNewTTbarVVBkg_newCuts4;   //!
   TBranch        *b_BDT_8TeV_H125Sig_0b1b2bWjetsBkg_newCuts4;   //!
   TBranch        *b_BDT_8TeV_H125Sig_LFHFWjetsNewTTbarVVBkg_newCuts4;   //!
   TBranch        *b_BDT_8TeV_H125Sig_NewTTbarBkg_newCuts4;   //!
   TBranch        *b_BDT_8TeV_H125Sig_VVBkg_newCuts4;   //!
   TBranch        *b_BDT_8TeV_H130Sig_LFHFWjetsNewTTbarVVBkg_newCuts4;   //!
   TBranch        *b_BDT_8TeV_H135Sig_LFHFWjetsNewTTbarVVBkg_newCuts4;   //!
   TBranch        *b_BDT_8TeV_H140Sig_LFHFWjetsNewTTbarVVBkg_newCuts;   //!
   TBranch        *b_BDT_8TeV_H145Sig_LFHFWjetsNewTTbarVVBkg_newCuts;   //!
   TBranch        *b_BDT_8TeV_H150Sig_LFHFWjetsNewTTbarVVBkg_newCuts;   //!
   TBranch        *b_BDT_8TeV_VVSig_0b1b2bWjetsBkg_newCuts4;   //!
   TBranch        *b_BDT_8TeV_VVSig_0b1b2bWjetsNewTTbarBkg_newCuts4;   //!
   TBranch        *b_BDT_8TeV_VVSig_NewTTbarBkg_newCuts4;   //!

   step4(TString inputFileName, TString outputFileName);
   virtual ~step4();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   
   std::pair<float,float> efficiencyFromPtEta(float pt1, float eta1, TTree *t);

};

#endif

#ifdef step4_cxx
step4::step4(TString inputFileName, TString outputFileName) : inputTree(0), inputFile(0), outputFile(0), treeEleTrigger(0), fileEleTrigger(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
  inputFile=TFile::Open(inputFileName);
  inputTree=(TTree*)inputFile->Get("tree");
  
  outputFile=new TFile(outputFileName,"RECREATE");

  KDCalc=new KDcalcPPWH(8000,125.6);

  //Stuff for electron trigger efficiency
  //fileEleTrigger=new TFile("/eos/uscms/store/user/sethzenz/fromdcache/EleRecoId.Presel.2012ABCD.root","READ");
  fileEleTrigger=new TFile("EleRecoId.Presel.2012ABCD.root","READ");
  if(fileEleTrigger->IsZombie()){
    cout << "Input file for electron trigger correction cannot be opened" << endl;
    delete fileEleTrigger;
    fileEleTrigger=0;
  }
  treeEleTrigger=(TTree*)fileEleTrigger->Get("tree");

  Init(inputTree);
}

step4::~step4()
{
   if (!inputTree) return;
   delete inputTree->GetCurrentFile();
}

Int_t step4::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!inputTree) return 0;
   return inputTree->GetEntry(entry);
}
Long64_t step4::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!inputTree) return -5;
   Long64_t centry = inputTree->LoadTree(entry);
   if (centry < 0) return centry;
   if (inputTree->GetTreeNumber() != fCurrent) {
      fCurrent = inputTree->GetTreeNumber();
      Notify();
   }
   return centry;
}

void step4::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   inputTree = tree;
   fCurrent = -1;
   inputTree->SetMakeClass(1);

   b_x_costheta1=inputTree->Branch("x_costheta1",&x_costheta1,"x_costheta1/F");
   b_x_costheta2=inputTree->Branch("x_costheta2",&x_costheta2,"x_costheta2/F");
   b_x_phi=inputTree->Branch("x_phi",&x_phi,"x_phi/F");
   b_x_costhetastar=inputTree->Branch("x_costhetastar",&x_costhetastar,"x_costhetastar/F");
   b_x_phi1=inputTree->Branch("x_phi1",&x_phi1,"x_phi1/F");
   b_x_phi2=inputTree->Branch("x_phi2",&x_phi2,"x_phi2/F");
   b_x_mVH=inputTree->Branch("x_mVH",&x_mVH,"x_mVH/F");
   b_x_rapidityVH=inputTree->Branch("x_rapidityVH",&x_rapidityVH,"x_rapidityVH/F");
   
   b_MELA_SM=inputTree->Branch("MELA_SM",&MELA_SM,"MELA_SM/F");
   b_MELA_PS=inputTree->Branch("MELA_PS",&MELA_PS,"MELA_PS/F");
   b_MELA_HO=inputTree->Branch("MELA_HO",&MELA_HO,"MELA_HO/F");

   b_lMETdPhi=inputTree->Branch("lMETdPhi",&lMETdPhi,"lMETdPhi/F");

   b_weightWpt_WJets=inputTree->Branch("weightWpt_WJets",&weightWpt_WJets,"weightWpt_WJets/F");
   b_weightWpt_TTbar=inputTree->Branch("weightWpt_TTbar",&weightWpt_TTbar,"weightWpt_TTbar/F");

   b_weightEleTrigger=inputTree->Branch("weightEleTrigger",&weightEleTrigger,"weightEleTrigger/F");

   inputTree->SetBranchAddress("lheV_pt", &lheV_pt, &b_lheV_pt);
   inputTree->SetBranchAddress("lheHT", &lheHT, &b_lheHT);
   inputTree->SetBranchAddress("lheNj", &lheNj, &b_lheNj);
   inputTree->SetBranchAddress("nPdf", &nPdf, &b_nPdf);
   inputTree->SetBranchAddress("PDFweight", PDFweight, &b_PDFweight);
   inputTree->SetBranchAddress("genZ", &genZ_mass, &b_genZ);
   inputTree->SetBranchAddress("genW", &genW_mass, &b_genW);
   inputTree->SetBranchAddress("genWstar", &genWstar_mass, &b_genWstar);
   inputTree->SetBranchAddress("genH", &genH_mass, &b_genH);
   inputTree->SetBranchAddress("nhJets", &nhJets, &b_nhJets);
   inputTree->SetBranchAddress("naJets", &naJets, &b_naJets);
   inputTree->SetBranchAddress("weightMCProd", &weightMCProd, &b_weightMCProd);
   inputTree->SetBranchAddress("hJet_eta", hJet_eta, &b_hJet_eta);
   inputTree->SetBranchAddress("hJet_phi", hJet_phi, &b_hJet_phi);
   inputTree->SetBranchAddress("hJet_csv", hJet_csv, &b_hJet_csv);
   inputTree->SetBranchAddress("hJet_csv_nominal", hJet_csv_nominal, &b_hJet_csv_nominal);
   inputTree->SetBranchAddress("hJet_csv_upBC", hJet_csv_upBC, &b_hJet_csv_upBC);
   inputTree->SetBranchAddress("hJet_csv_downBC", hJet_csv_downBC, &b_hJet_csv_downBC);
   inputTree->SetBranchAddress("hJet_csv_upL", hJet_csv_upL, &b_hJet_csv_upL);
   inputTree->SetBranchAddress("hJet_csv_downL", hJet_csv_downL, &b_hJet_csv_downL);
   inputTree->SetBranchAddress("hJet_csv_nominal4p", hJet_csv_nominal4p, &b_hJet_csv_nominal4p);
   inputTree->SetBranchAddress("hJet_csv_upBC4p", hJet_csv_upBC4p, &b_hJet_csv_upBC4p);
   inputTree->SetBranchAddress("hJet_csv_downBC4p", hJet_csv_downBC4p, &b_hJet_csv_downBC4p);
   inputTree->SetBranchAddress("hJet_csv_nominal1Bin", hJet_csv_nominal1Bin, &b_hJet_csv_nominal1Bin);
   inputTree->SetBranchAddress("hJet_csvivf", hJet_csvivf, &b_hJet_csvivf);
   inputTree->SetBranchAddress("hJet_cmva", hJet_cmva, &b_hJet_cmva);
   inputTree->SetBranchAddress("hJet_cosTheta", hJet_cosTheta, &b_hJet_cosTheta);
   inputTree->SetBranchAddress("hJet_numTracksSV", hJet_numTracksSV, &b_hJet_numTracksSV);
   inputTree->SetBranchAddress("hJet_chf", hJet_chf, &b_hJet_chf);
   inputTree->SetBranchAddress("hJet_nhf", hJet_nhf, &b_hJet_nhf);
   inputTree->SetBranchAddress("hJet_cef", hJet_cef, &b_hJet_cef);
   inputTree->SetBranchAddress("hJet_nef", hJet_nef, &b_hJet_nef);
   inputTree->SetBranchAddress("hJet_nch", hJet_nch, &b_hJet_nch);
   inputTree->SetBranchAddress("hJet_nconstituents", hJet_nconstituents, &b_hJet_nconstituents);
   inputTree->SetBranchAddress("hJet_flavour", hJet_flavour, &b_hJet_flavour);
   inputTree->SetBranchAddress("hJet_isSemiLept", hJet_isSemiLept, &b_hJet_isSemiLept);
   inputTree->SetBranchAddress("hJet_isSemiLeptMCtruth", hJet_isSemiLeptMCtruth, &b_hJet_isSemiLeptMCtruth);
   inputTree->SetBranchAddress("hJet_SoftLeptpdgId", hJet_SoftLeptpdgId, &b_hJet_SoftLeptpdgId);
   inputTree->SetBranchAddress("hJet_SoftLeptIdlooseMu", hJet_SoftLeptIdlooseMu, &b_hJet_SoftLeptIdlooseMu);
   inputTree->SetBranchAddress("hJet_SoftLeptId95", hJet_SoftLeptId95, &b_hJet_SoftLeptId95);
   inputTree->SetBranchAddress("hJet_SoftLeptPt", hJet_SoftLeptPt, &b_hJet_SoftLeptPt);
   inputTree->SetBranchAddress("hJet_SoftLeptdR", hJet_SoftLeptdR, &b_hJet_SoftLeptdR);
   inputTree->SetBranchAddress("hJet_SoftLeptptRel", hJet_SoftLeptptRel, &b_hJet_SoftLeptptRel);
   inputTree->SetBranchAddress("hJet_SoftLeptRelCombIso", hJet_SoftLeptRelCombIso, &b_hJet_SoftLeptRelCombIso);
   inputTree->SetBranchAddress("hJet_genPt", hJet_genPt, &b_hJet_genPt);
   inputTree->SetBranchAddress("hJet_genEta", hJet_genEta, &b_hJet_genEta);
   inputTree->SetBranchAddress("hJet_genPhi", hJet_genPhi, &b_hJet_genPhi);
   inputTree->SetBranchAddress("hJet_JECUnc", hJet_JECUnc, &b_hJet_JECUnc);
   inputTree->SetBranchAddress("hJet_vtxMass", hJet_vtxMass, &b_hJet_vtxMass);
   inputTree->SetBranchAddress("hJet_vtxPt", hJet_vtxPt, &b_hJet_vtxPt);
   inputTree->SetBranchAddress("hJet_vtxEta", hJet_vtxEta, &b_hJet_vtxEta);
   inputTree->SetBranchAddress("hJet_vtxPhi", hJet_vtxPhi, &b_hJet_vtxPhi);
   inputTree->SetBranchAddress("hJet_vtxE", hJet_vtxE, &b_hJet_vtxE);
   inputTree->SetBranchAddress("hJet_vtx3dL", hJet_vtx3dL, &b_hJet_vtx3dL);
   inputTree->SetBranchAddress("hJet_vtx3deL", hJet_vtx3deL, &b_hJet_vtx3deL);
   inputTree->SetBranchAddress("hJet_id", hJet_id, &b_hJet_id);
   inputTree->SetBranchAddress("hJet_SF_CSVL", hJet_SF_CSVL, &b_hJet_SF_CSVL);
   inputTree->SetBranchAddress("hJet_SF_CSVM", hJet_SF_CSVM, &b_hJet_SF_CSVM);
   inputTree->SetBranchAddress("hJet_SF_CSVT", hJet_SF_CSVT, &b_hJet_SF_CSVT);
   inputTree->SetBranchAddress("hJet_SF_CSVLerr", hJet_SF_CSVLerr, &b_hJet_SF_CSVLerr);
   inputTree->SetBranchAddress("hJet_SF_CSVMerr", hJet_SF_CSVMerr, &b_hJet_SF_CSVMerr);
   inputTree->SetBranchAddress("hJet_SF_CSVTerr", hJet_SF_CSVTerr, &b_hJet_SF_CSVTerr);
   inputTree->SetBranchAddress("hJet_ptLeadTrack", hJet_ptLeadTrack, &b_hJet_ptLeadTrack);
   inputTree->SetBranchAddress("hJet_puJetIdL", hJet_puJetIdL, &b_hJet_puJetIdL);
   inputTree->SetBranchAddress("hJet_puJetIdM", hJet_puJetIdM, &b_hJet_puJetIdM);
   inputTree->SetBranchAddress("hJet_puJetIdT", hJet_puJetIdT, &b_hJet_puJetIdT);
   inputTree->SetBranchAddress("hJet_puJetIdMva", hJet_puJetIdMva, &b_hJet_puJetIdMva);
   inputTree->SetBranchAddress("hJet_charge", hJet_charge, &b_hJet_charge);
   inputTree->SetBranchAddress("aJet_eta", aJet_eta, &b_aJet_eta);
   inputTree->SetBranchAddress("aJet_phi", aJet_phi, &b_aJet_phi);
   inputTree->SetBranchAddress("aJet_csv", aJet_csv, &b_aJet_csv);
   inputTree->SetBranchAddress("aJet_csv_nominal", aJet_csv_nominal, &b_aJet_csv_nominal);
   inputTree->SetBranchAddress("aJet_csv_upBC", aJet_csv_upBC, &b_aJet_csv_upBC);
   inputTree->SetBranchAddress("aJet_csv_downBC", aJet_csv_downBC, &b_aJet_csv_downBC);
   inputTree->SetBranchAddress("aJet_csv_upL", aJet_csv_upL, &b_aJet_csv_upL);
   inputTree->SetBranchAddress("aJet_csv_downL", aJet_csv_downL, &b_aJet_csv_downL);
   inputTree->SetBranchAddress("aJet_csv_nominal4p", aJet_csv_nominal4p, &b_aJet_csv_nominal4p);
   inputTree->SetBranchAddress("aJet_csv_upBC4p", aJet_csv_upBC4p, &b_aJet_csv_upBC4p);
   inputTree->SetBranchAddress("aJet_csv_downBC4p", aJet_csv_downBC4p, &b_aJet_csv_downBC4p);
   inputTree->SetBranchAddress("aJet_csv_nominal1Bin", aJet_csv_nominal1Bin, &b_aJet_csv_nominal1Bin);
   inputTree->SetBranchAddress("aJet_csvivf", aJet_csvivf, &b_aJet_csvivf);
   inputTree->SetBranchAddress("aJet_cmva", aJet_cmva, &b_aJet_cmva);
   inputTree->SetBranchAddress("aJet_cosTheta", aJet_cosTheta, &b_aJet_cosTheta);
   inputTree->SetBranchAddress("aJet_numTracksSV", aJet_numTracksSV, &b_aJet_numTracksSV);
   inputTree->SetBranchAddress("aJet_chf", aJet_chf, &b_aJet_chf);
   inputTree->SetBranchAddress("aJet_nhf", aJet_nhf, &b_aJet_nhf);
   inputTree->SetBranchAddress("aJet_cef", aJet_cef, &b_aJet_cef);
   inputTree->SetBranchAddress("aJet_nef", aJet_nef, &b_aJet_nef);
   inputTree->SetBranchAddress("aJet_nch", aJet_nch, &b_aJet_nch);
   inputTree->SetBranchAddress("aJet_nconstituents", aJet_nconstituents, &b_aJet_nconstituents);
   inputTree->SetBranchAddress("aJet_flavour", aJet_flavour, &b_aJet_flavour);
   inputTree->SetBranchAddress("aJet_isSemiLept", aJet_isSemiLept, &b_aJet_isSemiLept);
   inputTree->SetBranchAddress("aJet_isSemiLeptMCtruth", aJet_isSemiLeptMCtruth, &b_aJet_isSemiLeptMCtruth);
   inputTree->SetBranchAddress("aJet_SoftLeptpdgId", aJet_SoftLeptpdgId, &b_aJet_SoftLeptpdgId);
   inputTree->SetBranchAddress("aJet_SoftLeptIdlooseMu", aJet_SoftLeptIdlooseMu, &b_aJet_SoftLeptIdlooseMu);
   inputTree->SetBranchAddress("aJet_SoftLeptId95", aJet_SoftLeptId95, &b_aJet_SoftLeptId95);
   inputTree->SetBranchAddress("aJet_SoftLeptPt", aJet_SoftLeptPt, &b_aJet_SoftLeptPt);
   inputTree->SetBranchAddress("aJet_SoftLeptdR", aJet_SoftLeptdR, &b_aJet_SoftLeptdR);
   inputTree->SetBranchAddress("aJet_SoftLeptptRel", aJet_SoftLeptptRel, &b_aJet_SoftLeptptRel);
   inputTree->SetBranchAddress("aJet_SoftLeptRelCombIso", aJet_SoftLeptRelCombIso, &b_aJet_SoftLeptRelCombIso);
   inputTree->SetBranchAddress("aJet_puJetIdL", aJet_puJetIdL, &b_aJet_puJetIdL);
   inputTree->SetBranchAddress("aJet_puJetIdM", aJet_puJetIdM, &b_aJet_puJetIdM);
   inputTree->SetBranchAddress("aJet_puJetIdT", aJet_puJetIdT, &b_aJet_puJetIdT);
   inputTree->SetBranchAddress("aJet_puJetIdMva", aJet_puJetIdMva, &b_aJet_puJetIdMva);
   inputTree->SetBranchAddress("aJet_charge", aJet_charge, &b_aJet_charge);
   inputTree->SetBranchAddress("aJet_genPt", aJet_genPt, &b_aJet_genPt);
   inputTree->SetBranchAddress("aJet_genEta", aJet_genEta, &b_aJet_genEta);
   inputTree->SetBranchAddress("aJet_genPhi", aJet_genPhi, &b_aJet_genPhi);
   inputTree->SetBranchAddress("aJet_JECUnc", aJet_JECUnc, &b_aJet_JECUnc);
   inputTree->SetBranchAddress("aJet_vtxMass", aJet_vtxMass, &b_aJet_vtxMass);
   inputTree->SetBranchAddress("aJet_vtx3dL", aJet_vtx3dL, &b_aJet_vtx3dL);
   inputTree->SetBranchAddress("aJet_vtx3deL", aJet_vtx3deL, &b_aJet_vtx3deL);
   inputTree->SetBranchAddress("aJet_id", aJet_id, &b_aJet_id);
   inputTree->SetBranchAddress("aJet_SF_CSVL", aJet_SF_CSVL, &b_aJet_SF_CSVL);
   inputTree->SetBranchAddress("aJet_SF_CSVM", aJet_SF_CSVM, &b_aJet_SF_CSVM);
   inputTree->SetBranchAddress("aJet_SF_CSVT", aJet_SF_CSVT, &b_aJet_SF_CSVT);
   inputTree->SetBranchAddress("aJet_SF_CSVLerr", aJet_SF_CSVLerr, &b_aJet_SF_CSVLerr);
   inputTree->SetBranchAddress("aJet_SF_CSVMerr", aJet_SF_CSVMerr, &b_aJet_SF_CSVMerr);
   inputTree->SetBranchAddress("aJet_SF_CSVTerr", aJet_SF_CSVTerr, &b_aJet_SF_CSVTerr);
   inputTree->SetBranchAddress("deltaPullAngle", &deltaPullAngle, &b_deltaPullAngle);
   inputTree->SetBranchAddress("weightSignalEWK", &weightSignalEWK, &b_weightSignalEWK);
   inputTree->SetBranchAddress("weightSignalQCD", &weightSignalQCD, &b_weightSignalQCD);
   inputTree->SetBranchAddress("weightTrig", &weightTrig, &b_weightTrig);
   inputTree->SetBranchAddress("weightTrigMay", &weightTrigMay, &b_weightTrigMay);
   inputTree->SetBranchAddress("weightTrigV4", &weightTrigV4, &b_weightTrigV4);
   inputTree->SetBranchAddress("weightTrigMET", &weightTrigMET, &b_weightTrigMET);
   inputTree->SetBranchAddress("weightTrigOrMu30", &weightTrigOrMu30, &b_weightTrigOrMu30);
   inputTree->SetBranchAddress("weightEleRecoAndId", &weightEleRecoAndId, &b_weightEleRecoAndId);
   inputTree->SetBranchAddress("weightEleTrigJetMETPart", &weightEleTrigJetMETPart, &b_weightEleTrigJetMETPart);
   inputTree->SetBranchAddress("weightEleTrigElePart", &weightEleTrigElePart, &b_weightEleTrigElePart);
   inputTree->SetBranchAddress("weightEleTrigEleAugPart", &weightEleTrigEleAugPart, &b_weightEleTrigEleAugPart);
   inputTree->SetBranchAddress("weightTrigMET80", &weightTrigMET80, &b_weightTrigMET80);
   inputTree->SetBranchAddress("weightTrigMET100", &weightTrigMET100, &b_weightTrigMET100);
   inputTree->SetBranchAddress("weightTrig2CJet20", &weightTrig2CJet20, &b_weightTrig2CJet20);
   inputTree->SetBranchAddress("weightTrigMET150", &weightTrigMET150, &b_weightTrigMET150);
   inputTree->SetBranchAddress("weightTrigMET802CJet", &weightTrigMET802CJet, &b_weightTrigMET802CJet);
   inputTree->SetBranchAddress("weightTrigMET1002CJet", &weightTrigMET1002CJet, &b_weightTrigMET1002CJet);
   inputTree->SetBranchAddress("weightTrigMETLP", &weightTrigMETLP, &b_weightTrigMETLP);
   inputTree->SetBranchAddress("weightTrig2012A", &weightTrig2012A, &b_weightTrig2012A);
   inputTree->SetBranchAddress("weightTrig2012ADiMuon", &weightTrig2012ADiMuon, &b_weightTrig2012ADiMuon);
   inputTree->SetBranchAddress("weightTrig2012ADiEle", &weightTrig2012ADiEle, &b_weightTrig2012ADiEle);
   inputTree->SetBranchAddress("weightTrig2012ASingleMuon", &weightTrig2012ASingleMuon, &b_weightTrig2012ASingleMuon);
   inputTree->SetBranchAddress("weightTrig2012ASingleEle", &weightTrig2012ASingleEle, &b_weightTrig2012ASingleEle);
   inputTree->SetBranchAddress("weightTrig2012AMuonPlusWCandPt", &weightTrig2012AMuonPlusWCandPt, &b_weightTrig2012AMuonPlusWCandPt);
   inputTree->SetBranchAddress("weightTrig2012", &weightTrig2012, &b_weightTrig2012);
   inputTree->SetBranchAddress("weightTrig2012DiMuon", &weightTrig2012DiMuon, &b_weightTrig2012DiMuon);
   inputTree->SetBranchAddress("weightTrig2012DiEle", &weightTrig2012DiEle, &b_weightTrig2012DiEle);
   inputTree->SetBranchAddress("weightTrig2012SingleMuon", &weightTrig2012SingleMuon, &b_weightTrig2012SingleMuon);
   inputTree->SetBranchAddress("weightTrig2012SingleEle", &weightTrig2012SingleEle, &b_weightTrig2012SingleEle);
   inputTree->SetBranchAddress("weightTrig2012MuonPlusWCandPt", &weightTrig2012MuonPlusWCandPt, &b_weightTrig2012MuonPlusWCandPt);
   inputTree->SetBranchAddress("weightTrig2012AB", &weightTrig2012AB, &b_weightTrig2012AB);
   inputTree->SetBranchAddress("weightTrig2012ABDiMuon", &weightTrig2012ABDiMuon, &b_weightTrig2012ABDiMuon);
   inputTree->SetBranchAddress("weightTrig2012ABDiEle", &weightTrig2012ABDiEle, &b_weightTrig2012ABDiEle);
   inputTree->SetBranchAddress("weightTrig2012ABSingleMuon", &weightTrig2012ABSingleMuon, &b_weightTrig2012ABSingleMuon);
   inputTree->SetBranchAddress("weightTrig2012ABSingleEle", &weightTrig2012ABSingleEle, &b_weightTrig2012ABSingleEle);
   inputTree->SetBranchAddress("weightTrig2012ABMuonPlusWCandPt", &weightTrig2012ABMuonPlusWCandPt, &b_weightTrig2012ABMuonPlusWCandPt);
   inputTree->SetBranchAddress("weightTrig2012DiJet30MHT80", &weightTrig2012DiJet30MHT80, &b_weightTrig2012DiJet30MHT80);
   inputTree->SetBranchAddress("weightTrig2012PFMET150", &weightTrig2012PFMET150, &b_weightTrig2012PFMET150);
   inputTree->SetBranchAddress("weightTrig2012SumpT100MET100", &weightTrig2012SumpT100MET100, &b_weightTrig2012SumpT100MET100);
   inputTree->SetBranchAddress("weightTrig2012APFMET150orDiJetMET", &weightTrig2012APFMET150orDiJetMET, &b_weightTrig2012APFMET150orDiJetMET);
   inputTree->SetBranchAddress("weightTrig2012BPFMET150orDiJetMET", &weightTrig2012BPFMET150orDiJetMET, &b_weightTrig2012BPFMET150orDiJetMET);
   inputTree->SetBranchAddress("weightTrig2012CPFMET150orDiJetMET", &weightTrig2012CPFMET150orDiJetMET, &b_weightTrig2012CPFMET150orDiJetMET);
   inputTree->SetBranchAddress("PUweight", &PUweight, &b_PUweight);
   inputTree->SetBranchAddress("PUweightP", &PUweightP, &b_PUweightP);
   inputTree->SetBranchAddress("PUweightM", &PUweightM, &b_PUweightM);
   inputTree->SetBranchAddress("PUweightAB", &PUweightAB, &b_PUweightAB);
   inputTree->SetBranchAddress("PUweight2011B", &PUweight2011B, &b_PUweight2011B);
   inputTree->SetBranchAddress("PUweight1DObs", &PUweight1DObs, &b_PUweight1DObs);
   inputTree->SetBranchAddress("eventFlav", &eventFlav, &b_eventFlav);
   inputTree->SetBranchAddress("Vtype", &Vtype, &b_Vtype);
   inputTree->SetBranchAddress("HVdPhi", &HVdPhi, &b_HVdPhi);
   inputTree->SetBranchAddress("nvlep", &nvlep, &b_nvlep);
   inputTree->SetBranchAddress("nalep", &nalep, &b_nalep);
   inputTree->SetBranchAddress("vLepton_mass", vLepton_mass, &b_vLepton_mass);
   inputTree->SetBranchAddress("vLepton_pt", vLepton_pt, &b_vLepton_pt);
   inputTree->SetBranchAddress("vLepton_eta", vLepton_eta, &b_vLepton_eta);
   inputTree->SetBranchAddress("vLepton_phi", vLepton_phi, &b_vLepton_phi);
   inputTree->SetBranchAddress("vLepton_aodCombRelIso", vLepton_aodCombRelIso, &b_vLepton_aodCombRelIso);
   inputTree->SetBranchAddress("vLepton_pfCombRelIso", vLepton_pfCombRelIso, &b_vLepton_pfCombRelIso);
   inputTree->SetBranchAddress("vLepton_photonIso", vLepton_photonIso, &b_vLepton_photonIso);
   inputTree->SetBranchAddress("vLepton_neutralHadIso", vLepton_neutralHadIso, &b_vLepton_neutralHadIso);
   inputTree->SetBranchAddress("vLepton_chargedHadIso", vLepton_chargedHadIso, &b_vLepton_chargedHadIso);
   inputTree->SetBranchAddress("vLepton_chargedPUIso", vLepton_chargedPUIso, &b_vLepton_chargedPUIso);
   inputTree->SetBranchAddress("vLepton_particleIso", vLepton_particleIso, &b_vLepton_particleIso);
   inputTree->SetBranchAddress("vLepton_dxy", vLepton_dxy, &b_vLepton_dxy);
   inputTree->SetBranchAddress("vLepton_dz", vLepton_dz, &b_vLepton_dz);
   inputTree->SetBranchAddress("vLepton_type", vLepton_type, &b_vLepton_type);
   inputTree->SetBranchAddress("vLepton_id80", vLepton_id80, &b_vLepton_id80);
   inputTree->SetBranchAddress("vLepton_id95", vLepton_id95, &b_vLepton_id95);
   inputTree->SetBranchAddress("vLepton_vbtf", vLepton_vbtf, &b_vLepton_vbtf);
   inputTree->SetBranchAddress("vLepton_id80NoIso", vLepton_id80NoIso, &b_vLepton_id80NoIso);
   inputTree->SetBranchAddress("vLepton_genPt", vLepton_genPt, &b_vLepton_genPt);
   inputTree->SetBranchAddress("vLepton_genEta", vLepton_genEta, &b_vLepton_genEta);
   inputTree->SetBranchAddress("vLepton_genPhi", vLepton_genPhi, &b_vLepton_genPhi);
   inputTree->SetBranchAddress("vLepton_charge", vLepton_charge, &b_vLepton_charge);
   inputTree->SetBranchAddress("vLepton_pfCorrIso", vLepton_pfCorrIso, &b_vLepton_pfCorrIso);
   inputTree->SetBranchAddress("vLepton_pfCorrIsoHCP", vLepton_pfCorrIsoHCP, &b_vLepton_pfCorrIsoHCP);
   inputTree->SetBranchAddress("vLepton_id2012tight", vLepton_id2012tight, &b_vLepton_id2012tight);
   inputTree->SetBranchAddress("vLepton_idMVAnotrig", vLepton_idMVAnotrig, &b_vLepton_idMVAnotrig);
   inputTree->SetBranchAddress("vLepton_idMVAtrig", vLepton_idMVAtrig, &b_vLepton_idMVAtrig);
   inputTree->SetBranchAddress("vLepton_idMVApresel", vLepton_idMVApresel, &b_vLepton_idMVApresel);
   inputTree->SetBranchAddress("vLepton_innerHits", vLepton_innerHits, &b_vLepton_innerHits);
   inputTree->SetBranchAddress("vLepton_photonIsoDoubleCount", vLepton_photonIsoDoubleCount, &b_vLepton_photonIsoDoubleCount);
   inputTree->SetBranchAddress("vLepton_wpHWW", vLepton_wpHWW, &b_vLepton_wpHWW);
   inputTree->SetBranchAddress("vLepton_wp95", vLepton_wp95, &b_vLepton_wp95);
   inputTree->SetBranchAddress("vLepton_wp90", vLepton_wp90, &b_vLepton_wp90);
   inputTree->SetBranchAddress("vLepton_wp85", vLepton_wp85, &b_vLepton_wp85);
   inputTree->SetBranchAddress("vLepton_wp80", vLepton_wp80, &b_vLepton_wp80);
   inputTree->SetBranchAddress("vLepton_wp70", vLepton_wp70, &b_vLepton_wp70);
   inputTree->SetBranchAddress("aJet_selectedTauDR", aJet_selectedTauDR, &b_aJet_selectedTauDR);
   inputTree->SetBranchAddress("aLepton_mass", aLepton_mass, &b_aLepton_mass);
   inputTree->SetBranchAddress("aLepton_pt", aLepton_pt, &b_aLepton_pt);
   inputTree->SetBranchAddress("aLepton_eta", aLepton_eta, &b_aLepton_eta);
   inputTree->SetBranchAddress("aLepton_phi", aLepton_phi, &b_aLepton_phi);
   inputTree->SetBranchAddress("aLepton_aodCombRelIso", aLepton_aodCombRelIso, &b_aLepton_aodCombRelIso);
   inputTree->SetBranchAddress("aLepton_pfCombRelIso", aLepton_pfCombRelIso, &b_aLepton_pfCombRelIso);
   inputTree->SetBranchAddress("aLepton_photonIso", aLepton_photonIso, &b_aLepton_photonIso);
   inputTree->SetBranchAddress("aLepton_neutralHadIso", aLepton_neutralHadIso, &b_aLepton_neutralHadIso);
   inputTree->SetBranchAddress("aLepton_chargedHadIso", aLepton_chargedHadIso, &b_aLepton_chargedHadIso);
   inputTree->SetBranchAddress("aLepton_chargedPUIso", aLepton_chargedPUIso, &b_aLepton_chargedPUIso);
   inputTree->SetBranchAddress("aLepton_particleIso", aLepton_particleIso, &b_aLepton_particleIso);
   inputTree->SetBranchAddress("aLepton_dxy", aLepton_dxy, &b_aLepton_dxy);
   inputTree->SetBranchAddress("aLepton_dz", aLepton_dz, &b_aLepton_dz);
   inputTree->SetBranchAddress("aLepton_type", aLepton_type, &b_aLepton_type);
   inputTree->SetBranchAddress("aLepton_id80", aLepton_id80, &b_aLepton_id80);
   inputTree->SetBranchAddress("aLepton_id95", aLepton_id95, &b_aLepton_id95);
   inputTree->SetBranchAddress("aLepton_vbtf", aLepton_vbtf, &b_aLepton_vbtf);
   inputTree->SetBranchAddress("aLepton_id80NoIso", aLepton_id80NoIso, &b_aLepton_id80NoIso);
   inputTree->SetBranchAddress("aLepton_genPt", aLepton_genPt, &b_aLepton_genPt);
   inputTree->SetBranchAddress("aLepton_genEta", aLepton_genEta, &b_aLepton_genEta);
   inputTree->SetBranchAddress("aLepton_genPhi", aLepton_genPhi, &b_aLepton_genPhi);
   inputTree->SetBranchAddress("aLepton_charge", aLepton_charge, &b_aLepton_charge);
   inputTree->SetBranchAddress("aLepton_pfCorrIso", aLepton_pfCorrIso, &b_aLepton_pfCorrIso);
   inputTree->SetBranchAddress("aLepton_pfCorrIsoHCP", aLepton_pfCorrIsoHCP, &b_aLepton_pfCorrIsoHCP);
   inputTree->SetBranchAddress("aLepton_id2012tight", aLepton_id2012tight, &b_aLepton_id2012tight);
   inputTree->SetBranchAddress("aLepton_idMVAnotrig", aLepton_idMVAnotrig, &b_aLepton_idMVAnotrig);
   inputTree->SetBranchAddress("aLepton_idMVAtrig", aLepton_idMVAtrig, &b_aLepton_idMVAtrig);
   inputTree->SetBranchAddress("aLepton_idMVApresel", aLepton_idMVApresel, &b_aLepton_idMVApresel);
   inputTree->SetBranchAddress("aLepton_innerHits", aLepton_innerHits, &b_aLepton_innerHits);
   inputTree->SetBranchAddress("aLepton_photonIsoDoubleCount", aLepton_photonIsoDoubleCount, &b_aLepton_photonIsoDoubleCount);
   inputTree->SetBranchAddress("aLepton_wpHWW", aLepton_wpHWW, &b_aLepton_wpHWW);
   inputTree->SetBranchAddress("aLepton_wp95", aLepton_wp95, &b_aLepton_wp95);
   inputTree->SetBranchAddress("aLepton_wp90", aLepton_wp90, &b_aLepton_wp90);
   inputTree->SetBranchAddress("aLepton_wp85", aLepton_wp85, &b_aLepton_wp85);
   inputTree->SetBranchAddress("aLepton_wp80", aLepton_wp80, &b_aLepton_wp80);
   inputTree->SetBranchAddress("aLepton_wp70", aLepton_wp70, &b_aLepton_wp70);
   inputTree->SetBranchAddress("rho25", &rho25, &b_rho25);
   inputTree->SetBranchAddress("nPVs", &nPVs, &b_nPVs);
   inputTree->SetBranchAddress("METtype1diff", &METtype1diff_et, &b_METtype1diff);
   inputTree->SetBranchAddress("triggerFlags", triggerFlags, &b_triggerFlags);
   inputTree->SetBranchAddress("EVENT", &EVENT_run, &b_EVENT);
   inputTree->SetBranchAddress("hbhe", &hbhe, &b_hbhe);
   inputTree->SetBranchAddress("effectiveLumi", &effectiveLumi, &b_effectiveLumi);
   inputTree->SetBranchAddress("sampleNum", &sampleNum, &b_sampleNum);
   inputTree->SetBranchAddress("TopM", &TopM, &b_TopM);
   inputTree->SetBranchAddress("TopPt", &TopPt, &b_TopPt);
   inputTree->SetBranchAddress("TopEta", &TopEta, &b_TopEta);
   inputTree->SetBranchAddress("TopPhi", &TopPhi, &b_TopPhi);
   inputTree->SetBranchAddress("TopEtaLepJet", &TopEtaLepJet, &b_TopEtaLepJet);
   inputTree->SetBranchAddress("TopEtaTopJet", &TopEtaTopJet, &b_TopEtaTopJet);
   inputTree->SetBranchAddress("TopM_regres", &TopM_regres, &b_TopM_regres);
   inputTree->SetBranchAddress("TopPt_regres", &TopPt_regres, &b_TopPt_regres);
   inputTree->SetBranchAddress("Top2M", &Top2M, &b_Top2M);
   inputTree->SetBranchAddress("Top2Pt", &Top2Pt, &b_Top2Pt);
   inputTree->SetBranchAddress("Top3M", &Top3M, &b_Top3M);
   inputTree->SetBranchAddress("Top3Pt", &Top3Pt, &b_Top3Pt);
   inputTree->SetBranchAddress("Top2M_regres", &Top2M_regres, &b_Top2M_regres);
   inputTree->SetBranchAddress("Top2Pt_regres", &Top2Pt_regres, &b_Top2Pt_regres);
   inputTree->SetBranchAddress("Top3M_regres", &Top3M_regres, &b_Top3M_regres);
   inputTree->SetBranchAddress("Top3Pt_regres", &Top3Pt_regres, &b_Top3Pt_regres);
   inputTree->SetBranchAddress("mWH", &mWH, &b_mWH);
   inputTree->SetBranchAddress("mTWH", &mTWH, &b_mTWH);
   inputTree->SetBranchAddress("pWH", &pWH, &b_pWH);
   inputTree->SetBranchAddress("pTWH", &pTWH, &b_pTWH);
   inputTree->SetBranchAddress("hJet_csvReshapedNew", hJet_csvReshapedNew, &b_hJet_csvReshapedNew);
   inputTree->SetBranchAddress("aJet_csvReshapedNew", aJet_csvReshapedNew, &b_aJet_csvReshapedNew);
   inputTree->SetBranchAddress("hJet_ptCorr", hJet_ptCorr, &b_hJet_ptCorr);
   inputTree->SetBranchAddress("hJet_Et", hJet_Et, &b_hJet_Et);
   inputTree->SetBranchAddress("hJet_Mt", hJet_Mt, &b_hJet_Mt);
   inputTree->SetBranchAddress("dPhiAJetMET", &dPhiAJetMET, &b_dPhiAJetMET);
   inputTree->SetBranchAddress("dRAJetLept", &dRAJetLept, &b_dRAJetLept);
   inputTree->SetBranchAddress("hJet_closestAJetPt", hJet_closestAJetPt, &b_hJet_closestAJetPt);
   inputTree->SetBranchAddress("hJet_closestAJetDR", hJet_closestAJetDR, &b_hJet_closestAJetDR);
   inputTree->SetBranchAddress("METnoreg", &METnoreg_et, &b_METnoreg);
   inputTree->SetBranchAddress("H", &H_HiggsFlag, &b_H);
   inputTree->SetBranchAddress("V", &V_mass, &b_V);
   inputTree->SetBranchAddress("hJet_pt", hJet_pt, &b_hJet_pt);
   inputTree->SetBranchAddress("hJet_e", hJet_e, &b_hJet_e);
   inputTree->SetBranchAddress("aJet_pt", aJet_pt, &b_aJet_pt);
   inputTree->SetBranchAddress("aJet_e", aJet_e, &b_aJet_e);
   inputTree->SetBranchAddress("hJet_ptRaw", hJet_ptRaw, &b_hJet_ptRaw);
   inputTree->SetBranchAddress("METtype1corr", &METtype1corr_et, &b_METtype1corr);
   inputTree->SetBranchAddress("BDT_8TeV_H110Sig_LFHFWjetsNewTTbarVVBkg_newCuts4", &BDT_8TeV_H110Sig_LFHFWjetsNewTTbarVVBkg_newCuts4, &b_BDT_8TeV_H110Sig_LFHFWjetsNewTTbarVVBkg_newCuts4);
   inputTree->SetBranchAddress("BDT_8TeV_H115Sig_LFHFWjetsNewTTbarVVBkg_newCuts4", &BDT_8TeV_H115Sig_LFHFWjetsNewTTbarVVBkg_newCuts4, &b_BDT_8TeV_H115Sig_LFHFWjetsNewTTbarVVBkg_newCuts4);
   inputTree->SetBranchAddress("BDT_8TeV_H120Sig_LFHFWjetsNewTTbarVVBkg_newCuts4", &BDT_8TeV_H120Sig_LFHFWjetsNewTTbarVVBkg_newCuts4, &b_BDT_8TeV_H120Sig_LFHFWjetsNewTTbarVVBkg_newCuts4);
   inputTree->SetBranchAddress("BDT_8TeV_H125Sig_0b1b2bWjetsBkg_newCuts4", &BDT_8TeV_H125Sig_0b1b2bWjetsBkg_newCuts4, &b_BDT_8TeV_H125Sig_0b1b2bWjetsBkg_newCuts4);
   inputTree->SetBranchAddress("BDT_8TeV_H125Sig_LFHFWjetsNewTTbarVVBkg_newCuts4", &BDT_8TeV_H125Sig_LFHFWjetsNewTTbarVVBkg_newCuts4, &b_BDT_8TeV_H125Sig_LFHFWjetsNewTTbarVVBkg_newCuts4);
   inputTree->SetBranchAddress("BDT_8TeV_H125Sig_NewTTbarBkg_newCuts4", &BDT_8TeV_H125Sig_NewTTbarBkg_newCuts4, &b_BDT_8TeV_H125Sig_NewTTbarBkg_newCuts4);
   inputTree->SetBranchAddress("BDT_8TeV_H125Sig_VVBkg_newCuts4", &BDT_8TeV_H125Sig_VVBkg_newCuts4, &b_BDT_8TeV_H125Sig_VVBkg_newCuts4);
   inputTree->SetBranchAddress("BDT_8TeV_H130Sig_LFHFWjetsNewTTbarVVBkg_newCuts4", &BDT_8TeV_H130Sig_LFHFWjetsNewTTbarVVBkg_newCuts4, &b_BDT_8TeV_H130Sig_LFHFWjetsNewTTbarVVBkg_newCuts4);
   inputTree->SetBranchAddress("BDT_8TeV_H135Sig_LFHFWjetsNewTTbarVVBkg_newCuts4", &BDT_8TeV_H135Sig_LFHFWjetsNewTTbarVVBkg_newCuts4, &b_BDT_8TeV_H135Sig_LFHFWjetsNewTTbarVVBkg_newCuts4);
   inputTree->SetBranchAddress("BDT_8TeV_H140Sig_LFHFWjetsNewTTbarVVBkg_newCuts", &BDT_8TeV_H140Sig_LFHFWjetsNewTTbarVVBkg_newCuts, &b_BDT_8TeV_H140Sig_LFHFWjetsNewTTbarVVBkg_newCuts);
   inputTree->SetBranchAddress("BDT_8TeV_H145Sig_LFHFWjetsNewTTbarVVBkg_newCuts", &BDT_8TeV_H145Sig_LFHFWjetsNewTTbarVVBkg_newCuts, &b_BDT_8TeV_H145Sig_LFHFWjetsNewTTbarVVBkg_newCuts);
   inputTree->SetBranchAddress("BDT_8TeV_H150Sig_LFHFWjetsNewTTbarVVBkg_newCuts", &BDT_8TeV_H150Sig_LFHFWjetsNewTTbarVVBkg_newCuts, &b_BDT_8TeV_H150Sig_LFHFWjetsNewTTbarVVBkg_newCuts);
   inputTree->SetBranchAddress("BDT_8TeV_VVSig_0b1b2bWjetsBkg_newCuts4", &BDT_8TeV_VVSig_0b1b2bWjetsBkg_newCuts4, &b_BDT_8TeV_VVSig_0b1b2bWjetsBkg_newCuts4);
   inputTree->SetBranchAddress("BDT_8TeV_VVSig_0b1b2bWjetsNewTTbarBkg_newCuts4", &BDT_8TeV_VVSig_0b1b2bWjetsNewTTbarBkg_newCuts4, &b_BDT_8TeV_VVSig_0b1b2bWjetsNewTTbarBkg_newCuts4);
   inputTree->SetBranchAddress("BDT_8TeV_VVSig_NewTTbarBkg_newCuts4", &BDT_8TeV_VVSig_NewTTbarBkg_newCuts4, &b_BDT_8TeV_VVSig_NewTTbarBkg_newCuts4);
   Notify();
}

Bool_t step4::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void step4::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!inputTree) return;
   inputTree->Show(entry);
}
Int_t step4::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns 0 otherwise.

  if( (Vtype<2 || Vtype>3) || V_pt<100 || hJet_ptCorr[1]<30 || H_ptCorr<100 || METtype1corr_et<45 (hJet_pt[0] < 0.0 || hJet_pt[1] < 0.0)) return 0;   //Valid for W->lnu only!
  //if(Vtype>3) return 0;  //Only keep Z->ell ell and W->ell nu events - 0=Zmumu, 1=Zee, 2=Wmunu, 3=Wenu
    
  return 1;
}

TLorentzVector getNeutrino(TLorentzVector chargelep, TLorentzVector met,TString lep_type, Int_t diffMode=0);//diffMode: different neutrino vz 
void computeAngles(TLorentzVector thep4H, TLorentzVector thep4Z1, TLorentzVector thep4M11, TLorentzVector thep4M12, TLorentzVector thep4Z2, TLorentzVector thep4M21, TLorentzVector thep4M22, double& costheta1, double& costheta2, double& Phi, double& costhetastar, double& Phi1, double& Phi2);

#endif // #ifdef step4_cxx

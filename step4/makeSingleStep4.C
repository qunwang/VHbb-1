makeSingleStep4(){

  TString inputFile="/eos/uscms/store/user/sethzenz/fromdcache/Ntuple_Step1V42_Step2Tag_EDMV42_Step2_V6_MC_varsAddedSummed_v19/nominal/Step2_WHiggs0P_M-125p6_8TeV-JHUGenV4-private_000_varsBDTsAdded.root";
  TString outputFile="test.root";

  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");
  gSystem->AddIncludePath("-I$ROOFITSYS/include/");

  gROOT->LoadMacro("RooSpinZero_3D_WH_pp.cc+");
  gROOT->LoadMacro("ScalarPdfFactoryPPWH.cc+");
  gROOT->LoadMacro("KDcalcPPWH.cc+");

  gROOT->LoadMacro("METzCalculator.cc+");
  gROOT->LoadMacro("step4.cc+");
  step4 t(inputFile,outputFile);
  t.Loop();
}

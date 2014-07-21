makeSingleStep3p5(){

  TString inputFile="/eos/uscms/store/user/sethzenz/fromdcache/Ntuple_Step1V42_Step2Tag_EDMV42_Step2_V6_MC_varsAddedSummed_v19/JER_down/WHiggs0P_M-125p6_lumiWeighted/Step2_WHiggs0P_M-125p6_8TeV-JHUGenV4-private_000_varsBDTsAdded.root";
  TString inputFileNom="/eos/uscms/store/user/sethzenz/fromdcache/Ntuple_Step1V42_Step2Tag_EDMV42_Step2_V6_MC_varsAddedSummed_v19/nominal/Step2_WHiggs0P_M-125p6_8TeV-JHUGenV4-private_000_varsBDTsAdded.root";
  TString outputFile="/eos/uscms/store/user/lpcmbja/noreplica/ssagir/step3p5/JER_down/WHiggs0P_M-125p6_lumiWeighted/Step2_WHiggs0P_M-125p6_8TeV-JHUGenV4-private_000_varsBDTsAdded.root";

  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");
  gSystem->AddIncludePath("-I$ROOFITSYS/include/");

  gROOT->LoadMacro("step3p5.cc+");
  step3p5 t(inputFile,inputFileNom,outputFile);
  t.Loop();
}

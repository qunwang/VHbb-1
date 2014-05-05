makeStep4(TString macroDir, TString inputFile, TString outputFile){

  gROOT->SetMacroPath(macroDir);

  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");
  gSystem->AddIncludePath("-I$ROOFITSYS/include/");

  TString incl("-I");
  incl+=macroDir;
  gSystem->AddIncludePath(incl);

  gROOT->LoadMacro("RooSpinZero_3D_WH_pp.cc+");
  gROOT->LoadMacro("ScalarPdfFactoryPPWH.cc+");
  gROOT->LoadMacro("KDcalcPPWH.cc+");

  gROOT->LoadMacro("METzCalculator.cc+");
  gROOT->LoadMacro("step4.cc+");
  step4 t(inputFile,outputFile);
  t.Loop();
}

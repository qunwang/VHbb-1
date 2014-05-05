{
  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");
  gSystem->AddIncludePath("-I$ROOFITSYS/include/");

  gROOT->LoadMacro("RooSpinZero_3D_WH_pp.cc+");
  gROOT->LoadMacro("ScalarPdfFactoryPPWH.cc+");
  gROOT->LoadMacro("KDcalcPPWH.cc+");

  gROOT->LoadMacro("METzCalculator.cc+");
  gROOT->LoadMacro("step4.cc+");
}

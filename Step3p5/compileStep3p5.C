{
  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");
  gSystem->AddIncludePath("-I$ROOFITSYS/include/");

  gROOT->LoadMacro("step3p5.cc+");
}
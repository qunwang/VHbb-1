makeStep4(TString inputFile, TString outputFile){

  gROOT->LoadMacro("METzCalculator.cc+");
  gROOT->LoadMacro("step4.cc+");
  step4 t(inputFile,outputFile);
  t.Loop();
}

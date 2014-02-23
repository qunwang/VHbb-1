makeStep4(TString inputFile, TString outputFile){

  gROOT->LoadMacro("METzCalculator.cc+");
  gROOT->LoadMacro("makeStep4.cc+");
  makeStep4 t(inputFile,outputFile);
  t.Loop();
}

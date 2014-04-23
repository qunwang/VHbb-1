makeStep4(TString macroDir, TString inputFile, TString outputFile){

  gROOT->SetMacroPath(macroDir);
  gROOT->LoadMacro("METzCalculator.cc+");
  gROOT->LoadMacro("step4.cc+");
  step4 t(inputFile,outputFile);
  t.Loop();
}

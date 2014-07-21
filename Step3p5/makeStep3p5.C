makeStep3p5(TString macroDir, TString inputFile, TString inputFileNom, TString outputFile){

  gROOT->SetMacroPath(macroDir);
  
  gSystem->AddIncludePath("-I$CMSSW_BASE/src/");
  gSystem->AddIncludePath("-I$ROOFITSYS/include/");

  TString incl("-I");
  incl+=macroDir;
  gSystem->AddIncludePath(incl);

  gROOT->LoadMacro("step3p5.cc+");
  step3p5 t(inputFile,inputFileNom,outputFile);
  t.Loop();
}
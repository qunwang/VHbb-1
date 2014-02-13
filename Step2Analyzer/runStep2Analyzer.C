//void fianl_step();
#include <TH1D.h>
#include <TH2D.h>
#include <TString.h>
#include <TROOT.h>
#include <iostream>
#include <TGraph.h>
#include <TMath.h>
#include <map>
#include "fstream"
#include <TLegend.h>


void runStep2Analyzer() {
	gROOT->LoadMacro("Step2Analyzer.C+");
	gROOT->LoadMacro("tdrstyle.C");
	setTDRStyle(); //plotting style

	runStep2Analyzer_signle("Step2_WHiggs0P_M-125p6_8TeV-JHUGenV4-private");
}

void runStep2Analyzer_signle( TString samplename) 
{

	// mkdir plots fold accoding time
	TString dir = gSystem->UnixPathName(gInterpreter->GetCurrentMacroName());
	dir.ReplaceAll("runMyClass.C","");
	dir.ReplaceAll("/./","/");
	TDatime dt;

	char* plot_Dir_DateTime=Form("%sPlots/%i_%i_%i/%s_%i",dir.Data(), dt.GetYear(), dt.GetMonth(), dt.GetDay(), samplename.Data(), dt.GetTime());
	cout<<plot_Dir_DateTime<<endl;
	gSystem->mkdir(plot_Dir_DateTime, 1);

	TFile *file1=new TFile(samplename+".root");
	TTree *tree1=(TTree*) file1->Get("tree");
	if(tree1){

	Step2Analyzer* analyzor = new Step2Analyzer(tree1, plot_Dir_DateTime);
	analyzor->Loop();

	}else{
		cout<<"Error! Coundn't find a tree!!!"<<endl;
	}

}

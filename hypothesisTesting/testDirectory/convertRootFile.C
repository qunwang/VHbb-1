#include <iostream>

#include "TFile.h"
#include "TH1F.h"
#include "TString.h"
#include "TList.h"
#include "TKey.h"
#include "TObject.h"

void makeNew(TFile * myFile, TString oldname, TString newname) {
  
  myFile->cd();
  TH1F* h1 = (TH1F*)myFile->Get(oldname);
  TH1F* h2 = (TH1F*)h1->Clone(newname);
  //cout << oldname << " " << h1->Integral() << endl;
  h2->Write();

}

void convertRootFile(TString sigName = "Wh_125p6_0P", TString sigAltName = "Wh_125p6_0M") {

  TFile * myFile = new TFile("plots.root", "update");
  cout << "Changing file " << myFile << endl;
  cout << sigName << " is sig, and " << sigAltName << " is sig_ALT" << endl;
  cout << endl;

  TList * list = myFile->GetListOfKeys();
  for (int i = 0; i < list->GetSize(); i++) {
    TKey *key = dynamic_cast<TKey*>(list->At(i));
    TObject* obj = key->ReadObj();

    TString oldName = obj->GetName(); 
    TString newName = oldName;
    
    if( oldName.Contains(sigName) ) {
      newName.ReplaceAll(sigName,"sig");
      cout << oldName << " " << newName << endl;
      makeNew(myFile, oldName, newName);
    }
    else if( oldName.Contains(sigAltName) ) {
      newName.ReplaceAll(sigAltName,"sig_ALT");
      cout << oldName << " " << newName << endl;
      makeNew(myFile, oldName, newName);
    }
        
  }//end loop over keys

  myFile->Close();

}


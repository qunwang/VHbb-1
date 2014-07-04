// -*- C++ -*-
//
// Package:    VHbb/HbbProducer
// Class:      HbbProducer
// 
/**\class HbbProducer HbbProducer.cc VHbb/HbbProducer/plugins/HbbProducer.cc

   Description: [one line class summary]

   Implementation:
   [Notes on implementation]
*/
//
// Original Author:  john stupak
//         Created:  Fri, 27 Jun 2014 22:16:05 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "VHbb/HbbProducer/interface/HbbTuple.h"

#include <DataFormats/PatCandidates/interface/Jet.h>

#include <vector>
#include <memory>

using namespace std;

typedef edm::Handle< edm::View< pat::Jet > > h_patJets;
typedef vector<Hbb::Jet> v_HbbJets;
//typedef auto_ptr< v_HbbJets > p_v_HbbJets;

//
// class declaration
//

class HbbProducer : public edm::EDProducer {
public:
  explicit HbbProducer(const edm::ParameterSet&);
  ~HbbProducer();

  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

private:
  virtual void beginJob() override;
  virtual void produce(edm::Event&, const edm::EventSetup&) override;
  virtual void endJob() override;
  
  //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
  //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
  //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
  //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
  
  edm::InputTag _rhoSource;
  edm::InputTag _AK4Source, _AK8Source, _AK10Source, _AK12Source, _AK15Source;
  
  Hbb::Tuple _output;
  
  
  // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//


//
// static data member definitions
//

//
// constructors and destructor
//
HbbProducer::HbbProducer(const edm::ParameterSet& iConfig)
{
  
  _rhoSource=edm::InputTag(iConfig.getParameter<edm::InputTag>("rhoSource"));
  _AK4Source=edm::InputTag(iConfig.getParameter<edm::InputTag>("AK4Source"));
  _AK8Source=edm::InputTag(iConfig.getParameter<edm::InputTag>("AK8Source"));
  _AK10Source=edm::InputTag(iConfig.getParameter<edm::InputTag>("AK10Source"));
  _AK12Source=edm::InputTag(iConfig.getParameter<edm::InputTag>("AK12Source"));
  _AK15Source=edm::InputTag(iConfig.getParameter<edm::InputTag>("AK15Source"));

  //register your products
  produces<Hbb::Tuple>();
}


HbbProducer::~HbbProducer()
{
 
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to produce the data  ------------
void
HbbProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  edm::Handle<double> rho;
  iEvent.getByLabel(_rhoSource,rho);

  map< string, h_patJets > fatJetInputs=map< string, h_patJets >();
  map< string, v_HbbJets* > fatJetOutputs=map< string, v_HbbJets* >();

  h_patJets AK4jets;
  iEvent.getByLabel(_AK4Source,AK4jets);

  h_patJets AK8jets;
  iEvent.getByLabel(_AK8Source,AK8jets);
  fatJetInputs.insert(pair<string,h_patJets >(string("AK8"),AK8jets));
  fatJetOutputs.insert(pair<string, v_HbbJets* >(string("AK8"),&_output.AK8PFCHS));

  h_patJets AK10jets;
  iEvent.getByLabel(_AK10Source,AK10jets);
  fatJetInputs.insert(pair<string,h_patJets >(string("AK10"),AK10jets));
  fatJetOutputs.insert(pair<string, v_HbbJets* >(string("AK10"),&_output.AK10PFCHS));
  
  h_patJets AK12jets;
  iEvent.getByLabel(_AK12Source,AK12jets);
  fatJetInputs.insert(pair<string,h_patJets >(string("AK12"),AK12jets));
  fatJetOutputs.insert(pair<string, v_HbbJets* >(string("AK12"),&_output.AK12PFCHS));
  
  h_patJets AK15jets;
  iEvent.getByLabel(_AK15Source,AK15jets);
  fatJetInputs.insert(pair<string,h_patJets >(string("AK15"),AK15jets));
  fatJetOutputs.insert(pair<string, v_HbbJets* >(string("AK15"),&_output.AK15PFCHS));

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

  _output.rho=*rho;

  for(auto fatJetCollection=fatJetInputs.begin(); fatJetCollection!=fatJetInputs.end(); ++fatJetCollection){
    string name=fatJetCollection->first;
    h_patJets inputJets=fatJetCollection->second;

    v_HbbJets outputJets;
    for(auto inputJet=inputJets->begin(); inputJet!=inputJets->end(); ++inputJet){
      Hbb::Jet jet=Hbb::Jet();
      jet.lv.SetPtEtaPhiM(inputJet->pt(), inputJet->eta(), inputJet->phi(), inputJet->mass());

      jet.tau1=inputJet->userFloat((string("Njettiness")+string(name)+string(":tau1")).c_str());
      jet.tau2=inputJet->userFloat((string("Njettiness")+string(name)+string(":tau2")).c_str());
      jet.tau3=inputJet->userFloat((string("Njettiness")+string(name)+string(":tau3")).c_str());

      jet.prunedMass=inputJet->userFloat((string(name)+string("PFJetsCHSPrunedLinks")).c_str());
      jet.trimmedMass=inputJet->userFloat((string(name)+string("PFJetsCHSTrimmedLinks")).c_str());
      jet.filteredMass=inputJet->userFloat((string(name)+string("PFJetsCHSFilteredLinks")).c_str());

      jet.qJetsVolatility=inputJet->userFloat((string("QJetsAdder")+string(name)+string(":QjetsVolatility")).c_str());
      
      outputJets.push_back(jet);
    }
    *fatJetOutputs[name]=outputJets;
  }
  
  auto_ptr<Hbb::Tuple> pOut(new Hbb::Tuple(_output));
  iEvent.put(pOut);

}
  
// ------------ method called once each job just before starting event loop  ------------
void 
HbbProducer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
HbbProducer::endJob() {
}

// ------------ method called when starting to processes a run  ------------
/*
  void
  HbbProducer::beginRun(edm::Run const&, edm::EventSetup const&)
  {
  }
*/
 
// ------------ method called when ending the processing of a run  ------------
/*
  void
  HbbProducer::endRun(edm::Run const&, edm::EventSetup const&)
  {
  }
*/
 
// ------------ method called when starting to processes a luminosity block  ------------
/*
  void
  HbbProducer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
  {
  }
*/
 
// ------------ method called when ending the processing of a luminosity block  ------------
/*
  void
  HbbProducer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
  {
  }
*/
 
// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
HbbProducer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}
  
//define this as a plug-in
DEFINE_FWK_MODULE(HbbProducer);
  

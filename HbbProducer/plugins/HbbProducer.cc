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
  edm::InputTag _ak4Source, _ak8Source, _ak10Source, _ak12Source, _ak15Source;
  
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
  _ak4Source=edm::InputTag(iConfig.getParameter<edm::InputTag>("ak4Source"));
  _ak8Source=edm::InputTag(iConfig.getParameter<edm::InputTag>("ak8Source"));
  _ak10Source=edm::InputTag(iConfig.getParameter<edm::InputTag>("ak10Source"));
  _ak12Source=edm::InputTag(iConfig.getParameter<edm::InputTag>("ak12Source"));
  _ak15Source=edm::InputTag(iConfig.getParameter<edm::InputTag>("ak15Source"));

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

  h_patJets ak4jets;
  iEvent.getByLabel(_ak4Source,ak4jets);

  h_patJets ak8jets;
  iEvent.getByLabel(_ak8Source,ak8jets);
  fatJetInputs.insert(pair<string,h_patJets >(string("ak8"),ak8jets));
  fatJetOutputs.insert(pair<string, v_HbbJets* >(string("ak8"),&_output.ak8PFCHS));

  h_patJets ak10jets;
  iEvent.getByLabel(_ak10Source,ak10jets);
  fatJetInputs.insert(pair<string,h_patJets >(string("ak10"),ak10jets));
  fatJetOutputs.insert(pair<string, v_HbbJets* >(string("ak10"),&_output.ak10PFCHS));
  
  h_patJets ak12jets;
  iEvent.getByLabel(_ak12Source,ak12jets);
  fatJetInputs.insert(pair<string,h_patJets >(string("ak12"),ak12jets));
  fatJetOutputs.insert(pair<string, v_HbbJets* >(string("ak12"),&_output.ak12PFCHS));
  
  h_patJets ak15jets;
  iEvent.getByLabel(_ak15Source,ak15jets);
  fatJetInputs.insert(pair<string,h_patJets >(string("ak15"),ak15jets));
  fatJetOutputs.insert(pair<string, v_HbbJets* >(string("ak15"),&_output.ak15PFCHS));

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

  _output.rho=*rho;

  for(auto fatJetCollection=fatJetInputs.begin(); fatJetCollection!=fatJetInputs.end(); ++fatJetCollection){
    string name=fatJetCollection->first;
    h_patJets inputJets=fatJetCollection->second;

    v_HbbJets outputJets;
    for(auto inputJet=inputJets->begin(); inputJet!=inputJets->end(); ++inputJet){
      Hbb::Jet jet=Hbb::Jet();
      jet.lv.SetPtEtaPhiM(inputJet->pt(), inputJet->eta(), inputJet->phi(), inputJet->mass());
      //jet.tau1=inputJet->userFloat("NjettinessAK8:tau1");
      //jet.tau2=inputJet->userFloat("NjettinessAK8:tau2");
      //jet.tau3=inputJet->userFloat("NjettinessAK8:tau3");
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
  

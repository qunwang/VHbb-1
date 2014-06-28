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
  edm::InputTag _jetSource;
  
  HbbTuple _output;
  
  
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
  _jetSource=edm::InputTag(iConfig.getParameter<edm::InputTag>("jetSource"));

  //register your products
  produces<HbbTuple>();
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

  edm::Handle<edm::View<pat::Jet>> jets;
  iEvent.getByLabel(_jetSource,jets);

  _output.rho=*rho;

  for(edm::View<pat::Jet>::const_iterator jet=jets->begin(); jet!=jets->end(); ++jet){
    //std::cout<<jet->pt()<<std::endl;
  }

  std::auto_ptr<HbbTuple> pOut(new HbbTuple(_output));
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
  

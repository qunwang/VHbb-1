#ifndef VHbb_HbbProducer_HbbTuple_h
#define VHbb_HbbProducer_HbbTuple_h

#include "TLorentzVector.h"

#include <string>

namespace Hbb
{

  int def=-9999;

  //---------------------------------------------------------------------------------

  struct Object
  {
    TLorentzVector lv;

  Object() :
    lv(TLorentzVector())
    {
    }

  };
  
  //---------------------------------------------------------------------------------
  
  struct Jet:Object
  {
    float tau1, tau2, tau3;
    float prunedMass, trimmedMass, filteredMass;
    float qJetsVolatility;
  
  Jet() : Object(),
      tau1(def), tau2(def), tau3(def),
      prunedMass(def), trimmedMass(def), filteredMass(def),
      qJetsVolatility(def)
    {
    }

  };
  
  //---------------------------------------------------------------------------------

  struct Lepton:Object
  {
    int charge;
    
  Lepton() : Object(),
      charge(def)
      {
      }

  };

  //---------------------------------------------------------------------------------
  
  struct Electron:Lepton
  {
  Electron() : Lepton()
      {
      }

  };
  
  //---------------------------------------------------------------------------------
  
  struct Muon:Lepton
  {
  Muon() : Lepton()
      {
      }

  };

  //---------------------------------------------------------------------------------

  struct Tau:Lepton
  {
  Tau() : Lepton()
      {
      }

  };

  //---------------------------------------------------------------------------------

  struct V:Object
  {
  };

  //---------------------------------------------------------------------------------

  struct H:Object
  {
  };

  //---------------------------------------------------------------------------------
  struct MET:Object
  {
  };

  //---------------------------------------------------------------------------------

  struct Tuple
  {
    int eventClassification;
    float rho;
    
    std::vector<Jet> AK4PFCHS;
    std::vector<Jet> AK8PFCHS;
    std::vector<Jet> AK10PFCHS;
    std::vector<Jet> AK12PFCHS;
    std::vector<Jet> AK15PFCHS;

    std::vector<Electron> Electrons;
    std::vector<Muon> Muons;
    std::vector<Tau> Taus;
    
  Tuple() : 
    rho(def), 
      AK4PFCHS(std::vector<Jet>()), AK8PFCHS(std::vector<Jet>()), AK10PFCHS(std::vector<Jet>()), AK12PFCHS(std::vector<Jet>()), AK15PFCHS(std::vector<Jet>()),
      Electrons(std::vector<Electron>()), Muons(std::vector<Muon>()),Taus(std::vector<Tau>())
    {
    }
  };
  
  typedef std::vector<Object> ObjectCollection;
  typedef std::vector<Jet> JetCollection;
  typedef std::vector<Electron> ElectronCollection;
  typedef std::vector<Muon> MuonCollection;
  typedef std::vector<Tau> TauCollection;
  typedef std::vector<Tuple> TupleCollection;
}

#endif

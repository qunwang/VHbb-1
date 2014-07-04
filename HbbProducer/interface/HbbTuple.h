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
    double tau1, tau2, tau3;
    double prunedMass, trimmedMass, filteredMass;
    double qJetsVolatility;
  
  Jet() : Object(),
      tau1(def), tau2(def), tau3(def),
      prunedMass(def), trimmedMass(def), filteredMass(def),
      qJetsVolatility(def)
    {
    }
  };
    
  //---------------------------------------------------------------------------------

  struct Tuple
  {
    int eventClassification;
    double rho;
    
    std::vector<Jet> AK4PFCHS;
    std::vector<Jet> AK8PFCHS;
    std::vector<Jet> AK10PFCHS;
    std::vector<Jet> AK12PFCHS;
    std::vector<Jet> AK15PFCHS;

  Tuple() : 
    rho(def), 
      AK4PFCHS(std::vector<Jet>()), AK8PFCHS(std::vector<Jet>()), AK10PFCHS(std::vector<Jet>()), AK12PFCHS(std::vector<Jet>()), AK15PFCHS(std::vector<Jet>())
    {
    }
  };
  
  typedef std::vector<Object> ObjectCollection;
  typedef std::vector<Jet> JetCollection;
  typedef std::vector<Tuple> TupleCollection;
  
}

#endif

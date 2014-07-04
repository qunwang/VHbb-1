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
    double tau1;
    double tau2;
    double tau3;
  
  Jet() : Object(),
      tau1(def), tau2(def), tau3(def)
    {
    }
  };
    
  //---------------------------------------------------------------------------------

  struct Tuple
  {
    int eventClassification;
    double rho;
    
    std::vector<Jet> ak4PFCHS;
    std::vector<Jet> ak8PFCHS;
    std::vector<Jet> ak10PFCHS;
    std::vector<Jet> ak12PFCHS;
    std::vector<Jet> ak15PFCHS;

  Tuple() : 
    rho(def), 
      ak4PFCHS(std::vector<Jet>()), ak8PFCHS(std::vector<Jet>()), ak10PFCHS(std::vector<Jet>()), ak12PFCHS(std::vector<Jet>()), ak15PFCHS(std::vector<Jet>())
    {
    }
  };
  
  typedef std::vector<Object> ObjectCollection;
  typedef std::vector<Jet> JetCollection;
  typedef std::vector<Tuple> TupleCollection;
  
}

#endif

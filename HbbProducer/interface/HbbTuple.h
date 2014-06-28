#ifndef VHbb_HbbProducer_HbbTuple_h
#define VHbb_HbbProducer_HbbTuple_h

#include <string>

struct HbbTuple
{
  double rho;
  
HbbTuple(void) : 
  rho(-1) 
  {
  }
};

typedef std::vector<HbbTuple> HbbTupleCollection;

#endif

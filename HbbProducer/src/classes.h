#include "DataFormats/Common/interface/Wrapper.h"
#include "VHbb/HbbProducer/interface/HbbTuple.h"
#include <vector>

namespace { 
  struct dictionary {
    Hbb::Tuple dummy0;
    edm::Wrapper<Hbb::Tuple> dummy1;
    std::vector<Hbb::Tuple> dummy2;
    edm::Wrapper<std::vector<Hbb::Tuple> > dummy3;

    Hbb::Object dummy4;
    edm::Wrapper<Hbb::Object> dummy5;
    std::vector<Hbb::Object> dummy6;
    edm::Wrapper<std::vector<Hbb::Object> > dummy7;

    Hbb::Jet dummy8;
    edm::Wrapper<Hbb::Jet> dummy9;
    std::vector<Hbb::Jet> dummy10;
    edm::Wrapper<std::vector<Hbb::Jet> > dummy11;
    
  };
}

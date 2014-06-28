#include "DataFormats/Common/interface/Wrapper.h"
#include "VHbb/HbbProducer/interface/HbbTuple.h"
#include <vector>

namespace { 
  struct dictionary {
    HbbTuple dummy0;
    edm::Wrapper<HbbTuple> dummy1;
    std::vector<HbbTuple> dummy2;
    edm::Wrapper<std::vector<HbbTuple> > dummy3;
  };
}

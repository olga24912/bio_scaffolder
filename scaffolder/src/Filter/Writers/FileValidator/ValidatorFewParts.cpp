#include "ValidatorFewParts.h"

namespace filter {
    namespace writers {
        bool ValidatorFewParts::isGoodVertexSet(std::vector<int> vert, Filter *filter) {
            DEBUG("start validation");
            for (int i = 0; i < (int) vert.size(); ++i) {
                int v = vert[i];
                std::vector<int> edges = filter->getEdges(v);
                std::vector<std::pair<int, int> > sig;

                for (int e : edges) {
                    if (filter->getLibName(filter->getEdgeLib(e)) == "ref") continue;
                    sig.push_back(std::make_pair(filter->getEdgeCoordB1(e), filter->getEdgeCoordE1(e)));
                }

                for (int i = 0; i < (int) sig.size(); ++i) {
                    for (int j = 0; j < (int) sig.size(); ++j) {
                        if (sig[i].second + 500 < sig[j].first || sig[j].second + 500 < sig[i].first) {
                            return true;
                        }
                    }
                }
            }

            return false;
        }
    }
}
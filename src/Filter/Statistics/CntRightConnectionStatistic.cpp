#include "CntRightConnectionStatistic.h"
#include "Filter/AligInfo/InfoAboutContigsAlig.h"

namespace filter {
    namespace statistics {
        using namespace alig_info;
        void CntRightConnectionStatistic::calculateStatistic(ContigGraph *filter, std::string coordFile, int libNum) {
            InfoAboutContigsAlig aligInfo;
            aligInfo.parseCoordFile(filter, coordFile);

            int cnt[7] = {0, 0, 0, 0, 0, 0, 0};

            int n = filter->getVertexCount();
            for (int v = 0; v < n; ++v) {
                std::vector<int> edges = filter->getEdges(v);
                for (int e : edges) {
                    if (filter->getEdgeLib(e) != libNum) continue;
                    InfoAboutContigsAlig::ErrorType status = aligInfo.isCorrectEdge(filter, e);
                    cnt[status]++;
                }
            }

            printStatistic("", cnt);
        }
    }
}

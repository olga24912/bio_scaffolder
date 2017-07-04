#include <algorithm>
#include <iostream>
#include <set>
#include "ScaffolderPipeline.h"
#include "ScaffoldStrategy.h"
#include "ScaffoldStrategyOneLine.h"
#include "ScaffoldStrategyLeaveConnection.h"

void ScaffolderPipeline::evaluate(Filter *graph, std::string contigFile, std::string out) {
    INFO("start build scaffolds");
    Scaffolds scaffolds(contigFile);

    bothDirFilter(graph, scaffolds);
    //onlySplit50Filter(graph, scaffolds);
    scaffolds.print(out);
}

void ScaffolderPipeline::bothDirFilter(Filter *graph, Scaffolds &scaffolds) {
    using namespace contig_graph;
    std::vector<int> libs = graph->getLibList();

    std::vector<int> minEdge((unsigned long) libs[(int)libs.size() - 1], 1e9);
    std::vector<int> vert = graph->getVertexList();
    for (int v : vert) {
        std::vector<int> edges = graph->getEdges(v);
        for (int e : edges) {
            minEdge[graph->getEdgeLib(e)] = std::min(minEdge[graph->getEdgeLib(e)], graph->getEdgeWeight(e));
        }
    }

    for (int wp = 1; wp < 25; ++wp) {
        for (int ws50 = 1; ws50 < 25; ++ws50) {
            ScaffoldStrategyOneLine scafol;
            for (int l : libs) {
                std::stringstream arg;
                if (graph->getLibType(l) == ContigGraph::Lib::Type::RNA_PAIR) {
                    arg << l << " " << std::max(wp, minEdge[l]);
                } else if (graph->getLibType(l) == ContigGraph::Lib::Type::RNA_SPLIT_50) {
                    arg << l << " " << std::max(ws50, minEdge[l]);
                } else {
                    continue;
                }

                DEBUG("query: " << arg.str());
                graph->processQuery(Query(Query::MIN_EDGE_WEIGHT, arg.str()));
            }

            INFO("add scaffolds with minPairWeight=" << wp << " minSplit50Weight=" << ws50
                                                     << " minPairAcceptWeight=" << (int)(wp * 0.75 + ws50*2.25)
                                                     << " minSplit50AcceptWeight" <<  (int)(wp * 0.75 + ws50*1.25));

            scafol.addConnection(&scaffolds, graph, std::vector<int> ({0, 0, (int)(wp * 0.75 + ws50*2.25), (int)(wp * 0.75 + ws50*1.25), 0, 0}));
        }
    }
}

void ScaffolderPipeline::onlySplit50Filter(Filter *graph, Scaffolds &scaffolds) {
    using namespace contig_graph;
    std::vector<int> libs = graph->getLibList();

    std::vector<int> minEdge((unsigned long) libs[(int)libs.size() - 1], 1e9);
    std::vector<int> vert = graph->getVertexList();
    for (int v : vert) {
        std::vector<int> edges = graph->getEdges(v);
        for (int e : edges) {
            minEdge[graph->getEdgeLib(e)] = std::min(minEdge[graph->getEdgeLib(e)], graph->getEdgeWeight(e));
        }
    }

    for (int ws50 = 1; ws50 < 25; ++ws50) {
        ScaffoldStrategyOneLine scafol;
        for (int l : libs) {
            std::stringstream arg;
            if (graph->getLibType(l) == ContigGraph::Lib::Type::RNA_SPLIT_50) {
                arg << l << " " << std::max(ws50, minEdge[l]);
            } else {
                continue;
            }

            std::cerr << arg.str() << std::endl;
            graph->processQuery(Query(Query::MIN_EDGE_WEIGHT, arg.str()));
        }

        std::cerr << ws50 << " " << (int) (ws50 * 1.5) << std::endl;

        scafol.addConnection(&scaffolds, graph, std::vector<int>({0, 0, 0, (int) (ws50 * 1.5), 0, 0}));
    }
}



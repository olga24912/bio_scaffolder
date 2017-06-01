#include "GraphBuilder.h"

void GraphBuilder::setGraph(ContigGraph *graph) {
    GraphBuilder::graph = graph;
    graph->newLib(libName, getLibColor(), getLibType());
}

void GraphBuilder::setLibName(std::string libName, std::string path) {
    this->libName = libName;
    GraphBuilder::path = path + "/" + libName;

    std::string command = "mkdir " + GraphBuilder::path;
    system(command.c_str());
}

std::string GraphBuilder::colorToString(int *color) {
    std::string res = "#";
    for (int i = 0; i < 3; ++i) {
        if (color[i] / 16 < 10) {
            res += (color[i] / 16) + '0';
        } else {
            res += (color[i] / 16) - 10 + 'a';
        }

        if (color[i] % 16 < 10) {
            res += (color[i] % 16) + '0';
        } else {
            res += (color[i] % 16) - 10 + 'a';
        }
    }
    return res;
}

void GraphBuilder::setSamFileWriter() {
    this->samFileWriter = SamFileWriteEdge(path);
}

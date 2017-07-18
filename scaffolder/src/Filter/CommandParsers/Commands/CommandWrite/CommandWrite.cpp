#include "CommandWrite.h"

namespace filter {
    namespace commands {
        void CommandWrite::execute(std::string argv, State &state, ContigGraph *filter) {
            std::string fileName;
            std::stringstream ss(argv);
            ss >> fileName;

            state.dotWriterBuilder->setFilter(filter);
            state.dotWriterBuilder->setValidator(state.validator);
            state.dotWriterBuilder->setMaxVert(state.maxVert);
            state.dotWriterBuilder->setMaxEdge(state.maxEdge);
            state.dotWriterBuilder->setCoordFile(state.coordFile);

            writeGraph(argv, state, filter);

            tools::SystemTools::showDotFile(fileName);
        }
    }
}
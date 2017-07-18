#include "CommandWriteBigComp.h"

namespace filter {
    namespace commands {
        void CommandWriteBigComp::writeGraph(std::string argv, State &state, ContigGraph *filter) {
                std::stringstream ss(argv);
                std::string fileName;
                int size;
                ss >> fileName >> size;

                INFO("Write Big Comp fileName=" << fileName << " size=" << size);

                writers::WriteBigComponent writer(fileName, size, filter, state.validator, state.dotWriterBuilder);
                writer.write();
        }
    }
}

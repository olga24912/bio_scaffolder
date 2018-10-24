#ifndef SCAFFOLDER_WRITEBIGCOMPONENT_H
#define SCAFFOLDER_WRITEBIGCOMPONENT_H

#include "Writer.h"

namespace filter {
    namespace writers {
//split graph on component and write only big components in different files
        class WriteBigComponent : public Writer {
        private:
            std::string fileName; //prefix of file name for write component
            int minSize; //min size of the component
        public:
            WriteBigComponent(std::string fileName, int minSize, ContigGraph *graph1, FileValidator *validator,
                              DotWriterBuilder *builder);

            void write() override;

        private:
            DECL_LOGGER("WriteBigComponent");
        };
    }
}

#endif //SCAFFOLDER_WRITEBIGCOMPONENT_H
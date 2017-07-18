#ifndef SCAFFOLDER_VALIDATORNOTPATHWITHALLLIB_H
#define SCAFFOLDER_VALIDATORNOTPATHWITHALLLIB_H

#include "FileValidator.h"

namespace filter {
    namespace writers {
        class ValidatorNotPathWithAllLib : public FileValidator {
        public:
            virtual bool isGoodVertexSet(std::vector<int> vert, ContigGraph *graph);
        };
    }
}

#endif //SCAFFOLDER_VALIDATORNOTPATHWITHALLLIB_H

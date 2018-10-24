#ifndef SCAFFOLDER_COMMANDSETFVFEWPARTS_H
#define SCAFFOLDER_COMMANDSETFVFEWPARTS_H

#include <Filter/Writers/FileValidator/ValidatorNotPathWithAllLib.h>
#include <Filter/Writers/FileValidator/ValidatorFork.h>
#include <Filter/Writers/FileValidator/ValidatorFewParts.h>
#include "CommandSetFV.h"

namespace filter {
    namespace commands {

        class CommandSetFVFewParts : public CommandSetFV {
        protected:
            void setFV(State &state, std::string argv) override {
                INFO("set file validator few parts");
                state.validator = new writers::ValidatorFewParts();
            }
        };
    }
}

#endif //SCAFFOLDER_COMMANDSETFVFEWPARTS_H
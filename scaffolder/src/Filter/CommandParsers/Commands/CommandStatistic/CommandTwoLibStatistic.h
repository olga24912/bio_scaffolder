#ifndef SCAFFOLDER_COMMANDTWOLIBSTATISTIC_H
#define SCAFFOLDER_COMMANDTWOLIBSTATISTIC_H


#include <Filter/CommandParsers/Commands/Command.h>

class CommandTwoLibStatistic : public Command {
public:
    void execute(std::string argv, State &state, Filter *filter) override;
};


#endif //SCAFFOLDER_COMMANDTWOLIBSTATISTIC_H
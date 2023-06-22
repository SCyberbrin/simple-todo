#ifndef COMMAND_H
#define COMMAND_H

#include <vector>

class Command {
public:
    virtual void execute(const std::vector<std::string>& args) = 0;
};

#endif
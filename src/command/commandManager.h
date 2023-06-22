#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "command.h"

class CommandManager {
private:
    struct CommandInfo {
        std::string name;
        std::unique_ptr<Command> command;
    };

    std::vector<CommandInfo> commands;

public:
    void registerCommand(const std::string& name, std::unique_ptr<Command> command);

    void executeCommand(const std::string& name, const std::vector<std::string>& args);
};

#endif
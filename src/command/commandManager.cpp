#include "commandManager.h"


void CommandManager::registerCommand(const std::string &name, std::unique_ptr<Command> command)
{
    commands.push_back({name, std::move(command)});
}

void CommandManager::executeCommand(const std::string &name, const std::vector<std::string>& args)
{
    for (const auto& commandInfo : commands) {
        if (commandInfo.name == name) {
            commandInfo.command->execute(args);
            return;
        }
    }
    std::cout << "Command not found: " << name << std::endl;
}

#ifndef MOVE_COMMAND_H
#define MOVE_COMMAND_H

#include <iostream>
#include "command.h"
#include "../todoManager/todoManager.h"

class MoveCommand : public Command
{
public:
    void execute(const std::vector<std::string>& args) override {
        if (args.size() != 2) {
            std::cout << "Invalid input for mv command." << std::endl;
            return;
        }

        int fromIdx, toIdx;

        try {
            fromIdx = std::stoi(args[0]);
            toIdx = std::stoi(args[1]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid input for mv command. Index must be an integer." << std::endl;
            return;
        }

        if (fromIdx >= TodoManager::getTodosSize() || fromIdx < 0)
        {
            std::cout << "Selected todo doenst exist. Invalid todo." << std::endl;
            return;
        }

        if (toIdx >= TodoManager::getTodosSize() || toIdx < 0)
        {
            std::cout << "Invalid destination." << std::endl;
            return;
        }

        TodoManager::moveTodos(fromIdx, toIdx);
    
    }
};

#endif
#ifndef CHECKED_COMMAND_H
#define CHECKED_COMMAND_H

#include <string>
#include "command.h"
#include "removeCommand.h"
#include "../todoManager/todoManager.h"

class CheckedCommand : public Command
{
public:
    void execute(const std::vector<std::string>& args) override 
    {
        int selectedIdx;
        try {
            selectedIdx = std::stoi(args[0]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid input for c command. Index must be an integer." << std::endl;
            return;
        }

        if (selectedIdx >= TodoManager::getTodosSize() || selectedIdx < 0)
        {
            std::cout << "Selected todo doenst exist. Invalid todo." << std::endl;
            return;
        }

        todo *selectedTodo = TodoManager::getTodoById(selectedIdx);

        selectedTodo->checked = askUser(
            "Should the Todo '" + selectedTodo->Titel + "' get Checked?"
        );
    }
};

#endif
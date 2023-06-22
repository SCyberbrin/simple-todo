#ifndef REMOVE_COMMAND_H
#define REMOVE_COMMAND_H

#include <string>
#include "command.h"
#include "commandManager.h"
#include "../todoManager/todoManager.h"

class RemoveCommand : public Command
{
public:
    void execute(const std::vector<std::string>& args) override 
    {
        int selectedIdx;
        try {
            selectedIdx = std::stoi(args[0]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid input for r command. Index must be an integer." << std::endl;
            return;
        }

        if (selectedIdx >= TodoManager::getTodosSize() || selectedIdx < 0)
        {
            std::cout << "Selected todo doenst exist. Invalid todo." << std::endl;
            return;
        }

        if (!askUser("Are you sure you want to delete it?")) return;

        TodoManager::removeTodo(selectedIdx);
        
        std::cout << "Todo Nummber " << selectedIdx << " got Deleted!" << std::endl;
    }

    bool askUser(std::string question, const char * trueChar = "y", const char * falseChar = "n")
    {
        std::string anser;
        
        while (true)
        {
            std::cout << question << " [" << trueChar << "/" << falseChar << "] ";
            std::getline(std::cin, anser);

            if (anser == trueChar)
            {
                return true;
            } else if (anser == falseChar)
            {
                return false;
            }

            std::cout << "Wrong anser!" << std::endl;
        }
        

    }
};

#endif
#ifndef EDIT_COMMAND_H
#define EDIT_COMMAND_H

#include <string>
#include "command.h"
#include "commandManager.h"
#include "../todoManager/todoManager.h"

class EditCommand : public Command
{
public:
    void execute(const std::vector<std::string>& args) override 
    {
        int selectedIdx;
        todo *selectedTodo;
        
        try {
            selectedIdx = std::stoi(args[0]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid input for e command. Index must be an integer." << std::endl;
            return;
        }

        if (selectedIdx >= TodoManager::getTodosSize() || selectedIdx < 0)
        {
            std::cout << "Selected todo doenst exist. Invalid todo." << std::endl;
            return;
        }

        selectedTodo = TodoManager::getTodoById(selectedIdx);

        const std::string help_string = R"(
======================|Edit|======================
t: Edit the Titel
d: Edit the Description
q: Quit the Editor
==================================================
)";

        std::string _i;

        while (true)
        {
            std::cout << help_string << std::endl;
            std::getline(std::cin, _i);

            if (_i == "t")
            {

                std::string newTitel;
                
                std::cout << "Old Titel: " << selectedTodo->Titel << std::endl;

                std::cout << "New Titel: ";

                std::getline(std::cin, newTitel);

                if (newTitel.empty())
                {
                    std::cout << "invalid Titel" << std::endl;
                    continue;
                }

                selectedTodo->Titel = newTitel;


            } else if (_i == "d")
            {
                std::string newDescription;
                
                std::cout << "Old Description: " <<  selectedTodo->Description << std::endl;

                std::cout << "New Description: ";

                std::cin >> newDescription;

                selectedTodo->Titel = newDescription;
            } else if (_i == "q")
            {
                break;
            } else if (_i.empty())
            {
                continue;
            } else
            {
                std::cout << "Invalid Command" << std::endl;
                continue;
            }

        }
    }
};

#endif
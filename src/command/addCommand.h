#ifndef ADD_COMMAND_H
#define ADD_COMMAND_H

#include <string>
#include "command.h"
#include "../todoManager/todoManager.h"

class AddCommand : public Command
{
public:
    void execute(const std::vector<std::string>& args) override 
    {

        std::string titel;
        std::string description;

        std::cout << "====================|Add Todo|====================" << std::endl;
        
        while (true)
        {
            std::cout << "Titel: ";
            std::getline(std::cin, titel);
            
            if (titel.empty())
            {
                std::cout << "Not Empty Titel!" << std::endl;
                continue;
            }
            
            break;
        }



        std::cout << "Description: ";
        std::getline(std::cin, description);

        TodoManager::addTodo({titel, description});
    }
};


#endif
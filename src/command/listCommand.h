#ifndef LIST_COMMAND_H
#define LIST_COMMAND_H

#include <string>
#include "command.h"
#include "commandManager.h"
#include "../todoManager/todoManager.h"


class ListCommand : public Command
{
private:
    int index = 0;
public:
    void execute(const std::vector<std::string>& args) override 
    {
        
        std::cout << "===================|List Todo|====================" << std::endl;

        for (todo &_todo : TodoManager::getTodos())
        {
            std::cout << index << ": " << _todo.Titel << std::endl;

            ++index;
        }
        std::cout << "==================================================" << std::endl;
    }
};

#endif
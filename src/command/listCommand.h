#ifndef LIST_COMMAND_H
#define LIST_COMMAND_H

#include <string>
#include "command.h"
#include "commandManager.h"
#include "../todoManager/todoManager.h"


class ListCommand : public Command
{
public:
    void execute(const std::vector<std::string>& args) override 
    {
        int index = 0;
        std::cout << "===================|List Todo|====================" << std::endl;

        for (todo &_todo : TodoManager::getTodos())
        {
            std::cout << ckeckbox(_todo.checked) << " " << index << ": " << _todo.Titel << std::endl;

            ++index;
        }
        std::cout << "==================================================" << std::endl;
    }

private:
    std::string ckeckbox(bool checked)
    {
        if (checked)
        {
            return "[x]";
        }

        return "[ ]";
    }

};


#endif
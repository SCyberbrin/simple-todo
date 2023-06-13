#include <iostream>
#include <vector>
#include "todo.cpp"

const std::string help_string = R"(
======================|Help|======================
h: To Show this Page
l: Display all Todos.
a: Add an new Todo.
e <id>: Edit the existing Todo.
r <id>: Remove a specific Todo based on the Id.
q: Quit the Application
==================================================
)";

void printAllTodos(std::vector<todo> &_todos)
{
    int index = 0;
    std::cout << "===================|List Todo|====================" << std::endl;

    for (todo &_todo : _todos)
    {
        std::cout << index << ": " << _todo.Titel << std::endl;

        ++index;
    }
}

todo addTodo()
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

    todo newTodo = {titel, description};

    return newTodo;
}

std::string getLastSubstring(const std::string& str, const std::string& delimiter) {
    size_t pos = str.find_last_of(delimiter);
    if (pos != std::string::npos) {
        return str.substr(pos + 1);
    }
    return str;
}

bool hasDigit(const std::string &str)
{
    bool result = false;
    for (char i : str) {
      if(isdigit(i))
        result = true;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    std::vector<todo> todos;

    std::string i;

    std::cout << help_string << std::endl;
    
    while (true)
    {
        std::cout << "Command: ";
        std::getline(std::cin, i);

        if (i == "h")
        {
            std::cout << help_string << std::endl;
        } else if (i == "l")
        {
            printAllTodos(todos);

        } else if (i == "a")
        {
            todos.push_back(addTodo());
        } else if (i.substr(0, 1) == "r")
        {
            if (!hasDigit(i))
            {
                std::cout << "Invalid Command" << std::endl;
                continue;
            }

            int selectedIdx = 0;

            try
            {
                selectedIdx = std::stoi(i.erase(0, 2));
            }
            catch(std::invalid_argument)
            {
                std::cout << "Invalid Command" << std::endl;
                continue;
            }

            if (selectedIdx >= todos.size())
            {
                std::cout << "Invalid Todo Index" << std::endl;
                continue;
            }

            todos.erase(todos.begin() + selectedIdx);
            
            std::cout << "Todo Nummber " << selectedIdx << " got Deleted!" << std::endl;

        } else if (i == "q")
        {
            exit(0);
        } else if (i.empty())
        {
            continue;
        } else 
        {
            std::cout << "Invalid Command" << std::endl;
        }
        
        
    }
    

    return 0;
}
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "todo.cpp"
#include "ui_utils.cpp"

#define clear cout << "\033[H\033[J"

const std::string help_string = R"(
======================|Help|======================
h: To Show this Page
l: Display all Todos.
a: Add an new Todo.
e <id>: Edit the existing Todo.
r <id>: Remove a specific Todo based on the Id.
mv <fromId> <toId>: Moves a todo to a different Id.
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
    std::cout << "==================================================" << std::endl;
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

void editTodo(todo *selectedTodo)
{
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

            std::cin >> newTitel;

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

std::vector<std::string> tokenizeString(const std::string& input) {
    std::istringstream iss(input);
    std::vector<std::string> tokens;

    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

void move(std::vector<todo>& v, size_t oldIndex, size_t newIndex)
{
    if (oldIndex > newIndex)
        std::rotate(v.rend() - oldIndex - 1, v.rend() - oldIndex, v.rend() - newIndex);
    else        
        std::rotate(v.begin() + oldIndex, v.begin() + oldIndex + 1, v.begin() + newIndex + 1);
}

void processCommand(const std::vector<std::string>& tokens, std::vector<todo>& todos)
{
    if (tokens.empty()) {
        std::cout << "Invalid input." << std::endl;
        return;
    }

    std::string command = tokens[0];


    if (command == "h") 
    {
        std::cout << help_string << std::endl;
        return;
    }else if (command == "l")
    {
        printAllTodos(todos);
    } else if (command == "a")
    {
        todos.push_back(addTodo());
    } else if (command == "r")
    {
        int selectedIdx;
        try {
            selectedIdx = std::stoi(tokens[1]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid input for r command. Index must be an integer." << std::endl;
            return;
        }

        if (selectedIdx >= todos.size() || selectedIdx < 0)
        {
            std::cout << "Selected todo doenst exist. Invalid todo." << std::endl;
            return;
        }

        if (!askUser("Are you sure you want to delete it?")) return;

        todos.erase(todos.begin() + selectedIdx);
        
        std::cout << "Todo Nummber " << selectedIdx << " got Deleted!" << std::endl;

    } else if (command == "e")
    {

        int selectedIdx;

        try {
            selectedIdx = std::stoi(tokens[1]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid input for e command. Index must be an integer." << std::endl;
            return;
        }

        if (selectedIdx >= todos.size() || selectedIdx < 0)
        {
            std::cout << "Selected todo doenst exist. Invalid todo." << std::endl;
            return;
        }

        editTodo(&todos[selectedIdx]);
        
    } else if (command == "mv")
    {
        if (tokens.size() != 3) {
            std::cout << "Invalid input for mv command." << std::endl;
            return;
        }

        int fromIdx, toIdx;

        try {
            fromIdx = std::stoi(tokens[1]);
            toIdx = std::stoi(tokens[2]);
        } catch (const std::invalid_argument& e) {
            std::cout << "Invalid input for mv command. Index must be an integer." << std::endl;
            return;
        }

        if (fromIdx >= todos.size() || fromIdx < 0)
        {
            std::cout << "Selected todo doenst exist. Invalid todo." << std::endl;
            return;
        }

        if (toIdx >= todos.size() || toIdx < 0)
        {
            std::cout << "Invalid destination." << std::endl;
            return;
        }

        move(todos, fromIdx, toIdx);

    } else if (command == "q")
    {
        exit(0);
    }else 
    {
        std::cout << "Invalid Command" << std::endl;
    }
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

        std::vector<std::string> tokens = tokenizeString(i);

        processCommand(tokens, todos);

    }
    

    return 0;
}

#include "todoManager/todoManager.h"

#include <iostream>
#include <sstream>

#include "command/commandManager.h"
#include "command/moveCommand.h"
#include "command/addCommand.h"
#include "command/listCommand.h"
#include "command/editCommand.h"
#include "command/removeCommand.h"

#define clear std::cout << "\033[H\033[J"


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


std::vector<std::string> tokenizeString(const std::string& input) {
    std::istringstream iss(input);
    std::vector<std::string> tokens;

    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

int main(int argc, char const *argv[])
{
    CommandManager cm;

    // Register the 'a' command
    cm.registerCommand("a", std::make_unique<AddCommand>());

    // Register the 'l' command
    cm.registerCommand("l", std::make_unique<ListCommand>());

    // Register the 'e' command
    cm.registerCommand("e", std::make_unique<EditCommand>());

    // Register the 'r' command
    cm.registerCommand("r", std::make_unique<RemoveCommand>());

    // Register the 'mv' command
    cm.registerCommand("mv", std::make_unique<MoveCommand>());

    clear;

    std::cout << help_string << std::endl;
    
    std::string input;
    while (true) {
        std::cout << "Command: ";
        std::getline(std::cin, input);

        std::vector<std::string> token_commands = tokenizeString(input);

        if (token_commands[0] == "q")
            break;
        else if (token_commands[0] == "h"){
            std::cout << help_string << std::endl;
            continue;
        }


        std::vector<std::string> token_args = token_commands;
        token_args.erase(token_args.begin());

        cm.executeCommand(token_commands[0], token_args);
    }
    return 0;
}

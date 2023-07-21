#ifndef FILEIO_H
#define FILEIO_H

#include <filesystem>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

#include "todoManager/todoManager.h"

namespace fs = std::filesystem;

class fileIO
{
private:
    fs::path todoFilePath = ""; //todo: different path
public:
    fileIO();

    void saveTodos(std::vector<todo> const &todos);
    void loadTodos();
};

fileIO::fileIO()
{
    todoFilePath += "\\todos.data";
}

inline void fileIO::saveTodos(std::vector<todo> const &todos)
{
    std::ofstream todoFile(todoFilePath, std::ios::trunc);
    if (!todoFile.is_open()) return;

    for (todo todo : todos)
    {
        todoFile << todo.checked << ",\"" << todo.Titel << "\",\"" << todo.Description << "\"\n";
    }
    todoFile.close();
}

inline void fileIO::loadTodos()
{
    std::ifstream todoFile(todoFilePath);
    if (!todoFile.is_open()) return;
    
    std::string line;
    std::regex regexObj("^(\\d),\"(.+)\",\"(.+)\"$");

    while (getline(todoFile, line))
    {
        std::smatch match;
        if (std::regex_match(line, match, regexObj)) {
            todo _todo;

            _todo.checked = std::stoi(match[1].str());
            _todo.Titel = match[2].str();
            _todo.Description = match[3].str();
                       
            TodoManager::addTodo(_todo);
        }
    }
    
    todoFile.close();
}
#endif
#include "todoManager.h"



void TodoManager::addTodo(const todo &newTodo)
{ 
    getInstance().todos.push_back(newTodo);
}

todo *TodoManager::getTodoById(int todoId)
{
    return &getInstance().todos[todoId];
}

void TodoManager::removeTodo(int todoId)
{ 
    getInstance().todos.erase(getInstance().todos.begin() + todoId);

}

void TodoManager::moveTodos(size_t oldIndex, size_t newIndex)
{
    if (oldIndex > newIndex)
        std::rotate(getInstance().todos.rend() - oldIndex - 1, getInstance().todos.rend() - oldIndex, getInstance().todos.rend() - newIndex);
    else        
        std::rotate(getInstance().todos.begin() + oldIndex, getInstance().todos.begin() + oldIndex + 1, getInstance().todos.begin() + newIndex + 1);
}


TodoManager TodoManager::tm;
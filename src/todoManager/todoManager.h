#ifndef TODO_MAMAGER_H
#define TODO_MAMAGER_H

#include <vector>
#include <algorithm>
#include "todo.cpp"

class TodoManager
{
private:
    TodoManager(){};

    static TodoManager tm;

    std::vector<todo> todos;


public:

    TodoManager(TodoManager const&) = delete;
    void operator=(TodoManager const&) = delete;

    static TodoManager &getInstance()
    {
        return tm;
    }

    static void addTodo(const todo &newTodo);

    static int getTodosSize() { return getInstance().todos.size(); }

    static todo *getTodoById(int todoId);

    static void removeTodo(int todoId);

    static std::vector<todo> getTodos() { return getInstance().todos; }

    static void moveTodos(size_t oldIndex, size_t newIndex);

};

#endif
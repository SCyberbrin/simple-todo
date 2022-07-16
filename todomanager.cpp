#include "todomanager.h"

#include <QDebug>
todoManager::todoManager(QObject *parent)
: QObject{parent}
{
    QDir databasePath;
    QString path = databasePath.currentPath()+"/myDb.db";

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (db.open()) {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS todos "
                  "(id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "name varchar(20) not null, "
                  "description varchar(30), "
                  "done INTEGER DEFAULT 0, "
                  ");");
        query.clear();
    }

}

void todoManager::test()
{
    qDebug() << "hi";
}

void todoManager::addTodoToDB(SQLTODO newTodo)
{
    QSqlQuery query;
    if (getTodoFromDB(newTodo.id).name.isEmpty()){
        // IF THIS TODO ISNT IN THE DB
        query.prepare("INSERT INTO todos (name, description, done) "
                      "VALUES (?, ?, ?)");
    }else{
        // IF THIS TODO IS IN THE DB
        query.prepare("UPDATE todos SET name = ?, description = ?, done = ? "
                      "WHERE id = " + QString::number(newTodo.id));
    }
    query.bindValue(0, newTodo.name);
    query.bindValue(1, newTodo.description);
    query.bindValue(2, newTodo.done);
    query.exec();
}

void todoManager::deleteTodoToDB(int todoId)
{
    QSqlQuery query;
    query.prepare("DELETE FROM todos WHERE id = ?");
    query.bindValue(0, todoId);

    query.exec();
}

SQLTODO todoManager::getTodoFromDB(int todoId)
{
    // get all info from db to the todoEditor
    SQLTODO todo;

    QSqlQuery query;
    query.prepare("SELECT id, name, description, done FROM todos where id = ?;");

    query.bindValue(0, todoId);

    query.exec();
    while (query.next()) {

        todo.id = query.value(0).toInt(); // id
        todo.name = query.value(1).toString(); // name
        todo.description = query.value(2).toString(); // description
        todo.done = query.value(3).toBool(); // done

    }
    query.clear();
    return todo;
}

QList<SQLTODO> todoManager::getAllTodosFromDB()
{
    QList<SQLTODO> todoList;
    QSqlQuery query("SELECT id, name FROM todos");
    while (query.next()) {

        SQLTODO todo = SQLTODO();

        todo.id = query.value(0).toInt();
        todo.name = query.value(1).toString();


        todoList.append(todo);
    }
    return todoList;
}

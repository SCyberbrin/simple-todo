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

void todoManager::getTodosToTree(QTreeWidget *tree)
{
    QSqlQuery query("SELECT id, name FROM todos");
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();

        QTreeWidgetItem *itm = new QTreeWidgetItem(tree);
        itm->setText(0, QString::number(id));
        itm->setText(1, name);
    }
}

SQLTODO *todoManager::getFullTodoInfo(int todoId)
{
    if (!db.isOpen()) return new SQLTODO();

    SQLTODO *todo = new SQLTODO();

    QString sql = "SELECT id, name, description, done FROM todos where id = " + QString::number(todoId);

    qInfo() << sql;

    // get all info from db to the todoEditor
    QSqlQuery query(sql);
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString description = query.value(2).toString();
        bool done = query.value(3).toBool();

        todo->id = id;
        todo->name = name;
        todo->description = description;
        todo->done = done;
    }
    query.clear();
    return todo;
}

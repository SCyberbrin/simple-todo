#ifndef TODOMANAGER_H
#define TODOMANAGER_H

#include <QtWidgets>
#include <QObject>
#include <QtSql>

#include "SQLTODO.h"

class todoManager : public QObject
{
    Q_OBJECT
public:
    explicit todoManager(QObject *parent = nullptr);
    //void getTodo(int todoId);

public slots:
    void test(void);
    void getTodosToTree(QTreeWidget *tree);
    SQLTODO *getFullTodoInfo(int todoId);

private:
    //QList<SQLTODO> todos;
    QSqlDatabase db;

signals:

};

#endif // TODOMANAGER_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "todomanager.h"

#include "SQLTODO.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTreeWidgetItem *addTaskQTreeWidget(int id, QString name, QTreeWidgetItem *group = nullptr);
    QTreeWidgetItem *addGroupQTreeWidget(int id, QString name);

public slots:
    void updateTodoList(void);

private slots:
    void closeDisplay(void);
    void openDisplay(void);
    void displayCurrentTodo(void);

    void on_todoList_itemClicked(QTreeWidgetItem *item, int column);

    void on_actionDelete_triggered();

    void on_actionNew_triggered();

    void on_actionSaveTodo_triggered();

private:
    Ui::MainWindow *ui;
    todoManager *todo;
    SQLTODO currentTodoDisplayed;
};
#endif // MAINWINDOW_H

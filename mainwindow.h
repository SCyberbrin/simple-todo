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


private slots:
    void closeDisplay();
    void openDisplay();

    void on_todoList_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;
    todoManager *todo;
};
#endif // MAINWINDOW_H

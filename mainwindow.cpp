#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->todoList->setColumnCount(2);

    todoManager *todo = new todoManager(ui->todoList);

    QTreeWidgetItem *group = todo->addGroup("groupTest", "");

    todo->addTask("test", "test2", group);

}

MainWindow::~MainWindow()
{
    delete ui;
}


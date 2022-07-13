#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());*/


    ui->todoList->setColumnCount(2);

    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->todoList);

    itm->setText(0, "Hallo");
    itm->setText(1, "world");

    ui->todoList->addTopLevelItem(itm);

    // Add Child
    QTreeWidgetItem *childItm = new QTreeWidgetItem();
    childItm->setText(0, "hello2");
    childItm->setText(1, "world2");

    itm->addChild(childItm);

}

MainWindow::~MainWindow()
{
    delete ui;
}


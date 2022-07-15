#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    todo = new todoManager();

    ui->todoList->setColumnCount(2);

    todo->getTodosToTree(ui->todoList);

    //QTreeWidgetItem *group = todo->addGroupQTreeWidget("groupTest", "");

    //todo->addTaskQTreeWidget("test", "test2", group);
    //todo->getTodo(2);
    closeDisplay();

    connect(ui->actionNewGroup, SIGNAL(triggered(bool)), todo, SLOT(test(void)));
    connect(ui->actionnew, SIGNAL(triggered(bool)), todo, SLOT(test(void)));


    connect(ui->actionDelete, SIGNAL(triggered(bool)), this, SLOT(closeDisplay()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

QTreeWidgetItem *MainWindow::addTaskQTreeWidget(int id, QString name, QTreeWidgetItem *group)
{
    if (group == nullptr) {
        QTreeWidgetItem *itm = new QTreeWidgetItem(ui->todoList);
        itm->setText(0, name);
        itm->setText(1, QString(id));
        return itm;
    } else {
        QTreeWidgetItem *itm = new QTreeWidgetItem();
        itm->setText(0, name);
        itm->setText(1, QString(id));
        group->addChild(itm);
        return itm;
    }
}

QTreeWidgetItem *MainWindow::addGroupQTreeWidget(int id, QString name)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->todoList);

    itm->setText(0, name);
    itm->setText(1, QString(id));

    ui->todoList->addTopLevelItem(itm);
    return itm;
}


void MainWindow::closeDisplay()
{
    ui->todoNameLineEdit->clear();
    ui->todoNameLineEdit->setDisabled(true);

    ui->todoDescriptionTextEdit->clear();
    ui->todoDescriptionTextEdit->setDisabled(true);

    ui->todoDonecheckBox->setDisabled(true);
}

void MainWindow::openDisplay()
{
    ui->todoNameLineEdit->clear();
    ui->todoNameLineEdit->setDisabled(false);

    ui->todoDescriptionTextEdit->clear();
    ui->todoDescriptionTextEdit->setDisabled(false);

    ui->todoDonecheckBox->setDisabled(false);
}


void MainWindow::on_todoList_itemClicked(QTreeWidgetItem *item, int column)
{
    SQLTODO *todoInfo = todo->getFullTodoInfo(item->text(0).toInt());
    openDisplay();

    qInfo() << todoInfo->id;

    ui->todoNameLineEdit->setText(todoInfo->name);

    ui->todoDescriptionTextEdit->setPlainText(todoInfo->description);
    ui->todoDonecheckBox->setChecked(todoInfo->done);


}


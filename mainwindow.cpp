#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    todo = new todoManager();

    ui->todoList->setColumnCount(2);

    updateTodoList();

    closeDisplay();



    /*connect(ui->actionNewGroup, SIGNAL(triggered(bool)), todo, SLOT(test(void)));
    connect(ui->actionnew, SIGNAL(triggered(bool)), todo, SLOT(test(void)));


    connect(ui->actionDelete, SIGNAL(triggered(bool)), this, SLOT(closeDisplay()));*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

QTreeWidgetItem *MainWindow::addTaskQTreeWidget(int id, QString name, QTreeWidgetItem *group)
{
    if (group == nullptr) {
        QTreeWidgetItem *itm = new QTreeWidgetItem(ui->todoList);
        itm->setText(0, QString::number(id));
        itm->setText(1, name);
        return itm;
    } else {
        QTreeWidgetItem *itm = new QTreeWidgetItem();
        itm->setText(0, QString::number(id));
        itm->setText(1, name);
        group->addChild(itm);
        return itm;
    }
}

QTreeWidgetItem *MainWindow::addGroupQTreeWidget(int id, QString name)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->todoList);

    itm->setText(0, name);
    itm->setText(1, QString::number(id));

    ui->todoList->addTopLevelItem(itm);
    return itm;
}

void MainWindow::updateTodoList(void)
{
    ui->todoList->clear();
    QList<SQLTODO> allTodos = todo->getAllTodosFromDB();

    for (int i = 0; i < allTodos.size(); i++) {
        SQLTODO todo = allTodos.at(i);
        addTaskQTreeWidget(todo.id, todo.name);
    }
}


void MainWindow::closeDisplay(void)
{
    ui->todoNameLineEdit->clear();
    ui->todoNameLineEdit->setDisabled(true);

    ui->todoDescriptionTextEdit->clear();
    ui->todoDescriptionTextEdit->setDisabled(true);

    ui->todoDonecheckBox->setCheckState(Qt::CheckState(0));
    ui->todoDonecheckBox->setDisabled(true);

    ui->actionDelete->setDisabled(true);
    ui->actionSaveTodo->setDisabled(true);
}

void MainWindow::openDisplay(void)
{
    ui->todoNameLineEdit->clear();
    ui->todoNameLineEdit->setDisabled(false);

    ui->todoDescriptionTextEdit->clear();
    ui->todoDescriptionTextEdit->setDisabled(false);

    ui->todoDonecheckBox->setDisabled(false);

    ui->actionDelete->setDisabled(false);
    ui->actionSaveTodo->setDisabled(false);
}

void MainWindow::displayCurrentTodo()
{
    ui->todoNameLineEdit->setText(currentTodoDisplayed.name);

    ui->todoDescriptionTextEdit->setPlainText(currentTodoDisplayed.description);
    ui->todoDonecheckBox->setChecked(currentTodoDisplayed.done);
}


void MainWindow::on_todoList_itemClicked(QTreeWidgetItem *item, int column)
{
    // IF USER CLICKES TODO
    currentTodoDisplayed = todo->getTodoFromDB(item->text(0).toInt());

    openDisplay();
    displayCurrentTodo();
}


void MainWindow::on_actionDelete_triggered()
{
    QTreeWidgetItem *item = ui->todoList->selectedItems()[0];

    todo->deleteTodoToDB(item->text(0).toInt());

    closeDisplay();
    updateTodoList();
}


void MainWindow::on_actionNew_triggered()
{
    currentTodoDisplayed = SQLTODO();
    closeDisplay();
    openDisplay();

    displayCurrentTodo();
}


void MainWindow::on_actionSaveTodo_triggered()
{
    currentTodoDisplayed.name = ui->todoNameLineEdit->text();
    currentTodoDisplayed.description = ui->todoDescriptionTextEdit->toPlainText();
    currentTodoDisplayed.done = ui->todoDonecheckBox->checkState();

    closeDisplay();
    todo->addTodoToDB(currentTodoDisplayed);
    updateTodoList();
}


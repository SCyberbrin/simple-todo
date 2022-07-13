#include "todomanager.h"

#include <QDebug>
todoManager::todoManager(QTreeWidget *treeWid, QObject *parent)
: QObject{parent}
{
    TreeWid = treeWid;
}


QTreeWidgetItem *todoManager::addTask(QString name, QString description, QTreeWidgetItem *group)
{
    if (group == nullptr) {
        QTreeWidgetItem *itm = new QTreeWidgetItem(TreeWid);
        itm->setText(0, name);
        itm->setText(1, description);
        return itm;
    } else {
        QTreeWidgetItem *itm = new QTreeWidgetItem();
        itm->setText(0, name);
        itm->setText(1, description);
        group->addChild(itm);
        return itm;
    }
}

QTreeWidgetItem *todoManager::addGroup(QString name, QString description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(TreeWid);

    itm->setText(0, name);
    itm->setText(1, description);

    TreeWid->addTopLevelItem(itm);
    return itm;
}

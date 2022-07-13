#ifndef TODOMANAGER_H
#define TODOMANAGER_H

#include <QtWidgets>
#include <QObject>

class todoManager : public QObject
{
    Q_OBJECT
public:
    explicit todoManager(QTreeWidget *treeWid, QObject *parent = nullptr);
    QTreeWidgetItem *addTask(QString name, QString description, QTreeWidgetItem *group = nullptr);
    QTreeWidgetItem *addGroup(QString name, QString description);

private:
    QTreeWidget *TreeWid;

signals:

};

#endif // TODOMANAGER_H

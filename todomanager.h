#ifndef TODOMANAGER_H
#define TODOMANAGER_H

#include <QtWidgets>
#include <QObject>

class todoManager : public QObject
{
    Q_OBJECT
public:
    explicit todoManager(QObject *parent = nullptr, QTreeWidget *treeWid = nullptr);


signals:

};

#endif // TODOMANAGER_H

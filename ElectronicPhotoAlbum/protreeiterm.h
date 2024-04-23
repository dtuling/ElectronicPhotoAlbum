#ifndef PROTREEITERM_H
#define PROTREEITERM_H

#include <QTreeWidgetItem>
#include <QTreeWidget>
class ProTreeIterm : public QTreeWidgetItem
{
public:
    //重写构造函
    ProTreeIterm(QTreeWidget *treeview, const QString &name,const QString & path, int type = Type);
    ProTreeIterm(QTreeWidgetItem *parent, const QString &name,const QString & path, QTreeWidgetItem* root,int type = Type);

};

#endif // PROTREEITERM_H

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

    const QString & GetPath();
    QTreeWidgetItem* GetRoot();
    void SetPreItem(QTreeWidgetItem* item);
    void SetNextItem(QTreeWidgetItem* item);
    ProTreeIterm* GetPreItem();
    ProTreeIterm* GetNextItem();
    ProTreeIterm* GetLastPicChid();
    ProTreeIterm* GetFirstPicChid();
private:
    QString _path;
    QString _name;
    QTreeWidgetItem* _root;
    QTreeWidgetItem* _pre_item;
    QTreeWidgetItem* _next_item;


};

#endif // PROTREEITERM_H

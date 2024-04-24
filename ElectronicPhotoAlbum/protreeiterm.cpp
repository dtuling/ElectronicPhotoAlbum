#include "protreeiterm.h"


ProTreeIterm::ProTreeIterm(QTreeWidget *view, const QString &name,
                           const QString &path, int type)
    :QTreeWidgetItem(view,type)
    ,_path(path)
    ,_root(this)
    ,_pre_item(nullptr)
    ,_next_item(nullptr)
    ,_name(name)
{

}

ProTreeIterm::ProTreeIterm(QTreeWidgetItem *parent, const QString &name, const QString &path,
                           QTreeWidgetItem *root, int type)
    :QTreeWidgetItem(parent,type)
    ,_path(path)
    ,_root(root)
    ,_pre_item(nullptr)
    ,_next_item(nullptr)
    ,_name(name)

{

}

const QString &ProTreeIterm::GetPath()
{
    return _path;
}

QTreeWidgetItem *ProTreeIterm::GetRoot()
{
    return _root;
}

void ProTreeIterm::SetPreItem(QTreeWidgetItem *item)
{
    _pre_item = item;
}

void ProTreeIterm::SetNextItem(QTreeWidgetItem *item)
{
    _next_item = item;
}

ProTreeIterm *ProTreeIterm::GetPreItem()
{
    return dynamic_cast<ProTreeIterm*>(_pre_item);//父类转子类  需要类型转化
}

ProTreeIterm *ProTreeIterm::GetNextItem()
{
    return dynamic_cast<ProTreeIterm*>(_next_item);
}

ProTreeIterm *ProTreeIterm::GetLastPicChid()
{
    return nullptr;
}

ProTreeIterm *ProTreeIterm::GetFirstPicChid()
{
    return nullptr;
}

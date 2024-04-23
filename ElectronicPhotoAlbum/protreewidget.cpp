#include "protreewidget.h"
#include <QDir>
#include "protreeiterm.h"
#include "const.h"

ProTreeWidget::ProTreeWidget(QWidget *parent)
{

}

void ProTreeWidget::AddProToTree(const QString &name, const QString &path)
{
    QDir dir(path);
    QString file_path = dir.absoluteFilePath(name);
    if(_set_path.find(file_path) != _set_path.end())
    {
        return;
    }

    QDir pro_dir(file_path);
    if(!pro_dir.exists()){
        bool enable = pro_dir.mkpath(file_path);
        if(!enable)
        {
            return;
        }
    }
    _set_path.insert(file_path);

    auto * item = new ProTreeIterm(this,name,file_path,TreeItemPro);
    item->setData(0,Qt::DisplayRole,name);
    item->setData(0,Qt::DecorationRole,QIcon(":/icon/dir.png"));
    item->setData(0,Qt::ToolTipRole,file_path);


}

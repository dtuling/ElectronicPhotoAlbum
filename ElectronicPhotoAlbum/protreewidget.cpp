#include "protreewidget.h"
#include <QDir>
#include "protreeiterm.h"
#include "const.h"
#include <QHeaderView>
#include <QGuiApplication>
#include <QMenu>
#include <QFileDialog>
#include <QDebug>
ProTreeWidget::ProTreeWidget(QWidget *parent)
{
    this->header()->hide();

    connect(this,&ProTreeWidget::itemPressed,this,&ProTreeWidget::SlotItemPressed);
    _action_import = new QAction(QIcon(":/icon/import.png"),"导入文件",this);
    _action_setstart = new QAction(QIcon(":/icon/core.png"),"设置活动项目",this);
    _action_closepro = new QAction(QIcon(":/icon/close.png"),"关闭项目",this);
    _action_slideshow = new QAction(QIcon(":/icon/slideshow.png"),"轮播图\n播放",this);

    connect(_action_import,&QAction::triggered,this,&ProTreeWidget::SlotImport);
}

void ProTreeWidget::AddProToTree(const QString &name, const QString &path)
{
    qDebug() << "ADDPROTOTREE";
    QDir dir(path);
    QString file_path = dir.absoluteFilePath(name);
    //检测重名，判断路径和名字都一样则拒绝加入
    if(_set_path.find(file_path) != _set_path.end())
    {
        return;
    }
    //构造项目用的文件夹
    QDir pro_dir(file_path);
    //如果文件夹不存在则创建
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
    //显示在树形视图的顶层
    this->addTopLevelItem(item);
}

void ProTreeWidget::SlotItemPressed(QTreeWidgetItem *pressedItem, int colum)
{
    //可以设置提示 点击右键
    //右键被点击
    if(QGuiApplication::mouseButtons() == Qt::RightButton)
    {
        QMenu *menu  = new QMenu(this);

        int itemtype = pressedItem->type();
        if(itemtype == TreeItemPro)
        {
            _right_btn_item = pressedItem;
            menu->addAction(_action_import);
            menu->addAction(_action_closepro);
            menu->addAction(_action_setstart);
            menu->addAction(_action_slideshow);
            menu->exec(QCursor::pos());//显示的位置就是鼠标点击的位置
        }
    }
}
//导入文件
void ProTreeWidget::SlotImport()
{

    QFileDialog file_dialog(this);

    file_dialog.setFileMode(QFileDialog::Directory);
    file_dialog.setWindowTitle("选择导入的文件夹");
    file_dialog.exec();
    QString path = "";
    if(_right_btn_item)
    {
        qDebug() << "_rigjht_btn_item is empty";
        return;
    }
    //获取路径
    path = dynamic_cast<ProTreeIterm*>(_right_btn_item)->GetPath();
    file_dialog.setDirectory(path);
    file_dialog.setViewMode(QFileDialog::Detail);
    qDebug() << "path = " << path << endl;
    QStringList fileNames;
    if(file_dialog.exec())
    {
        fileNames = file_dialog.selectedFiles();
    }

    if(fileNames.length() <= 0)
    {
        return ;
    }

    QString import_path = fileNames.at(0);
    int file_count = 0;

    //模态对话框
    _dialog_progress = new QProgressDialog(this);
    _dialog_progress->setWindowTitle("秋迪玛黛");
    _dialog_progress->setFixedWidth(PROGRESS_WIDTH);
    _dialog_progress->setRange(0,PROGRESS_WIDTH);
    _dialog_progress->exec();


}

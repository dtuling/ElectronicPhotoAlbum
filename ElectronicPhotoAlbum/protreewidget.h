#ifndef PROTREEWIDGET_H
#define PROTREEWIDGET_H
//树形结构
#include <QTreeWidget>
#include <QAction>
#include <QProgressDialog>
class ProTreeWidget : public QTreeWidget
{
public:
    ProTreeWidget(QWidget *parent = nullptr);
    void AddProToTree(const QString& name,const QString& path);
private:
    QSet<QString> _set_path;
    //右键单击某个item之后弹出菜单
    QTreeWidgetItem* _right_btn_item;
    QAction* _action_import;
    QAction* _action_setstart;
    QAction* _action_closepro;
    QAction* _action_slideshow;//轮播图播放

    QProgressDialog* _dialog_progress;
private slots:
    void SlotItemPressed(QTreeWidgetItem* item,int colum);
    void SlotImport();
};

#endif // PROTREEWIDGET_H

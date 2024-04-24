#include "protree.h"
#include "ui_protree.h"
//项目目录树
ProTree::ProTree(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProTree)
{
    ui->setupUi(this);
    setMinimumWidth(378);
    setMaximumWidth(378);
}

ProTree::~ProTree()
{
    delete ui;
}

void ProTree::AddProToTree(const QString &name, const QString &path)
{
    ui->treeWidget->AddProToTree(name,path);



}

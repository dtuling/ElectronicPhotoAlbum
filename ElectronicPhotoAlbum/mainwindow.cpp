#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wizard.h"
#include "protree.h"

#include <QMenu>
#include <QAction>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建菜单
    QMenu* menu_file = menuBar()->addMenu(tr("文件(&F)"));

    //创建项目子菜单
    QAction* act_create_pro = new QAction(QIcon(":/icon/createpro.png"),tr("创建项目"),this);
    //绑定快捷键
    act_create_pro->setShortcut((QKeySequence(Qt::CTRL + Qt::Key_N)));
    menu_file->addAction(act_create_pro);

    //打开项目子菜单
    QAction* act_open_pro = new QAction(QIcon(":/icon/openpro.png"),tr("打开项目"),this);
    act_open_pro->setShortcut((QKeySequence(Qt::CTRL + Qt::Key_O)));
    menu_file->addAction(act_open_pro);

    //创建设置菜单
    QMenu* menu_set = menuBar()->addMenu(tr("设置(&S)"));//ALT + S 就可以选中
    //设置背景音乐子菜单
    QAction* act_music = new QAction(QIcon(":/icon/music.png"),tr("设置音乐"),this);
    act_music->setShortcut((QKeySequence(Qt::CTRL + Qt::Key_M)));
    menu_set->addAction(act_music);

    //连接信号和槽
    connect(act_create_pro,&QAction::triggered,this,&MainWindow::SloatCreatePro);

    //加载protree
    _protree = new ProTree();
    ui->proyLayout->addWidget(_protree);
}

void MainWindow::SloatCreatePro(bool)
{
    qDebug() << "SLOT CREATE PRO TRIGGERED" ;
    Wizard wizard(this);
    wizard.setWindowTitle(tr("创建项目"));
    auto * page = wizard.page(0);
    page->setTitle(tr("设置项目配置"));

    connect(&wizard,&Wizard::SigProSettings,dynamic_cast<ProTree*>(_protree),&ProTree::AddProToTree);

    wizard.show();
    wizard.exec();


}


MainWindow::~MainWindow()
{
    delete ui;
}



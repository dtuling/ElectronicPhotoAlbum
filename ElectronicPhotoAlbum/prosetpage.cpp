#include "prosetpage.h"
#include "ui_prosetpage.h"
#include <QLineEdit>
#include <QDir>
#include <QFileDialog>
ProSetPage::ProSetPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::ProSetPage)
{
    ui->setupUi(this);
    registerField("proPath",ui->lineEdit_2);
    registerField("proName",ui->lineEdit);

    connect(ui->lineEdit,&QLineEdit::textEdited,this,&ProSetPage::completeChanged);
    connect(ui->lineEdit_2,&QLineEdit::textEdited,this,&ProSetPage::completeChanged);

    QString curPath = QDir::currentPath();
    //设置光标
    ui->lineEdit_2->setText(curPath);
    ui->lineEdit_2->setCursorPosition(ui->lineEdit_2->text().size());
    //一键清楚lineEdit框的文字
    ui->lineEdit_2->setClearButtonEnabled(true);
    ui->lineEdit->setClearButtonEnabled(true);
}

ProSetPage::~ProSetPage()
{
    delete ui;
}

void ProSetPage::GetProSettings(QString &name, QString &path)
{
    name = ui->lineEdit->text();
    path = ui->lineEdit_2->text();
}

bool ProSetPage::isComplete() const
{
    if(ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "")
    {
        return false;
    }
    QDir dir(ui->lineEdit_2->text());
    if(!dir.exists())
    {
        ui->tips->setText("projext path is not exists");
        return false;
    }
    //判断路径
    QString absFilePath = dir.absoluteFilePath(ui->lineEdit->text());
    QDir dist_dir(absFilePath);
    //不存在  提示路径不存在
    if(dist_dir.exists())
    {
        ui->tips->setText("paoject has exists,change path or name");
        return false;
    }

    ui->tips->setText("");
    return QWizardPage::isComplete();
}

//browse槽函数
void ProSetPage::on_pushButton_clicked()
{
    QFileDialog file_dialog;
    file_dialog.setFileMode(QFileDialog::Directory);
    file_dialog.setWindowTitle("选择导入的文件夹");
    auto path = QDir::currentPath();
    file_dialog.setDirectory(path);
    file_dialog.setViewMode(QFileDialog::Detail);

    QStringList fileNames;
    if(file_dialog.exec())
    {
        fileNames = file_dialog.selectedFiles();
    }

    if(fileNames.length() <= 0)
    {
        return;
    }

    QString import_path = fileNames.at(0);
    ui->lineEdit_2->setText(import_path);

}

#include "confimpage.h"
#include "ui_confimpage.h"

ConfimPage::ConfimPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::ConfimPage)
{
    ui->setupUi(this);
}

ConfimPage::~ConfimPage()
{
    delete ui;
}

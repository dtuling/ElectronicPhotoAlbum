#ifndef CONFIMPAGE_H
#define CONFIMPAGE_H

#include <QWizardPage>

namespace Ui {
class ConfimPage;
}

class ConfimPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit ConfimPage(QWidget *parent = nullptr);
    ~ConfimPage();

private:
    Ui::ConfimPage *ui;
};

#endif // CONFIMPAGE_H

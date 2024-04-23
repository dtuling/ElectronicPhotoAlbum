#ifndef PROSETPAGE_H
#define PROSETPAGE_H

#include <QWizardPage>
//向导框
namespace Ui {
class ProSetPage;
}

class ProSetPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit ProSetPage(QWidget *parent = nullptr);
    ~ProSetPage();
    void GetProSettings(QString& name,QString & path);
protected:
    virtual bool isComplete() const override;
private slots:
    void on_pushButton_clicked();

private:
    Ui::ProSetPage *ui;
};

#endif // PROSETPAGE_H

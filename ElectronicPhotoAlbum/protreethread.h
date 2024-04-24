#ifndef PROTREETHREAD_H
#define PROTREETHREAD_H
#include <QThread>
#include <QTreeWidgetItem>
#include <QTreeWidget>
class ProTreeThread : public QThread
{
    Q_OBJECT
public:
    ProTreeThread(const QString& src_path, const QString& dist_path, QTreeWidgetItem* parent_item,
                  int file_count, QTreeWidget* self,QTreeWidgetItem* root,QObject* parent = nullptr);
    ~ProTreeThread();
protected:
    virtual void run(); //线程入口函数
private:
    void CreateProTree(const QString& src_path, const QString& dist_path,QTreeWidgetItem* parent_iter,
                       int& file_count,QTreeWidget* self,QTreeWidgetItem* root,QTreeWidgetItem* preitem);

signals:
    void SigUpdataProgress(int);
    void SigFinishProgress(int);


private:

    QString _src_path;
    QString _dist_path;
    int _file_count;
    QTreeWidgetItem* _parent_item;
    QTreeWidget* _self;
    QTreeWidgetItem* _root;
    bool _bstop;

};

#endif // PROTREETHREAD_H

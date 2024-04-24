#include "protreethread.h"
#include <QDir>
#include "protreeiterm.h"

ProTreeThread::ProTreeThread(const QString &src_path,
                             const QString &dist_path,
                             QTreeWidgetItem *parent_item,
                             int file_count, QTreeWidget *self,
                             QTreeWidgetItem *root,
                             QObject *parent)
    :QThread(parent),_src_path(src_path),_dist_path(dist_path),_file_count(file_count),_parent_item(parent_item),_self(self),_root(root),_bstop(false)

{

}

ProTreeThread::~ProTreeThread()
{

}

void ProTreeThread::run()
{

}

void ProTreeThread::CreateProTree(const QString &src_path, const QString &dist_path, QTreeWidgetItem *parent_iter, int &file_count, QTreeWidget *self, QTreeWidgetItem *root, QTreeWidgetItem *preitem)
{
    if(_bstop){
        return;
    }

    bool needcopy = true;
    if(src_path == dist_path)
    {
        needcopy = false;
    }

    QDir import_dir(src_path);
    QStringList nameFilters;
    import_dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    import_dir.setSorting(QDir::Name);
    QFileInfoList list = import_dir.entryInfoList();

    for(int i = 0; i < list.size(); ++i)
    {
        if(_bstop)
        {
            return;
        }

        QFileInfo fileInfo = list.at(i);
        bool bIsDir = fileInfo.isDir();
        //是否为目录
        if(bIsDir)
        {

        }
        else
        {
            if(_bstop)
            {
                return;
            }
            const QString& suffix = fileInfo.completeSuffix();
            if(suffix != "png" && suffix != "jpeg" && suffix != "jpg")
            {
                continue;
            }
            file_count++;
            emit SigUpdataProgress(file_count);
            if(!needcopy)
            {
                continue;
            }
            QDir dist_dir(dist_path);
            QString dist_file_path = dist_dir.absoluteFilePath(fileInfo.fileName());

            if(!QFile::copy(fileInfo.absoluteFilePath(),dist_file_path))
            {
                continue;
            }
            auto* item = new ProTreeIterm(parent_iter,fileInfo.fileName(),);
        }
     }




}

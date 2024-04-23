#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //加载Qss
    QFile qss(":/style/style.qss");
    if(qss.open(QFile::ReadOnly))
    {
        qDebug() << "open qss success" ;
        QString  style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
     }
    else
    {
        qDebug() << "open fail";
    }


    MainWindow w;
    w.setWindowTitle("Album");
    //默认最大化
    w.showMaximized();
    //w.show();
    return a.exec();
}

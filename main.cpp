#include <QCoreApplication>
#include <LoadInfo.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    LoadPCInfo pc;
    //    QD("SystemProductName"<<pc.SystemProductName);
    //    QD("BaseBoardProduct"<<pc.BaseBoardProduct);
    //    QD("BaseBoardVersion"<<pc.BaseBoardVersion);
    //    QD("SystemSKU"<<pc.SystemProductName);
    return a.exec();
}

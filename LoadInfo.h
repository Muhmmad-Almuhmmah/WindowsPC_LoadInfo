/**
 * Auther/Developed By Muhammad Almuhmmah
 * Githup : https://github.com/Muhmmad-Almuhmmah
 * Telegram : https://t.me/XDevYE
 * Facebook : https://www.facebook.com/X.Dev.Ye
 * #   			  © 2018-2022  			    #
 * **/

#ifndef LOADINFO_H
#define LOADINFO_H

#include <QStringList>
#include <QSettings>
#include <QDebug>
#define QD(X) qDebug() <<X;
#define GetDefineName(var) #var
#define GetNameWithPtr(var) #var,&var
typedef struct item{
    item(QString name,QString *ptr){
        Name=name;
        Pointer=ptr;
    }
    QString Name;
    QString *Pointer;
}InfoItem;
class LoadPCInfo
{
    QList<InfoItem> list;
public:
    LoadPCInfo() {
        // init dirs registry
        list<<InfoItem(GetNameWithPtr(SystemProductName));
        list<<InfoItem(GetNameWithPtr(SystemManufacturer));
        list<<InfoItem(GetNameWithPtr(SystemSKU));
        list<<InfoItem(GetNameWithPtr(SystemFamily));
        list<<InfoItem(GetNameWithPtr(BaseBoardManufacturer));
        list<<InfoItem(GetNameWithPtr(BaseBoardProduct));
        list<<InfoItem(GetNameWithPtr(BaseBoardVersion));
        list<<InfoItem(GetNameWithPtr(BIOSReleaseDate));
        list<<InfoItem(GetNameWithPtr(BIOSVendor));
        list<<InfoItem(GetNameWithPtr(BIOSVersion));

        list<<InfoItem(GetNameWithPtr(Identifier));
        list<<InfoItem(GetNameWithPtr(ProcessorNameString));
        list<<InfoItem(GetNameWithPtr(VendorIdentifier));


        list<<InfoItem(GetNameWithPtr(ProductName));
        list<<InfoItem(GetNameWithPtr(CurrentBuild));
        list<<InfoItem(GetNameWithPtr(ReleaseId));
        list<<InfoItem(GetNameWithPtr(CurrentType));
        list<<InfoItem(GetNameWithPtr(EditionID));
        list<<InfoItem(GetNameWithPtr(DisplayVersion));
        list<<InfoItem(GetNameWithPtr(CurrentVersion));
        list<<InfoItem(GetNameWithPtr(CompositionEditionID));
        list<<InfoItem(GetNameWithPtr(RegisteredOwner));
        list<<InfoItem(GetNameWithPtr(EditionID));

        QSettings Reg_DirBios(R"(HKEY_LOCAL_MACHINE\HARDWARE\DESCRIPTION\System\BIOS)",QSettings::NativeFormat),
                Reg_DirSysInfo(R"(HKEY_LOCAL_MACHINE\SYSTEM\ControlSet001\Control\SystemInformation)",QSettings::NativeFormat),
                RegDirCpu(R"(HKEY_LOCAL_MACHINE\HARDWARE\DESCRIPTION\System\CentralProcessor\0)",QSettings::NativeFormat),
                RegDirCurrentVersion(R"(HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion)",QSettings::NativeFormat);
        InitRegistryInfo(Reg_DirBios);
        InitRegistryInfo(RegDirCurrentVersion);
        InitRegistryInfo(Reg_DirSysInfo);
        InitRegistryInfo(RegDirCpu);
    }
    void InitRegistryInfo(QSettings &RegDir){
        QVariant variant;
        foreach(InfoItem item,list)
        {
            variant=RegDir.value(item.Name);
            if(variant.isValid() && !variant.toString().isEmpty() && item.Pointer->isEmpty()){
                *item.Pointer=variant.toString();
                qDebug() << item.Name<<*item.Pointer;
            }
        }
    }
    QString BaseBoardManufacturer,BaseBoardProduct,BaseBoardVersion,SystemSKU,
    BIOSReleaseDate,BIOSVendor,BIOSVersion,SystemFamily,SystemManufacturer,SystemProductName,
    Identifier,ProcessorNameString,VendorIdentifier,
    CurrentBuild,CompositionEditionID,EditionID,CurrentVersion,CurrentType,
    ProductName,ReleaseId,DisplayVersion,RegisteredOwner;
};

#endif // LOADINFO_H

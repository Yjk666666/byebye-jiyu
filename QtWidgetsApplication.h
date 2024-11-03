#pragma once
#include <QtWidgets/QWidget>
#include<qlabel.h>
#include<qpushbutton.h>
#include<qlineedit.h>
#include<qlayout.h>
#include<qfile.h>
#include<qfiledialog.h>
#include<qdebug.h>
#include "other.h"
#include<QDesktopServices>
#include <QProcess>
#include<qbytearray.h>
#include<qsettings.h>
#include<qtextstream.h>
#define $GET$  "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System"
#define $$PATH$$ "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\"
class QtWidgetsApplication : public QWidget
{
    Q_OBJECT
public slots:
    void checkpath()
    { 
        QString nowpath;
        nowpath = $GET$;

        read = new QFile("where.txt");
        write = new QFile("KJF.bat");
        if (read->open(QIODevice::ReadWrite))
        {
            if (write->open(QIODevice::Truncate|QIODevice::ReadWrite))
            {
                QTextStream in(read);
                QTextStream out(write);
                while (!in.atEnd()) {
                    QString line = in.readLine();
                    out << "del /f " << line << "\n";
                }
            }
        }
        QSettings* resumreg= new QSettings(nowpath, QSettings::NativeFormat);
        resumreg->setValue("DisableRegistryTools", 0);
        //Warning->setText("path="+nowpath+",debugger="+ rt->value("debugger").toString());
        delete resumreg;
        QSettings* resumcmd = new QSettings("HKEY_CURRENT_USER\\Software\\Policies\\Microsoft\\Windows\\System",QSettings::NativeFormat);
        resumcmd->setValue("DisableCMD", 0);
        delete resumcmd;

       QString s = "zmserv.exe";
        nowpath=$$PATH$$+s;
        QSettings* delzmserv = new QSettings(nowpath, QSettings::NativeFormat);
        delzmserv->setValue("debugger", "KJF.bat");
        delete delzmserv;

        s = "jfglzs.exe";
        nowpath = $$PATH$$ + s;
        QSettings *deljy=new QSettings(nowpath,QSettings::NativeFormat);
        deljy->setValue("debugger", "KJF.bat");
        delete deljy;

        s = "srvany.exe";
        nowpath = $$PATH$$ + s;
        QSettings* delsv = new QSettings(nowpath, QSettings::NativeFormat);
        delsv->setValue("debugger", "KJF.bat");
        delete delsv;

        s = "StudentMain.exe";
        nowpath = $$PATH$$ + s;
        QSettings* delstu = new QSettings(nowpath, QSettings::NativeFormat);
        delstu->setValue("debugger", "KJF.bat");
        delete delstu;

        s = "shutdown.exe";
        nowpath = $$PATH$$ + s;
        QSettings* deloff = new QSettings(nowpath, QSettings::NativeFormat);
        deloff->setValue("debugger", "KJF.bat");
        delete deloff;

        s = "przs.exe";
        nowpath = $$PATH$$ + s;
        QSettings* delps = new QSettings(nowpath, QSettings::NativeFormat);
        delps->setValue("debugger", "KJF.bat");
        delete delps;

        s = "regini.exe";
        nowpath = $$PATH$$ + s;
        QSettings* delregg = new QSettings(nowpath, QSettings::NativeFormat);
        delregg->setValue("debugger", "KJF.bat");
        delete delregg;

        s = "instsrv.exe";
        nowpath = $$PATH$$ + s;
        QSettings* delins = new QSettings(nowpath, QSettings::NativeFormat);
        delins->setValue("debugger", "KJF.bat");
        delete delins;
    }
public:
    QtWidgetsApplication(QWidget *parent = nullptr);
    ~QtWidgetsApplication();
private:
    QPushButton* confirm;
    QFile* read;
    QFile* write;
    QLabel* Warning,*sm;
}; 

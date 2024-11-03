#include "QtWidgetsApplication.h"
#include <QtWidgets/QApplication>
#include<string>
#include<iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWidgetsApplication w;
    w.show();
    return a.exec();
	return 0;
}

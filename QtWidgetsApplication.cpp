#include "QtWidgetsApplication.h"
#include <QTextStream>
QtWidgetsApplication::QtWidgetsApplication(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("拜拜极域v1.0");
    
    QVBoxLayout* mainout = new QVBoxLayout;
    //new
    confirm = new QPushButton("拜拜极域启动确认");
    sm = new QLabel("请在主文件夹下where.txt内输入文件位置:\n第一行：极域文件夹位置\n第二行:机房管理文件夹位置\n注意不要有任何空行!!!");
    
    Warning = new QLabel();
    connect(confirm, SIGNAL(clicked(bool)), this, SLOT(checkpath(void)));

    //add
    mainout->addWidget(sm);
    mainout->addWidget(confirm);
    this->setLayout(mainout);
}

QtWidgetsApplication::~QtWidgetsApplication()
{
    
}

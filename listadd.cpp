#include "listadd.h"
#include "ui_listadd.h"

ListAdd::ListAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListAdd)
{
    ui->setupUi(this);
}

ListAdd::~ListAdd()
{
    delete ui;
}
// 初始化
void ListAdd::initValue()
{
    // 创建系统托盘
    syetemTray = new SystemTray(this);
    connect(syetemTray->getShowWidget(), SIGNAL(triggered(bool)), this, SLOT(showNormal()));
    connect(syetemTray->getMinWidget(), SIGNAL(triggered(bool)), this, SLOT(showMinimized()));
    //ui->widgetTitle->setParentWidget(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    // 将TreeWidget点击的index与TabWidget页面显示的index相互绑定
    //connect(ui->widgetTree, SIGNAL(sendShowIndex(WidgetTabType)), ui->widgetTab, SLOT(receiveShowCurrentTab(WidgetTabType)));

}

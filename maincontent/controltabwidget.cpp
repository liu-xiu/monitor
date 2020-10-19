/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：界面右侧的TabWidget，显示当前已有的
 * 页面，与TreeWidget相对应
 * ***************************************/
#include "controltabwidget.h"
#include "ui_controltabwidget.h"
#include <QDialog>
#include <globaldef.hpp>
#include <QApplication>
#include <QMessageBox>

/******************   构造函数     *********************/
ControlTabWidget::ControlTabWidget(QWidget *parent) :
    QWidget(parent)
{
    ui = new Ui::ControlTabWidget;
    ui->setupUi(this);
    this->initValue();
}

/******************   析构函数     *********************/
ControlTabWidget::~ControlTabWidget()
{
    delete ui;
}

/******************   初始化数据     *********************/
void ControlTabWidget::initValue()
{
    //隐藏tabbar
    /*柳秀*/
    //ui->tabWidgetControl->tabBar()->setHidden(true);//隐藏上面选项卡
    ui->tabWidgetControl->tabBar()->setTabsClosable(true);//选项卡显示
    //移除部分没有用的选项卡
    ui->tabWidgetControl->removeTab(2);
    ui->tabWidgetControl->removeTab(2);
    ui->tabWidgetControl->removeTab(2);
    ui->tabWidgetControl->removeTab(2);
    ui->tabWidgetControl->removeTab(2);
    ui->tabWidgetControl->removeTab(2);
    ui->tabWidgetControl->removeTab(2);
    //设置界面颜色
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(30, 30, 30));
    ui->tabWidgetControl->setAutoFillBackground(true);//背景透明
    ui->tabWidgetControl->setPalette(palette);
    ui->tabWidgetControl->tabBar()->setPalette(palette);

   // {
   //     TabWidgetData tabWidgetData;
    //    tabWidgetData.currentWidget = ui->tabBanna;
   //     tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_BANNA);
    //    mapTabWidget[TAB_BANNA] = tabWidgetData;
   // }

//    {
//        TabWidgetData tabWidgetData;
//        tabWidgetData.currentWidget = ui->tabCylinder;
//        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_CYLINDER);
//        mapTabWidget[TAB_CYLINDER] = tabWidgetData;
//    }

//    {
//        TabWidgetData tabWidgetData;
//        tabWidgetData.currentWidget = ui->tabProgress;
//        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_PROGRESS);
//        mapTabWidget[TAB_PROGRESS] = tabWidgetData;
//    }
    //面板
    {
        TabWidgetData tabWidgetData;
        tabWidgetData.currentWidget = ui->tabFrame;
        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_FRAME);
        mapTabWidget[TAB_FRAME] = tabWidgetData;
        ui->tabWidgetControl->setCurrentWidget(tabWidgetData.currentWidget);
    }

//    {
//        TabWidgetData tabWidgetData;
//        tabWidgetData.currentWidget = ui->tabPlot;
//        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_CUSTOM_PLOT);
//        mapTabWidget[TAB_CUSTOM_PLOT] = tabWidgetData;
//    }

//    {
//        TabWidgetData tabWidgetData;
//        tabWidgetData.currentWidget = ui->tabMoveButton;
//        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_MOVE_BUTTON);
//        mapTabWidget[TAB_MOVE_BUTTON] = tabWidgetData;
//    }
    //表格
    {
        TabWidgetData tabWidgetData;
        tabWidgetData.currentWidget = ui->tabTableWidget;
        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_TABLE_WIDGET);
        mapTabWidget[TAB_TABLE_WIDGET] = tabWidgetData;
    }


//    {
//        TabWidgetData tabWidgetData;
//        tabWidgetData.currentWidget = ui->tabSlider;
//        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_SLIDER);
//        mapTabWidget[TAB_SLIDER] = tabWidgetData;
//    }

//    {
//        TabWidgetData tabWidgetData;
//        tabWidgetData.currentWidget = ui->tabOpengl;
//        tabWidgetData.currentTabText = ui->tabWidgetControl->tabText(TAB_OPENGL);
//        mapTabWidget[TAB_OPENGL] = tabWidgetData;
//    }
}

/******************   点击树形项显示对应Tab页     *********************/
void ControlTabWidget::receiveShowCurrentTab(WidgetTabType widgetTabType)
{
    if(widgetTabType >= TAB_MAX) return;
    TabWidgetData tabWidgetData = mapTabWidget.value(widgetTabType);
    if (ui->tabWidgetControl->indexOf(tabWidgetData.currentWidget) < 0) {
        ui->tabWidgetControl->addTab(tabWidgetData.currentWidget, tabWidgetData.currentTabText);
    }
    ui->tabWidgetControl->setCurrentWidget(tabWidgetData.currentWidget);
}


void ControlTabWidget::on_pBn_Add_clicked()
{
  //  ListAdd list;
  //  list.showNormal();

    //list=new Ui::ListAdd();
   // list->show();
    //listadd* new ListAdd(this);
   //ListAdd listadd;
   // listadd.showNormal();
  // QMessageBox::warning(0,QObject::tr("提示"),"对方拒绝接收！");
}

void ControlTabWidget::on_pBn_Search_clicked()
{
   //
}

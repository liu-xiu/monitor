/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：表格窗口
 * ***************************************/
#include "tablewidget.h"
#include "ui_tablewidget.h"
#include "tablecontrol.h"
#include <QTextStream>
#include "ui_tablecontrol.h"
#include <QMessageBox>
#include <QDesktopWidget>

// 构造函数
TableWidget::TableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableWidget)
{
    ui->setupUi(this);
    this->initValue();
}

// 析构函数
TableWidget::~TableWidget()
{
    delete ui;
}

// 初始化数据
void TableWidget::initValue()
{
    QString open_file_name ="E:/Desktop/build-CSV-Desktop_Qt_5_9_9_MSVC2013_64bit-Debug/debug/54.csv";
    QFile file(open_file_name);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,tr("open file error :"),tr("%1").arg(file.errorString()),QMessageBox::Yes);
        return;
    }
    QTextStream in(&file);
    QList<MapTableData> mapListTableData;
    in.readLine();//重第二行开始读
    while(!in.atEnd())
       {
           MapTableData mapTableData;
           QString linrstr = in.readLine();
           QStringList list = linrstr.split(",",QString::SkipEmptyParts);
           for(int num = 0; num < list.size(); num++)
           {
               CellData cellData;
               cellData.data = list.at(num);
               mapTableData[num] = cellData;
           }
          mapListTableData.append(mapTableData);
       }
       file.close();
       ui->widgetTable->updateTableData(mapListTableData);
}

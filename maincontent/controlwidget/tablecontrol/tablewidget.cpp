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
    QString open_file_name ="D:/build-QCoolPage-Desktop_Qt_5_9_9_MSVC2013_64bit-Debug/debug/123.csv";
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
       //
//    QList<MapTableData> mapListTableData;
//    for (int i = 0; i < 20; i++)
//    {
//        MapTableData mapTableData;
//        for (int j = 0; j <= TableControl::Port; j++)
//        {
//            CellData cellData;
//            if (i < 3)
//            {
//                cellData.setDataType(CellData::DANGER);
//            }
//            else if (i < 6)
//            {
//                cellData.setDataType(CellData::WARNING);
//            }

//            if (j == TableControl::ID)
//            {
//                cellData.data = "520";
//            }
//            else if (j == TableControl::NAME)
//            {
//                cellData.data = "YYC";
//            }
//            else if (j == TableControl::IP)
//            {
//                cellData.data = "TEST";
//            }
//            else if (j == TableControl::TYPEID)
//            {
//                cellData.data = "LIUXIU";
//            }
//            else if (j == TableControl::TYPE)
//            {
//                cellData.data = "100";
//            }
//            else if (j == TableControl::Port)
//            {
//                cellData.data = "22";
//            }
//            mapTableData[j] = cellData;
//        }
//        mapListTableData.append(mapTableData);
//    }
//    ui->widgetTable->updateTableData(mapListTableData);
//需要一进页面就把csv导入进去，但是不好使。
//     TableControl *tableControl=new TableControl();
//    int i = 0;
//    QString open_file_name = QFileDialog::getOpenFileName(this,tr("Excel file"),tr("E:\\"),tr("54.csv"));
//    QFile file(open_file_name);
//    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//       // QMessageBox::warning(this,tr("open file error :"),tr("%1").arg(file.errorString()),QMessageBox::Yes);
//        return;
//    }
//    QTextStream in(&file);
//    while(!in.atEnd())
//    {
//        QString linrstr = in.readLine();
//        QStringList list = linrstr.split(",",QString::SkipEmptyParts);
//        if(i == 0)
//        {
//            tableControl->ui->tableWidgetData->setColumnCount(list.size());
//            tableControl->ui->tableWidgetData->verticalHeader()->setHidden(true);
//            tableControl->ui->tableWidgetData->setColumnWidth(0,173);
//            tableControl->ui->tableWidgetData->setColumnWidth(1,152);
//            tableControl->ui->tableWidgetData->setColumnWidth(2,152);
//            tableControl->ui->tableWidgetData->setColumnWidth(3,152);
//            tableControl->ui->tableWidgetData->setColumnWidth(4,148);
//            tableControl->ui->tableWidgetData->setHorizontalHeaderLabels(QStringList()<<list.at(0)<<list.at(1)<<list.at(2)<<list.at(3)<<list.at(4));
//        }
//        else if(i > 0)
//        {
//            tableControl->ui->tableWidgetData->setRowCount(i);
//            for(int num = 0; num < list.size(); num++)
//            {
//                QTableWidgetItem *tableWidgetItem = new QTableWidgetItem(num);
//                tableWidgetItem->setTextAlignment(Qt::AlignCenter);
//                tableControl->ui->tableWidgetData->setItem(i-1,num,new QTableWidgetItem(list.at(num)));
//            }

//        }
//        i++;
//    }
//    file.close();
}

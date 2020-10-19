/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：表格
 * ***************************************/
#include "tablecontrol.h"
#include "ui_tablecontrol.h"
#include "tablewidget.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QTextStream>
#include <QFileDialog>
#include <QList>
#include <iostream>
#include <complex>
#include "listadd_dia.h"

using namespace std;
// 构造函数
TableControl::TableControl(QWidget *parent) :
    QWidget(parent)
{
    ui = new Ui::TableControl;
    ui->setupUi(this);
    this->initValue();
}
// 析构函数
TableControl::~TableControl()
{
    delete ui;
}
//QList<MapTableData> mapListTableData;
QString StrList;
// 初始化数据
void TableControl::initValue()
{
    ui->tableWidgetData->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetData->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetData->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidgetData->setAlternatingRowColors(true);
    ui->tableWidgetData->verticalHeader()->setHidden(true);
    ui->tableWidgetData->setShowGrid(false);
    ui->tableWidgetData->viewport()->setFocusPolicy(Qt::NoFocus);
}
void TableControl::changeCheck(int row, int col)
{
      if(ui->tableWidgetData ->item(row, col)->checkState() == Qt::Checked)
      {
          QMessageBox::information(this,tr("添加数据成功"),tr("信息已保存在!"),QMessageBox::Yes);
      }
}
// 添加数据
void TableControl::appendTableData(const MapTableData &mapTableData)
{
    m_mapListTableData.append(mapTableData);
    ui->tableWidgetData->setRowCount(m_mapListTableData.size());
    int a=m_mapListTableData.size();
    QTableWidgetItem *check=new QTableWidgetItem;
    check->setCheckState(Qt::Unchecked);
    check->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetData->setItem(m_mapListTableData.size() - 1,0,check); //插入复选框

    for (auto iter = mapTableData.begin(); iter != mapTableData.end(); iter++)
    {
        QTableWidgetItem *tableWidgetItem = new QTableWidgetItem(iter.value().data);
        tableWidgetItem->setTextColor(iter.value().color);
        tableWidgetItem->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetData->setItem(m_mapListTableData.size()-1 , iter.key()+1, tableWidgetItem);//行，列
    }
}
// 更新数据
void TableControl::updateTableData(const QList<MapTableData> &mapListData)
{
    for (MapTableData mapTableData : mapListData)
    {
        this->appendTableData(mapTableData);
    }
}
void TableControl::GetStr(QString str)
{
      StrList=str;
}
//添加按钮事件
void TableControl::on_pBn_Add_clicked()
{
     QDesktopWidget *pDesk = QApplication::desktop();
     list_d=new ListAdd_Dia(this);
     //list->setAttribute(Qt::WA_ShowModal, true);
     list_d->exec();
     //list_d->move((pDesk->width() - list_d->width()) / 2, (pDesk->height() - list_d->height()) / 2);//屏幕居中
     select_Bind();//刷新页面
}
//数据绑定
void TableControl::select_Bind()
{
    int i = 0;
    QString open_file_name ="D:/build-QCoolPage-Desktop_Qt_5_9_9_MSVC2013_64bit-Debug/debug/123.csv";
    QFile file(open_file_name);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,tr("open file error :"),tr("%1").arg(file.errorString()),QMessageBox::Yes);
        return;
    }
    QTextStream in(&file);
    in.readLine();
    while(!in.atEnd())
    {
        QString linrstr = in.readLine();
        QStringList list = linrstr.split(",",QString::SkipEmptyParts);
        ui->tableWidgetData->setRowCount(i);
        QTableWidgetItem *check=new QTableWidgetItem;
        check->setCheckState(Qt::Unchecked);
        check->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetData->setItem(i-1,0,check); //插入复选框
        for(int num = 0; num < list.size(); num++)
        {
            QTableWidgetItem *tableWidgetItem = new QTableWidgetItem(list.at(num));
            tableWidgetItem->setTextAlignment(Qt::AlignCenter);
            tableWidgetItem->setTextColor(Qt::white);
            ui->tableWidgetData->setItem(i-1,num+1,tableWidgetItem);
         }
        i++;
    }
    file.close();
}
//更新csv文件
void TableControl::on_pBn_Push_clicked()
{
    QString filename = "D:/build-QCoolPage-Desktop_Qt_5_9_9_MSVC2013_64bit-Debug/debug/123.csv";
    if(filename.isEmpty())
        return;
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,tr("警告"),tr("打不开文件"),QMessageBox::Yes);
            return;
    }
    QString str = "";
    QTextStream out(&file);
    int row = ui->tableWidgetData->rowCount();
    int horizon = ui->tableWidgetData->columnCount();
    for(int i = 1; i < horizon; i++)
    {
        str = ui->tableWidgetData->horizontalHeaderItem(i)->text();
        out<<str<<",";
    }
    out<<"\n";
    for(int i = 0; i < row; i++)
    {
        for(int j = 1; j < horizon; j++)
        {
            str = ui->tableWidgetData->item(i,j)->text();
            out<<str<<",";
        }
        out<<"\n";
    }
    //QMessageBox::information(this,QString::fromLocal8Bit("导出数据成功"),QString::fromLocal8Bit("信息已保存在%1!").arg(filename),QMessageBox::Yes);
    file.close();
}
//导入
void TableControl::on_pBn_PutIn_clicked()
{
    int i = 0;
    QString open_file_name =QFileDialog::getOpenFileName(this,tr("Excel file"),tr("C:\\"),tr("*.csv"));
    QFile file(open_file_name);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,tr("open file error :"),tr("%1").arg(file.errorString()),QMessageBox::Yes);
        return;
    }
    QTextStream in(&file);
    in.readLine();
    while(!in.atEnd())
    {
        QString linrstr = in.readLine();
        QStringList list = linrstr.split(",",QString::SkipEmptyParts);
        ui->tableWidgetData->setRowCount(i);
        QTableWidgetItem *check=new QTableWidgetItem;
        check->setCheckState(Qt::Unchecked);
        check->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetData->setItem(i-1,0,check); //插入复选框
        for(int num = 0; num < list.size(); num++)
        {
           QTableWidgetItem *tableWidgetItem = new QTableWidgetItem(list.at(num));
           tableWidgetItem->setTextAlignment(Qt::AlignCenter);//设置居中
           tableWidgetItem->setTextColor(Qt::white);//设置字体颜色
           ui->tableWidgetData->setItem(i-1,num+1,tableWidgetItem);
        }
        i++;
    }
    file.close();
}
//删除--先删除列表，再更新csv文件
void TableControl::on_pBn_Delete_clicked()
{
    int n=0;
    int row = ui->tableWidgetData->rowCount();
    for(int i=row-1;i>0;i--){
        if(ui->tableWidgetData ->item(i, 0)->checkState() == Qt::Checked){
              n=1;
        }
    }
    if(n==0)
    {
         QMessageBox::warning(this, tr("提示"),tr("请选择要删除的数据!"), QMessageBox::Yes);
         return;
    }
    for(int i=row-1;i>0;i--){
        if(ui->tableWidgetData ->item(i, 0)->checkState() == Qt::Checked){
              ui->tableWidgetData->removeRow(i);
        }
    }
    QMessageBox::warning(this, QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("删除数据成功!"), QMessageBox::Yes);
    on_pBn_Push_clicked();//更新csv文件
}
//修改
void TableControl::on_pBn_Edit_clicked()
{
    MapTableData mapTableData;
    QString a="";
    int row = ui->tableWidgetData->rowCount();
    int i=0;
    for( i=row-1;i>0;i--){
         if(ui->tableWidgetData ->item(i, 0)->checkState() == Qt::Checked){
             for(int num = 1; num < 7; num++){
                a+= ui->tableWidgetData->item(i,num)->text()+",";
             }
             break;
         }
    }
    QDesktopWidget *pDesk = QApplication::desktop();
    list_e=new ListEdit_dia(this);
    QObject::connect(this,SIGNAL(sendStr(QString)),list_e,SLOT(getStr(QString)));
    emit sendStr(a);
    list_e->exec();
    QStringList list = StrList.split(",",QString::SkipEmptyParts);
    for(int num = 0; num < list.size(); num++)
    {
        ui->tableWidgetData->item(i,num+1)->setText(list.at(num));
    }
    on_pBn_Push_clicked();//更新csv文件
}
//搜索
void TableControl::on_pBn_Search_clicked()
{
    int rC = ui->tableWidgetData->rowCount();//获得行数
        if (ui->tEt_ID->document()->isEmpty()) {//判断输入是否为空
            for (int i = 0; i < rC; i++) {
                ui->tableWidgetData->setRowHidden(i, false);//显示所有行
            }
        } else {
        //获取符合条件的cell索引
        QList<QTableWidgetItem *> item= ui->tableWidgetData->findItems(ui->tEt_ID->toPlainText(), Qt::MatchContains);
        for (int i = 0; i < rC; i++) {
            ui->tableWidgetData->setRowHidden(i, true);//隐藏所有行
        }
        if (!item.isEmpty()) { //不为空
            for (int i = 0; i < item.count(); i++) {
               ui->tableWidgetData->setRowHidden(item.at(i)->row(),false);//item.at(i).row()输出行号
            }
        }
    }
}
//自动搜索
void TableControl::on_pBn_SelectByIP_clicked()
{
    //QDesktopWidget *pDesk = QApplication::desktop();
    listselect=new ListSelectByIP(this);
    listselect->exec();
    //listselect->move((pDesk->width() - list_d->width()) / 2, (pDesk->height() - list_d->height()) / 2);//屏幕居中
}

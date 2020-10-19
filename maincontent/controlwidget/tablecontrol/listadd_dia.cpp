#include "listadd_dia.h"
#include "ui_listadd_dia.h"
#include <QMessageBox>
#include "tablecontrol.h"
#include "ui_tablecontrol.h"
#include <QFileDialog>
#include <QTextStream>

ListAdd_Dia::ListAdd_Dia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListAdd_Dia)
{
    ui->setupUi(this);
}

ListAdd_Dia::~ListAdd_Dia()
{
    delete ui;
}

void ListAdd_Dia::on_pBn_Add_clicked()
{
    if(ui->tEt_ID->document()->isEmpty())
    {
      QMessageBox::warning(this, tr("提示"),tr("ID不可为空!"), QMessageBox::Yes);
      return;
    }
    if(ui->tEt_IP->document()->isEmpty()){
       QMessageBox::warning(this, tr("提示"),tr("IP不可为空!"), QMessageBox::Yes);
       return;
    }
    if(ui->tEt_Port->document()->isEmpty()){
        QMessageBox::warning(this, tr("提示"),tr("端口不可为空!"), QMessageBox::Yes );
        return;
    }
    if(ui->tEt_Type->document()->isEmpty()){
        QMessageBox::warning(this, tr("提示"),tr("设备类型不可为空!"), QMessageBox::Yes);
        return;
    }
    if(ui->tEt_name->document()->isEmpty()){
        QMessageBox::warning(this, tr("提示"),tr("名称不可为空!"), QMessageBox::Yes);
        return;
     }
    if(ui->tEt_TypeID->document()->isEmpty()){
       QMessageBox::warning(this, tr("提示"),tr("设备型号不可为空!"), QMessageBox::Yes);
       return;
     }
        QString filename = "D:/build-QCoolPage-Desktop_Qt_5_9_9_MSVC2013_64bit-Debug/debug/123.csv";
        QFile file(filename);
        file.open(QIODevice::WriteOnly|QIODevice::Append);//在文件末尾添加。
        QString str = "";
        QTextStream out(&file);
        out.readLine();
        TableControl *tableControl=new TableControl();
          MapTableData mapTableData;
          str = ui->tEt_ID->toPlainText();
          out<<str<<",";
          str = ui->tEt_name->toPlainText();
          out<<str<<",";
          str= ui->tEt_IP->toPlainText();
          out<<str<<",";
          str = ui->tEt_Type->toPlainText();
          out<<str<<",";
          str = ui->tEt_TypeID->toPlainText();
          out<<str<<",";
          str = ui->tEt_Port->toPlainText();
          out<<str;
          out<<"\n";
          QMessageBox::information(this,tr("添加数据成功"),tr("信息已保存在!"),QMessageBox::Yes);
          file.close();
}

void ListAdd_Dia::on_pBn_Close_clicked()
{
    this->close();
}

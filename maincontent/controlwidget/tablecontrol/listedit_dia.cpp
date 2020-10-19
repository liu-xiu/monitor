#include "listedit_dia.h"
#include "ui_listedit_dia.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QTextStream>
#include "tablecontrol.h"

ListEdit_dia::ListEdit_dia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListEdit_dia)
{
    ui->setupUi(this);
}
ListEdit_dia::~ListEdit_dia()
{
    delete ui;
}
void ListEdit_dia::getStr(QString str)
{
    QStringList list = str.split(",",QString::SkipEmptyParts);
    ui->tEt_ID->setText(list.at(0));
    ui->tEt_name->setText(list.at(1));
    ui->tEt_IP->setText(list.at(2));
    ui->tEt_Type->setText(list.at(3));
    ui->tEt_TypeID->setText(list.at(4));
    ui->tEt_Port->setText(list.at(5));

}
void ListEdit_dia::on_pBn_Edit_clicked()
{
    QString a="";
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
    QList<MapTableData> mapListTableData;
    a+= ui->tEt_ID->toPlainText()+","+ui->tEt_name->toPlainText()+","+ui->tEt_IP->toPlainText()+
            ","+ui->tEt_Type->toPlainText()+","
            +ui->tEt_TypeID->toPlainText()+","+ui->tEt_Port->toPlainText();
    TableControl *tableControl=new TableControl();
    QObject::connect(this,SIGNAL(SendStr(QString)),tableControl,SLOT(GetStr(QString)));
    emit SendStr(a);
    QMessageBox::warning(this, tr("提示"),tr("修改数据成功!"), QMessageBox::Yes);
}

void ListEdit_dia::on_pBn_Close_clicked()
{
    this->close();
}

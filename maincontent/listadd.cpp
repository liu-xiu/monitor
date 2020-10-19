#include "listadd.h"
#include "ui_listadd.h"

ListAdd::ListAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListAdd)
{
    ui->setupUi(this);
    this->initValue();
}

ListAdd::~ListAdd()
{
    delete ui;
}
// 初始化数据
void ListAdd::initValue()
{

   ui->textEdit->tr("2");
}

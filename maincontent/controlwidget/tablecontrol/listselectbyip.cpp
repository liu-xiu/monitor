#include "listselectbyip.h"
#include "ui_listselectbyip.h"

ListSelectByIP::ListSelectByIP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListSelectByIP)
{
    ui->setupUi(this);
}

ListSelectByIP::~ListSelectByIP()
{
    delete ui;
}

void ListSelectByIP::on_pBn_Close_clicked()
{
    this->close();
}

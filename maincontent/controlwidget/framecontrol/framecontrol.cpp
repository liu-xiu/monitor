﻿/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：面板
 * ***************************************/
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
# pragma execution_character_set("utf-8")
#endif
#include "framewidget.h"
#include "ui_framewidget.h"
#include "framecontrol.h"
#include <QFrame>
#include "flowlayout/flowlayout.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>
#include "framewidget.h"


// 构造函数
FrameControl::FrameControl(QWidget * parentWidget,QFrame *parent) :
    QFrame(parent)
{
    this->setFixedWidth(FIXED_WIDTH);
    this->setFixedHeight(FIXED_HEIGHT);
    this->setObjectName("frameApplication");

    fw = parentWidget;
    QObject::connect(this,SIGNAL(sendStr(FrameControl*)),fw,SLOT(getStr(FrameControl*)));
}
int IMAGE_WIDTH;
int IMAGE_HEIGHT;
// 析构函数
FrameControl::~FrameControl()
{

}

 //设置面板图标
void FrameControl::setLabelPixMap(const QPixmap &pixMap)
{
    if (labelImage != nullptr) {
        labelImage->setPixmap(pixMap);
    }
}

 //设置标题
void FrameControl::setTitleInfo(const QString &title)
{
    if (labelTitle != nullptr) {
        labelTitle->setText(title);
    }
}

 //创建面板
void FrameControl::createFrame(const QPixmap &pixMap, int index)
{
    if(index==1){
        this->setFixedWidth(700);
        this->setFixedHeight(500);
       IMAGE_WIDTH=700;
       IMAGE_HEIGHT=500;
       this->setFixedWidth(700);
       this->setFixedHeight(500);
       //QHBoxLayout *hBoxLayout = new QHBoxLayout(this);
       labelImage = new QLabel(this);
       pixMap.scaled(700,500);
       labelImage->setFixedSize(700, 500);
       labelImage->setPixmap(pixMap);
       labelImage->setScaledContents(true);
      // QVBoxLayout *vBoxLayout = new QVBoxLayout();
       //hBoxLayout->addWidget(labelImage);
    }
    else
    {
        IMAGE_WIDTH=700;
        IMAGE_HEIGHT=500;

        QHBoxLayout *hBoxLayout = new QHBoxLayout(this);
        labelImage = new QLabel(this);
        pixMap.scaled(IMAGE_WIDTH,IMAGE_HEIGHT);
        labelImage->setFixedSize(IMAGE_WIDTH, IMAGE_HEIGHT);
        labelImage->setPixmap(pixMap);
        labelImage->setScaledContents(true);
        QVBoxLayout *vBoxLayout = new QVBoxLayout();
       // vBoxLayout->addWidget(labelTitle);
        //vBoxLayout->addWidget(pushButtonDownLoad);
        hBoxLayout->addWidget(labelImage);
        hBoxLayout->addLayout(vBoxLayout);
    }
}
 void FrameControl::mouseDoubleClickEvent(QMouseEvent *)
 {
     emit sendStr(this);
     tag = !tag;
     //this->setVisible(false);
     //frameWidget->flowLayout = new FlowLayout( frameWidget->ui->scrollAreaWidgetContents_2);
     //this->createFrame(QPixmap(this->IMAGE_PATH_), 1);
//   flowLayout = new FlowLayout(ui->scrollAreaWidgetContents_2);
     //frameWidget->flowLayout->->addWidget(frameControl);
     // QMessageBox::warning(0,QObject::tr("提示"),"对方拒绝接收！");

 }


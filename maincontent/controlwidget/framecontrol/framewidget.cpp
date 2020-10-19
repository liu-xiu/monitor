/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：面板窗口
 * ***************************************/
#include "framewidget.h"
#include "ui_framewidget.h"
#include "flowlayout/flowlayout.h"
#include "framecontrol.h"

// 构造函数
FrameWidget::FrameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrameWidget)
{
    ui->setupUi(this);
    this->initValue();
    //this->labelImage->installEventFilter(this);
    ///在这定义信号与曹  flowLayout
    ///1.flowLayout加一个双击事件
    ///2.获取那个FrameControl
    ///
   // connect(ui->scrollAreaWidgetContents_2,SIGNAL(mouseDoubleClickEvent),this,SLOT(func()));
}
// 析构函数
FrameWidget::~FrameWidget()
{
    delete ui;
}
QString path;
//隐藏多余的，思路是建一个vector数组，存放每次new的framecontrol对象，然后遍历这个数组，对于没有双击的都隐藏
//双击之后还得还回去没有实现呢
void FrameWidget::getStr(FrameControl *frame)
{
    //frame->setGeometry(300,300,700,700);
    frame->setFixedWidth(1800);
    frame->setFixedHeight(900);
    //frame->labelImage->setFixedSize(1800, 900);
    //frame->labelImage->setScaledContents(true);

//   path=str;
//   //flowLayout = new FlowLayout(ui->scrollAreaWidgetContents_2);

//   FrameControl *frameControl = new FrameControl();
//   frameControl->createFrame(QPixmap(path), 1);
//   frameControl->showMaximized();
//   //frameControl->setAttribute(Qt::WA_TranslucentBackground);//无边框
//   flowLayout->addWidget(frameControl);

}

// 初始化
void FrameWidget::initValue()
{
    flowLayout = new FlowLayout(ui->scrollAreaWidgetContents_2);
    ui->groupBox->setStyleSheet("QGroupBox{border:none}");
    //ui->groupBox_2->setStyleSheet("QGroupBox{border:none}");
    for (int i = 0; i < 20; i++)
    {
        FrameControl *frameControl = new FrameControl(this);
        frameControl->createFrame(QPixmap(IMAGE_PATH), 0);
        frameControl->setAttribute(Qt::WA_TranslucentBackground);//无边框
        //存起来
        //FrameControl vector[10]=new FrameControl(this);
        QString vector[20];
      //  vector[i]=frameControl;
        flowLayout->addWidget(frameControl);
    }

}
//void FrameWidget::mouseDoubleClickEvent(QMouseEvent *)
//{

//    flowLayout_ = new FlowLayout(ui->scrollAreaWidgetContents_2);
//    labelImage->setFixedSize(700, 500);
//   // this->labelImage->setWindowFlags(Qt::Dialog);
//    flowLayout_->addWidget(labelImage);

//   //this->labelImage->showFullScreen();
//}

void FrameWidget::on_pBn_Down_clicked()
{

}

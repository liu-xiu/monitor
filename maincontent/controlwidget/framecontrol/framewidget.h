/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：面板窗口
 * ***************************************/
#ifndef FRAMEWIDGET_H
#define FRAMEWIDGET_H

#include <QWidget>
#include <QDebug>
#include "framecontrol.h"
#include<QLabel>

class FlowLayout;
class QLabel;
class QPushButton;

namespace Ui {
class FrameWidget;
}

class FrameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FrameWidget(QWidget *parent = 0);
    ~FrameWidget();
    Ui::FrameWidget *ui;
    FlowLayout *flowLayout;//
    FlowLayout *flowLayout_;
   // void mouseDoubleClickEvent(QMouseEvent *);
private slots:
    void getStr(FrameControl *frame);
private:
      const QString IMAGE_PATH = ":/res/res/image/camera/example.jpg";
      const QString IMAGE_PATH_ = ":/res/res/image/banna/2.jpg";
private:
    void initValue();

};

#endif // FRAMEWIDGET_H

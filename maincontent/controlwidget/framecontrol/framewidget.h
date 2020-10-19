/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：面板窗口
 * ***************************************/
#ifndef FRAMEWIDGET_H
#define FRAMEWIDGET_H

#include <QWidget>
#include <QDebug>
#include "FrameControl.h"

class FlowLayout;//
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
   // bool eventFilter(QObject  *obj, QEvent *event);
private slots:
    void on_pBn_Down_clicked();
    //void mouseDoubleClickEvent(QMouseEvent *);
    void getStr(FrameControl *frame);
private:
   // QLabel *labelImage;
     const int IMAGE_WIDTH = 300;
     const int IMAGE_HEIGHT = 200;
    QLabel *labelTitle;
    const int FIXED_WIDTH = 300;
    const int FIXED_HEIGHT = 200;
//    const QString IMAGE_PATH = ":/res/res/image/image.png";
      const QString IMAGE_PATH = ":/res/res/image/camera/example.jpg";
      const QString IMAGE_PATH_ = ":/res/res/image/banna/2.jpg";
private:
    void initValue();
    //void  func();

};

#endif // FRAMEWIDGET_H

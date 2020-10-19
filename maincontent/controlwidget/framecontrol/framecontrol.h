/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：面板
 * ***************************************/
#ifndef FRAMECONTROL_H
#define FRAMECONTROL_H

#include <QFrame>


class QLabel;
class QPushButton;
class QLabel;
class FlowLayout;


class FrameControl : public QFrame
{
    Q_OBJECT

public:
    explicit FrameControl(QWidget * parentWidget,QFrame *parent = 0);
    ~FrameControl();
    void setLabelPixMap(const QPixmap &pixMap);//
    void setTitleInfo(const QString &title);//
    void createFrame(const QPixmap &pixMap,int index );//const QString &title
    void mouseDoubleClickEvent(QMouseEvent *);
     QLabel *labelImage;
private:

    QLabel *labelTitle;
    QWidget *fw;
    //FlowLayout *flowLayout;
    QPushButton *pushButtonDownLoad;
private:
   // const int IMAGE_WIDTH = 300;
    //const int IMAGE_HEIGHT = 200;
    const int FIXED_WIDTH = 300;
    const int FIXED_HEIGHT = 200;
    const int BUTTON_WIDTH = 80;
    const int BUTTON_HEIGHT = 25;
    const QString IMAGE_PATH_ = ":/res/res/image/camera/example.jpg";
    bool tag = false;
signals:
        void sendStr(FrameControl * f);
};

#endif // FRAMECONTROL_H

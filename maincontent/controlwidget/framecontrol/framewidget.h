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
#include "avglobal.h"
#include "dhconfigsdk.h"
#include "dhnetsdk.h"

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
    static void CALLBACK HaveReConnect(LLONG lLoginID,char *pchDVRIP,LONG nDVRPort,LDWORD dwUser);
    static void CALLBACK fRealDataCB(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LLONG param,LDWORD dwUser);
    static void CALLBACK DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser);
   // void mouseDoubleClickEvent(QMouseEvent *);
    static void CALLBACK VideoStatSumCallback(LLONG lAttachHandle, NET_VIDEOSTAT_SUMMARY* pBuf,DWORD dwBufLen, LDWORD dwUser);
private slots:
    void getStr(FrameControl *frame);
    void h_openPassengerFlow();
    void h_closePassengerFlow();
    void h_next();
private:
    void initSDK();
    char D_Ip[32] ;
    char D_UserName[32];
    char D_Pasdwd[32];
    int D_Port = 37777;
    int nIndex = 0;
    const QString IMAGE_PATH = ":/res/res/image/camera/example.jpg";
    const QString IMAGE_PATH_ = ":/res/res/image/banna/2.jpg";
private:
    void initValue();

};

#endif // FRAMEWIDGET_H

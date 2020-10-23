/*****************************************
 * 作者: YYC
 * 日期: 2020-04-26
 * 功能：面板窗口
 * ***************************************/
#include "framewidget.h"
#include "ui_framewidget.h"
#include "flowlayout/flowlayout.h"
#include "framecontrol.h"
#include<QMessageBox>
LLONG LoginHandle;//登录句柄
LLONG lHandle;//监视句柄
LLONG attachpassHnd;//订阅客流句柄

// 构造函数
FrameWidget::FrameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrameWidget)
{
    ui->setupUi(this);
    this->initValue();
    initSDK();
}
// 析构函数
FrameWidget::~FrameWidget()
{
    delete ui;
}
//断线回调
void CALLBACK FrameWidget::DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser)
{
    printf("Call DisConnectFunc\n");
    printf("lLoginID[0x%x]",lLoginID);
    if(NULL != pchDVRIP)
    {
        printf("pchDVRIP[%s]\n",pchDVRIP);
    }
    printf("nDVRPort[%d]\n",nDVRPort);
    printf("dwUser[%p]\n",dwUser);
    printf("\n");
}

void FrameWidget::initSDK(){
    if(CLIENT_Init((fDisConnect)this->DisConnectFunc, (LDWORD)0))
    {
        qDebug()<<"SDK INIT OK!"<<endl;
    }
    else
    {
        qDebug()<<"SDK INIT FAIL!"<<endl;
    }
}
//隐藏多余的，思路是建一个vector数组，存放每次new的framecontrol对象，然后遍历这个数组，对于没有双击的都隐藏
//双击之后还得还回去没有实现呢
void FrameWidget::getStr(FrameControl *frame)
{
    //frame->setGeometry(300,300,700,700);
    frame->setFixedWidth(1800);
    frame->setFixedHeight(900);
    frame->labelImage->setFixedSize(1800, 900);
    frame->labelImage->setScaledContents(true);
}

// 初始化
void FrameWidget::initValue()
{
    ui->tw->setStyleSheet("#tw::item{height:30px;}");
    //ui->toolBox->setStyleSheet("#toolBox::item{margins:none;}");
    ui->tw->setContentsMargins(0,0,0,0);
    ui->groupBox->setStyleSheet("QGroupBox{border:none}");
    strcpy(D_Ip,"192.168.0.66");
    strcpy(D_UserName,"admin");
    strcpy(D_Pasdwd,"admin");
    D_Port = 37777;
    //SDK初始化
    if(CLIENT_Init((fDisConnect)DisConnectFunc, (LDWORD)0))
    {
        qDebug()<<"SDK INIT OK!"<<endl;
    }
    else
    {
        qDebug()<<"SDK INIT FAIL!"<<endl;
    }
    //获取SDK版本信息
    DWORD dwNetSdkVersion = CLIENT_GetSDKVersion();
    printf("NetSDK version is [%d]\n",dwNetSdkVersion);
    //设置断线重连回调接口，设置过断线重连成功回调函数后，当设备出现断线情况，SDK内部会自动进行重连操作
    CLIENT_SetAutoReconnect(&HaveReConnect,0);
    //设置登录超时时间和尝试次数
    int nWaitTime = 5000; //登录请求响应超时时间设置为5s
    int nTryTimes = 3; //登录时尝试建立连接3次
    CLIENT_SetConnectTime(nWaitTime,nTryTimes);
    //设置更多网络参数，NET_PARAM的nWaittime,nConnectTryNum成员与CLIENT_SetConnectTime 接口设置的登录设备超时时间和尝试次数的意义相同
    NET_PARAM stuNetparm ={0};
    stuNetparm.nConnectTime = 3000;//登录时尝试建立连接的超时时间
    CLIENT_SetNetworkParam(&stuNetparm);
    // 登录
    NET_IN_LOGIN_WITH_HIGHLEVEL_SECURITY stInparam;
    memset(&stInparam, 0, sizeof(stInparam));
    stInparam.dwSize = sizeof(stInparam);

    strncpy(stInparam.szIP, D_Ip, sizeof(stInparam.szIP) - 1);
    strncpy(stInparam.szPassword, D_Pasdwd, sizeof(stInparam.szPassword) - 1);
    strncpy(stInparam.szUserName, D_UserName, sizeof(stInparam.szUserName) - 1);
    stInparam.nPort = D_Port;
    stInparam.emSpecCap = EM_LOGIN_SPEC_CAP_TCP;
    tagNET_OUT_LOGIN_WITH_HIGHLEVEL_SECURITY stOutparam;
    LoginHandle = CLIENT_LoginWithHighLevelSecurity(&stInparam, &stOutparam);
    qDebug()<<"LoginHandle="<<LoginHandle<<endl;
    if (LoginHandle)
    {
        QMessageBox::about(NULL,ui->cameraIp->text(),"连接成功");
    }
    else
    {
        QMessageBox::about(NULL,ui->cameraIp->text(),"登录失败哦");
    }
    h_next();
//    flowLayout = new FlowLayout(ui->scrollAreaWidgetContents_2);
//    ui->groupBox->setStyleSheet("QGroupBox{border:none}");
//    for (int i = 0; i < 20; i++)
//    {
//        FrameControl *frameControl = new FrameControl(this);
//        frameControl->createFrame(QPixmap(IMAGE_PATH), 0);
//        frameControl->setAttribute(Qt::WA_TranslucentBackground);//无边框
//        //存起来
//        //FrameControl vector[10]=new FrameControl(this);
//        QString vector[20];
//        //vector[i]=frameControl;
//        flowLayout->addWidget(frameControl);
//    }
}
void FrameWidget::h_next()
{
    if(FALSE == LoginHandle)
    {
        QMessageBox::about(NULL,ui->cameraIp->text(),"连接失败");
        return;
    }
    //获取Label句柄
    HWND hWnd = (HWND)ui->scrollAreaWidgetContents_2->winId();
    //监视
    lHandle = CLIENT_RealPlayEx(LoginHandle,0, hWnd);//实时监视句柄
    if (lHandle)
    {
        qDebug() << "CLIENT_RealPlayEx success!" << endl;
        //设置实时监视回调函数
        DWORD dwFlag = REALDATA_FLAG_RAW_DATA;//原始数据标志
        CLIENT_SetRealDataCallBackEx2(lHandle, &fRealDataCB, NULL,dwFlag);
    }
    else
    {
        qDebug() << "CLIENT_RealPlayEx: failed! Error code" <<CLIENT_GetLastError()<< endl;
    }

}
void FrameWidget::h_openPassengerFlow()
{
    if(FALSE == LoginHandle)
    {
        QMessageBox::about(NULL,ui->cameraIp->text(),"未连接登录");
        return;
    }
    NET_IN_ATTACH_VIDEOSTAT_SUM
            InParam={sizeof(NET_IN_ATTACH_VIDEOSTAT_SUM)};
    InParam.nChannel=0;
    InParam.cbVideoStatSum=&VideoStatSumCallback;
    NET_OUT_ATTACH_VIDEOSTAT_SUM OutParam={0};
    OutParam.dwSize=sizeof(OutParam);
    int nWaitTime=5000; //wait time
    // 订阅客流量统计
    attachpassHnd = CLIENT_AttachVideoStatSummary(LoginHandle,&InParam,&OutParam,nWaitTime);
    if(attachpassHnd)
    {
        qDebug() << "CLIENT_AttachVideoStatSummary sucess!" << endl;
    }
    else
    {
        qDebug() << "error number:" <<CLIENT_GetLastError() << endl;
    }

}
void FrameWidget::h_closePassengerFlow()
{
    if(FALSE == LoginHandle)
    {
        QMessageBox::about(NULL,ui->cameraIp->text(),"未连接登录");
        return;
    }
    if(FALSE == attachpassHnd)
    {
        QMessageBox::about(NULL,ui->cameraIp->text(),"未订阅客流统计");
        return;
    }
    CLIENT_DetachVideoStatSummary(attachpassHnd);
}
//客流数据回调
void CALLBACK FrameWidget::VideoStatSumCallback(LLONG lAttachHandle, NET_VIDEOSTAT_SUMMARY* pBuf,
                                               DWORD dwBufLen, LDWORD dwUser)
{
    // 处理回调数据
    qDebug() << "\nchannel:" <<pBuf->nChannelID << "\nname:"<< pBuf->szRuleName<< "\nenter:"<< pBuf->stuEnteredSubtotal.nTotal<< "\nleave:"<< pBuf->stuExitedSubtotal.nTotal<< endl;
}
void CALLBACK FrameWidget::fRealDataCB(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LLONG param,LDWORD dwUser)
{
    //printf("receive real data,param:lRealHandle[%p],dwDataType[%d],pBuffer[%p],dwBufSize[%d]\n",lRealHandle,dwDataType,pBuffer,dwBufSize);
    if(CLIENT_SaveRealData(lHandle,"D:/test.mp4"))
    {
       //printf("Save data success\n");
    }
}
//重连回调
void CALLBACK FrameWidget::HaveReConnect(LLONG lLoginID,char *pchDVRIP,LONG nDVRPort,LDWORD dwUser)
{
    printf("Call HaveReConnect\n");
    printf("lLoginID[0x%x]",lLoginID);
    if(NULL != pchDVRIP)
    {
        printf("pchDVRIP[%s]\n",pchDVRIP);
    }
    printf("nDVRPort[%d]\n",nDVRPort);
    printf("dwUser[%p]\n",dwUser);
    printf("\n");
}

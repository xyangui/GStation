// StaticStatus.cpp: implementation of the CStaticStatus class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "StaticStatus.h"

#include "math.h"

#include "GStationDlg.h"
#include "Msg_Telemetry.h"
#include "MAPX.h"
#include "Msg_WayPoint.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStaticStatus::CStaticStatus()
{

}

CStaticStatus::~CStaticStatus()
{

}

//创建静态控件时，需要主对话框的指针
void CStaticStatus::Create(CGStationDlg *pGSDlg)
{
	m_pGStationDlg = pGSDlg;

	CRect rect;
	m_pGStationDlg->GetClientRect(&rect);

	int left = rect.left + 1;
	int top = rect.bottom - 20;
	int bottom = rect.bottom;
	int gap = 2;//2个静态框之间的间隙
	int wide = (rect.right - rect.left - gap*8)/9;//8个间隙，共9个
	int LedWide = 25;

	//应答灯
	yingdaled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left,top,left+LedWide,bottom),m_pGStationDlg);
	//应答框
	yingda.Create("",1342312960,CRect(left+LedWide,top,left+wide,bottom),m_pGStationDlg);
	int i1right = left+wide;

	//通讯灯
	tongxunled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+wide+gap,top,left+wide+gap+LedWide,bottom),m_pGStationDlg);
	//通讯框
	tongxun.Create("",1342312960,CRect(left+wide+gap+LedWide,top,left+wide+gap+wide,bottom),m_pGStationDlg);
	int i2left = left+wide+gap;
	int i2right = left+wide+gap+wide;

	//模式
	moshiled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+(wide+gap)*2,top,left+(wide+gap)*2+LedWide,bottom),m_pGStationDlg);
	moshi.Create("",1342312960,CRect(left+(wide+gap)*2+LedWide,top,left+(wide+gap)*2+wide,bottom),m_pGStationDlg);
	int i3left = left+(wide+gap)*2;
	int i3right = left+(wide+gap)*2+wide;

	//GPS
	GPSled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+(wide+gap)*3,top,left+(wide+gap)*3+LedWide,bottom),m_pGStationDlg);
	GPS.Create("",1342312960,CRect(left+(wide+gap)*3+LedWide,top,left+(wide+gap)*3+wide,bottom),m_pGStationDlg);
	int i4left = left+(wide+gap)*3;
	int i4right = left+(wide+gap)*3+wide;
	
	//卫星
	weixingled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+(wide+gap)*4,top,left+(wide+gap)*4+LedWide,bottom),m_pGStationDlg);
	weixing.Create("",1342312960,CRect(left+(wide+gap)*4+LedWide,top,left+(wide+gap)*4+wide,bottom),m_pGStationDlg);
	int i5left = left+(wide+gap)*4;
	int i5right = left+(wide+gap)*4+wide;

	//PDOP
	PDOPled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+(wide+gap)*5,top,left+(wide+gap)*5+LedWide,bottom),m_pGStationDlg);
	PDOP.Create("",1342312960,CRect(left+(wide+gap)*5+LedWide,top,left+(wide+gap)*5+wide,bottom),m_pGStationDlg);
	int i6left = left+(wide+gap)*5;
	int i6right = left+(wide+gap)*5+wide;

	//舵机电压
	dianya_duojiled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+(wide+gap)*6,top,left+(wide+gap)*6+LedWide,bottom),m_pGStationDlg);
	dianya_duoji.Create("",1342312960,CRect(left+(wide+gap)*6+LedWide,top,left+(wide+gap)*6+wide,bottom),m_pGStationDlg);

	//总电压
	dianya_zongled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+(wide+gap)*7,top,left+(wide+gap)*7+LedWide,bottom),m_pGStationDlg);
	dianya_zong.Create("",1342312960,CRect(left+(wide+gap)*7+LedWide,top,left+(wide+gap)*7+wide,bottom),m_pGStationDlg);

	//温度
	wenduled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+(wide+gap)*8,top,left+(wide+gap)*8+LedWide,bottom),m_pGStationDlg);
	wendu.Create("",1342312960,CRect(left+(wide+gap)*8+LedWide,top,left+(wide+gap)*8+wide,bottom),m_pGStationDlg);

	CFont *font;
	font = m_pGStationDlg->GetFont();

	yingda.SetFont(font,TRUE);
	tongxun.SetFont(font,TRUE);
	moshi.SetFont(font,TRUE);
	GPS.SetFont(font,TRUE);
	weixing.SetFont(font,TRUE);
	dianya_duoji.SetFont(font,TRUE);
	dianya_zong.SetFont(font,TRUE);
	wendu.SetFont(font,TRUE);
	PDOP.SetFont(font,TRUE);

	yingdaled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDOFF));
	yingda.SetWindowText("应答:");
	
	tongxunled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDOFF));
	tongxun.SetWindowText("通讯:");

	moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDOFF));
	moshi.SetWindowText("模式:");
	
	GPSled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	GPS.SetWindowText("GPS:");
	
	weixingled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	weixing.SetWindowText("卫星:");	
	
	PDOPled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	PDOP.SetWindowText("PDOP: ");

	dianya_duojiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	dianya_duoji.SetWindowText("舵机电压:");
	
	dianya_zongled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	dianya_zong.SetWindowText("总电压:");
	
	wenduled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	wendu.SetWindowText("温度: ");

	left = rect.left + 5;
	top = rect.bottom - 45;
	bottom = rect.bottom - 25;
	//gap = 2;//2个静态框之间的间隙
	//wide = (rect.right - 399 - left - gap*5)/6;//5个间隙，共6个

	//偏航距
	pianhang.Create("",1342312960,CRect(left,top,i1right,bottom),m_pGStationDlg);
	//距目标点
	distance_targetpoint.Create("",1342312960,CRect(i2left,top,i2right,bottom),m_pGStationDlg);
	//距起飞点
	distance_zeropoint.Create("",1342312960,CRect(i3left,top,i3right,bottom),m_pGStationDlg);
	//方位
	fangwei.Create("",1342312960,CRect(i4left,top,i4right,bottom),m_pGStationDlg);
	//总航点数
	zonghangdian.Create("",1342312960,CRect(i5left,top,i5right,bottom),m_pGStationDlg);
	//制式时间
	zhishishijian.Create("",1342312960,CRect(i6left,top,i6right+37,bottom),m_pGStationDlg);

	pianhang.SetFont(font,TRUE);
	distance_zeropoint.SetFont(font,TRUE);
	distance_targetpoint.SetFont(font,TRUE);
	fangwei.SetFont(font,TRUE);
	zonghangdian.SetFont(font,TRUE);
	zhishishijian.SetFont(font,TRUE);

	pianhang.SetWindowText("偏航距:");
	distance_zeropoint.SetWindowText("距起飞点:");
	distance_targetpoint.SetWindowText("距目标点:");
	fangwei.SetWindowText("方位:");
	zonghangdian.SetWindowText("总航点数:");
	zhishishijian.SetWindowText("制式时间:");

	top = top - 20 - 3;
	bottom = bottom - 20 - 3;
	//wide = wide*2 + gap;
	int iFirstThreeWide = (rect.right - 392 - left - gap*3)/4;//3个间隙，共4个

	//鼠标点
	mousepoint.Create("",1342312960,CRect(left,top,left+iFirstThreeWide+2,bottom),m_pGStationDlg);
	//飞机点
	currentpoint.Create("",1342312960,CRect(left+iFirstThreeWide+gap+2,top,i3right,bottom),m_pGStationDlg);
	//总距离
	luchengyufangwei.Create("",1342312960,CRect(i4left,top,i4right,bottom),m_pGStationDlg);
	//当前距离
	CurrentDistance.Create("",1342312960,CRect(i5left,top,i5right,bottom),m_pGStationDlg);
	//当前角度
	CurrentAngle.Create("",1342312960,CRect(i6left,top,i6right+37,bottom),m_pGStationDlg);

	mousepoint.SetFont(font,TRUE);
	currentpoint.SetFont(font,TRUE);
	luchengyufangwei.SetFont(font,TRUE);
	CurrentDistance.SetFont(font,TRUE);
	CurrentAngle.SetFont(font,TRUE);

	mousepoint.SetWindowText("鼠标:");
	currentpoint.SetWindowText("无人船:");
	luchengyufangwei.SetWindowText("总距离:");
	CurrentDistance.SetWindowText("当前距离:");
	CurrentAngle.SetWindowText("当前角度");
}

void CStaticStatus::UpdateWayPoint(CMsg_Telemetry *pTelemetry, CMapX &ctrlMapX)
{
	CString tempstr;
	//总航点数//剩余航点被去掉，显示总航点数即可
	CMapXLayer layer;
	layer = ctrlMapX.GetLayers().Item("WayPointDown");
	int iFeatureCount = layer.AllFeatures().GetCount();
	//int num = m_dFtrsNum-pTelemetry->m_nTargetWP;//xyg
	//int iRemainWayPointNum = iFeatureCount - pTelemetry->m_nTargetWP + 1;
	tempstr.Format("总航点数:%d",iFeatureCount);
	//shengdian.SetWindowText(tempstr);
	zonghangdian.SetWindowText(tempstr);

	//距目标点
	CWayPoint WayPoint;
	CMsg_WayPoint Msg_WayPoint;
	BOOL bOK = Msg_WayPoint.GetWayPointFromTab(WayPoint, ctrlMapX, _T("WayPointDown"), pTelemetry->m_iTargetWayPoint);
	if (!bOK) 
		return;
		
	double d = ctrlMapX.Distance(pTelemetry->m_GPSdata.m_dLongitude,pTelemetry->m_GPSdata.m_dLatitude, 
		WayPoint.dLongitude, WayPoint.dLatitude);//*1609/1000;
	//计算距目标点距离是没有道理的，m_WayPointUp不一定和飞控上的m_WayPointDown一致，地图中不一定有m_WayPointDown
	tempstr.Format("距目标点:%5.3lfkm",d);
	distance_targetpoint.SetWindowText(tempstr);
	//double dd = ctrlMapX.Distance(123.53999159999999,41.827405700000000, 
		//126.13036099999999, 40.621136999999997);

    //距起飞点
	bOK = Msg_WayPoint.GetWayPointFromTab(WayPoint, ctrlMapX, _T("WayPointDown"), 1);
	if (!bOK) 
		return;

	d = ctrlMapX.Distance(pTelemetry->m_GPSdata.m_dLongitude,pTelemetry->m_GPSdata.m_dLatitude, 
		WayPoint.dLongitude, WayPoint.dLatitude);//*1609/1000;
	tempstr.Format("距起飞点:%5.3lfkm",d);
	distance_zeropoint.SetWindowText(tempstr);
	//double dd2 = ctrlMapX.Distance(123.53999159999999,41.827405700000000, 
		//126.82005300000000, 40.438020999999999);计算的不正确



	//方位：显示飞机相对于起飞点（航线1点）的方位角	
	//(MapY(pTelemetry->m_GPSdata.m_dLongitude) - WayPoint.dLongitude) 
	//    / (MapX(pTelemetry->m_GPSdata.m_dLatitude) - WayPoint.dLatitude)
	double angle;
	double dTemp = atan( (pTelemetry->m_GPSdata.m_dLongitude - WayPoint.dLongitude) / 
		(pTelemetry->m_GPSdata.m_dLatitude - WayPoint.dLatitude) ) / 3.1415926 * 180;
	if((pTelemetry->m_GPSdata.m_dLatitude - WayPoint.dLatitude) >= 0 && (pTelemetry->m_GPSdata.m_dLongitude - WayPoint.dLongitude) >= 0)
		angle = 90 - dTemp;
	else if((pTelemetry->m_GPSdata.m_dLatitude - WayPoint.dLatitude) >= 0 && (pTelemetry->m_GPSdata.m_dLongitude - WayPoint.dLongitude) < 0)
		angle = 90 - dTemp;
	else 
		angle = 270 - dTemp;
	
	if (pTelemetry->m_GPSdata.m_dLatitude == WayPoint.dLatitude) {
		angle = 0;//上面除以0，出现乱码，所以angle = 0
	}
	tempstr.Format("方位:%.1lf度",angle);
	fangwei.SetWindowText(tempstr);
}

//更新静态控件和按钮时，需要主对话框的CMsg_Telemetry。
void CStaticStatus::UpdateMsgTelemetry(CMsg_Telemetry *pTelemetry)//, CWayPoint *pWayPoint, int iRemainWayPointNum)
{
	CString tempstr;
	CString tempstr2;
    //应答
	yingdaled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDOFF));//灰色
	yingda.SetWindowText("应答:");	
	if(pTelemetry->m_iControlMode >= 16)//遥测数据——控制模式——从左向右数第4位=1时，表示已应答
	{
		yingdaled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));//绿色
		yingda.SetWindowText("应答:已应答");
	}
	//通讯
	tongxunled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	tongxun.SetWindowText("通讯:接收");
	for(int i=0; i<100000000; i++){//延时，使“通讯:接收”和绿灯闪烁
	}
	//Sleep(1000);
	tongxunled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDOFF));
	tongxun.SetWindowText("通讯:");
	
    //模式，即控制模式
	if (pTelemetry->m_iControlMode >= 16) {//第4位为接收应答位，=1时代表应答
		pTelemetry->m_iControlMode = pTelemetry->m_iControlMode - 16;
	}
	if(pTelemetry->m_iControlMode ==0)
	{
		moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
		moshi.SetWindowText("模式:UAV");
	}else if(pTelemetry->m_iControlMode ==1)
	{
		moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));//红色
		moshi.SetWindowText("模式:RC");
	}else if(pTelemetry->m_iControlMode ==2)
	{
		moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
		moshi.SetWindowText("模式:RPV");
	}else if(pTelemetry->m_iControlMode ==3)
	{
		moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
		moshi.SetWindowText("模式:CPV");
	}else{
		moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
		moshi.SetWindowText("模式:开机");//xyg添加
	}

    //GPS：GPS定位状况
	if(pTelemetry->m_GPSdata.m_iXD ==0)
	{
		GPSled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
		GPS.SetWindowText("GPS:NO!");
	}else if(pTelemetry->m_GPSdata.m_iXD ==1)
	{
		GPSled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
		GPS.SetWindowText("GPS:2D");
	}else
	{
		GPSled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
		GPS.SetWindowText("GPS:3D");
	}

    //卫星：卫星数	
	if(pTelemetry->m_GPSdata.m_iSatelliteNum >= 4)
		weixingled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	else
		weixingled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	tempstr.Format("%d",pTelemetry->m_GPSdata.m_iSatelliteNum);
	tempstr2 = "卫星:";
	tempstr2+=tempstr;
	weixing.SetWindowText(tempstr2);
    
	//气压	改成PDOP
/*
	tempstr.Format("%5.2lf",pTelemetry->m_fAirPress);
	tempstr2 = "气压:";
	tempstr2+=tempstr;	
	PDOPled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	PDOP.SetWindowText(tempstr2);
*/  //PDOP
	if (pTelemetry->m_GPSdata.m_fPDOP < 5 && pTelemetry->m_GPSdata.m_fPDOP > 0) {//m_fPDOP低于阀值5显示绿灯
		PDOPled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	}else{
		PDOPled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	}
	tempstr.Format("%5.2lf",pTelemetry->m_GPSdata.m_fPDOP);
	tempstr2 = "PDOP:";
	tempstr2+=tempstr;	
	PDOP.SetWindowText(tempstr2);	

	//舵机电压
	tempstr.Format("%2.2lfV",pTelemetry->m_fVoltageServo);
	tempstr2 = "舵机电压:";
	tempstr2+=tempstr;
	if((pTelemetry->m_fVoltageServo > m_pGStationDlg->m_pSettingSheet->m_pageSetSafe.m_fServo_VMin)&&
		(pTelemetry->m_fVoltageServo < m_pGStationDlg->m_pSettingSheet->m_pageSetSafe.m_fServo_VMax))
		dianya_duojiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	else
		dianya_duojiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	dianya_duoji.SetWindowText(tempstr2);
	
	//总电压	
	tempstr.Format("%2.2lfV",pTelemetry->m_fVoltageUAV);
	tempstr2 = "总电压:";
	tempstr2+=tempstr;

	if((pTelemetry->m_fVoltageUAV > m_pGStationDlg->m_pSettingSheet->m_pageSetSafe.m_fPilot_VMin)&&
		(pTelemetry->m_fVoltageUAV < m_pGStationDlg->m_pSettingSheet->m_pageSetSafe.m_fPilot_VMax))
		dianya_zongled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	else
		dianya_zongled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	dianya_zong.SetWindowText(tempstr2);

    //温度	
	tempstr.Format("%2.1lf度",pTelemetry->m_fTemperature);
	tempstr2 = "温度:";
	tempstr2+=tempstr;	
	wenduled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	wendu.SetWindowText(tempstr2);
   
/////////////GPS时间
//	tempstr.Format("%2.3lf",pTelemetry->m_nWendu_Dianzu);
//	tempstr2 = "主板温度:";
//	tempstr2+=tempstr;	
	int day,hour,minter,second;
	day = (int)pTelemetry->m_dGPSTime/1000/3600/24;
	hour = (int)((pTelemetry->m_dGPSTime/1000/3600/24-day)*24);
	minter = (int)(((pTelemetry->m_dGPSTime/1000/3600/24-day)*24-hour)*60);
	second = (int)((((pTelemetry->m_dGPSTime/1000/3600/24-day)*24-hour)*60-minter)*60);
	tempstr.Format("星期%d %2d:%2d:%2d",day,hour,minter,second);
	tempstr2 = "GPS时间:";
	tempstr2+=tempstr;
//	GPSTimeled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	//GPSTime.SetWindowText(tempstr2);//这里被xyg禁用，GPS时间在哪显示？

    //偏航距
	tempstr.Format("偏航距:%dm",pTelemetry->m_iYawDistance);
	pianhang.SetWindowText(tempstr);
    
	//距目标点//距起飞点//方位//总航点数//详见UpdateWayPoint

	//制式时间，就是：制式航线飞行剩余时间
	tempstr.Format("制式时间:%d秒",pTelemetry->m_iStandardTime);
	zhishishijian.SetWindowText(tempstr);
    
	//飞机：当前航点
	tempstr.Format("无人船:%lf,%lf",pTelemetry->m_GPSdata.m_dLongitude,pTelemetry->m_GPSdata.m_dLatitude);
	currentpoint.SetWindowText(tempstr);

	//打开关闭接收机，是m_iCurrentCondition2吗？
/*	if(pTelemetry->m_iCurrentCondition2 == 1)
	{
		//m_cClosereceive.SetWindowText("打开接收机");//xyg按钮
		//m_pGStationDlg->m_cToggleReceiver.SetWindowText("打开接收机");
		//receiverled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	}else
	{
		//m_cClosereceive.SetWindowText("关闭接收机");//xyg按钮
		//m_pGStationDlg->m_cToggleReceiver.SetWindowText("关闭接收机");
		//receiverled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	}*/
}
void CStaticStatus::UpdateXY(CString strX, CString strY)
{
	CString strTemp;
	strTemp.Format("鼠标:%s,%s",strX,strY);
	mousepoint.SetWindowText(strTemp);
}
void CStaticStatus::UpdateTotalDistance(double dDistance)
{
	CString strTemp;
	strTemp.Format("总距离:%.3f千米",dDistance);
	luchengyufangwei.SetWindowText(strTemp);
}
void CStaticStatus::UpdateCurrentDistance(double dDistance)
{
	CString strTemp;
	strTemp.Format("当前距离:%.3f千米",dDistance);
	CurrentDistance.SetWindowText(strTemp);
}
void CStaticStatus::UpdateCurrentAngle(double dAngle)
{
	CString strTemp;
	strTemp.Format("当前角度:%.1f度",dAngle);
	CurrentAngle.SetWindowText(strTemp);
}

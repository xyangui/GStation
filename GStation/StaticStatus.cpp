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

//������̬�ؼ�ʱ����Ҫ���Ի����ָ��
void CStaticStatus::Create(CGStationDlg *pGSDlg)
{
	m_pGStationDlg = pGSDlg;

	CRect rect;
	m_pGStationDlg->GetClientRect(&rect);

	int left = rect.left + 1;
	int top = rect.bottom - 20;
	int bottom = rect.bottom;
	int gap = 2;//2����̬��֮��ļ�϶
	int wide = (rect.right - rect.left - gap*8)/9;//8����϶����9��
	int LedWide = 25;

	//Ӧ���
	yingdaled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left,top,left+LedWide,bottom),m_pGStationDlg);
	//Ӧ���
	yingda.Create("",1342312960,CRect(left+LedWide,top,left+wide,bottom),m_pGStationDlg);
	int i1right = left+wide;

	//ͨѶ��
	tongxunled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+wide+gap,top,left+wide+gap+LedWide,bottom),m_pGStationDlg);
	//ͨѶ��
	tongxun.Create("",1342312960,CRect(left+wide+gap+LedWide,top,left+wide+gap+wide,bottom),m_pGStationDlg);
	int i2left = left+wide+gap;
	int i2right = left+wide+gap+wide;

	//ģʽ
	moshiled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+(wide+gap)*2,top,left+(wide+gap)*2+LedWide,bottom),m_pGStationDlg);
	moshi.Create("",1342312960,CRect(left+(wide+gap)*2+LedWide,top,left+(wide+gap)*2+wide,bottom),m_pGStationDlg);
	int i3left = left+(wide+gap)*2;
	int i3right = left+(wide+gap)*2+wide;

	//GPS
	GPSled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+(wide+gap)*3,top,left+(wide+gap)*3+LedWide,bottom),m_pGStationDlg);
	GPS.Create("",1342312960,CRect(left+(wide+gap)*3+LedWide,top,left+(wide+gap)*3+wide,bottom),m_pGStationDlg);
	int i4left = left+(wide+gap)*3;
	int i4right = left+(wide+gap)*3+wide;
	
	//����
	weixingled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+(wide+gap)*4,top,left+(wide+gap)*4+LedWide,bottom),m_pGStationDlg);
	weixing.Create("",1342312960,CRect(left+(wide+gap)*4+LedWide,top,left+(wide+gap)*4+wide,bottom),m_pGStationDlg);
	int i5left = left+(wide+gap)*4;
	int i5right = left+(wide+gap)*4+wide;

	//PDOP
	PDOPled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+(wide+gap)*5,top,left+(wide+gap)*5+LedWide,bottom),m_pGStationDlg);
	PDOP.Create("",1342312960,CRect(left+(wide+gap)*5+LedWide,top,left+(wide+gap)*5+wide,bottom),m_pGStationDlg);
	int i6left = left+(wide+gap)*5;
	int i6right = left+(wide+gap)*5+wide;

	//�����ѹ
	dianya_duojiled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+(wide+gap)*6,top,left+(wide+gap)*6+LedWide,bottom),m_pGStationDlg);
	dianya_duoji.Create("",1342312960,CRect(left+(wide+gap)*6+LedWide,top,left+(wide+gap)*6+wide,bottom),m_pGStationDlg);

	//�ܵ�ѹ
	dianya_zongled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+(wide+gap)*7,top,left+(wide+gap)*7+LedWide,bottom),m_pGStationDlg);
	dianya_zong.Create("",1342312960,CRect(left+(wide+gap)*7+LedWide,top,left+(wide+gap)*7+wide,bottom),m_pGStationDlg);

	//�¶�
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
	yingda.SetWindowText("Ӧ��:");
	
	tongxunled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDOFF));
	tongxun.SetWindowText("ͨѶ:");

	moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDOFF));
	moshi.SetWindowText("ģʽ:");
	
	GPSled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	GPS.SetWindowText("GPS:");
	
	weixingled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	weixing.SetWindowText("����:");	
	
	PDOPled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	PDOP.SetWindowText("PDOP: ");

	dianya_duojiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	dianya_duoji.SetWindowText("�����ѹ:");
	
	dianya_zongled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	dianya_zong.SetWindowText("�ܵ�ѹ:");
	
	wenduled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	wendu.SetWindowText("�¶�: ");

	left = rect.left + 5;
	top = rect.bottom - 45;
	bottom = rect.bottom - 25;
	//gap = 2;//2����̬��֮��ļ�϶
	//wide = (rect.right - 399 - left - gap*5)/6;//5����϶����6��

	//ƫ����
	pianhang.Create("",1342312960,CRect(left,top,i1right,bottom),m_pGStationDlg);
	//��Ŀ���
	distance_targetpoint.Create("",1342312960,CRect(i2left,top,i2right,bottom),m_pGStationDlg);
	//����ɵ�
	distance_zeropoint.Create("",1342312960,CRect(i3left,top,i3right,bottom),m_pGStationDlg);
	//��λ
	fangwei.Create("",1342312960,CRect(i4left,top,i4right,bottom),m_pGStationDlg);
	//�ܺ�����
	zonghangdian.Create("",1342312960,CRect(i5left,top,i5right,bottom),m_pGStationDlg);
	//��ʽʱ��
	zhishishijian.Create("",1342312960,CRect(i6left,top,i6right+37,bottom),m_pGStationDlg);

	pianhang.SetFont(font,TRUE);
	distance_zeropoint.SetFont(font,TRUE);
	distance_targetpoint.SetFont(font,TRUE);
	fangwei.SetFont(font,TRUE);
	zonghangdian.SetFont(font,TRUE);
	zhishishijian.SetFont(font,TRUE);

	pianhang.SetWindowText("ƫ����:");
	distance_zeropoint.SetWindowText("����ɵ�:");
	distance_targetpoint.SetWindowText("��Ŀ���:");
	fangwei.SetWindowText("��λ:");
	zonghangdian.SetWindowText("�ܺ�����:");
	zhishishijian.SetWindowText("��ʽʱ��:");

	top = top - 20 - 3;
	bottom = bottom - 20 - 3;
	//wide = wide*2 + gap;
	int iFirstThreeWide = (rect.right - 392 - left - gap*3)/4;//3����϶����4��

	//����
	mousepoint.Create("",1342312960,CRect(left,top,left+iFirstThreeWide+2,bottom),m_pGStationDlg);
	//�ɻ���
	currentpoint.Create("",1342312960,CRect(left+iFirstThreeWide+gap+2,top,i3right,bottom),m_pGStationDlg);
	//�ܾ���
	luchengyufangwei.Create("",1342312960,CRect(i4left,top,i4right,bottom),m_pGStationDlg);
	//��ǰ����
	CurrentDistance.Create("",1342312960,CRect(i5left,top,i5right,bottom),m_pGStationDlg);
	//��ǰ�Ƕ�
	CurrentAngle.Create("",1342312960,CRect(i6left,top,i6right+37,bottom),m_pGStationDlg);

	mousepoint.SetFont(font,TRUE);
	currentpoint.SetFont(font,TRUE);
	luchengyufangwei.SetFont(font,TRUE);
	CurrentDistance.SetFont(font,TRUE);
	CurrentAngle.SetFont(font,TRUE);

	mousepoint.SetWindowText("���:");
	currentpoint.SetWindowText("���˴�:");
	luchengyufangwei.SetWindowText("�ܾ���:");
	CurrentDistance.SetWindowText("��ǰ����:");
	CurrentAngle.SetWindowText("��ǰ�Ƕ�");
}

void CStaticStatus::UpdateWayPoint(CMsg_Telemetry *pTelemetry, CMapX &ctrlMapX)
{
	CString tempstr;
	//�ܺ�����//ʣ�ຽ�㱻ȥ������ʾ�ܺ���������
	CMapXLayer layer;
	layer = ctrlMapX.GetLayers().Item("WayPointDown");
	int iFeatureCount = layer.AllFeatures().GetCount();
	//int num = m_dFtrsNum-pTelemetry->m_nTargetWP;//xyg
	//int iRemainWayPointNum = iFeatureCount - pTelemetry->m_nTargetWP + 1;
	tempstr.Format("�ܺ�����:%d",iFeatureCount);
	//shengdian.SetWindowText(tempstr);
	zonghangdian.SetWindowText(tempstr);

	//��Ŀ���
	CWayPoint WayPoint;
	CMsg_WayPoint Msg_WayPoint;
	BOOL bOK = Msg_WayPoint.GetWayPointFromTab(WayPoint, ctrlMapX, _T("WayPointDown"), pTelemetry->m_iTargetWayPoint);
	if (!bOK) 
		return;
		
	double d = ctrlMapX.Distance(pTelemetry->m_GPSdata.m_dLongitude,pTelemetry->m_GPSdata.m_dLatitude, 
		WayPoint.dLongitude, WayPoint.dLatitude);//*1609/1000;
	//�����Ŀ��������û�е���ģ�m_WayPointUp��һ���ͷɿ��ϵ�m_WayPointDownһ�£���ͼ�в�һ����m_WayPointDown
	tempstr.Format("��Ŀ���:%5.3lfkm",d);
	distance_targetpoint.SetWindowText(tempstr);
	//double dd = ctrlMapX.Distance(123.53999159999999,41.827405700000000, 
		//126.13036099999999, 40.621136999999997);

    //����ɵ�
	bOK = Msg_WayPoint.GetWayPointFromTab(WayPoint, ctrlMapX, _T("WayPointDown"), 1);
	if (!bOK) 
		return;

	d = ctrlMapX.Distance(pTelemetry->m_GPSdata.m_dLongitude,pTelemetry->m_GPSdata.m_dLatitude, 
		WayPoint.dLongitude, WayPoint.dLatitude);//*1609/1000;
	tempstr.Format("����ɵ�:%5.3lfkm",d);
	distance_zeropoint.SetWindowText(tempstr);
	//double dd2 = ctrlMapX.Distance(123.53999159999999,41.827405700000000, 
		//126.82005300000000, 40.438020999999999);����Ĳ���ȷ



	//��λ����ʾ�ɻ��������ɵ㣨����1�㣩�ķ�λ��	
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
		angle = 0;//�������0���������룬����angle = 0
	}
	tempstr.Format("��λ:%.1lf��",angle);
	fangwei.SetWindowText(tempstr);
}

//���¾�̬�ؼ��Ͱ�ťʱ����Ҫ���Ի����CMsg_Telemetry��
void CStaticStatus::UpdateMsgTelemetry(CMsg_Telemetry *pTelemetry)//, CWayPoint *pWayPoint, int iRemainWayPointNum)
{
	CString tempstr;
	CString tempstr2;
    //Ӧ��
	yingdaled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDOFF));//��ɫ
	yingda.SetWindowText("Ӧ��:");	
	if(pTelemetry->m_iControlMode >= 16)//ң�����ݡ�������ģʽ����������������4λ=1ʱ����ʾ��Ӧ��
	{
		yingdaled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));//��ɫ
		yingda.SetWindowText("Ӧ��:��Ӧ��");
	}
	//ͨѶ
	tongxunled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	tongxun.SetWindowText("ͨѶ:����");
	for(int i=0; i<100000000; i++){//��ʱ��ʹ��ͨѶ:���ա����̵���˸
	}
	//Sleep(1000);
	tongxunled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDOFF));
	tongxun.SetWindowText("ͨѶ:");
	
    //ģʽ��������ģʽ
	if (pTelemetry->m_iControlMode >= 16) {//��4λΪ����Ӧ��λ��=1ʱ����Ӧ��
		pTelemetry->m_iControlMode = pTelemetry->m_iControlMode - 16;
	}
	if(pTelemetry->m_iControlMode ==0)
	{
		moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
		moshi.SetWindowText("ģʽ:UAV");
	}else if(pTelemetry->m_iControlMode ==1)
	{
		moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));//��ɫ
		moshi.SetWindowText("ģʽ:RC");
	}else if(pTelemetry->m_iControlMode ==2)
	{
		moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
		moshi.SetWindowText("ģʽ:RPV");
	}else if(pTelemetry->m_iControlMode ==3)
	{
		moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
		moshi.SetWindowText("ģʽ:CPV");
	}else{
		moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
		moshi.SetWindowText("ģʽ:����");//xyg���
	}

    //GPS��GPS��λ״��
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

    //���ǣ�������	
	if(pTelemetry->m_GPSdata.m_iSatelliteNum >= 4)
		weixingled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	else
		weixingled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	tempstr.Format("%d",pTelemetry->m_GPSdata.m_iSatelliteNum);
	tempstr2 = "����:";
	tempstr2+=tempstr;
	weixing.SetWindowText(tempstr2);
    
	//��ѹ	�ĳ�PDOP
/*
	tempstr.Format("%5.2lf",pTelemetry->m_fAirPress);
	tempstr2 = "��ѹ:";
	tempstr2+=tempstr;	
	PDOPled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	PDOP.SetWindowText(tempstr2);
*/  //PDOP
	if (pTelemetry->m_GPSdata.m_fPDOP < 5 && pTelemetry->m_GPSdata.m_fPDOP > 0) {//m_fPDOP���ڷ�ֵ5��ʾ�̵�
		PDOPled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	}else{
		PDOPled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	}
	tempstr.Format("%5.2lf",pTelemetry->m_GPSdata.m_fPDOP);
	tempstr2 = "PDOP:";
	tempstr2+=tempstr;	
	PDOP.SetWindowText(tempstr2);	

	//�����ѹ
	tempstr.Format("%2.2lfV",pTelemetry->m_fVoltageServo);
	tempstr2 = "�����ѹ:";
	tempstr2+=tempstr;
	if((pTelemetry->m_fVoltageServo > m_pGStationDlg->m_pSettingSheet->m_pageSetSafe.m_fServo_VMin)&&
		(pTelemetry->m_fVoltageServo < m_pGStationDlg->m_pSettingSheet->m_pageSetSafe.m_fServo_VMax))
		dianya_duojiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	else
		dianya_duojiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	dianya_duoji.SetWindowText(tempstr2);
	
	//�ܵ�ѹ	
	tempstr.Format("%2.2lfV",pTelemetry->m_fVoltageUAV);
	tempstr2 = "�ܵ�ѹ:";
	tempstr2+=tempstr;

	if((pTelemetry->m_fVoltageUAV > m_pGStationDlg->m_pSettingSheet->m_pageSetSafe.m_fPilot_VMin)&&
		(pTelemetry->m_fVoltageUAV < m_pGStationDlg->m_pSettingSheet->m_pageSetSafe.m_fPilot_VMax))
		dianya_zongled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	else
		dianya_zongled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	dianya_zong.SetWindowText(tempstr2);

    //�¶�	
	tempstr.Format("%2.1lf��",pTelemetry->m_fTemperature);
	tempstr2 = "�¶�:";
	tempstr2+=tempstr;	
	wenduled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	wendu.SetWindowText(tempstr2);
   
/////////////GPSʱ��
//	tempstr.Format("%2.3lf",pTelemetry->m_nWendu_Dianzu);
//	tempstr2 = "�����¶�:";
//	tempstr2+=tempstr;	
	int day,hour,minter,second;
	day = (int)pTelemetry->m_dGPSTime/1000/3600/24;
	hour = (int)((pTelemetry->m_dGPSTime/1000/3600/24-day)*24);
	minter = (int)(((pTelemetry->m_dGPSTime/1000/3600/24-day)*24-hour)*60);
	second = (int)((((pTelemetry->m_dGPSTime/1000/3600/24-day)*24-hour)*60-minter)*60);
	tempstr.Format("����%d %2d:%2d:%2d",day,hour,minter,second);
	tempstr2 = "GPSʱ��:";
	tempstr2+=tempstr;
//	GPSTimeled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	//GPSTime.SetWindowText(tempstr2);//���ﱻxyg���ã�GPSʱ��������ʾ��

    //ƫ����
	tempstr.Format("ƫ����:%dm",pTelemetry->m_iYawDistance);
	pianhang.SetWindowText(tempstr);
    
	//��Ŀ���//����ɵ�//��λ//�ܺ�����//���UpdateWayPoint

	//��ʽʱ�䣬���ǣ���ʽ���߷���ʣ��ʱ��
	tempstr.Format("��ʽʱ��:%d��",pTelemetry->m_iStandardTime);
	zhishishijian.SetWindowText(tempstr);
    
	//�ɻ�����ǰ����
	tempstr.Format("���˴�:%lf,%lf",pTelemetry->m_GPSdata.m_dLongitude,pTelemetry->m_GPSdata.m_dLatitude);
	currentpoint.SetWindowText(tempstr);

	//�򿪹رս��ջ�����m_iCurrentCondition2��
/*	if(pTelemetry->m_iCurrentCondition2 == 1)
	{
		//m_cClosereceive.SetWindowText("�򿪽��ջ�");//xyg��ť
		//m_pGStationDlg->m_cToggleReceiver.SetWindowText("�򿪽��ջ�");
		//receiverled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWARN));
	}else
	{
		//m_cClosereceive.SetWindowText("�رս��ջ�");//xyg��ť
		//m_pGStationDlg->m_cToggleReceiver.SetWindowText("�رս��ջ�");
		//receiverled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	}*/
}
void CStaticStatus::UpdateXY(CString strX, CString strY)
{
	CString strTemp;
	strTemp.Format("���:%s,%s",strX,strY);
	mousepoint.SetWindowText(strTemp);
}
void CStaticStatus::UpdateTotalDistance(double dDistance)
{
	CString strTemp;
	strTemp.Format("�ܾ���:%.3fǧ��",dDistance);
	luchengyufangwei.SetWindowText(strTemp);
}
void CStaticStatus::UpdateCurrentDistance(double dDistance)
{
	CString strTemp;
	strTemp.Format("��ǰ����:%.3fǧ��",dDistance);
	CurrentDistance.SetWindowText(strTemp);
}
void CStaticStatus::UpdateCurrentAngle(double dAngle)
{
	CString strTemp;
	strTemp.Format("��ǰ�Ƕ�:%.1f��",dAngle);
	CurrentAngle.SetWindowText(strTemp);
}

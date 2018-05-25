// Msg_WayPoint.cpp: implementation of the CMsg_WayPoint class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "Msg_WayPoint.h"

#include "Payload.h"
#include "Packet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CMsg_WayPoint::CMsg_WayPoint()
{
}
const int CMsg_WayPoint::MSG_ID = 0x12;//��������
const int CMsg_WayPoint::MSG_SIZE_PAYLOAD_LENGTH = 18;//�������������͡���С��У��ͣ���18���ֽ�
CMsg_WayPoint::~CMsg_WayPoint()
{
}
//���ݰ�����ֻ���һ�����㡣���浽"WayPointDown"��tab�У�û��һ���´����к������ݰ��Ķ��塣
void CMsg_WayPoint::UnpackSaveToTab(CPayload payload, CMapX &ctrlMapX)
{
	CWayPoint WayPoint;
	payload.resetIndex();           //�������������index=0

	int iTotalNum = payload.getU1();//������������֪��ʲô�ط��õ�
	int iWP_Num = payload.getU1();  //������ţ�����Ŵ����С��˳��
	WayPoint.iNum = iWP_Num;

	WayPoint.dLongitude = (double)payload.getI4h() / 10000000;
	WayPoint.dLatitude = (double)payload.getI4h() / 10000000;

	WayPoint.iAltitude = payload.getU2h();
	WayPoint.iSpeed = payload.getU1();
	WayPoint.iRadius = payload.getU2h();

	int iMark = payload.getU1();//��־�ֽ�
	WayPoint.iStandardModel = iMark % 8;

	if((iMark & 8) == 8)
		WayPoint.bToLine = TRUE;
	else 
		WayPoint.bToLine = FALSE;

	if((iMark & 16) == 16)
		WayPoint.bToGround = TRUE;
	else
		WayPoint.bToGround = FALSE;

	if((iMark & 32) == 32)
		WayPoint.bToSlope = TRUE;
	else
		WayPoint.bToSlope = FALSE;

	if((iMark & 64) == 64)
		WayPoint.bPhoto = TRUE;
	else 
		WayPoint.bPhoto = FALSE;

	WayPoint.iTime = payload.getU1();

	int iTask = payload.getU1();
	//���������ƣ�λ0�����1��λ1�����2��λ2��7����������ÿλ��0��1�ֱ��������Ԥ��״̬
	if((iTask & 1) == 1)
		WayPoint.bServo1 = TRUE;
	else 
		WayPoint.bServo1 = FALSE;

	if((iTask & 2) == 2)
		WayPoint.bServo2 = TRUE;
	else 
		WayPoint.bServo2 = FALSE;

	if((iTask & 3) == 3)
		WayPoint.bServo3 = TRUE;
	else
		WayPoint.bServo3 = FALSE;

	//��WayPoint���浽tab��
	SaveWayPointToTab(WayPoint, ctrlMapX, _T("WayPointDown"));
}
//����һ������OneWayPoint������ΪstrLayName�ĵ�ͼ����
void CMsg_WayPoint::SaveWayPointToTab(CWayPoint OneWayPoint, CMapX &ctrlMapX, CString strLayName)
{
	try {  
		int flag = OneWayPoint.iStandardModel + OneWayPoint.bToLine * 8 + 
			OneWayPoint.bToGround * 16 + OneWayPoint.bToSlope * 32 + 
			OneWayPoint.bPhoto * 64;
		//int time = OneWayPoint.iTime / 10;//�ӷɿش�������ֵ*10=�����ϵ��룬������10�룬�ɿ�Ϊ1
		int time = OneWayPoint.iTime;  //��Ӧ�ó�10
		int task = OneWayPoint.bServo1 + OneWayPoint.bServo2 * 2 +
			OneWayPoint.bServo3 * 4;

		CMapXFeature feature;
		feature.CreateDispatch(feature.GetClsid());
		feature.Attach(ctrlMapX.GetDispatch());
		
		feature.SetType(miFeatureTypeSymbol);
		//feature.SetStyle(ctrlMapX.GetDefaultStyle());
		feature.GetPoint().Set(OneWayPoint.dLongitude, OneWayPoint.dLatitude);
		
		CMapXFeature objFeature; 
		objFeature = ctrlMapX.GetLayers().Item(strLayName).AddFeature(feature);
		
		VARIANT lyrVt;
		lyrVt.vt = VT_DISPATCH;
		lyrVt.pdispVal = ctrlMapX.GetLayers().Item(strLayName);
		lyrVt.pdispVal->AddRef();
		
		CString str_key;
		CMapXLayer lay = ctrlMapX.GetLayers().Item(strLayName);
		
		lay.SetKeyField("altitude");
		str_key.Format("%d",OneWayPoint.iAltitude);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("speed");
		str_key.Format("%d",OneWayPoint.iSpeed);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("radius");
		str_key.Format("%d",OneWayPoint.iRadius);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("flag");
		str_key.Format("%d",flag);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("time");
		str_key.Format("%d",time);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("servo");
		str_key.Format("%d",task);//potdata.m_WayPointDown[i].toline);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("num");//num����ͼ�е����1,2,3...
		str_key.Format("%d",OneWayPoint.iNum);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.Refresh();//�����ˢ�£���ţ�1,2,3...ֻ��ʾһ�룬
	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();
	}
}
//���ݰ�������ȡ�ɿ��ڲ����㡣num=0�´����к��㣬num!=0�´���ӦnumΪ������ŵĺ���
CPacket CMsg_WayPoint::GetWayPointPack(int num)
{
	int numTemp;
	if(num < 0 || num > 100)
		numTemp = 0;
	else
		numTemp = num;

	CPacket  packet;
	packet.m_msgid = MSG_ID;
	packet.m_len = 1;//��һ���ֽ�

	packet.payload.putU1(numTemp);
	packet.generateCRC();
	return packet;
}
//���ݰ��������÷ɿ�һ�����㡣ֻ�������ΪWayPointNum�ĺ��㣬������������
CPacket CMsg_WayPoint::UpLoadOneWayPointPacket(CMapX &ctrlMapX, int iWayPointNum)
{
	CWayPoint WayPoint;
	GetWayPointFromTab(WayPoint, ctrlMapX, _T("WayPointStation"), iWayPointNum);

	CPacket  packet;
	packet.m_msgid = MSG_ID;
	packet.m_len = 17;

	packet.payload.putU1(WayPoint.iNum);
	packet.payload.putI4h((int)(WayPoint.dLongitude * 10000000));
	packet.payload.putI4h((int)(WayPoint.dLatitude * 10000000));

	packet.payload.putU2h(WayPoint.iAltitude);
	packet.payload.putU1(WayPoint.iSpeed);
	packet.payload.putU2h(WayPoint.iRadius);

	int flag = WayPoint.iStandardModel + WayPoint.bToLine*8 +
		WayPoint.bToGround*16 + WayPoint.bToSlope*32 + WayPoint.bPhoto*64;
	//int time = WayPoint.iTime/10;//��������
	int time = (WayPoint.iTime + 5) / 10;
	int sver = WayPoint.bServo1 + WayPoint.bServo2*2 + WayPoint.bServo3*4;

	packet.payload.putU1(flag);
	packet.payload.putU1(time);
	packet.payload.putU1(sver);

	packet.generateCRC();
	return packet;
}
//���ݰ��������÷ɿ����к��㡣packet��ȷ����TRUE��packet���󷵻�FALSE
BOOL CMsg_WayPoint::UpLoadAllWayPointPacket(CPacket &packet, CMapX &ctrlMapX)
{
	int iWayPointCount = 0;
	try {
		CMapXLayer lay = ctrlMapX.GetLayers().Item(_T("WayPointStation"));
		iWayPointCount = lay.AllFeatures().GetCount();//��������
	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();
	}
	if (iWayPointCount == 0) 
		return FALSE;	

	packet.m_msgid = MSG_ID;

	packet.m_len = iWayPointCount * 17 + 1;;
	packet.payload.putU1(iWayPointCount);

	for(int i = 1; i <= iWayPointCount; i++)
	{
		CWayPoint WayPoint;
		GetWayPointFromTab(WayPoint, ctrlMapX, _T("WayPointStation"), i);

		packet.payload.putU1(WayPoint.iNum);
		packet.payload.putI4h((int)(WayPoint.dLongitude * 10000000));
		packet.payload.putI4h((int)(WayPoint.dLatitude * 10000000));
		
		packet.payload.putU2h(WayPoint.iAltitude);
		packet.payload.putU1(WayPoint.iSpeed);
		packet.payload.putU2h(WayPoint.iRadius);
		
		int flag = WayPoint.iStandardModel + WayPoint.bToLine*8 +
			WayPoint.bToGround*16 + WayPoint.bToSlope*32 + WayPoint.bPhoto*64;
		int time = WayPoint.iTime/10;
		//int time = (WayPoint.iTime + 5) / 10;//��������
		int sver = WayPoint.bServo1 + WayPoint.bServo2*2 + WayPoint.bServo3*4;
		
		packet.payload.putU1(flag);
		packet.payload.putU1(time);
		packet.payload.putU1(sver);
	}
	packet.generateCRC();
	return TRUE;
}
//�������صĺ��㵽������Ʋ㣬WayPointDown����>WayPointStation
void CMsg_WayPoint::CopyWayPointFromDownToUp(CMapX &ctrlMapX)
{
	int iFeatureCount = 0;
	try {
		iFeatureCount = ctrlMapX.GetLayers().Item("WayPointDown").AllFeatures().GetCount();
		if (iFeatureCount == 0) 
			return;
		
		//ɾ��WayPointStation������ͼԪ
		DeleteAllFeature(ctrlMapX, _T("WayPointStation"));
	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();
	}
	for(int i = 1; i <= iFeatureCount; i++)
	{
		CWayPoint WayPoint;
		//��tab�ļ�����ͼ����ΪstrLayer���еõ����ΪiWayPointNum�ĺ���WayPoint
		GetWayPointFromTab(WayPoint, ctrlMapX, _T("WayPointDown"), i);
		//��WayPoint���浽tab��
		SaveWayPointToTab(WayPoint, ctrlMapX, _T("WayPointStation"));
	}
}
//�ڵ�ͼ��strLayName�У�ɾ�����к���
void CMsg_WayPoint::DeleteAllFeature(CMapX &ctrlMapX, CString strLayName)
{
	try {  
		CMapXLayer layer = ctrlMapX.GetLayers().Item(strLayName);
		layer.SetEditable(TRUE);
		
		CMapXFeatures features; 
		features = layer.AllFeatures();	
		int iCount = features.GetCount();//���WayPointDown��ʲôҲû�У�iCount=0
		
		CMapXFeature fea;
		for(int i = 1; i <= iCount; i++)
		{	
			fea = features.Item(i);
			layer.DeleteFeature(fea);
		}
		layer.Pack(miPackAll);//���dataset�пհ���
		layer.Refresh();  
		//lay.Pack(miPackAll);��MapXDataset.Refresh();����ͬʱ���ڣ�MapXDataset.GetRowCount();������ȷֵ
	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();
	}
}
//�ڵ�ͼ��strLayName�У�ɾ���������ΪiWayPointNum��CMapXFeature
void CMsg_WayPoint::DeleteFeatureFromWPNum(CMapX &ctrlMapX, CString strLayName, int iWayPointNum)
{
	try {
		int iFeatureNum = 0;
		iFeatureNum = GetFeatureNumFromWPNum(ctrlMapX, strLayName, iWayPointNum);
		if (iFeatureNum == 0) 
			return;
		
		CMapXLayer layer = ctrlMapX.GetLayers().Item(strLayName);
		layer.SetEditable(TRUE);
		
		CMapXFeature fea;
		fea = layer.AllFeatures().Item(iFeatureNum);
		layer.DeleteFeature(fea);
		layer.Pack(miPackAll);
		layer.Refresh(); 
	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();
	}
}
//�ڵ�ͼ��strLayName�У��ҵ��������ΪiWayPointNum��CMapXFeature��ţ�������
//iWayPointNumΪ��ʾ�ڵ�ͼ�ϵı�ǩ��=WayPoint.iNum����ͼ���е�CMapXFeature˳��һ����һ�µ�
int CMsg_WayPoint::GetFeatureNumFromWPNum(CMapX &ctrlMapX, CString strLayName, int iWayPointNum)
{
	int iFeatureNum = 0;
	try {
		VARIANT lyrVt;
		lyrVt.vt = VT_DISPATCH;
		lyrVt.pdispVal = ctrlMapX.GetLayers().Item(strLayName);
		lyrVt.pdispVal->AddRef();
		
		CMapXDataset MapXDataset = ctrlMapX.GetDatasets().Add(miDataSetLayer,lyrVt);
		int iRowCount = MapXDataset.GetRowCount();//Dataset��¼��	
		//��Ϊ�ɿ��ȴ���Ŵ�ĺ��㣬ɾ��һ����features.Item����뺽�����˳������
		for(int i = 1; i <= iRowCount; i++)
		{
			VARIANT Vt;
			Vt = MapXDataset.GetRowValues(i).Item(1).GetValue();
			double value = Vt.date;
			if (iWayPointNum == (int)value) {
				iFeatureNum = i;//�ҵ�iWayPointNum������Ŷ�Ӧ��features.Item(���iFeatureNum)
				break;
			}
		}
	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();
	}
	return iFeatureNum;
}
//��tab�ļ�����ͼ����ΪstrLayer���еõ����ΪiWayPointNum�ĺ���WayPoint��iWayPointNumΪ������ţ�����CMapXFeature���
//�ҵ�����TRUE��û�ҵ�����FALSE
BOOL CMsg_WayPoint::GetWayPointFromTab(CWayPoint &WayPoint, CMapX &ctrlMapX, CString strLayer, int iWayPointNum)
{
	try {
		int iFeatureNum = GetFeatureNumFromWPNum(ctrlMapX, strLayer, iWayPointNum);
		if (iFeatureNum == 0)//û�ҵ����ΪiWayPointNum�ĺ����ڵ�ͼ�е�Feature 
			return FALSE;
		
		VARIANT lyrVt;
		lyrVt.vt = VT_DISPATCH;
		lyrVt.pdispVal = ctrlMapX.GetLayers().Item(strLayer);
		lyrVt.pdispVal->AddRef();
		
		CMapXDataset MapXDataset = ctrlMapX.GetDatasets().Add(miDataSetLayer,lyrVt);
		CMapXLayer lay = ctrlMapX.GetLayers().Item(strLayer);
		//int iWayPointCount = lay.AllFeatures().GetCount();	
		//int iRowCount = MapXDataset.GetRowCount();//Dataset��¼��
		//for(int i = 1; i <= iWayPointCount; i++)
		//{
		CMapXPoint pt = lay.AllFeatures().Item(iFeatureNum).GetPoint();
		WayPoint.dLongitude = pt.GetX();
		WayPoint.dLatitude = pt.GetY();
		
		//CString str;
		//str.Format("%d",iFeatureNum);
		//lay.SetKeyField("num");
		//lay.AllFeatures().Item(iFeatureNum).SetKeyValue(str);
		
		VARIANT Vt;
		Vt = MapXDataset.GetRowValues(iFeatureNum).Item(1).GetValue();
		double value = Vt.date;
		WayPoint.iNum = (int)value;
		
		Vt = MapXDataset.GetRowValues(iFeatureNum).Item(2).GetValue();
		value = Vt.date;
		WayPoint.iAltitude = (int)value;
		
		Vt = MapXDataset.GetRowValues(iFeatureNum).Item(3).GetValue();
		value = Vt.date;
		WayPoint.iSpeed = (int)value;
		
		Vt = MapXDataset.GetRowValues(iFeatureNum).Item(4).GetValue();
		value = Vt.date;
		WayPoint.iRadius = (int)value;
		
		Vt = MapXDataset.GetRowValues(iFeatureNum).Item(5).GetValue();
		value = Vt.date;
		WayPoint.iStandardModel = (int)value & 7;
		
		int c;//��ȡ�ֽڵ�λ
		c = (int)value & 8;
		if(c == 0)
			WayPoint.bToLine = FALSE;
		else
			WayPoint.bToLine = TRUE;
		
		c = (int)value & 16;
		if(c == 0)
			WayPoint.bToGround = FALSE;
		else
			WayPoint.bToGround = TRUE;
		
		c = (int)value & 32;
		if(c == 0)
			WayPoint.bToSlope = FALSE;
		else
			WayPoint.bToSlope = TRUE;
		
		c = (int)value & 64;
		if(c == 0)
			WayPoint.bPhoto = FALSE;
		else
			WayPoint.bPhoto = TRUE;
		
		Vt = MapXDataset.GetRowValues(iFeatureNum).Item(6).GetValue();
		value = Vt.date;
		WayPoint.iTime = (int)(value * 10);
		
		Vt = MapXDataset.GetRowValues(iFeatureNum).Item(7).GetValue();
		value = Vt.date;
		c=(int)value & 1;
		if(c == 0)
			WayPoint.bServo1 = FALSE;
		else
			WayPoint.bServo1 = TRUE;
		
		c=(int)value & 2;
		if(c == 0)
			WayPoint.bServo2 = FALSE;
		else
			WayPoint.bServo2 = TRUE;
		
		c=(int)value & 4;
		if(c == 0)
			WayPoint.bServo3 = FALSE;
		else
			WayPoint.bServo3 = TRUE;
		//}
	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();
	}
	return TRUE;
}
/*��tab�ļ��У���ȡ������Ϣ�����浽m_WayPointUp[100]�ṹ����
void CMsg_WayPoint::GetWayPointUpFromTab(CMapX &ctrlMapX)
{
	VARIANT lyrVt;
	lyrVt.vt = VT_DISPATCH;
	lyrVt.pdispVal = ctrlMapX.GetLayers().Item("WayPointStation");
	lyrVt.pdispVal->AddRef();

	CMapXDataset MapXDataset = ctrlMapX.GetDatasets().Add(miDataSetLayer,lyrVt);

	CMapXLayer lay = ctrlMapX.GetLayers().Item("WayPointStation");
	int iWayPointCount = lay.AllFeatures().GetCount();
	m_WayPointUpCount = iWayPointCount;
	
	//int num2 = MapXDataset.GetRowCount();//Dataset��¼��
	
	for(int i = 1; i <= iWayPointCount; i++)
	{
		CMapXPoint pt = lay.AllFeatures().Item(i).GetPoint();
		m_WayPointUp[i].dLongitude = pt.GetX();
		m_WayPointUp[i].dLatitude = pt.GetY();

		//���浽m_CMapXPoints�У�m_CMapXPoints�������ô�С���Զ�����////�����浽CGStationDlg�е�m_CMapXPoints��
		//pGStationDlg->m_CMapXPoints.Add(pt, i);//iΪ1��Points.Count����//m_CMapXPointsû�õ����Ѿ�ɾ��
	
		CString str;
		str.Format("%d",i);
		lay.SetKeyField("num");
		lay.AllFeatures().Item(i).SetKeyValue(str);
	
		VARIANT Vt;
		Vt = MapXDataset.GetRowValues(i).Item(1).GetValue();
		double value = Vt.date;
		m_WayPointUp[i].iNum = (int)value;

		Vt = MapXDataset.GetRowValues(i).Item(2).GetValue();
		value = Vt.date;
		m_WayPointUp[i].iAltitude = (int)value;

		Vt = MapXDataset.GetRowValues(i).Item(3).GetValue();
		value = Vt.date;
		m_WayPointUp[i].iSpeed = (int)value;

		Vt = MapXDataset.GetRowValues(i).Item(4).GetValue();
		value = Vt.date;
		m_WayPointUp[i].iRadius = (int)value;

		Vt = MapXDataset.GetRowValues(i).Item(5).GetValue();
		value = Vt.date;
		m_WayPointUp[i].iStandardModel = (int)value & 7;

		int c;//��ȡ�ֽڵ�λ
		c = (int)value & 8;
		if(c == 0)
			m_WayPointUp[i].bToLine = FALSE;
		else
			m_WayPointUp[i].bToLine = TRUE;

		c = (int)value & 16;
		if(c == 0)
			m_WayPointUp[i].bToGround = FALSE;
		else
			m_WayPointUp[i].bToGround = TRUE;

		c = (int)value & 32;
		if(c == 0)
			m_WayPointUp[i].bToSlope = FALSE;
		else
			m_WayPointUp[i].bToSlope = TRUE;

		c = (int)value & 64;
		if(c == 0)
			m_WayPointUp[i].bPhoto = FALSE;
		else
			m_WayPointUp[i].bPhoto = TRUE;

		Vt = MapXDataset.GetRowValues(i).Item(6).GetValue();
		value = Vt.date;
		m_WayPointUp[i].iTime = (int)(value * 10);

		Vt = MapXDataset.GetRowValues(i).Item(7).GetValue();
		value = Vt.date;
		c=(int)value & 1;
		if(c == 0)
			m_WayPointUp[i].bServo1 = FALSE;
		else
			m_WayPointUp[i].bServo1 = TRUE;

		c=(int)value & 2;
		if(c == 0)
			m_WayPointUp[i].bServo2 = FALSE;
		else
			m_WayPointUp[i].bServo2 = TRUE;

		c=(int)value & 4;
		if(c == 0)
			m_WayPointUp[i].bServo3 = FALSE;
		else
			m_WayPointUp[i].bServo3 = TRUE;
	}
}*/
/*
void CMsg_WayPoint::CopyWayPointFromTo(WayPoint &WP_To, WayPoint &WP_From)
{
	WP_To.iNum = WP_From.iNum;
	WP_To.dLongitude = WP_From.dLongitude;
	WP_To.dLatitude = WP_From.dLatitude;
	WP_To.iAltitude = WP_From.iAltitude;
	WP_To.iSpeed = WP_From.iSpeed;
	WP_To.iRadius = WP_From.iRadius;
	WP_To.iTime = WP_From.iTime;
	WP_To.iStandardModel = WP_From.iStandardModel;
	WP_To.bToLine = WP_From.bToLine;
	WP_To.bToGround = WP_From.bToGround;	
	WP_To.bToSlope = WP_From.bToSlope;
	WP_To.bPhoto = WP_From.bPhoto;
	WP_To.bServo1 = WP_From.bServo1;
	WP_To.bServo2 = WP_From.bServo2;	
	WP_To.bServo3 = WP_From.bServo3;
}*/

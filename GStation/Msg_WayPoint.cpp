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
const int CMsg_WayPoint::MSG_ID = 0x12;//命令类型
const int CMsg_WayPoint::MSG_SIZE_PAYLOAD_LENGTH = 18;//不包括命令类型、大小、校验和，共18个字节
CMsg_WayPoint::~CMsg_WayPoint()
{
}
//数据包——只拆解一个航点。保存到"WayPointDown"的tab中，没有一次下传所有航点数据包的定义。
void CMsg_WayPoint::UnpackSaveToTab(CPayload payload, CMapX &ctrlMapX)
{
	CWayPoint WayPoint;
	payload.resetIndex();           //必须调用它，把index=0

	int iTotalNum = payload.getU1();//航点总数，不知道什么地方用到
	int iWP_Num = payload.getU1();  //航点序号，从序号大到序号小的顺序传
	WayPoint.iNum = iWP_Num;

	WayPoint.dLongitude = (double)payload.getI4h() / 10000000;
	WayPoint.dLatitude = (double)payload.getI4h() / 10000000;

	WayPoint.iAltitude = payload.getU2h();
	WayPoint.iSpeed = payload.getU1();
	WayPoint.iRadius = payload.getU2h();

	int iMark = payload.getU1();//标志字节
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
	//任务舵机控制（位0：舵机1；位1：舵机2；位2～7：保留），每位的0和1分别代表两个预设状态
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

	//把WayPoint保存到tab中
	SaveWayPointToTab(WayPoint, ctrlMapX, _T("WayPointDown"));
}
//保存一个航点OneWayPoint到层名为strLayName的地图层中
void CMsg_WayPoint::SaveWayPointToTab(CWayPoint OneWayPoint, CMapX &ctrlMapX, CString strLayName)
{
	try {  
		int flag = OneWayPoint.iStandardModel + OneWayPoint.bToLine * 8 + 
			OneWayPoint.bToGround * 16 + OneWayPoint.bToSlope * 32 + 
			OneWayPoint.bPhoto * 64;
		//int time = OneWayPoint.iTime / 10;//从飞控传过来的值*10=界面上的秒，即界面10秒，飞控为1
		int time = OneWayPoint.iTime;  //不应该除10
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
		
		lay.SetKeyField("num");//num就是图中的序号1,2,3...
		str_key.Format("%d",OneWayPoint.iNum);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.Refresh();//如果不刷新，序号，1,2,3...只显示一半，
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
//数据包——获取飞控内部航点。num=0下传所有航点，num!=0下传对应num为航点序号的航点
CPacket CMsg_WayPoint::GetWayPointPack(int num)
{
	int numTemp;
	if(num < 0 || num > 100)
		numTemp = 0;
	else
		numTemp = num;

	CPacket  packet;
	packet.m_msgid = MSG_ID;
	packet.m_len = 1;//就一个字节

	packet.payload.putU1(numTemp);
	packet.generateCRC();
	return packet;
}
//数据包——设置飞控一个航点。只更新序号为WayPointNum的航点，航点总数不变
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
	//int time = WayPoint.iTime/10;//整除不对
	int time = (WayPoint.iTime + 5) / 10;
	int sver = WayPoint.bServo1 + WayPoint.bServo2*2 + WayPoint.bServo3*4;

	packet.payload.putU1(flag);
	packet.payload.putU1(time);
	packet.payload.putU1(sver);

	packet.generateCRC();
	return packet;
}
//数据包——设置飞控所有航点。packet正确返回TRUE，packet错误返回FALSE
BOOL CMsg_WayPoint::UpLoadAllWayPointPacket(CPacket &packet, CMapX &ctrlMapX)
{
	int iWayPointCount = 0;
	try {
		CMapXLayer lay = ctrlMapX.GetLayers().Item(_T("WayPointStation"));
		iWayPointCount = lay.AllFeatures().GetCount();//航点总数
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
		//int time = (WayPoint.iTime + 5) / 10;//整除不对
		int sver = WayPoint.bServo1 + WayPoint.bServo2*2 + WayPoint.bServo3*4;
		
		packet.payload.putU1(flag);
		packet.payload.putU1(time);
		packet.payload.putU1(sver);
	}
	packet.generateCRC();
	return TRUE;
}
//拷贝下载的航点到航点设计层，WayPointDown——>WayPointStation
void CMsg_WayPoint::CopyWayPointFromDownToUp(CMapX &ctrlMapX)
{
	int iFeatureCount = 0;
	try {
		iFeatureCount = ctrlMapX.GetLayers().Item("WayPointDown").AllFeatures().GetCount();
		if (iFeatureCount == 0) 
			return;
		
		//删除WayPointStation层所有图元
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
		//从tab文件（地图层名为strLayer）中得到序号为iWayPointNum的航点WayPoint
		GetWayPointFromTab(WayPoint, ctrlMapX, _T("WayPointDown"), i);
		//把WayPoint保存到tab中
		SaveWayPointToTab(WayPoint, ctrlMapX, _T("WayPointStation"));
	}
}
//在地图层strLayName中，删除所有航点
void CMsg_WayPoint::DeleteAllFeature(CMapX &ctrlMapX, CString strLayName)
{
	try {  
		CMapXLayer layer = ctrlMapX.GetLayers().Item(strLayName);
		layer.SetEditable(TRUE);
		
		CMapXFeatures features; 
		features = layer.AllFeatures();	
		int iCount = features.GetCount();//如果WayPointDown层什么也没有，iCount=0
		
		CMapXFeature fea;
		for(int i = 1; i <= iCount; i++)
		{	
			fea = features.Item(i);
			layer.DeleteFeature(fea);
		}
		layer.Pack(miPackAll);//清除dataset中空白行
		layer.Refresh();  
		//lay.Pack(miPackAll);和MapXDataset.Refresh();必须同时存在，MapXDataset.GetRowCount();才是正确值
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
//在地图层strLayName中，删除航点序号为iWayPointNum的CMapXFeature
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
//在地图层strLayName中，找到航点序号为iWayPointNum的CMapXFeature序号，并返回
//iWayPointNum为显示在地图上的标签，=WayPoint.iNum，与图层中的CMapXFeature顺序不一定是一致的
int CMsg_WayPoint::GetFeatureNumFromWPNum(CMapX &ctrlMapX, CString strLayName, int iWayPointNum)
{
	int iFeatureNum = 0;
	try {
		VARIANT lyrVt;
		lyrVt.vt = VT_DISPATCH;
		lyrVt.pdispVal = ctrlMapX.GetLayers().Item(strLayName);
		lyrVt.pdispVal->AddRef();
		
		CMapXDataset MapXDataset = ctrlMapX.GetDatasets().Add(miDataSetLayer,lyrVt);
		int iRowCount = MapXDataset.GetRowCount();//Dataset记录数	
		//因为飞控先传序号大的航点，删除一个后，features.Item序号与航点序号顺序乱套
		for(int i = 1; i <= iRowCount; i++)
		{
			VARIANT Vt;
			Vt = MapXDataset.GetRowValues(i).Item(1).GetValue();
			double value = Vt.date;
			if (iWayPointNum == (int)value) {
				iFeatureNum = i;//找到iWayPointNum航点序号对应的features.Item(序号iFeatureNum)
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
//从tab文件（地图层名为strLayer）中得到序号为iWayPointNum的航点WayPoint，iWayPointNum为航点序号，不是CMapXFeature序号
//找到返回TRUE，没找到返回FALSE
BOOL CMsg_WayPoint::GetWayPointFromTab(CWayPoint &WayPoint, CMapX &ctrlMapX, CString strLayer, int iWayPointNum)
{
	try {
		int iFeatureNum = GetFeatureNumFromWPNum(ctrlMapX, strLayer, iWayPointNum);
		if (iFeatureNum == 0)//没找到序号为iWayPointNum的航点在地图中的Feature 
			return FALSE;
		
		VARIANT lyrVt;
		lyrVt.vt = VT_DISPATCH;
		lyrVt.pdispVal = ctrlMapX.GetLayers().Item(strLayer);
		lyrVt.pdispVal->AddRef();
		
		CMapXDataset MapXDataset = ctrlMapX.GetDatasets().Add(miDataSetLayer,lyrVt);
		CMapXLayer lay = ctrlMapX.GetLayers().Item(strLayer);
		//int iWayPointCount = lay.AllFeatures().GetCount();	
		//int iRowCount = MapXDataset.GetRowCount();//Dataset记录数
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
		
		int c;//获取字节单位
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
/*从tab文件中，读取航点信息，保存到m_WayPointUp[100]结构体中
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
	
	//int num2 = MapXDataset.GetRowCount();//Dataset记录数
	
	for(int i = 1; i <= iWayPointCount; i++)
	{
		CMapXPoint pt = lay.AllFeatures().Item(i).GetPoint();
		m_WayPointUp[i].dLongitude = pt.GetX();
		m_WayPointUp[i].dLatitude = pt.GetY();

		//保存到m_CMapXPoints中，m_CMapXPoints不用设置大小，自动增长////并保存到CGStationDlg中的m_CMapXPoints中
		//pGStationDlg->m_CMapXPoints.Add(pt, i);//i为1至Points.Count整数//m_CMapXPoints没用到，已经删除
	
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

		int c;//获取字节单位
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

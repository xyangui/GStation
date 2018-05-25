// CFlyGPSPointRecord.cpp: implementation of the CFlyGPSPointRecord class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "FlyGPSPointRecord.h"

#include "Msg_Telemetry.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CFlyGPSPointRecord::CFlyGPSPointRecord()
{
}
//只能有一个CFlyGPSPointRecord对象，即构造函数只能执行一次，因为执行两次时，原来存在“FlyGPSPoint”，有冲突。
CFlyGPSPointRecord::CFlyGPSPointRecord(CMapX &ctrlMapX)
{
	//此函数功能：在record文件夹下创建%d年%d月%d日%d点%d分%d秒.tab文件，用来存储飞控传过来的“遥测数据”
	char pFileName[256];   
	int nPos = GetCurrentDirectory(256, pFileName);//得到当前路径函数，后面没有"\"   
	if( nPos < 0 ){
		AfxMessageBox("无法得到当前路径！");
		return;   
	}
	CString csFullPath(pFileName); 

	CTime time;
	time = CTime::GetCurrentTime();

	CString strTemp;
	strTemp.Format("%d-%d-%d-%d-%d-%d", time.GetYear(), time.GetMonth(), 
		time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());

	CString strPathFileName;
	strPathFileName.Format("%s\\record\\%s.tab", csFullPath, strTemp);
	
	try
	{
		CMapXLayerInfo layerinfo;
		if( !layerinfo.CreateDispatch( layerinfo.GetClsid() ) ) 
			return ;  
		layerinfo.SetType(miLayerInfoTypeNewTable);     //新建图层类型
		
		VARIANT sVt;
		sVt.vt = VT_BSTR;
		sVt.bstrVal = strPathFileName.AllocSysString();//应该是图层与tab文件绑定
		layerinfo.AddParameter("FileSpec", sVt); 
		layerinfo.AddParameter("Name",COleVariant("FlyGPSPoint"));//飞机或船实际飞行的GPS航点层，即轨迹层
		
		CMapXFields fields;
		if( !fields.CreateDispatch( fields.GetClsid() ) )
			return ; 
		
		fields.AddIntegerField("controlmode",FALSE);    //控制模式
		fields.AddIntegerField("gpsxd",FALSE);          //GPS定位情况
		fields.AddIntegerField("pdop",FALSE);           //PDOP定位质量
		fields.AddIntegerField("satellitenum",FALSE);   //有效卫星数
		
		//fields.AddFloatField("longitude",FALSE);        //经度
		//fields.AddFloatField("latitude",FALSE);         //纬度
		fields.AddStringField("longitude",13,FALSE);    //经度
		fields.AddStringField("latitude",13,FALSE);     //纬度

		fields.AddFloatField("gpsaltitude",FALSE);      //高度
		fields.AddFloatField("gpsspeed",FALSE);         //水平速度
		fields.AddFloatField("direction",FALSE);        //航向

		fields.AddFloatField("roll",FALSE);             //滚转角
		fields.AddFloatField("pitch",FALSE);            //俯仰角
		fields.AddIntegerField("targetwaypoint",FALSE); //目标航点序号
		fields.AddIntegerField("rpm",FALSE);            //发动机转速
		fields.AddIntegerField("airspeed",FALSE);       //空速
		fields.AddIntegerField("targetairspeed",FALSE); //目标空速

		fields.AddIntegerField("airaltitude",FALSE);    //气压高度
		fields.AddIntegerField("targetaltitude",FALSE); //目标高度
		fields.AddIntegerField("targetdirection",FALSE);//目标航向
		fields.AddIntegerField("currentcondition",FALSE);//当前飞行状况

		fields.AddIntegerField("yawdistance",FALSE);      //偏航距
		fields.AddIntegerField("standardtime",FALSE);     //制式飞行剩余时间
		fields.AddIntegerField("currentcondition2",FALSE);//飞行状况
		fields.AddIntegerField("rpm2",FALSE);             //第二发动机转速

		fields.AddIntegerField("airpress",FALSE);    //气压值
		fields.AddIntegerField("voltageservo",FALSE);//舵机电压
		fields.AddIntegerField("voltageuav",FALSE);  //飞控电压
		fields.AddIntegerField("temperature",FALSE); //温度
		fields.AddIntegerField("rssi",FALSE);        //接收机信号强度
		fields.AddIntegerField("gpstime",FALSE);     //GPS时间

		fields.AddIntegerField("ch1",FALSE);         //CH1舵机数据
		fields.AddIntegerField("ch2",FALSE);         //CH2舵机数据
		fields.AddIntegerField("ch3",FALSE);         //CH3舵机数据
		fields.AddIntegerField("ch4",FALSE);         //CH4舵机数据
		fields.AddIntegerField("ch5",FALSE);         //CH5舵机数据

		fields.AddFloatField("currenttime",FALSE);

		VARIANT vField;
		vField.vt = VT_DISPATCH;
		vField.pdispVal = fields.m_lpDispatch;
		layerinfo.AddParameter("Fields", vField);
		
		CString strTemp = _T("1");
		sVt.bstrVal= strTemp.AllocSysString();
		layerinfo.AddParameter("OverwriteFile", sVt); 
	

		CMapXLayers layers = ctrlMapX.GetLayers();
		layers.Add(layerinfo.m_lpDispatch, 5); //增加“FlyGPSPoint”到现有图层集合
		
		CMapXLayer lay = ctrlMapX.GetLayers().Item("FlyGPSPoint");	
		
		//lay.SetVisible(FALSE);   //不可见
		lay.SetSelectable(TRUE);   //设置该层目标为可选择
		lay.SetOverrideStyle(TRUE);//该层中所有Feature使用相同的style
		lay.SetEditable(TRUE);	
		//lay.SetAutoLabel(TRUE);  //设置该层目标为自动标注，去掉标签1,2,3,4
		
		lay.GetStyle().SetLineColor(0x0000ff);
		lay.GetStyle().SetLineStyle(63);//设置标注线形
		lay.GetStyle().SetLineWidth(1);	//设置线形feature的线宽
		lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);

		lay.GetStyle().GetSymbolFont().SetName("Wingdings 2");
		lay.GetStyle().SetSymbolCharacter(150);//设置“圆圈”图标
		
		ctrlMapX.GetLayers().SetAnimationLayer(lay.m_lpDispatch);
		//ctrlMapX.GetLayers().SetInsertionLayer(lay.m_lpDispatch);
	}
	catch (COleDispatchException *e) 
	{
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e)
	{
		e->ReportError();
		e->Delete();
	}
}

CFlyGPSPointRecord::~CFlyGPSPointRecord()
{

}
//在地图上显示遥测数据的点
void CFlyGPSPointRecord::ShowSymbol(CMapX &ctrlMapX, CMsg_Telemetry *pMsgTelemetry)
{
	CMapXFeature feature;
	feature.CreateDispatch(feature.GetClsid());
	feature.Attach(ctrlMapX.GetDispatch());
	feature.SetType(miFeatureTypeSymbol);
				
	feature.SetStyle(ctrlMapX.GetDefaultStyle());
						
	feature.GetPoint().Set(pMsgTelemetry->m_GPSdata.m_dLongitude, pMsgTelemetry->m_GPSdata.m_dLatitude);
				
	CMapXFeature objFeature; 
	objFeature = ctrlMapX.GetLayers().Item("FlyGPSPoint").AddFeature(feature);
}
//存储遥测数据包到tab文件中
void CFlyGPSPointRecord::SaveMsgTelemetry(CMapX &ctrlMapX, CMsg_Telemetry *pMsgTelemetry)
{
	CMsg_Telemetry Telemetry;
	Telemetry = *pMsgTelemetry;
	
	try {  
		CMapXLayer lay = ctrlMapX.GetLayers().Item("FlyGPSPoint");
		
		CMapXFeature feature;
		feature.CreateDispatch(feature.GetClsid());
		feature.Attach(ctrlMapX.GetDispatch());
		feature.SetType(miFeatureTypeSymbol);
		feature.SetStyle(ctrlMapX.GetDefaultStyle());
		
		feature.GetPoint().Set(Telemetry.m_GPSdata.m_dLongitude, Telemetry.m_GPSdata.m_dLatitude);
		
		CMapXFeature objFeature; 
		objFeature = lay.AddFeature(feature);		
		
		VARIANT lyrVt;
		lyrVt.vt = VT_DISPATCH;
		lyrVt.pdispVal = lay;
		lyrVt.pdispVal->AddRef();
			
		CString str_key;

		lay.SetKeyField("controlmode");
		str_key.Format("%d", Telemetry.m_iControlMode);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("gpsxd");
		str_key.Format("%d", Telemetry.m_GPSdata.m_iXD);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("pdop");
		str_key.Format("%f", Telemetry.m_GPSdata.m_fPDOP);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("satellitenum");
		str_key.Format("%d", Telemetry.m_GPSdata.m_iSatelliteNum);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		//////////////////////////////////////////////////////////////////////////
		lay.SetKeyField("longitude");
		str_key.Format("%.8f", Telemetry.m_GPSdata.m_dLongitude);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("latitude");
		str_key.Format("%.8f", Telemetry.m_GPSdata.m_dLatitude);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("gpsaltitude");
		str_key.Format("%d", Telemetry.m_GPSdata.m_fGPSaltitude);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("gpsspeed");
		str_key.Format("%.2f", Telemetry.m_GPSdata.m_fGPSspeed);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("direction");
		str_key.Format("%d", Telemetry.m_GPSdata.m_fDirection);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		//////////////////////////////////////////////////////////////////////////
		lay.SetKeyField("roll");
		str_key.Format("%f", Telemetry.m_fRoll);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("pitch");
		str_key.Format("%f", Telemetry.m_fPitch);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		
		lay.SetKeyField("targetwaypoint");
		str_key.Format("%d", Telemetry.m_iTargetWayPoint);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("rpm");
		str_key.Format("%d", Telemetry.m_iRPM);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("airspeed");
		str_key.Format("%d", Telemetry.m_iAirSpeed);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("targetairspeed");
		str_key.Format("%d", Telemetry.m_iTargetAirSpeed);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		//////////////////////////////////////////////////////////////////////////
		lay.SetKeyField("airaltitude");
		str_key.Format("%d", Telemetry.m_iAirAltitude);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("targetaltitude");
		str_key.Format("%d", Telemetry.m_iTargetAltitude);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("targetdirection");
		str_key.Format("%d", Telemetry.m_iTargetDirection);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("currentcondition");
		str_key.Format("%d", Telemetry.m_iCurrentCondition);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		//////////////////////////////////////////////////////////////////////////
		lay.SetKeyField("yawdistance");
		str_key.Format("%d", Telemetry.m_iYawDistance);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("standardtime");
		str_key.Format("%d", Telemetry.m_iStandardTime);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("currentcondition2");
		str_key.Format("%d", Telemetry.m_iCurrentCondition2);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("rpm2");
		str_key.Format("%d", Telemetry.m_iRPM2);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		//////////////////////////////////////////////////////////////////////////
		lay.SetKeyField("airpress");
		str_key.Format("%d", Telemetry.m_fAirPress);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("voltageservo");
		str_key.Format("%.2f", Telemetry.m_fVoltageServo);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("voltageuav");
		str_key.Format("%.2f", Telemetry.m_fVoltageUAV);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("temperature");
		str_key.Format("%.1f", Telemetry.m_fTemperature);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("rssi");
		str_key.Format("%d", Telemetry.m_iRSSI);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("gpstime");
		str_key.Format("%d", Telemetry.m_dGPSTime);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		//////////////////////////////////////////////////////////////////////////
		lay.SetKeyField("ch1");
		str_key.Format("%d", Telemetry.m_iServo1);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("ch2");
		str_key.Format("%d", Telemetry.m_iServo2);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("ch3");
		str_key.Format("%d", Telemetry.m_iServo3);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("ch4");
		str_key.Format("%d", Telemetry.m_iServo4);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();

		lay.SetKeyField("ch5");
		str_key.Format("%d", Telemetry.m_iServo5);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
		//////////////////////////////////////////////////////////////////////////
		CTime time = CTime::GetCurrentTime();
		
		str_key.Format("%d%d%d%d%d%d", time.GetYear(), time.GetMonth(), 
			time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());

		lay.SetKeyField("currenttime");
		//str_key.Format("%s", strTemp);
		objFeature.SetKeyValue(str_key);
		objFeature.Update();
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
//从tab取出第iNum个(lay.AllFeatures().Item(iNum);)赋值给MsgTelemetry
void CFlyGPSPointRecord::GetMsgTelemetryFromTab(CMapX &ctrlMapX, CMsg_Telemetry &MsgTelemetry, int iNum)
{
	try { 
		CMapXLayer lay = ctrlMapX.GetLayers().Item("FlyGPSPoint");

		CMapXFeature objFeature;
		objFeature = lay.AllFeatures().Item(iNum);
		
		lay.SetKeyField("controlmode");
		MsgTelemetry.m_iControlMode = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("gpsxd");
		MsgTelemetry.m_GPSdata.m_iXD = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("pdop");
		MsgTelemetry.m_GPSdata.m_fPDOP = (float)atof(objFeature.GetKeyValue());

		lay.SetKeyField("satellitenum");
		MsgTelemetry.m_GPSdata.m_iSatelliteNum = atoi(objFeature.GetKeyValue());
		//////////////////////////////////////////////////////////////////////////
		lay.SetKeyField("longitude");
		MsgTelemetry.m_GPSdata.m_dLongitude = atof(objFeature.GetKeyValue());

		lay.SetKeyField("latitude");
		MsgTelemetry.m_GPSdata.m_dLatitude = atof(objFeature.GetKeyValue());

		lay.SetKeyField("gpsaltitude");
		MsgTelemetry.m_GPSdata.m_fGPSaltitude = (float)atof(objFeature.GetKeyValue());

		lay.SetKeyField("gpsspeed");
		MsgTelemetry.m_GPSdata.m_fGPSspeed = (float)atof(objFeature.GetKeyValue());

		lay.SetKeyField("direction");
		MsgTelemetry.m_GPSdata.m_fDirection = (float)atof(objFeature.GetKeyValue());
		//////////////////////////////////////////////////////////////////////////
		lay.SetKeyField("roll");
		MsgTelemetry.m_fRoll = (float)atof(objFeature.GetKeyValue());

		lay.SetKeyField("pitch");
		MsgTelemetry.m_fPitch = (float)atof(objFeature.GetKeyValue());
		
		lay.SetKeyField("targetwaypoint");
		MsgTelemetry.m_iTargetWayPoint = atoi(objFeature.GetKeyValue());
		
		lay.SetKeyField("rpm");
		MsgTelemetry.m_iRPM = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("airspeed");
		MsgTelemetry.m_iAirSpeed = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("targetairspeed");
		MsgTelemetry.m_iTargetAirSpeed = atoi(objFeature.GetKeyValue());
		//////////////////////////////////////////////////////////////////////////
		lay.SetKeyField("airaltitude");
		MsgTelemetry.m_iAirAltitude = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("targetaltitude");
		MsgTelemetry.m_iTargetAltitude = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("targetdirection");
		MsgTelemetry.m_iTargetDirection = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("currentcondition");
		MsgTelemetry.m_iCurrentCondition = atoi(objFeature.GetKeyValue());
		//////////////////////////////////////////////////////////////////////////
		lay.SetKeyField("yawdistance");
		MsgTelemetry.m_iYawDistance = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("standardtime");
		MsgTelemetry.m_iStandardTime = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("currentcondition2");
		MsgTelemetry.m_iCurrentCondition2 = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("rpm2");
		MsgTelemetry.m_iRPM2 = atoi(objFeature.GetKeyValue());
		//////////////////////////////////////////////////////////////////////////
		lay.SetKeyField("airpress");
		MsgTelemetry.m_fAirPress = (float)atof(objFeature.GetKeyValue());

		lay.SetKeyField("voltageservo");
		MsgTelemetry.m_fVoltageServo = (float)atof(objFeature.GetKeyValue());

		lay.SetKeyField("voltageuav");
		MsgTelemetry.m_fVoltageUAV = (float)atof(objFeature.GetKeyValue());

		lay.SetKeyField("temperature");
		MsgTelemetry.m_fTemperature = (float)atof(objFeature.GetKeyValue());

		lay.SetKeyField("rssi");
		MsgTelemetry.m_iRSSI = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("gpstime");
		MsgTelemetry.m_dGPSTime = atoi(objFeature.GetKeyValue());
		//////////////////////////////////////////////////////////////////////////
		lay.SetKeyField("ch1");
		MsgTelemetry.m_iServo1 = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("ch2");
		MsgTelemetry.m_iServo2 = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("ch3");
		MsgTelemetry.m_iServo3 = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("ch4");
		MsgTelemetry.m_iServo4 = atoi(objFeature.GetKeyValue());

		lay.SetKeyField("ch5");
		MsgTelemetry.m_iServo5 = atoi(objFeature.GetKeyValue());	
		//////////////////////////////////////////////////////////////////////////
		lay.SetKeyField("currenttime");
		MsgTelemetry.m_strCurrentTime = objFeature.GetKeyValue();
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
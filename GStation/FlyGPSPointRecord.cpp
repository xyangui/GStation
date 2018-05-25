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
//ֻ����һ��CFlyGPSPointRecord���󣬼����캯��ֻ��ִ��һ�Σ���Ϊִ������ʱ��ԭ�����ڡ�FlyGPSPoint�����г�ͻ��
CFlyGPSPointRecord::CFlyGPSPointRecord(CMapX &ctrlMapX)
{
	//�˺������ܣ���record�ļ����´���%d��%d��%d��%d��%d��%d��.tab�ļ��������洢�ɿش������ġ�ң�����ݡ�
	char pFileName[256];   
	int nPos = GetCurrentDirectory(256, pFileName);//�õ���ǰ·������������û��"\"   
	if( nPos < 0 ){
		AfxMessageBox("�޷��õ���ǰ·����");
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
		layerinfo.SetType(miLayerInfoTypeNewTable);     //�½�ͼ������
		
		VARIANT sVt;
		sVt.vt = VT_BSTR;
		sVt.bstrVal = strPathFileName.AllocSysString();//Ӧ����ͼ����tab�ļ���
		layerinfo.AddParameter("FileSpec", sVt); 
		layerinfo.AddParameter("Name",COleVariant("FlyGPSPoint"));//�ɻ���ʵ�ʷ��е�GPS����㣬���켣��
		
		CMapXFields fields;
		if( !fields.CreateDispatch( fields.GetClsid() ) )
			return ; 
		
		fields.AddIntegerField("controlmode",FALSE);    //����ģʽ
		fields.AddIntegerField("gpsxd",FALSE);          //GPS��λ���
		fields.AddIntegerField("pdop",FALSE);           //PDOP��λ����
		fields.AddIntegerField("satellitenum",FALSE);   //��Ч������
		
		//fields.AddFloatField("longitude",FALSE);        //����
		//fields.AddFloatField("latitude",FALSE);         //γ��
		fields.AddStringField("longitude",13,FALSE);    //����
		fields.AddStringField("latitude",13,FALSE);     //γ��

		fields.AddFloatField("gpsaltitude",FALSE);      //�߶�
		fields.AddFloatField("gpsspeed",FALSE);         //ˮƽ�ٶ�
		fields.AddFloatField("direction",FALSE);        //����

		fields.AddFloatField("roll",FALSE);             //��ת��
		fields.AddFloatField("pitch",FALSE);            //������
		fields.AddIntegerField("targetwaypoint",FALSE); //Ŀ�꺽�����
		fields.AddIntegerField("rpm",FALSE);            //������ת��
		fields.AddIntegerField("airspeed",FALSE);       //����
		fields.AddIntegerField("targetairspeed",FALSE); //Ŀ�����

		fields.AddIntegerField("airaltitude",FALSE);    //��ѹ�߶�
		fields.AddIntegerField("targetaltitude",FALSE); //Ŀ��߶�
		fields.AddIntegerField("targetdirection",FALSE);//Ŀ�꺽��
		fields.AddIntegerField("currentcondition",FALSE);//��ǰ����״��

		fields.AddIntegerField("yawdistance",FALSE);      //ƫ����
		fields.AddIntegerField("standardtime",FALSE);     //��ʽ����ʣ��ʱ��
		fields.AddIntegerField("currentcondition2",FALSE);//����״��
		fields.AddIntegerField("rpm2",FALSE);             //�ڶ�������ת��

		fields.AddIntegerField("airpress",FALSE);    //��ѹֵ
		fields.AddIntegerField("voltageservo",FALSE);//�����ѹ
		fields.AddIntegerField("voltageuav",FALSE);  //�ɿص�ѹ
		fields.AddIntegerField("temperature",FALSE); //�¶�
		fields.AddIntegerField("rssi",FALSE);        //���ջ��ź�ǿ��
		fields.AddIntegerField("gpstime",FALSE);     //GPSʱ��

		fields.AddIntegerField("ch1",FALSE);         //CH1�������
		fields.AddIntegerField("ch2",FALSE);         //CH2�������
		fields.AddIntegerField("ch3",FALSE);         //CH3�������
		fields.AddIntegerField("ch4",FALSE);         //CH4�������
		fields.AddIntegerField("ch5",FALSE);         //CH5�������

		fields.AddFloatField("currenttime",FALSE);

		VARIANT vField;
		vField.vt = VT_DISPATCH;
		vField.pdispVal = fields.m_lpDispatch;
		layerinfo.AddParameter("Fields", vField);
		
		CString strTemp = _T("1");
		sVt.bstrVal= strTemp.AllocSysString();
		layerinfo.AddParameter("OverwriteFile", sVt); 
	

		CMapXLayers layers = ctrlMapX.GetLayers();
		layers.Add(layerinfo.m_lpDispatch, 5); //���ӡ�FlyGPSPoint��������ͼ�㼯��
		
		CMapXLayer lay = ctrlMapX.GetLayers().Item("FlyGPSPoint");	
		
		//lay.SetVisible(FALSE);   //���ɼ�
		lay.SetSelectable(TRUE);   //���øò�Ŀ��Ϊ��ѡ��
		lay.SetOverrideStyle(TRUE);//�ò�������Featureʹ����ͬ��style
		lay.SetEditable(TRUE);	
		//lay.SetAutoLabel(TRUE);  //���øò�Ŀ��Ϊ�Զ���ע��ȥ����ǩ1,2,3,4
		
		lay.GetStyle().SetLineColor(0x0000ff);
		lay.GetStyle().SetLineStyle(63);//���ñ�ע����
		lay.GetStyle().SetLineWidth(1);	//��������feature���߿�
		lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);

		lay.GetStyle().GetSymbolFont().SetName("Wingdings 2");
		lay.GetStyle().SetSymbolCharacter(150);//���á�ԲȦ��ͼ��
		
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
//�ڵ�ͼ����ʾң�����ݵĵ�
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
//�洢ң�����ݰ���tab�ļ���
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
//��tabȡ����iNum��(lay.AllFeatures().Item(iNum);)��ֵ��MsgTelemetry
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
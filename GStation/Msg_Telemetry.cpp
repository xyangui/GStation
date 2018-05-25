// Msg_Telemetry.cpp: implementation of the CMsg_Telemetry class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "Msg_Telemetry.h"

#include "Payload.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMsg_Telemetry::CMsg_Telemetry()
{

}
const int CMsg_Telemetry::MSG_ID = 0x14;//命令类型
const int CMsg_Telemetry::MSG_SIZE_PAYLOAD_LENGTH = 70;//从命令类型算起（含命令类型）到校验和（含校验和），共72个字节
	            //不包括命令类型（1字节）、size（2字节）、校验和（1字节），参数68个字节+2个字节未知（5个CH舵机数据？） 	
CMsg_Telemetry::~CMsg_Telemetry()
{

}
void CMsg_Telemetry::Unpack(CPayload payload)
{
	payload.resetIndex();
	//m_nDataLength = payload.getI2();//payload不包括：size，
	m_iControlMode = payload.getU1();
	m_GPSdata.m_iXD = payload.getU1();
	m_GPSdata.m_fPDOP = (float)payload.getU2h() / 100; 

	m_GPSdata.m_iSatelliteNum = payload.getU1();
	m_GPSdata.m_dLongitude = (double)payload.getI4h() / 10000000;
	m_GPSdata.m_dLatitude = (double)payload.getI4h() / 10000000;
	m_GPSdata.m_fGPSaltitude = (float)((float)payload.getI4h() / 1000);


	//米/秒*60*60/1000=米/秒*3.6=公里/小时
	m_GPSdata.m_fGPSspeed = (float)((float)payload.getU4h()/100);//*3.6);(米/秒)



	
	m_GPSdata.m_fDirection = (float)((float)payload.getI4h() / 100000);
	
	m_fRoll = (float)payload.getI2() / 10;
	m_fPitch = (float)payload.getI2() / 10;
	m_iTargetWayPoint = payload.getU1();

	m_iRPM = payload.getU1() * 60;//是否*60？
	m_iAirSpeed = (int)(payload.getI2()/10*3.6);//是否取整？TF1D中没有取整
	m_iTargetAirSpeed = (int)(payload.getU1()*3.6);//是否取整？TF1D中没有取整
	m_iAirAltitude = payload.getI2();
	m_iTargetAltitude = payload.getI2();
	m_iTargetDirection = payload.getI2() / 10;//是否整除？TF1D中就是整除
	//m_nDesired_Heading：目标航向*10（度），就是UP30地面站中的“指向”
	m_iCurrentCondition = payload.getU1();

	m_iYawDistance = payload.getI2();

	m_iStandardTime = payload.getU2h();
	m_iCurrentCondition2 = payload.getU1();
	m_iRPM2 = payload.getU1();

	m_fAirPress = (float)payload.getU2() / 10;
	m_fVoltageServo = (float)((float)payload.getU2h() /1024*5*21.2/15);
	m_fVoltageUAV = (float)((float)payload.getU2h() / 1024*5*23.2/8.2);

	m_fTemperature =	(float)payload.getI2() / 10;
	m_iRSSI = payload.getU1();

	m_dGPSTime = (double)payload.getU4h();

	m_iServo1 = payload.getU2();
	m_iServo2 = payload.getU2();
	m_iServo3 = payload.getU2();
	m_iServo4 = payload.getU2();
	m_iServo5 = payload.getU2();
}

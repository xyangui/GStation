// Msg_Telemetry.h: interface for the CMsg_Telemetry class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSG_TELEMETRY_H__7DE8E743_041C_4A9B_8D26_321FF900A91B__INCLUDED_)
#define AFX_MSG_TELEMETRY_H__7DE8E743_041C_4A9B_8D26_321FF900A91B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Message.h"
class CPayload;

class CMsg_Telemetry : public CMessage
{
public:
	CMsg_Telemetry();
	virtual ~CMsg_Telemetry();

	static const int MSG_ID;
	static const int MSG_SIZE_PAYLOAD_LENGTH;

	void Unpack(CPayload payload);

	int m_nDataLength;  //遥测数据长度
    //以下变量值为：飞控传过来的值处理后的值，直接存储到tab中
	struct GPSDATA{
		int m_iXD;              //定位情况（1个字节）：0=无效；2=2D；3=3D
		float m_fPDOP;          //定位质量（2个字节）：界面中的PDOP
		int m_iSatelliteNum;    //有效卫星数量（1个字节）
		double m_dLongitude;    //经度（4个字节）
		double m_dLatitude;     //纬度（4个字节）
		float  m_fGPSaltitude;  //GPS高度（4个字节）
		float  m_fGPSspeed;     //GPS速度（4个字节）
		float  m_fDirection;    //航向（4个字节）
	};//卫星信息结构体

	int m_iControlMode;         //控制模式（1个字节）
	GPSDATA m_GPSdata;
	float m_fRoll;              //滚转角（2个字节）
	float m_fPitch;             //俯仰角（2个字节）
	int m_iTargetWayPoint;      //目标航点（1个字节）
	int m_iRPM;                 //发动机转速（1个字节）
	int m_iAirSpeed;            //空速（2个字节）
	int m_iTargetAirSpeed;      //设定空速（1个字节）
	int m_iAirAltitude;         //气压高度（2个字节）
	int m_iTargetAltitude;      //目标高度（2个字节）
	int m_iTargetDirection;     //目标航向（2个字节）
	int m_iCurrentCondition;    //当前飞行状态（1个字节）
	int m_iYawDistance;         //偏航距（2个字节）
	int m_iStandardTime;        //制式航线飞行剩余时间（2个字节）
	int m_iCurrentCondition2;   //飞行状况（1个字节）
	int m_iRPM2;                //第二发动机转速（1个字节）

	float m_fAirPress;          //气压值（2个字节）
	float m_fVoltageServo;      //舵机电压（2个字节）
	float m_fVoltageUAV;        //飞控电压（2个字节）
	float m_fTemperature;       //温度（2个字节）
	int m_iRSSI;                //接收机信号强度（保留）（1个字节）
	double m_dGPSTime;          //GPS时间（4个字节）

	int m_iServo1;              //CH1舵机数据（2个字节）
	int m_iServo2;              //CH2舵机数据（2个字节）
	int m_iServo3;              //CH3舵机数据（2个字节）
	int m_iServo4;              //CH4舵机数据（2个字节）
	int m_iServo5;              //CH5舵机数据（2个字节）
	
	CString m_strCurrentTime;
	int check;                  //校验和（1个字节）
};

#endif // !defined(AFX_MSG_TELEMETRY_H__7DE8E743_041C_4A9B_8D26_321FF900A91B__INCLUDED_)

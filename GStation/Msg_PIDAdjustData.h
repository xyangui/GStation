// Msg_PIDAdjustData.h: interface for the CMsg_PIDAdjustData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSG_PIDADJUSTDATA_H__230F2A6C_7E9B_4AA8_8ED1_7659110BA94E__INCLUDED_)
#define AFX_MSG_PIDADJUSTDATA_H__230F2A6C_7E9B_4AA8_8ED1_7659110BA94E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Payload.h"
#include "Message.h"
#include "Packet.h"

class CMsg_PIDAdjustData:public CMessage
{
public:
	CMsg_PIDAdjustData();
	virtual ~CMsg_PIDAdjustData();

	static const int MSG_ID;
	static const int MSG_SIZE_PAYLOAD_LENGTH;
	
	void Unpack(CPayload payload);
	CPacket GetRequestPacket();
	CPacket GetSetEnableCHPacket(short data);
	
	struct GPSDATA{
		int m_nStatus;          //定位情况（1个字节）
		float m_fPod;             //定位质量（2个字节）
		int m_nSatnum;          //有效卫星数量（1个字节）
		double m_dLat;          //经度（4个字节）
		double m_dLon;          //纬度（4个字节）
		float  m_fGPSalt;       //GPS高度（4个字节）
		float  m_fGPSspd;       //GPS速度（4个字节）
		float  m_fHangxiang;    //航向（4个字节）
	};//卫星信息结构体
	
	int m_nContralmodel;        //控制模式（1个字节）
	int m_nLoopsEnable;       //PID有效控制字节（无符号1个字节）
	float m_fRoll;             //滚转角（2个字节）
	float m_fPitch;            //俯仰角（2个字节）
	float m_fAimPitch;         //目标俯仰角（2个字节）
	int m_nAirspd;              //空速（2个字节）
	int m_nDesired_Airspd;      //目标空速（1个字节）
	int m_nAiralt;              //高度（2个字节）
	int m_nDesired_Airalt;      //目标高度（2个字节）
	int m_nDirection;           //磁罗盘航向（2个字节）(据实际测试应该为转弯速率)
	int m_nAimSwerveRate;       //目标转弯速率（I2）
	int m_nRPM;                 //发动机转速（1个字节）
	GPSDATA m_GPSdata;			//GPS数据（24）
	int m_nTargetWP;            //目标航点（1个字节）
	
	int check;                  //校验和（1个字节）

};

#endif // !defined(AFX_MSG_PIDADJUSTDATA_H__230F2A6C_7E9B_4AA8_8ED1_7659110BA94E__INCLUDED_)

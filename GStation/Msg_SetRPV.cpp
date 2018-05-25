// Msg_SetRPV.cpp: implementation of the CMsg_SetRPV class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "Msg_SetRPV.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMsg_SetRPV::CMsg_SetRPV()
{

}

CMsg_SetRPV::~CMsg_SetRPV()
{

}
//返回“设置目标迎角RPV值”数据包
CPacket CMsg_SetRPV::GetSetAimDegPacket(float fAimDeg)
{
	CPacket packet;
	packet.m_msgid = 0x08;
	packet.m_len = 2;
	
	packet.payload.putI2((int)(fAimDeg*10.0));
	
	packet.generateCRC();
	return packet;
}
//返回“设置目标空速RPV值”数据包
CPacket CMsg_SetRPV::GetSetAimAirSpeedPacket(int nAimAirSpeed)
{
	CPacket packet;
	packet.m_msgid = 0x09;
	packet.m_len = 2;
	
	packet.payload.putU2(nAimAirSpeed);
	
	packet.generateCRC();
	return packet;
}
//返回“获取设置目标高度RPV值”数据包
CPacket CMsg_SetRPV::GetSetAimAltitudePacket(int nAimAltitude)
{
	CPacket packet;
	packet.m_msgid = 0x0a;
	packet.m_len = 2;
	
	packet.payload.putU2(nAimAltitude);
	
	packet.generateCRC();
	return packet;
}
//返回“设置目标转弯速率RPV值”数据
CPacket CMsg_SetRPV::GetSetAimSweiveRatePacket(int nAimSweiveRate)
{
	CPacket packet;
	packet.m_msgid = 0x0b;
	packet.m_len = 2;
	
	packet.payload.putI2(nAimSweiveRate);
	
	packet.generateCRC();
	return packet;
}

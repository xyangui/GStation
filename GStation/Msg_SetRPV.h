// Msg_SetRPV.h: interface for the CMsg_SetRPV class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSG_SETRPV_H__145FD250_D7C9_4387_BA26_5400F25F93A7__INCLUDED_)
#define AFX_MSG_SETRPV_H__145FD250_D7C9_4387_BA26_5400F25F93A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Packet.h"

class CMsg_SetRPV  
{
public:
	CMsg_SetRPV();
	virtual ~CMsg_SetRPV();

	CPacket GetSetAimDegPacket(float fAimDeg);            //返回“设置目标迎角RPV值”数据包
	CPacket GetSetAimAirSpeedPacket(int nAimAirSpeed);    //返回“设置目标空速RPV值”数据包
	CPacket GetSetAimAltitudePacket(int nAimAltitude);    //返回“获取设置目标高度RPV值”数据包
	CPacket GetSetAimSweiveRatePacket(int nAimSweiveRate);//返回“设置目标转弯速率RPV值”数据
};

#endif // !defined(AFX_MSG_SETRPV_H__145FD250_D7C9_4387_BA26_5400F25F93A7__INCLUDED_)

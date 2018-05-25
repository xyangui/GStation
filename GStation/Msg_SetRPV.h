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

	CPacket GetSetAimDegPacket(float fAimDeg);            //���ء�����Ŀ��ӭ��RPVֵ�����ݰ�
	CPacket GetSetAimAirSpeedPacket(int nAimAirSpeed);    //���ء�����Ŀ�����RPVֵ�����ݰ�
	CPacket GetSetAimAltitudePacket(int nAimAltitude);    //���ء���ȡ����Ŀ��߶�RPVֵ�����ݰ�
	CPacket GetSetAimSweiveRatePacket(int nAimSweiveRate);//���ء�����Ŀ��ת������RPVֵ������
};

#endif // !defined(AFX_MSG_SETRPV_H__145FD250_D7C9_4387_BA26_5400F25F93A7__INCLUDED_)

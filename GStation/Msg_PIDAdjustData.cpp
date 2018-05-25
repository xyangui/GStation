// Msg_PIDAdjustData.cpp: implementation of the CMsg_PIDAdjustData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "Msg_PIDAdjustData.h"
#include "Packet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const int CMsg_PIDAdjustData::MSG_ID = 0x02;//��������
const int CMsg_PIDAdjustData::MSG_SIZE_PAYLOAD_LENGTH = 45;//����������С����ʱ������GPS���ݣ�

CMsg_PIDAdjustData::CMsg_PIDAdjustData()
{

}
CMsg_PIDAdjustData::~CMsg_PIDAdjustData()
{
	
}

void CMsg_PIDAdjustData::Unpack(CPayload payload)
{
	// ��λ�غ�����,�غ�payload�н�����������
	payload.resetIndex();
	// ��ʼ���
	m_nContralmodel = payload.getU1();
	m_nLoopsEnable = payload.getU1();
	m_fRoll = (float)payload.getI2() / 10;   if(m_fRoll >= 0x8000)	m_fRoll -= 65536;
	m_fPitch = (float)payload.getI2() / 10;   if(m_fPitch >= 0x8000)	m_fPitch -= 65536;
	m_fAimPitch = (float)payload.getI2() / 10;   if(m_fAimPitch >= 0x8000)	m_fAimPitch -= 65536;
	m_nAirspd = (int)(payload.getI2() / 10*3.6);
	m_nDesired_Airspd = (int)(payload.getU1()*3.6);

	m_nAiralt = payload.getI2();	if (m_nAiralt >= 0x8000)	m_nAiralt = m_nAiralt - 65536;
	m_nDesired_Airalt = payload.getI2();   if(m_nDesired_Airalt >= 0x8000)	m_nDesired_Airalt -= 65536;
	m_nDirection = payload.getI2();	if(m_nDirection >= 0x8000)	m_nDirection -= 65536;
	m_nAimSwerveRate = payload.getI2();	if(m_nAimSwerveRate >= 0x8000)	m_nAimSwerveRate -= 65536;
	m_nRPM = payload.getU1();
	//���GPS���ݣ����ĵ��������������ݿ���û�У�4Hz,����GPS���º���д����ݣ�������Ҫ�ж�GPS�Ƿ�����
	if (payload.m_iSize != MSG_SIZE_PAYLOAD_LENGTH) 
	{
		m_GPSdata.m_nStatus = 0;
		m_GPSdata.m_fPod = 0;
		m_GPSdata.m_nSatnum = 0;
		m_GPSdata.m_dLon = 0;
		m_GPSdata.m_dLat = 0;
		m_GPSdata.m_fGPSalt = 0;
		m_GPSdata.m_fGPSspd = 0;
		m_GPSdata.m_fHangxiang = 0;
		m_nTargetWP = 0;
		return;
	}
	m_GPSdata.m_nStatus = payload.getU1();
	m_GPSdata.m_fPod = (float)payload.getU2h() / 100;
	m_GPSdata.m_nSatnum = payload.getU1();
	m_GPSdata.m_dLon = (double)payload.getI4h() / 10000000;
	m_GPSdata.m_dLat = (double)payload.getI4h() / 10000000;
	m_GPSdata.m_fGPSalt = (float)((float)payload.getI4h() / 1000);
	m_GPSdata.m_fGPSspd = (float)((float)payload.getU4h() / 100*3.6);
	m_GPSdata.m_fHangxiang = (float)((float)payload.getI4h() / 100000);
	m_nTargetWP = payload.getU1();
}
//���ء�������PID�����������ݡ����ݰ�
CPacket CMsg_PIDAdjustData::GetRequestPacket()
{
	CPacket packet;
	packet.m_msgid = MSG_ID;
	packet.m_len = 0;
	
	packet.generateCRC();
	return packet;
}
//���ء�����PID��·��Ч�����ݰ�
CPacket CMsg_PIDAdjustData::GetSetEnableCHPacket(short data)
{
	CPacket packet;
	packet.m_msgid = 0x06;
	packet.m_len = 1;

	packet.payload.putU1(data);
	packet.generateCRC();
	return packet;
}
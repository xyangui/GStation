// Msg_OtherPIDAdjData.cpp: implementation of the CMsg_OtherPIDAdjData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "Msg_OtherPIDAdjData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMsg_OtherPIDAdjData::CMsg_OtherPIDAdjData()
{

}

CMsg_OtherPIDAdjData::~CMsg_OtherPIDAdjData()
{

}

/////////////////////////ӭ�����ݿ�ʼ/////////////////////////////
//���ء���ȡӭ�����ݡ������ݰ�
CPacket CMsg_OtherPIDAdjData::GetRequestYJDataPacket()
{
	CPacket packet;
	packet.m_msgid = 0x0D;
	packet.m_len = 0;

	packet.generateCRC();
	return packet;
}

//���ء�����ӭ�����ݡ������ݰ�
CPacket CMsg_OtherPIDAdjData::GetSetYJDataPacket(int maxDeg,int midDeg,int minDeg)
{
	CPacket packet;
	packet.m_msgid = 0x0D;
	packet.m_len = 6;
	
	packet.payload.putI2(maxDeg);
	packet.payload.putI2(midDeg);
	packet.payload.putI2(minDeg);
	
	packet.generateCRC();
	return packet;
}

//���� ���ص�ӭ�����ݰ�
void CMsg_OtherPIDAdjData::YJDataUnPacket(CPayload payload)
{
	// ��λ�غ�����,�غ�payload�н�����������
	payload.resetIndex();
	// ��ʼ���
	m_YJ_maxDeg = payload.getI2();//����ԭ���õ��ǣ�.getU2();	
	m_YJ_midDeg = payload.getI2();//����ԭ���õ��ǣ�.getU2();	 
    m_YJ_minDeg = payload.getI2();//����ԭ���õ��ǣ�.getU2();	 
    // �������
}
////////////////////////ӭ�����ݽ���////////////////////////////////

////////////////////////����ͨ�����ݿ�ʼ///////////////////////////
//���� ���󵼺����� �����ݰ�
CPacket CMsg_OtherPIDAdjData::GetRequestDhDataPacket()
{
	CPacket packet;
	packet.m_msgid = 0x16;
	packet.m_len = 0;

	packet.generateCRC();
	return packet;
}

//���� ���صĵ������ݰ�
void CMsg_OtherPIDAdjData::UnDhDataPacket(CPayload payload)
{	
	// ��λ�غ�����,�غ�payload�н�����������
	payload.resetIndex();
	//��ʼ���
	m_DH_AimWaypoint = payload.getU1();
	m_DH_YawDistance = payload.getI2();
	m_DH_PreAirLine = (float)(payload.getI2()/10.0);
	m_DH_RealHeading = (float)(payload.getI2()/10.0);
	m_DH_TotalYawAngle = (float)(payload.getI2()/10.0);
	m_DH_ToAimDistance = payload.getU2();
	//�������

}
////////////////////////����ͨ�����ݽ���///////////////////////////

////////////////////////������ ��ʼ/////////////////
//���� �������ת�����ʻ��¶� �����ݰ�
CPacket CMsg_OtherPIDAdjData::GetSetMaxZwRateDataPacket(int maxZwRate)
{
	CPacket packet;
	packet.m_msgid = 0x33;
	packet.m_len = 1;
	packet.payload.putU1(maxZwRate);
	packet.generateCRC();
	return packet;
}

//����  ���ÿ��ٿ���ģʽ �����ݰ�
CPacket CMsg_OtherPIDAdjData::GetSetAirspdCtrlmodelDataPacket(int airspdCtrlmodel)
{
	CPacket packet;
	packet.m_msgid = 0x34;
	packet.m_len = 1;
	packet.payload.putU1(airspdCtrlmodel);
	packet.generateCRC();
	return packet;
}
////////////////////////������ ����/////////////////

// Msg_OtherPIDAdjData.h: interface for the CMsg_OtherPIDAdjData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSG_OTHERPIDADJDATA_H__AF852A32_1F72_4C08_B6F2_F5E951EFB609__INCLUDED_)
#define AFX_MSG_OTHERPIDADJDATA_H__AF852A32_1F72_4C08_B6F2_F5E951EFB609__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Packet.h"
#include "Payload.h"

class CMsg_OtherPIDAdjData  
{
public:
	CMsg_OtherPIDAdjData();
	virtual ~CMsg_OtherPIDAdjData();
	/////////////////////////ӭ�����ݿ�ʼ/////////////////////////////
	CPacket GetRequestYJDataPacket();                            //���ء���ȡӭ�����ݡ������ݰ�
	CPacket GetSetYJDataPacket(int maxDeg,int midDeg,int minDeg);//���ء�����ӭ�����ݡ������ݰ�
	void YJDataUnPacket(CPayload payload);                       //���� ���ص�ӭ�����ݰ�

	int m_YJ_maxDeg;//���ӭ��ֵ���ȣ�
	int m_YJ_midDeg;//ƽ��ӭ��ֵ���ȣ�
	int m_YJ_minDeg;//��Сӭ��ֵ���ȣ�
	////////////////////////ӭ�����ݽ���////////////////////////////////

	////////////////////////����ͨ�����ݿ�ʼ///////////////////////////
	CPacket GetRequestDhDataPacket();     //���� ���󵼺����� �����ݰ�
	void UnDhDataPacket(CPayload payload);//���� ���صĵ������ݰ�

	int m_DH_AimWaypoint;    //Ŀ�꺽��
	int m_DH_YawDistance;    //ƫ����
	float m_DH_PreAirLine;   //Ԥ�躽��
	float m_DH_RealHeading;  //ʵ�ʺ���
	float m_DH_TotalYawAngle;//�ܵ�ƫ���Ƕ�
	int m_DH_ToAimDistance;  //��Ŀ������
	////////////////////////����ͨ�����ݽ���///////////////////////////

	////////////////////////������ ��ʼ/////////////////////
	CPacket GetSetMaxZwRateDataPacket(int maxZwRate);
	CPacket GetSetAirspdCtrlmodelDataPacket(int airspdCtrlmodel);
	////////////////////////������ ����/////////////////////
};

#endif // !defined(AFX_MSG_OTHERPIDADJDATA_H__AF852A32_1F72_4C08_B6F2_F5E951EFB609__INCLUDED_)

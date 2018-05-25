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
		int m_nStatus;          //��λ�����1���ֽڣ�
		float m_fPod;             //��λ������2���ֽڣ�
		int m_nSatnum;          //��Ч����������1���ֽڣ�
		double m_dLat;          //���ȣ�4���ֽڣ�
		double m_dLon;          //γ�ȣ�4���ֽڣ�
		float  m_fGPSalt;       //GPS�߶ȣ�4���ֽڣ�
		float  m_fGPSspd;       //GPS�ٶȣ�4���ֽڣ�
		float  m_fHangxiang;    //����4���ֽڣ�
	};//������Ϣ�ṹ��
	
	int m_nContralmodel;        //����ģʽ��1���ֽڣ�
	int m_nLoopsEnable;       //PID��Ч�����ֽڣ��޷���1���ֽڣ�
	float m_fRoll;             //��ת�ǣ�2���ֽڣ�
	float m_fPitch;            //�����ǣ�2���ֽڣ�
	float m_fAimPitch;         //Ŀ�긩���ǣ�2���ֽڣ�
	int m_nAirspd;              //���٣�2���ֽڣ�
	int m_nDesired_Airspd;      //Ŀ����٣�1���ֽڣ�
	int m_nAiralt;              //�߶ȣ�2���ֽڣ�
	int m_nDesired_Airalt;      //Ŀ��߶ȣ�2���ֽڣ�
	int m_nDirection;           //�����̺���2���ֽڣ�(��ʵ�ʲ���Ӧ��Ϊת������)
	int m_nAimSwerveRate;       //Ŀ��ת�����ʣ�I2��
	int m_nRPM;                 //������ת�٣�1���ֽڣ�
	GPSDATA m_GPSdata;			//GPS���ݣ�24��
	int m_nTargetWP;            //Ŀ�꺽�㣨1���ֽڣ�
	
	int check;                  //У��ͣ�1���ֽڣ�

};

#endif // !defined(AFX_MSG_PIDADJUSTDATA_H__230F2A6C_7E9B_4AA8_8ED1_7659110BA94E__INCLUDED_)

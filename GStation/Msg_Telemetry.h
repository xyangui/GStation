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

	int m_nDataLength;  //ң�����ݳ���
    //���±���ֵΪ���ɿش�������ֵ������ֵ��ֱ�Ӵ洢��tab��
	struct GPSDATA{
		int m_iXD;              //��λ�����1���ֽڣ���0=��Ч��2=2D��3=3D
		float m_fPDOP;          //��λ������2���ֽڣ��������е�PDOP
		int m_iSatelliteNum;    //��Ч����������1���ֽڣ�
		double m_dLongitude;    //���ȣ�4���ֽڣ�
		double m_dLatitude;     //γ�ȣ�4���ֽڣ�
		float  m_fGPSaltitude;  //GPS�߶ȣ�4���ֽڣ�
		float  m_fGPSspeed;     //GPS�ٶȣ�4���ֽڣ�
		float  m_fDirection;    //����4���ֽڣ�
	};//������Ϣ�ṹ��

	int m_iControlMode;         //����ģʽ��1���ֽڣ�
	GPSDATA m_GPSdata;
	float m_fRoll;              //��ת�ǣ�2���ֽڣ�
	float m_fPitch;             //�����ǣ�2���ֽڣ�
	int m_iTargetWayPoint;      //Ŀ�꺽�㣨1���ֽڣ�
	int m_iRPM;                 //������ת�٣�1���ֽڣ�
	int m_iAirSpeed;            //���٣�2���ֽڣ�
	int m_iTargetAirSpeed;      //�趨���٣�1���ֽڣ�
	int m_iAirAltitude;         //��ѹ�߶ȣ�2���ֽڣ�
	int m_iTargetAltitude;      //Ŀ��߶ȣ�2���ֽڣ�
	int m_iTargetDirection;     //Ŀ�꺽��2���ֽڣ�
	int m_iCurrentCondition;    //��ǰ����״̬��1���ֽڣ�
	int m_iYawDistance;         //ƫ���ࣨ2���ֽڣ�
	int m_iStandardTime;        //��ʽ���߷���ʣ��ʱ�䣨2���ֽڣ�
	int m_iCurrentCondition2;   //����״����1���ֽڣ�
	int m_iRPM2;                //�ڶ�������ת�٣�1���ֽڣ�

	float m_fAirPress;          //��ѹֵ��2���ֽڣ�
	float m_fVoltageServo;      //�����ѹ��2���ֽڣ�
	float m_fVoltageUAV;        //�ɿص�ѹ��2���ֽڣ�
	float m_fTemperature;       //�¶ȣ�2���ֽڣ�
	int m_iRSSI;                //���ջ��ź�ǿ�ȣ���������1���ֽڣ�
	double m_dGPSTime;          //GPSʱ�䣨4���ֽڣ�

	int m_iServo1;              //CH1������ݣ�2���ֽڣ�
	int m_iServo2;              //CH2������ݣ�2���ֽڣ�
	int m_iServo3;              //CH3������ݣ�2���ֽڣ�
	int m_iServo4;              //CH4������ݣ�2���ֽڣ�
	int m_iServo5;              //CH5������ݣ�2���ֽڣ�
	
	CString m_strCurrentTime;
	int check;                  //У��ͣ�1���ֽڣ�
};

#endif // !defined(AFX_MSG_TELEMETRY_H__7DE8E743_041C_4A9B_8D26_321FF900A91B__INCLUDED_)

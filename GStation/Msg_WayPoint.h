// Msg_WayPoint.h: interface for the CMsg_WayPoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSG_WAYPOINT_H__72E782B5_9E2E_4CAD_907C_C2E9BA43AF41__INCLUDED_)
#define AFX_MSG_WAYPOINT_H__72E782B5_9E2E_4CAD_907C_C2E9BA43AF41__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MAPX.h"
#include "Message.h"
class CPayload;
class CPacket;

class CWayPoint 
{
public:
	int iNum;          //�������
	double dLongitude; //����*1e7(��)
	double dLatitude;  //γ��*1e7(��)
	int iAltitude;     //�߶�(m)
	int iSpeed;        //����(m/s)
	int iRadius;       //����뾶(m)
	int iTime;         //��ʽ����ʱ��*10(��),������ʾ10�룬�ɿش�����0x01��iTime=���棨�룩��tab�洢=�ɿ�
	int iStandardModel;//��ʽģʽ1��7����0
	BOOL bToLine;      //�Ƿ�����
	BOOL bToGround;    //�Ƿ���½
	BOOL bToSlope;     //�Ƿ�б�·���
	BOOL bPhoto;       //�������
	BOOL bServo1;      //���1
	BOOL bServo2;      //���2
	BOOL bServo3;      //���3
};

class CMsg_WayPoint : public CMessage  
{
public:
	CMsg_WayPoint();
	virtual ~CMsg_WayPoint();

	static const int MSG_ID;
	static const int MSG_SIZE_PAYLOAD_LENGTH;

	void UnpackSaveToTab(CPayload payload, CMapX &ctrlMapX);
	CPacket GetWayPointPack(int num);

	CPacket UpLoadOneWayPointPacket(CMapX &ctrlMapX, int iWayPointNum);
	BOOL UpLoadAllWayPointPacket(CPacket &packet, CMapX &ctrlMapX);

	void CopyWayPointFromDownToUp(CMapX &ctrlMapX);

	void DeleteAllFeature(CMapX &ctrlMapX, CString strLayName);
	void DeleteFeatureFromWPNum(CMapX &ctrlMapX, CString strLayName, int iWayPointNum);
	int GetFeatureNumFromWPNum(CMapX &ctrlMapX, CString strLayName, int iWayPointNum);

	BOOL GetWayPointFromTab(CWayPoint &WayPoint, CMapX &ctrlMapX, CString strLayer, int iWayPointNum);
	void SaveWayPointToTab(CWayPoint OneWayPoint, CMapX &ctrlMapX, CString strLayName);
/*
	struct WayPoint{
		int iNum;          //�������
		double dLongitude; //����*1e7(��)
		double dLatitude;  //γ��*1e7(��)
		int iAltitude;     //�߶�(m)
		int iSpeed;        //����(m/s)
		int iRadius;       //����뾶(m)
		int iTime;         //��ʽ����ʱ��*10(��)
		int iStandardModel;//��ʽģʽ1��7����0
		bool bToLine;      //�Ƿ�����
		bool bToGround;    //�Ƿ���½
		bool bToSlope;     //�Ƿ�б�·���
		bool bPhoto;       //�������
		bool bServo1;      //���1
		bool bServo2;      //���2
		bool bServo3;      //���3
	};*///m_WayPointUp[100];            //������Ϣ�ṹ�壬��m_WayPointUp[1]��ʼ���棬����m_WayPointUp[0]
	//int m_WayPointUpCount;         //[100]�к��������
	//WayPoint m_WayPointDown[100]; //�洢���صĺ�����Ϣ
};

#endif // !defined(AFX_MSG_WAYPOINT_H__72E782B5_9E2E_4CAD_907C_C2E9BA43AF41__INCLUDED_)

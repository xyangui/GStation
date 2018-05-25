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
	int iNum;          //航点序号
	double dLongitude; //经度*1e7(度)
	double dLatitude;  //纬度*1e7(度)
	int iAltitude;     //高度(m)
	int iSpeed;        //空速(m/s)
	int iRadius;       //到达半径(m)
	int iTime;         //制式飞行时间*10(秒),界面显示10秒，飞控传回来0x01，iTime=界面（秒），tab存储=飞控
	int iStandardModel;//制式模式1—7或者0
	BOOL bToLine;      //是否沿线
	BOOL bToGround;    //是否着陆
	BOOL bToSlope;     //是否斜坡飞行
	BOOL bPhoto;       //相机控制
	BOOL bServo1;      //舵机1
	BOOL bServo2;      //舵机2
	BOOL bServo3;      //舵机3
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
		int iNum;          //航点序号
		double dLongitude; //经度*1e7(度)
		double dLatitude;  //纬度*1e7(度)
		int iAltitude;     //高度(m)
		int iSpeed;        //空速(m/s)
		int iRadius;       //到达半径(m)
		int iTime;         //制式飞行时间*10(秒)
		int iStandardModel;//制式模式1—7或者0
		bool bToLine;      //是否沿线
		bool bToGround;    //是否着陆
		bool bToSlope;     //是否斜坡飞行
		bool bPhoto;       //相机控制
		bool bServo1;      //舵机1
		bool bServo2;      //舵机2
		bool bServo3;      //舵机3
	};*///m_WayPointUp[100];            //航点信息结构体，从m_WayPointUp[1]开始保存，不是m_WayPointUp[0]
	//int m_WayPointUpCount;         //[100]中航点的总数
	//WayPoint m_WayPointDown[100]; //存储下载的航点信息
};

#endif // !defined(AFX_MSG_WAYPOINT_H__72E782B5_9E2E_4CAD_907C_C2E9BA43AF41__INCLUDED_)

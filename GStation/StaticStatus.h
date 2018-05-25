// StaticStatus.h: interface for the CStaticStatus class.
//
//////////////////////////////////////////////////////////////////////
#if !defined(AFX_STATICSTATUS_H__2977D45B_F5DF_4DE2_8081_002579737C9D__INCLUDED_)
#define AFX_STATICSTATUS_H__2977D45B_F5DF_4DE2_8081_002579737C9D__INCLUDED_

//#include "GStationDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MAPX.h"

class CGStationDlg;
class CMsg_Telemetry;
class CMsg_WayPoint;

class CStaticStatus  
{
public:
	CStaticStatus();
	virtual ~CStaticStatus();

	void Create(CGStationDlg *pGSDlg);
	void UpdateMsgTelemetry(CMsg_Telemetry *pTelemetry);
	void UpdateWayPoint(CMsg_Telemetry *pTelemetry, CMapX &ctrlMapX);

	void UpdateXY(CString strX, CString strY);
	void UpdateTotalDistance(double dDistance);
	void UpdateCurrentDistance(double dDistance);
	void UpdateCurrentAngle(double dAngle);

    //动态创建静态文本框
	CStatic static_bg;
	CStatic yingda;
	CStatic yingdaled;
	CStatic tongxun;
	CStatic tongxunled;
	CStatic moshi;
	CStatic moshiled;
	CStatic GPS;
	CStatic GPSled;
	CStatic weixing;
	CStatic weixingled;
	CStatic PDOP;
	CStatic PDOPled;
	CStatic dianya_duoji;
	CStatic dianya_duojiled;
	CStatic dianya_zong;
	CStatic dianya_zongled;
	CStatic wendu;
	CStatic wenduled;

	CStatic pianhang;
	CStatic distance_zeropoint;
	CStatic distance_targetpoint;
	CStatic fangwei;
	CStatic zonghangdian;
	CStatic zhishishijian;

	CStatic mousepoint;
	CStatic currentpoint;
	CStatic luchengyufangwei;
	CStatic CurrentDistance;
	CStatic CurrentAngle;

private:
	CGStationDlg *m_pGStationDlg;
};

#endif // !defined(AFX_STATICSTATUS_H__2977D45B_F5DF_4DE2_8081_002579737C9D__INCLUDED_)

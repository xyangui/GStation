// FlyGPSPointRecord.h: interface for the CFlyGPSPointRecord class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLYGPSPOINTRECORD_H__AAB283B2_92B8_4107_9E3B_99C04617B1EB__INCLUDED_)
#define AFX_FLYGPSPOINTRECORD_H__AAB283B2_92B8_4107_9E3B_99C04617B1EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MAPX.h"
class CMsg_Telemetry;

class CFlyGPSPointRecord //飞控GPS轨迹记录类，负责记录收到的遥控数据 
{
public:
	CFlyGPSPointRecord();
	CFlyGPSPointRecord(CMapX &ctrlMapX);
	virtual ~CFlyGPSPointRecord();

	void ShowSymbol(CMapX &ctrlMapX, CMsg_Telemetry *pMsgTelemetry);
	void SaveMsgTelemetry(CMapX &ctrlMapX, CMsg_Telemetry *pMsgTelemetry);

	void GetMsgTelemetryFromTab(CMapX &ctrlMapX, CMsg_Telemetry &MsgTelemetry, int iNum);
};

#endif // !defined(AFX_FLYGPSPOINTRECORD_H__AAB283B2_92B8_4107_9E3B_99C04617B1EB__INCLUDED_)

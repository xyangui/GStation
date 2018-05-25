// PlaneUAV.h: interface for the CPlaneUAV class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANEUAV_H__AB6C7141_E5C2_4F7E_8B0F_534B6B004936__INCLUDED_)
#define AFX_PLANEUAV_H__AB6C7141_E5C2_4F7E_8B0F_534B6B004936__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MAPX.h"

class CPlaneUAV  //只负责移动飞机图标
{
public:
	CPlaneUAV();
	virtual ~CPlaneUAV();

	void InitShowFlane(CMapX &ctrlMapX, double dXLongitude, double dYLatitude);
	void Run();
	void UpdateFeature();
	void UpdateCurrentPosition(double dXLongitude, double dYLatitude);

public:
	void SetStartXY(double X,double Y);
	double StartX;//x 
	double StartY;//y
	
	double dSpeed;
	double dDirectory;//方向
	
	double m_dCX;//当前位置X坐标
	double m_dCY;//当前位置Y坐标

	CMapXFeature m_PlaneUAVFeature;
};

#endif // !defined(AFX_PLANEUAV_H__AB6C7141_E5C2_4F7E_8B0F_534B6B004936__INCLUDED_)

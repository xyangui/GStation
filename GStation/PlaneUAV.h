// PlaneUAV.h: interface for the CPlaneUAV class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANEUAV_H__AB6C7141_E5C2_4F7E_8B0F_534B6B004936__INCLUDED_)
#define AFX_PLANEUAV_H__AB6C7141_E5C2_4F7E_8B0F_534B6B004936__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MAPX.h"

class CPlaneUAV  //ֻ�����ƶ��ɻ�ͼ��
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
	double dDirectory;//����
	
	double m_dCX;//��ǰλ��X����
	double m_dCY;//��ǰλ��Y����

	CMapXFeature m_PlaneUAVFeature;
};

#endif // !defined(AFX_PLANEUAV_H__AB6C7141_E5C2_4F7E_8B0F_534B6B004936__INCLUDED_)

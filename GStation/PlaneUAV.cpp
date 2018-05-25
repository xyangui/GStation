// CPlaneUAV.cpp: implementation of the CPlaneUAV class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "PlaneUAV.h"

#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPlaneUAV::CPlaneUAV()
{
	StartX = 123.5037221;
	StartY = 41.7961444;
	dSpeed = 200;     //每小时2000公里
	dDirectory = 180; //0度正北，90度正东，180度正南，270度正西
	m_dCX = StartX;
	m_dCY = StartY;
}

CPlaneUAV::~CPlaneUAV()
{

}
//初始化，显示飞机图标，只执行一次
void CPlaneUAV::InitShowFlane(CMapX &ctrlMapX, double dXLongitude, double dYLatitude)
{
	try{ 
		CMapXFeature ftr; 
		
		if (ftr.CreateDispatch(ftr.GetClsid())) { 
			ftr = ctrlMapX.GetFeatureFactory().CreateSymbol(); 
			CMapXStyle style = ftr.GetStyle(); //获得图元的风格 
		
			//设置图元的风格，显示位图 
			style.SetSymbolType(miSymbolTypeBitmap); 
			//指定所要显示位图的存放位置 
			style.SetSymbolBitmapName("S2.BMP"); 
			//style.SetSymbolBitmapName("SS2.BMP"); 
			//指定位图大小 
			style.SetSymbolBitmapSize(32); 
			//设置为透明 
			style.SetSymbolBitmapTransparent(TRUE); 
		
			/*/如果不存在位图，显示飞机图标，飞机图标能旋转，位图不能旋转
			style.SetSymbolType(miSymbolTypeTrueTypeFont);
			style.GetSymbolFont().SetName("Map Symbols");
			style.SetSymbolCharacter(53);//设置“飞机”图标
			//如果不存在位图，显示飞机图标*/

			//指定需要显示图元的位置（经纬度位置） 
			//ftr.GetPoint().Set(123.5037221, 41.7961444);
			ftr.GetPoint().Set(dXLongitude, dYLatitude);
			
			CMapXLayers layers = ctrlMapX.GetLayers(); 
			m_PlaneUAVFeature = layers.Item("PlaneUAV").AddFeature(ftr); 
		} 
		else 
		{ 
			AfxThrowOleException(CO_E_CLASS_CREATE_FAILED); 
		} 
	} 
	
	catch (COleDispatchException *e) { 
		e->ReportError(); 
		e->Delete(); 
	} 
	catch (COleException *e) { 
		e->ReportError(); 
		e->Delete(); 
	} 
}
//根据坐标参数改变飞机图标的位置
void CPlaneUAV::UpdateCurrentPosition(double dXLongitude, double dYLatitude)
{
	m_dCX = dXLongitude;
	m_dCY = dYLatitude;
	UpdateFeature();
}
//根据m_dCX,m_dCY改变飞机图标的位置
void CPlaneUAV::UpdateFeature()
{
	CMapXPoint point;
	point.CreateDispatch(point.GetClsid());	//Creates a dispatch for the point
	point.Set(m_dCX,m_dCY); 

	m_PlaneUAVFeature.SetPoint(point.m_lpDispatch);
	m_PlaneUAVFeature.Update();
	CMapXStyle style = m_PlaneUAVFeature.GetStyle();

	if(style.GetSymbolFontRotation()!=(short)dDirectory)
	{
		style.SetSymbolFontRotation((short)dDirectory);
		m_PlaneUAVFeature.SetStyle(style.m_lpDispatch);
		m_PlaneUAVFeature.Update();	
	}
}
void CPlaneUAV::Run()
{
	double dx,dy;
	dx=dSpeed*sin(dDirectory*0.01745329)*3/(3600*60);
	dy=dSpeed*cos(dDirectory*0.01745329)*3/(3600*60);
	
	m_dCX=m_dCX+dx;
	m_dCY=m_dCY+dy;
}
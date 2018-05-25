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
	dSpeed = 200;     //ÿСʱ2000����
	dDirectory = 180; //0��������90��������180�����ϣ�270������
	m_dCX = StartX;
	m_dCY = StartY;
}

CPlaneUAV::~CPlaneUAV()
{

}
//��ʼ������ʾ�ɻ�ͼ�ִֻ꣬��һ��
void CPlaneUAV::InitShowFlane(CMapX &ctrlMapX, double dXLongitude, double dYLatitude)
{
	try{ 
		CMapXFeature ftr; 
		
		if (ftr.CreateDispatch(ftr.GetClsid())) { 
			ftr = ctrlMapX.GetFeatureFactory().CreateSymbol(); 
			CMapXStyle style = ftr.GetStyle(); //���ͼԪ�ķ�� 
		
			//����ͼԪ�ķ����ʾλͼ 
			style.SetSymbolType(miSymbolTypeBitmap); 
			//ָ����Ҫ��ʾλͼ�Ĵ��λ�� 
			style.SetSymbolBitmapName("S2.BMP"); 
			//style.SetSymbolBitmapName("SS2.BMP"); 
			//ָ��λͼ��С 
			style.SetSymbolBitmapSize(32); 
			//����Ϊ͸�� 
			style.SetSymbolBitmapTransparent(TRUE); 
		
			/*/���������λͼ����ʾ�ɻ�ͼ�꣬�ɻ�ͼ������ת��λͼ������ת
			style.SetSymbolType(miSymbolTypeTrueTypeFont);
			style.GetSymbolFont().SetName("Map Symbols");
			style.SetSymbolCharacter(53);//���á��ɻ���ͼ��
			//���������λͼ����ʾ�ɻ�ͼ��*/

			//ָ����Ҫ��ʾͼԪ��λ�ã���γ��λ�ã� 
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
//������������ı�ɻ�ͼ���λ��
void CPlaneUAV::UpdateCurrentPosition(double dXLongitude, double dYLatitude)
{
	m_dCX = dXLongitude;
	m_dCY = dYLatitude;
	UpdateFeature();
}
//����m_dCX,m_dCY�ı�ɻ�ͼ���λ��
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
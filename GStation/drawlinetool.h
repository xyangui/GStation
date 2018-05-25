#if !defined(AFX_DRAWLINETOOL_H__98CA5301_11F4_4813_B216_A15446751FA9__INCLUDED_)
#define AFX_DRAWLINETOOL_H__98CA5301_11F4_4813_B216_A15446751FA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CTeePoint2D;
class CDrawLineList;
class CPen1;

/////////////////////////////////////////////////////////////////////////////
// CDrawLineTool wrapper class

class CDrawLineTool : public COleDispatchDriver
{
public:
	CDrawLineTool() {}		// Calls COleDispatchDriver default constructor
	CDrawLineTool(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDrawLineTool(const CDrawLineTool& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	VARIANT GetSeries();
	void SetSeries(const VARIANT& newValue);
	CTeePoint2D GetFromPoint();
	CTeePoint2D GetToPoint();
	CTeePoint2D AxisPoint(double X, double Y);
	long Clicked(long X, long Y);
	void DeleteSelected();
	CTeePoint2D ScreenPoint(long X, long Y);
	CDrawLineList GetLines();
	long GetSelected();
	void SetSelected(long nNewValue);
	long GetButton();
	void SetButton(long nNewValue);
	BOOL GetEnableDraw();
	void SetEnableDraw(BOOL bNewValue);
	BOOL GetEnableSelect();
	void SetEnableSelect(BOOL bNewValue);
	CPen1 GetPen();
	long AddLine(double FromX, double FromY, double ToX, double ToY);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWLINETOOL_H__98CA5301_11F4_4813_B216_A15446751FA9__INCLUDED_)

#if !defined(AFX_AXES_H__2A9975A5_5279_49EE_9150_BC8AEF30601B__INCLUDED_)
#define AFX_AXES_H__2A9975A5_5279_49EE_9150_BC8AEF30601B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CAxis;

/////////////////////////////////////////////////////////////////////////////
// CAxes wrapper class

class CAxes : public COleDispatchDriver
{
public:
	CAxes() {}		// Calls COleDispatchDriver default constructor
	CAxes(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAxes(const CAxes& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CAxis GetLeft();
	CAxis GetRight();
	CAxis GetTop();
	CAxis GetBottom();
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	CAxis GetDepth();
	BOOL GetDrawAxesBeforeSeries();
	void SetDrawAxesBeforeSeries(BOOL bNewValue);
	long AddCustom(BOOL IsHorizontal);
	CAxis GetCustom(long CustomAxisIndex);
	long GetCustomCount();
	void RemoveCustom(long CustomAxisIndex);
	void RemoveAllCustom();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AXES_H__2A9975A5_5279_49EE_9150_BC8AEF30601B__INCLUDED_)

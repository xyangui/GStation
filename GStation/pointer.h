#if !defined(AFX_POINTER_H__845EF42E_05F1_43BE_A275_B9712092F016__INCLUDED_)
#define AFX_POINTER_H__845EF42E_05F1_43BE_A275_B9712092F016__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CBrush1;
class CPen1;

/////////////////////////////////////////////////////////////////////////////
// CPointer wrapper class

class CPointer : public COleDispatchDriver
{
public:
	CPointer() {}		// Calls COleDispatchDriver default constructor
	CPointer(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CPointer(const CPointer& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CBrush1 GetBrush();
	BOOL GetDraw3D();
	void SetDraw3D(BOOL bNewValue);
	long GetHorizontalSize();
	void SetHorizontalSize(long nNewValue);
	long GetVerticalSize();
	void SetVerticalSize(long nNewValue);
	BOOL GetInflateMargins();
	void SetInflateMargins(BOOL bNewValue);
	CPen1 GetPen();
	long GetStyle();
	void SetStyle(long nNewValue);
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	BOOL GetDark3D();
	void SetDark3D(BOOL bNewValue);
	void DrawPointer(long DC, BOOL Is3D, long px, long py, long tmpHoriz, long tmpVert, unsigned long AColor, long AStyle);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POINTER_H__845EF42E_05F1_43BE_A275_B9712092F016__INCLUDED_)
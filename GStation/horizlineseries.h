#if !defined(AFX_HORIZLINESERIES_H__6BC3B94E_4D74_441E_9EAD_10078CDD22ED__INCLUDED_)
#define AFX_HORIZLINESERIES_H__6BC3B94E_4D74_441E_9EAD_10078CDD22ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CPointer;
class CPen1;
class CBrush1;

/////////////////////////////////////////////////////////////////////////////
// CHorizLineSeries wrapper class

class CHorizLineSeries : public COleDispatchDriver
{
public:
	CHorizLineSeries() {}		// Calls COleDispatchDriver default constructor
	CHorizLineSeries(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CHorizLineSeries(const CHorizLineSeries& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CPointer GetPointer();
	BOOL GetStairs();
	void SetStairs(BOOL bNewValue);
	BOOL GetInvertedStairs();
	void SetInvertedStairs(BOOL bNewValue);
	CPen1 GetLinePen();
	long GetLineBrush();
	void SetLineBrush(long nNewValue);
	BOOL GetClickableLine();
	void SetClickableLine(BOOL bNewValue);
	long GetLineHeight();
	void SetLineHeight(long nNewValue);
	BOOL GetDark3D();
	void SetDark3D(BOOL bNewValue);
	CBrush1 GetBrush();
	BOOL GetColorEachLine();
	void SetColorEachLine(BOOL bNewValue);
	CPen1 GetOutline();
	long GetTransparency();
	void SetTransparency(long nNewValue);
	long GetStacked();
	void SetStacked(long nNewValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HORIZLINESERIES_H__6BC3B94E_4D74_441E_9EAD_10078CDD22ED__INCLUDED_)

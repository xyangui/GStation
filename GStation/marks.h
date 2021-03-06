#if !defined(AFX_MARKS_H__6D6D6404_8A91_4177_8163_F5EB8CE40194__INCLUDED_)
#define AFX_MARKS_H__6D6D6404_8A91_4177_8163_F5EB8CE40194__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CTeeFont;
class CGradient;
class CPen1;
class CSeriesMarksPositions;

/////////////////////////////////////////////////////////////////////////////
// CMarks wrapper class

class CMarks : public COleDispatchDriver
{
public:
	CMarks() {}		// Calls COleDispatchDriver default constructor
	CMarks(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CMarks(const CMarks& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	unsigned long GetColor();
	void SetColor(unsigned long newValue);
	CTeeFont GetFont();
	CGradient GetGradient();
	long GetShadowSize();
	void SetShadowSize(long nNewValue);
	unsigned long GetShadowColor();
	void SetShadowColor(unsigned long newValue);
	BOOL GetTransparent();
	void SetTransparent(BOOL bNewValue);
	long GetShapeStyle();
	void SetShapeStyle(long nNewValue);
	long GetTransparency();
	void SetTransparency(long nNewValue);
	// method 'GetShapeBounds' not emitted because of invalid return type or parameter type
	long GetBevel();
	void SetBevel(long nNewValue);
	long GetBevelWidth();
	void SetBevelWidth(long nNewValue);
	CPen1 GetArrow();
	long GetArrowLength();
	void SetArrowLength(long nNewValue);
	unsigned long GetBackColor();
	void SetBackColor(unsigned long newValue);
	BOOL GetClip();
	void SetClip(BOOL bNewValue);
	CPen1 GetFrame();
	long GetStyle();
	void SetStyle(long nNewValue);
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	CSeriesMarksPositions GetPositions();
	long Clicked(long X, long Y);
	long GetZPosition();
	void SetZPosition(long nNewValue);
	long GetAngle();
	void SetAngle(long nNewValue);
	long GetDrawEvery();
	void SetDrawEvery(long nNewValue);
	BOOL GetMultiline();
	void SetMultiline(BOOL bNewValue);
	void ResetPositions();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MARKS_H__6D6D6404_8A91_4177_8163_F5EB8CE40194__INCLUDED_)

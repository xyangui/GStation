#if !defined(AFX_TITLES_H__D377972D_3047_4B73_A185_A8468562E733__INCLUDED_)
#define AFX_TITLES_H__D377972D_3047_4B73_A185_A8468562E733__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CTeeFont;
class CGradient;
class CBrush1;
class CPen1;
class CStrings;

/////////////////////////////////////////////////////////////////////////////
// CTitles wrapper class

class CTitles : public COleDispatchDriver
{
public:
	CTitles() {}		// Calls COleDispatchDriver default constructor
	CTitles(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CTitles(const CTitles& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

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
	BOOL GetCustomPosition();
	void SetCustomPosition(BOOL bNewValue);
	long GetLeft();
	void SetLeft(long nNewValue);
	long GetTop();
	void SetTop(long nNewValue);
	BOOL GetAdjustFrame();
	void SetAdjustFrame(BOOL bNewValue);
	long GetAlignment();
	void SetAlignment(long nNewValue);
	CBrush1 GetBrush();
	CPen1 GetFrame();
	CStrings GetText();
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TITLES_H__D377972D_3047_4B73_A185_A8468562E733__INCLUDED_)

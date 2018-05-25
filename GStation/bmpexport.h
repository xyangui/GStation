#if !defined(AFX_BMPEXPORT_H__5763481F_81D3_41E7_A627_E5382BF7A983__INCLUDED_)
#define AFX_BMPEXPORT_H__5763481F_81D3_41E7_A627_E5382BF7A983__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CBMPExport wrapper class

class CBMPExport : public COleDispatchDriver
{
public:
	CBMPExport() {}		// Calls COleDispatchDriver default constructor
	CBMPExport(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CBMPExport(const CBMPExport& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetWidth();
	void SetWidth(long nNewValue);
	long GetHeight();
	void SetHeight(long nNewValue);
	void SaveToFile(LPCTSTR FileName);
	VARIANT SaveToStream();
	long GetColors();
	void SetColors(long nNewValue);
	BOOL GetMonochrome();
	void SetMonochrome(BOOL bNewValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BMPEXPORT_H__5763481F_81D3_41E7_A627_E5382BF7A983__INCLUDED_)

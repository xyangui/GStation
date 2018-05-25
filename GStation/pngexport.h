#if !defined(AFX_PNGEXPORT_H__5919B060_7C35_4115_99AF_40F0F9F0BBD6__INCLUDED_)
#define AFX_PNGEXPORT_H__5919B060_7C35_4115_99AF_40F0F9F0BBD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CPNGExport wrapper class

class CPNGExport : public COleDispatchDriver
{
public:
	CPNGExport() {}		// Calls COleDispatchDriver default constructor
	CPNGExport(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CPNGExport(const CPNGExport& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

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
	long GetCompressionLevel();
	void SetCompressionLevel(long nNewValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PNGEXPORT_H__5919B060_7C35_4115_99AF_40F0F9F0BBD6__INCLUDED_)

#if !defined(AFX_NATIVEEXPORT_H__AC2AD421_6930_44C1_9B3A_9FE75D811FF0__INCLUDED_)
#define AFX_NATIVEEXPORT_H__AC2AD421_6930_44C1_9B3A_9FE75D811FF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CNativeExport wrapper class

class CNativeExport : public COleDispatchDriver
{
public:
	CNativeExport() {}		// Calls COleDispatchDriver default constructor
	CNativeExport(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CNativeExport(const CNativeExport& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void SaveToFile(LPCTSTR FileName, BOOL IncludeData);
	VARIANT SaveToStream(BOOL IncludeData);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NATIVEEXPORT_H__AC2AD421_6930_44C1_9B3A_9FE75D811FF0__INCLUDED_)

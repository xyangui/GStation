#if !defined(AFX_INSTRUMENTCIRCLE_H__D927CFA5_91B9_4BCF_8FC0_430448A6B3B9__INCLUDED_)
#define AFX_INSTRUMENTCIRCLE_H__D927CFA5_91B9_4BCF_8FC0_430448A6B3B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// InstrumentCircle.h : main header file for INSTRUMENTCIRCLE.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CInstrumentCircleApp : See InstrumentCircle.cpp for implementation.

class CInstrumentCircleApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INSTRUMENTCIRCLE_H__D927CFA5_91B9_4BCF_8FC0_430448A6B3B9__INCLUDED)

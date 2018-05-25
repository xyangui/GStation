#if !defined(AFX_INSTRUMENTPANEL_H__5BFF501D_75C0_45C2_9E15_015F420D65B3__INCLUDED_)
#define AFX_INSTRUMENTPANEL_H__5BFF501D_75C0_45C2_9E15_015F420D65B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// InstrumentPanel.h : main header file for INSTRUMENTPANEL.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CInstrumentPanelApp : See InstrumentPanel.cpp for implementation.

class CInstrumentPanelApp : public COleControlModule
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

#endif // !defined(AFX_INSTRUMENTPANEL_H__5BFF501D_75C0_45C2_9E15_015F420D65B3__INCLUDED)

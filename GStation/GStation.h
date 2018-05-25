// GStation.h : main header file for the GSTATION application
//

#if !defined(AFX_GSTATION_H__94DF28BF_2F3A_4FB5_9B67_CDB7C5C84DE8__INCLUDED_)
#define AFX_GSTATION_H__94DF28BF_2F3A_4FB5_9B67_CDB7C5C84DE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGStationApp:
// See GStation.cpp for the implementation of this class
//

class CGStationApp : public CWinApp
{
public:
	CGStationApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGStationApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGStationApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GSTATION_H__94DF28BF_2F3A_4FB5_9B67_CDB7C5C84DE8__INCLUDED_)

// TF1D.h : main header file for the TF1D application
//

#if !defined(AFX_TF1D_H__0B5AEB23_C855_4E5F_828A_793CCBA55F85__INCLUDED_)
#define AFX_TF1D_H__0B5AEB23_C855_4E5F_828A_793CCBA55F85__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTF1DApp:
// See TF1D.cpp for the implementation of this class
//

class CTF1DApp : public CWinApp
{
public:
	CTF1DApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTF1DApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTF1DApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TF1D_H__0B5AEB23_C855_4E5F_828A_793CCBA55F85__INCLUDED_)

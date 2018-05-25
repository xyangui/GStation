#if !defined(AFX_SETTING_H__DF321ACD_1E30_4BB5_B4B0_39F3A6570788__INCLUDED_)
#define AFX_SETTING_H__DF321ACD_1E30_4BB5_B4B0_39F3A6570788__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Setting.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetting

#include "SetSerialport.h"
#include "SetSafe.h"
#include "SetInterface.h"
#include "SetAirSpeed.h"
#include "SetAltitude.h"
#include "SetPhoto.h"
#include "SetVersion.h"
#include "SetSetUp.h"
#include "SetPitchRoll.h"
#include "SetSteeringEngine.h"

class CSetting : public CPropertySheet
{
	DECLARE_DYNAMIC(CSetting)

// Construction
public:
	CSetting(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSetting(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:
	CSetSerialport  m_pageSetSerialport;
	CSetSafe        m_pageSetSafe;
	CSetInterface   m_pageSetInterface;
	CSetAirSpeed    m_pageSetAirSpeed;
	CSetAltitude    m_pageSetAltitude;
	CSetPhoto       m_pageSetPhoto;
	CSetVersion     m_pageSetVersion;
	CSetSetUp       m_pageSetSetUp;
	CSetPitchRoll   m_pageSetPitchRoll;
	CSetSteeringEngine  m_pageSetSteeringEngine;
  
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetting)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSetting();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSetting)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTING_H__DF321ACD_1E30_4BB5_B4B0_39F3A6570788__INCLUDED_)

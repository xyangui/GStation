#if !defined(AFX_INSTRUMENTPANELPPG_H__8AEEDB00_BD6C_4421_8F25_EED18EB7A856__INCLUDED_)
#define AFX_INSTRUMENTPANELPPG_H__8AEEDB00_BD6C_4421_8F25_EED18EB7A856__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// InstrumentPanelPpg.h : Declaration of the CInstrumentPanelPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CInstrumentPanelPropPage : See InstrumentPanelPpg.cpp.cpp for implementation.

class CInstrumentPanelPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CInstrumentPanelPropPage)
	DECLARE_OLECREATE_EX(CInstrumentPanelPropPage)

// Constructor
public:
	CInstrumentPanelPropPage();

// Dialog Data
	//{{AFX_DATA(CInstrumentPanelPropPage)
	enum { IDD = IDD_PROPPAGE_INSTRUMENTPANEL };
	short	m_updateFyDeg;
	short	m_updateGzDeg;
	short	m_updateDirection;
	short	m_AimAirSpeed;
	short	m_AimHeight;
	short	m_AirSpeed;
	short	m_ApHeight;
	short	m_AimDirection;
	float	m_heading;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CInstrumentPanelPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INSTRUMENTPANELPPG_H__8AEEDB00_BD6C_4421_8F25_EED18EB7A856__INCLUDED)

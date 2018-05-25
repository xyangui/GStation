#if !defined(AFX_INSTRUMENTCIRCLEPPG_H__0831CAA7_8E85_4655_870B_155D7DEECAAE__INCLUDED_)
#define AFX_INSTRUMENTCIRCLEPPG_H__0831CAA7_8E85_4655_870B_155D7DEECAAE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// InstrumentCirclePpg.h : Declaration of the CInstrumentCirclePropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CInstrumentCirclePropPage : See InstrumentCirclePpg.cpp.cpp for implementation.

class CInstrumentCirclePropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CInstrumentCirclePropPage)
	DECLARE_OLECREATE_EX(CInstrumentCirclePropPage)

// Constructor
public:
	CInstrumentCirclePropPage();

// Dialog Data
	//{{AFX_DATA(CInstrumentCirclePropPage)
	enum { IDD = IDD_PROPPAGE_INSTRUMENTCIRCLE };
	UINT	m_edit_divCount;
	int		m_edit_maxDeg;
	int		m_edit_maxValue;
	int		m_edit_minDeg;
	int		m_edit_minValue;
	double	m_edit_realValue;
	double	m_edit_aimValue;
	double	m_edit_numberFont;
	double	m_edit_labFont;
	long	m_edit_labX;
	long	m_edit_labY;
	CString	m_edit_labText;
	CString	m_edit_labTextLine2;
	CString	m_edit_labY2;
	int		m_edit_labX2;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CInstrumentCirclePropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INSTRUMENTCIRCLEPPG_H__0831CAA7_8E85_4655_870B_155D7DEECAAE__INCLUDED)

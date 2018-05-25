#if !defined(AFX_SETINTERFACE_H__0752FC87_43C3_4071_9052_4D5D7D6554D3__INCLUDED_)
#define AFX_SETINTERFACE_H__0752FC87_43C3_4071_9052_4D5D7D6554D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetInterface.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetInterface dialog

class CSetInterface : public CPropertyPage
{
	DECLARE_DYNCREATE(CSetInterface)

// Construction
public:
	CSetInterface();
	~CSetInterface();

// Dialog Data
	//{{AFX_DATA(CSetInterface)
	enum { IDD = IDD_SET_INTERFACE };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSetInterface)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSetInterface)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETINTERFACE_H__0752FC87_43C3_4071_9052_4D5D7D6554D3__INCLUDED_)

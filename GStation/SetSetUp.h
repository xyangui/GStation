#if !defined(AFX_SETSETUP_H__369442D7_8B62_4751_B74F_4E7CA97D5367__INCLUDED_)
#define AFX_SETSETUP_H__369442D7_8B62_4751_B74F_4E7CA97D5367__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetSetUp.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetSetUp dialog

class CSetSetUp : public CPropertyPage
{
	DECLARE_DYNCREATE(CSetSetUp)

// Construction
public:
	CSetSetUp();
	~CSetSetUp();

// Dialog Data
	//{{AFX_DATA(CSetSetUp)
	enum { IDD = IDD_SET_SETUP };
	CComboBox	m_combo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSetSetUp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSetSetUp)
	afx_msg void OnButtonSet();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETSETUP_H__369442D7_8B62_4751_B74F_4E7CA97D5367__INCLUDED_)

#if !defined(AFX_SETSTEERINGENGINE_H__CF1CF2F3_1E17_4C33_830A_B9189CFC606A__INCLUDED_)
#define AFX_SETSTEERINGENGINE_H__CF1CF2F3_1E17_4C33_830A_B9189CFC606A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetSteeringEngine.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetSteeringEngine dialog

class CSetSteeringEngine : public CPropertyPage
{
	DECLARE_DYNCREATE(CSetSteeringEngine)

// Construction
public:
	CSetSteeringEngine();
	~CSetSteeringEngine();

// Dialog Data
	//{{AFX_DATA(CSetSteeringEngine)
	enum { IDD = IDD_SET_STEERINGENGINE };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSetSteeringEngine)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSetSteeringEngine)
	afx_msg void OnButtonSetLaunch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETSTEERINGENGINE_H__CF1CF2F3_1E17_4C33_830A_B9189CFC606A__INCLUDED_)

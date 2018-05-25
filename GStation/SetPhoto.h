#if !defined(AFX_SETPHOTO_H__50D20D71_FC39_4F8F_AC2F_E2ABA480E0E0__INCLUDED_)
#define AFX_SETPHOTO_H__50D20D71_FC39_4F8F_AC2F_E2ABA480E0E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetPhoto.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetPhoto dialog

class CSetPhoto : public CPropertyPage
{
	DECLARE_DYNCREATE(CSetPhoto)

// Construction
public:
	CSetPhoto();
	~CSetPhoto();

// Dialog Data
	//{{AFX_DATA(CSetPhoto)
	enum { IDD = IDD_SET_PHOTO };
	int		m_iEqualTime;
	int		m_iEqualDistance;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSetPhoto)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSetPhoto)
	afx_msg void OnButtonSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETPHOTO_H__50D20D71_FC39_4F8F_AC2F_E2ABA480E0E0__INCLUDED_)

#if !defined(AFX_SETPITCHROLL_H__9B058E42_4517_4668_BD1A_CCAE419478A9__INCLUDED_)
#define AFX_SETPITCHROLL_H__9B058E42_4517_4668_BD1A_CCAE419478A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetPitchRoll.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetPitchRoll dialog

class CPayload;

class CSetPitchRoll : public CPropertyPage
{
	DECLARE_DYNCREATE(CSetPitchRoll)

// Construction
public:
	CSetPitchRoll();
	~CSetPitchRoll();

	void Unpack(CPayload payload);

// Dialog Data
	//{{AFX_DATA(CSetPitchRoll)
	enum { IDD = IDD_SET_PITCH_ROLL };
	float	m_fPitch;
	float	m_fRoll;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSetPitchRoll)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSetPitchRoll)
	afx_msg void OnButtonCapture();
	afx_msg void OnButtonSet();
	afx_msg void OnButtonToZero();
	LRESULT OnUpdateMyData(WPARAM wParam, LPARAM lParam);  	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETPITCHROLL_H__9B058E42_4517_4668_BD1A_CCAE419478A9__INCLUDED_)

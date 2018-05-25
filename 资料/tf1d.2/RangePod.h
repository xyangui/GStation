#if !defined(AFX_RANGEPOD_H__9B7A4619_C484_4CEC_BF01_0AC40F1C6F28__INCLUDED_)
#define AFX_RANGEPOD_H__9B7A4619_C484_4CEC_BF01_0AC40F1C6F28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RangePod.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRangePod dialog

class CRangePod : public CDialog
{
// Construction
public:
	CRangePod(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRangePod)
	enum { IDD = IDD_RANGEPOD };
	double	m_First_Lat;
	double	m_First_Lon;
	int		m_In_Dis;
	int		m_Linenum;
	double	m_Second_Lat;
	double	m_Second_Lon;
	double	m_lfPointDis;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRangePod)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRangePod)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RANGEPOD_H__9B7A4619_C484_4CEC_BF01_0AC40F1C6F28__INCLUDED_)

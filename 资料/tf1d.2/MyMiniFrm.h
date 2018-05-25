#if !defined(AFX_MYMINIFRM_H__0C76292A_38EA_4414_82F2_AE024DBBF212__INCLUDED_)
#define AFX_MYMINIFRM_H__0C76292A_38EA_4414_82F2_AE024DBBF212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyMiniFrm.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyMiniFrm frame

class CMyMiniFrm : public CMiniFrameWnd
{
	DECLARE_DYNCREATE(CMyMiniFrm)

public:
	CMyMiniFrm();  
protected:
         // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyMiniFrm)
	public:
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyMiniFrm();

	// Generated message map functions
	//{{AFX_MSG(CMyMiniFrm)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMINIFRM_H__0C76292A_38EA_4414_82F2_AE024DBBF212__INCLUDED_)

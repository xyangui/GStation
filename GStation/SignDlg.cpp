// SignDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gstation.h"
#include "SignDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSignDlg dialog


CSignDlg::CSignDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSignDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSignDlg)
	m_strSign = _T("");
	//}}AFX_DATA_INIT
}


void CSignDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSignDlg)
	DDX_Text(pDX, IDC_EDIT_SIGN, m_strSign);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSignDlg, CDialog)
	//{{AFX_MSG_MAP(CSignDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSignDlg message handlers

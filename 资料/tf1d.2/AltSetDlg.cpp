// AltSetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TF1D.h"
#include "AltSetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAltSetDlg dialog


CAltSetDlg::CAltSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAltSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAltSetDlg)
	m_nAlt = 0;
	//}}AFX_DATA_INIT
}


void CAltSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAltSetDlg)
	DDX_Text(pDX, IDC_ALT, m_nAlt);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAltSetDlg, CDialog)
	//{{AFX_MSG_MAP(CAltSetDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAltSetDlg message handlers

// DownSteeringDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gstation.h"
#include "DownSteeringDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDownSteeringDlg dialog


CDownSteeringDlg::CDownSteeringDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDownSteeringDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDownSteeringDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDownSteeringDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownSteeringDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDownSteeringDlg, CDialog)
	//{{AFX_MSG_MAP(CDownSteeringDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDownSteeringDlg message handlers

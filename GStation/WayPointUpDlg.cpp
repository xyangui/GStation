// WayPointUpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GStation.h"
#include "WayPointUpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWayPointUpDlg dialog


CWayPointUpDlg::CWayPointUpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWayPointUpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWayPointUpDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWayPointUpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWayPointUpDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWayPointUpDlg, CDialog)
	//{{AFX_MSG_MAP(CWayPointUpDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWayPointUpDlg message handlers

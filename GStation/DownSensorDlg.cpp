// DownSensorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gstation.h"
#include "DownSensorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDownSensorDlg dialog


CDownSensorDlg::CDownSensorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDownSensorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDownSensorDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDownSensorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownSensorDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDownSensorDlg, CDialog)
	//{{AFX_MSG_MAP(CDownSensorDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDownSensorDlg message handlers

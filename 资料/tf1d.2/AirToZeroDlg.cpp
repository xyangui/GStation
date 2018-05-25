// AirToZeroDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TF1D.h"
#include "AirToZeroDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAirToZeroDlg dialog


CAirToZeroDlg::CAirToZeroDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAirToZeroDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAirToZeroDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAirToZeroDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAirToZeroDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAirToZeroDlg, CDialog)
	//{{AFX_MSG_MAP(CAirToZeroDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAirToZeroDlg message handlers

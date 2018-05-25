// SetInterface.cpp : implementation file
//

#include "stdafx.h"
#include "GStation.h"
#include "SetInterface.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetInterface property page

IMPLEMENT_DYNCREATE(CSetInterface, CPropertyPage)

CSetInterface::CSetInterface() : CPropertyPage(CSetInterface::IDD)
{
	//{{AFX_DATA_INIT(CSetInterface)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CSetInterface::~CSetInterface()
{
}

void CSetInterface::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetInterface)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetInterface, CPropertyPage)
	//{{AFX_MSG_MAP(CSetInterface)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetInterface message handlers

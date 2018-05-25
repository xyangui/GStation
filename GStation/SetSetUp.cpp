// SetSetUp.cpp : implementation file
//

#include "stdafx.h"
#include "GStation.h"
#include "SetSetUp.h"

#include "GStationDlg.h"
#include "Setting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetSetUp property page

IMPLEMENT_DYNCREATE(CSetSetUp, CPropertyPage)

CSetSetUp::CSetSetUp() : CPropertyPage(CSetSetUp::IDD)
{
	//{{AFX_DATA_INIT(CSetSetUp)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CSetSetUp::~CSetSetUp()
{
}

void CSetSetUp::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetSetUp)
	DDX_Control(pDX, IDC_COMBO, m_combo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetSetUp, CPropertyPage)
	//{{AFX_MSG_MAP(CSetSetUp)
	ON_BN_CLICKED(IDC_BUTTON_SET, OnButtonSet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetSetUp message handlers

BOOL CSetSetUp::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_combo.SetCurSel(0);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSetSetUp::OnButtonSet() 
{
	UpdateData(TRUE);
	int iTemp = 1 + m_combo.GetCurSel();//比“代码”少1

	CSetting *pSetting = (CSetting*)GetParent();
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();

	CPacket Packet;
	Packet.m_msgid = 0x41;//设定自驾仪安装方向
	Packet.m_len = 1;
	Packet.payload.putU1(iTemp);
	Packet.generateCRC();

	pGStationDlg->SendPacket(Packet);
}

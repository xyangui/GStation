// SetAirSpeed.cpp : implementation file
//

#include "stdafx.h"
#include "GStation.h"
#include "SetAirSpeed.h"

#include "GStationDlg.h"
#include "Setting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetAirSpeed property page

IMPLEMENT_DYNCREATE(CSetAirSpeed, CPropertyPage)

CSetAirSpeed::CSetAirSpeed() : CPropertyPage(CSetAirSpeed::IDD)
{
	//{{AFX_DATA_INIT(CSetAirSpeed)
	m_iAirSpeedValue = 0;
	//}}AFX_DATA_INIT
}

CSetAirSpeed::~CSetAirSpeed()
{
}

void CSetAirSpeed::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetAirSpeed)
	DDX_Text(pDX, IDC_EDIT_AIRSPEED_VALUE, m_iAirSpeedValue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetAirSpeed, CPropertyPage)
	//{{AFX_MSG_MAP(CSetAirSpeed)
	ON_BN_CLICKED(IDC_BUTTON_AIRSPEED_TOZERO, OnButtonAirSpeedToZero)
	ON_BN_CLICKED(IDC_BUTTON_AIRSPEED_CAPTURE, OnButtonAirSpeedCapture)
	ON_BN_CLICKED(IDC_BUTTON_AIRSPEED_SET, OnButtonAirSpeedSet)
	ON_BN_CLICKED(IDC_BUTTON_AIRSPEED_DEFAULT, OnButtonAirSpeedDefault)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetAirSpeed message handlers

void CSetAirSpeed::OnButtonAirSpeedToZero() 
{
	if(AfxMessageBox(_T("注意：空速将清零！"), MB_YESNO|MB_ICONQUESTION) == IDNO)
		return;

	CSetting *pSetting = (CSetting*)GetParent();
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();

	CPacket Packet;
	Packet.m_msgid = 0x1b;//空速清零命令
	Packet.m_len = 0;
	Packet.generateCRC();

	pGStationDlg->SendPacket(Packet);
}

void CSetAirSpeed::OnButtonAirSpeedCapture() 
{
	CSetting *pSetting = (CSetting*)GetParent();
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();

	CPacket Packet;
	Packet.m_msgid = 0x1a;//获取空速计系数
	Packet.m_len = 1;

	Packet.payload.putU1(0);
	Packet.generateCRC();

	pGStationDlg->SendPacket(Packet);
}

void CSetAirSpeed::OnButtonAirSpeedSet() 
{
	UpdateData(TRUE);

	CSetting *pSetting = (CSetting*)GetParent();
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();

	CPacket Packet;
	Packet.m_msgid = 0x1a;//设定空速计系数
	Packet.m_len = 5;

	Packet.payload.putU1(1);
	Packet.payload.putU4h(m_iAirSpeedValue);
	Packet.generateCRC();

	pGStationDlg->SendPacket(Packet);
}

void CSetAirSpeed::OnButtonAirSpeedDefault() 
{
	m_iAirSpeedValue = 1498824;
	UpdateData(FALSE);
}

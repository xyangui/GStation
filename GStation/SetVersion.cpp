// SetVersion.cpp : implementation file
//

#include "stdafx.h"
#include "GStation.h"
#include "SetVersion.h"

#include "GStationDlg.h"
#include "Setting.h"
#include "Payload.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetVersion property page

IMPLEMENT_DYNCREATE(CSetVersion, CPropertyPage)

CSetVersion::CSetVersion() : CPropertyPage(CSetVersion::IDD)
{
	//{{AFX_DATA_INIT(CSetVersion)
	m_iHardWare = 0;
	m_fSoft = 0;
	//}}AFX_DATA_INIT
}

CSetVersion::~CSetVersion()
{
}

void CSetVersion::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetVersion)
	DDX_Text(pDX, IDC_EDIT_HARDWARE, m_iHardWare);
	DDX_Text(pDX, IDC_EDIT_SOFT, m_fSoft);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetVersion, CPropertyPage)
	//{{AFX_MSG_MAP(CSetVersion)
	ON_BN_CLICKED(IDC_BUTTON_CAPTURE, OnButtonCapture)
	ON_BN_CLICKED(IDC_BUTTON_SET, OnButtonSet)
	ON_MESSAGE(WM_VERSION,OnUpdateMyData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetVersion message handlers

void CSetVersion::OnButtonCapture() 
{
	CPacket Packet;
	Packet.m_msgid = 0x27;//获取飞控软硬件版本
	Packet.m_len = 1;

	Packet.payload.putU1(0);
	Packet.generateCRC();

	CSetting *pSetting = (CSetting*)GetParent();
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();

	pGStationDlg->SendPacket(Packet);
}

void CSetVersion::OnButtonSet() 
{
	UpdateData(TRUE);

	CPacket Packet;
	Packet.m_msgid = 0x27;//设置飞控软硬件版本
	Packet.m_len = 3;

	Packet.payload.putU1(1);
	Packet.payload.putU2h(m_iHardWare);//软件版本在哪设置？不能设置，也没有必要设置
	Packet.generateCRC();

	CSetting *pSetting = (CSetting*)GetParent();
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();

	pGStationDlg->SendPacket(Packet);	
}
LRESULT CSetVersion::OnUpdateMyData(WPARAM wParam, LPARAM lParam)  
{  
	UpdateData(wParam);  
    return 1;  
} 
void CSetVersion::Unpack(CPayload payload)
{
	payload.resetIndex();
	
	m_fSoft = (float)payload.getU1() / 10;
	m_iHardWare = payload.getU2h();
}


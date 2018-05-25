// SetAltitude.cpp : implementation file
//

#include "stdafx.h"
#include "GStation.h"
#include "SetAltitude.h"

#include "GStationDlg.h"
#include "Setting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetAltitude property page

IMPLEMENT_DYNCREATE(CSetAltitude, CPropertyPage)

CSetAltitude::CSetAltitude() : CPropertyPage(CSetAltitude::IDD)
{
	//{{AFX_DATA_INIT(CSetAltitude)
	m_sAltitude = 0;
	//}}AFX_DATA_INIT
}

CSetAltitude::~CSetAltitude()
{
}

void CSetAltitude::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetAltitude)
	DDX_Text(pDX, IDC_EDIT_ALTITUDE, m_sAltitude);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetAltitude, CPropertyPage)
	//{{AFX_MSG_MAP(CSetAltitude)
	ON_BN_CLICKED(IDC_BUTTON_SET, OnButtonSet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetAltitude message handlers

void CSetAltitude::OnButtonSet() 
{
	UpdateData(TRUE);
	
	CString str;
	str.Format("注意：地面相对高度将设置为%d？", m_sAltitude);

	if(AfxMessageBox(str,MB_YESNO|MB_ICONQUESTION) == IDNO)
		return;


	CSetting *pSetting = (CSetting*)GetParent();
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();

	CPacket Packet;
	Packet.m_msgid = 0x11;//设置当前气压对应高度（地面标定高度）
	Packet.m_len = 2;

	Packet.payload.putI2(m_sAltitude * 10);//飞控上的值=界面上的值*10
	Packet.generateCRC();

	pGStationDlg->SendPacket(Packet);
}

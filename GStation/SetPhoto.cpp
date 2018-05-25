// SetPhoto.cpp : implementation file
//

#include "stdafx.h"
#include "GStation.h"
#include "SetPhoto.h"

#include "GStationDlg.h"
#include "Setting.h"
#include "Payload.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetPhoto property page

IMPLEMENT_DYNCREATE(CSetPhoto, CPropertyPage)

CSetPhoto::CSetPhoto() : CPropertyPage(CSetPhoto::IDD)
{
	//{{AFX_DATA_INIT(CSetPhoto)
	m_iEqualTime = 0;
	m_iEqualDistance = 0;
	//}}AFX_DATA_INIT
}

CSetPhoto::~CSetPhoto()
{
}

void CSetPhoto::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetPhoto)
	DDX_Text(pDX, IDC_EDIT_EQUAL_TIME, m_iEqualTime);
	DDX_Text(pDX, IDC_EDIT_EQUAL_DISTANCE, m_iEqualDistance);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetPhoto, CPropertyPage)
	//{{AFX_MSG_MAP(CSetPhoto)
	ON_BN_CLICKED(IDC_BUTTON_SET, OnButtonSet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetPhoto message handlers

void CSetPhoto::OnButtonSet() 
{
	UpdateData(TRUE);
	
	int iDistanceOrTime = 3;//没有选中任何一个单选状态，即初始化时
	
	CButton *pBtn1 = (CButton *)GetDlgItem( IDC_RADIO_EQUAL_TIME ) ; 
	if ( pBtn1->GetCheck() == 1 ) 
		iDistanceOrTime = 1;
	
	CButton *pBtn2 = (CButton *)GetDlgItem( IDC_RADIO_EQUAL_DISTANCE ) ; 
	if ( pBtn2->GetCheck() == 1 ) 
		iDistanceOrTime = 0;
	
	if (iDistanceOrTime == 3) {
		AfxMessageBox("请选中“等时拍照”或者“等距拍照”！");
		return;
	}

	int iElectronOrSteering = 3;

	CButton *pBtn3 = (CButton *)GetDlgItem( IDC_RADIO_ELECTRON_DOOR ) ; 
	if ( pBtn3->GetCheck() == 1 ) 
		iElectronOrSteering = 0;
	
	CButton *pBtn4 = (CButton *)GetDlgItem( IDC_RADIO_STEER_DOOR ) ; 
	if ( pBtn4->GetCheck() == 1 ) 
		iElectronOrSteering = 1;

	if (iElectronOrSteering == 3) {
		AfxMessageBox("请选中“电子快门”或者“舵机控制快门”！");
		return;
	}

	CPacket Packet;
	Packet.m_msgid = 0x2D;//设定照相参数
	Packet.m_len = 5;
	
	Packet.payload.putU1(iDistanceOrTime);
	Packet.payload.putU1(m_iEqualTime);
	Packet.payload.putU2h(m_iEqualDistance);
	Packet.payload.putU1(iElectronOrSteering);
	Packet.generateCRC();
	
	CSetting *pSetting = (CSetting*)GetParent();
	CGStationDlg *pGStationDlg = (CGStationDlg*)pSetting->GetParent();
	
	pGStationDlg->SendPacket(Packet);		
}

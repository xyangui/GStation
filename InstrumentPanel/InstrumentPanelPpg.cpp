// InstrumentPanelPpg.cpp : Implementation of the CInstrumentPanelPropPage property page class.

#include "stdafx.h"
#include "InstrumentPanel.h"
#include "InstrumentPanelPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CInstrumentPanelPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CInstrumentPanelPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CInstrumentPanelPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CInstrumentPanelPropPage, "INSTRUMENTPANEL.InstrumentPanelPropPage.1",
	0x52a256c9, 0xec2d, 0x48b9, 0xb6, 0x9d, 0xe2, 0x4a, 0x21, 0x79, 0x49, 0xfa)


/////////////////////////////////////////////////////////////////////////////
// CInstrumentPanelPropPage::CInstrumentPanelPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CInstrumentPanelPropPage

BOOL CInstrumentPanelPropPage::CInstrumentPanelPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_INSTRUMENTPANEL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CInstrumentPanelPropPage::CInstrumentPanelPropPage - Constructor

CInstrumentPanelPropPage::CInstrumentPanelPropPage() :
	COlePropertyPage(IDD, IDS_INSTRUMENTPANEL_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CInstrumentPanelPropPage)
	m_updateFyDeg = 0;
	m_updateGzDeg = 0;
	m_updateDirection = 0;
	m_AimAirSpeed = 0;
	m_AimHeight = 0;
	m_AirSpeed = 0;
	m_ApHeight = 0;
	m_AimDirection = 0;
	m_heading = 0.0f;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CInstrumentPanelPropPage::DoDataExchange - Moves data between page and properties

void CInstrumentPanelPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CInstrumentPanelPropPage)
	DDP_Text(pDX, IDC_EDIT_FYDEG, m_updateFyDeg, _T("FyDeg") );
	DDX_Text(pDX, IDC_EDIT_FYDEG, m_updateFyDeg);
	DDV_MinMaxInt(pDX, m_updateFyDeg, -89, 89);
	DDP_Text(pDX, IDC_EDIT_GzDeg, m_updateGzDeg, _T("GzDeg") );
	DDX_Text(pDX, IDC_EDIT_GzDeg, m_updateGzDeg);
	DDV_MinMaxInt(pDX, m_updateGzDeg, -89, 89);
	DDP_Text(pDX, IDC_EDIT_DIRECTION, m_updateDirection, _T("Direction") );
	DDX_Text(pDX, IDC_EDIT_DIRECTION, m_updateDirection);
	DDV_MinMaxInt(pDX, m_updateDirection, 0, 359);
	DDP_Text(pDX, IDC_EDIT_AimAirSpeed, m_AimAirSpeed, _T("AimAirSpeed") );
	DDX_Text(pDX, IDC_EDIT_AimAirSpeed, m_AimAirSpeed);
	DDP_Text(pDX, IDC_EDIT_AimHeight, m_AimHeight, _T("AimHeight") );
	DDX_Text(pDX, IDC_EDIT_AimHeight, m_AimHeight);
	DDP_Text(pDX, IDC_EDIT_AirSpeed, m_AirSpeed, _T("AirSpeed") );
	DDX_Text(pDX, IDC_EDIT_AirSpeed, m_AirSpeed);
	DDP_Text(pDX, IDC_EDIT_ApHeight, m_ApHeight, _T("ApHeight") );
	DDX_Text(pDX, IDC_EDIT_ApHeight, m_ApHeight);
	DDP_Text(pDX, IDC_EDIT_AimDirection, m_AimDirection, _T("AimDirection") );
	DDX_Text(pDX, IDC_EDIT_AimDirection, m_AimDirection);
	DDP_Text(pDX, IDC_EDIT_HEADING, m_heading, _T("Heading") );
	DDX_Text(pDX, IDC_EDIT_HEADING, m_heading);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CInstrumentPanelPropPage message handlers

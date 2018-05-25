// InstrumentCirclePpg.cpp : Implementation of the CInstrumentCirclePropPage property page class.

#include "stdafx.h"
#include "InstrumentCircle.h"
#include "InstrumentCirclePpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CInstrumentCirclePropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CInstrumentCirclePropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CInstrumentCirclePropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CInstrumentCirclePropPage, "INSTRUMENTCIRCLE.InstrumentCirclePropPage.1",
	0xd3ce82db, 0xad02, 0x4ca5, 0x8e, 0xdc, 0x4f, 0x20, 0x7a, 0x31, 0x11, 0xbc)


/////////////////////////////////////////////////////////////////////////////
// CInstrumentCirclePropPage::CInstrumentCirclePropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CInstrumentCirclePropPage

BOOL CInstrumentCirclePropPage::CInstrumentCirclePropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_INSTRUMENTCIRCLE_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CInstrumentCirclePropPage::CInstrumentCirclePropPage - Constructor

CInstrumentCirclePropPage::CInstrumentCirclePropPage() :
	COlePropertyPage(IDD, IDS_INSTRUMENTCIRCLE_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CInstrumentCirclePropPage)
	m_edit_divCount = 0;
	m_edit_maxDeg = 0;
	m_edit_maxValue = 0;
	m_edit_minDeg = 0;
	m_edit_minValue = 0;
	m_edit_realValue = 0.0;
	m_edit_aimValue = 0.0;
	m_edit_numberFont = 0.0;
	m_edit_labFont = 0.0;
	m_edit_labX = 0;
	m_edit_labY = 0;
	m_edit_labText = _T("");
	m_edit_labTextLine2 = _T("");
	m_edit_labY2 = _T("");
	m_edit_labX2 = 0;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CInstrumentCirclePropPage::DoDataExchange - Moves data between page and properties

void CInstrumentCirclePropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CInstrumentCirclePropPage)
	DDP_Text(pDX, IDC_EDIT_DIVCOUNT, m_edit_divCount, _T("DivCount") );
	DDX_Text(pDX, IDC_EDIT_DIVCOUNT, m_edit_divCount);
	DDP_Text(pDX, IDC_EDIT_MAXDEG, m_edit_maxDeg, _T("MaxDeg") );
	DDX_Text(pDX, IDC_EDIT_MAXDEG, m_edit_maxDeg);
	DDP_Text(pDX, IDC_EDIT_MAXVALUE, m_edit_maxValue, _T("MaxValue") );
	DDX_Text(pDX, IDC_EDIT_MAXVALUE, m_edit_maxValue);
	DDP_Text(pDX, IDC_EDIT_MINDEG, m_edit_minDeg, _T("MinDeg") );
	DDX_Text(pDX, IDC_EDIT_MINDEG, m_edit_minDeg);
	DDP_Text(pDX, IDC_EDIT_MINVALUE, m_edit_minValue, _T("MinValue") );
	DDX_Text(pDX, IDC_EDIT_MINVALUE, m_edit_minValue);
	DDP_Text(pDX, IDC_EDIT_REALVALUE, m_edit_realValue, _T("RealValue") );
	DDX_Text(pDX, IDC_EDIT_REALVALUE, m_edit_realValue);
	DDP_Text(pDX, IDC_EDIT_AIMVALUE, m_edit_aimValue, _T("AimValue") );
	DDX_Text(pDX, IDC_EDIT_AIMVALUE, m_edit_aimValue);
	DDP_Text(pDX, IDC_EDIT_NumberFont, m_edit_numberFont, _T("NumberFont") );
	DDX_Text(pDX, IDC_EDIT_NumberFont, m_edit_numberFont);
	DDP_Text(pDX, IDC_EDIT_LabFont, m_edit_labFont, _T("LabFont") );
	DDX_Text(pDX, IDC_EDIT_LabFont, m_edit_labFont);
	DDP_Text(pDX, IDC_EDIT_LabX, m_edit_labX, _T("LabX") );
	DDX_Text(pDX, IDC_EDIT_LabX, m_edit_labX);
	DDP_Text(pDX, IDC_EDIT_LabY, m_edit_labY, _T("LabY") );
	DDX_Text(pDX, IDC_EDIT_LabY, m_edit_labY);
	DDP_Text(pDX, IDC_EDIT_LabText, m_edit_labText, _T("LabText") );
	DDX_Text(pDX, IDC_EDIT_LabText, m_edit_labText);
	DDP_Text(pDX, IDC_EDIT_LabTextLine2, m_edit_labTextLine2, _T("LabTextLine2") );
	DDX_Text(pDX, IDC_EDIT_LabTextLine2, m_edit_labTextLine2);
	DDP_Text(pDX, IDC_EDIT_LabY2, m_edit_labY2, _T("LabY2") );
	DDX_Text(pDX, IDC_EDIT_LabY2, m_edit_labY2);
	DDP_Text(pDX, IDC_EDIT_LabX2, m_edit_labX2, _T("LabX2") );
	DDX_Text(pDX, IDC_EDIT_LabX2, m_edit_labX2);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CInstrumentCirclePropPage message handlers

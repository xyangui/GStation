// Setting.cpp : implementation file
//

#include "stdafx.h"
#include "GStation.h"
#include "Setting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetting

IMPLEMENT_DYNAMIC(CSetting, CPropertySheet)

CSetting::CSetting(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

CSetting::CSetting(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage( &m_pageSetSerialport );	// First page
	AddPage( &m_pageSetSteeringEngine );// Second page

	AddPage( &m_pageSetPitchRoll );
	AddPage( &m_pageSetSafe );	        

	//AddPage( &m_pageSetInterface );
	//AddPage( &m_pageSetAirSpeed );
	//AddPage( &m_pageSetAltitude );

	AddPage( &m_pageSetPhoto );
	AddPage( &m_pageSetVersion );

	AddPage( &m_pageSetSetUp );
}

CSetting::~CSetting()
{
}


BEGIN_MESSAGE_MAP(CSetting, CPropertySheet)
	//{{AFX_MSG_MAP(CSetting)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetting message handlers

// MyMiniFrm.cpp : implementation file
//

#include "stdafx.h"
#include "TF1D.h"
#include "MyMiniFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyMiniFrm

IMPLEMENT_DYNCREATE(CMyMiniFrm, CMiniFrameWnd)

CMyMiniFrm::CMyMiniFrm()
{
}

CMyMiniFrm::~CMyMiniFrm()
{
}


BEGIN_MESSAGE_MAP(CMyMiniFrm, CMiniFrameWnd)
	//{{AFX_MSG_MAP(CMyMiniFrm)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyMiniFrm message handlers

BOOL CMyMiniFrm::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	BOOL br = GetParent()->OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
	// leave the default proc to handles the tooltip updating mechanism
	CMiniFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
	return br;	// return what the parent returns
}

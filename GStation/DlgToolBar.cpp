// DlgToolBar.cpp : implementation file
//

#include "stdafx.h"

#include "DlgToolBar.h"
#include <afxpriv.h>	// for WM_IDLEUPDATECMDUI

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgToolBar

BEGIN_MESSAGE_MAP(CDlgToolBar, CToolBar)
	//{{AFX_MSG_MAP(CDlgToolBar)
	ON_MESSAGE(WM_IDLEUPDATECMDUI, OnIdleUpdateCmdUI)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

///////////////////////////////////////////////////////////
// CDlgToolBar::OnIdleUpdateCmdUI
//   CToolBar::OnUpdateCmdUI() expects a CFrameWnd pointer
//   as its first parameter.  However, it only passes this
//   parameter to other functions which only require a
//   "plain" CCmdTarget pointer.
//   So, to make the compiler happy, we simply
//   cast our parent's CWnd pointer into a CFrameWnd
//   pointer before calling CToolBar::OnUpdateCmdUI().
//   This is certainly not elegant, but it works!

LRESULT CDlgToolBar::OnIdleUpdateCmdUI(WPARAM wParam, LPARAM) 
{
	CToolBar::OnIdleUpdateCmdUI(wParam, 0); 
	if (IsWindowVisible()) 
	{
		CFrameWnd *pParent = (CFrameWnd *)GetParent();
		if (pParent)
			OnUpdateCmdUI(pParent, (BOOL)wParam);
	}
	return 0L;
}

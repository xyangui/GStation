// DownPhotoDataDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GStation.h"
#include "DownPhotoDataDlg.h"

#include "GStationDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDownPhotoDataDlg dialog


CDownPhotoDataDlg::CDownPhotoDataDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDownPhotoDataDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDownPhotoDataDlg)
	m_iEnd = 1;
	m_iStart = 1;
	m_iRadio = 0;
	//}}AFX_DATA_INIT
	m_iReturn_Start = 0;
	m_iReturn_End = 0;
}


void CDownPhotoDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownPhotoDataDlg)
	DDX_Control(pDX, IDC_EDIT_END, m_cEnd);
	DDX_Control(pDX, IDC_EDIT_START, m_cStart);
	DDX_Text(pDX, IDC_EDIT_END, m_iEnd);
	DDV_MinMaxInt(pDX, m_iEnd, 1, 10000);
	DDX_Text(pDX, IDC_EDIT_START, m_iStart);
	DDV_MinMaxInt(pDX, m_iStart, 1, 10000);
	DDX_Radio(pDX, IDC_RADIO_ALL, m_iRadio);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDownPhotoDataDlg, CDialog)
	//{{AFX_MSG_MAP(CDownPhotoDataDlg)
	ON_BN_CLICKED(IDC_RADIO_ALL, OnRadioAll)
	ON_BN_CLICKED(IDC_RADIO_RANGE, OnRadioRange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDownPhotoDataDlg message handlers

void CDownPhotoDataDlg::OnRadioAll() 
{
	m_cEnd.EnableWindow(FALSE);
	m_cStart.EnableWindow(FALSE);
}

void CDownPhotoDataDlg::OnRadioRange() 
{
	m_cEnd.EnableWindow(TRUE);
	m_cStart.EnableWindow(TRUE);		
}

void CDownPhotoDataDlg::OnOK() 
{
	UpdateData(TRUE);
	if(m_iRadio == 0)
	{
		m_iReturn_Start = 0;
	    m_iReturn_End = 0;

	}else{
		if(m_iStart > m_iEnd)
		{
			AfxMessageBox("起始位置不能大于结束位置！");
		    return;
		}else{
			m_iReturn_Start = m_iStart;
			m_iReturn_End = m_iEnd;
		}
	}
	CDialog::OnOK();
}

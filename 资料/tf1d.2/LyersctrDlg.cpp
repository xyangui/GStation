// LyersctrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TF1D.h"
#include "LyersctrDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLyersctrDlg dialog


CLyersctrDlg::CLyersctrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLyersctrDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLyersctrDlg)
	m_sDirecter = _T("");
	//}}AFX_DATA_INIT
}


void CLyersctrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLyersctrDlg)
	DDX_Control(pDX, IDOK, m_cOk);
	DDX_Control(pDX, IDCANCEL, m_cCancel);
	DDX_Control(pDX, IDC_OPENMAP, m_cOpenmap);
	DDX_Control(pDX, IDC_OPENLAYER, m_cOpenlayer);
	DDX_Control(pDX, IDC_NEWLAYER, m_cNewlayer);
	DDX_Text(pDX, IDC_DIRECTER, m_sDirecter);
	DDX_Control(pDX, IDC_COMMONDIALOG1, m_comDlg);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLyersctrDlg, CDialog)
	//{{AFX_MSG_MAP(CLyersctrDlg)
	ON_BN_CLICKED(IDC_NEWLAYER, OnNewlayer)
	ON_BN_CLICKED(IDC_OPENLAYER, OnOpenlayer)
	ON_BN_CLICKED(IDC_OPENMAP, OnOpenmap)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLyersctrDlg message handlers

void CLyersctrDlg::OnNewlayer() 
{
	// TODO: Add your control notification handler code here
	m_nFlag = 1;
	CString file;
	CString strtemp;
//	CMapXLayer lay;
 	file.Empty();
	m_comDlg.SetInitDir(m_sGetDir);
	strtemp = m_comDlg.GetInitDir();
	m_comDlg.SetDialogTitle("新建航线");
	m_comDlg.SetFilter("*.tab");
	m_comDlg.SetFileName("*.tab");
 	m_comDlg.ShowOpen();
 	m_sFileName=m_comDlg.GetFileTitle();
	file=m_comDlg.GetFileName();
	file.TrimRight();
	m_sDirecter = file;
	UpdateData(FALSE);
	
}

void CLyersctrDlg::OnOpenlayer() 
{
	// TODO: Add your control notification handler code here
	m_nFlag = 2;
	CString file,name;
//	CMapXLayer lay;
 	file.Empty();
	m_comDlg.SetInitDir(m_sGetDir);
	m_comDlg.SetDialogTitle("打开航线");
	m_comDlg.SetFilter("*.tab");
	m_comDlg.SetFileName("*.tab");
 	m_comDlg.ShowOpen();

 	file=m_comDlg.GetFileName();
	m_sFileName=m_comDlg.GetFileTitle();
	file.TrimRight();
	m_sDirecter = file;
	UpdateData(FALSE);
}

void CLyersctrDlg::OnOpenmap() 
{
	// TODO: Add your control notification handler code here
	m_nFlag = 3;
	CString file,name;
//	CMapXLayer lay;
 	file.Empty();
	m_comDlg.SetDialogTitle("打开电子地图");
	m_comDlg.SetFilter("*.gst");
	m_comDlg.SetFileName("*.gst");
 	m_comDlg.ShowOpen();

 	file=m_comDlg.GetFileName();
	m_sFileName=m_comDlg.GetFileTitle();
	file.TrimRight();
	m_sDirecter = file;
	UpdateData(FALSE);
}

BOOL CLyersctrDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
//	m_comDlg.SetInitDir("\\airlines");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLyersctrDlg::OnGetDir(CString str)
{
	m_sGetDir = str;

}

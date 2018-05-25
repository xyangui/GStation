// LineComputerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TF1D.h"
#include "LineComputerDlg.h"
#include "math.h";

#define pai 3.1415926

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLineComputerDlg dialog


CLineComputerDlg::CLineComputerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLineComputerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLineComputerDlg)
	m_nAlt = 0;
	m_nForphotonum = 0;
	m_dLength = 0.0;
	m_nLinediepian = 0;
	m_nLinedis = 0;
	m_nPhotodiepian = 0;
	m_nPhotodis = 0;
	m_nPhotolength = 0;
	m_nPhotowidth = 0;
	m_dTotaldis = 0.0;
	m_dWidth = 0.0;
	m_dFenbianlv = 0.0;
	m_sJingtou = _T("");
	m_dFortime = 0.0;
	//}}AFX_DATA_INIT
}


void CLineComputerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLineComputerDlg)
	DDX_Control(pDX, IDCANCEL, m_cCancel);
	DDX_Control(pDX, IDOK, m_cOK);
	DDX_Control(pDX, IDC_JINGTOU, m_cJingtou);
	DDX_Text(pDX, IDC_ALT, m_nAlt);
	DDX_Text(pDX, IDC_FORPHOTONUM, m_nForphotonum);
	DDX_Text(pDX, IDC_LENGTH, m_dLength);
	DDX_Text(pDX, IDC_LINEDIEPIAN, m_nLinediepian);
	DDX_Text(pDX, IDC_LINEDIS, m_nLinedis);
	DDX_Text(pDX, IDC_PHOTODIEPIAN, m_nPhotodiepian);
	DDX_Text(pDX, IDC_PHOTODIS, m_nPhotodis);
	DDX_Text(pDX, IDC_PHOTOLENGTH, m_nPhotolength);
	DDX_Text(pDX, IDC_PHOTOWIDTH, m_nPhotowidth);
	DDX_Text(pDX, IDC_TOTALDIS, m_dTotaldis);
	DDX_Text(pDX, IDC_WIDTH, m_dWidth);
	DDX_Text(pDX, IDC_FENBIANLV, m_dFenbianlv);
	DDX_CBString(pDX, IDC_JINGTOU, m_sJingtou);
	DDX_Text(pDX, IDC_FORTIME, m_dFortime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLineComputerDlg, CDialog)
	//{{AFX_MSG_MAP(CLineComputerDlg)
	ON_BN_CLICKED(IDOK, OnComputer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLineComputerDlg message handlers

BOOL CLineComputerDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_cJingtou.AddString(_T("14mm"));
	m_cJingtou.InsertString(1,_T("20mm"));
	m_cJingtou.InsertString(2,_T("24mm"));
	m_cJingtou.InsertString(3,_T("28mm"));
	m_cJingtou.InsertString(4,_T("35mm"));
	m_cJingtou.InsertString(5,_T("50mm"));
	m_cJingtou.InsertString(6,_T("100mm"));
	m_cJingtou.SetCurSel(3);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLineComputerDlg::OnComputer() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_sJingtou == "14mm")
		m_nJingtou = 104;
	else if(m_sJingtou == "20mm")
		m_nJingtou = 84;
	else if(m_sJingtou == "24mm")
		m_nJingtou = 74;
	else if(m_sJingtou == "28mm")
		m_nJingtou = 65;
	else if(m_sJingtou == "35mm")
		m_nJingtou = 54;
	else if(m_sJingtou == "50mm")
		m_nJingtou = 40;
	else if(m_sJingtou == "100mm")
		m_nJingtou = 20;
	else{
		AfxMessageBox("请选择标准镜头尺寸");
//		break;
	}
	double temp;
	temp = tan(double(m_nJingtou)/180*3.1415926/2);
//	temp  = tan(double((m_nJingtou)/180*3.1415926)/2);
//飞行高度计算
	m_nAlt = m_dFenbianlv*5616/temp/2;
//单幅图长
	m_nPhotolength = 2*m_nAlt*temp;
//单幅图宽
	m_nPhotowidth = 2*m_nAlt*temp*2/3;
//航线间距计算
	m_nLinedis = m_nPhotolength*(1-double(m_nLinediepian)/100);
//拍照间距计算
	m_nPhotodis = m_nPhotolength*(1-double(m_nPhotodiepian)/100)*2/3;
//总里程计算
	m_dTotaldis = (int(m_dLength*1000/m_nLinedis)+1)*m_dWidth;
//飞行时间预计
	m_dFortime = m_dTotaldis/90;
//预计拍摄张数
	m_nForphotonum = m_dTotaldis*1000/m_nPhotodis;
	UpdateData(FALSE);
}

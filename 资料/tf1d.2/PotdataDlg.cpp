// PotdataDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TF1D.h"
#include "PotdataDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPotdataDlg dialog


CPotdataDlg::CPotdataDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPotdataDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPotdataDlg)
	m_nCheck_Photo = FALSE;
	m_nCheck_Serv1 = FALSE;
	m_nCheck_Serv3 = FALSE;
	m_nCheck_Serv2 = FALSE;
	m_nCheck_Toground = FALSE;
	m_nCheck_Toline = FALSE;
	m_nCheck_Toslide = FALSE;
	m_nMode_Alt = 0;
	m_nMode_Linetype = 0;
	m_nMode_Raid = 0;
	m_nMode_Spd = 0;
	m_nMode_Time = 0;
	m_dAlt1 = 0.0;
	m_dAlt2 = 0.0;
	m_dAlt3 = 0.0;
	m_dAlt4 = 0.0;
	m_dAlt5 = 0.0;
	m_dAlt6 = 0.0;
	m_dLat1 = 0.0;
	m_dLat5 = 0.0;
	m_dLat2 = 0.0;
	m_dLat3 = 0.0;
	m_dLat4 = 0.0;
	m_dLat6 = 0.0;
	m_nLinetype1 = 0;
	m_nLinetype2 = 0;
	m_nLinetype3 = 0;
	m_nLinetype4 = 0;
	m_nLinetype5 = 0;
	m_nLinetype6 = 0;
	m_dLon1 = 0.0;
	m_dLon2 = 0.0;
	m_dLon3 = 0.0;
	m_dLon4 = 0.0;
	m_dLon5 = 0.0;
	m_dLon6 = 0.0;
	m_nNum1 = 0;
	m_nNum2 = 0;
	m_nNum3 = 0;
	m_nNum4 = 0;
	m_nNum5 = 0;
	m_nNum6 = 0;
	m_bPhoto1 = FALSE;
	m_bPhoto2 = FALSE;
	m_bPhoto3 = FALSE;
	m_bPhoto4 = FALSE;
	m_bPhoto5 = FALSE;
	m_bPhoto6 = FALSE;
	m_nRaid1 = 0;
	m_nRaid2 = 0;
	m_nRaid3 = 0;
	m_nRaid4 = 0;
	m_nRaid5 = 0;
	m_nRaid6 = 0;
	m_bServ11 = FALSE;
	m_bServ12 = FALSE;
	m_bServ13 = FALSE;
	m_bServ14 = FALSE;
	m_bServ15 = FALSE;
	m_bServ16 = FALSE;
	m_bServ31 = FALSE;
	m_bServ32 = FALSE;
	m_bServ33 = FALSE;
	m_bServ34 = FALSE;
	m_bServ35 = FALSE;
	m_bServ36 = FALSE;
	m_bServ21 = FALSE;
	m_bServ22 = FALSE;
	m_bServ23 = FALSE;
	m_bServ24 = FALSE;
	m_bServ25 = FALSE;
	m_bServ26 = FALSE;
	m_nSpd1 = 0;
	m_nSpd3 = 0;
	m_nSpd2 = 0;
	m_nSpd4 = 0;
	m_nSpd5 = 0;
	m_nSpd6 = 0;
	m_nTime1 = 0;
	m_nTime3 = 0;
	m_nTime2 = 0;
	m_nTime4 = 0;
	m_nTime5 = 0;
	m_nTime6 = 0;
	m_bToGround1 = FALSE;
	m_bToGround2 = FALSE;
	m_bToGround3 = FALSE;
	m_bToGround4 = FALSE;
	m_bToGround5 = FALSE;
	m_bToGround6 = FALSE;
	m_bToLine1 = FALSE;
	m_bToLine2 = FALSE;
	m_bToLine3 = FALSE;
	m_bToLine4 = FALSE;
	m_bToLine5 = FALSE;
	m_bToLine6 = FALSE;
	m_bToSlide1 = FALSE;
	m_bToSlide2 = FALSE;
	m_bToSlide3 = FALSE;
	m_bToSlide4 = FALSE;
	m_bToSlide5 = FALSE;
	m_bToSlide6 = FALSE;
	//}}AFX_DATA_INIT
//	m_cScroll.EnableScrollBar(ESB_ENABLE_BOTH);
}


void CPotdataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPotdataDlg)
	DDX_Control(pDX, IDC_SCROLLBAR, m_cScroll);
	DDX_Check(pDX, IDC_CHECK_PHOTO, m_nCheck_Photo);
	DDX_Check(pDX, IDC_CHECK_SERV1, m_nCheck_Serv1);
	DDX_Check(pDX, IDC_CHECK_SERV3, m_nCheck_Serv3);
	DDX_Check(pDX, IDC_CHECK_SEVER2, m_nCheck_Serv2);
	DDX_Check(pDX, IDC_CHECK_TOGROUND, m_nCheck_Toground);
	DDX_Check(pDX, IDC_CHECK_TOLINE, m_nCheck_Toline);
	DDX_Check(pDX, IDC_CHECK_TOSLIDE, m_nCheck_Toslide);
	DDX_Text(pDX, IDC_MODEL_ALT, m_nMode_Alt);
	DDX_Text(pDX, IDC_MODEL_LINETYPE, m_nMode_Linetype);
	DDX_Text(pDX, IDC_MODEL_RAID, m_nMode_Raid);
	DDX_Text(pDX, IDC_MODEL_SPD, m_nMode_Spd);
	DDX_Text(pDX, IDC_MODEL_TIME, m_nMode_Time);
	DDX_Text(pDX, IDC_ALT1, m_dAlt1);
	DDX_Text(pDX, IDC_ALT2, m_dAlt2);
	DDX_Text(pDX, IDC_ALT3, m_dAlt3);
	DDX_Text(pDX, IDC_ALT4, m_dAlt4);
	DDX_Text(pDX, IDC_ALT5, m_dAlt5);
	DDX_Text(pDX, IDC_ALT6, m_dAlt6);
	DDX_Text(pDX, IDC_LAT1, m_dLat1);
	DDX_Text(pDX, IDC_LAT5, m_dLat5);
	DDX_Text(pDX, IDC_LAT2, m_dLat2);
	DDX_Text(pDX, IDC_LAT3, m_dLat3);
	DDX_Text(pDX, IDC_LAT4, m_dLat4);
	DDX_Text(pDX, IDC_LAT6, m_dLat6);
	DDX_Text(pDX, IDC_LINETYPE1, m_nLinetype1);
	DDX_Text(pDX, IDC_LINETYPE2, m_nLinetype2);
	DDX_Text(pDX, IDC_LINETYPE3, m_nLinetype3);
	DDX_Text(pDX, IDC_LINETYPE4, m_nLinetype4);
	DDX_Text(pDX, IDC_LINETYPE5, m_nLinetype5);
	DDX_Text(pDX, IDC_LINETYPE6, m_nLinetype6);
	DDX_Text(pDX, IDC_LON1, m_dLon1);
	DDX_Text(pDX, IDC_LON2, m_dLon2);
	DDX_Text(pDX, IDC_LON3, m_dLon3);
	DDX_Text(pDX, IDC_LON4, m_dLon4);
	DDX_Text(pDX, IDC_LON5, m_dLon5);
	DDX_Text(pDX, IDC_LON6, m_dLon6);
	DDX_Text(pDX, IDC_NUM1, m_nNum1);
	DDX_Text(pDX, IDC_NUM2, m_nNum2);
	DDX_Text(pDX, IDC_NUM3, m_nNum3);
	DDX_Text(pDX, IDC_NUM4, m_nNum4);
	DDX_Text(pDX, IDC_NUM5, m_nNum5);
	DDX_Text(pDX, IDC_NUM6, m_nNum6);
	DDX_Check(pDX, IDC_PHOTO1, m_bPhoto1);
	DDX_Check(pDX, IDC_PHOTO2, m_bPhoto2);
	DDX_Check(pDX, IDC_PHOTO3, m_bPhoto3);
	DDX_Check(pDX, IDC_PHOTO4, m_bPhoto4);
	DDX_Check(pDX, IDC_PHOTO5, m_bPhoto5);
	DDX_Check(pDX, IDC_PHOTO6, m_bPhoto6);
	DDX_Text(pDX, IDC_RAID1, m_nRaid1);
	DDX_Text(pDX, IDC_RAID2, m_nRaid2);
	DDX_Text(pDX, IDC_RAID3, m_nRaid3);
	DDX_Text(pDX, IDC_RAID4, m_nRaid4);
	DDX_Text(pDX, IDC_RAID5, m_nRaid5);
	DDX_Text(pDX, IDC_RAID6, m_nRaid6);
	DDX_Check(pDX, IDC_SERV11, m_bServ11);
	DDX_Check(pDX, IDC_SERV12, m_bServ12);
	DDX_Check(pDX, IDC_SERV13, m_bServ13);
	DDX_Check(pDX, IDC_SERV14, m_bServ14);
	DDX_Check(pDX, IDC_SERV15, m_bServ15);
	DDX_Check(pDX, IDC_SERV16, m_bServ16);
	DDX_Check(pDX, IDC_SERV31, m_bServ31);
	DDX_Check(pDX, IDC_SERV32, m_bServ32);
	DDX_Check(pDX, IDC_SERV33, m_bServ33);
	DDX_Check(pDX, IDC_SERV34, m_bServ34);
	DDX_Check(pDX, IDC_SERV35, m_bServ35);
	DDX_Check(pDX, IDC_SERV36, m_bServ36);
	DDX_Check(pDX, IDC_SEVER21, m_bServ21);
	DDX_Check(pDX, IDC_SEVER22, m_bServ22);
	DDX_Check(pDX, IDC_SEVER23, m_bServ23);
	DDX_Check(pDX, IDC_SEVER24, m_bServ24);
	DDX_Check(pDX, IDC_SEVER25, m_bServ25);
	DDX_Check(pDX, IDC_SEVER26, m_bServ26);
	DDX_Text(pDX, IDC_SPD1, m_nSpd1);
	DDX_Text(pDX, IDC_SPD3, m_nSpd3);
	DDX_Text(pDX, IDC_SPD2, m_nSpd2);
	DDX_Text(pDX, IDC_SPD4, m_nSpd4);
	DDX_Text(pDX, IDC_SPD5, m_nSpd5);
	DDX_Text(pDX, IDC_SPD6, m_nSpd6);
	DDX_Text(pDX, IDC_TIME1, m_nTime1);
	DDX_Text(pDX, IDC_TIME3, m_nTime3);
	DDX_Text(pDX, IDC_TIME2, m_nTime2);
	DDX_Text(pDX, IDC_TIME4, m_nTime4);
	DDX_Text(pDX, IDC_TIME5, m_nTime5);
	DDX_Text(pDX, IDC_TIME6, m_nTime6);
	DDX_Check(pDX, IDC_TOGROUND1, m_bToGround1);
	DDX_Check(pDX, IDC_TOGROUND2, m_bToGround2);
	DDX_Check(pDX, IDC_TOGROUND3, m_bToGround3);
	DDX_Check(pDX, IDC_TOGROUND4, m_bToGround4);
	DDX_Check(pDX, IDC_TOGROUND5, m_bToGround5);
	DDX_Check(pDX, IDC_TOGROUND6, m_bToGround6);
	DDX_Check(pDX, IDC_TOLINE1, m_bToLine1);
	DDX_Check(pDX, IDC_TOLINE2, m_bToLine2);
	DDX_Check(pDX, IDC_TOLINE3, m_bToLine3);
	DDX_Check(pDX, IDC_TOLINE4, m_bToLine4);
	DDX_Check(pDX, IDC_TOLINE5, m_bToLine5);
	DDX_Check(pDX, IDC_TOLINE6, m_bToLine6);
	DDX_Check(pDX, IDC_TOSLIDE1, m_bToSlide1);
	DDX_Check(pDX, IDC_TOSLIDE2, m_bToSlide2);
	DDX_Check(pDX, IDC_TOSLIDE3, m_bToSlide3);
	DDX_Check(pDX, IDC_TOSLIDE4, m_bToSlide4);
	DDX_Check(pDX, IDC_TOSLIDE5, m_bToSlide5);
	DDX_Check(pDX, IDC_TOSLIDE6, m_bToSlide6);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPotdataDlg, CDialog)
	//{{AFX_MSG_MAP(CPotdataDlg)
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPotdataDlg message handlers

void CPotdataDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_nPotNum>6)
		m_cScroll.SetScrollRange(1,m_nPotNum-5,TRUE);


	OnSaveListPot(m_nNum1);///保存当前修改

	if(nSBCode == 1)
	m_nScroll = m_nScroll+1;
	if(nSBCode == SB_LINEUP)
		m_nScroll = m_nScroll-1;
	if(nSBCode == 3)
		m_nScroll = m_nScroll+6;
	if(nSBCode == SB_PAGEUP)
		m_nScroll = m_nScroll-6;
	if(m_nScroll>m_nPotNum-5)
		m_nScroll = m_nPotNum-5;
	if(m_nScroll<1)
		m_nScroll = 1;

	m_cScroll.SetScrollPos(m_nScroll,TRUE);
	OnCreateStatic(m_nScroll);

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CPotdataDlg::OnCreateStatic(int linenum)
{
//	m_cScroll.EnableScrollBar(ESB_ENABLE_BOTH);
//	AfxMessageBox("hello");
//	UpdateData(FALSE);
	m_nNum1 = potdata.m_Potdata[linenum].num;
	m_dLon1 = potdata.m_Potdata[linenum].lon;
	m_dLat1 = potdata.m_Potdata[linenum].lat;
	m_dAlt1 = potdata.m_Potdata[linenum].alt;
	m_nSpd1 = potdata.m_Potdata[linenum].spd;
	m_nRaid1 = potdata.m_Potdata[linenum].raid;
	m_nTime1 = potdata.m_Potdata[linenum].time;
	m_nLinetype1 = potdata.m_Potdata[linenum].linetype;
	m_bPhoto1 = potdata.m_Potdata[linenum].photo;
	m_bServ11 = potdata.m_Potdata[linenum].serv1;
	m_bServ21 = potdata.m_Potdata[linenum].serv2;
	m_bServ31 = potdata.m_Potdata[linenum].serv3;
	m_bToGround1 = potdata.m_Potdata[linenum].toground;
	m_bToLine1 = potdata.m_Potdata[linenum].toline;
	m_bToSlide1 = potdata.m_Potdata[linenum].toslide;

	linenum++;
	m_nNum2 = potdata.m_Potdata[linenum].num;
	m_dLon2 = potdata.m_Potdata[linenum].lon;
	m_dLat2 = potdata.m_Potdata[linenum].lat;
	m_dAlt2 = potdata.m_Potdata[linenum].alt;
	m_nSpd2 = potdata.m_Potdata[linenum].spd;
	m_nRaid2 = potdata.m_Potdata[linenum].raid;
	m_nTime2 = potdata.m_Potdata[linenum].time;
	m_nLinetype2 = potdata.m_Potdata[linenum].linetype;
	m_bPhoto2 = potdata.m_Potdata[linenum].photo;
	m_bServ12 = potdata.m_Potdata[linenum].serv1;
	m_bServ22 = potdata.m_Potdata[linenum].serv2;
	m_bServ32 = potdata.m_Potdata[linenum].serv3;
	m_bToGround2 = potdata.m_Potdata[linenum].toground;
	m_bToLine2 = potdata.m_Potdata[linenum].toline;
	m_bToSlide2 = potdata.m_Potdata[linenum].toslide;

	linenum++;
	m_nNum3 = potdata.m_Potdata[linenum].num;
	m_dLon3 = potdata.m_Potdata[linenum].lon;
	m_dLat3 = potdata.m_Potdata[linenum].lat;
	m_dAlt3 = potdata.m_Potdata[linenum].alt;
	m_nSpd3 = potdata.m_Potdata[linenum].spd;
	m_nRaid3 = potdata.m_Potdata[linenum].raid;
	m_nTime3 = potdata.m_Potdata[linenum].time;
	m_nLinetype3 = potdata.m_Potdata[linenum].linetype;
	m_bPhoto3 = potdata.m_Potdata[linenum].photo;
	m_bServ13 = potdata.m_Potdata[linenum].serv1;
	m_bServ23 = potdata.m_Potdata[linenum].serv2;
	m_bServ33 = potdata.m_Potdata[linenum].serv3;
	m_bToGround3 = potdata.m_Potdata[linenum].toground;
	m_bToLine3 = potdata.m_Potdata[linenum].toline;
	m_bToSlide3 = potdata.m_Potdata[linenum].toslide;

	linenum++;
	m_nNum4 = potdata.m_Potdata[linenum].num;
	m_dLon4 = potdata.m_Potdata[linenum].lon;
	m_dLat4 = potdata.m_Potdata[linenum].lat;
	m_dAlt4 = potdata.m_Potdata[linenum].alt;
	m_nSpd4 = potdata.m_Potdata[linenum].spd;
	m_nRaid4 = potdata.m_Potdata[linenum].raid;
	m_nTime4 = potdata.m_Potdata[linenum].time;
	m_nLinetype4 = potdata.m_Potdata[linenum].linetype;
	m_bPhoto4 = potdata.m_Potdata[linenum].photo;
	m_bServ14 = potdata.m_Potdata[linenum].serv1;
	m_bServ24 = potdata.m_Potdata[linenum].serv2;
	m_bServ34 = potdata.m_Potdata[linenum].serv3;
	m_bToGround4 = potdata.m_Potdata[linenum].toground;
	m_bToLine4 = potdata.m_Potdata[linenum].toline;
	m_bToSlide4 = potdata.m_Potdata[linenum].toslide;

	linenum++;
	m_nNum5 = potdata.m_Potdata[linenum].num;
	m_dLon5 = potdata.m_Potdata[linenum].lon;
	m_dLat5 = potdata.m_Potdata[linenum].lat;
	m_dAlt5 = potdata.m_Potdata[linenum].alt;
	m_nSpd5 = potdata.m_Potdata[linenum].spd;
	m_nRaid5 = potdata.m_Potdata[linenum].raid;
	m_nTime5 = potdata.m_Potdata[linenum].time;
	m_nLinetype5 = potdata.m_Potdata[linenum].linetype;
	m_bPhoto5 = potdata.m_Potdata[linenum].photo;
	m_bServ15 = potdata.m_Potdata[linenum].serv1;
	m_bServ25 = potdata.m_Potdata[linenum].serv2;
	m_bServ35 = potdata.m_Potdata[linenum].serv3;
	m_bToGround5 = potdata.m_Potdata[linenum].toground;
	m_bToLine5 = potdata.m_Potdata[linenum].toline;
	m_bToSlide5 = potdata.m_Potdata[linenum].toslide;

	linenum++;
	m_nNum6 = potdata.m_Potdata[linenum].num;
	m_dLon6 = potdata.m_Potdata[linenum].lon;
	m_dLat6 = potdata.m_Potdata[linenum].lat;
	m_dAlt6 = potdata.m_Potdata[linenum].alt;
	m_nSpd6 = potdata.m_Potdata[linenum].spd;
	m_nRaid6 = potdata.m_Potdata[linenum].raid;
	m_nTime6 = potdata.m_Potdata[linenum].time;
	m_nLinetype6 = potdata.m_Potdata[linenum].linetype;
	m_bPhoto6 = potdata.m_Potdata[linenum].photo;
	m_bServ16 = potdata.m_Potdata[linenum].serv1;
	m_bServ26 = potdata.m_Potdata[linenum].serv2;
	m_bServ36 = potdata.m_Potdata[linenum].serv3;
	m_bToGround6 = potdata.m_Potdata[linenum].toground;
	m_bToLine6 = potdata.m_Potdata[linenum].toline;
	m_bToSlide6 = potdata.m_Potdata[linenum].toslide;

	UpdateData(FALSE);

}

BOOL CPotdataDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_cScroll.EnableScrollBar(ESB_ENABLE_BOTH);

	m_nScroll = 1;



	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPotdataDlg::OnPotListInit()
{



	m_nMode_Alt = m_model_Potdata.alt;
	m_nMode_Linetype = m_model_Potdata.linetype;
	m_nMode_Raid = m_model_Potdata.raid;
	m_nMode_Spd = m_model_Potdata.spd;
	m_nMode_Time = m_model_Potdata.time;
	m_nCheck_Photo = m_model_Potdata.photo;
	m_nCheck_Serv1 = m_model_Potdata.serv1;
	m_nCheck_Serv2 = m_model_Potdata.serv2;
	m_nCheck_Serv3 = m_model_Potdata.serv3;
	m_nCheck_Toground = m_model_Potdata.toground;
	m_nCheck_Toline = m_model_Potdata.toline;
	m_nCheck_Toslide = m_model_Potdata.toslide;
if(m_nPotNum>=1)
{
	m_nNum1 = potdata.m_Potdata[1].num;
	m_dLon1 = potdata.m_Potdata[1].lon;
	m_dLat1 = potdata.m_Potdata[1].lat;
	m_dAlt1 = potdata.m_Potdata[1].alt;
	m_nSpd1 = potdata.m_Potdata[1].spd;
	m_nRaid1 = potdata.m_Potdata[1].raid;
	m_nTime1 = potdata.m_Potdata[1].time;
	m_nLinetype1 = potdata.m_Potdata[1].linetype;
	m_bPhoto1 = potdata.m_Potdata[1].photo;
	m_bServ11 = potdata.m_Potdata[1].serv1;
	m_bServ21 = potdata.m_Potdata[1].serv2;
	m_bServ31 = potdata.m_Potdata[1].serv3;
	m_bToGround1 = potdata.m_Potdata[1].toground;
	m_bToLine1 = potdata.m_Potdata[1].toline;
	m_bToSlide1 = potdata.m_Potdata[1].toslide;
}
if(m_nPotNum>=2)
{
	m_nNum2 = potdata.m_Potdata[2].num;
	m_dLon2 = potdata.m_Potdata[2].lon;
	m_dLat2 = potdata.m_Potdata[2].lat;
	m_dAlt2 = potdata.m_Potdata[2].alt;
	m_nSpd2 = potdata.m_Potdata[2].spd;
	m_nRaid2 = potdata.m_Potdata[2].raid;
	m_nTime2 = potdata.m_Potdata[2].time;
	m_nLinetype2 = potdata.m_Potdata[2].linetype;
	m_bPhoto2 = potdata.m_Potdata[2].photo;
	m_bServ12 = potdata.m_Potdata[2].serv1;
	m_bServ22 = potdata.m_Potdata[2].serv2;
	m_bServ32 = potdata.m_Potdata[2].serv3;
	m_bToGround2 = potdata.m_Potdata[2].toground;
	m_bToLine2 = potdata.m_Potdata[2].toline;
	m_bToSlide2 = potdata.m_Potdata[2].toslide;
}
if(m_nPotNum>=3)
{
	m_nNum3 = potdata.m_Potdata[3].num;
	m_dLon3 = potdata.m_Potdata[3].lon;
	m_dLat3 = potdata.m_Potdata[3].lat;
	m_dAlt3 = potdata.m_Potdata[3].alt;
	m_nSpd3 = potdata.m_Potdata[3].spd;
	m_nRaid3 = potdata.m_Potdata[3].raid;
	m_nTime3 = potdata.m_Potdata[3].time;
	m_nLinetype3 = potdata.m_Potdata[3].linetype;
	m_bPhoto3 = potdata.m_Potdata[3].photo;
	m_bServ13 = potdata.m_Potdata[3].serv1;
	m_bServ23 = potdata.m_Potdata[3].serv2;
	m_bServ33 = potdata.m_Potdata[3].serv3;
	m_bToGround3 = potdata.m_Potdata[3].toground;
	m_bToLine3 = potdata.m_Potdata[3].toline;
	m_bToSlide3 = potdata.m_Potdata[3].toslide;
}
if(m_nPotNum>=4)
{
	m_nNum4 = potdata.m_Potdata[4].num;
	m_dLon4 = potdata.m_Potdata[4].lon;
	m_dLat4 = potdata.m_Potdata[4].lat;
	m_dAlt4 = potdata.m_Potdata[4].alt;
	m_nSpd4 = potdata.m_Potdata[4].spd;
	m_nRaid4 = potdata.m_Potdata[4].raid;
	m_nTime4 = potdata.m_Potdata[4].time;
	m_nLinetype4 = potdata.m_Potdata[4].linetype;
	m_bPhoto4 = potdata.m_Potdata[4].photo;
	m_bServ14 = potdata.m_Potdata[4].serv1;
	m_bServ24 = potdata.m_Potdata[4].serv2;
	m_bServ34 = potdata.m_Potdata[4].serv3;
	m_bToGround4 = potdata.m_Potdata[4].toground;
	m_bToLine4 = potdata.m_Potdata[4].toline;
	m_bToSlide4 = potdata.m_Potdata[4].toslide;
}
if(m_nPotNum>=5)
{
	m_nNum5 = potdata.m_Potdata[5].num;
	m_dLon5 = potdata.m_Potdata[5].lon;
	m_dLat5 = potdata.m_Potdata[5].lat;
	m_dAlt5 = potdata.m_Potdata[5].alt;
	m_nSpd5 = potdata.m_Potdata[5].spd;
	m_nRaid5 = potdata.m_Potdata[5].raid;
	m_nTime5 = potdata.m_Potdata[5].time;
	m_nLinetype5 = potdata.m_Potdata[5].linetype;
	m_bPhoto5 = potdata.m_Potdata[5].photo;
	m_bServ15 = potdata.m_Potdata[5].serv1;
	m_bServ25 = potdata.m_Potdata[5].serv2;
	m_bServ35 = potdata.m_Potdata[5].serv3;
	m_bToGround5 = potdata.m_Potdata[5].toground;
	m_bToLine5 = potdata.m_Potdata[5].toline;
	m_bToSlide5 = potdata.m_Potdata[5].toslide;
}
if(m_nPotNum>=6)
{
	m_nNum6 = potdata.m_Potdata[6].num;
	m_dLon6 = potdata.m_Potdata[6].lon;
	m_dLat6 = potdata.m_Potdata[6].lat;
	m_dAlt6 = potdata.m_Potdata[6].alt;
	m_nSpd6 = potdata.m_Potdata[6].spd;
	m_nRaid6 = potdata.m_Potdata[6].raid;
	m_nTime6 = potdata.m_Potdata[6].time;
	m_nLinetype6 = potdata.m_Potdata[6].linetype;
	m_bPhoto6 = potdata.m_Potdata[6].photo;
	m_bServ16 = potdata.m_Potdata[6].serv1;
	m_bServ26 = potdata.m_Potdata[6].serv2;
	m_bServ36 = potdata.m_Potdata[6].serv3;
	m_bToGround6 = potdata.m_Potdata[6].toground;
	m_bToLine6 = potdata.m_Potdata[6].toline;
	m_bToSlide6 = potdata.m_Potdata[6].toslide;
}
}

void CPotdataDlg::OnSaveListPot(int linenum)
{
	UpdateData(TRUE);
	potdata.m_Potdata[linenum].num = m_nNum1;
	potdata.m_Potdata[linenum].lon = m_dLon1;
	potdata.m_Potdata[linenum].lat = m_dLat1;
	potdata.m_Potdata[linenum].alt = m_dAlt1;
	potdata.m_Potdata[linenum].spd = m_nSpd1;
	potdata.m_Potdata[linenum].raid = m_nRaid1;
	potdata.m_Potdata[linenum].time = m_nTime1;
	potdata.m_Potdata[linenum].linetype = m_nLinetype1;
	potdata.m_Potdata[linenum].photo = m_bPhoto1;
	potdata.m_Potdata[linenum].serv1 = m_bServ11;
	potdata.m_Potdata[linenum].serv2 = m_bServ21;
	potdata.m_Potdata[linenum].serv3 = m_bServ31;
	potdata.m_Potdata[linenum].toground = m_bToGround1;
	potdata.m_Potdata[linenum].toline = m_bToLine1;
	potdata.m_Potdata[linenum].toslide = m_bToSlide1;

	linenum++;
	potdata.m_Potdata[linenum].num = m_nNum2;
	potdata.m_Potdata[linenum].lon = m_dLon2;
	potdata.m_Potdata[linenum].lat = m_dLat2;
	potdata.m_Potdata[linenum].alt = m_dAlt2;
	potdata.m_Potdata[linenum].spd = m_nSpd2;
	potdata.m_Potdata[linenum].raid = m_nRaid2;
	potdata.m_Potdata[linenum].time = m_nTime2;
	potdata.m_Potdata[linenum].linetype = m_nLinetype2;
	potdata.m_Potdata[linenum].photo = m_bPhoto2;
	potdata.m_Potdata[linenum].serv1 = m_bServ12;
	potdata.m_Potdata[linenum].serv2 = m_bServ22;
	potdata.m_Potdata[linenum].serv3 = m_bServ32;
	potdata.m_Potdata[linenum].toground = m_bToGround2;
	potdata.m_Potdata[linenum].toline = m_bToLine2;
	potdata.m_Potdata[linenum].toslide = m_bToSlide2;

	linenum++;
	potdata.m_Potdata[linenum].num = m_nNum3;
	potdata.m_Potdata[linenum].lon = m_dLon3;
	potdata.m_Potdata[linenum].lat = m_dLat3;
	potdata.m_Potdata[linenum].alt = m_dAlt3;
	potdata.m_Potdata[linenum].spd = m_nSpd3;
	potdata.m_Potdata[linenum].raid = m_nRaid3;
	potdata.m_Potdata[linenum].time = m_nTime3;
	potdata.m_Potdata[linenum].linetype = m_nLinetype3;
	potdata.m_Potdata[linenum].photo = m_bPhoto3;
	potdata.m_Potdata[linenum].serv1 = m_bServ13;
	potdata.m_Potdata[linenum].serv2 = m_bServ23;
	potdata.m_Potdata[linenum].serv3 = m_bServ33;
	potdata.m_Potdata[linenum].toground = m_bToGround3;
	potdata.m_Potdata[linenum].toline = m_bToLine3;
	potdata.m_Potdata[linenum].toslide = m_bToSlide3;

	linenum++;
	potdata.m_Potdata[linenum].num = m_nNum4;
	potdata.m_Potdata[linenum].lon = m_dLon4;
	potdata.m_Potdata[linenum].lat = m_dLat4;
	potdata.m_Potdata[linenum].alt = m_dAlt4;
	potdata.m_Potdata[linenum].spd = m_nSpd4;
	potdata.m_Potdata[linenum].raid = m_nRaid4;
	potdata.m_Potdata[linenum].time = m_nTime4;
	potdata.m_Potdata[linenum].linetype = m_nLinetype4;
	potdata.m_Potdata[linenum].photo = m_bPhoto4;
	potdata.m_Potdata[linenum].serv1 = m_bServ14;
	potdata.m_Potdata[linenum].serv2 = m_bServ24;
	potdata.m_Potdata[linenum].serv3 = m_bServ34;
	potdata.m_Potdata[linenum].toground = m_bToGround4;
	potdata.m_Potdata[linenum].toline = m_bToLine4;
	potdata.m_Potdata[linenum].toslide = m_bToSlide4;

	linenum++;
	potdata.m_Potdata[linenum].num = m_nNum5;
	potdata.m_Potdata[linenum].lon = m_dLon5;
	potdata.m_Potdata[linenum].lat = m_dLat5;
	potdata.m_Potdata[linenum].alt = m_dAlt5;
	potdata.m_Potdata[linenum].spd = m_nSpd5;
	potdata.m_Potdata[linenum].raid = m_nRaid5;
	potdata.m_Potdata[linenum].time = m_nTime5;
	potdata.m_Potdata[linenum].linetype = m_nLinetype5;
	potdata.m_Potdata[linenum].photo = m_bPhoto5;
	potdata.m_Potdata[linenum].serv1 = m_bServ15;
	potdata.m_Potdata[linenum].serv2 = m_bServ25;
	potdata.m_Potdata[linenum].serv3 = m_bServ35;
	potdata.m_Potdata[linenum].toground = m_bToGround5;
	potdata.m_Potdata[linenum].toline = m_bToLine5;
	potdata.m_Potdata[linenum].toslide = m_bToSlide5;

	linenum++;
	potdata.m_Potdata[linenum].num = m_nNum6;
	potdata.m_Potdata[linenum].lon = m_dLon6;
	potdata.m_Potdata[linenum].lat = m_dLat6;
	potdata.m_Potdata[linenum].alt = m_dAlt6;
	potdata.m_Potdata[linenum].spd = m_nSpd6;
	potdata.m_Potdata[linenum].raid = m_nRaid6;
	potdata.m_Potdata[linenum].time = m_nTime6;
	potdata.m_Potdata[linenum].linetype = m_nLinetype6;
	potdata.m_Potdata[linenum].photo = m_bPhoto6;
	potdata.m_Potdata[linenum].serv1 = m_bServ16;
	potdata.m_Potdata[linenum].serv2 = m_bServ26;
	potdata.m_Potdata[linenum].serv3 = m_bServ36;
	potdata.m_Potdata[linenum].toground = m_bToGround6;
	potdata.m_Potdata[linenum].toline = m_bToLine6;
	potdata.m_Potdata[linenum].toslide = m_bToSlide6;

	linenum++;

}

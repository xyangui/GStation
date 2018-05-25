// TF1DDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TF1D.h"
#include "TF1DDlg.h"
#include "portsetdlg.h"
#include "potdatadlg.h"
#include "lyersctrDlg.h"
#include "Safesetdlg.h"
#include "math.h"
#include "rangepod.h"
#include "uavsetdlg.h"
#include "airtozerodlg.h"
#include "altsetdlg.h"
#include "btsetdlg.h"
#include "photosetdlg.h"
#include "linecomputerdlg.h"






#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define MYTOOL_DISTANCE 100
#define MYTOOL_DISTANCEON 101
#define MYTOOL_POINT 102
#define MYTOOL_POINT_RANGE 103
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTF1DDlg dialog

CTF1DDlg::CTF1DDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTF1DDlg::IDD, pParent)
{
	OnSafedataInit();
//	OnSomeDataInit();
	//{{AFX_DATA_INIT(CTF1DDlg)
	m_bCheckLine = FALSE;
	m_bMapSelectable = FALSE;
	m_nPoint_Target = 0;
	m_Point_Target_Send = 2;
	m_bCheckRealLine = TRUE;
	m_bCheckUpLine = TRUE;
	m_nFlyspeed = 16;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTF1DDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTF1DDlg)
	DDX_Control(pDX, IDC_TOTALDIS, m_cTotalDis);
	DDX_Control(pDX, IDC_SHOWSPEED, m_cShowSpeed);
	DDX_Control(pDX, IDC_SHOWSITE, m_cShowSite);
	DDX_Control(pDX, IDC_SITESLIDE, m_cSiteSlider);
	DDX_Control(pDX, IDC_SENDTARGETPOINT, m_cSendtargetpoint);
	DDX_Control(pDX, IDC_OPENCPV, m_cOpenCPV);
	DDX_Control(pDX, IDC_CPVSPEED, m_cCPVspeed);
	DDX_Control(pDX, IDC_CPVHEADING, m_cCPVheading);
	DDX_Control(pDX, IDC_CPVALT, m_cCPValt);
	DDX_Control(pDX, IDC_BEGAINFLY, m_cBegainfly);
	DDX_Control(pDX, IDC_COPYPOINTS, m_cCopyPoints);
	DDX_Control(pDX, IDC_SPEEDSLIDER, m_cSpeedSlider);
	DDX_Control(pDX, IDC_FREQUENCY, m_cFrequency);
	DDX_Control(pDX, IDC_PHOTONUM, m_cPhotoNum);
	DDX_Control(pDX, IDC_DATASTYLE, m_cDataStyle);
	DDX_Control(pDX, IDC_CLOSERECEIVE, m_cClosereceive);
	DDX_Control(pDX, IDC_SERIATEPHOTOSTOP, m_cSeriatePhotoStop);
	DDX_Control(pDX, IDC_ASKPHOTONUM, m_cAskPhotoNum);
	DDX_Control(pDX, IDC_DOWNPHOTODATA, m_cDownPhotoData);
	DDX_Control(pDX, IDC_HEADINGPHOTO, m_cHeadingPhoto);
	DDX_Control(pDX, IDC_SERIATEPHOTO, m_cSeriatePhoto);
	DDX_Control(pDX, IDC_POINTTARGET, m_cPoint_Target);
	DDX_Control(pDX, IDC_DOWNLOADPOINTS, m_cDownloadPoints);
	DDX_Control(pDX, ID_UPLOADPOINT, m_cUploadPoint);
	DDX_Control(pDX, IDC_ROLL, m_cRoll);
	DDX_Control(pDX, IDC_PITCH, m_cPitch);
	DDX_Control(pDX, IDC_HEADING, m_cHeading);
	DDX_Control(pDX, IDC_RANGEPOINTS, m_cRangePoints);
	DDX_Control(pDX, IDC_CHECKLINE, m_cCheckLine);
	DDX_Control(pDX, IDC_DISTANCE, m_cDistance);
	DDX_Control(pDX, IDC_POTDATA, m_cPotdata);
	DDX_Control(pDX, IDC_POINTS, m_cPoints);
	DDX_Control(pDX, IDC_AIROW, m_cAirow);
	DDX_Control(pDX, IDC_LAYERSCTR, m_cLayersCtr);
	DDX_Control(pDX, IDC_MOVE, m_cMove);
	DDX_Control(pDX, IDC_SELECT, m_cSelect);
	DDX_Control(pDX, IDC_SELECTRECT, m_cSelectRect);
	DDX_Control(pDX, IDC_ZOOMOUT, m_cZoomOut);
	DDX_Control(pDX, IDC_ZOOMIN, m_cZoomIn);
	DDX_Control(pDX, IDC_MAP1, m_cMap);
	DDX_Control(pDX, IDC_MSCOMM, m_Com);
	DDX_Control(pDX, IDC_COMMONDIALOG1, m_comDlg);
	DDX_Check(pDX, IDC_CHECKLINE, m_bCheckLine);
	DDX_Check(pDX, IDC_CHECKMAPSELECTABLE, m_bMapSelectable);
	DDX_Control(pDX, IDC_METER_ALT, m_cMeter_Alt);
	DDX_Control(pDX, IDC_METER_HEAD, m_cMeter_Head);
	DDX_Control(pDX, IDC_METER_RPM, m_cMeter_Rpm);
	DDX_Control(pDX, IDC_METER_SPD, m_cMeter_Spd);
	DDX_Control(pDX, IDC_AIRCTRL, m_cAirctrl);
	DDX_Text(pDX, IDC_POINTTARGET, m_nPoint_Target);
	DDX_Text(pDX, IDC_POINTTARGETSEND, m_Point_Target_Send);
	DDX_Check(pDX, IDC_CHECKREALLINE, m_bCheckRealLine);
	DDX_Check(pDX, IDC_CHECKUPLINE, m_bCheckUpLine);
	DDX_Control(pDX, IDC_COMMONDIALOG2, m_comDlg2);
	DDX_Text(pDX, IDC_FLYSPEED, m_nFlyspeed);
	DDV_MinMaxInt(pDX, m_nFlyspeed, 15, 25);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTF1DDlg, CDialog)
	//{{AFX_MSG_MAP(CTF1DDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_TOOL, OnTool)
	ON_UPDATE_COMMAND_UI(ID_TOOL, OnUpdateTool)
	ON_BN_CLICKED(IDC_AIROW, OnAirow)
	ON_BN_CLICKED(IDC_LAYERSCTR, OnLayersctr)
	ON_BN_CLICKED(IDC_MOVE, OnMove)
	ON_BN_CLICKED(IDC_POINTS, OnPoints)
	ON_BN_CLICKED(IDC_SELECT, OnSelect)
	ON_BN_CLICKED(IDC_SELECTRECT, OnSelectrect)
	ON_BN_CLICKED(IDC_ZOOMIN, OnZoomin)
	ON_BN_CLICKED(IDC_ZOOMOUT, OnZoomout)
	ON_COMMAND(ID_PORTSET, OnPortset)
	ON_BN_CLICKED(IDC_POTDATA, OnPotdata)
	ON_COMMAND(ID_DATAGET, OnDataget)
	ON_COMMAND(ID_SAFESET, OnSafeset)
	ON_BN_CLICKED(IDC_DISTANCE, OnDistance)
	ON_COMMAND(ID_UPLOADPOINT, OnUploadpoint)
	ON_COMMAND(ID_INSERTPOINT, OnInsertpoint)
	ON_BN_CLICKED(IDC_LAYERCONTRAL, OnLayercontral)
	ON_BN_CLICKED(IDC_CHECKLINE, OnCheckline)
	ON_BN_CLICKED(IDC_CHECKMAPSELECTABLE, OnCheckmapselectable)
	ON_BN_CLICKED(IDC_RANGEPOINTS, OnRangepoints)
	ON_BN_CLICKED(IDC_DOWNLOADPOINTS, OnDownloadpoints)
	ON_BN_CLICKED(IDC_SENDTARGETPOINT, OnSendtargetpoint)
	ON_COMMAND(ID_UAVSET, OnUavset)
	ON_COMMAND(ID_MENU_BUHUO_ZHONGLI, OnMenuBuhuoZhongli)
	ON_COMMAND(ID_MENU_BUHUO_STOPOIL, OnMenuBuhuoStopoil)
	ON_COMMAND(ID_MENU_BUHUO_MINOIL, OnMenuBuhuoMinoil)
	ON_COMMAND(ID_MENU_BUHUO_MAXOIL, OnMenuBuhuoMaxoil)
	ON_BN_CLICKED(IDC_SERIATEPHOTO, OnSeriatephoto)
	ON_BN_CLICKED(IDC_SERIATEPHOTOSTOP, OnSeriatephotostop)
	ON_BN_CLICKED(IDC_HEADINGPHOTO, OnHeadingphoto)
	ON_BN_CLICKED(IDC_DOWNPHOTODATA, OnDownphotodata)
	ON_BN_CLICKED(IDC_ASKPHOTONUM, OnAskphotonum)
	ON_BN_CLICKED(IDC_CLOSERECEIVE, OnClosereceive)
	ON_BN_CLICKED(IDC_CHECKUPLINE, OnCheckupline)
	ON_BN_CLICKED(IDC_CHECKREALLINE, OnCheckrealline)
	ON_WM_TIMER()
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SPEEDSLIDER, OnReleasedcaptureSpeedslider)
	ON_COMMAND(ID_UPLOADSOMEPOINT, OnUploadsomepoint)
	ON_BN_CLICKED(IDC_COPYPOINTS, OnCopypoints)
	ON_COMMAND(ID_DATASHOW, OnDatashow)
	ON_COMMAND(ID_YAOCEDATA, OnYaocedata)
	ON_COMMAND(ID_YAOCEDATASTOP, OnYaocedatastop)
	ON_BN_CLICKED(IDC_BEGAINFLY, OnBegainfly)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SITESLIDE, OnReleasedcaptureSiteslide)
	ON_COMMAND(ID_PICSHOW, OnPicshow)
	ON_BN_CLICKED(IDC_BPLAYSITE, OnBplaysiteSet)
	ON_BN_CLICKED(ID_UPLOADPOINT, OnUploadpoint)
	ON_COMMAND(ID_MENUITEM_COMPUTER, OnLineComputer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTF1DDlg message handlers

BOOL CTF1DDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}


	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
//	toolbar.Create(this);
//	toolbar.SetBarStyle(toolbar.GetBarStyle() |
//		CBRS_TOOLTIPS | CBRS_FLYBY|CBRS_BORDER_ANY | CBRS_SIZE_DYNAMIC|0x800|CBRS_GRIPPER);
//	toolbar.LoadToolBar(IDR_TOOLBAR);

//	EnableDocking(CBRS_ALIGN_ANY)
//	toolbar.EnableDocking(CBRS_ALIGN_ANY);

	
//	CBitmap bitmap;
//	bitmap.LoadBitmap(IDB_BITMAP2);
//	m_cBttest.SetBitmap(bitmap);

//	toolbar.Create(this);
//	toolbar.SetBarStyle(toolbar.GetBarStyle() |
//		CBRS_TOOLTIPS | CBRS_FLYBY|CBRS_BORDER_ANY | CBRS_SIZE_DYNAMIC|0x800|CBRS_GRIPPER);
//	toolbar.LoadToolBar(IDR_TOOLBAR);
	
//	toolbar.LoadBitmap(IDB_BITMAP1);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
//	toolbar.ShowWindow(TRUE);
	CenterWindow();
/////////////////////////////////////////////////////////
	m_cMap.SetGeoSet("map\\china.gst");
	m_cMap.SetTitleText("");
////////////关闭已有图层的可选择性///////////////////////
	long tempnum;
	tempnum = m_cMap.GetLayers().GetCount();
	for(int i=1;i<=tempnum;i++)
	{
		m_cMap.GetLayers().Item(i).SetSelectable(FALSE);
	}
	OnCreateOtherLayers();
	m_cMap.SetAutoRedraw(FALSE);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
	OnCreateStatic();
	OnButtonInit();
	OnSomeDataInit();
	m_cMap.CreateCustomTool(MYTOOL_DISTANCE, miToolTypePoly, miCrossCursor);
	m_cMap.CreateCustomTool(MYTOOL_POINT,miToolTypePoly, miCrossCursor);
	m_nButton_Flag = 0;
	m_pts.CreateDispatch(m_pts.GetClsid());
	IDofFeature = -1;
	fpFlag = FALSE;
	m_nTotalNum = 0;
	m_nTotalNum_Timer = 0;

///////////////////////////////////////////////////////////////////////////////
//	CFile fptemp;
/*	CString str_temp = "ini.txt";
	fpini = new CFile("ini.txt",CFile::modeRead|CFile::modeWrite|CFile::typeBinary);
	if(!fpini)//.Open("ini.txt",CFile::modeRead|CFile::modeWrite|CFile::typeBinary))
	{
		fpini->Open("ini.txt",CFile::modeCreate|CFile::modeWrite|CFile::modeRead);
	    fpini->Write("115200",6);
	}
	str_parth = fpini->GetFilePath();
	int len;
	CString str;
	len = str_parth.GetLength();
	str_parth.Delete(len-8,8);
*/
//	len = fpini->GetLength();
//	LPVOID m_pData;
//	pData = new unsigned char[len];
//	m_pData = (LPVOID)pData;
//	fpini->Read(m_pData,len);
//	pData = (unsigned char*)m_pData;
//	str = pData;
//////////////////////////////////////////////////////////////////////////////
	m_cSpeedSlider.SetRangeMax(6);
	m_cSpeedSlider.SetRangeMin(0);
	m_cShowSpeed.SetWindowText("0X");
	m_cSiteSlider.SetRangeMax(1000);
	m_cSiteSlider.SetRangeMin(0);
	m_cShowSite.SetWindowText("0‰");
	m_bFilesaveFlag = FALSE;
	m_bTime2Flag = TRUE;

//////////////////////////////////////////////////////////////////////////////
OnFileInit();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTF1DDlg::OnSysCommand(UINT nID, LPARAM  lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTF1DDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;


//		CBrush brush;
//		brush.CreateSolidBrush(RGB(230,235,243));
//		dc.FillRect(&rect,&brush);
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
//		CPaintDC dc(this); 
//		CRect rect;
//		GetClientRect(&rect);
//		CBrush brush;
//		brush.CreateSolidBrush(RGB(230,235,243));
//		dc.FillRect(&rect,&brush);
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTF1DDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTF1DDlg::OnOK() 
{
	// TODO: Add extra validation here
//	static1.SetWindowText("应答：已应答!");
//	CWnd* wnd = AfxGetMainWnd();
//	toolbar.Create(this,CBRS_FLOATING);
//	toolbar.LoadToolBar(IDR_TOOLBAR);
//	CDialog::OnOK();
}

//DEL void CTF1DDlg::OnButton2() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	AfxMessageBox("button2");
//DEL }

//void CTF1DDlg::OnButton32782() 
//{
	// TODO: Add your command handler code here
//	AfxMessageBox("button1");
	
//}

void CTF1DDlg::OnTool() 
{
	// TODO: Add your command handler code here
//AfxMessageBox("hellotool");
//	if(toolbar)
	{
		if(toolbar.IsWindowVisible())
			toolbar.ShowWindow(FALSE);
		else
			toolbar.ShowWindow(TRUE);
	}
//	UpdateWindow();
}

void CTF1DDlg::OnUpdateTool(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(toolbar) {
		if(toolbar.IsWindowVisible())
		{
			pCmdUI->SetCheck(FALSE);
		}
		else
		{
			pCmdUI->SetCheck(TRUE);
		}
	}
	else
		pCmdUI->SetCheck(TRUE);

	
}

void CTF1DDlg::CreateToolBar()
{

//	toolbar.EnableDocking(CBRS_ALIGN_TOP | CBRS_ALIGN_BOTTOM);
}

void CTF1DDlg::OnCreateStatic()
{
	
	CRect rect;
	CFont *font;
//	DWORD temp;
	font = this->GetFont();

	GetClientRect(&rect);
	int left,bottom,right;
	left = rect.left;
	bottom = rect.bottom;
	right = rect.right;

//	temp = m_cStatictest.GetStyle();

	yingdaled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left,bottom-20,left+20,bottom),this,IDC_STATIC1);
	yingda.Create("",1342312960,CRect(left+20,bottom-20,left+130,bottom),this,IDC_STATIC1);

	tongxunled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+132,bottom-20,left+152,bottom),this,IDC_STATIC1);
	tongxun.Create("",1342312960,CRect(left+152,bottom-20,left+232,bottom),this,IDC_STATIC1);

	moshiled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+234,bottom-20,left+254,bottom),this,IDC_STATIC1);
	moshi.Create("",1342312960,CRect(left+254,bottom-20,left+334,bottom),this,IDC_STATIC1);

	GPSled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+336,bottom-20,left+356,bottom),this,IDC_STATIC1);
	GPS.Create("",1342312960,CRect(left+356,bottom-20,left+426,bottom),this,IDC_STATIC1);

	weixingled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+428,bottom-20,left+448,bottom),this,IDC_STATIC1);
	weixing.Create("",1342312960,CRect(left+448,bottom-20,left+518,bottom),this,IDC_STATIC1);

	dianya_zongled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+520,bottom-20,left+540,bottom),this,IDC_STATIC1);
	dianya_zong.Create("",1342312960,CRect(left+540,bottom-20,left+640,bottom),this,IDC_STATIC1);

	dianya_duojiled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+642,bottom-20,left+662,bottom),this,IDC_STATIC1);
	dianya_duoji.Create("",1342312960,CRect(left+664,bottom-20,left+770,bottom),this,IDC_STATIC1);

	wenduled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+772,bottom-20,left+792,bottom),this,IDC_STATIC1);
	wendu.Create("",1342312960,CRect(left+794,bottom-20,left+900,bottom),this,IDC_STATIC1);

	qiyaled.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_ICON|SS_CENTER,CRect(left+902,bottom-20,left+922,bottom),this,IDC_STATIC1);
	qiya.Create("",1342312960,CRect(left+924,bottom-20,left+1022,bottom),this,IDC_STATIC1);

//	pianhang1.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_CENTER,CRect(left+5,bottom-45,left+60,bottom-25),this,IDC_STATIC1);
	pianhang1.Create("",1342312961,CRect(left+5,bottom-45,left+60,bottom-25),this,IDC_STATIC1);

	receiverled.Create("",WS_CHILD|WS_VISIBLE|SS_ICON|SS_CENTER,CRect(right-30,bottom-80,right-10,bottom-60),this,IDC_STATIC1);

	GPSTime.Create("",1342312960,CRect(left+707,bottom-45,left+910,bottom-25),this,IDC_STATIC1);

	pianhang.Create("",1342312960,CRect(left+58,bottom-45,left+120,bottom-25),this,IDC_STATIC1);
	distance_zeropoint1.Create("",1342312961,CRect(left+122,bottom-45,left+195,bottom-25),this,IDC_STATIC1);
	distance_zeropoint.Create("",1342312960,CRect(left+195,bottom-45,left+285,bottom-25),this,IDC_STATIC1);
	distance_currentpoint1.Create("",1342312961,CRect(left+287,bottom-45,left+360,bottom-25),this,IDC_STATIC1);
	distance_currentpoint.Create("",1342312960,CRect(left+360,bottom-45,left+450,bottom-25),this,IDC_STATIC1);
	zhishishijian1.Create("",1342312961,CRect(left+452,bottom-45,left+522,bottom-25),this,IDC_STATIC1);
	zhishishijian.Create("",1342312960,CRect(left+522,bottom-45,left+580,bottom-25),this,IDC_STATIC1);
	shengdian1.Create("",1342312961,CRect(left+582,bottom-45,left+652,bottom-25),this,IDC_STATIC1);
	shengdian.Create("",1342312960,CRect(left+652,bottom-45,left+702,bottom-25),this,IDC_STATIC1);

	
	mousepoint1.Create("",1342312961,CRect(left+5,bottom-67,left+60,bottom-47),this,IDC_STATIC1);
	mousepoint.Create("",1342312960,CRect(left+60,bottom-67,left+190,bottom-47),this,IDC_STATIC1);
	currentpoint1.Create("",1342312961,CRect(left+192,bottom-67,left+247,bottom-47),this,IDC_STATIC1);
	currentpoint.Create("",1342312960,CRect(left+247,bottom-67,left+377,bottom-47),this,IDC_STATIC1);
	distancepoints1.Create("",1342312961,CRect(left+380,bottom-67,left+460,bottom-47),this,IDC_STATIC1);
	distancepoints.Create("",1342312960,CRect(left+460,bottom-67,left+702,bottom-47),this,IDC_STATIC1);
//	alldistance1.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_CENTER,CRect(left+5,bottom-67,left+60,bottom-47),this,IDC_STATIC1);
//	alldistance.Create("",WS_CHILD|WS_VISIBLE|SS_SUNKEN|SS_CENTER,CRect(left+5,bottom-67,left+60,bottom-47),this,IDC_STATIC1);

//	static_bg;
	yingda.SetFont(font,TRUE);
	tongxun.SetFont(font,TRUE);
	moshi.SetFont(font,TRUE);
	GPS.SetFont(font,TRUE);
	weixing.SetFont(font,TRUE);
	dianya_duoji.SetFont(font,TRUE);
	dianya_zong.SetFont(font,TRUE);
	wendu.SetFont(font,TRUE);
	qiya.SetFont(font,TRUE);
	GPSTime.SetFont(font,TRUE);
//	xitongshijian;

	pianhang.SetFont(font,TRUE);
	distance_zeropoint.SetFont(font,TRUE);
	distance_currentpoint.SetFont(font,TRUE);
	shengdian.SetFont(font,TRUE);
	zhishishijian.SetFont(font,TRUE);
	pianhang1.SetFont(font,TRUE);
	distance_zeropoint1.SetFont(font,TRUE);
	distance_currentpoint1.SetFont(font,TRUE);
	shengdian1.SetFont(font,TRUE);
	zhishishijian1.SetFont(font,TRUE);

	mousepoint.SetFont(font,TRUE);
	mousepoint1.SetFont(font,TRUE);
	currentpoint.SetFont(font,TRUE);
	currentpoint1.SetFont(font,TRUE);
	distancepoints.SetFont(font,TRUE);
	distancepoints1.SetFont(font,TRUE);
//	desireddistance1.SetFont(font,TRUE);
//	desireddistance.SetFont(font,TRUE);
//	realdistance1.SetFont(font,TRUE);
//	realdistance.SetFont(font,TRUE);
//	remaindistance1.SetFont(font,TRUE);
//	remaindistance.SetFont(font,TRUE);



	mousepoint1.SetWindowText("鼠标点:");
//	mousepoint.SetWindowText("123.452636, 42.568954");
	currentpoint1.SetWindowText("飞机点:");
	distancepoints1.SetWindowText("矢量距离:");



	pianhang1.SetWindowText("偏航距:");
	distance_zeropoint1.SetWindowText("距起飞点:");
	distance_currentpoint1.SetWindowText("距目标点:");
	zhishishijian1.SetWindowText("制式时间:");
	shengdian1.SetWindowText("剩余航点:");

	yingdaled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDOFF));
	yingda.SetWindowText("应答:");
	
	tongxunled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDOFF));
	tongxun.SetWindowText("通讯:");

	
	moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWAR));
	moshi.SetWindowText("模式:");
	
	GPSled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWAR));
	GPS.SetWindowText("GPS:");

	
	weixingled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWAR));
	weixing.SetWindowText("卫星:");
	
	dianya_zongled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWAR));
	dianya_zong.SetWindowText("总电压:");
	
	dianya_duojiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWAR));
	dianya_duoji.SetWindowText("舵机电压:");
	
	wenduled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	wendu.SetWindowText("温度: ");

	qiyaled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	qiya.SetWindowText("气压: ");

	GPSTime.SetWindowText("GPS时间:");

	receiverled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
}

void CTF1DDlg::OnButtonInit()
{
	m_cZoomIn.SetIcon(AfxGetApp()->LoadIcon(IDI_ZOOMIN));
	m_cZoomOut.SetIcon(AfxGetApp()->LoadIcon(IDI_ZOOMOUT));
	m_cMove.SetIcon(AfxGetApp()->LoadIcon(IDI_MOVE));
	m_cSelect.SetIcon(AfxGetApp()->LoadIcon(IDI_SELECT));
	m_cSelectRect.SetIcon(AfxGetApp()->LoadIcon(IDI_SELECTRECT));
	m_cLayersCtr.SetIcon(AfxGetApp()->LoadIcon(IDI_LAYERSCTR));
	m_cAirow.SetIcon(AfxGetApp()->LoadIcon(IDI_AIROW));
	m_cPoints.SetIcon(AfxGetApp()->LoadIcon(IDI_POINTS));
	m_cPotdata.SetIcon(AfxGetApp()->LoadIcon(IDI_POTDATA));
	m_cDistance.SetIcon(AfxGetApp()->LoadIcon(IDI_DISTANCE));
	m_cRangePoints.SetIcon(AfxGetApp()->LoadIcon(IDI_RANGEPOINTS));
	m_cUploadPoint.SetIcon(AfxGetApp()->LoadIcon(IDI_UPPOINTS));
	m_cDownloadPoints.SetIcon(AfxGetApp()->LoadIcon(IDI_DOWNPOINTS));
	m_cSeriatePhoto.SetIcon(AfxGetApp()->LoadIcon(IDI_LIANPAI));
	m_cSeriatePhotoStop.SetIcon(AfxGetApp()->LoadIcon(IDI_LIANPAIOFF));
	m_cDownPhotoData.SetIcon(AfxGetApp()->LoadIcon(IDI_DOWNPHOTODATA));
	m_cHeadingPhoto.SetIcon(AfxGetApp()->LoadIcon(IDI_HEADINGPHOTO));
	m_cAskPhotoNum.SetIcon(AfxGetApp()->LoadIcon(IDI_ASKPHOTONUM));
	m_cCopyPoints.SetIcon(AfxGetApp()->LoadIcon(IDI_COPYPOINTS));

}

BEGIN_EVENTSINK_MAP(CTF1DDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CTF1DDlg)
	ON_EVENT(CTF1DDlg, IDC_MAP1, -605 /* MouseDown */, OnMouseDownMap, VTS_I2 VTS_I2 VTS_R4 VTS_R4)
	ON_EVENT(CTF1DDlg, IDC_MSCOMM, 1 /* OnComm */, OnOnCommMscomm, VTS_NONE)
	ON_EVENT(CTF1DDlg, IDC_MAP1, -606 /* MouseMove */, OnMouseMoveMap, VTS_I2 VTS_I2 VTS_R4 VTS_R4)
	ON_EVENT(CTF1DDlg, IDC_MAP1, -607 /* MouseUp */, OnMouseUpMap, VTS_I2 VTS_I2 VTS_R4 VTS_R4)
	ON_EVENT(CTF1DDlg, IDC_MAP1, -602 /* KeyDown */, OnKeyDownMap, VTS_PI2 VTS_I2)
	ON_EVENT(CTF1DDlg, IDC_MAP1, 15 /* MapDraw */, OnMapDrawMap, VTS_I2)
	ON_EVENT(CTF1DDlg, IDC_MAP1, -604 /* KeyUp */, OnKeyUpMap, VTS_PI2 VTS_I2)
	//}}AFX_EVENTSINK_MAP
	ON_EVENT(CTF1DDlg, IDC_MAP1, 11 /* PolyToolUsed */, OnPolyToolUsedMap, VTS_I2 VTS_I4 VTS_DISPATCH VTS_BOOL VTS_BOOL VTS_PBOOL)
//	ON_EVENT(CTF1DDlg, IDC_MAP1, 12 /* PointToolUsed */, OnPointToolUsedMap, VTS_I2 VTS_I4 VTS_DISPATCH VTS_BOOL VTS_BOOL VTS_PBOOL)

END_EVENTSINK_MAP()

void CTF1DDlg::OnMouseUpMap(short Button, short Shift, float X, float Y) 
{
	// TODO: Add your control notification handler code here
if(Button == 1)
	{
		double x,y;
		m_cMap.ConvertCoord(&X,&Y,&x,&y,miScreenToMap);
		if((x-m_lfLon_MouseDown!=0)||(y-m_lfLat_MouseDown!=0))
			m_bMouseUpOK = TRUE;
		m_cMap.SetAutoRedraw(TRUE);
//		m_cMap.RedrawWindow();//.UpdateWindow();
//		m_cMap.SetRedrawInterval(1000);//.SetRedraw(TRUE);
//		Sleep(1000);

	}
//		m_cMap.SetAutoRedraw(FALSE);
}
void CTF1DDlg::OnMouseDownMap(short Button, short Shift, float X, float Y) 
{
	// TODO: Add your control notification handler code here
	double x,y;
	m_cMap.ConvertCoord(&X,&Y,&x,&y,miScreenToMap);

	if(Button == 1)
	{
		if(m_MapToolNum == MYTOOL_DISTANCE||m_MapToolNum == MYTOOL_POINT)
		{
			m_MapToolNum = MYTOOL_DISTANCEON;
			m_lfLon_MouseDown = x;
			m_lfLat_MouseDown = y;
			m_lfDistance_All = 0;
		}else
		{
			double d = m_cMap.Distance(m_lfLon_MouseDown, m_lfLat_MouseDown, x, y)*1.609;
			m_lfLon_MouseDown = x;
			m_lfLat_MouseDown = y;
			m_lfDistance_All+=d;
		}
	}else if(Button==2)
	{
		CMenu menu;
		CMenu *pMenu=NULL;  // pop-up menu 
		menu.LoadMenu(IDR_MENUMOUSE);
	
		pMenu = menu.GetSubMenu(0);
	
		SetMenuDefaultItem(pMenu->m_hMenu, IDC_ZOOMIN, FALSE);
		POINT pt;
		GetCursorPos(&pt);

		////////////////////////////////////////////////
		//判断是否选定一个航点，以决定是否激活变灰菜单//
		////////////////////////////////////////////////
		if(m_sLayerName_Points!="")
		{
		CMapXLayer lay;
		lay = m_cMap.GetLayers().Item(m_sLayerName_Points);
		m_Features_Select = lay.GetSelection();
		if(m_Features_Select.GetCount()==1)
		{
		pMenu->EnableMenuItem(ID_INSERTPOINT,MF_ENABLED);
		pMenu->EnableMenuItem(ID_UPLOADSOMEPOINT,MF_ENABLED);
		}
		}

		pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pt.x, pt.y, this, NULL); 

 
    // Destroy the menu. 
		menu.DestroyMenu(); 
	}
}

void CTF1DDlg::OnAirow() 
{
	// TODO: Add your control notification handler code here
	m_cMap.SetCurrentTool(miArrowTool);
	m_MapToolNum = miArrowTool;
	
}

void CTF1DDlg::OnLayersctr() 
{
	// TODO: Add your control notification handler code here
	CString strtemp;
	CLyersctrDlg layerDlg;

	strtemp.Format("%s\\airlines",str_parth);

	layerDlg.OnGetDir(strtemp);

	if(layerDlg.DoModal() == IDOK)
	{
		m_Layercontral.m_nFlag = layerDlg.m_nFlag;
		m_Layercontral.m_sLayerDirecte = layerDlg.m_sDirecter;
		m_Layercontral.m_sLayerName = layerDlg.m_sFileName;
	}else return;
	if(m_Layercontral.m_nFlag == 1)
	{
		OnNewLayer(m_Layercontral.m_sLayerDirecte,m_Layercontral.m_sLayerName);
	}else if(m_Layercontral.m_nFlag ==2)
	{
		OnOpenLayer(m_Layercontral.m_sLayerDirecte,m_Layercontral.m_sLayerName);
	}else if(m_Layercontral.m_nFlag ==3)
	{
		OnOpenMap(m_Layercontral.m_sLayerDirecte,m_Layercontral.m_sLayerName);
	}else
	{
	}
}

void CTF1DDlg::OnMove() 
{
	// TODO: Add your control notification handler code here
	m_cMap.SetCurrentTool(miPanTool);
	m_MapToolNum = miPanTool;
	
}


void CTF1DDlg::OnSelect() 
{
	// TODO: Add your control notification handler code here
	m_cMap.SetCurrentTool(miSelectTool);
	m_MapToolNum = miSelectTool;
	
}

void CTF1DDlg::OnSelectrect() 
{
	// TODO: Add your control notification handler code here
	m_cMap.SetCurrentTool(miRectSelectTool);
	m_MapToolNum = miRectSelectTool;
	
}

void CTF1DDlg::OnZoomin() 
{
	// TODO: Add your control notification handler code here
	m_cMap.SetCurrentTool(miZoomInTool);
	m_MapToolNum = miZoomInTool;
}

void CTF1DDlg::OnZoomout() 
{
	// TODO: Add your control notification handler code here
	m_cMap.SetCurrentTool(miZoomOutTool);
//	m_cMap.SetCurrentTool(miLabelTool);
	m_MapToolNum = miZoomOutTool;

	
}

void CTF1DDlg::OnPortset() 
{
	// TODO: Add your command handler code here
	CPortsetDlg portDlg;
	CString m_tempsCom;
//	CString m_tempsBt;
	CString str_temp;
	CString str,strtemp;
	CFile* m_pFile;

	portDlg.m_nPort = m_nPort;
	str_temp.Format("COM%d",m_nPort);
	portDlg.m_sCom = str_temp;
	portDlg.m_sBt = m_sBt;
	if(portDlg.DoModal() == IDOK)
	{
		m_tempsCom = portDlg.m_sCom;
		m_sBt = portDlg.m_sBt;

		m_strSettings.Format("%s,%s",m_sBt,"n,8,1");
		if(m_tempsCom == "COM1")
			m_nPort = 1;
		else if(m_tempsCom == "COM2")
			m_nPort = 2;
		else if(m_tempsCom == "COM3")
			m_nPort = 3;
		else m_nPort = 4;

		str_temp.Format("%s\\ini.txt",str_parth);
		str.Format("%d%s",m_nPort,m_sBt);

		m_pFile=new CFile(str_temp,CFile::modeCreate|CFile::modeRead|CFile::typeBinary|CFile::modeWrite);
 	//文件是否打开判断
		if(!m_pFile) {AfxMessageBox("系统默认文件ini.txt丢失");}
		m_pFile->Write(str,str.GetLength());

		m_pFile->Close();
 	}
	delete portDlg;
}


void CTF1DDlg::OnOnCommMscomm() 
{
	// TODO: Add your control notification handler code here

	VARIANT variant_inp;
	COleSafeArray safearray_inp;
	LONG len,k;
	BYTE rxdata[2048]; //设置BYTE数组 An 8-bit integerthat is not signed.
	CString strtemp;
	CString inttemp;
//	int checktemp;
	CString strtemp2;

	if(bReceive)
	{
	
//		m_nLengthGed=0;
		if(m_Com.GetCommEvent()==2)     //事件值为2表示接收缓冲区内有字符
		{
			strtemp="";
			variant_inp = m_Com.GetInput();   //读缓冲区
			safearray_inp = variant_inp;           //VARIANT型变量转换为ColeSafeArray型变量
			len=safearray_inp.GetOneDimSize(); //得到有效数据长度
			for(k=0;k<len;k++)
				safearray_inp.GetElement(&k,rxdata+k);//转换为BYTE型数组
//			m_nLengthGed = len;//总数据长度

			for(k=0;k<len;k++)             //将数组转换为Cstring型变量
			{
				const unsigned char bt=*(unsigned char*)(rxdata+k);//无符号型
				strtemp.Format("%d",bt); //以十进制形式保存数据
				GetStrReceived(strtemp);//数据处理

			}
		}
	}


}

void CTF1DDlg::OpenPort()
{
	
	if(m_Com.GetPortOpen())
		m_Com.SetPortOpen(FALSE);

	m_Com.SetCommPort(m_nPort);       //选择com1
	if( !m_Com.GetPortOpen())
		m_Com.SetPortOpen(TRUE);//打开串口
	else
		AfxMessageBox("cannot open serial port");

	m_Com.SetSettings(m_strSettings); //波特率115200，无校验，8个数据位，1个停止位
	m_Com.SetRThreshold(1); 
	//参数1表示每当串口接收缓冲区中有多于或等于1个字符时将引发一个接收数据的OnComm事件
	m_Com.SetInputMode(1);
	m_Com.SetInputLen(0);  //设置当前接收区数据长度为0
	m_Com.GetInput();//先预读缓冲区以清除残留数据	

}

void CTF1DDlg::OnPotdata() 
{
	// TODO: Add your control notification handler code here
	CPotdataDlg potDlg;
	potDlg.potdata = potdata;
	potDlg.m_nPotNum = m_dFtrsNum;
	potDlg.m_model_Potdata.alt = m_model_Potdata.alt;
	potDlg.m_model_Potdata.linetype = m_model_Potdata.linetype;
	potDlg.m_model_Potdata.photo = m_model_Potdata.photo;
	potDlg.m_model_Potdata.raid = m_model_Potdata.raid;
	potDlg.m_model_Potdata.serv1 = m_model_Potdata.serv1;
	potDlg.m_model_Potdata.serv2 = m_model_Potdata.serv2;
	potDlg.m_model_Potdata.serv3 = m_model_Potdata.serv3;
	potDlg.m_model_Potdata.spd = m_model_Potdata.spd;
	potDlg.m_model_Potdata.time = m_model_Potdata.time;
	potDlg.m_model_Potdata.toground = m_model_Potdata.toground;
	potDlg.m_model_Potdata.toline = m_model_Potdata.toline;
	potDlg.m_model_Potdata.toslide = m_model_Potdata.toslide;
	potDlg.OnPotListInit();
	UpdateData(TRUE);

	if(potDlg.DoModal() == IDOK)
	{
		potdata = potDlg.potdata;
		UpdateData(TRUE);
		if(potdata.m_Potdata[potDlg.m_nNum1].num>0)
		{
			potdata.m_Potdata[potDlg.m_nNum1].num = potDlg.m_nNum1;
			potdata.m_Potdata[potDlg.m_nNum1].lon = potDlg.m_dLon1;
			potdata.m_Potdata[potDlg.m_nNum1].lat = potDlg.m_dLat1;
			potdata.m_Potdata[potDlg.m_nNum1].alt = potDlg.m_dAlt1;	
			potdata.m_Potdata[potDlg.m_nNum1].spd = potDlg.m_nSpd1;
			potdata.m_Potdata[potDlg.m_nNum1].raid = potDlg.m_nRaid1;
			potdata.m_Potdata[potDlg.m_nNum1].time = potDlg.m_nTime1;
			potdata.m_Potdata[potDlg.m_nNum1].linetype = potDlg.m_nLinetype1;	
			potdata.m_Potdata[potDlg.m_nNum1].photo = potDlg.m_bPhoto1;	
			potdata.m_Potdata[potDlg.m_nNum1].serv1 = potDlg.m_bServ11;
			potdata.m_Potdata[potDlg.m_nNum1].serv2 = potDlg.m_bServ21;
			potdata.m_Potdata[potDlg.m_nNum1].serv3 = potDlg.m_bServ31;
			potdata.m_Potdata[potDlg.m_nNum1].toground = potDlg.m_bToGround1;
			potdata.m_Potdata[potDlg.m_nNum1].toline = potDlg.m_bToLine1;
			potdata.m_Potdata[potDlg.m_nNum1].toslide = potDlg.m_bToSlide1;
		}


		if(potdata.m_Potdata[potDlg.m_nNum2].num>0)
		{
			potdata.m_Potdata[potDlg.m_nNum2].num = potDlg.m_nNum2;
			potdata.m_Potdata[potDlg.m_nNum2].lon = potDlg.m_dLon2;
			potdata.m_Potdata[potDlg.m_nNum2].lat = potDlg.m_dLat2;
			potdata.m_Potdata[potDlg.m_nNum2].alt = potDlg.m_dAlt2;
			potdata.m_Potdata[potDlg.m_nNum2].spd = potDlg.m_nSpd2;
			potdata.m_Potdata[potDlg.m_nNum2].raid = potDlg.m_nRaid2;
			potdata.m_Potdata[potDlg.m_nNum2].time = potDlg.m_nTime2;
			potdata.m_Potdata[potDlg.m_nNum2].linetype = potDlg.m_nLinetype2;
			potdata.m_Potdata[potDlg.m_nNum2].photo = potDlg.m_bPhoto2;
			potdata.m_Potdata[potDlg.m_nNum2].serv1 = potDlg.m_bServ12;
			potdata.m_Potdata[potDlg.m_nNum2].serv2 = potDlg.m_bServ22;
			potdata.m_Potdata[potDlg.m_nNum2].serv3 = potDlg.m_bServ32;
			potdata.m_Potdata[potDlg.m_nNum2].toground = potDlg.m_bToGround2;
			potdata.m_Potdata[potDlg.m_nNum2].toline = potDlg.m_bToLine2;
			potdata.m_Potdata[potDlg.m_nNum2].toslide = potDlg.m_bToSlide2;
		}

		if(potdata.m_Potdata[potDlg.m_nNum3].num>0)
		{
			potdata.m_Potdata[potDlg.m_nNum3].num = potDlg.m_nNum3;
			potdata.m_Potdata[potDlg.m_nNum3].lon = potDlg.m_dLon3;
			potdata.m_Potdata[potDlg.m_nNum3].lat = potDlg.m_dLat3;
			potdata.m_Potdata[potDlg.m_nNum3].alt = potDlg.m_dAlt3;
			potdata.m_Potdata[potDlg.m_nNum3].spd = potDlg.m_nSpd3;
			potdata.m_Potdata[potDlg.m_nNum3].raid = potDlg.m_nRaid3;
			potdata.m_Potdata[potDlg.m_nNum3].time = potDlg.m_nTime3;
			potdata.m_Potdata[potDlg.m_nNum3].linetype = potDlg.m_nLinetype3;
			potdata.m_Potdata[potDlg.m_nNum3].photo = potDlg.m_bPhoto3;
			potdata.m_Potdata[potDlg.m_nNum3].serv1 = potDlg.m_bServ13;
			potdata.m_Potdata[potDlg.m_nNum3].serv2 = potDlg.m_bServ23;
			potdata.m_Potdata[potDlg.m_nNum3].serv3 = potDlg.m_bServ33;
			potdata.m_Potdata[potDlg.m_nNum3].toground = potDlg.m_bToGround3;
			potdata.m_Potdata[potDlg.m_nNum3].toline = potDlg.m_bToLine3;
			potdata.m_Potdata[potDlg.m_nNum3].toslide = potDlg.m_bToSlide3;
		}


		if(potdata.m_Potdata[potDlg.m_nNum4].num>0)
		{
			potdata.m_Potdata[potDlg.m_nNum4].num = potDlg.m_nNum4;
			potdata.m_Potdata[potDlg.m_nNum4].lon = potDlg.m_dLon4;
			potdata.m_Potdata[potDlg.m_nNum4].lat = potDlg.m_dLat4;
			potdata.m_Potdata[potDlg.m_nNum4].alt = potDlg.m_dAlt4;
			potdata.m_Potdata[potDlg.m_nNum4].spd = potDlg.m_nSpd4;
			potdata.m_Potdata[potDlg.m_nNum4].raid = potDlg.m_nRaid4;
			potdata.m_Potdata[potDlg.m_nNum4].time = potDlg.m_nTime4;
			potdata.m_Potdata[potDlg.m_nNum4].linetype = potDlg.m_nLinetype4;
			potdata.m_Potdata[potDlg.m_nNum4].photo = potDlg.m_bPhoto4;
			potdata.m_Potdata[potDlg.m_nNum4].serv1 = potDlg.m_bServ14;
			potdata.m_Potdata[potDlg.m_nNum4].serv2 = potDlg.m_bServ24;
			potdata.m_Potdata[potDlg.m_nNum4].serv3 = potDlg.m_bServ34;
			potdata.m_Potdata[potDlg.m_nNum4].toground = potDlg.m_bToGround4;
			potdata.m_Potdata[potDlg.m_nNum4].toline = potDlg.m_bToLine4;
			potdata.m_Potdata[potDlg.m_nNum4].toslide = potDlg.m_bToSlide4;
		}


		if(potdata.m_Potdata[potDlg.m_nNum5].num>0)
		{
			potdata.m_Potdata[potDlg.m_nNum5].num = potDlg.m_nNum5;
			potdata.m_Potdata[potDlg.m_nNum5].lon = potDlg.m_dLon5;
			potdata.m_Potdata[potDlg.m_nNum5].lat = potDlg.m_dLat5;
			potdata.m_Potdata[potDlg.m_nNum5].alt = potDlg.m_dAlt5;
			potdata.m_Potdata[potDlg.m_nNum5].spd = potDlg.m_nSpd5;
			potdata.m_Potdata[potDlg.m_nNum5].raid = potDlg.m_nRaid5;
			potdata.m_Potdata[potDlg.m_nNum5].time = potDlg.m_nTime5;
			potdata.m_Potdata[potDlg.m_nNum5].linetype = potDlg.m_nLinetype5;
			potdata.m_Potdata[potDlg.m_nNum5].photo = potDlg.m_bPhoto5;
			potdata.m_Potdata[potDlg.m_nNum5].serv1 = potDlg.m_bServ15;
			potdata.m_Potdata[potDlg.m_nNum5].serv2 = potDlg.m_bServ25;
			potdata.m_Potdata[potDlg.m_nNum5].serv3 = potDlg.m_bServ35;
			potdata.m_Potdata[potDlg.m_nNum5].toground = potDlg.m_bToGround5;
			potdata.m_Potdata[potDlg.m_nNum5].toline = potDlg.m_bToLine5;
			potdata.m_Potdata[potDlg.m_nNum5].toslide = potDlg.m_bToSlide5;
		}


		if(potdata.m_Potdata[potDlg.m_nNum6].num>0)
		{
			potdata.m_Potdata[potDlg.m_nNum6].num = potDlg.m_nNum6;
			potdata.m_Potdata[potDlg.m_nNum6].lon = potDlg.m_dLon6;
			potdata.m_Potdata[potDlg.m_nNum6].lat = potDlg.m_dLat6;
			potdata.m_Potdata[potDlg.m_nNum6].alt = potDlg.m_dAlt6;
			potdata.m_Potdata[potDlg.m_nNum6].spd = potDlg.m_nSpd6;
			potdata.m_Potdata[potDlg.m_nNum6].raid = potDlg.m_nRaid6;
			potdata.m_Potdata[potDlg.m_nNum6].time = potDlg.m_nTime6;
			potdata.m_Potdata[potDlg.m_nNum6].linetype = potDlg.m_nLinetype6;
			potdata.m_Potdata[potDlg.m_nNum6].photo = potDlg.m_bPhoto6;
			potdata.m_Potdata[potDlg.m_nNum6].serv1 = potDlg.m_bServ16;
			potdata.m_Potdata[potDlg.m_nNum6].serv2 = potDlg.m_bServ26;
			potdata.m_Potdata[potDlg.m_nNum6].serv3 = potDlg.m_bServ36;
			potdata.m_Potdata[potDlg.m_nNum6].toground = potDlg.m_bToGround6;
			potdata.m_Potdata[potDlg.m_nNum6].toline = potDlg.m_bToLine6;
			potdata.m_Potdata[potDlg.m_nNum6].toslide = potDlg.m_bToSlide6;
		}

		m_model_Potdata.alt = potDlg.m_nMode_Alt;
		m_model_Potdata.linetype = potDlg.m_nMode_Linetype;
		m_model_Potdata.photo = potDlg.m_nCheck_Photo;
		m_model_Potdata.raid = potDlg.m_nMode_Raid;
		m_model_Potdata.serv1 = potDlg.m_nCheck_Serv1;
		m_model_Potdata.serv2 = potDlg.m_nCheck_Serv2;
		m_model_Potdata.serv3 = potDlg.m_nCheck_Serv3;
		m_model_Potdata.spd = potDlg.m_nMode_Spd;
		m_model_Potdata.time = potDlg.m_nMode_Time;
		m_model_Potdata.toground = potDlg.m_nCheck_Toground;
		m_model_Potdata.toline = potDlg.m_nCheck_Toline;
		m_model_Potdata.toslide = potDlg.m_nCheck_Toslide;

		OnUpdatePointFeatures();
	
	}
	delete potDlg;
	
}

void CTF1DDlg::GetStrReceived(CString str)
{
	if(str == "10")//0X0A判断，是则字头标志为TRUE
	{
		m_bHead = TRUE;
	}
	if(m_bHead == TRUE)//字头标志为真，则检查下一个字符是否为0xFF，是则为帧开始，标志恢复FALSE
	{
		if(str == "255")
		{
			GiveStrZero(m_nstrnum);			
			m_bHead = FALSE;
			m_nstrnum = 0;
		}
		else if(str =="10")
		{
			m_bHead = TRUE;
		}
		else
		{
			m_bHead = FALSE;
		}
	}
	
	OnOperateStr(str,m_nstrnum);
	m_sStrReceived +=str;
	if(m_nstrnum>90)
		m_nstrnum = 90;
	m_pBuff[m_nstrnum] = atoi(str);
	m_nstrnum++;
}

void CTF1DDlg::GiveStrZero(int num)
{
	if(m_bFilesaveFlag == TRUE)
		OnFileSaveRecord(num);
	m_sStrReceived = "";
	m_bTime2Flag = FALSE;//////////////////定时器2标志
}

void CTF1DDlg::OnOperateStr(CString str, int num)
{
	CString strtemp;
	int numtemp;
	strtemp = str;
	numtemp = num;

	if(numtemp ==1)
	{
		m_nCommandType = atoi(strtemp);
		m_nTotalNum++;///接收语句的总量统计
	}
	switch(m_nCommandType)
	{
	case 20:
		m_cDataStyle.SetWindowText("遥测数据");
		OnYaoceDataOperate(strtemp,numtemp);
		break;
	case 18:
		m_cDataStyle.SetWindowText("下载航点");
		OnDownpotOperate(strtemp,numtemp);
		break;
	case 46:
		m_cDataStyle.SetWindowText("照片数据");
		OnPhotoDataOperate(strtemp,numtemp);
		break;
	case 47:
		m_cDataStyle.SetWindowText("照片数量");
		OnPhotoNumOperate(strtemp,numtemp);
		break;
	default:
		break;
	}

}
//////////////////////////////////////////////////////
///////          遥测数据处理函数               //////
///////         含校验字节共59字节              //////
///////     其中数据长度2字节，校验1字节        //////
//////////////////////////////////////////////////////
void CTF1DDlg::OnYaoceDataOperate(CString str, int num)
{
	int tempnum;
	CString targettemp;
	switch(num)
	{
	case 2:////数据长度
		tempnum = atoi(str);
		m_Yaoce_Data.check = 20;
		m_Yaoce_Data.check += tempnum;
		m_dNumLength_Yaoce = tempnum*256;
		break;
	case 3:////数据长度
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_dNumLength_Yaoce = m_dNumLength_Yaoce+tempnum;
		break;
	case 4://///////////////控制模式
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nContralmodel = tempnum;
		break;
//////////////////////////////////////////////////////////
///////                GPS信息                       /////
///////                共24字节                      /////
//////////////////////////////////////////////////////////
	case 5://///////////////定位情况
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_nStatus = tempnum;
		break;
	case 6://///////////////定位质量
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_nPod = tempnum;
		break;
	case 7:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_nPod = m_Yaoce_Data.m_GPSdata.m_nPod+tempnum*256;
		m_Yaoce_Data.m_GPSdata.m_nPod = m_Yaoce_Data.m_GPSdata.m_nPod/100;
		break;
	case 8:////////////////有效卫星个数
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_nSatnum = tempnum;
		break;
	case 9://///////////////jing度
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dLon = tempnum;
		break;
	case 10:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dLon = m_Yaoce_Data.m_GPSdata.m_dLon+tempnum*256;
		break;
	case 11:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dLon = m_Yaoce_Data.m_GPSdata.m_dLon+tempnum*256*256;
		break;
	case 12:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dLon = m_Yaoce_Data.m_GPSdata.m_dLon+tempnum*256*256*256;
		m_Yaoce_Data.m_GPSdata.m_dLon = m_Yaoce_Data.m_GPSdata.m_dLon/10000000;
		break;
	case 13:////////////////wei度
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dLat = tempnum;
		break;
	case 14:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dLat = m_Yaoce_Data.m_GPSdata.m_dLat+tempnum*256;
		break;
	case 15:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dLat = m_Yaoce_Data.m_GPSdata.m_dLat+tempnum*256*256;
		break;
	case 16:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dLat = m_Yaoce_Data.m_GPSdata.m_dLat+tempnum*256*256*256;
		m_Yaoce_Data.m_GPSdata.m_dLat = m_Yaoce_Data.m_GPSdata.m_dLat/10000000;
		break;
	case 17://////////////GPS高度
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dGPSalt = tempnum;
		break;
	case 18:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dGPSalt = m_Yaoce_Data.m_GPSdata.m_dGPSalt+tempnum*256;
		break;
	case 19:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dGPSalt = m_Yaoce_Data.m_GPSdata.m_dGPSalt+tempnum*256*256;
		break;
	case 20:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dGPSalt = m_Yaoce_Data.m_GPSdata.m_dGPSalt+tempnum*256*256*256;
		m_Yaoce_Data.m_GPSdata.m_dGPSalt = m_Yaoce_Data.m_GPSdata.m_dGPSalt/1000;
		break;
	case 21://////////GPS速度
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dGPSspd = tempnum;
		break;
	case 22:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dGPSspd = m_Yaoce_Data.m_GPSdata.m_dGPSspd+tempnum*256;
		break;
	case 23:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dGPSspd = m_Yaoce_Data.m_GPSdata.m_dGPSspd+tempnum*256*256;
		break;
	case 24:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dGPSspd = m_Yaoce_Data.m_GPSdata.m_dGPSspd+tempnum*256*256*256;
		m_Yaoce_Data.m_GPSdata.m_dGPSspd = m_Yaoce_Data.m_GPSdata.m_dGPSspd/100*3.6;
		break;
	case 25:///////////航向
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dHangxiang = tempnum;
		break;
	case 26:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dHangxiang = m_Yaoce_Data.m_GPSdata.m_dHangxiang+tempnum*256;
		break;
	case 27:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dHangxiang = m_Yaoce_Data.m_GPSdata.m_dHangxiang+tempnum*256*256;
		break;
	case 28:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_GPSdata.m_dHangxiang = m_Yaoce_Data.m_GPSdata.m_dHangxiang+tempnum*256*256*256;
		m_Yaoce_Data.m_GPSdata.m_dHangxiang = m_Yaoce_Data.m_GPSdata.m_dHangxiang/100000;
		break;
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
	case 29:///////////////滚转角
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_dRoll = tempnum*256;
		break;
	case 30:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_dRoll = m_Yaoce_Data.m_dRoll+tempnum;
		if(m_Yaoce_Data.m_dRoll>3600)
			m_Yaoce_Data.m_dRoll = m_Yaoce_Data.m_dRoll-65535;
		m_Yaoce_Data.m_dRoll = m_Yaoce_Data.m_dRoll/10;
	
		break;
	case 31://///////////俯仰角
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_dPitch = tempnum*256;
		break;
	case 32:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_dPitch = m_Yaoce_Data.m_dPitch+tempnum;
		if(m_Yaoce_Data.m_dPitch>3600)
			m_Yaoce_Data.m_dPitch = m_Yaoce_Data.m_dPitch-65535;
		m_Yaoce_Data.m_dPitch = m_Yaoce_Data.m_dPitch/10;
		
		break;
	case 33://///////////目标航点
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nTargetWP = tempnum;
		m_nPoint_Target = tempnum;
		
		targettemp.Format("%d",m_nPoint_Target);
		m_cPoint_Target.SetWindowText(targettemp);
		break;
	case 34://////////////发动机转速
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nRPM = tempnum*60;
		break;
	case 35://///////////空速
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nAirspd = tempnum*256;
		break;
	case 36:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nAirspd = m_Yaoce_Data.m_nAirspd+tempnum;
		m_Yaoce_Data.m_nAirspd = m_Yaoce_Data.m_nAirspd/10*3.6;
		break;
	case 37://////////////设定空速
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nDesired_Airspd = tempnum*3.6;
		break;
	case 38://///////////气压高度
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nAiralt = tempnum*256;
		break;
	case 39:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nAiralt = m_Yaoce_Data.m_nAiralt+tempnum;
		if(m_Yaoce_Data.m_nAiralt>=0x8000)
			m_Yaoce_Data.m_nAiralt = m_Yaoce_Data.m_nAiralt-65536;
		break;
	case 40://///////////设定高度
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nDesired_Airalt = tempnum*256;
		break;
	case 41:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nDesired_Airalt = m_Yaoce_Data.m_nDesired_Airalt+tempnum;
		break;
	case 42://///////////目标航向
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nDesired_Heading = tempnum*256;
		break;
	case 43:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nDesired_Heading = m_Yaoce_Data.m_nDesired_Heading+tempnum;
		m_Yaoce_Data.m_nDesired_Heading = m_Yaoce_Data.m_nDesired_Heading/10;
		break;
	case 44://////////////当前飞行状况
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nCurrentstatus = tempnum;
		break;
	case 45://////////////偏航距
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nCte = tempnum*256;
		break;
	case 46:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nCte = m_Yaoce_Data.m_nCte+tempnum;
		if(m_Yaoce_Data.m_nCte>=0x8000)
			m_Yaoce_Data.m_nCte = m_Yaoce_Data.m_nCte-65536;
		break;
	case 47://////////////制式飞行剩余时间
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nPatterntime = tempnum;
		break;
	case 48:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nPatterntime = m_Yaoce_Data.m_nPatterntime+tempnum*256;
		break;
	case 49://////////////飞行状况
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nStatus1 = tempnum;
		break;
	case 50://////////////第二发动机转速
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nStatus2 = tempnum;
		break;
///////////////////////////////////////////////
/////         以下为3秒1次电压数据        /////
///////////////////////////////////////////////
	case 51:///////////////气压值
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_fAirPress = tempnum*256;
		break;
	case 52:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_fAirPress = (m_Yaoce_Data.m_fAirPress+tempnum)/10;
		break;
	case 53:///////////////舵机电压
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nDianya_Duoji = tempnum;
		break;
	case 54:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nDianya_Duoji = m_Yaoce_Data.m_nDianya_Duoji+tempnum*256;
		m_Yaoce_Data.m_nDianya_Duoji = m_Yaoce_Data.m_nDianya_Duoji/1024*5*21.2/15;
		break;
	case 55:///////////////飞控电压
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nDianya_UAV = tempnum;
		break;
	case 56:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_nDianya_UAV = m_Yaoce_Data.m_nDianya_UAV+tempnum*256;
		m_Yaoce_Data.m_nDianya_UAV = m_Yaoce_Data.m_nDianya_UAV/1024*5*23.2/8.2;
		break;
	case 57:///////////////温度
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_fTempr = tempnum;
		break;
	case 58:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_fTempr = m_Yaoce_Data.m_fTempr*256+tempnum;
		m_Yaoce_Data.m_fTempr = m_Yaoce_Data.m_fTempr/10;

//		m_Yaoce_Data.m_fTempr = (m_Yaoce_Data.m_fTempr/1024*5-2.5)/0.0084+27;
//		m_Yaoce_Data.m_fTempr = log(6.2*m_Yaoce_Data.m_fTempr/(1024-m_Yaoce_Data.m_fTempr)*1000);
//		m_Yaoce_Data.m_fTempr = 0.0003*pow(m_Yaoce_Data.m_fTempr,5)-0.0231*pow(m_Yaoce_Data.m_fTempr,4)+0.4433*pow(m_Yaoce_Data.m_fTempr,3)-1.3891*pow(m_Yaoce_Data.m_fTempr,2)-50.604*m_Yaoce_Data.m_fTempr+389.23;
		break;
	case 59:///////////////接收机信号强度（保留）
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		break;
	case 60:////////////////GPS时间
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_dGPSTime = tempnum;
		break;
	case 61:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_dGPSTime = m_Yaoce_Data.m_dGPSTime+tempnum*256;
		break;
	case 62:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_dGPSTime = m_Yaoce_Data.m_dGPSTime+tempnum*256*256;
		break;
	case 63:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		m_Yaoce_Data.m_dGPSTime = m_Yaoce_Data.m_dGPSTime+tempnum*256*256*256;
//		m_Yaoce_Data.m_dGPSTime = m_Yaoce_Data.m_GPSdata.m_dLat/10000000;
		break;
	case 64:///////////////CH1
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
//		m_Yaoce_Data.m_fTempr = tempnum;
		break;
	case 65:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		break;
	case 66:///////////////CH2
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
//		m_Yaoce_Data.m_fTempr = tempnum;
		break;
	case 67:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		break;
	case 68:///////////////CH3
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
//		m_Yaoce_Data.m_fTempr = tempnum;
		break;
	case 69:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		break;
	case 70:///////////////CH4
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
//		m_Yaoce_Data.m_fTempr = tempnum;
		break;
	case 71:
		tempnum = atoi(str);
		m_Yaoce_Data.check += tempnum;
		break;
	case 72:///////////////校验
		tempnum = atoi(str);
		m_Yaoce_Data.check = m_Yaoce_Data.check%256;
		if(m_Yaoce_Data.check == tempnum)
			{
				OnStaticUpdate();
				OnDrawPoint(m_Yaoce_Data.m_GPSdata.m_dLon,m_Yaoce_Data.m_GPSdata.m_dLat,m_Yaoce_Data.m_GPSdata.m_dHangxiang);
				OnUpdateMeter();
				tongxunled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDOFF));
				tongxun.SetWindowText("通讯:");
				if(m_bFilesaveFlag == TRUE)
					OnFileSaveText();
			}else
			{
				tongxunled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWAR));
				tongxun.SetWindowText("通讯:异常");
				
			}
		
		break;
	default:
		break;

	}

}
///开启遥测数据接收,同时开启定时器，创建记录文件
void CTF1DDlg::OnDataget() 
{
	// TODO: Add your command handler code here
	m_bFilesaveFlag = TRUE;//////////设置文件保存标志为真

	int date,hour,minuter,month,second;

	CTime time;
	CString strfile;
	CString strtemp;
	time = CTime::GetCurrentTime();
	month = time.GetMonth();
	date = time.GetDay();
	hour = time.GetHour();
	minuter = time.GetMinute();
	second = time.GetSecond();
	strtemp.Format("%d月%d日%d点%d分%d秒",month,date,hour,minuter,second);
	strfile.Format("%s\\record\\record%s.rec",str_parth,strtemp);
	m_fp_Record.Open(strfile,CFile::modeCreate|CFile::modeWrite);
	strfile.Format("%s\\record\\record%s.txt",str_parth,strtemp);
	m_fp_Text.Open(strfile,CFile::modeCreate|CFile::modeWrite);

	bReceive = TRUE;////接收标志置真值
	OpenPort();
	SetTimer(1,1000,NULL);//////打开统计定时器
	
}

void CTF1DDlg::OnStaticUpdate()
{
	CString tempstr;
	CString tempstr2;
///指令应答
	yingdaled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDOFF));
	yingda.SetWindowText("应答:");
	if(m_Yaoce_Data.m_nContralmodel>=16)
	{
		yingdaled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
		yingda.SetWindowText("应答:已应答!!!");
	}
	
	tongxunled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	tongxun.SetWindowText("通讯:接收");
	
///控制模式
	if(m_Yaoce_Data.m_nContralmodel ==0)
	{
		moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
		moshi.SetWindowText("模式:UAV");
	}else if(m_Yaoce_Data.m_nContralmodel ==1)
	{
		moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWAR));
		moshi.SetWindowText("模式:RC");
	}else if(m_Yaoce_Data.m_nContralmodel ==2)
	{
		moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWAR));
		moshi.SetWindowText("模式:RPV");
	}else if(m_Yaoce_Data.m_nContralmodel ==3)
	{
		moshiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWAR));
		moshi.SetWindowText("模式:CPV");
	}
//GPS定位状况
	if(m_Yaoce_Data.m_GPSdata.m_nStatus ==0)
	{
		GPSled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWAR));
		GPS.SetWindowText("GPS:NO!");
	}else if(m_Yaoce_Data.m_GPSdata.m_nStatus ==1)
	{
		GPSled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWAR));
		GPS.SetWindowText("GPS:2D");
	}else
	{
		GPSled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
		GPS.SetWindowText("GPS:3D");
	}
//////卫星数
	tempstr.Format("%d",m_Yaoce_Data.m_GPSdata.m_nSatnum);
	tempstr2 = "卫星:";
	tempstr2+=tempstr;
	if(m_Yaoce_Data.m_GPSdata.m_nSatnum>=3)
		weixingled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	else
		weixingled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWAR));
	weixing.SetWindowText(tempstr2);
//////总电压	
	tempstr.Format("%2.3lf",m_Yaoce_Data.m_nDianya_UAV);
	tempstr2 = "总电压:";
	tempstr2+=tempstr;
	if((m_Yaoce_Data.m_nDianya_UAV>m_Safe_data.m_nUAVV_Min)&&(m_Yaoce_Data.m_nDianya_UAV<m_Safe_data.m_nUAVV_Max))
		dianya_zongled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	else
		dianya_zongled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWAR));
	dianya_zong.SetWindowText(tempstr2);
	
//////舵机电压
	tempstr.Format("%2.3lf",m_Yaoce_Data.m_nDianya_Duoji);
	tempstr2 = "舵机电压:";
	tempstr2+=tempstr;
	if((m_Yaoce_Data.m_nDianya_Duoji>m_Safe_data.m_nServV_Min)&&(m_Yaoce_Data.m_nDianya_Duoji<m_Safe_data.m_nServV_Max))
		dianya_duojiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	else
		dianya_duojiled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWAR));
	dianya_duoji.SetWindowText(tempstr2);
////////////温度	
	tempstr.Format("%2.3lf",m_Yaoce_Data.m_fTempr);
	tempstr2 = "温度:";
	tempstr2+=tempstr;	
	wenduled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	wendu.SetWindowText(tempstr2);
////////////气压	
	tempstr.Format("%5.2lf",m_Yaoce_Data.m_fAirPress);
	tempstr2 = "气压:";
	tempstr2+=tempstr;	
	qiyaled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	qiya.SetWindowText(tempstr2);
/////////////GPS时间
//	tempstr.Format("%2.3lf",m_Yaoce_Data.m_nWendu_Dianzu);
//	tempstr2 = "主板温度:";
//	tempstr2+=tempstr;	
	int day,hour,minter,second;
	day = (int)m_Yaoce_Data.m_dGPSTime/1000/3600/24;
	hour = (int)((m_Yaoce_Data.m_dGPSTime/1000/3600/24-day)*24);
	minter = (int)(((m_Yaoce_Data.m_dGPSTime/1000/3600/24-day)*24-hour)*60);
	second = (int)((((m_Yaoce_Data.m_dGPSTime/1000/3600/24-day)*24-hour)*60-minter)*60);
	tempstr.Format("星期%d %2d:%2d:%2d",day,hour,minter,second);
	tempstr2 = "GPS时间:";
	tempstr2+=tempstr;
//	GPSTimeled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	GPSTime.SetWindowText(tempstr2);

//偏航
	tempstr.Format("%dm",m_Yaoce_Data.m_nCte);
	pianhang.SetWindowText(tempstr);
//制式时间
	tempstr.Format("%d",m_Yaoce_Data.m_nPatterntime);
	zhishishijian.SetWindowText(tempstr);
//当前航点
	tempstr.Format("%lf,%lf",m_Yaoce_Data.m_GPSdata.m_dLon,m_Yaoce_Data.m_GPSdata.m_dLat);
	currentpoint.SetWindowText(tempstr);
//距目标点
	double d = m_cMap.Distance(m_Yaoce_Data.m_GPSdata.m_dLon,m_Yaoce_Data.m_GPSdata.m_dLat, potdata.m_Potdata[m_Yaoce_Data.m_nTargetWP].lon, potdata.m_Potdata[m_Yaoce_Data.m_nTargetWP].lat)*1609/1000;
	tempstr.Format("%5.3lfkm",d);
	distance_currentpoint.SetWindowText(tempstr);
//距起飞点
	d = m_cMap.Distance(m_Yaoce_Data.m_GPSdata.m_dLon,m_Yaoce_Data.m_GPSdata.m_dLat, potdata.m_Potdata[1].lon, potdata.m_Potdata[1].lat)*1609/1000;
	tempstr.Format("%5.3lfkm",d);
	distance_zeropoint.SetWindowText(tempstr);
//剩余航点
	int num = m_dFtrsNum-m_Yaoce_Data.m_nTargetWP;
	tempstr.Format("%d",num);
	shengdian.SetWindowText(tempstr);

	if(m_Yaoce_Data.m_nStatus1 == 1)
	{
		m_cClosereceive.SetWindowText("打开接收机");
		receiverled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWAR));
	}else
	{
		m_cClosereceive.SetWindowText("关闭接收机");
		receiverled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
	}


}

void CTF1DDlg::OnSafeset() 
{
	// TODO: Add your command handler code here
	CSafesetDlg safesetDlg;
	safesetDlg.m_nAir_Max = m_Safe_data.m_nAir_Max;
	safesetDlg.m_nAir_Min = m_Safe_data.m_nAir_Min;
	safesetDlg.m_nHigh_Min = m_Safe_data.m_nHigh_Min;
	safesetDlg.m_nPasheng_Max = m_Safe_data.m_nPasheng_Max;
	safesetDlg.m_nPasheng_Min = m_Safe_data.m_nPasheng_Min;
	safesetDlg.m_nServV_Max = m_Safe_data.m_nServV_Max;
	safesetDlg.m_nServV_Min = m_Safe_data.m_nServV_Min;
	safesetDlg.m_nUAVV_Max = m_Safe_data.m_nUAVV_Max;
	safesetDlg.m_nUAVV_Min = m_Safe_data.m_nUAVV_Min;

	if(safesetDlg.DoModal() == IDOK)
	{
		UpdateData(TRUE);
		m_Safe_data.m_nAir_Max = safesetDlg.m_nAir_Max;
		m_Safe_data.m_nAir_Min = safesetDlg.m_nAir_Min;
		m_Safe_data.m_nHigh_Min = safesetDlg.m_nHigh_Min;
		m_Safe_data.m_nPasheng_Max = safesetDlg.m_nPasheng_Max;
		m_Safe_data.m_nPasheng_Min = safesetDlg.m_nPasheng_Min;
		m_Safe_data.m_nServV_Max = safesetDlg.m_nServV_Max;
		m_Safe_data.m_nServV_Min = safesetDlg.m_nServV_Min;
		m_Safe_data.m_nUAVV_Max = safesetDlg.m_nUAVV_Max;
		m_Safe_data.m_nUAVV_Min = safesetDlg.m_nUAVV_Min;
	}
	
}

void CTF1DDlg::OnSafedataInit()
{
	m_Safe_data.m_nAir_Max = 140;
	m_Safe_data.m_nAir_Min = 70;
	m_Safe_data.m_nHigh_Min = 100;
	m_Safe_data.m_nPasheng_Max = 10;
	m_Safe_data.m_nPasheng_Min = -10;
	m_Safe_data.m_nServV_Max = 7;
	m_Safe_data.m_nServV_Min = 4.5;
	m_Safe_data.m_nUAVV_Max = 12;
	m_Safe_data.m_nUAVV_Min = 7.3;

}

void CTF1DDlg::OnMouseMoveMap(short Button, short Shift, float X, float Y) 
{
	// TODO: Add your control notification handler code here
	double x,y;
	CString m_sDistance_temp;
	CString m_sLon_temp;
	CString m_sLat_temp;
	m_cMap.ConvertCoord(&X,&Y,&x,&y,miScreenToMap);
	m_sLon_temp.Format("%lf",x);
	m_sLat_temp.Format("%lf",y);
	mousepoint.SetWindowText(m_sLon_temp+","+m_sLat_temp);
	mousepoint.UpdateData(FALSE);

	if(m_MapToolNum == MYTOOL_DISTANCEON||m_MapToolNum == MYTOOL_POINT_RANGE)
	{
		double angle;
		double temp2;
		double d = m_cMap.Distance(m_lfLon_MouseDown, m_lfLat_MouseDown, x, y)*1.609;

		temp2 = (atan((y-m_lfLat_MouseDown)/(x-m_lfLon_MouseDown)))/3.1415926*180;
		if((x-m_lfLon_MouseDown)>=0&&(y-m_lfLat_MouseDown)>=0)
			angle = 90-temp2;
		else if((x-m_lfLon_MouseDown)>=0&&(y-m_lfLat_MouseDown)<0)
			angle = 90-temp2;
		else 
			angle = 270-temp2;

		m_sDistance_temp.Format("%5.3lfkm,(%3.3lf),总计：%5.3lfkm",d,angle,m_lfDistance_All);
		distancepoints.SetWindowText(m_sDistance_temp);
		distancepoints.UpdateData(FALSE);

	}

}

void CTF1DDlg::OnDistance() 
{
	// TODO: Add your control notification handler code here
	m_cMap.SetCurrentTool(MYTOOL_DISTANCE);
	m_MapToolNum = MYTOOL_DISTANCE;
	m_lfDistance_All = 0;
	
}

void CTF1DDlg::OnPoints() 
{
	// TODO: Add your control notification handler code here
//	m_cMap.SetCurrentTool(miAddPolylineTool);
	if(m_sLayerName_Points != "航线层")
	{
		AfxMessageBox("请首先建立新的航点图层或者打开已有图层!");
		m_cCheckLine.SetCheck(0);
		return;
	}
	m_MapToolNum = MYTOOL_POINT;

	m_Flag_Point = FALSE;//////插入航点为非
	m_cMap.SetCurrentTool(MYTOOL_POINT);


}
/*
void CTF1DDlg::OnPointToolUsedMap(short ToolNum, long Flags, LPDISPATCH Points, BOOL bShift, BOOL bCtrl, BOOL FAR* EnableDefault)
{
	if (ToolNum == MYTOOL_POINT)
	{
		try {
		
		//	double dDistanceTot = 0.0;
		//	double d = m_cMap.Distance(pt1.GetX(), pt1.GetY(), pt2.GetX(), pt2.GetY())*1.609;
		//		dDistanceTot += d;
		//	
		//	CString str;
		//	str.Format("%fkm", dDistanceTot);
		//	m_nNumDis = str;
			AfxMessageBox("1");
		}
		catch (COleDispatchException *e) {
			e->ReportError();
			e->Delete();
		}
		catch (COleException *e) {
			e->ReportError();
			e->Delete();
		}
	}
}
*/
/////////////////////////////////////////////////
//测距功能实现，计算测距结果，标定航点
/////////////////////////////////////////////////
void CTF1DDlg::OnPolyToolUsedMap(short ToolNum, long Flags, LPDISPATCH Points, BOOL bShift, BOOL bCtrl, BOOL FAR* EnableDefault) 
{
	
	if (ToolNum == MYTOOL_DISTANCE)
	{
		try {
		
		//	double dDistanceTot = 0.0;
		//	double d = m_cMap.Distance(pt1.GetX(), pt1.GetY(), pt2.GetX(), pt2.GetY())*1.609;
		//		dDistanceTot += d;
		//	
		//	CString str;
		//	str.Format("%fkm", dDistanceTot);
		//	m_nNumDis = str;
		//	AfxMessageBox("1");
		}
		catch (COleDispatchException *e) {
			e->ReportError();
			e->Delete();
		}
		catch (COleException *e) {
			e->ReportError();
			e->Delete();
		}
	}
	if (ToolNum == MYTOOL_POINT)
	{
		if(m_MapToolNum == MYTOOL_POINT_RANGE)
		{
			m_dRange_Num++;
			if(m_dRange_Num == 1)
			{
				m_Range1_Lat = m_lfLat_MouseDown;
				m_Range1_Lon = m_lfLon_MouseDown;
			}else if(m_dRange_Num == 2)
			{
				CRangePod rangeDlg;
				double x,y;
				rangeDlg.m_First_Lat=m_Range1_Lat;
				rangeDlg.m_First_Lon=m_Range1_Lon;
				rangeDlg.m_Second_Lat=m_lfLat_MouseDown;
				rangeDlg.m_Second_Lon=m_lfLon_MouseDown;
				rangeDlg.m_lfPointDis = 1.609*m_cMap.Distance(m_lfLon_MouseDown,m_lfLat_MouseDown,m_Range1_Lon, m_Range1_Lat);

				if(rangeDlg.DoModal() == IDOK)
				{
					UpdateData(FALSE);
					double m_Dis_In = (double)rangeDlg.m_In_Dis/1000;
					int m_linenum = rangeDlg.m_Linenum;
	
					double dis = rangeDlg.m_lfPointDis;
					double tempx = m_lfLon_MouseDown-m_Range1_Lon;
					double tempy = m_lfLat_MouseDown-m_Range1_Lat;
					double dis_lon = 1.609*m_cMap.Distance(123,0,122,0);
					double dis_lat = 1.609*m_cMap.Distance(123,41,123,42);

					double tempxnext,tempynext;
			//		tempxnext = (m_Dis_In/dis*tempy*cos(m_lfLat_MouseDown));
			//		tempynext = (m_Dis_In/dis*tempx/cos(m_lfLat_MouseDown));
					tempxnext = dis_lat*tempy*m_Dis_In/dis/dis_lon/cos(m_lfLat_MouseDown/180*3.1415926);
					tempynext = dis_lon*tempx*m_Dis_In/dis/dis_lat*cos(m_lfLat_MouseDown/180*3.1415926);

			//		tempxnext = tempxnext/cos(m_lfLat_MouseDown);

					for(int i=0;i<m_linenum;i++)
					{
						if(i%2 != 0)
						{
						x = m_lfLon_MouseDown+i*tempxnext;
						y = m_lfLat_MouseDown-i*tempynext;
						OnRangePointsToMap(x,y);
						x = m_Range1_Lon+i*tempxnext;
						y = m_Range1_Lat-i*tempynext;
						OnRangePointsToMap(x,y);
						}else
						{
						x = m_Range1_Lon+i*tempxnext;
						y = m_Range1_Lat-i*tempynext;
						OnRangePointsToMap(x,y);
						x = m_lfLon_MouseDown+i*tempxnext;
						y = m_lfLat_MouseDown-i*tempynext;
						OnRangePointsToMap(x,y);
						}
					}
				}

			}else{
			}
		}else
		{
			if(m_Flag_Point == FALSE)
			{
				OnPointToMap();//标定航点
			}else
			{
				OnInsertPointToMap();//插入航点
			}
		}
	}
	
}

void CTF1DDlg::OnNewLayer(CString directer, CString name)
{
//	LPDISPATCH pDispatch;
	CString name_temp;
	CString directer_temp;
	CMapXFields fields;
	CMapXLayerInfo layerinfo;
	CMapXLayer layer;
	CMapXLayers layers;

///////////////////////////////////////////////
////         判断并关闭上一航线图层        ////
///////////////////////////////////////////////
//	OnCreateOtherLayers();
	if(m_sLayerName_Points == "航线层")
	{
		m_cMap.GetLayers().Remove("航线层");
		m_pts.RemoveAll();                   //////航点记录清楚
		m_dFtrsNum = 0;                      //////图元个数清除
	}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
/////                 建立新图层                    ////
////////////////////////////////////////////////////////
	int num_temp,num_temp2;
	num_temp = name.GetLength();
	num_temp2 = directer.GetLength();
	if(num_temp>4)
		name_temp = name.Right(4);
	if(name_temp ==".tab"||name_temp==".TAB")
	{
		name_temp = name.Left(num_temp-4);
		directer_temp = directer;
	}
	else {
		name_temp = name;
		directer_temp = directer+".tab";
	}



	m_sLayerName_Points = name_temp;/////纪录图层名称
//	pDispatch = m_cMap.GetLayers().CreateLayer(name_temp,directer_temp);

	try
	{
	if(!fields.CreateDispatch(fields.GetClsid()))
	return ; 
//	long width=30;
//	CString sFdName="First";

//	fields.AddStringField((LPCTSTR)sFdName,width,FALSE);
//	sFdName="Second";
//	fields.AddIntegerField(sFdName,FALSE);
	fields.AddIntegerField("num",FALSE); 
	fields.AddFloatField("alt",FALSE);
	fields.AddFloatField("tas",FALSE);
	fields.AddIntegerField("r",FALSE);
	fields.AddSmallIntField("flag",FALSE);
	fields.AddSmallIntField("time",FALSE);
	fields.AddSmallIntField("task",FALSE);
	VARIANT vField;
	vField.vt=VT_DISPATCH;
	vField.pdispVal=fields.m_lpDispatch;

	if(!layerinfo.CreateDispatch(layerinfo.GetClsid())) 
		return ;  
	layerinfo.SetType(miLayerInfoTypeNewTable);     //新建图层类型
	VARIANT sVt;
	sVt.vt=VT_BSTR;
	sVt.bstrVal=directer_temp.AllocSysString();
	layerinfo.AddParameter("FileSpec",sVt); 
	sVt.bstrVal=name_temp.AllocSysString();
//	layerinfo.AddParameter("Name",COleVariant("航线层"));
	layerinfo.AddParameter("Name",COleVariant("航线层"));
	layerinfo.AddParameter("Fields",vField);
	directer_temp="1";
	sVt.bstrVal=directer_temp.AllocSysString();
	layerinfo.AddParameter("OverwriteFile",sVt); 
  
	layers=m_cMap.GetLayers();
	layer=layers.Add(layerinfo.m_lpDispatch); 
  
	m_sLayerName_Points = layer.GetName();/////纪录图层名称
	m_cMap.GetLayers().Item(m_sLayerName_Points).SetSelectable(TRUE);
	m_cMap.GetLayers().Item(m_sLayerName_Points).SetOverrideStyle(TRUE);
	m_cMap.GetLayers().Item(m_sLayerName_Points).SetEditable(TRUE);

	m_cMap.GetLayers().Item(m_sLayerName_Points).SetAutoLabel(TRUE);///////////自动标注开

//	m_cMap.GetLayers().SetAnimationLayer(layer.m_lpDispatch);
//	m_cMap.GetLayers().SetInsertionLayer(layer.m_lpDispatch);
  
	}
	catch (COleDispatchException *e) 
	{
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e)
	{
		e->ReportError();
		e->Delete();
	}


	VARIANT lyrVt;
	lyrVt.vt = VT_DISPATCH;
	lyrVt.pdispVal = m_cMap.GetLayers().Item(m_sLayerName_Points);

	lyrVt.pdispVal->AddRef();


	m_dataset = m_cMap.GetDatasets().Add(miDataSetLayer,lyrVt);
	m_cMap.GetLayers().Item(m_sLayerName_Points).SetAutoLabel(TRUE);
//	int i = dataset.GetFields().GetCount();


}

void CTF1DDlg::OnOpenLayer(CString directer, CString name)
{
	CString layername;
	CMapXFeatures ftrs;
	CMapXFeature ftr;
	CMapXLayer lay;
 //	file = directer;

///////////////////////////////////////////////
////         判断并关闭上一航线图层        ////
///////////////////////////////////////////////
//	OnCreateOtherLayers();
	if(m_sLayerName_Points == "航线层")
	{
		m_cMap.GetLayers().Remove("航线层");
		m_pts.RemoveAll();
		m_dFtrsNum = 0;
	}
///////////////////////////////////////////////
	lay = m_cMap.GetLayers().Add(directer);
	lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
	lay.GetStyle().GetSymbolFont().SetName("Wingdings");
	lay.GetStyle().SetSymbolCharacter(181);
	lay.GetStyle().SetSymbolFontHalo(TRUE);
	lay.GetStyle().SetSymbolFontColor(0x0e1eff);
	lay.GetLabelProperties().SetPosition(miPositionTR);
	lay.GetLabelProperties().SetOffset(2);
	lay.GetLabelProperties().GetStyle().SetTextFontColor(0xff00ff);
	layername = lay.GetName();
	m_sLayerName_Points = layername;/////纪录图层名称
	m_cMap.GetLayers().Item(layername).SetSelectable(TRUE);
	m_cMap.GetLayers().Item(layername).SetOverrideStyle(TRUE);
	m_cMap.GetLayers().Item(layername).SetEditable(TRUE);

	m_cMap.GetLayers().Item(layername).SetAutoLabel(TRUE);///////////自动标注开

//	m_cMap.GetLayers().SetAnimationLayer(lay.m_lpDispatch);
	m_cMap.GetLayers().SetInsertionLayer(lay.m_lpDispatch);



	VARIANT lyrVt;
	lyrVt.vt = VT_DISPATCH;
	lyrVt.pdispVal = m_cMap.GetLayers().Item(m_sLayerName_Points);

	lyrVt.pdispVal->AddRef();
	m_dataset = m_cMap.GetDatasets().Add(miDataSetLayer,lyrVt);
	m_cMap.GetLayers().Item(m_sLayerName_Points).SetAutoLabel(TRUE);

	m_cMap.SetAutoRedraw(TRUE);
	OnGetLayerPoints();
	m_cMap.SetAutoRedraw(FALSE);
//	m_dataset
}

void CTF1DDlg::OnOpenMap(CString directer, CString name)
{
	m_cMap.SetGeoSet(directer);
	m_cMap.SetTitleText("");
/////////////////////////////////////////////////////////
////////////关闭已有图层的可选择性///////////////////////
	long tempnum;
	tempnum = m_cMap.GetLayers().GetCount();
	for(int i=1;i<=tempnum;i++)
	{
		m_cMap.GetLayers().Item(i).SetSelectable(FALSE);
	}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
OnCreateOtherLayers();
}



void CTF1DDlg::OnCreateOtherLayers()
{
	LPDISPATCH pDispatch;
	CMapXLayer lay;
/////////////////////////////////////////
///            创建航线层              //
/////////////////////////////////////////
	pDispatch = m_cMap.GetLayers().CreateLayer("LineLayer",NULL);

	m_cMap.GetLayers().Item("LineLayer").SetSelectable(TRUE);
	m_cMap.GetLayers().Item("LineLayer").SetOverrideStyle(TRUE);
	m_cMap.GetLayers().Item("LineLayer").SetEditable(TRUE);

//	m_cMap.GetLayers().SetAnimationLayer(pDispatch);/////暂时设定航线层为动态图层
	m_cMap.GetLayers().SetInsertionLayer(pDispatch);

	lay = m_cMap.GetLayers().Item("LineLayer");
	lay.GetStyle().SetLineColor(0x0000ff);
	lay.GetStyle().SetLineStyle(63);
	lay.GetStyle().SetLineWidth(1);

/////////////////////////////////////////
///            创建航迹层              //
/////////////////////////////////////////
	pDispatch = m_cMap.GetLayers().CreateLayer("FlyLayer",NULL);

	m_cMap.GetLayers().Item("FlyLayer").SetSelectable(TRUE);
	m_cMap.GetLayers().Item("FlyLayer").SetOverrideStyle(TRUE);
	m_cMap.GetLayers().Item("FlyLayer").SetEditable(TRUE);

//	m_cMap.GetLayers().SetAnimationLayer(pDispatch);
	m_cMap.GetLayers().SetInsertionLayer(pDispatch);

/////////////////////////////////////////
///            创建飞机层              //
/////////////////////////////////////////
	pDispatch = m_cMap.GetLayers().CreateLayer("UAVPoints",NULL);

	m_cMap.GetLayers().Item("UAVPoints").SetSelectable(TRUE);
	m_cMap.GetLayers().Item("UAVPoints").SetOverrideStyle(TRUE);
	m_cMap.GetLayers().Item("UAVPoints").SetEditable(TRUE);
//	m_cMap.GetLayers().Item("UAVPoints").SetDrawLabelsAfter(FALSE);

	lay = m_cMap.GetLayers().Item("UAVPoints");
	lay.GetStyle().SetLineColor(0xff0000);
	lay.GetStyle().SetLineStyle(1);
	lay.GetStyle().SetLineWidth(3);

	lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
	lay.GetStyle().GetSymbolFont().SetName("Wingdings");
	lay.GetStyle().SetSymbolCharacter(81);
	lay.GetStyle().SetSymbolFontHalo(TRUE);
	lay.GetStyle().SetSymbolFontColor(0x0e1eff);


	m_cMap.GetLayers().SetAnimationLayer(pDispatch);
	m_cMap.GetLayers().SetInsertionLayer(pDispatch);

/////////////////////////////////////////
///        创建下载航点显示层          //
/////////////////////////////////////////
	pDispatch = m_cMap.GetLayers().CreateLayer("DownPoints",NULL);

	m_cMap.GetLayers().Item("DownPoints").SetSelectable(TRUE);
	m_cMap.GetLayers().Item("DownPoints").SetOverrideStyle(TRUE);
	m_cMap.GetLayers().Item("DownPoints").SetEditable(TRUE);

//	m_cMap.GetLayers().SetAnimationLayer(pDispatch);
//	m_cMap.GetLayers().SetInsertionLayer(pDispatch);

}

void CTF1DDlg::OnSomeDataInit()
{

	m_dFtrsNum = 0;////////////图层图元数
	m_strSettings = _T("115200,n,8,1");
	m_nPort = 1;
	bReceive = FALSE;
	m_bHead = FALSE;
	m_nstrnum = 0;
	m_MapToolNum = 0;
	m_sLayerName_Points = "";
	m_bMouseUpOK = FALSE;////////////

	m_model_Potdata.alt = 500;
	m_model_Potdata.lat = 0;
	m_model_Potdata.linetype = 0;
	m_model_Potdata.lon = 0;
	m_model_Potdata.num = 0;
	m_model_Potdata.photo = TRUE;
	m_model_Potdata.raid = 130;
	m_model_Potdata.spd = 25;
	m_model_Potdata.serv1 = FALSE;
	m_model_Potdata.serv2 = FALSE;
	m_model_Potdata.serv3 = FALSE;
	m_model_Potdata.time = 0;
	m_model_Potdata.toground = FALSE;
	m_model_Potdata.toline = TRUE;
	m_model_Potdata.toslide = FALSE;
	


}

void CTF1DDlg::OnInsertpoint() 
{
	// TODO: Add your command handler code here
	CMapXLayer lay;
	CString str;

	lay = m_cMap.GetLayers().Item(m_sLayerName_Points);
	str = lay.GetSelection().Item(1).GetKeyValue();
	m_InsertPoint_Key = atoi(str);///获取插入点号

	m_Flag_Point = TRUE;
	m_MapToolNum = MYTOOL_POINT;

	m_cMap.SetCurrentTool(MYTOOL_POINT);





	
}

void CTF1DDlg::OnLayercontral() 
{
	// TODO: Add your control notification handler code here
	m_cMap.GetLayers().LayersDlg();
}

void CTF1DDlg::OnCheckline() 
{
	// TODO: Add your control notification handler code here
//	m_cCheckLine.UpdateData(FALSE);

	m_cMap.SetAutoRedraw(TRUE);
	CMapXPoint pt;
	pt.CreateDispatch(pt.GetClsid());
	if(m_sLayerName_Points != "航线层")
	{
		AfxMessageBox("请首先建立新的航点图层或者打开已有图层!");
		m_cCheckLine.SetCheck(0);
		return;
	}
	if(m_bCheckLine == FALSE)
	{
		int i = m_cMap.GetLayers().Item("LineLayer").AllFeatures().GetCount();
		int j = m_pts.GetCount();
		if(j == m_dFtrsNum)
		{
			pt.Set(potdata.m_Potdata[1].lon,potdata.m_Potdata[1].lat);
			m_pts.Add(pt,j+1);
		}
		if(j<2)
		{
			AfxMessageBox("请先标定至少2个航点");
			m_cCheckLine.SetCheck(0);
			return;
		}
		if(i == 0)
		{
			CMapXFeature obj,newobj;
  
			if(!newobj.CreateDispatch(newobj.GetClsid()))
			{
				TRACE0("Failed to create Feature object");
				return;
			}
			try{
				newobj.Attach(m_cMap.GetDispatch());
				newobj.SetType(miFeatureTypeLine);
				newobj.SetStyle(m_cMap.GetDefaultStyle()); 
				newobj.GetParts().Add(m_pts);
				obj = m_cMap.GetLayers().Item("LineLayer").AddFeature(newobj);
			} catch (COleDispatchException *e) {
				e->ReportError();
				e->Delete();
				return;
			} catch (COleException *e) {
				e->ReportError();
				e->Delete();
				return;
			}
		} else
		{
			CMapXFeature obj,newobj;
  
			if(!newobj.CreateDispatch(newobj.GetClsid()))
			{
				TRACE0("Failed to create Feature object");
				return;
			}
  
 
		try {
				newobj.Attach(m_cMap.GetDispatch());
				newobj.SetType(miFeatureTypeLine);
				newobj.SetStyle(m_cMap.GetDefaultStyle()); 
   				newobj.GetParts().Add(m_pts);
				obj = m_cMap.GetLayers().Item("LineLayer").AllFeatures().Item(1);
				m_cMap.GetLayers().Item("LineLayer").DeleteFeature(obj);
				obj = m_cMap.GetLayers().Item("LineLayer").AddFeature(newobj);
			} catch (COleDispatchException *e) {
				e->ReportError();
				e->Delete();
				return;
			} catch (COleException *e) {
				e->ReportError();
				e->Delete();
				return;
			}			
			m_cMap.GetLayers().Item("LineLayer").SetVisible(TRUE);
			
		}
	}else
	{
		m_cMap.GetLayers().Item("LineLayer").SetVisible(FALSE);
	}
		m_bCheckLine = !m_bCheckLine;

		int num = m_pts.GetCount();
		double dis = 0;
		CString str;
		for(int x=1;x<num;x++)
		{
			dis += m_cMap.Distance(m_pts.Item(x).GetX(), m_pts.Item(x).GetY(), m_pts.Item(x+1).GetX(), m_pts.Item(x+1).GetY())*1.609;
			if(x == num-1)
			{
				str.Format("%4.3lfkm",dis);
				m_cTotalDis.SetWindowText(str);
			}
		}

	m_cMap.SetAutoRedraw(FALSE);	
  }



void CTF1DDlg::OnCheckmapselectable() 
{
	// TODO: Add your control notification handler code here
	m_bMapSelectable = !m_bMapSelectable;

	if(m_bMapSelectable == TRUE)
	{
/////////////////////////////////////////////////////////
////////////打开已有图层的可选择性///////////////////////
		long tempnum;
		tempnum = m_cMap.GetLayers().GetCount();
		for(int i=1;i<=tempnum;i++)
		{
			m_cMap.GetLayers().Item(i).SetSelectable(TRUE);
		}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
	}else
	{
		long tempnum;
		tempnum = m_cMap.GetLayers().GetCount();
		for(int i=1;i<=tempnum;i++)
		{
			m_cMap.GetLayers().Item(i).SetSelectable(FALSE);
		}
		if(m_sLayerName_Points == "航线层")
			m_cMap.GetLayers().Item(m_sLayerName_Points).SetSelectable(TRUE);
	}
}


void CTF1DDlg::OnKeyDownMap(short FAR* KeyCode, short Shift) 
{
	// TODO: Add your control notification handler code here

	if(m_sLayerName_Points != "航线层")
		return;
	int i = *KeyCode;
	
	if(i == 46)
	{
		VARIANT lyrVt;

		lyrVt.vt = VT_DISPATCH;
		lyrVt.pdispVal = m_cMap.GetLayers().Item(m_sLayerName_Points);
		lyrVt.pdispVal->AddRef();

		m_dataset = m_cMap.GetDatasets().Add(miDataSetLayer,lyrVt);

		CMapXFeatures ftrs;
		CMapX cMap;
		CMapXSelection selections;
		selections = m_cMap.GetLayers().Item(m_sLayerName_Points).GetSelection();
//		m_Delselections = selections;
		int num = selections.GetCount();
		for(i = 1;i<=num;i++)
		{
			CString str;
			str = selections.Item(i).GetKeyValue();
			int value = atoi(str);
			m_dataset.GetRowValues(value).Clone().RemoveAll();
//			m_Row_Values_Remove[i] = value;
//
		}
	}
		
}
void CTF1DDlg::OnKeyUpMap(short FAR* KeyCode, short Shift) 
{
	// TODO: Add your control notification handler code here
//	int num = m_Delselections.GetCount();
	if(m_sLayerName_Points != "航线层")
		return;
	int i = *KeyCode;
	
	if(i == 46)
		OnDeleteFeatures();
	
}
void CTF1DDlg::OnMapDrawMap(short Flag) 
{
	// TODO: Add your control notification handler code here
	if(m_MapToolNum == miSelectTool||m_MapToolNum == miRectSelectTool||m_bMouseUpOK == TRUE)
	{
	
		int num;
		double x,y;
	

		CMapXFeatures ftrs;
		CMapXFeature ftr;

		if(!ftr.CreateDispatch(ftr.GetClsid()))
		{
			TRACE0("Failed to create Feature object");
			return;
		}
	//	CMapX cMap;
	
			CMapXLayer lay;
			CMapXSelection selection;
			CMapXPoint pt;
			if(m_sLayerName_Points == "航线层"&&m_bMouseUpOK==TRUE)
			{
				lay = m_cMap.GetLayers().Item(m_sLayerName_Points);
				selection = lay.GetSelection();
				num = selection.GetCount();
				for(int i = 1;i<=num;i++)
				{
					CString str = selection.Item(i).GetKeyValue();
					selection.Item(i).Update();
					
					pt = selection.Item(i).GetPoint();
					x = pt.GetX();
					y = pt.GetY();
					int j = atoi(str);
					m_pts.Item(j).Set(x,y);
					potdata.m_Potdata[j].lon = x;
					potdata.m_Potdata[j].lat = y;
			//		m_Potdata[j].lon = x;
			//		m_Potdata[j].lat = y;

				}
				
				///////////////////////////////////////
				if(m_bCheckLine == TRUE&&m_bMouseUpOK==TRUE)
				{
					CMapXFeature obj,newobj;
	 
					if(!newobj.CreateDispatch(newobj.GetClsid()))
					{
						TRACE0("Failed to create Feature object");
						return;
					}
  
 
					try {
					newobj.Attach(m_cMap.GetDispatch());
					newobj.SetType(miFeatureTypeLine);
					newobj.SetStyle(m_cMap.GetDefaultStyle()); 
   
					newobj.GetParts().Add(m_pts);

					obj = m_cMap.GetLayers().Item("LineLayer").AllFeatures().Item(1);
					m_cMap.GetLayers().Item("LineLayer").DeleteFeature(obj);
					obj = m_cMap.GetLayers().Item("LineLayer").AddFeature(newobj);

					} catch (COleDispatchException *e) {
					e->ReportError();

					e->Delete();
					return;
					} catch (COleException *e) {
					e->ReportError();
					e->Delete();
					return;
					}	
				}
				///////////////////////////////////////
			}
	
	}
	m_bMouseUpOK = FALSE;
	m_cMap.SetAutoRedraw(FALSE);
}



void CTF1DDlg::OnGetLayerPoints()
{

	CMapXLayer lay;
	CMapXPoint pt;
	int num;
	int c;//获取字节单位
	CString str;
	double value;
	double x,y;
	VARIANT Vt;
	VARIANT lyrVt;

	lyrVt.vt = VT_DISPATCH;
	lyrVt.pdispVal = m_cMap.GetLayers().Item(m_sLayerName_Points);
	lyrVt.pdispVal->AddRef();

	m_dataset = m_cMap.GetDatasets().Add(miDataSetLayer,lyrVt);

	lay = m_cMap.GetLayers().Item(m_sLayerName_Points);

	num = lay.AllFeatures().GetCount();
	int num2 = m_dataset.GetRowCount();
	m_dFtrsNum = num;
//	num = dataset.GetRowCount();

	for(int i=1;i<=num;i++)
	{
		pt = lay.AllFeatures().Item(i).GetPoint();
		x = pt.GetX();
		y = pt.GetY();
		str.Format("%d",i);
		lay.SetKeyField("num");
		lay.AllFeatures().Item(i).SetKeyValue(str);
		potdata.m_Potdata[i].lon = x;
		potdata.m_Potdata[i].lat = y;
	//	m_Potdata[i].lon = x;
	//	m_Potdata[i].lat = y;
		m_pts.Add(pt,i);
		for(int j=1;j<8;j++)
		{
			Vt = m_dataset.GetRowValues(i).Item(j).GetValue();
			value = Vt.date;
			switch(j)
			{
			case 1:
				potdata.m_Potdata[i].num = value;
				break;
			case 2:
				potdata.m_Potdata[i].alt = value;
				break;
			case 3:
				potdata.m_Potdata[i].spd = value;
				break;
			case 4:
				potdata.m_Potdata[i].raid = value;
				break;
			case 5:
				potdata.m_Potdata[i].linetype = (int)value&7;
				c = (int)value&8;
				if(c == 0)
					potdata.m_Potdata[i].toline = FALSE;
				else
					potdata.m_Potdata[i].toline = TRUE;
				c = (int)value&16;
				if(c == 0)
					potdata.m_Potdata[i].toground = FALSE;
				else
					potdata.m_Potdata[i].toground = TRUE;
				c = (int)value&32;
				if(c == 0)
					potdata.m_Potdata[i].toslide = FALSE;
				else
					potdata.m_Potdata[i].toslide = TRUE;
				c = (int)value&64;
				if(c == 0)
					potdata.m_Potdata[i].photo = FALSE;
				else
					potdata.m_Potdata[i].photo = TRUE;
				break;
			case 6:
				potdata.m_Potdata[i].time = value*10;
				break;
			default:
			
				c=(int)value&1;
				if(c == 0)
					potdata.m_Potdata[i].serv1 = FALSE;
				else
					potdata.m_Potdata[i].serv1 = TRUE;
				c=(int)value&2;
				if(c == 0)
					potdata.m_Potdata[i].serv2 = FALSE;
				else
					potdata.m_Potdata[i].serv2 = TRUE;
				c=(int)value&4;
				if(c == 0)
					potdata.m_Potdata[i].serv3 = FALSE;
				else
					potdata.m_Potdata[i].serv3 = TRUE;
				
				break;
			}
		}
	}
}

void CTF1DDlg::OnDeleteFeatures()
{
	VARIANT lyrVt;
	CString str;
	CString str_key;
	CMapXLayer lay;
	CMapXFeature obj;

	lay = m_cMap.GetLayers().Item(m_sLayerName_Points);
	lyrVt.vt = VT_DISPATCH;
	lyrVt.pdispVal = lay;

	lyrVt.pdispVal->AddRef();
	m_dataset = m_cMap.GetDatasets().Add(miDataSetLayer,lyrVt);
	lay.Pack(miPackAll);
		
	int bb = m_dataset.GetRowCount();
	int ftrsnum = lay.AllFeatures().GetCount();
	m_dFtrsNum = ftrsnum;
	for(int i=1;i<=ftrsnum;i++)
	{
		obj = lay.AllFeatures().Item(i);
		m_pts.Item(i).Set(obj.GetCenterX(),obj.GetCenterY());
		str = obj.GetKeyValue();
		int j = atoi(str);
		potdata.m_Potdata[i] = potdata.m_Potdata[j];
		potdata.m_Potdata[i].num = i;

		lay.SetKeyField("num");
		str_key.Format("%d",potdata.m_Potdata[i].num);
		obj.SetKeyValue(str_key);
		obj.Update();
		lay.Refresh();
	}

	int ptsnum = m_pts.GetCount();
	for(int k=ftrsnum+1;k<=ptsnum;k++)
	{
		m_pts.Remove(k);
	}
	m_dataset.Refresh();
 }

void CTF1DDlg::OnPointToMap()
{

	try {
			CMapXPoint pt;
			CMapXFeature fre,obj; 
			CMapXLayer lay;
			double x,y;
			int flag,time,task;
						
			m_dFtrsNum++;

			x = m_lfLon_MouseDown;
			y = m_lfLat_MouseDown;
//			m_cMap.ConvertCoord(&X,&Y,&x,&y,miScreenToMap);
//			CMapXPoints pts;
//			m_pts.CreateDispatch(m_pts.GetClsid());// 作为全局变量，移植时应放入初始化函数内
			lay = m_cMap.GetLayers().Item(m_sLayerName_Points);
			pt.CreateDispatch(pt.GetClsid());
			fre.CreateDispatch(fre.GetClsid());
			fre.Attach(m_cMap.GetDispatch());
			fre.SetType(miFeatureTypeSymbol);

			pt.Set(x,y);
			m_pts.Add(pt,m_dFtrsNum);

			lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
			lay.GetStyle().GetSymbolFont().SetName("Wingdings");
			lay.GetStyle().SetSymbolCharacter(181);
			lay.GetStyle().SetSymbolFontHalo(TRUE);
			lay.GetStyle().SetSymbolFontColor(0x0e1eff);
 //			newlayer.GetStyle().GetSymbolFont().SetSize(fontSize);
//			lay.GetStyle().SetSymbolFontRotation(-angle);
			fre.SetStyle(m_cMap.GetDefaultStyle());
			fre.GetPoint().Set(x,y);
//			fre.SetKeyValue("1");//////////////////////////////////////////////////////////标注添
			lay.GetLabelProperties().SetPosition(miPositionTR);
			lay.GetLabelProperties().SetOffset(2);
			lay.GetLabelProperties().GetStyle().SetTextFontColor(0xff00ff);

			obj = m_cMap.GetLayers().Item(m_sLayerName_Points).AddFeature(fre);

	//		CMapXDataset dataset;
	//		CMapXRowValue rowvalue;
	//		CMapXRowValues rowvalues;
	//		rowvalue.SetValue(
	//		rowvalues.Add(rowvalue);

		
			VARIANT lyrVt;
	//		CMapXRowValues rvs;
	//		CMapXRowValue rv;
			lyrVt.vt = VT_DISPATCH;
			lyrVt.pdispVal = m_cMap.GetLayers().Item(m_sLayerName_Points);

			lyrVt.pdispVal->AddRef();
			m_dataset = m_cMap.GetDatasets().Add(miDataSetLayer,lyrVt);
	//	
		
	//		int i = m_dataset.GetRowCount();
			int i = lay.AllFeatures().GetCount();
			CString str_key;
			


			potdata.m_Potdata[i].lon = x;
			potdata.m_Potdata[i].lat = y;
		//	m_Potdata[i].lon = x;
		//	m_Potdata[i].lat = y;
			potdata.m_Potdata[i].num = i;
			potdata.m_Potdata[i].alt = m_model_Potdata.alt;
			potdata.m_Potdata[i].linetype = m_model_Potdata.linetype;
			potdata.m_Potdata[i].photo = m_model_Potdata.photo;
			potdata.m_Potdata[i].raid = m_model_Potdata.raid;
			potdata.m_Potdata[i].spd = m_model_Potdata.spd;
			potdata.m_Potdata[i].serv1 = m_model_Potdata.serv1;
			potdata.m_Potdata[i].serv2 = m_model_Potdata.serv2;
			potdata.m_Potdata[i].serv3 = m_model_Potdata.serv3;
			potdata.m_Potdata[i].time = m_model_Potdata.time;
			potdata.m_Potdata[i].toground = m_model_Potdata.toground;
			potdata.m_Potdata[i].toline = m_model_Potdata.toline;
			potdata.m_Potdata[i].toslide = m_model_Potdata.toslide;
	
			flag = potdata.m_Potdata[i].linetype+ potdata.m_Potdata[i].toline*8+potdata.m_Potdata[i].toground*16+potdata.m_Potdata[i].toslide*32+potdata.m_Potdata[i].photo*64;
			time = potdata.m_Potdata[i].time/10;
			task = potdata.m_Potdata[i].serv1+potdata.m_Potdata[i].serv2*2+potdata.m_Potdata[i].serv3*4;

			
			lay.SetKeyField("alt");
			str_key.Format("%d",potdata.m_Potdata[i].alt);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("tas");
			str_key.Format("%d",potdata.m_Potdata[i].spd);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("r");
			str_key.Format("%d",potdata.m_Potdata[i].raid);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("flag");
			str_key.Format("%d",flag);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("time");
			str_key.Format("%d",time);
			obj.SetKeyValue(str_key);
			obj.Update();
		

			lay.SetKeyField("task");
			str_key.Format("%d",task);//potdata.m_Potdata[i].toline);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("num");
			str_key.Format("%d",potdata.m_Potdata[i].num);
			obj.SetKeyValue(str_key);
			obj.Update();
		//	m_dataset.Refresh();
		
		}
		catch (COleDispatchException *e) {
			e->ReportError();
			e->Delete();
		}
		catch (COleException *e) {
			e->ReportError();
			e->Delete();
	}
	
}

void CTF1DDlg::OnInsertPointToMap()
{
m_InsertPoint_Key++;


	try {
			CMapXPoint pt;
			CMapXFeature fre,obj,oldobj; 
			CMapXFeatures ftrs;
			CMapXLayer lay;
			CString str;
			double x,y;
			int flag,time,task;
						
			VARIANT lyrVt;
	//		CMapXRowValues rvs;
	//		CMapXRowValue rv;
			lyrVt.vt = VT_DISPATCH;
			lyrVt.pdispVal = m_cMap.GetLayers().Item(m_sLayerName_Points);

			lyrVt.pdispVal->AddRef();
			m_dataset = m_cMap.GetDatasets().Add(miDataSetLayer,lyrVt);



			m_dFtrsNum++;

			x = m_lfLon_MouseDown;
			y = m_lfLat_MouseDown;

			pt.CreateDispatch(pt.GetClsid());
			fre.CreateDispatch(fre.GetClsid());
			
			fre.Attach(m_cMap.GetDispatch());
			fre.SetType(miFeatureTypeSymbol);

			pt.Set(x,y);
			m_pts.Add(pt,m_dFtrsNum);

			lay = m_cMap.GetLayers().Item(m_sLayerName_Points);

			for(int j=m_dFtrsNum;j>m_InsertPoint_Key;j--)
			{
				str.Format("%d",j-1);
				int key = lay.FeatureIDFromFeatureName(str);
				m_pts.Item(j).Set(m_pts.Item(j-1).GetX(),m_pts.Item(j-1).GetY());
				potdata.m_Potdata[j] = potdata.m_Potdata[j-1];
				potdata.m_Potdata[j].num = j;
			//	m_Potdata[j] = m_Potdata[j-1];
			//	m_Potdata[j].num = j;

				lay.SetKeyField("num");
				str.Format("%d",j);
				obj = lay.AllFeatures().Item(key);
				obj.SetKeyValue(str);
				obj.Update();
			}
			m_pts.Item(m_InsertPoint_Key).Set(x,y);


			lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
			lay.GetStyle().GetSymbolFont().SetName("Wingdings");
			lay.GetStyle().SetSymbolCharacter(181);
			lay.GetStyle().SetSymbolFontHalo(TRUE);
			lay.GetStyle().SetSymbolFontColor(0x0e1eff);
 //			newlayer.GetStyle().GetSymbolFont().SetSize(fontSize);
//			lay.GetStyle().SetSymbolFontRotation(-angle);
			fre.SetStyle(m_cMap.GetDefaultStyle());
			fre.GetPoint().Set(x,y);
//			fre.SetKeyValue("1");//////////////////////////////////////////////////////////标注添
			lay.GetLabelProperties().SetPosition(miPositionTR);
			lay.GetLabelProperties().SetOffset(2);
			lay.GetLabelProperties().GetStyle().SetTextFontColor(0xff00ff);

			obj = m_cMap.GetLayers().Item(m_sLayerName_Points).AddFeature(fre);


			CString str_key;

			potdata.m_Potdata[m_InsertPoint_Key].lon = x;
			potdata.m_Potdata[m_InsertPoint_Key].lat = y;
			potdata.m_Potdata[m_InsertPoint_Key].lon = x;
			potdata.m_Potdata[m_InsertPoint_Key].lat = y;
			potdata.m_Potdata[m_InsertPoint_Key].num = m_InsertPoint_Key;
			potdata.m_Potdata[m_InsertPoint_Key].alt = m_model_Potdata.alt;
			potdata.m_Potdata[m_InsertPoint_Key].linetype = m_model_Potdata.linetype;
			potdata.m_Potdata[m_InsertPoint_Key].photo = m_model_Potdata.photo;
			potdata.m_Potdata[m_InsertPoint_Key].raid = m_model_Potdata.raid;
			potdata.m_Potdata[m_InsertPoint_Key].spd = m_model_Potdata.spd;
			potdata.m_Potdata[m_InsertPoint_Key].serv1 = m_model_Potdata.serv1;
			potdata.m_Potdata[m_InsertPoint_Key].serv2 = m_model_Potdata.serv2;
			potdata.m_Potdata[m_InsertPoint_Key].serv3 = m_model_Potdata.serv3;
			potdata.m_Potdata[m_InsertPoint_Key].time = m_model_Potdata.time;
			potdata.m_Potdata[m_InsertPoint_Key].toground = m_model_Potdata.toground;
			potdata.m_Potdata[m_InsertPoint_Key].toline = m_model_Potdata.toline;
			potdata.m_Potdata[m_InsertPoint_Key].toslide = m_model_Potdata.toslide;

			flag = potdata.m_Potdata[m_InsertPoint_Key].linetype+ potdata.m_Potdata[m_InsertPoint_Key].toline*8+potdata.m_Potdata[m_InsertPoint_Key].toground*16+potdata.m_Potdata[m_InsertPoint_Key].toslide*32+potdata.m_Potdata[m_InsertPoint_Key].photo*64;
			time = potdata.m_Potdata[m_InsertPoint_Key].time;
			task = potdata.m_Potdata[m_InsertPoint_Key].serv1+potdata.m_Potdata[m_InsertPoint_Key].serv2*2+potdata.m_Potdata[m_InsertPoint_Key].serv3*4;

			
			lay.SetKeyField("alt");
			str_key.Format("%d",potdata.m_Potdata[m_InsertPoint_Key].alt);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("tas");
			str_key.Format("%d",potdata.m_Potdata[m_InsertPoint_Key].spd);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("r");
			str_key.Format("%d",potdata.m_Potdata[m_InsertPoint_Key].raid);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("flag");
			str_key.Format("%d",flag);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("time");
			str_key.Format("%d",time);
			obj.SetKeyValue(str_key);
			obj.Update();
/*
			int c = 0;
			if(potdata.m_Potdata[m_InsertPoint_Key].toline ==TRUE)
				c = c|64;
			if(potdata.m_Potdata[m_InsertPoint_Key].toground == TRUE)
				c = c|32;
			if(potdata.m_Potdata[m_InsertPoint_Key].toslide == TRUE)
				c = c|16;
			if(potdata.m_Potdata[m_InsertPoint_Key].photo == TRUE)
				c = c|8;
			if(potdata.m_Potdata[m_InsertPoint_Key].serv1 == TRUE)
				c = c|4;
			if(potdata.m_Potdata[m_InsertPoint_Key].serv2 == TRUE)
				c = c|2;
			if(potdata.m_Potdata[m_InsertPoint_Key].serv3 == TRUE)
				c = c|1;

*/			

			lay.SetKeyField("task");
			str_key.Format("%d",task);//m_Potdata[i].toline);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("num");
			str_key.Format("%d",potdata.m_Potdata[m_InsertPoint_Key].num);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.Pack(miPackAll);
			for(j=m_dFtrsNum;j>=1;j--)
			{
				str.Format("%d",j);
				int key = lay.FeatureIDFromFeatureName(str);
				lay.DeleteFeature(key);
			//	ftrs.Add(oldobj);
			}
		    lay.Pack(miPackAll);
			for(j=1;j<=m_dFtrsNum;j++)
			{
			fre.SetStyle(m_cMap.GetDefaultStyle());
			fre.GetPoint().Set(m_pts.Item(j).GetX(),m_pts.Item(j).GetY());
//			fre.SetKeyValue("1");//////////////////////////////////////////////////////////标注添
			lay.GetLabelProperties().SetPosition(miPositionTR);
			lay.GetLabelProperties().SetOffset(2);
			lay.GetLabelProperties().GetStyle().SetTextFontColor(0xff00ff);

			obj = m_cMap.GetLayers().Item(m_sLayerName_Points).AddFeature(fre);

			flag = potdata.m_Potdata[j].linetype+ potdata.m_Potdata[j].toline*8+potdata.m_Potdata[j].toground*16+potdata.m_Potdata[j].toslide*32+potdata.m_Potdata[j].photo*64;
			time = potdata.m_Potdata[j].time;
			task = potdata.m_Potdata[j].serv1+potdata.m_Potdata[j].serv2*2+potdata.m_Potdata[j].serv3*4;


			lay.SetKeyField("alt");
			str_key.Format("%d",potdata.m_Potdata[j].alt);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("tas");
			str_key.Format("%d",potdata.m_Potdata[j].spd);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("r");
			str_key.Format("%d",potdata.m_Potdata[j].raid);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("flag");
			str_key.Format("%d",flag);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("time");
			str_key.Format("%d",time);
			obj.SetKeyValue(str_key);
			obj.Update();
/*
			c = 0;
			if(potdata.m_Potdata[j].toline ==TRUE)
				c = c|64;
			if(potdata.m_Potdata[j].toground == TRUE)
				c = c|32;
			if(potdata.m_Potdata[j].toslide == TRUE)
				c = c|16;
			if(potdata.m_Potdata[j].photo == TRUE)
				c = c|8;
			if(potdata.m_Potdata[j].serv1 == TRUE)
				c = c|4;
			if(potdata.m_Potdata[j].serv2 == TRUE)
				c = c|2;
			if(potdata.m_Potdata[j].serv3 == TRUE)
				c = c|1;

*/			

			lay.SetKeyField("task");
			str_key.Format("%d",task);//potdata.m_Potdata[i].toline);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("num");
			str_key.Format("%d",potdata.m_Potdata[j].num);
			obj.SetKeyValue(str_key);
			obj.Update();

			}

		
		}
		catch (COleDispatchException *e) {
			e->ReportError();
			e->Delete();
		}
		catch (COleException *e) {
			e->ReportError();
			e->Delete();
		}


}

void CTF1DDlg::OnRangepoints() 
{
	// TODO: Add your control notification handler code here
	if(m_sLayerName_Points != "航线层")
	{
		AfxMessageBox("请首先建立新的航点图层或者打开已有图层!");
		m_cCheckLine.SetCheck(0);
		return;
	}
	AfxMessageBox("提示:\n您将进行区域自动航线绘制，\n请选择航线两个端点，并在稍\n后的对话框中进行参数写入");
	m_MapToolNum = MYTOOL_POINT_RANGE;
	m_dRange_Num = 0;

	m_Flag_Point = FALSE;//////插入航点为非
	m_cMap.SetCurrentTool(MYTOOL_POINT);
}

void CTF1DDlg::OnRangePointsToMap(double lon, double lat)
{
	try {
			CMapXPoint pt;
			CMapXFeature fre,obj; 
			CMapXLayer lay;
			double x,y;
			int flag,time,task;
						
			m_dFtrsNum++;

			x = lon;
			y = lat;
//			m_cMap.ConvertCoord(&X,&Y,&x,&y,miScreenToMap);
//			CMapXPoints pts;
//			m_pts.CreateDispatch(m_pts.GetClsid());// 作为全局变量，移植时应放入初始化函数内
			lay = m_cMap.GetLayers().Item(m_sLayerName_Points);
			pt.CreateDispatch(pt.GetClsid());
			fre.CreateDispatch(fre.GetClsid());
			fre.Attach(m_cMap.GetDispatch());
			fre.SetType(miFeatureTypeSymbol);

			pt.Set(x,y);
			m_pts.Add(pt,m_dFtrsNum);

			lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
			lay.GetStyle().GetSymbolFont().SetName("Wingdings");
			lay.GetStyle().SetSymbolCharacter(181);
			lay.GetStyle().SetSymbolFontHalo(TRUE);
			lay.GetStyle().SetSymbolFontColor(0x0e1eff);
 //			newlayer.GetStyle().GetSymbolFont().SetSize(fontSize);
//			lay.GetStyle().SetSymbolFontRotation(-angle);
			fre.SetStyle(m_cMap.GetDefaultStyle());
			fre.GetPoint().Set(x,y);
//			fre.SetKeyValue("1");//////////////////////////////////////////////////////////标注添
			lay.GetLabelProperties().SetPosition(miPositionTR);
			lay.GetLabelProperties().SetOffset(2);
			lay.GetLabelProperties().GetStyle().SetTextFontColor(0xff00ff);

			obj = m_cMap.GetLayers().Item(m_sLayerName_Points).AddFeature(fre);

	//		CMapXDataset dataset;
	//		CMapXRowValue rowvalue;
	//		CMapXRowValues rowvalues;
	//		rowvalue.SetValue(
	//		rowvalues.Add(rowvalue);

		
			VARIANT lyrVt;
	//		CMapXRowValues rvs;
	//		CMapXRowValue rv;
			lyrVt.vt = VT_DISPATCH;
			lyrVt.pdispVal = m_cMap.GetLayers().Item(m_sLayerName_Points);

			lyrVt.pdispVal->AddRef();
			m_dataset = m_cMap.GetDatasets().Add(miDataSetLayer,lyrVt);
	//	
		
	//		int i = m_dataset.GetRowCount();
			int i = lay.AllFeatures().GetCount();
			CString str_key;
			


			potdata.m_Potdata[i].lon = x;
			potdata.m_Potdata[i].lat = y;
			potdata.m_Potdata[i].lon = x;
			potdata.m_Potdata[i].lat = y;
			potdata.m_Potdata[i].num = i;
			potdata.m_Potdata[i].alt = m_model_Potdata.alt;
			potdata.m_Potdata[i].linetype = m_model_Potdata.linetype;
			potdata.m_Potdata[i].photo = m_model_Potdata.photo;
			potdata.m_Potdata[i].raid = m_model_Potdata.raid;
			potdata.m_Potdata[i].spd = m_model_Potdata.spd;
			potdata.m_Potdata[i].serv1 = m_model_Potdata.serv1;
			potdata.m_Potdata[i].serv2 = m_model_Potdata.serv2;
			potdata.m_Potdata[i].serv3 = m_model_Potdata.serv3;
			potdata.m_Potdata[i].time = m_model_Potdata.time;
			potdata.m_Potdata[i].toground = m_model_Potdata.toground;
			potdata.m_Potdata[i].toline = m_model_Potdata.toline;
			potdata.m_Potdata[i].toslide = m_model_Potdata.toslide;

			flag = potdata.m_Potdata[i].linetype+ potdata.m_Potdata[i].toline*8+potdata.m_Potdata[i].toground*16+potdata.m_Potdata[i].toslide*32+potdata.m_Potdata[i].photo*64;
			time = potdata.m_Potdata[i].time/10;
			task = potdata.m_Potdata[i].serv1+potdata.m_Potdata[i].serv2*2+potdata.m_Potdata[i].serv3*4;

			
			
			lay.SetKeyField("alt");
			str_key.Format("%d",potdata.m_Potdata[i].alt);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("tas");
			str_key.Format("%d",potdata.m_Potdata[i].spd);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("r");
			str_key.Format("%d",potdata.m_Potdata[i].raid);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("flag");
			str_key.Format("%d",flag);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("time");
			str_key.Format("%d",time);
			obj.SetKeyValue(str_key);
			obj.Update();
/*
			int c = 0;
			if(potdata.m_Potdata[i].toline ==TRUE)
				c = c|64;
			if(potdata.m_Potdata[i].toground == TRUE)
				c = c|32;
			if(potdata.m_Potdata[i].toslide == TRUE)
				c = c|16;
			if(potdata.m_Potdata[i].photo == TRUE)
				c = c|8;
			if(potdata.m_Potdata[i].serv1 == TRUE)
				c = c|4;
			if(potdata.m_Potdata[i].serv2 == TRUE)
				c = c|2;
			if(potdata.m_Potdata[i].serv3 == TRUE)
				c = c|1;

*/			

			lay.SetKeyField("task");
			str_key.Format("%d",task);//potdata.m_Potdata[i].toline);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("num");
			str_key.Format("%d",potdata.m_Potdata[i].num);
			obj.SetKeyValue(str_key);
			obj.Update();
		//	m_dataset.Refresh();
		
		}
		catch (COleDispatchException *e) {
			e->ReportError();
			e->Delete();
		}
		catch (COleException *e) {
			e->ReportError();
			e->Delete();
	}


}

void CTF1DDlg::OnDrawPoint(double lon, double lat, int angle)
{

	try {
			CMapXPoint pt;
			CMapXPoints ptss;
			CMapXFeature fre,obj,fre2; 
			CMapXLayer lay;
			double x,y;
			
			x = lon;
			y = lat;
						

//			m_cMap.GetLayers().SetAnimationLayer(m_cMap.GetLayers().Item("UAVPoints"));
			
			pt.CreateDispatch(pt.GetClsid());
			ptss.CreateDispatch(ptss.GetClsid());
			fre.CreateDispatch(fre.GetClsid());
			fre.Attach(m_cMap.GetDispatch());
			fre.SetType(miFeatureTypeSymbol);
			fre2.CreateDispatch(fre2.GetClsid());
			fre2.Attach(m_cMap.GetDispatch());
			fre2.SetType(miFeatureTypeLine);

		
			lay = m_cMap.GetLayers().Item("UAVPoints");
			if(IDofFeature!=-1)
				lay.DeleteFeature(IDofFeature);
/////////////////////////////////////////////////////////////////////////飞行点绘制
//			lay = m_cMap.GetLayers().Item("FlyLayer");
			pt.Set(x,y);
			ptss.Add(pt,1);
//			pt.Set(x,y);
			ptss.Add(pt,2);

//			lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
//			lay.GetStyle().GetSymbolFont().SetName("Wingdings");
//			lay.GetStyle().SetSymbolCharacter(159);
//			lay.GetStyle().SetSymbolFontHalo(TRUE);
//			lay.GetStyle().SetSymbolFontColor(0xff1e0e);
//			lay.GetStyle().SetLineColor(0xff0000);
//			lay.GetStyle().SetLineStyle(1);
//			lay.GetStyle().SetLineWidth(5);

			fre2.SetType(miFeatureTypeLine);
			fre2.SetStyle(m_cMap.GetDefaultStyle());
//			fre2.GetPoint().Set(x,y);
			fre2.GetParts().Add(ptss);
//			lay.GetLabelProperties().SetPosition(miPositionTR);
//			lay.GetLabelProperties().SetOffset(2);
//			lay.GetLabelProperties().GetStyle().SetTextFontColor(0xff00ff);
			obj = m_cMap.GetLayers().Item("UAVPoints").AddFeature(fre2);


//////////////////////////////////////////////////////////////////////////飞机绘制	
			pt.Set(x,y);
//			lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
//			lay.GetStyle().GetSymbolFont().SetName("Wingdings");
//			lay.GetStyle().SetSymbolCharacter(81);
//			lay.GetStyle().SetSymbolFontHalo(TRUE);
//			lay.GetStyle().SetSymbolFontColor(0x0e1eff);
			lay.GetStyle().SetSymbolFontRotation(angle-90);
			fre.SetStyle(m_cMap.GetDefaultStyle());
			fre.GetPoint().Set(x,y);
//			fre.SetKeyValue("1");//////////////////////////////////////////////////////////标注添
//			lay.GetLabelProperties().SetPosition(miPositionTR);
//			lay.GetLabelProperties().SetOffset(2);
//			lay.GetLabelProperties().GetStyle().SetTextFontColor(0xff00ff);
			obj = m_cMap.GetLayers().Item("UAVPoints").AddFeature(fre);
			IDofFeature = obj.GetFeatureID();
//			m_cMap.GetLayers().SetAnimationLayer(NULL);



		}
		catch (COleDispatchException *e) {
			e->ReportError();
			e->Delete();
		}
		catch (COleException *e) {
			e->ReportError();
			e->Delete();
	}

}

void CTF1DDlg::OnUpdateMeter()
{
	CString str;

	m_cMeter_Spd.SetHandID(0);
	m_cMeter_Spd.SetHandValue(m_Yaoce_Data.m_nAirspd);
	m_cMeter_Spd.SetHandID(1);
	m_cMeter_Spd.SetHandValue(m_Yaoce_Data.m_GPSdata.m_dGPSspd);
	m_cMeter_Spd.SetHandID(2);
	m_cMeter_Spd.SetHandValue(m_Yaoce_Data.m_nDesired_Airspd);

	m_cMeter_Alt.SetHandID(0);
	m_cMeter_Alt.SetHandValue(m_Yaoce_Data.m_GPSdata.m_dGPSalt);
	m_cMeter_Alt.SetHandID(1);
	m_cMeter_Alt.SetHandValue(m_Yaoce_Data.m_nAiralt);
	m_cMeter_Alt.SetHandID(2);
	m_cMeter_Alt.SetHandValue(m_Yaoce_Data.m_nDesired_Airalt);

	m_cMeter_Rpm.SetHandValue(m_Yaoce_Data.m_nRPM);

	m_cMeter_Head.SetHandID(0);
	m_cMeter_Head.SetHandValue(m_Yaoce_Data.m_GPSdata.m_dHangxiang);
	m_cMeter_Head.SetHandID(1);
	m_cMeter_Head.SetHandValue(m_Yaoce_Data.m_nDesired_Heading);

	m_cAirctrl.SetAHPitch(m_Yaoce_Data.m_dPitch);
	m_cAirctrl.SetAHRoll(m_Yaoce_Data.m_dRoll);
	m_cAirctrl.SetAHHeading(m_Yaoce_Data.m_GPSdata.m_dHangxiang);
	m_cAirctrl.SetAutoRedraw(TRUE);

	str.Format("%3.2lf",m_Yaoce_Data.m_nCurrentstatus);
	m_cHeading.SetWindowText(str);
	str.Format("%3.2lf",m_Yaoce_Data.m_dPitch);
	m_cPitch.SetWindowText(str);
	str.Format("%3.2lf",m_Yaoce_Data.m_dRoll);
	m_cRoll.SetWindowText(str);
}

//void CTF1DDlg::OnButton1() 
//{
//	// TODO: Add your control notification handler code here
//	OnUpdateMeter();
//}

void CTF1DDlg::OnUpdatePointFeatures()
{
	CMapXFeatures ftrs;
	CMapXFeature obj;
	CMapXPoint pt;
	CMapXLayer lay;
	double x,y;
	int flag,time,task;
	CString str_key;

	pt.CreateDispatch(pt.GetClsid());

	VARIANT lyrVt;
	//		CMapXRowValues rvs;
	//		CMapXRowValue rv;
	lyrVt.vt = VT_DISPATCH;
	lyrVt.pdispVal = m_cMap.GetLayers().Item(m_sLayerName_Points);
	lyrVt.pdispVal->AddRef();
	m_dataset = m_cMap.GetDatasets().Add(miDataSetLayer,lyrVt);
	lay = m_cMap.GetLayers().Item(m_sLayerName_Points);

	for(int i=1;i<=m_dFtrsNum;i++)
	{
			x = potdata.m_Potdata[i].lon;
			y = potdata.m_Potdata[i].lat;
			pt.Set(x,y);
			m_pts.Item(i).Set(x,y);
			obj = lay.AllFeatures().Item(i);
			obj.SetPoint(pt.m_lpDispatch);
			obj.Update();

			flag = potdata.m_Potdata[i].linetype+ potdata.m_Potdata[i].toline*8+potdata.m_Potdata[i].toground*16+potdata.m_Potdata[i].toslide*32+potdata.m_Potdata[i].photo*64;
			time = potdata.m_Potdata[i].time/10;
			task = potdata.m_Potdata[i].serv1+potdata.m_Potdata[i].serv2*2+potdata.m_Potdata[i].serv3*4;


			lay.SetKeyField("alt");
			str_key.Format("%d",potdata.m_Potdata[i].alt);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("tas");
			str_key.Format("%d",potdata.m_Potdata[i].spd);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("r");
			str_key.Format("%d",potdata.m_Potdata[i].raid);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("flag");
			str_key.Format("%d",flag);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("time");
			str_key.Format("%d",time);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("task");
			str_key.Format("%d",task);//potdata.m_Potdata[i].toline);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("num");
			str_key.Format("%d",potdata.m_Potdata[i].num);
			obj.SetKeyValue(str_key);
			obj.Update();
	}

}

void CTF1DDlg::OnUploadpoint() 
{
	// TODO: Add your command handler code here

	int pointnum;
	int check=0;
	int size;
	int size_h;
	int size_l;
	int lat1,lat2,lat3,lat4;
	int lon1,lon2,lon3,lon4;
	int alt_h,alt_l;
	int spd,raid_h,raid_l;
	int flag;
	int time;
	int sver;
	CString str;
	CString m_strSendString = "";
	CByteArray hexdata;
	UpdateData(TRUE);

	pointnum = m_dFtrsNum;///航点总数
	size = pointnum*17+1;
	size_h = size/256;
	size_l = size%256;

	if(AfxMessageBox("注意：请确认是否进行上传航点!\n同时请确保串行端口处于数据接收状态",MB_YESNO) == IDNO)
		return;

	m_strSendString.Format("%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x12,size_h,size_l,pointnum);///信息头，至航点数
	check = check+0x12+size_h+size_l+pointnum;

	for(int i = 1;i<=pointnum;i++)
	{
		lon4 = potdata.m_Potdata[i].lon*10000000/256/256/256;
		lon3 = (int)(potdata.m_Potdata[i].lon*10000000/256/256)%256;
		lon2 = (int)(potdata.m_Potdata[i].lon*10000000/256)%256;
		lon1 = (int)(potdata.m_Potdata[i].lon*10000000)%256;
		lat4 = potdata.m_Potdata[i].lat*10000000/256/256/256;
		lat3 = (int)(potdata.m_Potdata[i].lat*10000000/256/256)%256;
		lat2 = (int)(potdata.m_Potdata[i].lat*10000000/256)%256;
		lat1 = (int)(potdata.m_Potdata[i].lat*10000000)%256;
		alt_h = potdata.m_Potdata[i].alt/256;
		alt_l = potdata.m_Potdata[i].alt%256;
		spd = potdata.m_Potdata[i].spd;
		raid_h = potdata.m_Potdata[i].raid/256;
		raid_l = potdata.m_Potdata[i].raid%256;
		flag = potdata.m_Potdata[i].linetype+ potdata.m_Potdata[i].toline*8+potdata.m_Potdata[i].toground*16+potdata.m_Potdata[i].toslide*32+potdata.m_Potdata[i].photo*64;
		time = potdata.m_Potdata[i].time/10;
		sver = potdata.m_Potdata[i].serv1+potdata.m_Potdata[i].serv2*2+potdata.m_Potdata[i].serv3*4;

		str.Format("%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",i,lon1,lon2,lon3,lon4,lat1,lat2,lat3,lat4,alt_l,alt_h,spd,raid_l,raid_h,flag,time,sver);
		m_strSendString +=str;
		check = check+i+lon1+lon2+lon3+lon4+lat1+lat2+lat3+lat4+alt_l+alt_h+spd+raid_l+raid_h+flag+time+sver;
		if(i == pointnum)
		{
			check = check%256;
			str.Format("%02x",check);
			m_strSendString += str;
		}
	}

		String2Hex(m_strSendString ,hexdata);
		m_Com.SetOutput(COleVariant(hexdata));//发送数据
}

void CTF1DDlg::OnDownloadpoints() 
{
	// TODO: Add your control notification handler code here
	int num;
	CDownPoints m_cDownpoints;
	if(m_cDownpoints.DoModal() == IDOK)
	{
		num = m_cDownpoints.m_nPotNum;
		int check;
		CString str;
		CByteArray hexdata;
	


		check = 0;
		check = (check+0x12+1+num)%256;
		CString m_strSendString = "";
		m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x12,0,1,num,check);
		String2Hex(m_strSendString ,hexdata);
		m_Com.SetOutput(COleVariant(hexdata));//发送数据
//		AfxMessageBox("secusse");

	}
	
}

void CTF1DDlg::OnSendtargetpoint() 
{
	// TODO: Add your control notification handler code here
	Beep(300,100);
	int pointnum;
	int check;
	CByteArray hexdata;
	UpdateData(TRUE);
	pointnum = m_Point_Target_Send;

	if(AfxMessageBox("注意：请确认是否进行上传更改目标航点!\n同时请确保串行端口处于数据接收状态",MB_YESNO) == IDNO)
		return;

	check = 0;
	check = (check+0x13+1+pointnum)%256;
		CString m_strSendString = "";
		m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x13,0,1,pointnum,check);
		String2Hex(m_strSendString ,hexdata);
		m_Com.SetOutput(COleVariant(hexdata));//发送数据

}

int CTF1DDlg::String2Hex(CString str, CByteArray &senddata)
{

	int hexdata,lowhexdata;
	int hexdatalen=0;
	int len=str.GetLength();
	
	senddata.SetSize(len/2);
	
	for(int i=0;i<len;)
	{
		char lstr,hstr=str[i];
		if(hstr==' ')
		{
			i++;
			continue;
		}
		i++;
		if(i>=len)
			break;
		lstr=str[i];
		hexdata=ConvertHexChar(hstr);
		lowhexdata=ConvertHexChar(lstr);
		if((hexdata==16)||(lowhexdata==16))
			break;
		else 
			hexdata=hexdata*16+lowhexdata;
		i++;
		senddata[hexdatalen]=(char)hexdata;
		hexdatalen++;
	}

	senddata.SetSize(hexdatalen);
	return hexdatalen;


}

char CTF1DDlg::ConvertHexChar(char ch)
{
	if((ch>='0')&&(ch<='9'))
		return ch-0x30;
	else if((ch>='A')&&(ch<='F'))
		return ch-'A'+10;
	else if((ch>='a')&&(ch<='f'))
		return ch-'a'+10;
	else return (-1);


}

void CTF1DDlg::OnUavset() 
{
	// TODO: Add your command handler code here
	m_Com.SetPortOpen(FALSE);
	m_Com.SetRThreshold(FALSE);
	bReceive = FALSE;
	CUAVSetDlg uavDlg;

	uavDlg.m_nPort = m_nPort;
	uavDlg.m_strSettings = m_strSettings;

	uavDlg.DoModal();

//	uavDlg.OnPhotoset();
//	AfxMessageBox("hello");
	OpenPort();
	bReceive = TRUE;
}

/*void CTF1DDlg::OnPhotoset() 
{
	// TODO: Add your command handler code here

	CPhotoSetDlg photoset;
	int m_time;
	int m_dis;
	if(photoset.DoModal()==IDOK)
	{
	}
	
}

void CTF1DDlg::OnAltset() 
{
	// TODO: Add your command handler code here
	CAltSetDlg altset;
	if(altset.DoModal()==IDOK)
	{
	}
	
}

void CTF1DDlg::OnAirtozero() 
{
	// TODO: Add your command handler code here
	CAirToZeroDlg airtozero;
	if(airtozero.DoModal()==IDOK)
	{
	}
	
}

void CTF1DDlg::OnBtset() 
{
	// TODO: Add your command handler code here
	CBTSetDlg btset;
	CString m_sBt;
	if(btset.DoModal()==IDOK)
	{
	}
	
}
*/
void CTF1DDlg::OnMenuBuhuoZhongli() 
{
	// TODO: Add your command handler code here
	int check;
	CByteArray hexdata;

	
	check = 0;
	check = (check+0x03+1+0)%256;
		CString m_strSendString = "";
		m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x03,0,1,0,check);
		String2Hex(m_strSendString ,hexdata);
		m_Com.SetOutput(COleVariant(hexdata));//发送数据
//	AfxMessageBox("secusse");
}

void CTF1DDlg::OnMenuBuhuoStopoil() 
{
	// TODO: Add your command handler code here
	int check;
	CByteArray hexdata;

	
	check = 0;
	check = (check+0x03+1+3)%256;
		CString m_strSendString = "";
		m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x03,0,1,3,check);
		String2Hex(m_strSendString ,hexdata);
		m_Com.SetOutput(COleVariant(hexdata));//发送数据
//	AfxMessageBox("secusse");
}

void CTF1DDlg::OnMenuBuhuoMinoil() 
{
	// TODO: Add your command handler code here
	int check;
	CByteArray hexdata;

	
	check = 0;
	check = (check+0x03+1+2)%256;
		CString m_strSendString = "";
		m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x03,0,1,2,check);
		String2Hex(m_strSendString ,hexdata);
		m_Com.SetOutput(COleVariant(hexdata));//发送数据
//	AfxMessageBox("secusse");
	
}

void CTF1DDlg::OnMenuBuhuoMaxoil() 
{
	// TODO: Add your command handler code here
	int check;
	CByteArray hexdata;

	
	check = 0;
	check = (check+0x03+1+1)%256;
		CString m_strSendString = "";
		m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x03,0,1,1,check);
		String2Hex(m_strSendString ,hexdata);
		m_Com.SetOutput(COleVariant(hexdata));//发送数据
//	AfxMessageBox("secusse");
	
}

void CTF1DDlg::OnDownpotOperate(CString str,int num)
{
	int temp;

	switch(num)
	{
	case 2:
		temp = atoi(str);
		m_Down_Pot.check = 0;
		m_Down_Pot.check += temp;
		break;
	case 3:
		temp = atoi(str);
		m_Down_Pot.check += temp;
		break;
	case 4://////航点总数
		temp = atoi(str);
		m_Down_Pot.totalnum = temp;
		m_Down_Pot.check += temp;
		break;
	case 5:
		m_Down_Pot.num = atoi(str);
		m_Down_Pot.check += m_Down_Pot.num;
		break;
	case 6:
		m_Down_Pot.lon4 = atoi(str);
		m_Down_Pot.check += m_Down_Pot.lon4;
		break;
	case 7:
		m_Down_Pot.lon3 = atoi(str);
		m_Down_Pot.check += m_Down_Pot.lon3;
		break;
	case 8:
		m_Down_Pot.lon2 = atoi(str);
		m_Down_Pot.check += m_Down_Pot.lon2;
		break;
	case 9:
		m_Down_Pot.lon1 = atoi(str);
		m_Down_Pot.check += m_Down_Pot.lon1;
		break;
	case 10:
		m_Down_Pot.lat4 = atoi(str);
		m_Down_Pot.check += m_Down_Pot.lat4;
		break;
	case 11:
		m_Down_Pot.lat3 = atoi(str);
		m_Down_Pot.check += m_Down_Pot.lat3;
		break;
	case 12:
		m_Down_Pot.lat2 = atoi(str);
		m_Down_Pot.check += m_Down_Pot.lat2;
		break;
	case 13:
		m_Down_Pot.lat1 = atoi(str);
		m_Down_Pot.check += m_Down_Pot.lat1;
		break;
	case 14:
		m_Down_Pot.alt_l = atoi(str);
		m_Down_Pot.check += m_Down_Pot.alt_l;
		break;
	case 15:
		m_Down_Pot.alt_h = atoi(str);
		m_Down_Pot.check += m_Down_Pot.alt_h;
		break;
	case 16:
		m_Down_Pot.spd = atoi(str);
		m_Down_Pot.check += m_Down_Pot.spd;
		break;
	case 17:
		m_Down_Pot.r_l = atoi(str);
		m_Down_Pot.check += m_Down_Pot.r_l;
		break;
	case 18:
		m_Down_Pot.r_h = atoi(str);
		m_Down_Pot.check += m_Down_Pot.r_h;
		break;
	case 19:
		m_Down_Pot.flag = atoi(str);
		m_Down_Pot.check += m_Down_Pot.flag;
		break;
	case 20:
		m_Down_Pot.time = atoi(str);
		m_Down_Pot.check += m_Down_Pot.time;
		break;
	case 21:
		m_Down_Pot.task = atoi(str);
		m_Down_Pot.check += m_Down_Pot.task;
		break;
	case 22:
		temp = atoi(str);
		m_Down_Pot.check = (m_Down_Pot.check+18)%256;
		if(m_Down_Pot.check == temp)
		{
			m_Potdata_Down[m_Down_Pot.num].num = m_Down_Pot.num;
			m_Potdata_Down[m_Down_Pot.num].lon = (double)(m_Down_Pot.lon4+m_Down_Pot.lon3*256+m_Down_Pot.lon2*256*256+m_Down_Pot.lon1*256*256*256)/10000000;
			m_Potdata_Down[m_Down_Pot.num].lat = (double)(m_Down_Pot.lat4+m_Down_Pot.lat3*256+m_Down_Pot.lat2*256*256+m_Down_Pot.lat1*256*256*256)/10000000;
			m_Potdata_Down[m_Down_Pot.num].alt = m_Down_Pot.alt_h*256+m_Down_Pot.alt_l;
			m_Potdata_Down[m_Down_Pot.num].spd = m_Down_Pot.spd;
			m_Potdata_Down[m_Down_Pot.num].raid = m_Down_Pot.r_h*256+m_Down_Pot.r_l;
			m_Potdata_Down[m_Down_Pot.num].linetype = m_Down_Pot.flag%8;
			if((m_Down_Pot.flag&8) == 8)
				m_Potdata_Down[m_Down_Pot.num].toline = TRUE;
			else 
				m_Potdata_Down[m_Down_Pot.num].toline = FALSE;
			if((m_Down_Pot.flag&16) == 16)
				m_Potdata_Down[m_Down_Pot.num].toground = TRUE;
			else
				m_Potdata_Down[m_Down_Pot.num].toground = FALSE;
			if((m_Down_Pot.flag&32) == 32)
				m_Potdata_Down[m_Down_Pot.num].toslide = TRUE;
			else
				m_Potdata_Down[m_Down_Pot.num].toslide = FALSE;
			if((m_Down_Pot.flag&64) == 64)
				m_Potdata_Down[m_Down_Pot.num].photo = TRUE;
			else 
				m_Potdata_Down[m_Down_Pot.num].photo = FALSE;

			m_Potdata_Down[m_Down_Pot.num].time = m_Down_Pot.time;

			if((m_Down_Pot.task&1) == 1)
				m_Potdata_Down[m_Down_Pot.num].serv1 = TRUE;
			else 
				m_Potdata_Down[m_Down_Pot.num].serv1 = FALSE;
			if((m_Down_Pot.flag&2) == 2)
				m_Potdata_Down[m_Down_Pot.num].serv2 = TRUE;
			else 
				m_Potdata_Down[m_Down_Pot.num].serv2 = FALSE;
			if((m_Down_Pot.flag&3) == 3)
				m_Potdata_Down[m_Down_Pot.num].serv3 = TRUE;
			else
				m_Potdata_Down[m_Down_Pot.num].serv3 = FALSE;

			OnDrowDownPot(m_Down_Pot.num);

		}
		break;
	default:
		break;
	}

}

void CTF1DDlg::OnSeriatephoto() 
{
	// TODO: Add your control notification handler code here
	int check;
	CString str;
	CByteArray hexdata;

	str.Format("提示：是否开启相机连拍");

	if(AfxMessageBox(str,MB_YESNO) == IDNO)
		return;

	check = 0;
	check = (check+0x2c+1+1)%256;
	CString m_strSendString = "";
	m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x2c,0,1,1,check);
	String2Hex(m_strSendString ,hexdata);
	m_Com.SetOutput(COleVariant(hexdata));//发送数据
	
}

void CTF1DDlg::OnSeriatephotostop() 
{
	// TODO: Add your control notification handler code here
		char check;
	CString str;
	CByteArray hexdata;

	str.Format("提示：是否关闭相机连拍");

	if(AfxMessageBox(str,MB_YESNO) == IDNO)
		return;

	check = 0;
	check = check+0x2c+1+0;
	CString m_strSendString = "";
	m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x2c,0,1,0,check);
	String2Hex(m_strSendString ,hexdata);
	m_Com.SetOutput(COleVariant(hexdata));//发送数据
	
	
}

void CTF1DDlg::OnHeadingphoto() 
{
	// TODO: Add your control notification handler code here
	char check;
	CByteArray hexdata;
	check = 0;
	check = check+0x2c+1+2;
	CString m_strSendString = "";
	m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x2c,0,1,2,check);
	String2Hex(m_strSendString ,hexdata);
	m_Com.SetOutput(COleVariant(hexdata));//发送数据
	
	
}

void CTF1DDlg::OnDownphotodata() 
{
	// TODO: Add your control notification handler code here
	char check;
	CByteArray hexdata;
	check = 0;
	check = check+0x2e+4;
	CString m_strSendString = "";
	m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x2e,0,4,0,0,0,0,check);
	String2Hex(m_strSendString ,hexdata);
	m_Com.SetOutput(COleVariant(hexdata));//发送数据	
}

void CTF1DDlg::OnAskphotonum() 
{
	// TODO: Add your control notification handler code here
	char check;
	CByteArray hexdata;
	check = 0;
	check = check+0x2f;
	CString m_strSendString = "";
	m_strSendString.Format("%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x2f,0,0,check);
	String2Hex(m_strSendString ,hexdata);
	m_Com.SetOutput(COleVariant(hexdata));//发送数据	
}

void CTF1DDlg::OnClosereceive() 
{
	// TODO: Add your control notification handler code here
//	Beep(500,100);
//	Beep(400,100);
	Beep(300,100);
//	Beep(400,100);
	char check;
	CByteArray hexdata;
	CString str;
	CString str1;


	m_cClosereceive.GetWindowText(str1);

	if(str1 == "关闭接收机")
		str.Format("提示：是否关闭接收机");
	else str.Format("提示：是否打开接收机");
	if(AfxMessageBox(str,MB_YESNO) == IDNO)
		return;

	if(str1 == "关闭接收机")
	{
		m_cClosereceive.SetWindowText("打开接收机");
//		m_cClosereceive.Print(pDC,PRF_CLIENT);
//		m_cClosereceive.SetRedraw(TRUE);
//		m_cClosereceive.LoadBitmaps(IDB_BITMAP5);
		receiverled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDWAR));
		check = 0;
		check = check+0x24+1+1;
		CString m_strSendString = "";
		m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x24,0,1,1,check);
		String2Hex(m_strSendString ,hexdata);
		m_Com.SetOutput(COleVariant(hexdata));//发送数据
	}
	else
	{
		m_cClosereceive.SetWindowText("关闭接收机");
		receiverled.SetIcon(AfxGetApp()->LoadIcon(IDI_LEDON));
		check = 0;
		check = check+0x24+1;
		CString m_strSendString = "";
		m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x24,0,1,0,check);
		String2Hex(m_strSendString ,hexdata);
		m_Com.SetOutput(COleVariant(hexdata));//发送数据
	}
	
		
	
}

void CTF1DDlg::OnPhotoDataOperate(CString str,int num)
{
	int temp;
	CString strtemp;
	switch(num)
	{
	case 2:
		temp = atoi(str);
		m_Down_Pot.check = 0;
		m_Down_Pot.check += temp;
		break;
	case 3:
		temp = atoi(str);
		m_Down_Pot.check += temp;
		break;
	case 4:///序号
		temp = atoi(str);
		m_Photodata.num = temp*256;
		m_Down_Pot.check += temp;
		break;
	case 5:
		temp = atoi(str);
		m_Photodata.num = m_Photodata.num+temp;
		m_Down_Pot.check += temp;
		break;
	case 6:///时间
		temp = atoi(str);
		m_Photodata.time = temp;
		m_Down_Pot.check += temp;
		break;
	case 7:
		temp = atoi(str);
		m_Photodata.time += temp*256;
		m_Down_Pot.check += temp;
		break;
	case 8:
		temp = atoi(str);
		m_Photodata.time += temp*256*256;
		m_Down_Pot.check += temp;
		break;
	case 9:
		temp = atoi(str);
		m_Photodata.time += temp*256*256*256;
		m_Down_Pot.check += temp;
		break;
	case 10://经度
		temp = atoi(str);
		m_Photodata.lon = temp;
		m_Down_Pot.check += temp;
		break;
	case 11:
		temp = atoi(str);
		m_Photodata.lon += temp*256;
		m_Down_Pot.check += temp;
		break;
	case 12:
		temp = atoi(str);
		m_Photodata.lon += temp*256*256;
		m_Down_Pot.check += temp;
		break;
	case 13:
		temp = atoi(str);
		m_Photodata.lon += temp*256*256*256;
		m_Photodata.lon = m_Photodata.lon/10000000;
		m_Down_Pot.check += temp;
		break;
	case 14://纬度
		temp = atoi(str);
		m_Down_Pot.check += temp;
		m_Photodata.lat = temp;
		break;
	case 15:
		temp = atoi(str);
		m_Down_Pot.check += temp;
		m_Photodata.lat += temp*256;
		break;
	case 16:
		temp = atoi(str);
		m_Down_Pot.check += temp;
		m_Photodata.lat += temp*256*256;
		break;
	case 17:
		temp = atoi(str);
		m_Down_Pot.check += temp;
		m_Photodata.lat += temp*256*256*256;
		m_Photodata.lat = m_Photodata.lat/10000000;
		break;
	case 18://高度
		temp = atoi(str);
		m_Down_Pot.check += temp;
		m_Photodata.alt = temp;
		break;
	case 19:
		temp = atoi(str);
		m_Down_Pot.check += temp;
		m_Photodata.alt += temp*256;
		break;
	case 20:
		temp = atoi(str);
		m_Down_Pot.check += temp;
		m_Photodata.alt += temp*256*256;
		break;
	case 21:
		temp = atoi(str);
		m_Down_Pot.check += temp;
		m_Photodata.alt += temp*256*256*256;	
		m_Photodata.alt = m_Photodata.alt/1000;
		break;
	case 22://俯仰
		temp = atoi(str);
		m_Down_Pot.check += temp;
		m_Photodata.pitch = temp;
		break;
	case 23:
		temp = atoi(str);
		m_Down_Pot.check += temp;
		m_Photodata.pitch += temp*256;
		if(m_Photodata.pitch>3600)
			m_Photodata.pitch = m_Photodata.pitch-65535;
		m_Photodata.pitch = m_Photodata.pitch/10;
		break;
	case 24://滚转
		temp = atoi(str);
		m_Down_Pot.check += temp;
		m_Photodata.roll = temp;
		break;
	case 25:
		temp = atoi(str);
		m_Down_Pot.check += temp;
		m_Photodata.roll += temp*256;
		if(m_Photodata.roll>3600)
			m_Photodata.roll = m_Photodata.roll-65535;
		m_Photodata.roll = m_Photodata.roll/10;
		break;
	case 26://航向
		temp = atoi(str);
		m_Down_Pot.check += temp;
		m_Photodata.heading = temp;
		break;
	case 27:
		temp = atoi(str);
		m_Down_Pot.check += temp;
		m_Photodata.heading += temp*256;	
		m_Photodata.heading = m_Photodata.heading/10;
		break;
	case 28:
		temp = atoi(str);
		m_Down_Pot.check  = (m_Down_Pot.check+46)%256;
		if(m_Down_Pot.check == temp)
		{
			int day,hour,minter,second;
			day = (int)m_Photodata.time/1000/3600/24;
			hour = (int)((m_Photodata.time/1000/3600/24-day)*24);
			minter = (int)(((m_Photodata.time/1000/3600/24-day)*24-hour)*60);
			second = (int)((((m_Photodata.time/1000/3600/24-day)*24-hour)*60-minter)*60);
			strtemp.Format("%4d   星期%d %2d:%2d:%2d  %4.5lf    %4.5lf   %4ld     %5.2lf    %5.2lf    %5.2lf\r\n",m_Photodata.num,day,hour,minter,second,m_Photodata.lon,m_Photodata.lat,m_Photodata.alt,m_Photodata.pitch,m_Photodata.roll,m_Photodata.heading);
			OnFileSavePhotoData(strtemp);
		}
	default:
		break;
	}


}

void CTF1DDlg::OnFileSavePhotoData(CString str)
{
	int m_len;
	if(fpFlag == FALSE)
	{
		int date,hour,minuter,month,second;

		CTime time;
		CString strfile;
		CString strtemp = "";
		time = CTime::GetCurrentTime();
		month = time.GetMonth();
		date = time.GetDay();
		hour = time.GetHour();
		minuter = time.GetMinute();
		second = time.GetSecond();

		strtemp.Format("%d月%d日%d点%d分%d秒",month,date,hour,minuter,second);
		strfile.Format("%s\\照片数据\\照片数据%s.txt",str_parth,strtemp);

		fpFlag = fp.Open(strfile,CFile::modeCreate|CFile::modeWrite);
//		strtemp	= "时间, 自驾电压,舵机电压,电台电压,数管电压,组件电压,GPS纬度(N),GPS经度(N),空速,地速,高度,GPS时间,自驾模式,GPS状态,航点\n ";
	}

//	m_len = strtemp.GetLength();
//	fp.SeekToEnd();
//	fp.Write(strtemp,m_len);
	

//	str += "\n\r";
	m_len=str.GetLength();
	fp.SeekToEnd();
	fp.Write(str,m_len);
}

void CTF1DDlg::OnDrowDownPot(int num)
{
		try {
			CMapXPoint pt;
			CMapXFeature fre,obj; 
			CMapXLayer lay;
			double x,y;
			int flag,time,task;
						
//			m_dFtrsNum++;

			x = m_Potdata_Down[num].lon;
			y = m_Potdata_Down[num].lat;

			lay = m_cMap.GetLayers().Item("DownPoints");
			pt.CreateDispatch(pt.GetClsid());
			fre.CreateDispatch(fre.GetClsid());
			fre.Attach(m_cMap.GetDispatch());
			fre.SetType(miFeatureTypeSymbol);

			pt.Set(x,y);
//			m_pts.Add(pt,m_dFtrsNum);

			lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
			lay.GetStyle().GetSymbolFont().SetName("Wingdings");
			lay.GetStyle().SetSymbolCharacter(171);
			lay.GetStyle().SetSymbolFontHalo(TRUE);
			lay.GetStyle().SetSymbolFontColor(0xff1e0e);
 //			newlayer.GetStyle().GetSymbolFont().SetSize(fontSize);
//			lay.GetStyle().SetSymbolFontRotation(-angle);
			fre.SetStyle(m_cMap.GetDefaultStyle());
			fre.GetPoint().Set(x,y);
//			fre.SetKeyValue("1");//////////////////////////////////////////////////////////标注添
			lay.GetLabelProperties().SetPosition(miPositionTR);
			lay.GetLabelProperties().SetOffset(4);
			lay.GetLabelProperties().GetStyle().SetTextFontColor(0xff1e0e);

			obj = m_cMap.GetLayers().Item("DownPoints").AddFeature(fre);
		
			VARIANT lyrVt;
	//		CMapXRowValues rvs;
	//		CMapXRowValue rv;
			lyrVt.vt = VT_DISPATCH;
			lyrVt.pdispVal = m_cMap.GetLayers().Item("DownPoints");

			lyrVt.pdispVal->AddRef();
			m_dataset = m_cMap.GetDatasets().Add(miDataSetLayer,lyrVt);

			
//			CString str_key;
//			lay.SetKeyField("num");
//			str_key.Format("%d",num);
//			obj.SetKeyValue(str_key);
//			obj.Update();
		//	m_dataset.Refresh();
		
		}
		catch (COleDispatchException *e) {
			e->ReportError();
			e->Delete();
		}
		catch (COleException *e) {
			e->ReportError();
			e->Delete();
	}


}

void CTF1DDlg::OnCheckupline() 
{
	// TODO: Add your control notification handler code here
	m_bCheckUpLine = !m_bCheckUpLine;
	if(m_bCheckUpLine == FALSE)
		m_cMap.GetLayers().Item("DownPoints").SetVisible(FALSE);
	else
		m_cMap.GetLayers().Item("DownPoints").SetVisible(TRUE);
	
}

void CTF1DDlg::OnCheckrealline() 
{
	// TODO: Add your control notification handler code here
	m_bCheckRealLine = !m_bCheckRealLine;
	if(m_bCheckRealLine == FALSE)
		m_cMap.GetLayers().Item("UAVPoints").SetVisible(FALSE);
	else
		m_cMap.GetLayers().Item("UAVPoints").SetVisible(TRUE);
	
}

void CTF1DDlg::OnPhotoNumOperate(CString str,int num)
{
	int tempnum;
	CString strtemp;
	switch(num)
	{

	case 4:////数据
		tempnum = atoi(str);
		m_nPhotoNum = tempnum*256;
		break;
	case 5:///
		tempnum = atoi(str);
		m_nPhotoNum += tempnum;
		strtemp.Format("%d",m_nPhotoNum);
		m_cPhotoNum.SetWindowText(strtemp);
		break;
	default:
		break;
	}

}

void CTF1DDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	unsigned char c;
	int num;
	int per;
	CString sper;
	if(nIDEvent == 1)
	{
		num = (int)(m_nTotalNum-m_nTotalNum_Timer);
		str.Format("%d",num);
		m_cFrequency.SetWindowText(str);
		m_nTotalNum_Timer = m_nTotalNum;
	}else if(nIDEvent == 2)
	{
		if(m_bTime2Flag == FALSE)
		{
			m_bTime2Flag = TRUE;
		}
		for(;m_nDataPos<m_nDataLength;m_nDataPos++)
		{
			per = m_nDataPos*1000/m_nDataLength;
			sper.Format("%d‰",per);
			m_cShowSite.SetWindowText(sper);
			m_cSiteSlider.SetPos(per);
			if(m_bTime2Flag == TRUE)
			{
				c = pData[m_nDataPos];
				str.Format("%d",c);
				GetStrReceived(str);
			}else
			{
				break;
			}
		}
		
	}
	
	CDialog::OnTimer(nIDEvent);
}
/*
void CTF1DDlg::OnCustomdrawSpeedslider(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	AfxMessageBox("111");
	
	*pResult = 0;
}
*/

void CTF1DDlg::OnReleasedcaptureSpeedslider(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int num;
	CString str;
	num = m_cSpeedSlider.GetPos();
//	str.Format("%d",num);
//	AfxMessageBox(str);

	if(	m_nTimeFlag!=0)
	{
		if(num == 0)
		{
			m_cShowSpeed.SetWindowText("0X");
			KillTimer(2);
		}
		else
		{
			num = pow(2,num-1);
			str.Format("%dX",num);
			m_cShowSpeed.SetWindowText(str);
			num = 1000/num;
			KillTimer(2);
			SetTimer(2,num,NULL);
		}
	}else
	{
		if(num == 0)
		{
			m_cShowSpeed.SetWindowText("0X");
		}else
		{
			num = pow(2,num-1);
			str.Format("%dX",num);
			m_cShowSpeed.SetWindowText(str);
			num = 1000/num;
			m_nTimeFlag = SetTimer(2,num,NULL);////开启回放速度选择定时器
		}
	}

	*pResult = 0;
}

void CTF1DDlg::OnFileSaveRecord(int m_num)
{
//	int m_len;
//	m_len=str.GetLength();
	m_fp_Record.SeekToEnd();
	m_fp_Record.Write(m_pBuff,m_num);

}

void CTF1DDlg::OnFileSaveText()
{
	int hour,miniter,second;
	int m_len;
	CTime time;
	CString strtime;
	CString strtemp;
	time = CTime::GetCurrentTime();
	hour = time.GetHour();
	miniter = time.GetMinute();
	second = time.GetSecond();
	strtime.Format("%2d:%2d:%2d",hour,miniter,second);
	m_sYaoce_Data_Save.Format("%s  %3d  %3.5lf  %3.5lf  %4.1lf  %3.2lf  %4.2lf  %4d\r\n",strtime,m_Yaoce_Data.m_nTargetWP,m_Yaoce_Data.m_GPSdata.m_dLon,m_Yaoce_Data.m_GPSdata.m_dLat,m_Yaoce_Data.m_GPSdata.m_dGPSalt,m_Yaoce_Data.m_GPSdata.m_dGPSspd,m_Yaoce_Data.m_GPSdata.m_dHangxiang,m_Yaoce_Data.m_nRPM);
	////////////////////////////////////////////////////////////    /////时间    目标航点/////////////// 经度                          纬度                             GPS高度                          GPS速度                      GPS航向                             转速
	m_len=m_sYaoce_Data_Save.GetLength();
	m_fp_Text.SeekToEnd();
	m_fp_Text.Write(m_sYaoce_Data_Save,m_len);

}

void CTF1DDlg::OnUploadsomepoint() 
{
	// TODO: Add your command handler code here	
	Beep(300,100);
	if(AfxMessageBox("注意：请确认是否进行上传航点!\n同时请确保串行端口处于数据接收状态",MB_YESNO) == IDNO)
		return;

	int check=0;
	int size;
	int size_h;
	int size_l;
	int lat1,lat2,lat3,lat4;
	int lon1,lon2,lon3,lon4;
	int alt_h,alt_l;
	int spd,raid_h,raid_l;
	int flag;
	int time;
	int sver;
	CMapXLayer lay;
	CString str,strtemp;
	CString m_strSendString = "";
	CByteArray hexdata;
//	UpdateData(TRUE);
	int count;////选择航点总数
	int num;//////航点号

	lay = m_cMap.GetLayers().Item(m_sLayerName_Points);
	count = lay.GetSelection().GetCount();
	for(int i=1;i<=count;i++)
	{
		str = lay.GetSelection().Item(i).GetKeyValue();
		num = atoi(str);///获取选择航点号
		lon4 = potdata.m_Potdata[num].lon*10000000/256/256/256;
		lon3 = (int)(potdata.m_Potdata[num].lon*10000000/256/256)%256;
		lon2 = (int)(potdata.m_Potdata[num].lon*10000000/256)%256;
		lon1 = (int)(potdata.m_Potdata[num].lon*10000000)%256;
		lat4 = potdata.m_Potdata[num].lat*10000000/256/256/256;
		lat3 = (int)(potdata.m_Potdata[num].lat*10000000/256/256)%256;
		lat2 = (int)(potdata.m_Potdata[num].lat*10000000/256)%256;
		lat1 = (int)(potdata.m_Potdata[num].lat*10000000)%256;
		alt_h = potdata.m_Potdata[num].alt/256;
		alt_l = potdata.m_Potdata[num].alt%256;
		spd = potdata.m_Potdata[num].spd;
		raid_h = potdata.m_Potdata[num].raid/256;
		raid_l = potdata.m_Potdata[num].raid%256;
		flag = potdata.m_Potdata[num].linetype+ potdata.m_Potdata[num].toline*8+potdata.m_Potdata[num].toground*16+potdata.m_Potdata[num].toslide*32+potdata.m_Potdata[num].photo*64;
		time = potdata.m_Potdata[num].time/10;
		sver = potdata.m_Potdata[num].serv1+potdata.m_Potdata[num].serv2*2+potdata.m_Potdata[num].serv3*4;

		m_strSendString.Format("%02x%02x%02x%02x%02x",0x0a,0xFF,0x12,0,17);///信息头，至航点数
		check = 0x12+0+17;
		strtemp.Format("%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",num,lon1,lon2,lon3,lon4,lat1,lat2,lat3,lat4,alt_l,alt_h,spd,raid_l,raid_h,flag,time,sver);
		m_strSendString +=strtemp;
		check = check+num+lon1+lon2+lon3+lon4+lat1+lat2+lat3+lat4+alt_l+alt_h+spd+raid_l+raid_h+flag+time+sver;
		check = check%256;
		strtemp.Format("%02x",check);
		m_strSendString += strtemp;
		String2Hex(m_strSendString ,hexdata);
		m_Com.SetOutput(COleVariant(hexdata));//发送数据
	}
}

void CTF1DDlg::OnCopypoints() 
{
	// TODO: Add your control notification handler code here
	if(m_sLayerName_Points != "航线层")
	{
		AfxMessageBox("请首先创建航点图层");
		return;
	}
	try {
		CMapXPoint pt;
		CMapXFeature fre,obj; 
		CMapXLayer lay;
		double x,y;
		int flag,time,task;
		CString str_key;
						
		lay = m_cMap.GetLayers().Item(m_sLayerName_Points);
		pt.CreateDispatch(pt.GetClsid());
		fre.CreateDispatch(fre.GetClsid());
		fre.Attach(m_cMap.GetDispatch());
		fre.SetType(miFeatureTypeSymbol);
		lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
		lay.GetStyle().GetSymbolFont().SetName("Wingdings");
		lay.GetStyle().SetSymbolCharacter(181);
		lay.GetStyle().SetSymbolFontHalo(TRUE);
		lay.GetStyle().SetSymbolFontColor(0x0e1eff);
		lay.GetLabelProperties().SetPosition(miPositionTR);
		lay.GetLabelProperties().SetOffset(2);
		lay.GetLabelProperties().GetStyle().SetTextFontColor(0xff00ff);
		fre.SetStyle(m_cMap.GetDefaultStyle());
		for(int i=1;i<=m_Down_Pot.totalnum;i++)
		{
			potdata.m_Potdata[i].num = m_Potdata_Down[i].num;
			potdata.m_Potdata[i].alt = m_Potdata_Down[i].alt;
			potdata.m_Potdata[i].lat = m_Potdata_Down[i].lat;
			potdata.m_Potdata[i].linetype = m_Potdata_Down[i].linetype;
			potdata.m_Potdata[i].lon = m_Potdata_Down[i].lon;
			potdata.m_Potdata[i].photo = m_Potdata_Down[i].photo;
			potdata.m_Potdata[i].raid = m_Potdata_Down[i].raid;
			potdata.m_Potdata[i].serv1 = m_Potdata_Down[i].serv1;
			potdata.m_Potdata[i].serv2 = m_Potdata_Down[i].serv2;	
			potdata.m_Potdata[i].serv3 = m_Potdata_Down[i].serv3;
			potdata.m_Potdata[i].spd = m_Potdata_Down[i].spd;
			potdata.m_Potdata[i].time = m_Potdata_Down[i].time;
			potdata.m_Potdata[i].toground = m_Potdata_Down[i].toground;
			potdata.m_Potdata[i].toline = m_Potdata_Down[i].toline;
			potdata.m_Potdata[i].toslide = m_Potdata_Down[i].toslide;

			flag = potdata.m_Potdata[i].linetype+ potdata.m_Potdata[i].toline*8+potdata.m_Potdata[i].toground*16+potdata.m_Potdata[i].toslide*32+potdata.m_Potdata[i].photo*64;
			time = potdata.m_Potdata[i].time/10;
			task = potdata.m_Potdata[i].serv1+potdata.m_Potdata[i].serv2*2+potdata.m_Potdata[i].serv3*4;

		

			m_dFtrsNum++;
			x = potdata.m_Potdata[i].lon;
			y = potdata.m_Potdata[i].lat;
			pt.Set(x,y);
			m_pts.Add(pt,m_dFtrsNum);
			fre.GetPoint().Set(x,y);
			obj = m_cMap.GetLayers().Item(m_sLayerName_Points).AddFeature(fre);

			VARIANT lyrVt;
			lyrVt.vt = VT_DISPATCH;
			lyrVt.pdispVal = m_cMap.GetLayers().Item(m_sLayerName_Points);

			lyrVt.pdispVal->AddRef();
			m_dataset = m_cMap.GetDatasets().Add(miDataSetLayer,lyrVt);


			lay.SetKeyField("alt");
			str_key.Format("%d",potdata.m_Potdata[i].alt);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("tas");
			str_key.Format("%d",potdata.m_Potdata[i].spd);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("r");
			str_key.Format("%d",potdata.m_Potdata[i].raid);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("flag");
			str_key.Format("%d",flag);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("time");
			str_key.Format("%d",time);
			obj.SetKeyValue(str_key);
			obj.Update();
		

			lay.SetKeyField("task");
			str_key.Format("%d",task);//potdata.m_Potdata[i].toline);
			obj.SetKeyValue(str_key);
			obj.Update();

			lay.SetKeyField("num");
			str_key.Format("%d",potdata.m_Potdata[i].num);
			obj.SetKeyValue(str_key);
			obj.Update();
		}

	}
	catch (COleDispatchException *e) {
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e) {
		e->ReportError();
		e->Delete();
	}
}

void CTF1DDlg::OnDatashow() 
{
	// TODO: Add your command handler code here
	m_bFilesaveFlag = FALSE;//////////设置文件保存标志为非
	CFile* m_pFile;

//	LONG m_nDataPos;
	LPVOID m_pData;

	unsigned char c;
	CString str;
	CString strtemp;
 	//////////////////////////////
	strtemp.Format("%s\\record",str_parth);

 	CString	file;
 	file.Empty();
	m_comDlg2.SetDialogTitle("航迹回放文件选择");
	m_comDlg2.SetFilter("*.rec");
	m_comDlg2.SetFileName("*.rec");
	m_comDlg2.SetInitDir(strtemp);
 	m_comDlg2.ShowOpen();
 	file=m_comDlg2.GetFileName();
	file.TrimRight();
 	if(file.IsEmpty())
	{
       AfxMessageBox("Please Select a txt file");
	   return;
	}
 	else
	{
 	//文件打开
		m_pFile=new CFile(file,CFile::modeRead|CFile::typeBinary);
 	//文件是否打开判断
		if(!m_pFile) {AfxMessageBox("该文件打开出错");}
 	//获取文件长度
		m_nDataLength = m_pFile->GetLength();
		pData = new unsigned char[m_nDataLength];
		m_pData = (LPVOID)pData;
		m_pFile->ReadHuge(m_pData,m_nDataLength);
		pData = (unsigned char*)m_pData;
		m_pFile->Close();
	}
	m_nDataPos = 0;

}

void CTF1DDlg::OnYaocedata() 
{
	// TODO: Add your command handler code here
	char check;
	CByteArray hexdata;
	check = 0;
	check = check+0x14;
	CString m_strSendString = "";
	m_strSendString.Format("%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x14,0,0,check);
	String2Hex(m_strSendString ,hexdata);
	m_Com.SetOutput(COleVariant(hexdata));//发送数据
	
}

void CTF1DDlg::OnYaocedatastop() 
{
	// TODO: Add your command handler code here
	Beep(300,100);
	if(AfxMessageBox("提示:\n停发数据后,自动驾驶仪\n将停止数据的自动下传,\n请确认是否进行此项操作",MB_YESNO) == IDNO)
		return;
	char check;
	CByteArray hexdata;
	check = 0;
	check = check+1;
	CString m_strSendString = "";
	m_strSendString.Format("%02x%02x%02x%02x%02x%02x",0x0a,0xFF,1,0,0,check);
	String2Hex(m_strSendString ,hexdata);
	m_Com.SetOutput(COleVariant(hexdata));//发送数据
	
}

void CTF1DDlg::OnBegainfly() 
{
	// TODO: Add your control notification handler code here
	Beep(300,100);
	if(AfxMessageBox("警告:\n切勿在以下情况未发生时启动滑翔:\n1.发动机工作出现异常;\n2.无人机无法控制.\n请再次确认是否启动滑翔!\n需设定滑翔空速为:米/秒",MB_YESNO) == IDNO)
		return;
	char check;
	CString str;
	int num;
	UpdateData(TRUE);
	num = m_nFlyspeed;
	CByteArray hexdata;
	check = 0;
	check = check+0x32+2+num;
	CString m_strSendString = "";
	m_strSendString.Format("%02x%02x%02x%02x%02x%02x%02x%02x",0x0a,0xFF,0x32,0,2,0,num,check);
	String2Hex(m_strSendString ,hexdata);
	m_Com.SetOutput(COleVariant(hexdata));//发送数据

	str.Format("已发送设定空速为%dm/s的空速控制滑翔指令，\n请观察应答信息是否显示已应答",num);
	AfxMessageBox(str);
	
}

void CTF1DDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	Beep(500,100);
	if(AfxMessageBox("注意：是否确认退出当前程序?\n单击“是”退出,单击“否”返回程序",MB_YESNO) == IDNO)
		return;
	CDialog::OnCancel();
}


void CTF1DDlg::OnReleasedcaptureSiteslide(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	long num;
	CString str;
	num = m_cSiteSlider.GetPos();
	m_nDataPos = m_nDataLength*num/1000;

	str.Format("%d‰",num);
	m_cShowSite.SetWindowText(str);
	*pResult = 0;
}

void CTF1DDlg::OnPicshow() 
{
	// TODO: Add your command handler code here
	//	LPDISPATCH pDispatch;
	CMapXFields fields;
	CMapXLayerInfo layerinfo;
	CMapXLayer layer;
	CMapXLayers layers;

///////////////////////////////////////////////
////        创建"PhotosLayer"图层          ////
///////////////////////////////////////////////
	try
	{
		if(!fields.CreateDispatch(fields.GetClsid()))
		return ; 

		fields.AddIntegerField("num",FALSE); 

		VARIANT vField;
		vField.vt=VT_DISPATCH;
		vField.pdispVal=fields.m_lpDispatch;

		if(!layerinfo.CreateDispatch(layerinfo.GetClsid())) 
			return ;  
		layerinfo.SetType(miLayerInfoTypeTemp);     //新建图层类型
		layerinfo.AddParameter("Name",COleVariant("PhotosLayer"));
		layerinfo.AddParameter("Fields",vField);

		layers=m_cMap.GetLayers();
		layer=layers.Add(layerinfo.m_lpDispatch); 
  
		m_cMap.GetLayers().Item("PhotosLayer").SetSelectable(TRUE);
		m_cMap.GetLayers().Item("PhotosLayer").SetOverrideStyle(TRUE);
		m_cMap.GetLayers().Item("PhotosLayer").SetEditable(TRUE);
		m_cMap.GetLayers().Item("PhotosLayer").SetAutoLabel(TRUE);///////////自动标注开
		m_cMap.GetLayers().SetAnimationLayer(layer.m_lpDispatch);
		m_cMap.GetLayers().SetInsertionLayer(layer.m_lpDispatch);
  
	}
	catch (COleDispatchException *e) 
	{
		e->ReportError();
		e->Delete();
	}
	catch (COleException *e)
	{
		e->ReportError();
		e->Delete();
	}
	VARIANT lyrVt;
	lyrVt.vt = VT_DISPATCH;
	lyrVt.pdispVal = m_cMap.GetLayers().Item("PhotosLayer");
	lyrVt.pdispVal->AddRef();
	m_dataset = m_cMap.GetDatasets().Add(miDataSetLayer,lyrVt);
	m_cMap.GetLayers().Item("PhotosLayer").SetAutoLabel(TRUE);
//	int i = dataset.GetFields().GetCount();

		m_bFilesaveFlag = FALSE;//////////设置文件保存标志为非
	CFile* m_pFile;

//	LONG m_nDataPos;
	LPVOID m_pData;
	unsigned char c;
	CString str,strtemp;
	CString strall;
	long strnum,num;
	double lon,lat;
	double heading;

 	//////////////////////////////
 	CString	file;
 	file.Empty();
	m_comDlg2.SetDialogTitle("照片位置回放文件选择");
	m_comDlg2.SetFilter("*.txt");
	m_comDlg2.SetFileName("*.txt");
 	m_comDlg2.ShowOpen();
 	file=m_comDlg2.GetFileName();
	file.TrimRight();
 	if(file.IsEmpty())
	{
       AfxMessageBox("Please Select a txt file");
	   return;
	}
 	else
	{
 	//文件打开
		m_pFile=new CFile(file,CFile::modeRead|CFile::typeBinary);
 	//文件是否打开判断
		if(!m_pFile) {AfxMessageBox("该文件打开出错");}
 	//获取文件长度
		m_nDataLength = m_pFile->GetLength();
		pData = new unsigned char[m_nDataLength];
		m_pData = (LPVOID)pData;
		m_pFile->ReadHuge(m_pData,m_nDataLength);
		pData = (unsigned char*)m_pData;
		m_pFile->Close();
		strall = pData;
	}
	m_nDataPos = 0;

	strnum = 0;

	for(;m_nDataPos<m_nDataLength;)
	{
		strnum = strall.Find("\n",m_nDataPos);
		strnum = strnum-m_nDataPos;
//		m_nDataPos = m_nDataPos+1;
		str = strall.Mid(m_nDataPos,strnum);
		m_nDataPos = m_nDataPos+strnum+1;

		strtemp = str.Left(4);
		num = atoi(strtemp);
		strtemp = str.Mid(22,10);
		lon = atof(strtemp);
		strtemp = str.Mid(35,10);
		lat = atof(strtemp);
		strtemp = str.Mid(strnum-7,6);
		heading = atof(strtemp);
		OnDrawPhotoShow(lon,lat,num,heading);
	}

}

void CTF1DDlg::OnDrawPhotoShow(double lon, double lat, int num, double heading)
{
		try {
			CMapXPoint pt;
			CMapXFeature fre,obj; 
			CMapXLayer lay;
			double x,y;
			CString str_key;
			int angle;

			x = lon;
			y = lat;
			angle = (int)heading-90;

			lay = m_cMap.GetLayers().Item("PhotosLayer");
			pt.CreateDispatch(pt.GetClsid());
			fre.CreateDispatch(fre.GetClsid());
			fre.Attach(m_cMap.GetDispatch());
			fre.SetType(miFeatureTypeSymbol);

			pt.Set(x,y);

			lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
			lay.GetStyle().GetSymbolFont().SetName("Wingdings");
			lay.GetStyle().SetSymbolCharacter(176);
			lay.GetStyle().SetSymbolFontHalo(TRUE);
			lay.GetStyle().SetSymbolFontColor(0xdd1e00);
 //			newlayer.GetStyle().GetSymbolFont().SetSize(fontSize);
//			lay.GetStyle().SetSymbolFontRotation(angle);
			fre.SetStyle(m_cMap.GetDefaultStyle());
			fre.GetPoint().Set(x,y);
//			fre.SetKeyValue("1");//////////////////////////////////////////////////////////标注添
			lay.GetLabelProperties().SetPosition(miPositionTR);
			lay.GetLabelProperties().SetOffset(2);
			lay.GetLabelProperties().GetStyle().SetTextFontColor(0xff00ff);

			obj = lay.AddFeature(fre);

	//		CMapXDataset dataset;
	//		CMapXRowValue rowvalue;
	//		CMapXRowValues rowvalues;
	//		rowvalue.SetValue(
	//		rowvalues.Add(rowvalue);

		
			VARIANT lyrVt;
	//		CMapXRowValues rvs;
	//		CMapXRowValue rv;
			lyrVt.vt = VT_DISPATCH;
			lyrVt.pdispVal = m_cMap.GetLayers().Item("PhotosLayer");

			lyrVt.pdispVal->AddRef();
			m_dataset = m_cMap.GetDatasets().Add(miDataSetLayer,lyrVt);


			lay.SetKeyField("num");
			str_key.Format("%d",num);
			obj.SetKeyValue(str_key);
			obj.Update();
		//	m_dataset.Refresh();
		
		}
		catch (COleDispatchException *e) {
			e->ReportError();
			e->Delete();
		}
		catch (COleException *e) {
			e->ReportError();
			e->Delete();
	}
	

}

void CTF1DDlg::OnFileInit()
{
	CString str_temp = "ini.txt";
	LPVOID m_pData;
	CString str,strtemp;
	CFile* m_pFile;
	int len;
//	CString m_tempsBt;

	m_pFile=new CFile("ini.txt",CFile::modeRead|CFile::typeBinary);
 	//文件是否打开判断
	if(!m_pFile) {AfxMessageBox("系统默认文件ini.txt丢失");}
	str_parth = m_pFile->GetFilePath();
	len = str_parth.GetLength();
	str_parth.Delete(len-8,8);

 	//获取文件长度
	len = m_pFile->GetLength();
	pData = new unsigned char[len];
	m_pData = (LPVOID)pData;
	m_pFile->ReadHuge(m_pData,len);
	pData = (unsigned char*)m_pData;
	m_pFile->Close();
	str = pData;

	m_sBt = str.Mid(1,len-1);
	strtemp = str.Left(1);
	m_nPort = atoi(strtemp);
	m_strSettings.Format("%s,%s",m_sBt,"n,8,1");
}

void CTF1DDlg::OnBplaysiteSet() 
{
	// TODO: Add your control notification handler code here
	long num;
	CString str;
	m_cShowSite.GetWindowText(str);
	num = atoi(str);
	m_nDataPos = num*m_nDataLength/1000;
	m_cSiteSlider.SetPos(num);

}

void CTF1DDlg::OnLineComputer() 
{
	// TODO: Add your command handler code here
	CLineComputerDlg LineComputerDlg;
	LineComputerDlg.DoModal();
}

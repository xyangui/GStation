// PIDAdjDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gstation.h"
#include "PIDAdjDlg.h"
#include "GStationDlg.h"

#include "scroll.h"
#include "strings.h"
#include "tchart.h"
#include "series.h"
#include "valuelist.h"
#include "axes.h"
#include "axis.h"
#include "pen.h"
#include "axislabels.h"
#include "teefont.h"
#include "axistitle.h"
#include "aspect.h"
#include "fastlineseries.h"
#include "titles.h"
#include "fastlineseries.h"
#include "panel.h"
#include "legend.h"
#include "tools.h"
#include "toollist.h"
#include "annotationtool.h"
#include "page.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPIDAdjDlg dialog

CGStationDlg *cGStationDlg;

CPIDAdjDlg::CPIDAdjDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPIDAdjDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPIDAdjDlg)
	m_txtBP = 0;
	m_txtDh_D = 0;
	m_txtDH_I = 0;
	m_txtDh_P = 0;
	m_txtFxd_D = 0;
	m_txtFxd_I = 0;
	m_txtFxd_P = 0;
	m_txtFy_D = 0;
	m_txtFy_I = 0;
	m_txtFy_P = 0;
	m_txtGdAgl_D = 0;
	m_txtGdAgl_I = 0;
	m_txtGuAgl_P = 0;
	m_txtGdQg_D = 0;
	m_txtGdQg_I = 0;
	m_txtGz_D = 0;
	m_txtGdQg_P = 0;
	m_txtGz_I = 0;
	m_txtGz_P = 0;
	m_txtKsKf_D = 0;
	m_txtKsKf_I = 0;
	m_txtKsKf_P = 0;
	m_txtKsKy_D = 0;
	m_txtKsKy_I = 0;
	m_txtKsKy_P = 0;
	m_txtPhxz_D = 0;
	m_txtPhxz_I = 0;
	m_txtPhxz_P = 0;
	m_txtTP = 0;
	m_txtVP = 0;
	m_txtAimFyDeg = 0;
	m_txtAimGd = 0;
	m_txtAimHx = 0;
	m_txtAimKs = 0;
	m_txtAimZwRate = 0;
	m_txtCj = 0;
	m_txtDs = 0;
	m_txtFyDeg = 0;
	m_txtFyRPV = 0.0f;
	m_txtGd = 0;
	m_txtGdRPV = 0;
	m_txtGPSgd = 0;
	m_txtHx = 0;
	m_txthxx = 0;
	m_txtJmb = 0;
	m_txtKs = 0;
	m_txtKsRPV = 0;
	m_txtMaxYj = 0;
	m_txtMaxZwRate = 0;
	m_txtMidYj = 0;
	m_txtPIDModel = 0;
	m_txtPxc = 0;
	m_txtZwRate = 0;
	m_txtZwRPV = 0;
	m_txtFyGzDeg = 0;
	m_txtCtrlModel = _T("");
	m_check_FySwitch = FALSE;
	m_check_GdSwitch = FALSE;
	m_check_GPSDhSwitch = FALSE;
	m_check_GzSwitch = FALSE;
	m_check_KsSwitch = FALSE;
	m_check_KsToYm = FALSE;
	m_check_PhxzSwitch = FALSE;
	m_check_ZwbzSwitch = FALSE;
	m_check_ZwSwitch = FALSE;
	m_txtMinYJ = 0;
	//}}AFX_DATA_INIT

	m_ChartDataCount = 0;
	m_IsRefresh = false;
	m_combo_SelectIndex = 0;
	m_chartShowPointCount = 99;
	cGStationDlg = (CGStationDlg*)AfxGetApp()->GetMainWnd();
	
	m_colorEditText = RGB(0,0,0);
	m_colorEditBK = RGB(255,255,255);
	m_pEditBkBrush = new CBrush(RGB(255,255,255));
}


void CPIDAdjDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPIDAdjDlg)
	DDX_Control(pDX, IDC_COMBO_SelectCH, m_combo_SelectCH);
	DDX_Control(pDX, IDC_BTN_SendYjData, m_btnSendYjData);
	DDX_Control(pDX, IDC_BTN_SendData, m_btnSendData);
	DDX_Text(pDX, IDC_EDIT_BP, m_txtBP);
	DDX_Text(pDX, IDC_EDIT_dh_D, m_txtDh_D);
	DDX_Text(pDX, IDC_EDIT_dh_I, m_txtDH_I);
	DDX_Text(pDX, IDC_EDIT_dh_P, m_txtDh_P);
	DDX_Text(pDX, IDC_EDIT_fxd_D, m_txtFxd_D);
	DDX_Text(pDX, IDC_EDIT_fxd_I, m_txtFxd_I);
	DDX_Text(pDX, IDC_EDIT_fxd_P, m_txtFxd_P);
	DDX_Text(pDX, IDC_EDIT_fy_D, m_txtFy_D);
	DDX_Text(pDX, IDC_EDIT_fy_I, m_txtFy_I);
	DDX_Text(pDX, IDC_EDIT_fy_P, m_txtFy_P);
	DDX_Text(pDX, IDC_EDIT_gd_agl_D, m_txtGdAgl_D);
	DDX_Text(pDX, IDC_EDIT_gd_agl_I, m_txtGdAgl_I);
	DDX_Text(pDX, IDC_EDIT_gd_agl_P, m_txtGuAgl_P);
	DDX_Text(pDX, IDC_EDIT_gd_qg_D, m_txtGdQg_D);
	DDX_Text(pDX, IDC_EDIT_gd_qg_I, m_txtGdQg_I);
	DDX_Text(pDX, IDC_EDIT_gz_D, m_txtGz_D);
	DDX_Text(pDX, IDC_EDIT_gd_qg_P, m_txtGdQg_P);
	DDX_Text(pDX, IDC_EDIT_gz_I, m_txtGz_I);
	DDX_Text(pDX, IDC_EDIT_gz_P, m_txtGz_P);
	DDX_Text(pDX, IDC_EDIT_ks_kf_D, m_txtKsKf_D);
	DDX_Text(pDX, IDC_EDIT_ks_kf_I, m_txtKsKf_I);
	DDX_Text(pDX, IDC_EDIT_ks_kf_P, m_txtKsKf_P);
	DDX_Text(pDX, IDC_EDIT_ks_ky_D, m_txtKsKy_D);
	DDX_Text(pDX, IDC_EDIT_ks_ky_I, m_txtKsKy_I);
	DDX_Text(pDX, IDC_EDIT_ks_ky_P, m_txtKsKy_P);
	DDX_Text(pDX, IDC_EDIT_phxz_D, m_txtPhxz_D);
	DDX_Text(pDX, IDC_EDIT_phxz_I, m_txtPhxz_I);
	DDX_Text(pDX, IDC_EDIT_phxz_P, m_txtPhxz_P);
	DDX_Text(pDX, IDC_EDIT_TP, m_txtTP);
	DDX_Text(pDX, IDC_EDIT_VP, m_txtVP);
	DDX_Text(pDX, IDC_EDIT_aimFyDeg, m_txtAimFyDeg);
	DDX_Text(pDX, IDC_EDIT_aimGd, m_txtAimGd);
	DDX_Text(pDX, IDC_EDIT_aimHx, m_txtAimHx);
	DDX_Text(pDX, IDC_EDIT_aimKs, m_txtAimKs);
	DDX_Text(pDX, IDC_EDIT_aimZwRate, m_txtAimZwRate);
	DDX_Text(pDX, IDC_EDIT_cj, m_txtCj);
	DDX_Text(pDX, IDC_EDIT_ds, m_txtDs);
	DDX_Text(pDX, IDC_EDIT_fyDeg, m_txtFyDeg);
	DDX_Text(pDX, IDC_EDIT_fyRPV, m_txtFyRPV);
	DDX_Text(pDX, IDC_EDIT_gd, m_txtGd);
	DDX_Text(pDX, IDC_EDIT_gdRPV, m_txtGdRPV);
	DDX_Text(pDX, IDC_EDIT_GPSgd, m_txtGPSgd);
	DDX_Text(pDX, IDC_EDIT_hx, m_txtHx);
	DDX_Text(pDX, IDC_EDIT_hxx, m_txthxx);
	DDX_Text(pDX, IDC_EDIT_jmb, m_txtJmb);
	DDX_Text(pDX, IDC_EDIT_ks, m_txtKs);
	DDX_Text(pDX, IDC_EDIT_ksRPV, m_txtKsRPV);
	DDX_Text(pDX, IDC_EDIT_MaxYj, m_txtMaxYj);
	DDX_Text(pDX, IDC_EDIT_maxZwRate, m_txtMaxZwRate);
	DDX_Text(pDX, IDC_EDIT_MidYj, m_txtMidYj);
	DDX_Text(pDX, IDC_EDIT_PIDModel, m_txtPIDModel);
	DDX_Text(pDX, IDC_EDIT_pxc, m_txtPxc);
	DDX_Text(pDX, IDC_EDIT_zwRate, m_txtZwRate);
	DDX_Text(pDX, IDC_EDIT_zwRPV, m_txtZwRPV);
	DDX_Control(pDX, IDC_TCHART_PID, m_Chart_PID);
	DDX_Text(pDX, IDC_EDIT_fy_gzDeg, m_txtFyGzDeg);
	DDX_Text(pDX, IDC_EDIT_CtrlModel, m_txtCtrlModel);
	DDX_Check(pDX, IDC_CHECK_FySwitch, m_check_FySwitch);
	DDX_Check(pDX, IDC_CHECK_GdSwitch, m_check_GdSwitch);
	DDX_Check(pDX, IDC_CHECK_GPSDhSwitch, m_check_GPSDhSwitch);
	DDX_Check(pDX, IDC_CHECK_GzSwitch, m_check_GzSwitch);
	DDX_Check(pDX, IDC_CHECK_KsSwitch, m_check_KsSwitch);
	DDX_Check(pDX, IDC_CHECK_KsToYm, m_check_KsToYm);
	DDX_Check(pDX, IDC_CHECK_PhxzSwitch, m_check_PhxzSwitch);
	DDX_Check(pDX, IDC_CHECK_ZwbzSwitch, m_check_ZwbzSwitch);
	DDX_Check(pDX, IDC_CHECK_ZwSwitch, m_check_ZwSwitch);
	DDX_Text(pDX, IDC_EDIT_MinYj, m_txtMinYJ);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPIDAdjDlg, CDialog)
	//{{AFX_MSG_MAP(CPIDAdjDlg)
	ON_BN_CLICKED(IDC_BTN_GETPIDDATA, OnBtnGetpiddata)
	ON_WM_PAINT()
	ON_WM_DRAWITEM()
	ON_BN_CLICKED(IDC_BTN_SendData, OnBTNSendData)
	ON_CBN_SELENDOK(IDC_COMBO_SelectCH, OnSelendokCOMBOSelectCH)
	ON_BN_CLICKED(IDC_BTN_SendFyRPV, OnBTNSendFyRPV)
	ON_BN_CLICKED(IDC_BTN_SendGdRPV, OnBTNSendGdRPV)
	ON_BN_CLICKED(IDC_BTN_SendKsRPV, OnBTNSendKsRPV)
	ON_BN_CLICKED(IDC_BTN_SendMaxZwRate, OnBTNSendMaxZwRate)
	ON_BN_CLICKED(IDC_BTN_SendYjData, OnBTNSendYjData)
	ON_BN_CLICKED(IDC_BTN_SendZwRPV, OnBTNSendZwRPV)
	ON_BN_CLICKED(IDC_BTN_GetYjData, OnBTNGetYjData)
	ON_BN_CLICKED(IDC_BTN_OpenAllCh, OnBTNOpenAllCh)
	ON_WM_DESTROY()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CHECK_FySwitch, OnCHECKFySwitch)
	ON_BN_CLICKED(IDC_CHECK_KsToYm, OnCHECKKsToYm)
	ON_BN_CLICKED(IDC_CHECK_GdSwitch, OnCHECKFySwitch)
	ON_BN_CLICKED(IDC_CHECK_GPSDhSwitch, OnCHECKFySwitch)
	ON_BN_CLICKED(IDC_CHECK_GzSwitch, OnCHECKFySwitch)
	ON_BN_CLICKED(IDC_CHECK_KsSwitch, OnCHECKFySwitch)
	ON_BN_CLICKED(IDC_CHECK_PhxzSwitch, OnCHECKFySwitch)
	ON_BN_CLICKED(IDC_CHECK_ZwbzSwitch, OnCHECKFySwitch)
	ON_BN_CLICKED(IDC_CHECK_ZwSwitch, OnCHECKFySwitch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPIDAdjDlg message handlers
//获取PID数据  按钮单击事件
void CPIDAdjDlg::OnBtnGetpiddata() 
{
	cGStationDlg->SendPacket(m_Msg_PIDData.GetRequestPacket());

}


void CPIDAdjDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// Do not call CDialog::OnPaint() for painting messages
}

void CPIDAdjDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

// 更新 PID调整窗口中 的PID参数
void CPIDAdjDlg::UpDlgPIDData()
{
	
	m_txtBP = m_Msg_PIDData.m_BP;
	m_txtDh_D = m_Msg_PIDData.m_dh_D;
	m_txtDH_I = m_Msg_PIDData.m_dh_I;
	m_txtDh_P = m_Msg_PIDData.m_dh_P;
	m_txtFxd_D = m_Msg_PIDData.m_fxd_D;
	m_txtFxd_I = m_Msg_PIDData.m_fxd_I;
	m_txtFxd_P = m_Msg_PIDData.m_fxd_P;
	m_txtFy_D = m_Msg_PIDData.m_fy_D;
	m_txtFy_I = m_Msg_PIDData.m_fy_I;
	m_txtFy_P = m_Msg_PIDData.m_fy_P;
	m_txtGdAgl_D = m_Msg_PIDData.m_gd_agl_D;
	m_txtGdAgl_I = m_Msg_PIDData.m_gd_agl_I;
	m_txtGuAgl_P = m_Msg_PIDData.m_gd_agl_P;
	m_txtGdQg_D = m_Msg_PIDData.m_gd_qg_D;
	m_txtGdQg_I = m_Msg_PIDData.m_gd_qg_I;
	m_txtGz_D = m_Msg_PIDData.m_gz_D;
	m_txtGdQg_P = m_Msg_PIDData.m_gd_qg_P;
	m_txtGz_I = m_Msg_PIDData.m_gz_I;
	m_txtGz_P = m_Msg_PIDData.m_gz_P;
	m_txtKsKf_D = m_Msg_PIDData.m_ks_kf_D;
	m_txtKsKf_I = m_Msg_PIDData.m_ks_kf_I;
	m_txtKsKf_P = m_Msg_PIDData.m_ks_kf_P;
	m_txtKsKy_D = m_Msg_PIDData.m_ks_ky_D;
	m_txtKsKy_I = m_Msg_PIDData.m_ks_ky_I;
	m_txtKsKy_P = m_Msg_PIDData.m_ks_ky_P;
	m_txtPhxz_D = m_Msg_PIDData.m_phxz_D;
	m_txtPhxz_I = m_Msg_PIDData.m_phxz_I;
	m_txtPhxz_P = m_Msg_PIDData.m_phxz_P;
	m_txtTP = m_Msg_PIDData.m_TP;
	m_txtVP = m_Msg_PIDData.m_VP;
	UpdateData(false);

	m_btnSendData.EnableWindow(true);
}

// 发送参数 按钮单击事件
void CPIDAdjDlg::OnBTNSendData()
{
	UpdateData();
	m_Msg_PIDData.m_BP = m_txtBP;

	m_Msg_PIDData.m_dh_D = m_txtDh_D;
	m_Msg_PIDData.m_dh_I = m_txtDH_I;
	m_Msg_PIDData.m_dh_P = m_txtDh_P;

	m_Msg_PIDData.m_fxd_D = m_txtFxd_D;
	m_Msg_PIDData.m_fxd_I = m_txtFxd_I;
	m_Msg_PIDData.m_fxd_P = m_txtFxd_P;

	m_Msg_PIDData.m_fy_D = m_txtFy_D;
	m_Msg_PIDData.m_fy_I = m_txtFy_I;
	m_Msg_PIDData.m_fy_P = m_txtFy_P;

	m_Msg_PIDData.m_gd_agl_D = m_txtGdAgl_D;
	m_Msg_PIDData.m_gd_agl_I = m_txtGdAgl_I;
	m_Msg_PIDData.m_gd_agl_P = m_txtGuAgl_P;

	m_Msg_PIDData.m_gd_qg_D = m_txtGdQg_D;
	m_Msg_PIDData.m_gd_qg_I = m_txtGdQg_I;
	m_Msg_PIDData.m_gd_qg_P = m_txtGdQg_P;

	m_Msg_PIDData.m_gz_D = m_txtGz_D;
	m_Msg_PIDData.m_gz_I = m_txtGz_I;
	m_Msg_PIDData.m_gz_P = m_txtGz_P;

	m_Msg_PIDData.m_ks_kf_D = m_txtKsKf_D;
	m_Msg_PIDData.m_ks_kf_I = m_txtKsKf_I;
	m_Msg_PIDData.m_ks_kf_P = m_txtKsKf_P;

	m_Msg_PIDData.m_ks_ky_D = m_txtKsKy_D;
	m_Msg_PIDData.m_ks_ky_I = m_txtKsKy_I;
	m_Msg_PIDData.m_ks_ky_P = m_txtKsKy_P;

	m_Msg_PIDData.m_phxz_D = m_txtPhxz_D;
	m_Msg_PIDData.m_phxz_I = m_txtPhxz_I;
    m_Msg_PIDData.m_phxz_P = m_txtPhxz_P;

	m_Msg_PIDData.m_TP = m_txtTP;
	m_Msg_PIDData.m_VP = m_txtVP;

	 cGStationDlg->SendPacket(m_Msg_PIDData.GetUpDataPacket());
}

// 更新PID调整窗口中 PID调整所需参数
void CPIDAdjDlg::UpDlgPIDAdjData()
{
	m_txtFyDeg = m_Msg_PIDAdjustData.m_fPitch;
	m_txtAimFyDeg = m_Msg_PIDAdjustData.m_fAimPitch;
	m_txtKs = m_Msg_PIDAdjustData.m_nAirspd;
	m_txtAimKs = m_Msg_PIDAdjustData.m_nDesired_Airspd;

	m_txtGd = m_Msg_PIDAdjustData.m_nAiralt;
	m_txtAimGd = m_Msg_PIDAdjustData.m_nDesired_Airalt;
	m_txtGPSgd = m_Msg_PIDAdjustData.m_GPSdata.m_fGPSalt;
	m_txtZwRate = (float)(m_Msg_PIDAdjustData.m_nDirection/10.0);
	m_txtAimZwRate =  (float)(m_Msg_PIDAdjustData.m_nAimSwerveRate/10.0);
	m_txtFyGzDeg = m_Msg_PIDAdjustData.m_fRoll;

	switch (m_Msg_PIDAdjustData.m_nContralmodel)
	{
	case 0: m_txtCtrlModel = "UAV";
		break;
	case 1: m_txtCtrlModel = "RC";
		break;
	case 2: m_txtCtrlModel = "RPV";
		break;
	case 3: m_txtCtrlModel = "CPV";
		break;
	default : m_txtCtrlModel = "UnKnown";
		break;
	}
	
	m_txtPIDModel = m_Msg_PIDAdjustData.m_nLoopsEnable;
	short temp = m_txtPIDModel;

	m_check_ZwSwitch = temp & 0x01; //0000 0001->0x01 
	m_check_KsSwitch = (temp >> 1) & 0x01; 
	m_check_FySwitch = (temp >> 2) & 0x01;
	m_check_GdSwitch = (temp >> 3) & 0x01;
	m_check_GzSwitch = (temp >> 4) & 0x01;
	m_check_GPSDhSwitch = (temp >> 5) & 0x01;
	m_check_ZwbzSwitch = (temp >> 6) & 0x01;
	m_check_PhxzSwitch = (temp >> 7) & 0x01;

	SetEditText(((CEdit*)(this->GetDlgItem(IDC_EDIT_FySwitch))),m_check_FySwitch);
	SetEditText(((CEdit*)(this->GetDlgItem(IDC_EDIT_ZwbcSwitch))),m_check_FySwitch);
	SetEditText(((CEdit*)(this->GetDlgItem(IDC_EDIT_KsSwitch))),m_check_KsSwitch);
	SetEditText(((CEdit*)(this->GetDlgItem(IDC_EDIT_GdSwitch))),m_check_GdSwitch);
	SetEditText(((CEdit*)(this->GetDlgItem(IDC_EDIT_ZwSwitch))),m_check_ZwSwitch);
	SetEditText(((CEdit*)(this->GetDlgItem(IDC_EDIT_GzSwitch))),m_check_GzSwitch);
	SetEditText(((CEdit*)(this->GetDlgItem(IDC_EDIT_GPSDhSwitch))),m_check_GPSDhSwitch);
	SetEditText(((CEdit*)(this->GetDlgItem(IDC_EDIT_PhxzSwitch))),m_check_PhxzSwitch);

	UpdateData(false);

	((CEdit*)(this->GetDlgItem(IDC_EDIT_FySwitch)))->Invalidate();
	((CEdit*)(this->GetDlgItem(IDC_EDIT_ZwbcSwitch)))->Invalidate();
	((CEdit*)(this->GetDlgItem(IDC_EDIT_KsSwitch)))->Invalidate();
	((CEdit*)(this->GetDlgItem(IDC_EDIT_GdSwitch)))->Invalidate();
	((CEdit*)(this->GetDlgItem(IDC_EDIT_ZwSwitch)))->Invalidate();
	((CEdit*)(this->GetDlgItem(IDC_EDIT_GzSwitch)))->Invalidate();
	((CEdit*)(this->GetDlgItem(IDC_EDIT_GPSDhSwitch)))->Invalidate();
	((CEdit*)(this->GetDlgItem(IDC_EDIT_PhxzSwitch)))->Invalidate();
	
}

// 更新PID调整窗口中的  迎角数据
void CPIDAdjDlg::UpYJData()
{
	m_txtMaxYj = m_Msg_OtherPIDAdjData.m_YJ_maxDeg;
	m_txtMidYj = m_Msg_OtherPIDAdjData.m_YJ_midDeg;
	m_txtMidYj = m_Msg_OtherPIDAdjData.m_YJ_minDeg;

	UpdateData(false);
}

//设置通道开关文字及背景色
void CPIDAdjDlg::SetEditBC(CEdit* editCtrl,BOOL isNo)
{
	if (isNo)
	{
		m_colorEditBK = RGB(0,255,0);
	}
	else
	{
		m_colorEditBK = RGB(255,255,0);
	}
}
//设置通道开关文字
void CPIDAdjDlg::SetEditText(CEdit* editCtrl,BOOL isNo)
{
	if (isNo)
	{
		editCtrl->SetWindowText("NO");
	}
	else
	{
		editCtrl->SetWindowText("OFF");
	}
}

//更新图表控件数据
void CPIDAdjDlg::UpChartData()
{
	float tempAim,temp1;

	tempAim = 0;
	temp1 = 0;

	if (m_IsRefresh)
	{
		switch (m_combo_SelectIndex)
		{
			//俯仰通道
			case 0:  tempAim = m_Msg_PIDAdjustData.m_fAimPitch; temp1 = m_Msg_PIDAdjustData.m_fPitch;
				break;
			//空速通道
			case 1:	 tempAim = (float)m_Msg_PIDAdjustData.m_nDesired_Airspd; temp1 = (float)m_Msg_PIDAdjustData.m_nAirspd;
				break;
			//高度通道
			case 2:  tempAim = (float)m_Msg_PIDAdjustData.m_nDesired_Airalt; temp1 = (float)m_Msg_PIDAdjustData.m_nAiralt;
				break;
			//转弯通道
			case 3:  tempAim = (float)(m_Msg_PIDAdjustData.m_nAimSwerveRate / 10.0); temp1 = (float)(m_Msg_PIDAdjustData.m_nDirection / 10.0);
				break;
			//副翼通道
			case 4:  tempAim = 0.0; temp1 = m_Msg_PIDAdjustData.m_fRoll;
				break;
			//导航通道
			case 5:  
				break;
			default :	break;
		}
		
		if (m_ChartDataCount > m_chartShowPointCount)
		{
			m_Chart_PID.Series(0).AddXY(m_ChartDataCount,tempAim,NULL,1);
			m_Chart_PID.Series(1).AddXY(m_ChartDataCount,temp1,NULL,1);

			m_Chart_PID.GetAxis().GetBottom().SetMinMax(m_ChartDataCount - m_chartShowPointCount-1,m_ChartDataCount-1);
			m_Chart_PID.GetAxis().GetBottom().Scroll(1.0,false);
		}
		else
		{
			m_Chart_PID.Series(0).AddXY(m_ChartDataCount,tempAim,NULL,1);
			m_Chart_PID.Series(1).AddXY(m_ChartDataCount,temp1,NULL,1);
		}
		m_ChartDataCount++;
	}
}

// 下拉框选择完毕事件 即通道切换事件
void CPIDAdjDlg::OnSelendokCOMBOSelectCH() 
{
	m_IsRefresh = true;
	m_combo_SelectIndex = m_combo_SelectCH.GetCurSel();
	switch (m_combo_SelectIndex)
	{
		case 0: m_Chart_PID.GetHeader().GetText().SetItem(0, COleVariant("俯仰通道"));
			m_Chart_PID.GetAxis().GetLeft().SetMinMax(-40,40);
			break;
		case 1:	 m_Chart_PID.GetHeader().GetText().SetItem(0, COleVariant("空速通道"));
			m_Chart_PID.GetAxis().GetLeft().SetMinMax(-40,40);
			break;
		case 2: m_Chart_PID.GetHeader().GetText().SetItem(0, COleVariant("高度通道"));
			m_Chart_PID.GetAxis().GetLeft().SetMinMax(0,1500);
			break;
		case 3: m_Chart_PID.GetHeader().GetText().SetItem(0, COleVariant("转弯通道"));
			m_Chart_PID.GetAxis().GetLeft().SetMinMax(-70,70);
			break;
		case 4: m_Chart_PID.GetHeader().GetText().SetItem(0, COleVariant("副翼通道"));
			m_Chart_PID.GetAxis().GetLeft().SetMinMax(-50,50);
			break;
		case 5: m_Chart_PID.GetHeader().GetText().SetItem(0, COleVariant("导航通道"));
			m_Chart_PID.GetAxis().GetLeft().SetMinMax(0,400);
			break;
		default :	m_Chart_PID.GetHeader().GetText().SetItem(0, COleVariant("请选择通道")); m_IsRefresh = false;
			break;
	}
	
	// 清除之前的线条
	m_Chart_PID.Series(0).Clear();
	m_Chart_PID.Series(1).Clear();
	m_Chart_PID.GetAxis().GetBottom().SetMinMax(0,m_chartShowPointCount);
	m_ChartDataCount = 0;

	// 发送获取PID所需参数请求包
    if (m_IsRefresh) cGStationDlg->SendPacket(m_Msg_PIDAdjustData.GetRequestPacket());
}

//发送俯仰RPV值  按钮事件
void CPIDAdjDlg::OnBTNSendFyRPV() 
{
	UpdateData();
	cGStationDlg->SendPacket(m_Msg_SetRPV.GetSetAimDegPacket(m_txtFyRPV));
	
}

// 发送高度RPV值  按钮事件
void CPIDAdjDlg::OnBTNSendGdRPV() 
{
	UpdateData();
	cGStationDlg->SendPacket(m_Msg_SetRPV.GetSetAimAltitudePacket(m_txtGdRPV));
}

// 发送空速RPV值  按钮事件
void CPIDAdjDlg::OnBTNSendKsRPV() 
{
	UpdateData();
	cGStationDlg->SendPacket(m_Msg_SetRPV.GetSetAimAirSpeedPacket(m_txtKsRPV));
}

// 发送转弯RPV值  按钮事件
void CPIDAdjDlg::OnBTNSendZwRPV() 
{
	UpdateData();
	cGStationDlg->SendPacket(m_Msg_SetRPV.GetSetAimSweiveRatePacket(m_txtZwRPV));
}

// 发送转弯速率最大值 按钮事件
void CPIDAdjDlg::OnBTNSendMaxZwRate() 
{
	UpdateData();
	cGStationDlg->SendPacket(m_Msg_OtherPIDAdjData.GetSetMaxZwRateDataPacket(m_txtMaxZwRate));
}

// 获取迎角数据  按钮事件
void CPIDAdjDlg::OnBTNGetYjData() 
{
	cGStationDlg->SendPacket(m_Msg_OtherPIDAdjData.GetRequestYJDataPacket());
}

// 发送迎角数据  按钮事件
void CPIDAdjDlg::OnBTNSendYjData() 
{
	UpdateData();
	cGStationDlg->SendPacket(m_Msg_OtherPIDAdjData.GetSetYJDataPacket(m_txtMaxYj,m_txtMidYj,m_txtMinYJ));
}

// 打开所有通道 按钮事件
void CPIDAdjDlg::OnBTNOpenAllCh() 
{
	cGStationDlg->SendPacket(m_Msg_PIDAdjustData.GetSetEnableCHPacket(0xFF));
}

void CPIDAdjDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	delete m_pEditBkBrush;
	
}

HBRUSH CPIDAdjDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	switch (nCtlColor) {
		
	case CTLCOLOR_EDIT:
	case CTLCOLOR_MSGBOX:
		if(!m_IsRefresh) return hbr;
		switch (pWnd->GetDlgCtrlID())
		{
		case IDC_EDIT_FySwitch:SetEditBC((CEdit*)pWnd->GetDlgItem(IDC_EDIT_FySwitch),m_check_FySwitch);
			break;
		case IDC_EDIT_ZwbcSwitch:SetEditBC((CEdit*)pWnd->GetDlgItem(IDC_EDIT_ZwbcSwitch),m_check_ZwbzSwitch);
			break;
		case IDC_EDIT_KsSwitch:SetEditBC((CEdit*)pWnd->GetDlgItem(IDC_EDIT_KsSwitch),m_check_KsSwitch);
			break;
		case IDC_EDIT_GdSwitch:SetEditBC((CEdit*)pWnd->GetDlgItem(IDC_EDIT_GdSwitch),m_check_GdSwitch);
			break;
		case IDC_EDIT_ZwSwitch:SetEditBC((CEdit*)pWnd->GetDlgItem(IDC_EDIT_ZwSwitch),m_check_ZwSwitch);
			break;
		case IDC_EDIT_GzSwitch:SetEditBC((CEdit*)pWnd->GetDlgItem(IDC_EDIT_GzSwitch),m_check_GzSwitch);
			break;
		case IDC_EDIT_GPSDhSwitch:SetEditBC((CEdit*)pWnd->GetDlgItem(IDC_EDIT_GPSDhSwitch),m_check_GzSwitch);
			break;
		case IDC_EDIT_PhxzSwitch:SetEditBC((CEdit*)(pWnd->GetDlgItem(IDC_EDIT_PhxzSwitch)),m_check_PhxzSwitch);
			break;
		default:  return hbr;
		}
		pDC->SetTextColor(m_colorEditText);
		pDC->SetBkColor(m_colorEditBK);

		return (HBRUSH)(m_pEditBkBrush->GetSafeHandle());
		
	default:
	return hbr;
	}
}

//通道开关单击事件
void CPIDAdjDlg::OnCHECKFySwitch() 
{
	int data;
	data = 0x00;
	UpdateData();
	CString str;
	str.Format("%d",(int)m_check_FySwitch);
	MessageBox(str);
	data |= (m_check_ZwSwitch?0x01:0x00);
	data |= (m_check_KsSwitch?0x01:0x00)<<1;
	data |= (m_check_FySwitch?0x01:0x00)<<2;
	data |= (m_check_GdSwitch?0x01:0x00)<<3;
	data |= (m_check_GzSwitch?0x01:0x00)<<4;
	data |= (m_check_GPSDhSwitch?0x01:0x00)<<5;
	data |= (m_check_ZwbzSwitch?0x01:0x00)<<6;
	data |= (m_check_PhxzSwitch?0x01:0x00)<<7;

	cGStationDlg->SendPacket(m_Msg_PIDAdjustData.GetSetEnableCHPacket(data));
}

//空速控制油门 事件
void CPIDAdjDlg::OnCHECKKsToYm() 
{
	UpdateData();
	cGStationDlg->SendPacket(m_Msg_OtherPIDAdjData.GetSetAirspdCtrlmodelDataPacket((m_check_KsToYm?1:0)));
}

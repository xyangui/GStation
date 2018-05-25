// InstrumentCircleCtl.cpp : Implementation of the CInstrumentCircleCtrl ActiveX Control class.

#include "stdafx.h"
#include "InstrumentCircle.h"
#include "InstrumentCircleCtl.h"
#include "InstrumentCirclePpg.h"
#include "math.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define CONVERTTORAD 3.1415926/180

IMPLEMENT_DYNCREATE(CInstrumentCircleCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CInstrumentCircleCtrl, COleControl)
	//{{AFX_MSG_MAP(CInstrumentCircleCtrl)
	ON_WM_CREATE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CInstrumentCircleCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CInstrumentCircleCtrl)
	DISP_PROPERTY_NOTIFY(CInstrumentCircleCtrl, "MinDeg", m_minDeg, OnMinDegChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CInstrumentCircleCtrl, "MaxDeg", m_maxDeg, OnMaxDegChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CInstrumentCircleCtrl, "MinValue", m_minValue, OnMinValueChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CInstrumentCircleCtrl, "MaxValue", m_maxValue, OnMaxValueChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CInstrumentCircleCtrl, "DivCount", m_divCount, OnDivCountChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CInstrumentCircleCtrl, "RealValue", m_realValue, OnRealValueChanged, VT_R8)
	DISP_PROPERTY_NOTIFY(CInstrumentCircleCtrl, "AimValue", m_aimValue, OnAimValueChanged, VT_R8)
	DISP_PROPERTY_NOTIFY(CInstrumentCircleCtrl, "NumberFont", m_numberFont, OnNumberFontChanged, VT_R8)
	DISP_PROPERTY_NOTIFY(CInstrumentCircleCtrl, "LabFont", m_labFont, OnLabFontChanged, VT_R8)
	DISP_PROPERTY_NOTIFY(CInstrumentCircleCtrl, "LabX", m_labX, OnLabXChanged, VT_I4)
	DISP_PROPERTY_NOTIFY(CInstrumentCircleCtrl, "LabY", m_labY, OnLabYChanged, VT_I4)
	DISP_PROPERTY_NOTIFY(CInstrumentCircleCtrl, "LabText", m_labText, OnLabTextChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CInstrumentCircleCtrl, "LabTextLine2", m_labTextLine2, OnLabTextLine2Changed, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CInstrumentCircleCtrl, "LabX2", m_labX2, OnLabX2Changed, VT_I4)
	DISP_PROPERTY_NOTIFY(CInstrumentCircleCtrl, "LabY2", m_labY2, OnLabY2Changed, VT_I4)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CInstrumentCircleCtrl, COleControl)
	//{{AFX_EVENT_MAP(CInstrumentCircleCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CInstrumentCircleCtrl, 1)
	PROPPAGEID(CInstrumentCirclePropPage::guid)
END_PROPPAGEIDS(CInstrumentCircleCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CInstrumentCircleCtrl, "INSTRUMENTCIRCLE.InstrumentCircleCtrl.1",
	0x74de98ee, 0xde61, 0x46c1, 0xaa, 0x56, 0x96, 0x16, 0xc1, 0xe4, 0x9e, 0x90)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CInstrumentCircleCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DInstrumentCircle =
		{ 0x14e2fee7, 0x6904, 0x4433, { 0x84, 0x72, 0xbe, 0x7, 0xea, 0xf2, 0xf7, 0xb3 } };
const IID BASED_CODE IID_DInstrumentCircleEvents =
		{ 0x3df0103c, 0x7b57, 0x4e36, { 0xa2, 0x71, 0xf0, 0xd3, 0x6, 0xe4, 0x5d, 0xd1 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwInstrumentCircleOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CInstrumentCircleCtrl, IDS_INSTRUMENTCIRCLE, _dwInstrumentCircleOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CInstrumentCircleCtrl::CInstrumentCircleCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CInstrumentCircleCtrl

BOOL CInstrumentCircleCtrl::CInstrumentCircleCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_INSTRUMENTCIRCLE,
			IDB_INSTRUMENTCIRCLE,
			afxRegApartmentThreading,
			_dwInstrumentCircleOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CInstrumentCircleCtrl::CInstrumentCircleCtrl - Constructor

CInstrumentCircleCtrl::CInstrumentCircleCtrl()
{
	InitializeIIDs(&IID_DInstrumentCircle, &IID_DInstrumentCircleEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CInstrumentCircleCtrl::~CInstrumentCircleCtrl - Destructor

CInstrumentCircleCtrl::~CInstrumentCircleCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CInstrumentCircleCtrl::OnDraw - Drawing function

void CInstrumentCircleCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	

	CPen pen;
	CPen *oldPen;

	CBrush brush;
	CBrush *oldBrush;

	CPoint centerPoint;
	CPoint linePoint1,linePoint2;
	CPoint markPoint;
	double markR;
	double r;
	double lineR1,lineR2;
	double lineLength;
	double deg;
	deg = 0;//1

	lineLength = (1.0/20.0)*(rcBounds.Width()/2.0);
	r = rcBounds.Width() < rcBounds.Height()?rcBounds.Width():rcBounds.Height();
	r = (4.5/5.0)*(r/2.0);

	
	centerPoint.x = rcBounds.CenterPoint().x;
	centerPoint.y = rcBounds.CenterPoint().y;

	//最小值、最大值
	double minValue,maxValue;
	minValue = m_minValue;//2
	maxValue = m_maxValue;//3
	//最小度数、最大度数
	double minDeg,maxDeg;
	minDeg = m_minDeg;//4
	maxDeg = m_maxDeg;//5
	//每一度对应的值
	double valuePerDeg = (maxValue - minValue)/(maxDeg - minDeg);
	//等份数
	double divValue;
	divValue = m_divCount;//6
	//每一等分对应的值即每一小格的值
	double divValuePer = (maxValue - minValue)/divValue;
	//每一等分对应的度数即每一小格的度数
	double divDegPer = (maxDeg - minDeg)/divValue;

	int i=0;
	CString str;
	int strcount;
	int fontHeight,fontWidth;
	TEXTMETRIC tm;
	pdc->GetTextMetrics(&tm);
	fontHeight = tm.tmHeight;
	fontWidth = tm.tmAveCharWidth;

	//创建字体
	CFont font;
	CFont *pOldFont;
	int fontSize = (int)(m_numberFont * lineLength);
	font.CreateFont(fontSize, 0, 0, 0, 400, 
		FALSE, FALSE, 0, ANSI_CHARSET,
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, 
		DEFAULT_PITCH|FF_SWISS, "Arial");
	pOldFont = pdc->SelectObject(&font);//选择字体并返回原来的字体指针
	pdc->SetBkMode(TRANSPARENT);//设置透明背景
	pdc->SetTextColor(RGB(255,255,255));//设置字体颜色
	pdc->SetTextAlign(TA_CENTER | TA_CENTER);//设置对齐方式


	CRect bg;
	int l;
	l = rcBounds.Width()>rcBounds.Height()?rcBounds.Height():rcBounds.Width();
	bg.TopLeft().x = rcBounds.CenterPoint().x - l/2;
	bg.TopLeft().y = rcBounds.CenterPoint().y - l/2;
	bg.BottomRight().x = rcBounds.CenterPoint().x + l/2;
	bg.BottomRight().y = rcBounds.CenterPoint().y + l/2;
	
	//画圆形表盘背景(底色即黑色圆)
	pen.DeleteObject();
	pen.CreatePen(PS_SOLID,0,RGB(236,233,216));
	oldPen = pdc->SelectObject(&pen);
	brush.CreateSolidBrush(RGB(236,233,216));
	oldBrush = pdc->SelectObject(&brush);
	pdc->Rectangle(rcBounds);

	brush.DeleteObject();
	brush.CreateSolidBrush(RGB(0,0,0));
	pdc->SelectObject(&brush);
	pdc->Ellipse(bg);
	pdc->SelectObject(oldBrush);

	/*oldPen = pdc->SelectObject(&pen);*/
	for(i = 0; i <= divValue; i++)
	{
		//画刻线

		deg = minDeg + divDegPer*i;

		lineR1 = r;
	
		switch (i % 10)
		{
		case 0: lineR2 = r - 2*lineLength;
			pen.DeleteObject();
			pen.CreatePen(PS_SOLID,3,RGB(255,255,255));
			break;
		case 5: lineR2 = r - 1.5*lineLength;
			pen.DeleteObject();
			pen.CreatePen(PS_SOLID,2,RGB(255,255,255));
			break;
		default: lineR2 = r - lineLength;
			pen.DeleteObject();
			pen.CreatePen(PS_SOLID,1,RGB(255,255,255));
			break;
		}
		pdc->SelectObject(&pen);

		linePoint1.x = centerPoint.x - lineR1*cos(deg*CONVERTTORAD);
		linePoint1.y = centerPoint.y - lineR1*sin(deg*CONVERTTORAD);

		linePoint2.x = centerPoint.x - lineR2*cos(deg*CONVERTTORAD);
		linePoint2.y = centerPoint.y - lineR2*sin(deg*CONVERTTORAD);

		pdc->MoveTo(linePoint1);
		pdc->LineTo(linePoint2);
		
		if (i % 10 == 0)
		{
			str.Format(_T("%d"),((int)(minValue + divValuePer*i)));
			strcount = str.GetLength();
			markR = lineR2 - strcount*fontSize/3.4;

			markPoint.x = centerPoint.x - markR*cos(deg*CONVERTTORAD);
		    markPoint.y = centerPoint.y - markR*sin(deg*CONVERTTORAD);

			pdc->TextOut(markPoint.x ,markPoint.y - fontSize/2.4,str);
		}
	}


	//画指针

	//目标指针
	CPoint aimPointer[3];
	CRect aimCircle;
	double pointerR;
	double aimDegValue;
	
	aimDegValue = m_aimValue;//7
	
	aimDegValue = minDeg + aimDegValue/valuePerDeg;
	
	pointerR = r;

	brush.DeleteObject();
	brush.CreateSolidBrush(RGB(255,0,0));
	pdc->SelectObject(&brush);

	pen.DeleteObject();
	pen.CreatePen(PS_SOLID,1,RGB(255,0,0));
	pdc->SelectObject(&pen);
	
	aimCircle = CRect(centerPoint.x-1.5*lineLength-2 ,centerPoint.y-1.5*lineLength-2,centerPoint.x+1.5*lineLength+2,centerPoint.y+1.5*lineLength+2);
	pdc->Ellipse(aimCircle);
	
	aimPointer[0].x = centerPoint.x - pointerR*cos(aimDegValue*CONVERTTORAD);
	aimPointer[0].y = centerPoint.y - pointerR*sin(aimDegValue*CONVERTTORAD);
	
	aimPointer[1].x = centerPoint.x - 1.5*lineLength*cos((aimDegValue+30)*CONVERTTORAD);
	aimPointer[1].y = centerPoint.y - 1.5*lineLength*sin((aimDegValue+30)*CONVERTTORAD);
	
	aimPointer[2].x = centerPoint.x - 1.5*lineLength*cos((aimDegValue-30)*CONVERTTORAD);
	aimPointer[2].y = centerPoint.y - 1.5*lineLength*sin((aimDegValue-30)*CONVERTTORAD);
	
    pdc->Polygon(aimPointer,3);
	//实际指针





	CPoint pointer[3];
	CRect circle;
	double degValue;
	
	degValue = m_realValue;//8
	
	degValue = minDeg + degValue/valuePerDeg;
	
	brush.DeleteObject();
	brush.CreateSolidBrush(RGB(255,255,255));
	pdc->SelectObject(&brush);

	pen.DeleteObject();
	pen.CreatePen(PS_SOLID,1,RGB(255,255,255));
	pdc->SelectObject(&pen);

	circle = CRect(centerPoint.x-1.5*lineLength ,centerPoint.y-1.5*lineLength,centerPoint.x+1.5*lineLength,centerPoint.y+1.5*lineLength);
	pdc->Ellipse(circle);
	
	pointer[0].x = centerPoint.x - pointerR*cos(degValue*CONVERTTORAD);
	pointer[0].y = centerPoint.y - pointerR*sin(degValue*CONVERTTORAD);
	
	pointer[1].x = centerPoint.x - 1.5*lineLength*cos((degValue+30)*CONVERTTORAD);
	pointer[1].y = centerPoint.y - 1.5*lineLength*sin((degValue+30)*CONVERTTORAD);
	
	pointer[2].x = centerPoint.x - 1.5*lineLength*cos((degValue-30)*CONVERTTORAD);
	pointer[2].y = centerPoint.y - 1.5*lineLength*sin((degValue-30)*CONVERTTORAD);
	
    pdc->Polygon(pointer,3);




	//画文字标签（注释）
	//创建字体
	int labfontSize = (int)(m_labFont * lineLength);
	font.DeleteObject();
	font.CreateFont(labfontSize, 0, 0, 0, 400, 
		FALSE, FALSE, 0, ANSI_CHARSET,
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, 
		DEFAULT_PITCH|FF_SWISS, "Arial");
	pdc->SelectObject(&font);//选择字体并返回原来的字体指针
	pdc->SetBkMode(TRANSPARENT);//设置透明背景
	pdc->SetTextColor(RGB(255,255,255));//设置字体颜色
	pdc->SetTextAlign(TA_CENTER | TA_CENTER);//设置对齐方式
	

	CString labText,labTextLine2;
	labText.Format(m_labText);
	labTextLine2.Format(m_labTextLine2);
	if (m_labX == 0 && m_labY == 0)
	{
		m_labX = centerPoint.x - rcBounds.bottom / 4;
		m_labY = centerPoint.y + 10;
	}
	pdc->TextOut(m_labX,m_labY,labText);
	pdc->TextOut(m_labX2,m_labY2,labTextLine2);

	pdc->SelectObject(oldBrush);
	pdc->SelectObject(oldPen);
	pdc->SelectObject(pOldFont);
}
/////////////////////////////////////////////////////////////////////////////
// CInstrumentCircleCtrl::DoPropExchange - Persistence support

void CInstrumentCircleCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_Short(pPX,"MinDeg",m_minDeg,-40);
	PX_Short(pPX,"MaxDeg",m_maxDeg,220);
	PX_Short(pPX,"MinValue",m_minValue,0);
	PX_Short(pPX,"MaxValue",m_maxValue,12);
	PX_Short(pPX,"DivCount",m_divCount,60);
	PX_Double(pPX,"AimValue",m_aimValue,0);
	PX_Double(pPX,"RealValue",m_realValue,5);
	PX_Double(pPX,"NumberFont",m_numberFont,4.0);
	PX_Double(pPX,"LabFont",m_labFont,4.0);
	PX_Long(pPX,"LabX",m_labX,0);
	PX_Long(pPX,"LabY",m_labY,0);
	PX_String(pPX,"LabText",m_labText,"rpm\nx1000");
	PX_Long(pPX,"LabX2",m_labX2,0);
	PX_Long(pPX,"LabY2",m_labY2,0);
	PX_String(pPX,"LabTextLine2",m_labTextLine2,"rpm1000");
	

}


/////////////////////////////////////////////////////////////////////////////
// CInstrumentCircleCtrl::OnResetState - Reset control to default state

void CInstrumentCircleCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CInstrumentCircleCtrl message handlers


int CInstrumentCircleCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	SetTimer(1,1000,NULL);
	
	return 0;
}

void CInstrumentCircleCtrl::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
//	InvalidateControl();

	COleControl::OnTimer(nIDEvent);
}

void CInstrumentCircleCtrl::OnMinDegChanged() 
{
	// TODO: Add notification handler code
	InvalidateControl();
	SetModifiedFlag();
}

void CInstrumentCircleCtrl::OnMaxDegChanged() 
{
	// TODO: Add notification handler c
	InvalidateControl();

	SetModifiedFlag();
}

void CInstrumentCircleCtrl::OnMinValueChanged() 
{
	// TODO: Add notification handler code
	InvalidateControl();

	SetModifiedFlag();
}

void CInstrumentCircleCtrl::OnMaxValueChanged() 
{
	// TODO: Add notification handler code
	InvalidateControl();

	SetModifiedFlag();
}

void CInstrumentCircleCtrl::OnDivCountChanged() 
{
	// TODO: Add notification handler code
	InvalidateControl();

	SetModifiedFlag();
}

void CInstrumentCircleCtrl::OnRealValueChanged() 
{
	// TODO: Add notification handler code
	InvalidateControl();

	SetModifiedFlag();
}

void CInstrumentCircleCtrl::OnAimValueChanged() 
{
	// TODO: Add notification handler code
	InvalidateControl();

	SetModifiedFlag();
}

void CInstrumentCircleCtrl::OnNumberFontChanged() 
{
	// TODO: Add notification handler code
	InvalidateControl();
	SetModifiedFlag();
}

void CInstrumentCircleCtrl::OnLabFontChanged() 
{
	// TODO: Add notification handler code
	InvalidateControl();
	SetModifiedFlag();
}

void CInstrumentCircleCtrl::OnLabXChanged() 
{
	// TODO: Add notification handler code
	InvalidateControl();
	SetModifiedFlag();
}

void CInstrumentCircleCtrl::OnLabYChanged() 
{
	// TODO: Add notification handler code
	InvalidateControl();
	SetModifiedFlag();
}

void CInstrumentCircleCtrl::OnLabTextChanged() 
{
	// TODO: Add notification handler code
	InvalidateControl();
	SetModifiedFlag();
}

void CInstrumentCircleCtrl::OnLabTextLine2Changed() 
{
	// TODO: Add notification handler code

	InvalidateControl();
	SetModifiedFlag();
}

void CInstrumentCircleCtrl::OnLabX2Changed() 
{
	// TODO: Add notification handler code

	InvalidateControl();
	SetModifiedFlag();
}

void CInstrumentCircleCtrl::OnLabY2Changed() 
{
	// TODO: Add notification handler code

	InvalidateControl();
	SetModifiedFlag();
}

// InstrumentPanelCtl.cpp : Implementation of the CInstrumentPanelCtrl ActiveX Control class.

#include "stdafx.h"
#include "InstrumentPanel.h"
#include "InstrumentPanelCtl.h"
#include "InstrumentPanelPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CInstrumentPanelCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CInstrumentPanelCtrl, COleControl)
	//{{AFX_MSG_MAP(CInstrumentPanelCtrl)
	ON_WM_CREATE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CInstrumentPanelCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CInstrumentPanelCtrl)
	DISP_PROPERTY_NOTIFY(CInstrumentPanelCtrl, "FyDeg", m_fyDeg, OnFyDegChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CInstrumentPanelCtrl, "GzDeg", m_gzDeg, OnGzDegChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CInstrumentPanelCtrl, "Direction", m_direction, OnDirectionChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CInstrumentPanelCtrl, "ApHeight", m_apHeight, OnApHeightChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CInstrumentPanelCtrl, "AimHeight", m_aimHeight, OnAimHeightChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CInstrumentPanelCtrl, "AirSpeed", m_airSpeed, OnAirSpeedChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CInstrumentPanelCtrl, "AimAirSpeed", m_aimAirSpeed, OnAimAirSpeedChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CInstrumentPanelCtrl, "AimDirection", m_aimDirection, OnAimDirectionChanged, VT_I2)
	DISP_PROPERTY_NOTIFY(CInstrumentPanelCtrl, "Heading", m_heading, OnHeadingChanged, VT_R4)
	DISP_FUNCTION(CInstrumentPanelCtrl, "UpDate", UpDate, VT_EMPTY, VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_R4)
	DISP_STOCKPROP_FORECOLOR()
	DISP_STOCKPROP_BACKCOLOR()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CInstrumentPanelCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CInstrumentPanelCtrl, COleControl)
	//{{AFX_EVENT_MAP(CInstrumentPanelCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CInstrumentPanelCtrl, 1)
	PROPPAGEID(CInstrumentPanelPropPage::guid)
END_PROPPAGEIDS(CInstrumentPanelCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CInstrumentPanelCtrl, "INSTRUMENTPANEL.InstrumentPanelCtrl.1",
	0x9542050c, 0x6b62, 0x4250, 0x86, 0x5f, 0x46, 0x57, 0x9f, 0xa5, 0x76, 0xb8)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CInstrumentPanelCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DInstrumentPanel =
		{ 0x9b91c551, 0x22a6, 0x441d, { 0xa6, 0x8a, 0xa4, 0x8b, 0x5e, 0x85, 0xb3, 0xea } };
const IID BASED_CODE IID_DInstrumentPanelEvents =
		{ 0x51c7353b, 0xde07, 0x49a6, { 0xb5, 0x78, 0x1c, 0x91, 0xd8, 0x60, 0x3d, 0xbc } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwInstrumentPanelOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CInstrumentPanelCtrl, IDS_INSTRUMENTPANEL, _dwInstrumentPanelOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CInstrumentPanelCtrl::CInstrumentPanelCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CInstrumentPanelCtrl

BOOL CInstrumentPanelCtrl::CInstrumentPanelCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_INSTRUMENTPANEL,
			IDB_INSTRUMENTPANEL,
			afxRegApartmentThreading,
			_dwInstrumentPanelOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CInstrumentPanelCtrl::CInstrumentPanelCtrl - Constructor

CInstrumentPanelCtrl::CInstrumentPanelCtrl()
{
	InitializeIIDs(&IID_DInstrumentPanel, &IID_DInstrumentPanelEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CInstrumentPanelCtrl::~CInstrumentPanelCtrl - Destructor

CInstrumentPanelCtrl::~CInstrumentPanelCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CInstrumentPanelCtrl::OnDraw - Drawing function


CBrush* CInstrumentPanelCtrl::SetBrush(CBrush* brush,COLORREF colorRef,CDC* pDC)
{
	CBrush* tempBrush;
	brush->DeleteObject();
	brush->CreateSolidBrush(colorRef);
	tempBrush = pDC->SelectObject(brush);
	
	return tempBrush;
}

// ���û���
CPen* CInstrumentPanelCtrl::SetPen(CPen* pen,int penStyle, int width,COLORREF colorRef,CDC* pdc)
{
	CPen* tempPen;

	pen->DeleteObject();
	pen->CreatePen(penStyle, width, colorRef);//PS_SOLID
	tempPen = pdc->SelectObject(pen);

	return tempPen;
}
//�����Ǳ��̰�ɫ�̶��߲���
void CInstrumentPanelCtrl::DrowScaleLine(CDC* pdc,CRect* rect,CPen* pen)
{
	int h,w;//�ο����
	CPoint centerPoint;//���߻��Ʋο����ĵ�
	int scaleLineWidth,ScaleLineHight;//���߿��

    CFont* pFontOld;//���������ָ��
    CFont font;//�����������

	//���ؼ������Ϊ�ο����
	h = rect->Height();
	w = rect->Width();

	//���ÿ��߿��
	scaleLineWidth = w/5;
	ScaleLineHight = h /14;

	//���ؼ����ĵ���Ϊ�Ǳ��̿��߻��Ʋο����ĵ�
	centerPoint = rect->CenterPoint();

	//���û���
	SetPen(pen,PS_SOLID, 1,RGB(255,255,255),pdc);


	int nHeight;//����߶�

	//��������߶�
	nHeight = (int)(ScaleLineHight*0.7);
	
	//��������
	font.CreateFont(nHeight, 0, 0, 0, 400, 
		FALSE, FALSE, 0, ANSI_CHARSET,
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, 
		DEFAULT_PITCH|FF_SWISS, "Arial");
	
	//��������
	pFontOld = pdc->SelectObject(&font);//ѡ�����岢����ԭ��������ָ��
	pdc->SetBkMode(TRANSPARENT);//����͸������
	pdc->SetTextColor(RGB(255,255,255));//�����ı���ɫ
	pdc->SetTextAlign(TA_BOTTOM |TA_LEFT);//���ö��뷽ʽ
	
	/////////////////////// ����ֱ�̶���//////////////////////////
 	CString str;//�ַ���ʱ����
 	int number=0;//��ʱ����

	/////////////////////// �����ο̶���(��ת����)//////////////////////////

	CPoint pm1,pm2;//�̶��߿��Ƶ�
	int r,lenth,tempLenth;//���ΰ뾶���̶��߲ο��������ȣ��̶���ѡ�ó���
	double a,b,db,tempDb;//���νǶȣ������ұ���X��������ļнǣ���С�̶ȼнǣ���ʱ����

	a = 100.0;//�������νǶ�Ϊ100��
	lenth = ScaleLineHight/4;//���ÿ̶��߲ο���������

	b = (90.0 - a/2.0);
	
	db = a/20.0;//������������20����С�ֶ�
	r = (int)(6.2*ScaleLineHight);//�������ΰ뾶

	b -= db;//Ϊ�������ұ߿��߶����õ�

	//�������ο����Ұ벿
	for (int i = 0; i < 11; i++)
	{
		b = b + db;

		tempDb = b*0.017453;

		if (i%2 == 0) tempLenth = 2*lenth;
		else tempLenth = lenth;

		pm1.x = (int)(centerPoint.x + r * cos(tempDb));
		pm1.y = (int)(centerPoint.y  - r * sin(tempDb));

		pm2.x = (int)(centerPoint.x + ((r + tempLenth) * cos(tempDb)));
		pm2.y = (int)(centerPoint.y  - ((r + tempLenth) * sin(tempDb)));

		pdc->MoveTo(pm1);
		pdc->LineTo(pm2);

		pdc->MoveTo(2*centerPoint.x - pm1.x, pm1.y);
		pdc->LineTo(2*centerPoint.x - pm2.x, pm2.y);

		//��ע�̶�ֵ
		if ((i+2)%4 == 0 && i != 10)
		{
			number = (int)(a/2 - i * db);
	 		str.Format(_T("%d"),number);
			pdc->TextOut(pm2.x,pm2.y  ,str);
			pdc->TextOut(2*centerPoint.x - pm2.x - 2*lenth, pm2.y,str);
		}
	}
	////////////////////// ����Բָ�� //////////////////
	// ָ���ĸ���
	CPoint sPoint[4];
	// ָ�����ǵ�1/2�ױ߳�����sh,ָ�볤sr
	int sw,sh,sr;

	int a1,b1;
	double arad;

	// ��ʼ������
	sh = ScaleLineHight / 2;
	sw = sh / 2;
	sr = r - sh;

	// ָ��ƫ�ƽǶ�  ��Ϊ��ת�Ƕ���
	b1 = m_gzDeg;

	a1 = 90 - abs(b1);
	arad = a1 * 0.017453;

	sPoint[0].x = (int)(centerPoint.x - 1.0*r*cos(arad) + 1);
	sPoint[0].y = (int)(centerPoint.y  - 1.0*r*sin(arad));//+ 0.8*ScaleLineHight

	sPoint[2].x = (int)(sPoint[0].x + 1.0*sh * cos(arad));
	sPoint[2].y = (int)(sPoint[0].y + 1.0*sh * sin(arad));

	sPoint[1].x = (int)(sPoint[2].x - 1.0*sw*sin(arad));
	sPoint[1].y = (int)(sPoint[2].y + 1.0*sw*cos(arad));

	sPoint[3].x = (int)(sPoint[2].x + 1.0*sw*sin(arad));
	sPoint[3].y = (int)(sPoint[2].y - 1.0*sw*cos(arad) +1);

	//����ƫ�ƽǶ�Ϊ��ֵʱ������ָ����Ƶ�����
	if (b1 < 0)
	{
		sPoint[0].x = 2*centerPoint.x - sPoint[0].x;
		
		sPoint[2].x = 2*centerPoint.x - sPoint[2].x;
		
		sPoint[1].x = 2*centerPoint.x - sPoint[1].x;
		
		sPoint[3].x = 2*centerPoint.x - sPoint[3].x;
	}

	SetPen(pen,PS_SOLID,1,RGB(255,255,0),pdc);

	/*pdc->Polygon(sPoint, 4);*/
	pdc->MoveTo(sPoint[0]);
	pdc->LineTo(sPoint[1]);

	pdc->MoveTo(sPoint[1]);
	pdc->LineTo(sPoint[3]);

	pdc->MoveTo(sPoint[3]);
	pdc->LineTo(sPoint[0]);

	//////////////////////////// ���Ƹ����̶��ߣ������ƶ���///////////////
	int maxDeg;
	maxDeg = 25;
	// �����ֶȿ�
	double fyDiv;
	fyDiv = ScaleLineHight / 5.0;
	// ������������ƫ����
	int fyCdx,fyCdy;
	fyCdx = 0;
	fyCdy = 0;
	// �̶ȶ�Ӧֵ
	int fyMark;
	// �������ĵ�����
	CPoint fyCenterPoint;
	fyCenterPoint.x = centerPoint.x;
	fyCenterPoint.y = centerPoint.y;
	//fyCenterPoint.Offset(0,0);
	// �����̶��߿��Ƶ�
	CPoint fyLineCtrlPoint[3];

	// ���û���
	SetPen(pen,PS_SOLID, 1,RGB(200,200,200),pdc);
	
	if (b1 > 0)
	{
		arad = 3.141592 - arad;
	}

	for (i = -maxDeg; i <= maxDeg; i++)
	{
		// �������ĵ�ƫ����
		fyCdx = (int)((double)(i*fyDiv) * cos(arad));
		fyCdy = -((int)((double)(i*fyDiv) * sin(arad)));

		fyMark = abs(i + b1);

		if (fyMark % 10 == 0 || fyMark %10 ==5)
		{
			switch (fyMark % 10)
			{
				// ��ʮ�̶� ��
				case 0:
					tempLenth = scaleLineWidth / 2;
					break;
				// ����̶� ��
				case 5:
					tempLenth = scaleLineWidth / 3;
					break;
			}
		
			fyLineCtrlPoint[1].x = fyCenterPoint.x + fyCdx;
			fyLineCtrlPoint[1].y = fyCenterPoint.y + fyCdy;
			
			fyLineCtrlPoint[0].x = (int)(fyLineCtrlPoint[1].x - tempLenth * sin(arad));
			fyLineCtrlPoint[0].y = (int)(fyLineCtrlPoint[1].y - tempLenth * cos(arad));
			
			fyLineCtrlPoint[2].x = (int)(fyLineCtrlPoint[1].x + tempLenth * sin(arad));
			fyLineCtrlPoint[2].y = (int)(fyLineCtrlPoint[1].y + tempLenth * cos(arad) - 1);

			pdc->MoveTo(fyLineCtrlPoint[0]);
			pdc->LineTo(fyLineCtrlPoint[2]);

			if (fyMark % 10 == 0)
			{
				str.Format(_T("%d"),fyMark);
				pdc->TextOut(fyLineCtrlPoint[2].x + nHeight/2 ,fyLineCtrlPoint[2].y + nHeight/2,str);
			}
		}
	}

	// ���Ʒ�λ�̶ȳ�
	CPoint ctpoint;

	// ��С�ֶ�
	double fw;
	fw = scaleLineWidth / 40;
	double dx;

	// �����0-360
	 int dir;
	 dir = m_direction;

	// ���÷�λ�̶����ĵ�����
	ctpoint.x = centerPoint.x;
	ctpoint.y = (int)(centerPoint.y + 5.5*ScaleLineHight);

	// ���ð�ɫ���� ��������ָ��
	SetPen(pen,PS_SOLID,2,RGB(255,255,255),pdc);

	sPoint[0].x = ctpoint.x;
	sPoint[0].y = ctpoint.y - 2;

	sPoint[1].x = sPoint[0].x - 1*sw;
	sPoint[1].y = (int)(sPoint[0].y - 0.5*sh);

	sPoint[3].x = sPoint[0].x + 1*sw;
	sPoint[3].y = (int)(sPoint[0].y - 0.5*sh);

	pdc->MoveTo(sPoint[0]);
	pdc->LineTo(sPoint[1]);
	
	pdc->MoveTo(sPoint[1]);
	pdc->LineTo(sPoint[3]);
	
	pdc->MoveTo(sPoint[3]);
	pdc->LineTo(sPoint[0]);

	// ���ð�ɫ����
	SetPen(pen,PS_SOLID,1,RGB(255,255,255),pdc);

	pm1.x = ctpoint.x;
	pm1.y = ctpoint.y;

	pm2.x = pm1.x;
	pm2.y = pm1.y + 2 * lenth;

	double templenth1;
	CPoint minPoint,maxPoint;
	bool isShow;
	isShow = false;
	
	// �̶ȳ߿�190��
	for (i = -95; i <= 95; i++)
	{
		dx = i * fw;
		if ((dir + i) % 10 == 5 || (dir + i) % 10 == -5) tempLenth = lenth;
		else if ((dir + i) % 10 == 0) tempLenth = 2*lenth;
		else tempLenth = 0;

		if (tempLenth != 0)
		{
			pm1.x = (int)(ctpoint.x + i*fw);
			
			pm2.x = pm1.x;
			pm2.y = pm1.y + tempLenth;
			
			pdc->MoveTo(pm1);
			pdc->LineTo(pm2);

			if (tempLenth == 2*lenth && (dir+i) % 30 == 0)
			{
				number = dir + i;
				if (number < 0) number = 360 + number;

				if (number == 0)
				{
					pdc->TextOut((int)(pm2.x - 0.4*tempLenth),(int)(pm2.y + 1.5*tempLenth)  ,"N");
				}
				else if (number == 90)
				{
					pdc->TextOut((int)(pm2.x - 0.4*tempLenth),(int)(pm2.y + 1.5*tempLenth)  ,"E");
				}
				else if (number == 180)
				{
					pdc->TextOut((int)(pm2.x - 0.5*tempLenth),(int)(pm2.y + 1.5*tempLenth)  ,"S");
				}
				else if (number == 270)
				{
					pdc->TextOut((int)(pm2.x - 0.6*tempLenth),(int)(pm2.y + 1.5*tempLenth)  ,"W");
				}
				else
				{
					if (number > 100) templenth1 = 2*lenth;
					else if (number >10) templenth1 = 1.1*lenth;
					if (number >= 360) number -= 360;

					str.Format(_T("%d"),number);
					pdc->TextOut((int)(pm2.x - templenth1), (int)(pm2.y + 1.5*tempLenth)  ,str);
				}
			}	
		}

		// ������ָ�루Ŀ�귽��
		if (dir + i == m_aimDirection)
		{
			isShow = true;
			
			CPen tempPen(PS_SOLID,2,RGB(255,0,0));
			CPen* old;
			
			old = pdc->SelectObject(&tempPen);
			
			sPoint[0].x = (int)(ctpoint.x + i * fw);
			sPoint[0].y = ctpoint.y;

			sPoint[1].x = sPoint[0].x - 1*sw;
			sPoint[1].y = (int)(sPoint[0].y - 0.5*sh);
			
			sPoint[3].x = sPoint[0].x + 1*sw;
			sPoint[3].y = (int)(sPoint[0].y - 0.5*sh);
			
			pdc->MoveTo(sPoint[0]);
			pdc->LineTo(sPoint[1]);
			
			pdc->MoveTo(sPoint[1]);
			pdc->LineTo(sPoint[3]);
			
			pdc->MoveTo(sPoint[3]);
			pdc->LineTo(sPoint[0]);
			
			pdc->SelectObject(old);
			
		}
	}
	//�ж����п̶��Ƿ�����ʾ
	if (!isShow)
	{
		if (abs(m_aimDirection - (360-95+dir)) < abs(m_aimDirection - (95+dir)))
		{
			CPen tempPen(PS_SOLID,2,RGB(255,0,0));
			CPen* old;
			
			old = pdc->SelectObject(&tempPen);
			
			sPoint[0].x = (int)(ctpoint.x + -95 * fw);
			sPoint[0].y = ctpoint.y - sw;
			
			sPoint[1].x = (int)(sPoint[0].x + 0.5*sh);
			sPoint[1].y = sPoint[0].y - 1*sw;
			
			sPoint[3].x = (int)(sPoint[0].x + 0.5*sh);
			sPoint[3].y = sPoint[0].y + 1*sw;
			
			pdc->MoveTo(sPoint[0]);
			pdc->LineTo(sPoint[1]);
			
			pdc->MoveTo(sPoint[1]);
			pdc->LineTo(sPoint[3]);
			
			pdc->MoveTo(sPoint[3]);
			pdc->LineTo(sPoint[0]);
			
			pdc->SelectObject(old);
		}
		else
		{
			CPen tempPen(PS_SOLID,2,RGB(255,0,0));
			CPen* old;
			
			old = pdc->SelectObject(&tempPen);
			
			sPoint[0].x = (int)(ctpoint.x + 95 * fw);
			sPoint[0].y = ctpoint.y - sw;
			
			sPoint[1].x = (int)(sPoint[0].x - 0.5*sh);
			sPoint[1].y = sPoint[0].y - 1*sw;
			
			sPoint[3].x = (int)(sPoint[0].x - 0.5*sh);
			sPoint[3].y = sPoint[0].y + 1*sw;
			
			pdc->MoveTo(sPoint[0]);
			pdc->LineTo(sPoint[1]);
			
			pdc->MoveTo(sPoint[1]);
			pdc->LineTo(sPoint[3]);
			
			pdc->MoveTo(sPoint[3]);
			pdc->LineTo(sPoint[0]);
			
			pdc->SelectObject(old);
		}
	}

	CPen drawPen;

	drawPen.CreatePen(PS_SOLID, 1, RGB(255,255,255));
	centerPoint.Offset(-100,0);
	// ���ٿ̶���
	DrawRuler(pdc,pen,m_aimAirSpeed,m_airSpeed,-20,20,-1,true, true,true,true,2,ScaleLineHight / 5,scaleLineWidth / 10.0,centerPoint);
	centerPoint.Offset(100,0);
	centerPoint.Offset(100,0);
	// ��ѹ�̶���
	DrawRuler(pdc,pen,m_aimHeight,m_apHeight,-45,45,1,false,true,true,true,4,ScaleLineHight / 10,scaleLineWidth / 10.0,centerPoint);

}
//pdc:���
//pen������
//varAim:Ŀ��ֵ
// ���ƴ�ֱ�̶ȳ�
// MaxDeg:���̶�
// minDeg:��С�̶�
// direction:���Ʒ���:1:Ϊ������ң�-1��Ϊ�������
// isSign:�Ƿ���ʾ����
// isMove:�����Ƿ��ƶ�
// isIco���Ƿ���ʾͼ��ָ��
// minDivValue:��С�̶�ֵ
// minDivWidth:��С�̶ȿ�
// centerPoint:���Ŀ̶ȵ�����
void CInstrumentPanelCtrl::DrawRuler(CDC* pdc, CPen* pen,int varAim, int varMove, int minDeg, int maxDeg, int direction, bool isuint,  bool isSign, bool isMove,bool isIcon,double d_minDivValue, double minDivWidth,double shortDivLineWidth, CPoint centerPoint)
{

	// ��������ƫ����
	int cdx,cdy;
	cdx = 0;
	cdy = 0;
	// �̶ȶ�Ӧֵ
	int mark;
	int minDivValue;
	minDivValue = (int)d_minDivValue;
	CString str;
	int strcount;
	int fontHeight,fontWidth;
	TEXTMETRIC tm;
	pdc->GetTextMetrics(&tm);
	fontHeight = tm.tmHeight;
	fontWidth = (int)(tm.tmAveCharWidth*1.5);

	bool isShow;
	isShow = false;

	// ������С��
	CPoint minPoint;
	bool isMinPoint;
	isMinPoint = true;

	// �����̶��߿��Ƶ�
	CPoint divCtrlPoint[2];

	double tempLenth;
	tempLenth = 0;
	
	CPen* OldPen;
	
	OldPen = pdc->SelectObject(pen);

	for (int i = minDeg; i <= maxDeg; i++)
	{
		// �������ĵ�ƫ����
		cdx = 0;
		cdy = -(int)(i*minDivWidth);

		mark = i;// * minDivValue;
		if (isMove)
		{
			mark = mark + varMove;
		}
		if (!isSign)
		{
			mark = abs(mark);
		}
		if (isuint && mark < 0)
		{
			continue;
		}

		if (mark % minDivValue == 0)
		{
			switch (mark % 10)
			{
				// ��ʮ�̶� ��
			case 0:
				tempLenth = 1.5 * shortDivLineWidth;
				break;
				// ����̶� ��
			case 5:
				tempLenth = 1.0 * shortDivLineWidth;
				break;
			default:
				tempLenth = 0.7 * shortDivLineWidth;
				break;
			}
			
			divCtrlPoint[1].x = centerPoint.x + cdx;
			divCtrlPoint[1].y = centerPoint.y + cdy;
			
			divCtrlPoint[0].x = (int)(divCtrlPoint[1].x + direction * tempLenth);
			divCtrlPoint[0].y = divCtrlPoint[1].y;
			
			pdc->MoveTo(divCtrlPoint[0]);
			pdc->LineTo(divCtrlPoint[1]);

			if (isMinPoint)
			{
				isMinPoint = false;
				minPoint.x = divCtrlPoint[1].x;
				minPoint.y = divCtrlPoint[1].y;
			}
			if (mark % 10 == 0)
			{
				str.Format(_T("%d"),mark);
				strcount = str.GetLength();
				if (direction > 0) strcount = 0;
				pdc->TextOut(divCtrlPoint[0].x + direction * fontWidth * strcount + 2 ,divCtrlPoint[0].y + fontHeight/2,str);
			}
		}
		
		if (mark == varAim)
		{
			isShow = true;

			CPen tempPen(PS_SOLID,2,RGB(255,0,0));
			CPen* old;

			old = pdc->SelectObject(&tempPen);
			
			divCtrlPoint[1].x = centerPoint.x + cdx;
			divCtrlPoint[1].y = centerPoint.y + cdy;

			pdc->MoveTo(divCtrlPoint[1]);
			pdc->LineTo((int)(divCtrlPoint[1].x - direction * fontWidth/1.5), divCtrlPoint[1].y - fontHeight/3);

			pdc->MoveTo(divCtrlPoint[1]);
			pdc->LineTo((int)(divCtrlPoint[1].x - direction * fontWidth/1.5), divCtrlPoint[1].y + fontHeight/3);

			pdc->SelectObject(old);
		}
	}
	if (!isShow)
	{
		if (varAim > varMove)
		{
			CPen tempPen(PS_SOLID,2,RGB(255,0,0));
			CPen* old;
			
			old = pdc->SelectObject(&tempPen);
			
			pdc->MoveTo(divCtrlPoint[1]);
			pdc->LineTo((int)(divCtrlPoint[1].x - fontWidth/1.5), divCtrlPoint[1].y + fontHeight/3);
			
			pdc->MoveTo(divCtrlPoint[1]);
			pdc->LineTo((int)(divCtrlPoint[1].x + fontWidth/1.5), divCtrlPoint[1].y + fontHeight/3);
			
			pdc->SelectObject(old);
		}
		else
		{
			CPen tempPen(PS_SOLID,2,RGB(255,0,0));
			CPen* old;
			
			old = pdc->SelectObject(&tempPen);
			
			pdc->MoveTo(minPoint);
			pdc->LineTo((int)(minPoint.x - fontWidth/1.5), minPoint.y - fontHeight/3);
			
			pdc->MoveTo(minPoint);
			pdc->LineTo((int)(minPoint.x + fontWidth/1.5), minPoint.y - fontHeight/3);
			
			pdc->SelectObject(old);
		}
	}

	CBrush brush;
	CRect rect;

	SetBrush(&brush,RGB(0,0,0),pdc);
	// ���ƾ��ο�
	rect = new CRect(centerPoint.x, (int)(centerPoint.y - minDivWidth*minDivValue),   (int)(centerPoint.x + direction*4.5*shortDivLineWidth), (int)(centerPoint.y + minDivWidth*minDivValue));
	pdc->Rectangle(rect);

	str.Format(_T("%d"),varMove);
	strcount = str.GetLength();
	pdc->TextOut((int)(rect.CenterPoint().x - fontWidth * strcount / 2.8), rect.CenterPoint().y + fontHeight/2 ,str);

	// �ָ�����
	pdc->SelectObject(OldPen);
}

void CInstrumentPanelCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.

	CPen penDraw, *pPenOld ;//���廭��
	CBrush brushFill, *pBrushOld ;//���廭ˢ
	CPoint pointNeedle[4] ;//�����ĸ���
	int dh,dv,w;//�����ת��ˮƽ�϶�������ƫ���������ֱ�϶�������ƫ����ڹ�ת�������̶ȣ�������֮һ�ؼ����
	COLORREF backColor,foreColor;//������ɫ
	int gzDeg,fyDeg;//�����ת�ǣ���������ʱ����

	CRect rect;//������η�Χ

	///////////////////��ʱû�õ�//////////////////////////////
	backColor = TranslateColor(GetBackColor());//��ȡ����ɫ
	foreColor = TranslateColor(GetForeColor());//��ȡǰ��ɫ
    /////////////////////////////////////////////////////

	backColor = RGB(9,101,255);//���ñ���ɫ���Ǳ�����ɫ����
	foreColor = RGB(150,88,35);//����ǰ��ɫ���Ǳ�����ɫ����

	// �����ĸ����͹�ת�����Ը�ֵ����ʱ����
	gzDeg = m_gzDeg;
	fyDeg = m_fyDeg;

	rect = rcBounds;//���ؼ����η�Χ�����ֲ����η�Χ����

	// ������ձ���
	SetBrush(&brushFill,backColor,pdc);//���û�ˢ�������Զ���ģ�
	pdc->Rectangle(rect);//�����Σ���ղ��ּ��������֣�

	// ��ʼ������
	dh=0;
	dv=0;
	w = (int)(rect.Width()/2);//�ؼ���ȵ�һ��

	// ����ת�Ƕ�ת��Ϊ����ƫ��
	if(gzDeg>= 0 && gzDeg<90)
	{
		dh = (int)((double)w*tan(((double)gzDeg/180.0)*3.14));
	}
	else if(gzDeg<0 &&gzDeg>-90)
	{
		dh = -(int)((double)w*tan((double)(-gzDeg/180.0)*3.14));
	}
	else
	{
		dh = 0;
	}
	
    //�����Ƕ�תΪ����ƫ��
	dv = (fyDeg * rect.Height())/140;
	
	// �����ı��Σ���ɫ���֣�������
	pointNeedle[0].x= rect.Width();
	pointNeedle[0].y = rect.Height()/2 - dh + dv;
	pointNeedle[1].x= 0;
	pointNeedle[1].y = rect.Height()/2 + dh + dv;
	pointNeedle[2].x = 0;
	pointNeedle[2].y = rect.Height();
	pointNeedle[3] = rect.BottomRight();
	
	// ������ɫ���֣����壩
	pBrushOld = SetBrush(&brushFill,foreColor,pdc);//���û�ˢ
	pdc->Polygon(pointNeedle, 4);
	
	// ���û���
	penDraw.DeleteObject();
	penDraw.CreatePen(PS_SOLID, 2, RGB(255,255,255));
	pPenOld = pdc->SelectObject(&penDraw);

	// ����ˮƽ��
		// ��ˮƽ��
	pdc->MoveTo(pointNeedle[0]);//�����ߵ����
	pdc->LineTo(pointNeedle[1]);// �����ߵ��յ�
		// ��ɫˮƽ����������ɫ���ι��ɣ�

	CPoint rp1,rp2;//��ɫˮƽС�������ϣ�����������
	CPoint centerPoint;//�����Ǳ������ĵ�

	int rectw,recth;//�ο���͸�

	//���ο���͸߶�Ӧ���ؼ��Ŀ����
	rectw = rect.Width();
	recth = rect.Height();

	centerPoint = rect.CenterPoint();//���Ǳ������ĵ���Ϊ�ؼ����ĵ�

	//���þ��εĿ��Ƶ�����
	rp1.x = (int)(centerPoint.x - 0.26*rectw);
	rp1.y = centerPoint.y - recth/70;

	rp2.x = (int)(rp1.x + 0.2*rectw);
	rp2.y = rp1.y + recth/35;
    //���û�ˢ������
	SetBrush(&brushFill,RGB(255,255,0),pdc);
	SetPen(&penDraw,PS_SOLID,2,RGB(0,0,0),pdc);
	//����������ɫС����
	pdc->Rectangle(CRect(rp1,rp2));
	pdc->Rectangle(centerPoint.x - recth/80, centerPoint.y - recth/80, centerPoint.x + recth/80, centerPoint.y + recth/80);
	pdc->Rectangle(2*centerPoint.x - rp1.x, rp1.y, 2*centerPoint.x - rp2.x, rp2.y);

    // �����Ǳ��̣���ɫ���̶��߲���
	DrowScaleLine(pdc,&rect,&penDraw);

	// ����ָ���벿��
	CPoint compassCenterPoint;
	compassCenterPoint.x = rect.TopLeft().x + (int)(rect.Width()/10);
	compassCenterPoint.y = rect.BottomRight().y - (int)(rect.Width()/10);

	DrawCompass(pdc,compassCenterPoint, (float)(rect.Width()/22.0));
}

//////////////////////////�Զ��庯��////////////////////////////
//����ָ����
void CInstrumentPanelCtrl::DrawCompass(CDC *pdc, CPoint centerPoint, float r)
{
//	CClientDC dc(this);
	CPoint CtrlPoint1[3];
	CPoint CtrlPoint2[3];
	float a;
	a = m_heading;
	CBrush brush;
	brush.CreateSolidBrush(RGB(0,0,255));
	CBrush *pOldBrush = pdc->SelectObject(&brush);

	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(255,255,255));//PS_SOLID
	CPen *pOldPen = pdc->SelectObject(&pen);
	// ����Բ�α���
	pdc->Ellipse((int)(centerPoint.x-r) , (int)(centerPoint.y-r), (int)(centerPoint.x + r) , (int)(centerPoint.y +r));
	
	// ����ָ��
	CtrlPoint1[0] = DoZhengYunSuan(centerPoint,(float)(0.8*r),ConvertDeg(a));
	CtrlPoint1[1] = DoZhengYunSuan(centerPoint,(float)(0.2*r),ConvertDeg(a-90));
	CtrlPoint1[2] = DoZhengYunSuan(centerPoint,(float)(0.2*r),ConvertDeg(a + 90));

	CtrlPoint2[0] = DoZhengYunSuan(centerPoint,(float)(0.8*r),ConvertDeg(a + 180));
	CtrlPoint2[1] = DoZhengYunSuan(centerPoint,(float)(0.2*r),ConvertDeg(a-90));
	CtrlPoint2[2] = DoZhengYunSuan(centerPoint,(float)(0.2*r),ConvertDeg(a + 90));

	pen.DeleteObject();
	pen.CreatePen(PS_SOLID, 1, RGB(255,255,255));
	pdc->SelectObject(&pen);

	brush.DeleteObject();
	brush.CreateSolidBrush(RGB(255,255,255));
	pdc->SelectObject(&brush);

	pdc->Polygon(CtrlPoint2,3);

	pen.DeleteObject();
	pen.CreatePen(PS_SOLID, 1, RGB(255,20,0));
	pdc->SelectObject(&pen);

	brush.DeleteObject();
	brush.CreateSolidBrush(RGB(255,20,0));
	pdc->SelectObject(&brush);

	pdc->Polygon(CtrlPoint1,3);

	// ��������
	//��������
	CFont font;
	CFont *pOldFont;
	font.CreateFont((int)(1* r), 0, 0, 0, 400, 
		FALSE, FALSE, 0, ANSI_CHARSET,
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, 
		DEFAULT_PITCH|FF_SWISS, "Arial");
	pOldFont = pdc->SelectObject(&font);//ѡ�����岢����ԭ��������ָ��
	pdc->SetBkMode(TRANSPARENT);//����͸������
	pdc->SetTextColor(RGB(255,255,255));//����������ɫ
	pdc->SetTextAlign(TA_CENTER | TA_CENTER);//���ö��뷽ʽ

	int fontHeight;
	int fontWidth;
	TEXTMETRIC tm;
	pdc->GetTextMetrics(&tm);
	fontHeight = tm.tmHeight;
	fontWidth = tm.tmAveCharWidth;

	pdc->TextOut((int)(centerPoint.x),(int)(centerPoint.y - r - fontHeight),"N");
	pdc->TextOut((int)(centerPoint.x),(int)(centerPoint.y + r),"S");
	pdc->TextOut((int)(centerPoint.x - r - 1.2*fontWidth),(int)(centerPoint.y - fontHeight/2),"W");
	pdc->TextOut((int)(centerPoint.x + r + fontWidth),(int)(centerPoint.y- fontHeight/2),"E");

	pdc->SelectObject(pOldFont);
	pdc->SelectObject(pOldBrush);
	pdc->SelectObject (pOldPen);
}

//���Ƕ�ת��0-360�ȷ�Χ
float CInstrumentPanelCtrl::ConvertDeg(float a)
{
	float temp;
	temp = a;

	if (temp >= 0)
	{
		temp -= (int)(temp / 360)*360;
	}
	else if (a < 0)
	{
		temp = (float)(360.0 + (temp - (int)(temp/360)*360));
	}

	return temp;

}
/// <summary>
/// ��������
/// </summary>
/// <param name="dA">��֪��A����</param>
/// <param name="dab">AB����</param>
/// <param name="a">�Ƕȣ���λΪ��λ��</param>
/// <returns>Ŀ���B����</returns>
CPoint CInstrumentPanelCtrl::DoZhengYunSuan(CPoint dA, float dab, float a)
{
    int dx, dy;
    float rate = (float)(3.141592 / 180.0);
	
    CPoint dB;
	
    dx = (int)(dab * sin(a * rate));
    dy = -(int)(dab * cos(a * rate));


	
    dB.x = dA.x + dx;
    dB.y = dA.y + dy;
	
    return dB;
}
/////////////////////////////////////////////////////////////////////////////
// CInstrumentPanelCtrl::DoPropExchange - Persistence support

void CInstrumentPanelCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_Short(pPX,"FyDeg",m_fyDeg,0);
	PX_Short(pPX,"GzDeg",m_gzDeg,0);
	PX_Short(pPX,"Direction",m_direction,0);
	PX_Short(pPX,"AimAirSpeed",m_aimAirSpeed,0);
	PX_Short(pPX,"AirSpeed",m_airSpeed,0);
	PX_Short(pPX,"ApHeight",m_apHeight,0);
	PX_Short(pPX,"AimHeight",m_aimHeight,0);
	PX_Short(pPX,"AimDirection",m_aimDirection,0);
	PX_Float(pPX,"Heading",m_heading,0);
//	PX_Float(pPX,"Heading",m_)

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CInstrumentPanelCtrl::OnResetState - Reset control to default state

void CInstrumentPanelCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CInstrumentPanelCtrl::AboutBox - Display an "About" box to the user

void CInstrumentPanelCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_INSTRUMENTPANEL);
	dlgAbout.DoModal();
}
//

/////////////////////////////////////////////////////////////////////////////
// CInstrumentPanelCtrl message handlers



int CInstrumentPanelCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	/*SetTimer(1,1000,NULL);*/

	return 0;
}

void CInstrumentPanelCtrl::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
//	InvalidateControl(NULL);

	COleControl::OnTimer(nIDEvent);
}

void CInstrumentPanelCtrl::OnFyDegChanged() 
{
	// TODO: Add notification handler code

	if (m_fyDeg <= -90)
	{
		m_fyDeg = -89;
	}
	else if(m_fyDeg >= 90)
	{
		m_fyDeg = 89;	
	}

	InvalidateControl(NULL);

	SetModifiedFlag();
}

void CInstrumentPanelCtrl::OnGzDegChanged() 
{
	// TODO: Add notification handler code
	if (m_gzDeg <= -90)
	{
		m_gzDeg = -89;
	}
	else if(m_gzDeg >= 90)
	{
		m_gzDeg = 89;	
	}

	InvalidateControl(NULL);

	SetModifiedFlag();
}

void CInstrumentPanelCtrl::OnDirectionChanged() 
{
	// TODO: Add notification handler code

	if (m_direction < 0)
	{
		m_direction = 0;
	}
	else if(m_direction >= 360)
	{
		m_direction = 0;	
	}

	InvalidateControl(NULL);

	SetModifiedFlag();
}

void CInstrumentPanelCtrl::OnApHeightChanged() 
{
	// TODO: Add notification handler code
	InvalidateControl(NULL);
	SetModifiedFlag();
}

void CInstrumentPanelCtrl::OnAimHeightChanged() 
{
	// TODO: Add notification handler code
	InvalidateControl(NULL);
	SetModifiedFlag();
}

void CInstrumentPanelCtrl::OnAirSpeedChanged() 
{
	// TODO: Add notification handler code

	if (m_airSpeed < 0)
	{
		m_airSpeed = 0;
	}

	InvalidateControl(NULL);
	SetModifiedFlag();
}

void CInstrumentPanelCtrl::OnAimAirSpeedChanged() 
{
	// TODO: Add notification handler code
	if (m_aimAirSpeed < 0)
	{
		m_aimAirSpeed = 0;
	}
	InvalidateControl(NULL);
	SetModifiedFlag();
}

void CInstrumentPanelCtrl::OnAimDirectionChanged() 
{
	// TODO: Add notification handler code


	if (m_aimDirection < 0)
	{
		m_aimDirection = 0;
	}
	else if(m_aimDirection >= 360)
	{
		m_aimDirection = 0;	
	}
	
	InvalidateControl(NULL);

	SetModifiedFlag();
}

void CInstrumentPanelCtrl::UpDate(short gzDeg, short fyDeg, short direction, short aimDirection, short airSpeed, short aimAirSpeed, short apHeight, short aimHeight, float heading) 
{
	// TODO: Add your dispatch handler code here


	if (fyDeg <= -90)
	{
		fyDeg = -89;
	}
	else if(fyDeg >= 90)
	{
		fyDeg = 89;	
	}

	m_fyDeg = fyDeg;


	if (gzDeg <= -90)
	{
		gzDeg = -89;
	}
	else if(gzDeg >= 90)
	{
		gzDeg = 89;	
	}

	m_gzDeg = gzDeg;


	if (direction < 0)
	{
		direction = 0;
	}
	else if(direction >= 360)
	{
		direction = 0;	
	}
	m_direction = direction;

	if (aimDirection < 0)
	{
		aimDirection = 0;
	}
	else if(m_aimDirection >= 360)
	{
		aimDirection = 0;	
	}
	m_aimDirection = aimDirection;

	if (airSpeed < 0)
	{
		airSpeed = 0;
	}
	m_airSpeed = airSpeed;

	if (aimAirSpeed < 0)
	{
		aimAirSpeed = 0;
	}
	m_aimAirSpeed = aimAirSpeed;


	m_apHeight = apHeight;
	m_aimHeight = aimHeight;
	m_heading = heading;



	InvalidateControl(NULL);
}

void CInstrumentPanelCtrl::OnHeadingChanged() 
{
	// TODO: Add notification handler code
	InvalidateControl(NULL);

	SetModifiedFlag();
}

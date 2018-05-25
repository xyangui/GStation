#if !defined(AFX_INSTRUMENTPANELCTL_H__A399C734_92B6_42C4_950C_AD27A6285E3A__INCLUDED_)
#define AFX_INSTRUMENTPANELCTL_H__A399C734_92B6_42C4_950C_AD27A6285E3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// InstrumentPanelCtl.h : Declaration of the CInstrumentPanelCtrl ActiveX Control class.
#include <math.h>

/////////////////////////////////////////////////////////////////////////////
// CInstrumentPanelCtrl : See InstrumentPanelCtl.cpp for implementation.

class CInstrumentPanelCtrl : public COleControl
{
	DECLARE_DYNCREATE(CInstrumentPanelCtrl)

// Constructor
public:
	CInstrumentPanelCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInstrumentPanelCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CInstrumentPanelCtrl();
	CBrush* SetBrush(CBrush* brush,COLORREF colorRef,CDC* pDC);
	CPen* SetPen(CPen* pen,int penStyle, int width,COLORREF colorRef,CDC* pdc);
	void DrowScaleLine(CDC* pdc,CRect* rect,CPen* pen);
	void DrawRuler(CDC* pdc, CPen* pen, int varAim, int varMove, int minDeg, int maxDeg, int direction,bool isuint, bool isSign, bool isMove,bool isIcon,double d_minDivValue, double minDivWidth,double shortDivLineWidth, CPoint centerPoint);
	void DrawCompass(CDC *pdc,CPoint centerPoint, float r);
	CPoint DoZhengYunSuan(CPoint dA, float dab, float a);
	float ConvertDeg(float a);

	DECLARE_OLECREATE_EX(CInstrumentPanelCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CInstrumentPanelCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CInstrumentPanelCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CInstrumentPanelCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CInstrumentPanelCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CInstrumentPanelCtrl)
	short m_fyDeg;
	afx_msg void OnFyDegChanged();
	short m_gzDeg;
	afx_msg void OnGzDegChanged();
	short m_direction;
	afx_msg void OnDirectionChanged();
	short m_apHeight;
	afx_msg void OnApHeightChanged();
	short m_aimHeight;
	afx_msg void OnAimHeightChanged();
	short m_airSpeed;
	afx_msg void OnAirSpeedChanged();
	short m_aimAirSpeed;
	afx_msg void OnAimAirSpeedChanged();
	short m_aimDirection;
	afx_msg void OnAimDirectionChanged();
	float m_heading;
	afx_msg void OnHeadingChanged();
	afx_msg void UpDate(short gzDeg, short fyDeg, short direction, short aimDirection, short airSpeed, short aimAirSpeed, short apHeight, short aimHeight, float heading);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CInstrumentPanelCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CInstrumentPanelCtrl)
	dispidFyDeg = 1L,
	dispidGzDeg = 2L,
	dispidDirection = 3L,
	dispidApHeight = 4L,
	dispidAimHeight = 5L,
	dispidAirSpeed = 6L,
	dispidAimAirSpeed = 7L,
	dispidAimDirection = 8L,
	dispidUpDate = 9L,
	dispidHeading = 10L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INSTRUMENTPANELCTL_H__A399C734_92B6_42C4_950C_AD27A6285E3A__INCLUDED)

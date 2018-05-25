#if !defined(AFX_INSTRUMENTCIRCLECTL_H__F1F039FA_3AEC_4CD5_A685_E803AF16608B__INCLUDED_)
#define AFX_INSTRUMENTCIRCLECTL_H__F1F039FA_3AEC_4CD5_A685_E803AF16608B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// InstrumentCircleCtl.h : Declaration of the CInstrumentCircleCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CInstrumentCircleCtrl : See InstrumentCircleCtl.cpp for implementation.

class CInstrumentCircleCtrl : public COleControl
{
	DECLARE_DYNCREATE(CInstrumentCircleCtrl)

// Constructor
public:
	CInstrumentCircleCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInstrumentCircleCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CInstrumentCircleCtrl();

	DECLARE_OLECREATE_EX(CInstrumentCircleCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CInstrumentCircleCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CInstrumentCircleCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CInstrumentCircleCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CInstrumentCircleCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CInstrumentCircleCtrl)
	short m_minDeg;
	afx_msg void OnMinDegChanged();
	short m_maxDeg;
	afx_msg void OnMaxDegChanged();
	short m_minValue;
	afx_msg void OnMinValueChanged();
	short m_maxValue;
	afx_msg void OnMaxValueChanged();
	short m_divCount;
	afx_msg void OnDivCountChanged();
	double m_realValue;
	afx_msg void OnRealValueChanged();
	double m_aimValue;
	afx_msg void OnAimValueChanged();
	double m_numberFont;
	afx_msg void OnNumberFontChanged();
	double m_labFont;
	afx_msg void OnLabFontChanged();
	long m_labX;
	afx_msg void OnLabXChanged();
	long m_labY;
	afx_msg void OnLabYChanged();
	CString m_labText;
	afx_msg void OnLabTextChanged();
	CString m_labTextLine2;
	afx_msg void OnLabTextLine2Changed();
	long m_labX2;
	afx_msg void OnLabX2Changed();
	long m_labY2;
	afx_msg void OnLabY2Changed();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// Event maps
	//{{AFX_EVENT(CInstrumentCircleCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CInstrumentCircleCtrl)
	dispidMimDeg = 1L,
	dispidMaxDeg = 2L,
	dispidMinValue = 3L,
	dispidMaxValue = 4L,
	dispidDivCount = 5L,
	dispidRealValue = 6L,
	dispidAimValue = 7L,
	dispidNumberFont = 8L,
	dispidLabFont = 9L,
	dispidLabX = 10L,
	dispidLabY = 11L,
	dispidLabText = 12L,
	dispidLabTextLine2 = 13L,
	dispidLabX2 = 14L,
	dispidLabY2 = 15L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INSTRUMENTCIRCLECTL_H__F1F039FA_3AEC_4CD5_A685_E803AF16608B__INCLUDED)

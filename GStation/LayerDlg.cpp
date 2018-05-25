// LayerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GStation.h"
#include "LayerDlg.h"

#include "GStationDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLayerDlg dialog


CLayerDlg::CLayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLayerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLayerDlg)
	m_strDirectoryFileName = _T("");
	//}}AFX_DATA_INIT
}


void CLayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLayerDlg)
	DDX_Control(pDX, IDC_COMBO_LAYER, m_comboLayer);
	DDX_Text(pDX, IDC_EDIT_DIRECTORY, m_strDirectoryFileName);
	DDX_Control(pDX, IDC_COMMONDIALOG, m_comDlg);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLayerDlg, CDialog)
	//{{AFX_MSG_MAP(CLayerDlg)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_OPEN, OnButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_MAP, OnButtonMap)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLayerDlg message handlers
BOOL CLayerDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_comboLayer.SetCurSel(0);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
//�½�
void CLayerDlg::OnButtonNew() 
{
	ClickButtonType = New;

	UpdateData(TRUE);
	
	CString strDirectory, strTitle;
	CString strPath = GetDirectory();

	if (m_comboLayer.GetCurSel() == 0) { //WayPointStation
		strDirectory.Format("%s\\airlines", strPath);
		strTitle = _T("�½������");
	}
	if (m_comboLayer.GetCurSel() == 1) { //��־��
		strDirectory.Format("%s\\flags", strPath);
		strTitle = _T("�½���־��");
	}

	m_comDlg.SetInitDir(strDirectory);
	m_comDlg.SetDialogTitle(strTitle);
	m_comDlg.SetFilter("*.tab");
	m_comDlg.SetFileName("*.tab");

 	m_comDlg.ShowOpen();
	SetCurrentDirectory(strPath);//�����������û���

	CString file;
 	file.Empty();
	file = m_comDlg.GetFileName();
	file.TrimRight();

	m_strDirectoryFileName = file;//����·�����ļ�������չ��
	m_strFileExtensionName = m_comDlg.GetFileTitle();//ֻ���ļ�������չ��

	//�����ļ���ʱ����ʱ��ѡ�*.tab��ȫ�����ǣ���ʱ���ص�����ֵ����������չ��
	//ֻ�����롰�ļ���.tab��ʱ����ʱ���ص�����ֵ��������չ��
	CString strExtension;//��չ��

	if(m_strFileExtensionName.GetLength() > 4)
		strExtension = m_strFileExtensionName.Right(4);
	
	if(strExtension != ".tab" && strExtension != ".TAB")
	{
		m_strFileExtensionName = m_strFileExtensionName + ".tab";
		m_strDirectoryFileName = m_strDirectoryFileName + ".tab";
	}

	UpdateData(FALSE);
}
//��
void CLayerDlg::OnButtonOpen() 
{
	ClickButtonType = Open;

	UpdateData(TRUE);

	CString strDirectory, strTitle;
	CString strPath = GetDirectory();

	if (m_comboLayer.GetCurSel() == 0) { //WayPointStation
		strDirectory.Format("%s\\airlines", strPath);
		strTitle = _T("�򿪺����ļ�");
	}
	if (m_comboLayer.GetCurSel() == 1) { //��־��
		strDirectory.Format("%s\\flags", strPath);
		strTitle = _T("�򿪱�־�ļ�");
	}
	
	m_comDlg.SetInitDir(strDirectory);
	m_comDlg.SetDialogTitle(strTitle);
	m_comDlg.SetFilter("*.tab");
	m_comDlg.SetFileName("*.tab");
	
	m_comDlg.ShowOpen();//������B�ı��˵�ǰ·��
	SetCurrentDirectory(strPath);//�����������û���
		
	CString file;
 	file.Empty();
	file = m_comDlg.GetFileName();
	file.TrimRight();

	m_strDirectoryFileName = file;//����·�����ļ�������չ��
	m_strFileExtensionName = m_comDlg.GetFileTitle();//ֻ���ļ�������չ��

	UpdateData(FALSE);
}
//���ӵ�ͼ
void CLayerDlg::OnButtonMap() 
{
	ClickButtonType = Map;

	CString strPath = GetDirectory();

	CString strDirectory;
	strDirectory.Format("%s\\map", strPath);
	m_comDlg.SetInitDir(strDirectory);

	m_comDlg.SetDialogTitle("�򿪵��ӵ�ͼ");
	m_comDlg.SetFilter("*.gst");
	m_comDlg.SetFileName("*.gst");

 	m_comDlg.ShowOpen();
	SetCurrentDirectory(strPath);//�����������û���

	CString file;
 	file.Empty();
	file = m_comDlg.GetFileName();
	file.TrimRight();

	m_strDirectoryFileName = file;//����·�����ļ�������չ��
	m_strFileExtensionName = m_comDlg.GetFileTitle();//ֻ���ļ�������չ��

	CGStationDlg *pGStationDlg = (CGStationDlg*)GetParent();
	pGStationDlg->OpenMapGST(m_strDirectoryFileName);

	CDialog::OnCancel();
}
//�õ���ǰ·������������û��"\"
CString CLayerDlg::GetDirectory()
{
	char pFileName[256];   
	int nPos = GetCurrentDirectory(256, pFileName);   
	CString csFullPath(pFileName);    
	if( nPos < 0 )   
		return CString("");   
	else   
		return csFullPath;   
}

void CLayerDlg::OnOK() 
{
	if (m_strDirectoryFileName.IsEmpty() || m_strFileExtensionName.IsEmpty()) {
		AfxMessageBox(_T("��ʾ��·�����ļ���������Ϊ�գ�"));
		return;
	}
	
	CGStationDlg *pGStationDlg = (CGStationDlg*)GetParent();
	try
	{
		if (ClickButtonType == New && m_comboLayer.GetCurSel() == 0) {//�½�WayPointStation
			//����CTF1DDlg::OnNewLayer(CString directer, CString name)
			if (pGStationDlg->m_bWayPointStationIsExist) {
				pGStationDlg->m_ctrlMapX.GetLayers().Remove("WayPointStation");
				pGStationDlg->m_bWayPointStationIsExist = FALSE;
			}
			
			CMapXLayerInfo layerinfo;
			if( !layerinfo.CreateDispatch( layerinfo.GetClsid() ) ) 
				return ;  
			layerinfo.SetType(miLayerInfoTypeNewTable);     //�½�ͼ������
			
			VARIANT sVt;
			sVt.vt = VT_BSTR;
			sVt.bstrVal = m_strDirectoryFileName.AllocSysString();//Ӧ����ͼ����tab�ļ���
			layerinfo.AddParameter("FileSpec", sVt); 
			layerinfo.AddParameter("Name",COleVariant("WayPointStation"));
			
			CMapXFields fields;
			if( !fields.CreateDispatch( fields.GetClsid() ) )
				return ; 
			fields.AddIntegerField("num",FALSE); 
			fields.AddIntegerField("altitude",FALSE);
			fields.AddIntegerField("speed",FALSE);
			fields.AddIntegerField("radius",FALSE);
			fields.AddSmallIntField("flag",FALSE);
			fields.AddSmallIntField("time",FALSE);
			fields.AddSmallIntField("servo",FALSE);
			
			VARIANT vField;
			vField.vt = VT_DISPATCH;
			vField.pdispVal = fields.m_lpDispatch;
			layerinfo.AddParameter("Fields", vField);
			
			CString strTemp = _T("1");
			sVt.bstrVal= strTemp.AllocSysString();
			layerinfo.AddParameter("OverwriteFile", sVt); 
			
			CMapXLayers layers = pGStationDlg->m_ctrlMapX.GetLayers();
			layers.Add(layerinfo.m_lpDispatch, 4); //���ӡ�WayPointStation��������ͼ�㼯��
			
			CMapXLayer lay = pGStationDlg->m_ctrlMapX.GetLayers().Item("WayPointStation");
			
			lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
			lay.GetStyle().GetSymbolFont().SetName( "Map Symbols" );//���÷���featureʹ�õ�����
			lay.GetStyle().SetSymbolCharacter(54);//���÷���featureʹ�õ��ַ������õ��ͼ��
			lay.GetStyle().SetSymbolFontHalo(TRUE);
			lay.GetStyle().SetSymbolFontColor(miColorRed);//����ͼ����ɫ
			
			lay.GetLabelProperties().SetPosition(miPositionCR);//���ñ�עλ��//���ñ�ǩ�����1,2,3...��λ��
			lay.GetLabelProperties().SetOffset(2);//���ñ�עƫ����//���ñ�ǩ�����1,2,3...����ͼ�����ĵ��ƫ����
			lay.GetLabelProperties().GetStyle().SetTextFontColor(miColorRed);//���ñ�ǩ�����1,2,3...��������ɫ
			lay.GetLabelProperties().GetStyle().SetTextFontShadow(TRUE);//���ñ�ǩ�����1,2,3...����Ӱ
			
			lay.SetSelectable(TRUE);   //���øò�Ŀ��Ϊ��ѡ��
			lay.SetOverrideStyle(TRUE);//�ò�������Featureʹ����ͬ��style
			lay.SetEditable(TRUE);	
			lay.SetAutoLabel(TRUE);    //���øò�Ŀ��Ϊ�Զ���ע
			
			//lay.GetStyle().SetLineColor(0x0000ff);
			//lay.GetStyle().SetLineStyle(63);//���ñ�ע����
			//lay.GetStyle().SetLineWidth(1);	//��������feature���߿�
			//lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
			
			pGStationDlg->m_ctrlMapX.GetLayers().SetInsertionLayer(lay.m_lpDispatch);
			
			pGStationDlg->m_bWayPointStationIsExist = TRUE;//WayPointStation�Ѿ�����
			((CButton*)pGStationDlg->GetDlgItem(IDC_CHECK_LAYER_WAYLINE))->SetCheck(0);
			//��ѡ�򡰺��߲㡱���򹴣����߲�ֻ�Ǻ���֮������ߣ���WayLine�㣬��WayPointStation�޹�
			((CButton*)pGStationDlg->GetDlgItem(IDC_CHECK_WAYPOINTSTATION))->SetCheck(1);
		}
		
		if (ClickButtonType == Open && m_comboLayer.GetCurSel() == 0) { //��WayPointStation
			
			CMapXLayer lay = pGStationDlg->m_ctrlMapX.GetLayers().Add( m_strDirectoryFileName, 4 );//��λ��4��
			CString layername = lay.GetName();//���ԭ���ʹ���WayPointStation��layernameΪWayPointStation_2
			
			if (layername.Left(15) != _T("WayPointStation")) {
				AfxMessageBox(_T("��ʾ����ѡ���к�����tab�ļ��򿪣�"));
				pGStationDlg->m_ctrlMapX.GetLayers().Remove(layername);
				return;
			}
			//layernameҪô�ǡ�WayPointStation����Ҫô�ǡ�WayPointStation_2��
			if (pGStationDlg->m_bWayPointStationIsExist) { //ԭ��WayPointStation�ʹ��ڣ�layername�ǡ�WayPointStation_2��
				pGStationDlg->m_ctrlMapX.GetLayers().Remove("WayPointStation"); //ɾ��ԭ���ġ�WayPointStation��
				pGStationDlg->m_ctrlMapX.GetLayers().Remove(layername);         //ɾ����WayPointStation_2��
				lay = pGStationDlg->m_ctrlMapX.GetLayers().Add( m_strDirectoryFileName, 4 );//�ٴ�Add�󣬱�Ϊ��WayPointStation��
			}else{
				//layername�ǡ�WayPointStation���������ٴ�ɾ�����
				pGStationDlg->m_bWayPointStationIsExist = TRUE;//WayPointStation�Ѿ�����
			}
			
			lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
			lay.GetStyle().GetSymbolFont().SetName( "Map Symbols" );//���÷���featureʹ�õ�����
			lay.GetStyle().SetSymbolCharacter(54);//���÷���featureʹ�õ��ַ������õ��ͼ��
			lay.GetStyle().SetSymbolFontHalo(TRUE);
			lay.GetStyle().SetSymbolFontColor(miColorRed);//����ͼ����ɫ
			
			lay.GetLabelProperties().SetPosition(miPositionCR);//���ñ�עλ��//���ñ�ǩ�����1,2,3...��λ��
			lay.GetLabelProperties().SetOffset(2);//���ñ�עƫ����//���ñ�ǩ�����1,2,3...����ͼ�����ĵ��ƫ����
			lay.GetLabelProperties().GetStyle().SetTextFontColor(miColorRed);//���ñ�ǩ�����1,2,3...��������ɫ
			lay.GetLabelProperties().GetStyle().SetTextFontShadow(TRUE);//���ñ�ǩ�����1,2,3...����Ӱ
			
			lay.SetSelectable(TRUE);
			lay.SetOverrideStyle(TRUE);
			lay.SetEditable(TRUE);
			lay.SetAutoLabel(TRUE);
			
			//lay.GetStyle().SetLineColor(0x0000ff);
			//lay.GetStyle().SetLineStyle(63);//���ñ�ע����
			//lay.GetStyle().SetLineWidth(1);	//��������feature���߿�
			//lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
			
			pGStationDlg->m_ctrlMapX.GetLayers().SetInsertionLayer(lay.m_lpDispatch);
			
			pGStationDlg->m_ctrlMapX.SetAutoRedraw(TRUE);
			
			((CButton*)pGStationDlg->GetDlgItem(IDC_CHECK_LAYER_WAYLINE))->SetCheck(0);
			((CButton*)pGStationDlg->GetDlgItem(IDC_CHECK_WAYPOINTSTATION))->SetCheck(1);
		}
		
		if (ClickButtonType == New && m_comboLayer.GetCurSel() == 1) {//�½���־��
			
			if (pGStationDlg->m_bSignLayerIsExist) {
				pGStationDlg->m_ctrlMapX.GetLayers().Remove("Sign");
				pGStationDlg->m_bSignLayerIsExist = FALSE;
			}
			
			CMapXLayerInfo layerinfo;
			if( !layerinfo.CreateDispatch( layerinfo.GetClsid() ) ) 
				return ;  
			layerinfo.SetType(miLayerInfoTypeNewTable);//�½�ͼ������
			
			VARIANT sVt;
			sVt.vt = VT_BSTR;
			sVt.bstrVal = m_strDirectoryFileName.AllocSysString();//Ӧ����ͼ����tab�ļ���
			layerinfo.AddParameter("FileSpec", sVt); 
			layerinfo.AddParameter("Name",COleVariant("Sign"));
			
			CMapXFields fields;
			if( !fields.CreateDispatch( fields.GetClsid() ) )
				return ; 
			fields.AddStringField("label",100, TRUE);
		
			VARIANT vField;
			vField.vt = VT_DISPATCH;
			vField.pdispVal = fields.m_lpDispatch;
			layerinfo.AddParameter("Fields", vField);
			
			CMapXLayers layers = pGStationDlg->m_ctrlMapX.GetLayers();
			layers.Add(layerinfo.m_lpDispatch, 5); //���ӡ�Sign��������ͼ�㼯��
			
			CMapXLayer lay = pGStationDlg->m_ctrlMapX.GetLayers().Item("Sign");
			
			lay.SetSelectable(TRUE);   //���øò�Ŀ��Ϊ��ѡ��
			lay.SetOverrideStyle(TRUE);//�ò�������Featureʹ����ͬ��style
			lay.SetEditable(TRUE);	
			lay.SetAutoLabel(TRUE);    //���øò�Ŀ��Ϊ�Զ���ע
			
			pGStationDlg->m_ctrlMapX.GetLayers().SetInsertionLayer(lay.m_lpDispatch);
			
			pGStationDlg->m_bSignLayerIsExist = TRUE;//Sign�Ѿ�����
			((CButton*)pGStationDlg->GetDlgItem(IDC_CHECK_LAYER_SIGN))->SetCheck(1);         //����־�㡱��
			((CButton*)pGStationDlg->GetDlgItem(IDC_CHECK_LAYER_SIGN_SHOWSIGN))->SetCheck(1);//����ʾ��ע����
		}
		if (ClickButtonType == Open && m_comboLayer.GetCurSel() == 1) { //�򿪱�־��
			
			CMapXLayer lay = pGStationDlg->m_ctrlMapX.GetLayers().Add( m_strDirectoryFileName, 5 );
			CString layername = lay.GetName();//���ԭ���ʹ��ڱ�־�㣬layernameΪSign_2
			
			if (layername.Left(4) != _T("Sign")) {
				AfxMessageBox(_T("��ʾ����ѡ���б�־���tab�ļ��򿪣�"));
				pGStationDlg->m_ctrlMapX.GetLayers().Remove(layername);
				return;
			}
			//layernameҪô�ǡ�Sign����Ҫô�ǡ�Sign_2��
			if (pGStationDlg->m_bSignLayerIsExist) {                   //ԭ����־��ʹ��ڣ�layername�ǡ�Sign_2��
				pGStationDlg->m_ctrlMapX.GetLayers().Remove("Sign");   //ɾ��ԭ���ġ�Sign��
				pGStationDlg->m_ctrlMapX.GetLayers().Remove(layername);//ɾ����Sign_2��
				//ɾ����Sign_2�����ٴ�Add�󣬱�Ϊ��Sign��
				lay = pGStationDlg->m_ctrlMapX.GetLayers().Add( m_strDirectoryFileName, 5 );
			}else{
				//layername�ǡ�Sign���������ٴ�ɾ�����
				pGStationDlg->m_bSignLayerIsExist = TRUE;//��־���Ѿ�����
			}

			lay.SetSelectable(TRUE);   //���øò�Ŀ��Ϊ��ѡ��
			lay.SetOverrideStyle(TRUE);//�ò�������Featureʹ����ͬ��style
			lay.SetEditable(TRUE);	
			lay.SetAutoLabel(TRUE);    //���øò�Ŀ��Ϊ�Զ���ע
			
			pGStationDlg->m_ctrlMapX.GetLayers().SetInsertionLayer(lay.m_lpDispatch);
			
			((CButton*)pGStationDlg->GetDlgItem(IDC_CHECK_LAYER_SIGN))->SetCheck(1);         //����־�㡱��
			((CButton*)pGStationDlg->GetDlgItem(IDC_CHECK_LAYER_SIGN_SHOWSIGN))->SetCheck(1);//����ʾ��ע����
		}
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
		
	CDialog::OnOK();
}
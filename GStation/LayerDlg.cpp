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
//新建
void CLayerDlg::OnButtonNew() 
{
	ClickButtonType = New;

	UpdateData(TRUE);
	
	CString strDirectory, strTitle;
	CString strPath = GetDirectory();

	if (m_comboLayer.GetCurSel() == 0) { //WayPointStation
		strDirectory.Format("%s\\airlines", strPath);
		strTitle = _T("新建航点层");
	}
	if (m_comboLayer.GetCurSel() == 1) { //标志层
		strDirectory.Format("%s\\flags", strPath);
		strTitle = _T("新建标志层");
	}

	m_comDlg.SetInitDir(strDirectory);
	m_comDlg.SetDialogTitle(strTitle);
	m_comDlg.SetFilter("*.tab");
	m_comDlg.SetFileName("*.tab");

 	m_comDlg.ShowOpen();
	SetCurrentDirectory(strPath);//还得他妈设置回来

	CString file;
 	file.Empty();
	file = m_comDlg.GetFileName();
	file.TrimRight();

	m_strDirectoryFileName = file;//包含路径和文件名和扩展名
	m_strFileExtensionName = m_comDlg.GetFileTitle();//只有文件名和扩展名

	//输入文件名时，有时候把“*.tab”全都覆盖，这时返回的两个值都不包括扩展名
	//只有输入“文件名.tab”时，这时返回的两个值都包括扩展名
	CString strExtension;//扩展名

	if(m_strFileExtensionName.GetLength() > 4)
		strExtension = m_strFileExtensionName.Right(4);
	
	if(strExtension != ".tab" && strExtension != ".TAB")
	{
		m_strFileExtensionName = m_strFileExtensionName + ".tab";
		m_strDirectoryFileName = m_strDirectoryFileName + ".tab";
	}

	UpdateData(FALSE);
}
//打开
void CLayerDlg::OnButtonOpen() 
{
	ClickButtonType = Open;

	UpdateData(TRUE);

	CString strDirectory, strTitle;
	CString strPath = GetDirectory();

	if (m_comboLayer.GetCurSel() == 0) { //WayPointStation
		strDirectory.Format("%s\\airlines", strPath);
		strTitle = _T("打开航点文件");
	}
	if (m_comboLayer.GetCurSel() == 1) { //标志层
		strDirectory.Format("%s\\flags", strPath);
		strTitle = _T("打开标志文件");
	}
	
	m_comDlg.SetInitDir(strDirectory);
	m_comDlg.SetDialogTitle(strTitle);
	m_comDlg.SetFilter("*.tab");
	m_comDlg.SetFileName("*.tab");
	
	m_comDlg.ShowOpen();//就是这B改变了当前路径
	SetCurrentDirectory(strPath);//还得他妈设置回来
		
	CString file;
 	file.Empty();
	file = m_comDlg.GetFileName();
	file.TrimRight();

	m_strDirectoryFileName = file;//包含路径和文件名和扩展名
	m_strFileExtensionName = m_comDlg.GetFileTitle();//只有文件名和扩展名

	UpdateData(FALSE);
}
//电子地图
void CLayerDlg::OnButtonMap() 
{
	ClickButtonType = Map;

	CString strPath = GetDirectory();

	CString strDirectory;
	strDirectory.Format("%s\\map", strPath);
	m_comDlg.SetInitDir(strDirectory);

	m_comDlg.SetDialogTitle("打开电子地图");
	m_comDlg.SetFilter("*.gst");
	m_comDlg.SetFileName("*.gst");

 	m_comDlg.ShowOpen();
	SetCurrentDirectory(strPath);//还得他妈设置回来

	CString file;
 	file.Empty();
	file = m_comDlg.GetFileName();
	file.TrimRight();

	m_strDirectoryFileName = file;//包含路径和文件名和扩展名
	m_strFileExtensionName = m_comDlg.GetFileTitle();//只有文件名和扩展名

	CGStationDlg *pGStationDlg = (CGStationDlg*)GetParent();
	pGStationDlg->OpenMapGST(m_strDirectoryFileName);

	CDialog::OnCancel();
}
//得到当前路径函数，后面没有"\"
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
		AfxMessageBox(_T("提示：路径和文件名都不能为空！"));
		return;
	}
	
	CGStationDlg *pGStationDlg = (CGStationDlg*)GetParent();
	try
	{
		if (ClickButtonType == New && m_comboLayer.GetCurSel() == 0) {//新建WayPointStation
			//来自CTF1DDlg::OnNewLayer(CString directer, CString name)
			if (pGStationDlg->m_bWayPointStationIsExist) {
				pGStationDlg->m_ctrlMapX.GetLayers().Remove("WayPointStation");
				pGStationDlg->m_bWayPointStationIsExist = FALSE;
			}
			
			CMapXLayerInfo layerinfo;
			if( !layerinfo.CreateDispatch( layerinfo.GetClsid() ) ) 
				return ;  
			layerinfo.SetType(miLayerInfoTypeNewTable);     //新建图层类型
			
			VARIANT sVt;
			sVt.vt = VT_BSTR;
			sVt.bstrVal = m_strDirectoryFileName.AllocSysString();//应该是图层与tab文件绑定
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
			layers.Add(layerinfo.m_lpDispatch, 4); //增加“WayPointStation”到现有图层集合
			
			CMapXLayer lay = pGStationDlg->m_ctrlMapX.GetLayers().Item("WayPointStation");
			
			lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
			lay.GetStyle().GetSymbolFont().SetName( "Map Symbols" );//设置符号feature使用的字体
			lay.GetStyle().SetSymbolCharacter(54);//设置符号feature使用的字符，设置点的图标
			lay.GetStyle().SetSymbolFontHalo(TRUE);
			lay.GetStyle().SetSymbolFontColor(miColorRed);//设置图标颜色
			
			lay.GetLabelProperties().SetPosition(miPositionCR);//设置标注位置//设置标签（序号1,2,3...）位置
			lay.GetLabelProperties().SetOffset(2);//设置标注偏移量//设置标签（序号1,2,3...）与图标中心点的偏移量
			lay.GetLabelProperties().GetStyle().SetTextFontColor(miColorRed);//设置标签（序号1,2,3...）字体颜色
			lay.GetLabelProperties().GetStyle().SetTextFontShadow(TRUE);//设置标签（序号1,2,3...）阴影
			
			lay.SetSelectable(TRUE);   //设置该层目标为可选择
			lay.SetOverrideStyle(TRUE);//该层中所有Feature使用相同的style
			lay.SetEditable(TRUE);	
			lay.SetAutoLabel(TRUE);    //设置该层目标为自动标注
			
			//lay.GetStyle().SetLineColor(0x0000ff);
			//lay.GetStyle().SetLineStyle(63);//设置标注线形
			//lay.GetStyle().SetLineWidth(1);	//设置线形feature的线宽
			//lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
			
			pGStationDlg->m_ctrlMapX.GetLayers().SetInsertionLayer(lay.m_lpDispatch);
			
			pGStationDlg->m_bWayPointStationIsExist = TRUE;//WayPointStation已经存在
			((CButton*)pGStationDlg->GetDlgItem(IDC_CHECK_LAYER_WAYLINE))->SetCheck(0);
			//多选框“航线层”不打勾，航线层只是航点之间的连线，在WayLine层，与WayPointStation无关
			((CButton*)pGStationDlg->GetDlgItem(IDC_CHECK_WAYPOINTSTATION))->SetCheck(1);
		}
		
		if (ClickButtonType == Open && m_comboLayer.GetCurSel() == 0) { //打开WayPointStation
			
			CMapXLayer lay = pGStationDlg->m_ctrlMapX.GetLayers().Add( m_strDirectoryFileName, 4 );//定位第4层
			CString layername = lay.GetName();//如果原来就存在WayPointStation，layername为WayPointStation_2
			
			if (layername.Left(15) != _T("WayPointStation")) {
				AfxMessageBox(_T("提示：请选择有航点层的tab文件打开！"));
				pGStationDlg->m_ctrlMapX.GetLayers().Remove(layername);
				return;
			}
			//layername要么是“WayPointStation”，要么是“WayPointStation_2”
			if (pGStationDlg->m_bWayPointStationIsExist) { //原来WayPointStation就存在，layername是“WayPointStation_2”
				pGStationDlg->m_ctrlMapX.GetLayers().Remove("WayPointStation"); //删除原来的“WayPointStation”
				pGStationDlg->m_ctrlMapX.GetLayers().Remove(layername);         //删除“WayPointStation_2”
				lay = pGStationDlg->m_ctrlMapX.GetLayers().Add( m_strDirectoryFileName, 4 );//再次Add后，变为“WayPointStation”
			}else{
				//layername是“WayPointStation”，不用再次删除添加
				pGStationDlg->m_bWayPointStationIsExist = TRUE;//WayPointStation已经存在
			}
			
			lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
			lay.GetStyle().GetSymbolFont().SetName( "Map Symbols" );//设置符号feature使用的字体
			lay.GetStyle().SetSymbolCharacter(54);//设置符号feature使用的字符，设置点的图标
			lay.GetStyle().SetSymbolFontHalo(TRUE);
			lay.GetStyle().SetSymbolFontColor(miColorRed);//设置图标颜色
			
			lay.GetLabelProperties().SetPosition(miPositionCR);//设置标注位置//设置标签（序号1,2,3...）位置
			lay.GetLabelProperties().SetOffset(2);//设置标注偏移量//设置标签（序号1,2,3...）与图标中心点的偏移量
			lay.GetLabelProperties().GetStyle().SetTextFontColor(miColorRed);//设置标签（序号1,2,3...）字体颜色
			lay.GetLabelProperties().GetStyle().SetTextFontShadow(TRUE);//设置标签（序号1,2,3...）阴影
			
			lay.SetSelectable(TRUE);
			lay.SetOverrideStyle(TRUE);
			lay.SetEditable(TRUE);
			lay.SetAutoLabel(TRUE);
			
			//lay.GetStyle().SetLineColor(0x0000ff);
			//lay.GetStyle().SetLineStyle(63);//设置标注线形
			//lay.GetStyle().SetLineWidth(1);	//设置线形feature的线宽
			//lay.GetStyle().SetSymbolType(miSymbolTypeTrueTypeFont);
			
			pGStationDlg->m_ctrlMapX.GetLayers().SetInsertionLayer(lay.m_lpDispatch);
			
			pGStationDlg->m_ctrlMapX.SetAutoRedraw(TRUE);
			
			((CButton*)pGStationDlg->GetDlgItem(IDC_CHECK_LAYER_WAYLINE))->SetCheck(0);
			((CButton*)pGStationDlg->GetDlgItem(IDC_CHECK_WAYPOINTSTATION))->SetCheck(1);
		}
		
		if (ClickButtonType == New && m_comboLayer.GetCurSel() == 1) {//新建标志层
			
			if (pGStationDlg->m_bSignLayerIsExist) {
				pGStationDlg->m_ctrlMapX.GetLayers().Remove("Sign");
				pGStationDlg->m_bSignLayerIsExist = FALSE;
			}
			
			CMapXLayerInfo layerinfo;
			if( !layerinfo.CreateDispatch( layerinfo.GetClsid() ) ) 
				return ;  
			layerinfo.SetType(miLayerInfoTypeNewTable);//新建图层类型
			
			VARIANT sVt;
			sVt.vt = VT_BSTR;
			sVt.bstrVal = m_strDirectoryFileName.AllocSysString();//应该是图层与tab文件绑定
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
			layers.Add(layerinfo.m_lpDispatch, 5); //增加“Sign”到现有图层集合
			
			CMapXLayer lay = pGStationDlg->m_ctrlMapX.GetLayers().Item("Sign");
			
			lay.SetSelectable(TRUE);   //设置该层目标为可选择
			lay.SetOverrideStyle(TRUE);//该层中所有Feature使用相同的style
			lay.SetEditable(TRUE);	
			lay.SetAutoLabel(TRUE);    //设置该层目标为自动标注
			
			pGStationDlg->m_ctrlMapX.GetLayers().SetInsertionLayer(lay.m_lpDispatch);
			
			pGStationDlg->m_bSignLayerIsExist = TRUE;//Sign已经存在
			((CButton*)pGStationDlg->GetDlgItem(IDC_CHECK_LAYER_SIGN))->SetCheck(1);         //“标志层”打勾
			((CButton*)pGStationDlg->GetDlgItem(IDC_CHECK_LAYER_SIGN_SHOWSIGN))->SetCheck(1);//“显示标注”打勾
		}
		if (ClickButtonType == Open && m_comboLayer.GetCurSel() == 1) { //打开标志层
			
			CMapXLayer lay = pGStationDlg->m_ctrlMapX.GetLayers().Add( m_strDirectoryFileName, 5 );
			CString layername = lay.GetName();//如果原来就存在标志层，layername为Sign_2
			
			if (layername.Left(4) != _T("Sign")) {
				AfxMessageBox(_T("提示：请选择有标志层的tab文件打开！"));
				pGStationDlg->m_ctrlMapX.GetLayers().Remove(layername);
				return;
			}
			//layername要么是“Sign”，要么是“Sign_2”
			if (pGStationDlg->m_bSignLayerIsExist) {                   //原来标志层就存在，layername是“Sign_2”
				pGStationDlg->m_ctrlMapX.GetLayers().Remove("Sign");   //删除原来的“Sign”
				pGStationDlg->m_ctrlMapX.GetLayers().Remove(layername);//删除“Sign_2”
				//删除“Sign_2”后，再次Add后，变为“Sign”
				lay = pGStationDlg->m_ctrlMapX.GetLayers().Add( m_strDirectoryFileName, 5 );
			}else{
				//layername是“Sign”，不用再次删除添加
				pGStationDlg->m_bSignLayerIsExist = TRUE;//标志层已经存在
			}

			lay.SetSelectable(TRUE);   //设置该层目标为可选择
			lay.SetOverrideStyle(TRUE);//该层中所有Feature使用相同的style
			lay.SetEditable(TRUE);	
			lay.SetAutoLabel(TRUE);    //设置该层目标为自动标注
			
			pGStationDlg->m_ctrlMapX.GetLayers().SetInsertionLayer(lay.m_lpDispatch);
			
			((CButton*)pGStationDlg->GetDlgItem(IDC_CHECK_LAYER_SIGN))->SetCheck(1);         //“标志层”打勾
			((CButton*)pGStationDlg->GetDlgItem(IDC_CHECK_LAYER_SIGN_SHOWSIGN))->SetCheck(1);//“显示标注”打勾
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
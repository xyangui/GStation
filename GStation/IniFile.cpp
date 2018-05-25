// IniFile.cpp: implementation of the CIniFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "IniFile.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIniFile::CIniFile(CString strDirectory)
{
	CString strDirectoryFileName;
	strDirectoryFileName.Format("%s\\ini.txt",strDirectory);
	
	CFile* pFile;
	pFile=new CFile(strDirectoryFileName, CFile::modeRead|CFile::typeBinary);
	if(!pFile) {
		AfxMessageBox("ϵͳ��ʼ���ļ�ini.txt��ʧ��");
	}

	int len = pFile->GetLength();
	unsigned char* pUnChar = new unsigned char[len];
	LPVOID pData = (LPVOID)pUnChar;

	pFile->ReadHuge(pData,len);
	pFile->Close();

	pUnChar = (unsigned char*)pData;
	CString strData = pUnChar;
/*
    ��CSetSerialport����ҳ�е�ֵ��Ӧ����
0	m_comboComTele.AddString(_T("1"));
1	m_comboComTele.AddString(_T("2"));
2	m_comboComTele.AddString(_T("3"));
3	m_comboComTele.AddString(_T("4"));
4	m_comboComTele.AddString(_T("5"));
5	m_comboComTele.AddString(_T("6"));
6	m_comboComTele.SetCurSel(m_iCurSelComTele);
	
0	m_comboBT.AddString(_T("1200"));
1	m_comboBT.InsertString(1,_T("2400"));
2	m_comboBT.InsertString(2,_T("4800"));
3	m_comboBT.InsertString(3,_T("9600"));
4	m_comboBT.InsertString(4,_T("19200"));
5	m_comboBT.InsertString(5,_T("38400"));
6	m_comboBT.InsertString(6,_T("57600"));
7	m_comboBT.InsertString(7,_T("115200"));
*/
	//���ڣ�����ȡһ���ַ�
	//m_iCom=0ʱ������com1��m_iCom=1ʱ������com2���Դ�����
	m_iCom = atoi(strData.Left(1)); 
	//�����ʣ��������ڶ����ַ���ʼȡһ���ַ���Mid�ĵ�һ��������0��ʼ
	//m_iBT=0ʱ������1200��m_iBT=1ʱ������2400���Դ�����
	m_iBT = atoi(strData.Mid(1,1));
	

	/*
	CString strDirectoryFileName;
	strDirectoryFileName.Format("%s\\ini.txt",m_strDirectory);

	CFile* pFile;
	pFile = new CFile(strDirectoryFileName,CFile::modeCreate|CFile::modeRead|CFile::typeBinary|CFile::modeWrite);
	if(!pFile) {
		AfxMessageBox("ϵͳ��ʼ���ļ�ini.txt��ʧ��");
	}

	CString str;
	str.Format("%d%d",m_iCurSelCom,m_iCurSelBT);
	pFile->Write(str,str.GetLength());
	pFile->Close();*/
}

CIniFile::~CIniFile()
{

}

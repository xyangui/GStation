// Payload.cpp: implementation of the CPayload class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "Payload.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPayload::CPayload()
{
	m_iSize = 0;
	index = 0;
}

CPayload::~CPayload()
{
}

void CPayload::add(BYTE byteBuffer)
{
	m_byteBuffer[m_iSize] = byteBuffer;
	m_iSize++;//ָm_byteBuffer[2048]����Ч���ݵĴ�С
}

void CPayload::resetIndex() 
{
	index = 0;
}

int CPayload::getU1()
{
	int result = (int)m_byteBuffer[index];
	index++;
	return result;
}

int CPayload::getU2()
{
	int result;
	result = m_byteBuffer[index] * 256 + m_byteBuffer[index+1];
	index += 2;
	return result;
}

short CPayload::getI2()
{
	short result;//�����short���������λΪ1ʱ����������intʱΪ��������Ҫת���ɸ���
/*
	result = m_byteBuffer[index] * 256 + m_byteBuffer[index+1];
		//I2Ϊ����������������2���ֽڣ�ֱ�ӷ���int��4���ֽڣ���2���ֽڣ������������
	//I2���������û�����⣬����Ǹ�����Ҫת����int�ĸ���
	if(result >= 32768){//32768������Ϊ0x8000
		index = index - 65535 - 1;//65535������Ϊ0xffff
		//����Ϊ������ʽ������Ϊԭ��ȡ����+1
		//�����Ǹ������������-65535�൱����ȡ������-1
	}
*/
	result = m_byteBuffer[index];
	result = result << 8;
	result = result + m_byteBuffer[index+1];

	index += 2;

	return result;
}

int CPayload::getU2h()
{
	int result;
	result = m_byteBuffer[index] + m_byteBuffer[index+1] * 256;
	index += 2;
	return result;
}

int CPayload::getI4h()
{
	int result;
	result = m_byteBuffer[index+3] & (int)0xFF;
	result = result << 8;
	result |= m_byteBuffer[index+2] & (int)0xFF;
	result = result << 8;
	result |= m_byteBuffer[index+1] & (int)0xFF;
	result = result << 8;
	result |= m_byteBuffer[index];

	//result = m_byteBuffer[index] + m_byteBuffer[index+1] * 256;
	//result += m_byteBuffer[index+2] * 256* 256 + m_byteBuffer[index+3] * 256 * 256 * 256;
	index += 4;
	return result;
}

hyper CPayload::getU4h()
{
/*	int test = m_byteBuffer[index];
	test = m_byteBuffer[index+1];

	test = m_byteBuffer[index+1]* 256;
	test = m_byteBuffer[index+2] * 256* 256; 
	test = m_byteBuffer[index+3] * 256 * 256 * 256;
*/

	int result;
	result = m_byteBuffer[index] + m_byteBuffer[index+1] * 256;
	result += m_byteBuffer[index+2] * 256* 256 + m_byteBuffer[index+3] * 256 * 256 * 256;
	index += 4;
	return result;
}

/*
	int getU1();   //U1	  �޷���1�ֽ�	
	int getU2();   //U2	  �޷���2�ֽڣ���λ��ǰ	��int���з���4���ֽڣ���int�������ֽڴ���U2��
	int getI2();   //I2	  2�ֽ���������λ��ǰ   ��shortΪ�з���16bit���ͣ�	
	int getU2h();  //U2h  �޷���2�ֽ���������λ�ں�	����int�������ֽڴ���U2h��
	int getI4h();  //I4h  4�ֽ���������λ�ں�	
	hyper getU4h();//U4h  �޷���4�ֽ���������λ�ں�	��hyper�з���64λ���ͣ��ú�4���ֽڴ���U4h��
*/

void CPayload::putU1(int data)
{
	add((BYTE)data);
}
	
void CPayload::putU2(int data)
{
	add((BYTE)(data / 256));
	add((BYTE)data);
}

void CPayload::putI2(short data)
{
/*
	add((BYTE)(data / 256));//dataΪ����ʱ��data/256�Ͳ�֪����ʲôֵ�ˣ�
	add((BYTE)data);
*/

	add((BYTE)(data >> 8));
	add((BYTE)data);//ȡ��8λ��ǰ��ȫ����ȥ��dataΪ����ʱ��(BYTE)dataΪ������BYTEΪ�޷���
}
void CPayload::putI2(int data)//��ò���������������dataΪ������sData���ܱ������
{
	short sData = (short)data;//ȡ��16λ��ǰ��ȫ����ȥ��
	                          //data=0x00008000(32768)��sData����˸���
/*
	add((BYTE)(sData / 256));
	add((BYTE)sData);
*/

	add((BYTE)(sData >> 8));
	add((BYTE)sData);
}

void CPayload::putU2h(int data)
{
	add((BYTE)(data));
	add((BYTE)(data / 256));
}

void CPayload::putI4h(int data)
{
	add((BYTE)(data));
	add((BYTE)(data >> 8));
	add((BYTE)(data >> 16));
	add((BYTE)(data >> 24));
}

void CPayload::putU4h(hyper data)
{
/*	int test = (BYTE)(data);
	test = (BYTE)(data/256);
	test = (BYTE)(data / (256*256)); 
	test = (BYTE)(data / (256*256*256));
*/
	add((BYTE)(data));
	add((BYTE)(data/256));
	add((BYTE)(data / (256*256)));
	add((BYTE)(data / (256*256*256)));
}
//����
//m_Com�����������ݸ�ֵ��byteBuffer[]
void CPayload::putByteBuffer(BYTE byteBuffer[], int iSize)
{	
	for(int i=0; i<iSize;  i++)
		m_byteBuffer[i] = byteBuffer[i];

	m_iSize = iSize;
	index = 0;
}

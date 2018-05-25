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
	m_iSize++;//指m_byteBuffer[2048]中有效数据的大小
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
	short result;//最好用short，否则最高位为1时代表负数，用int时为正数，还要转换成负数
/*
	result = m_byteBuffer[index] * 256 + m_byteBuffer[index+1];
		//I2为有正负号整数，共2个字节，直接放在int（4个字节）后2个字节，都变成正数。
	//I2如果是整数没有问题，如果是负数需要转换成int的负数
	if(result >= 32768){//32768二进制为0x8000
		index = index - 65535 - 1;//65535二进制为0xffff
		//负数为补码形式，补码为原码取反后+1
		//本来是负数变成正数，-65535相当于再取反，再-1
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
	int getU1();   //U1	  无符号1字节	
	int getU2();   //U2	  无符号2字节，高位在前	（int是有符号4个字节，用int后两个字节代表U2）
	int getI2();   //I2	  2字节整数，高位在前   （short为有符号16bit整型）	
	int getU2h();  //U2h  无符号2字节整数，高位在后	（用int后两个字节代表U2h）
	int getI4h();  //I4h  4字节整数，高位在后	
	hyper getU4h();//U4h  无符号4字节整数，高位在后	（hyper有符号64位整型，用后4个字节代表U4h）
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
	add((BYTE)(data / 256));//data为负数时，data/256就不知道是什么值了？
	add((BYTE)data);
*/

	add((BYTE)(data >> 8));
	add((BYTE)data);//取后8位，前面全部舍去。data为负数时，(BYTE)data为正数，BYTE为无符号
}
void CPayload::putI2(int data)//最好不用这个函数，如果data为负数，sData可能变成正数
{
	short sData = (short)data;//取后16位，前面全部舍去，
	                          //data=0x00008000(32768)，sData变成了负数
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
//无用
//m_Com读出来的数据赋值给byteBuffer[]
void CPayload::putByteBuffer(BYTE byteBuffer[], int iSize)
{	
	for(int i=0; i<iSize;  i++)
		m_byteBuffer[i] = byteBuffer[i];

	m_iSize = iSize;
	index = 0;
}

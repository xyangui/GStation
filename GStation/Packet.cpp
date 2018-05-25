// Packet.cpp: implementation of the CPacket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "Packet.h"

#include "CRC.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPacket::CPacket()
{

}

const BYTE CPacket::bytePacketHead1 = 0x0A;//包第1个字节
const BYTE CPacket::bytePacketHead2 = 0xFF;//包第2个字节

CPacket::~CPacket()
{
	//delete CRC;//如果有这句，关闭程序时出错
}
//前面必须给m_msgid，payload赋值
void CPacket::generateCRC()
{
	//m_msgid = 20;//不同的包设置不同的命令类型
	CRC = new CCRC((BYTE)m_msgid);//校验和(1字节，从命令类型算起+size两个字节+参数，直到参数尾)
	
	//payload.resetIndex();
	CRC->update_checksum((BYTE)(m_len/256));//CRC是一个字节一个字节相加，先取高位相加
	CRC->update_checksum((BYTE)m_len);      //再取低位相加
	
	for (int i = 0; i < payload.m_iSize; i++)
	{
		CRC->update_checksum(payload.m_byteBuffer[i]);//不包括命令类型+size，只包括参数
	}
	CRC->finish_checksum();
}
//m_len指数据包文档定义时就应该知道包的大小，payload.m_iSize是载荷已经获得了多少
//m_len应该指读取数据包时，从第4,5个字节（0A +FF+ 命令类型(1字节)+size（2字节，高字节在前））
//获得的数据包大小
BOOL CPacket::payloadIsFilled()
{
	return (payload.m_iSize == m_len);
}

void CPacket::GetCByteArray(CByteArray &SendByteArray)
{
	SendByteArray.Add(bytePacketHead1);
	SendByteArray.Add(bytePacketHead2);

	SendByteArray.Add((BYTE)m_msgid);
	SendByteArray.Add((BYTE)(m_len/256));
	SendByteArray.Add((BYTE)m_len);

	for(int i = 0; i < payload.m_iSize; i++)
	{
		SendByteArray.Add(payload.m_byteBuffer[i]);
	}

	generateCRC();//发送时已经创建了CRC，这里又重复创建了一次
	SendByteArray.Add((BYTE)CRC->getCRCvalue());
}


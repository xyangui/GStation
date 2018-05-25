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

const BYTE CPacket::bytePacketHead1 = 0x0A;//����1���ֽ�
const BYTE CPacket::bytePacketHead2 = 0xFF;//����2���ֽ�

CPacket::~CPacket()
{
	//delete CRC;//�������䣬�رճ���ʱ����
}
//ǰ������m_msgid��payload��ֵ
void CPacket::generateCRC()
{
	//m_msgid = 20;//��ͬ�İ����ò�ͬ����������
	CRC = new CCRC((BYTE)m_msgid);//У���(1�ֽڣ���������������+size�����ֽ�+������ֱ������β)
	
	//payload.resetIndex();
	CRC->update_checksum((BYTE)(m_len/256));//CRC��һ���ֽ�һ���ֽ���ӣ���ȡ��λ���
	CRC->update_checksum((BYTE)m_len);      //��ȡ��λ���
	
	for (int i = 0; i < payload.m_iSize; i++)
	{
		CRC->update_checksum(payload.m_byteBuffer[i]);//��������������+size��ֻ��������
	}
	CRC->finish_checksum();
}
//m_lenָ���ݰ��ĵ�����ʱ��Ӧ��֪�����Ĵ�С��payload.m_iSize���غ��Ѿ�����˶���
//m_lenӦ��ָ��ȡ���ݰ�ʱ���ӵ�4,5���ֽڣ�0A +FF+ ��������(1�ֽ�)+size��2�ֽڣ����ֽ���ǰ����
//��õ����ݰ���С
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

	generateCRC();//����ʱ�Ѿ�������CRC���������ظ�������һ��
	SendByteArray.Add((BYTE)CRC->getCRCvalue());
}


// Packet.h: interface for the CPacket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PACKET_H__CB45EBA2_F9ED_41FA_981D_9018E2EAF1A2__INCLUDED_)
#define AFX_PACKET_H__CB45EBA2_F9ED_41FA_981D_9018E2EAF1A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CRC.h"
#include "Payload.h"

class CPacket  
{
public:
	CPacket();
	virtual ~CPacket();	
	
	BOOL payloadIsFilled();
	void generateCRC();

	void GetCByteArray(CByteArray &senddata);
	
	//static指所有对象都共有，const指不可改变，但是对象之间的const可以不同
	static const  BYTE bytePacketHead1; //0x0A，包第1个字节
	static const  BYTE bytePacketHead2; //0xFF，包第2个字节
	
	int m_msgid; //命令类型1个字节
	int m_len;   //不包括命令类型、size(2个字节)、CRC，只包括参数
	
	CPayload payload;//不包括命令类型、size和CRC，只包括参数
	
	CCRC *CRC;
};

#endif // !defined(AFX_PACKET_H__CB45EBA2_F9ED_41FA_981D_9018E2EAF1A2__INCLUDED_)

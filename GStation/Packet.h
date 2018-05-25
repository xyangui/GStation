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
	
	//staticָ���ж��󶼹��У�constָ���ɸı䣬���Ƕ���֮���const���Բ�ͬ
	static const  BYTE bytePacketHead1; //0x0A������1���ֽ�
	static const  BYTE bytePacketHead2; //0xFF������2���ֽ�
	
	int m_msgid; //��������1���ֽ�
	int m_len;   //�������������͡�size(2���ֽ�)��CRC��ֻ��������
	
	CPayload payload;//�������������͡�size��CRC��ֻ��������
	
	CCRC *CRC;
};

#endif // !defined(AFX_PACKET_H__CB45EBA2_F9ED_41FA_981D_9018E2EAF1A2__INCLUDED_)

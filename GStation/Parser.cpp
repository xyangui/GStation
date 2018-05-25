// Pars.cpp: implementation of the CPars class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GStation.h"
#include "Parser.h"

#include "Packet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParser::CParser()
{
	//state = MAVLINK_PARSE_STATE_UNINIT; //û�г�ʼ��
	state = MAVLINK_PARSE_STATE_HEAD1;
}

CParser::~CParser()
{

}

CPacket* CParser::link_parse_BYTE(BYTE byteBuffer)
{
	msg_received = false;

	switch (state) 
	{
	    //case MAVLINK_PARSE_STATE_UNINIT:

		case MAVLINK_PARSE_STATE_HEAD1:
			if (byteBuffer == CPacket::bytePacketHead1) //0x0A������1���ֽ�
			{
				state = MAVLINK_PARSE_STATE_GOT_HEAD1;
				m_Packet.payload.m_iSize = 0;//��0������������һ�����ݰ�������m_iSizeһֱ������
			}
			break;

		case MAVLINK_PARSE_STATE_GOT_HEAD1:
			if (byteBuffer == CPacket::bytePacketHead2) //0xFF������2���ֽ�
			{
				state = MAVLINK_PARSE_STATE_GOT_HEAD2;
			}
			else
			{
				state = MAVLINK_PARSE_STATE_HEAD1;
			}
			break;

		case MAVLINK_PARSE_STATE_GOT_HEAD2:
			m_Packet.m_msgid = (int)byteBuffer;
			state = MAVLINK_PARSE_STATE_GOT_MSGID;
			break;

		case MAVLINK_PARSE_STATE_GOT_MSGID:
			m_Packet.m_len = (int)byteBuffer;
			state = MAVLINK_PARSE_STATE_GOT_LENGTH1;
			break;

		case MAVLINK_PARSE_STATE_GOT_LENGTH1:
			m_Packet.m_len = m_Packet.m_len * 256 + (int)byteBuffer;
			state = MAVLINK_PARSE_STATE_GOT_LENGTH2;
			break;

		case MAVLINK_PARSE_STATE_GOT_LENGTH2:
			m_Packet.payload.add(byteBuffer);//payload����Ч���ݼ�1
			if (m_Packet.payloadIsFilled()) {//payload����Ч���ݴ�С��m_Packet.m_len�Ƿ����
				state = MAVLINK_PARSE_STATE_GOT_PAYLOAD;//payload�������������͡�size��CRC��ֻ��������
			}
			break;

		case MAVLINK_PARSE_STATE_GOT_PAYLOAD://�Ѿ���������İ�(������CRC)
			m_Packet.generateCRC();          //�Ѿ�����ó�CRC��m_Packet��������
			if(byteBuffer != m_Packet.CRC->getCRCvalue())//����õ���CRC���յ���CRC�����
			{
				msg_received = false;
				state = MAVLINK_PARSE_STATE_HEAD1;
				AfxMessageBox("�յ������ݰ�У��Ͳ���ȷ���Ѷ�����");
			}else{
				msg_received = true;
				state = MAVLINK_PARSE_STATE_HEAD1;
			}
			break;
	}

	if (msg_received) 
	{
		return &m_Packet;
	} else {
		return NULL;
	}
}

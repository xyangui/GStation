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
	//state = MAVLINK_PARSE_STATE_UNINIT; //没有初始化
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
			if (byteBuffer == CPacket::bytePacketHead1) //0x0A，包第1个字节
			{
				state = MAVLINK_PARSE_STATE_GOT_HEAD1;
				m_Packet.payload.m_iSize = 0;//归0，继续接收下一个数据包，否则m_iSize一直在增大
			}
			break;

		case MAVLINK_PARSE_STATE_GOT_HEAD1:
			if (byteBuffer == CPacket::bytePacketHead2) //0xFF，包第2个字节
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
			m_Packet.payload.add(byteBuffer);//payload中有效数据加1
			if (m_Packet.payloadIsFilled()) {//payload中有效数据大小与m_Packet.m_len是否相等
				state = MAVLINK_PARSE_STATE_GOT_PAYLOAD;//payload不包括命令类型、size和CRC，只包括参数
			}
			break;

		case MAVLINK_PARSE_STATE_GOT_PAYLOAD://已经获得完整的包(不包括CRC)
			m_Packet.generateCRC();          //已经计算得出CRC，m_Packet是完整的
			if(byteBuffer != m_Packet.CRC->getCRCvalue())//计算得到的CRC与收到的CRC不相等
			{
				msg_received = false;
				state = MAVLINK_PARSE_STATE_HEAD1;
				AfxMessageBox("收到的数据包校验和不正确，已丢弃！");
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

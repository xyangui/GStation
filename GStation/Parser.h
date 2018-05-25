// Parser.h: interface for the CPars class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PARS_H__7A756F2E_BAE3_404F_A07A_1F9D5AA48C56__INCLUDED_)
#define AFX_PARS_H__7A756F2E_BAE3_404F_A07A_1F9D5AA48C56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Packet.h"

class CParser  
{
public:
	CParser();
	virtual ~CParser();
	
	CPacket* link_parse_BYTE(BYTE byteBuffer);
	/**
	 * States from the parsing state machine
	 */
	enum MAV_states {
		MAVLINK_PARSE_STATE_UNINIT, 
		MAVLINK_PARSE_STATE_HEAD1, 
		MAVLINK_PARSE_STATE_GOT_HEAD1,
		MAVLINK_PARSE_STATE_GOT_HEAD2, 
		MAVLINK_PARSE_STATE_GOT_MSGID, 
		MAVLINK_PARSE_STATE_GOT_LENGTH1, 
		MAVLINK_PARSE_STATE_GOT_LENGTH2, 
		MAVLINK_PARSE_STATE_GOT_PAYLOAD
	}state;

	//static boolean msg_received;

private:
	CPacket m_Packet;
	bool msg_received;

	//MAVLinkMessage message;
};

#endif // !defined(AFX_PARS_H__7A756F2E_BAE3_404F_A07A_1F9D5AA48C56__INCLUDED_)

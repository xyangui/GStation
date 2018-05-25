// Msg_PIDData.h: interface for the CMsg_PIDData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSG_PIDDATA_H__E5FF67AD_7BB8_44A9_B76D_B94762AF7C26__INCLUDED_)
#define AFX_MSG_PIDDATA_H__E5FF67AD_7BB8_44A9_B76D_B94762AF7C26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Message.h"
#include "Payload.h"
#include "Packet.h"

class CMsg_PIDData  :public CMessage
{
public:
	CMsg_PIDData();
	virtual ~CMsg_PIDData();

	void Unpack(CPayload payload);
	CPacket GetRequestPacket();
	CPacket GetUpDataPacket();
	
	static const int MSG_ID;                 //命令id
	static const int MSG_SIZE_PAYLOAD_LENGTH;//参数长度24字节
	
	int m_fy_P;	//迎角即俯仰通道P   U1
	int m_fy_I; //迎角即俯仰通道I   U1
	int m_fy_D; //迎角即俯仰通道D   U1

	int m_gz_P; //副翼即滚转通道P   U1
	int m_gz_I; //副翼即滚转通道I   U1
	int m_gz_D; //副翼即滚转通道D   U1
	
	int m_fxd_P; //方向舵通道P   U1
	int m_fxd_I; //方向舵通道I   U1
	int m_fxd_D; //方向舵通道D   U1

	int m_gd_qg_P; //高度通道-气高P   U1
	int m_gd_qg_I; //高度通道-气高I   U1
	int m_gd_qg_D; //高度通道-气高D   U1

	int m_ks_ky_P; //空速-空油通道P   U1
	int m_ks_ky_I; //空速-空油通道I   U1
	int m_ks_ky_D; //空速-空油通道D   U1

	int m_VP; //风门补偿VP   U1
	int m_TP; //高度补偿TP   U1

	int m_phxz_P; //偏航修正通道P   U1
	int m_phxz_I; //偏航修正通道I   U1
	int m_phxz_D; //偏航修正通道D   U1

	int m_dh_P; //导航通道P   U1
	int m_dh_I; //导航通道I   U1
	int m_dh_D; //导航通道D   U1

	int m_BP; //航向参与百分比：BP   U1

	int m_ks_kf_P; //空速-空俯通道P   U1
	int m_ks_kf_I; //空速-空俯通道I   U1
	int m_ks_kf_D; //空速-空俯通道D   U1

	int m_gd_agl_P; //高度通道-AGL
	int m_gd_agl_I; //高度通道-AGL
	int m_gd_agl_D; //高度通道-AGL
};
#endif // !defined(AFX_MSG_PIDDATA_H__E5FF67AD_7BB8_44A9_B76D_B94762AF7C26__INCLUDED_)

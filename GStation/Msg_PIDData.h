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
	
	static const int MSG_ID;                 //����id
	static const int MSG_SIZE_PAYLOAD_LENGTH;//��������24�ֽ�
	
	int m_fy_P;	//ӭ�Ǽ�����ͨ��P   U1
	int m_fy_I; //ӭ�Ǽ�����ͨ��I   U1
	int m_fy_D; //ӭ�Ǽ�����ͨ��D   U1

	int m_gz_P; //������תͨ��P   U1
	int m_gz_I; //������תͨ��I   U1
	int m_gz_D; //������תͨ��D   U1
	
	int m_fxd_P; //�����ͨ��P   U1
	int m_fxd_I; //�����ͨ��I   U1
	int m_fxd_D; //�����ͨ��D   U1

	int m_gd_qg_P; //�߶�ͨ��-����P   U1
	int m_gd_qg_I; //�߶�ͨ��-����I   U1
	int m_gd_qg_D; //�߶�ͨ��-����D   U1

	int m_ks_ky_P; //����-����ͨ��P   U1
	int m_ks_ky_I; //����-����ͨ��I   U1
	int m_ks_ky_D; //����-����ͨ��D   U1

	int m_VP; //���Ų���VP   U1
	int m_TP; //�߶Ȳ���TP   U1

	int m_phxz_P; //ƫ������ͨ��P   U1
	int m_phxz_I; //ƫ������ͨ��I   U1
	int m_phxz_D; //ƫ������ͨ��D   U1

	int m_dh_P; //����ͨ��P   U1
	int m_dh_I; //����ͨ��I   U1
	int m_dh_D; //����ͨ��D   U1

	int m_BP; //�������ٷֱȣ�BP   U1

	int m_ks_kf_P; //����-�ո�ͨ��P   U1
	int m_ks_kf_I; //����-�ո�ͨ��I   U1
	int m_ks_kf_D; //����-�ո�ͨ��D   U1

	int m_gd_agl_P; //�߶�ͨ��-AGL
	int m_gd_agl_I; //�߶�ͨ��-AGL
	int m_gd_agl_D; //�߶�ͨ��-AGL
};
#endif // !defined(AFX_MSG_PIDDATA_H__E5FF67AD_7BB8_44A9_B76D_B94762AF7C26__INCLUDED_)

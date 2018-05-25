// Payload.h: interface for the CPayload class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PAYLOAD_H__4D8AA81A_7E96_4D4F_B016_9EF32AB2FF2D__INCLUDED_)
#define AFX_PAYLOAD_H__4D8AA81A_7E96_4D4F_B016_9EF32AB2FF2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPayload  
{
public:
	void add(BYTE byteBuffer);
	void putByteBuffer(BYTE byteBuffer[], int isize);

	int getU1();   //U1	  �޷���1�ֽ�	
	int getU2();   //U2	  �޷���2�ֽڣ���λ��ǰ	��int���з���4���ֽڣ���int�������ֽڴ���U2��
	short getI2(); //I2	  2�ֽ���������λ��ǰ   ��shortΪ�з���16bit���ͣ�	
	int getU2h();  //U2h  �޷���2�ֽ���������λ�ں�	����int�������ֽڴ���U2h��
	int getI4h();  //I4h  4�ֽ���������λ�ں�	
	hyper getU4h();//U4h  �޷���4�ֽ���������λ�ں�	��hyper�з���64λ���ͣ��ú�4���ֽڴ���U4h��
	
	//��֪��U2��I2��ʲô����U2�����Ƿ�������

	void putU1(int data);
	void putU2(int data);
	void putI2(short data);
	void putI2(int data);
	void putU2h(int data);
	void putI4h(int data);
	void putU4h(hyper data);

	CPayload();
	virtual ~CPayload();

	void resetIndex();

	int index;

	int m_iSize;  //ָm_byteBuffer[2048]����Ч���ݵĴ�С
	BYTE m_byteBuffer[2048];

};

#endif // !defined(AFX_PAYLOAD_H__4D8AA81A_7E96_4D4F_B016_9EF32AB2FF2D__INCLUDED_)

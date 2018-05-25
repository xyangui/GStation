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

	int getU1();   //U1	  无符号1字节	
	int getU2();   //U2	  无符号2字节，高位在前	（int是有符号4个字节，用int后两个字节代表U2）
	short getI2(); //I2	  2字节整数，高位在前   （short为有符号16bit整型）	
	int getU2h();  //U2h  无符号2字节整数，高位在后	（用int后两个字节代表U2h）
	int getI4h();  //I4h  4字节整数，高位在后	
	hyper getU4h();//U4h  无符号4字节整数，高位在后	（hyper有符号64位整型，用后4个字节代表U4h）
	
	//不知道U2和I2有什么区别，U2可以是非整数？

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

	int m_iSize;  //指m_byteBuffer[2048]中有效数据的大小
	BYTE m_byteBuffer[2048];

};

#endif // !defined(AFX_PAYLOAD_H__4D8AA81A_7E96_4D4F_B016_9EF32AB2FF2D__INCLUDED_)

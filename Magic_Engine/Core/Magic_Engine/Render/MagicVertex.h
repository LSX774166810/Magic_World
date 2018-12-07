#ifndef _MAGICVERTEX_H_
#define _MAGICVERTEX_H_

#include "Define/Magic_Macro.h"

namespace Magic
{
	class DLL_MAGIC_ENGINE_OUTPUT_INPUT VERTEX_BUFFER
	{
	public:
		enum DRAW_USAGE
		{
			DYNAMIC_DRAW = 0,
			STREAM_DRAW,
			STATIC_DRAW
		};
	private:
		struct Buffer_Attribute
		{
			unsigned int Buffer_MaxSize;
			DRAW_USAGE usage;
			Buffer_Attribute();
		};

	public:
		VERTEX_BUFFER();
		virtual ~VERTEX_BUFFER();

		void Shutdown();

		/*
		����:������������
		����:
		_number = ����������������
		����ֵ:��
		*/
		void CreateBuffer(unsigned char _number);

		/*
		����:���û�������ʽ
		����:
		_BufferPos = ���õڼ�����������
		_usage = DRAW_USAGE(��Ⱦ����)
		_number = ���ж�������
		_byteSize = ÿ������ռ�Ķ��ٸ�Float(4�ֽ�)
		_divisor = ��ʼ��Ⱦһ���µ�ʵ����ʱ����¶������Ե�����(0Ϊÿ�������Ӧһ������)
		����ֵ:��
		*/
		void SetBuffer(unsigned int _BufferPos, DRAW_USAGE _usage, unsigned int _number, unsigned int* _4byteSize, unsigned int _divisor = 0);

		/*
		����:���ü����Ⱦ�ǻ�����
		����:
		_BufferPos = ���õڼ�����������
		_usage = DRAW_USAGE(��Ⱦ����)
		����ֵ:��
		*/
		void SetDrawIndirectBuffer(unsigned int _BufferPos, DRAW_USAGE _usage);

		/*
		����:��������������
		����:
		_BufferPos = ���õڼ�����������
		_usage = DRAW_USAGE(��Ⱦ����)
		����ֵ:��
		*/
		void SetIndexBuffer(unsigned char _BufferPos, DRAW_USAGE _usage);

		/*
		����:��̬д������
		(д��GPU�����ݴ�С���Զ���������һ�δ�С)
		����:
		_BufferPos = �ڼ�����������
		_size = д���С
		_data = ��Ҫд�������
		����ֵ:��
		*/
		void DynamicWrite(unsigned int _BufferPos, unsigned int _size, void* _data);

		/*
		����:��̬д������
		(д��GPU�Ļ����С���ᷢ���ı����Ծ�������,������GPU����󻺴�����)
		����:
		_BufferPos = �ڼ�����������
		_Offset = д���ƫ�Ƶ�ַ
		_size = д���С
		_data = ��Ҫд�������
		����ֵ:��
		*/
		void StaticWrite(unsigned int _BufferPos, unsigned int _Offset, unsigned int _size, void* _data);

		/*
		����:ӳ�仺����
		����:
		_BufferPos = �ڼ�����������
		����ֵ:
		void* = ָ��ӳ�������ָ��
		*/
		void* StartUpdataVertex(unsigned char _BufferPos);

		/*
		����:�ر�ӳ�仺����
		����:
		_BufferPos = �ڼ�����������
		����ֵ:��
		*/
		void EndUpdataVertex(unsigned char _BufferPos);

		/*
		����:�󶨻�����
		����:
		_BufferPos = �ڼ�����������
		����ֵ:��
		*/
		void BindBuffer(unsigned char _BufferPos);

		/*
		����:�رհ󶨻�����
		����:
		_BufferPos = �ڼ�����������
		����ֵ:��
		*/
		void UnBindBuffer(unsigned char _BufferPos);

		/*
		����:����������
		����:��
		����ֵ:��
		*/
		void Bind();

		/*
		����:�رհ���������
		����:��
		����ֵ:��
		*/
		void UnBind();

	private:
		char m_Index_Pos;
		char m_Draw_Indirect;
		char m_Buffer_Number;
		char m_Max_CardSlot;
		Buffer_Attribute* pBuffer_Attribute;
		unsigned int m_VAO;
		unsigned int* pVBO;
	};
}

class DLL_MAGIC_ENGINE_OUTPUT_INPUT MagicVertex
{
public:
	MagicVertex();
	virtual ~MagicVertex();

	void CreateVBO(const unsigned char &_number = 1, bool _ARRAYBuffer = false);
	void BindCreate(const unsigned char &_number, unsigned char _size, unsigned int _VertexNumber, void* _data);
	void Delete();

	void* StartUpdataVertex(const unsigned char &_number);
	void EndUpdataVertex();

	void* StartUpdataIndex();
	void EndUpdataIndex();

	unsigned int GetVAO() { return vaoHandle; }
	inline unsigned int GetVertexNumber() { return m_VertexNumber; }
	inline unsigned int GetIndexNumber() { return m_IndexNumber; }
private:
	unsigned char m_vboNumber;
	unsigned int m_VertexNumber, m_IndexNumber;
	unsigned int*vboHandles;
	unsigned int vaoHandle;//vertex array object 
};

#endif
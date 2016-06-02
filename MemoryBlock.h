#pragma once
#include <stdlib.h>
#include <string.h>
typedef unsigned short USHORT;
struct MemoryBlock
{
	//����ǰ��ָ��
	MemoryBlock*prev;
	MemoryBlock* next;
	//����MemoryBlock�ܴ�С��
	int mSize;
	//δ��������
	int free;
	//�׸�δ���������
	int first;
	//Padding
	char mPad[2];
	MemoryBlock(USHORT=1, USHORT = 0);
	static void* operator new(size_t, USHORT, USHORT);
	static void operator delete(void*);
};


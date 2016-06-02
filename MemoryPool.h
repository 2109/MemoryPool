#pragma once
#include <stdlib.h>
#include <map>

typedef unsigned short USHORT;
struct MemoryBlock;


//ȫ���ڴ��Ϊ�����ࡣʹ�õ�ʱ��ֻ��Ҫһ��ʵ�����ɣ�������Ҫ���ʵ����
class MemoryPool
{
private:
	static USHORT poolMapIndex;
	//���䲻ͬ�ڴ��ʱ���Ӧ��ӳ���
	std::map<int, int>poolMap;
	//�ڴ�ض����С��
	const int POOLALIGNMENT = 8;
	//��ʼ���ڴ��
	int initBlockCount;
	//�ڴ�鲻�������Ŀ�����
	int growBlockcount;
	//�����ڴ���±�
	unsigned firstIndex;
	//ĩ�ڴ���±ꡣ
	unsigned lastIndex;
	//���16�в�ͬ�ڴ���С��Ҳ����˵���ڴ�������16����
	MemoryBlock* memoryHashMap[16];
	MemoryBlock** mpPtr;
	//���㲻ͬ�ڴ���Ӧ��hashCode
	int Hash(int);
	//�����ֽ�
	int AlignBytes(int);
	//���ط�����С��
	int GetUnitSize(int);
protected:
	static MemoryPool* memoryPoolInstance;
	MemoryPool(int initBlockSize = 1024, int growBlockSize = 256);
public:
	//�����ڴ�
	void* Alloc(int);
	//�ͷ��ڴ档
	void FreeAlloc(void*);
	//����ȫ���ڴ��ʵ��
	static MemoryPool* GetInstance();
	~MemoryPool();
};

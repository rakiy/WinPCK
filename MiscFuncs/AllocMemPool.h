#pragma once

#include <windows.h>

class CAllocMemPool
{
	// �ڵ�
	struct Node {
		// ��ڵ�
		Node*               next = nullptr;
		// �ѷ�������
		size_t              allocated = 0;
		// �ϴη���λ��
		BYTE*               last_allocated = nullptr;
		// ������
		BYTE                buffer[0];
	};

public:
	CAllocMemPool(size_t _PoolSize);
	~CAllocMemPool();

	// �����ڴ�
	void*               Alloc(size_t size, UINT32 align = sizeof(size_t));
	// �ͷ��ڴ�
	void                Free(void* address);

private:

	// ����ڵ�
	__forceinline Node* new_Node();
	// �׽ڵ�
	Node*	m_pFirstNode/* = new_Node()*/;

	size_t	m_EachPoolSize;
};

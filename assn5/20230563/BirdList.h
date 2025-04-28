#pragma once
#include "BirdNode.h"

#include <string>

class BirdList
{
private:
	BirdNode* head;
	BirdNode* tail;
public:
	BirdList();		//�� ����Ʈ ������
	~BirdList();	//�� ����Ʈ �Ҹ���

	BirdNode* GetHead() const;	//�� ����Ʈ ��� ����
	BirdNode* GetTail() const;	//�� ����Ʈ ���� ����
	void AddBirdNode(BirdNode*);	//�� �߰�
};



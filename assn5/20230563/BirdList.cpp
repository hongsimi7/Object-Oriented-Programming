#include "BirdList.h"
#include "Bird.h"
#include "Goose.h"

BirdList::BirdList() {		//�� ����Ʈ ������
	this->head = NULL;
	this->tail = NULL;
}

BirdList::~BirdList() {		//�� ����Ʈ �Ҹ���
}

BirdNode* BirdList::GetHead() const {	//�� ����Ʈ ��� ����
	return this->head;
}

BirdNode* BirdList::GetTail() const {	//�� ����Ʈ ���� ����
	return this->tail;
}

void BirdList::AddBirdNode(BirdNode* node) {		//�� �߰�
	if (this->head == NULL && this->tail == NULL)
	{
		this->head = node;
		this->tail = node;
	}
	else
	{
		this->tail->SetNext(node);
		this->tail = node;
	}
}
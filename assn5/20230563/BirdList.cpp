#include "BirdList.h"
#include "Bird.h"
#include "Goose.h"

BirdList::BirdList() {		//새 리스트 생성자
	this->head = NULL;
	this->tail = NULL;
}

BirdList::~BirdList() {		//새 리스트 소멸자
}

BirdNode* BirdList::GetHead() const {	//새 리스트 헤드 리턴
	return this->head;
}

BirdNode* BirdList::GetTail() const {	//새 리스트 테일 리턴
	return this->tail;
}

void BirdList::AddBirdNode(BirdNode* node) {		//새 추가
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
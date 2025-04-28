#pragma once
#include "BirdNode.h"

#include <string>

class BirdList
{
private:
	BirdNode* head;
	BirdNode* tail;
public:
	BirdList();		//새 리스트 생성자
	~BirdList();	//새 리스트 소멸자

	BirdNode* GetHead() const;	//새 리스트 헤드 리턴
	BirdNode* GetTail() const;	//새 리스트 테일 리턴
	void AddBirdNode(BirdNode*);	//새 추가
};



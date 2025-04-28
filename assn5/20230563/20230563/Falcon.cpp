#include "Falcon.h"

#include <iostream>

Falcon::Falcon() : Bird() {		//송골매 생성자
	job = 0;
}

Falcon::~Falcon() {			//송골매 소멸자

}

void Falcon::Skill(BirdList* birdlist) {		//송골매 스킬
	using namespace std;
	string select;	//유저 입력
	cout << "살조를 사용하겠습니까? [Y/N]: ";
	cin >> select;
	if (select == "Y")		//살조 실행
	{
		BirdNode* current = birdlist->GetHead();
		cout << "살해하고 싶은 플레이어의 이름을 입력하세요: ";
		cin >> select;
		while (current != NULL)
		{
			if (current->GetBird()->GetPlayerName() == select)	//살조하고 싶은 새의 이름을 찾았을 경우
			{
				cout <<  "전체 메시지: " << select << "이(가) 무참히 살해당하였습니다..\n";
				current->GetBird()->GoDead();
				kill = true;
				return;
			}
			current = current->GetNext();
		}
		
	}
	else if (select == "N") return;		//살조 미사용
	else;
}
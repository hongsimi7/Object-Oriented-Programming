#include "Duck.h"

#include <iostream>

Duck::Duck() : Bird() {		//오리 생성자
	job = 2;
	killability = 1;
}

Duck::~Duck() {				//오리 소멸자

}

void Duck::Skill(BirdList* birdlist) {		//오리 스킬
	using namespace std;
	string select;			//유저 입력
	cout << "살조를 사용하겠습니까? [Y/N]: ";
	cin >> select;
	if (select == "Y")		//살조 실행
	{
		if (killability == 0) //살조 불가능
		{
			cout << "라운드당 오리 진영의 살조 제한 횟수에 도달하였습니다.\n";
			return;
		}

		BirdNode* current = birdlist->GetHead();		//살조 가능
		cout << "살해하고 싶은 플레이어의 이름을 입력하세요: ";
		cin >> select;
		while (current != NULL)
		{
			if (current->GetBird()->GetPlayerName() == select)		//살조하고 싶은 새의 이름을 찾았을 경우
			{
				cout <<  "전체 메시지: " << select << "이(가) 무참히 살해당하였습니다..\n";
				killability -= 1;
				current->GetBird()->GoDead();		//새 사망
				kill = true;
				killability -= 1;
				return;
			}
			current = current->GetNext();
		}
		
	}
	else if (select == "N") return;		//살조 미사용
	else;
}
#include "DetectiveGoose.h"
#include <iostream>


DetectiveGoose::DetectiveGoose() : Bird() {		//탐정 오리 생성자
	job = 3;
}

DetectiveGoose::~DetectiveGoose() {				//탐정 오리 소멸자

}

void DetectiveGoose::Skill(BirdList* birdlist) {		//탐정 오리 스킬
	using namespace std;
	string select;		//유저 입력
	cout << "조사를 사용하시겠습니까? [Y/N]: ";
	cin >> select;
	if (select == "Y")		//조사 사용
	{
		BirdNode* current = birdlist->GetHead();
		cout << "조사하고 싶은 플레이어의 이름을 입력하세요: ";
		cin >> select;
		while (current != NULL)
		{
			if (current->GetBird()->GetPlayerName() == select)		//조사하고 싶은 새를 찾았을 경우
			{
				if (current->GetBird()->GetPlayerKill())	cout << select << "은(는) 이번 라운드에 누군가를 무참히 살해하였습니다..!\n";		//살해한 경우
				else cout <<  select << "은(는) 이번 라운드에 아무도 해치지 않았습니다.\n";			//살해하지 않은 경우
				return;
			}
			current = current->GetNext();
		}
	}
	else if (select == "N")	return;		//조사 미사용
	else;
}
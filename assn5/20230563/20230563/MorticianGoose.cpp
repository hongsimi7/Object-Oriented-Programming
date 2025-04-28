#include "MorticianGoose.h"

#include <iostream>

MorticianGoose::MorticianGoose() : Bird() {		//장의사 거위 생성자
	job = 4;
}

MorticianGoose::~MorticianGoose() {				//장의사 거위 소멸자

}

void MorticianGoose::Skill(BirdList*birdlist) {		//장의사 거위 스킬
	using namespace std;
	string select;
	cout << "염습을 사용하시겠습니까? [Y/N]: ";
	cin >> select;
	if (select == "Y")				//염습 사용
	{
		BirdNode* current = birdlist->GetHead();
		while (current != NULL)
		{
			if (current->GetBird()->checkdead())	//사망한 새가 한 마리라도 있을 경우(염습 가능)
			{
				BirdNode * findcurrent = birdlist->GetHead();
				cout << "염습하고 싶은 플레이어의 이름을 입력하세요: ";		//염습하고 싶은 새 입력
				cin >> select;
				while (findcurrent != NULL)
				{
					if (findcurrent->GetBird()->GetPlayerName() == select)		//염습하고 싶은 새를 찾은 경우
					{
						cout << select << "의 역할은 " << BirdRoleName[findcurrent->GetBird()->GetPlayerjob()] << "입니다.\n";	//직업 출력
						return;
					}
					findcurrent = findcurrent->GetNext();
				}
			}
			current = current->GetNext();
		}

		cout << "염습 가능 대상이 없습니다.\n";		//염습 불가능
		return;
	}
	else if (select == "N") return;	//염습 미사용
	else;
}
#include "AssassinDuck.h"
#include <iostream>

AssassinDuck::AssassinDuck() : Bird(){	//암살자 오리 생성자
	job = 1;
	killability = 1;
	assassinability = 2;
}

AssassinDuck::~AssassinDuck() {		//암살자 오리 소멸자

}

void AssassinDuck::Skill(BirdList* birdlist) {		//암살자 오리 스킬
	using namespace std;
	string select;		//유저 입력

	cout << "암살을 사용하겠습니까? [Y/N]: ";
	cin >> select;
	if (select == "Y")		//암살 실행
	{
		if (assassinability == 0)	//암살 불가능
		{
			cout << "더 이상 암살 능력을 사용할 수 없습니다!\n";
		}
		else				//암살 가능
		{
			int killjob;	//암살하고 싶은 직업 번호
			cout << "암살하고 싶은 플레이어의 이름을 입력하세요: ";
			cin >> select;
			cout << "암살하고 싶은 플레이어의 역할 번호를 입력하세요: ";
			cin >> killjob;
			BirdNode* current = birdlist->GetHead();
			while (current != NULL)
			{
				if (current->GetBird()->GetPlayerName() == select)	//암살하고 싶은 새의 이름을 찾았을 경우
				{
					if (current->GetBird()->GetPlayerjob() == killjob)	//암살하고 싶은 새의 직업이 알맞는 경우(암살 성공)
					{
						cout <<  "전체 메시지: " << select << "이(가) 무참히 살해당하였습니다..\n";
						current->GetBird()->GoDead();	//새 사망
						assassinability -= 1;
						kill = true;	
						break;
					}
					else				//암살하고 싶은 새의 직업이 알맞지 않은 경우(암살 실패)
					{
						cout << "전체 메시지: " << GetPlayerName() << "은(는) 극단적 선택을 하였습니다.\n";
						this->GoDead();		//암살자 오리 사망
						return;
					}
				}
				current = current->GetNext();
			}
		}
	}

	cout << "살조를 사용하겠습니까? [Y/N]: ";
	cin >> select;
	if (select == "Y")		//살조 실행
	{
		if (killability == 0)	//살조 불가능
		{
			cout << "라운드당 오리 진영의 살조 제한 횟수에 도달하였습니다.\n";
			return;
		}

		BirdNode* current = birdlist->GetHead();		//살조 가능
		cout << "살해하고 싶은 플레이어의 이름을 입력하세요: ";
		cin >> select;
		while (current != NULL)
		{
			if (current->GetBird()->GetPlayerName() == select)	//살조하고 싶은 새의 이름을 찾았을 경우
			{
				cout << "전체 메시지: " << select << "이(가) 무참히 살해당하였습니다..\n";
				current->GetBird()->GoDead();	//새 사망
				killability -= 1;
				kill = true;
				return;
			}
			current = current->GetNext();
		}

	}
	else if (select == "N") return;	//살조 미사용
	else;
}
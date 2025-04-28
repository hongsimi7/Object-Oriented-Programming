#include <iostream>
#include <string>
#include "GGD.h"
#include "Macro.h"

GGD::GGD() {
	bird_list = new BirdList();		//새 리스트 동적할당
	killability = 1;				//오리의 살조 가능 횟수
}
GGD::~GGD() {

}
void GGD::GameStart() {
	int select;						//유저 선택
	bool game_start = false;		//게임 시작 신호
	int Duck_count;					//오리 수
	int Goose_count;				//거위 수
	int Falcon_count;				//송골매 수
	int dodobird_count;				//도도새 수
	BirdNode* current;

	while (!game_start) {

		std::cout << "------------게임 설정 메뉴-------------\n";
		std::cout << "1. 플레이어 추가\n";
		std::cout << "2. 라운드당 오리 진영 살조 제한 횟수 설정\n";
		std::cout << "3. 게임 시작하기!\n";
		std::cout << "---------------------------------------\n";
		std::cout << "메뉴 번호를 입력하세요: ";
		std::cin >> select;

		switch (select)
		{
		case 1:				//플레이어 추가
			AddPlayer();
			break;
		case 2:				//오리의 살조 횟수 변경
			Changekillnumber();
			break;
		case 3:				//게임 시작
			if (bird_list->GetHead() == NULL)		//플레이어가 없을 때
			{
				std::cout << "게임을 시작할 수 없습니다!!\n";
				break;
			}

			current = bird_list->GetHead();			//새의 수 초기화
			Duck_count = 0;
			Goose_count = 0;
			Falcon_count = 0;
			dodobird_count = 0;
			
			while (current != NULL)	//새의 수 카운트
			{
				if (current->GetBird()->GetPlayerjob() == 5 || current->GetBird()->GetPlayerjob() == 4 || current->GetBird()->GetPlayerjob() == 3) Goose_count += 1;
				else if (current->GetBird()->GetPlayerjob() == 2 || current->GetBird()->GetPlayerjob() == 1) Duck_count += 1;
				else if (current->GetBird()->GetPlayerjob() == 0) Falcon_count += 1;
				else dodobird_count += 1;
				current = current->GetNext();
			}

			if ((Falcon_count + Duck_count) == 0)	//거위의 승리일 때
			{
				std::cout << "게임을 시작할 수 없습니다!!\n";
				break;
			}

			else if (Duck_count >= 1 && Duck_count >= (Falcon_count + Goose_count + dodobird_count))	//오리의 승리일 때
			{
				std::cout << "게임을 시작할 수 없습니다!!\n";
				break;
			}

			else if (Falcon_count = 1 && (Duck_count + Goose_count + dodobird_count) <= 1)		//송골매의 승리일 때
			{
				std::cout << "게임을 시작할 수 없습니다!!\n";
				break;
			}

			else {
				std::cout << "게임시작!!\n";
				game_start = true;
				break;
			}
				
		default:
			break;
		}
	}
}
void GGD::RoundProgress() {		//게임 진행
	using namespace std;
	static int count = 1;		//라운드 카운트
	int game_killability = killability;	//라운드 당 오리의 살조 횟수 초기화

	BirdNode* current = bird_list->GetHead();
	while(current != NULL)		//각각의 새의 살조 횟수 초기화
	{
		current->GetBird()->change_killability(killability);
		current = current->GetNext();
	}

	cout << "----------------Round "<< count <<"----------------\n";
	current = bird_list->GetHead();
	while (current != NULL)
	{
		if (current->GetBird()->checkdead() == false)		
		{
			if (current->GetBird()->GetPlayerjob() == 0)	//송골매일 때
			{
				cout << current->GetBird()->GetPlayerName() << "님 당신은 " << BirdRoleName[current->GetBird()->GetPlayerjob()] << "입니다.\n";
				current->GetBird()->Skill(bird_list);
			}

		}
		current = current->GetNext();
	}

	current = bird_list->GetHead();
	while (current != NULL)
	{
		if (current->GetBird()->checkdead() == false)
		{
			if (current->GetBird()->GetPlayerjob() == 1)	//암살자 오리일 때
			{
				cout << current->GetBird()->GetPlayerName() << "님 당신은 " << BirdRoleName[current->GetBird()->GetPlayerjob()] << "입니다.\n";
				current->GetBird()->Skill(bird_list);

				game_killability = current->GetBird()->check_killability();
				BirdNode* killcurrent = bird_list->GetHead();
				while (killcurrent != NULL)
				{
					killcurrent->GetBird()->change_killability(game_killability);
					killcurrent = killcurrent->GetNext();
				}
			}

		}
		current = current->GetNext();
	}

	current = bird_list->GetHead();
	while (current != NULL)
	{
		if (current->GetBird()->checkdead() == false)
		{
			if (current->GetBird()->GetPlayerjob() == 2)	//오리일 때
			{
				cout << current->GetBird()->GetPlayerName() << "님 당신은 " << BirdRoleName[current->GetBird()->GetPlayerjob()] << "입니다.\n";
				current->GetBird()->Skill(bird_list);

				game_killability = current->GetBird()->check_killability();
				BirdNode* killcurrent = bird_list->GetHead();
				while (killcurrent != NULL)
				{
					killcurrent->GetBird()->change_killability(game_killability);
					killcurrent = killcurrent->GetNext();
				}
			}

		}
		current = current->GetNext();
	}

	current = bird_list->GetHead();
	while (current != NULL)
	{
		if (current->GetBird()->checkdead() == false)	//탐정 거위일 때
		{
			if (current->GetBird()->GetPlayerjob() == 3)
			{
				cout << current->GetBird()->GetPlayerName() << "님 당신은 " << BirdRoleName[current->GetBird()->GetPlayerjob()] << "입니다.\n";
				current->GetBird()->Skill(bird_list);
			}

		}
		current = current->GetNext();
	}

	current = bird_list->GetHead();
	while (current != NULL)
	{
		if (current->GetBird()->checkdead() == false)
		{
			if (current->GetBird()->GetPlayerjob() == 4)	//장의사 거위일 때
			{
				cout << current->GetBird()->GetPlayerName() << "님 당신은 " << BirdRoleName[current->GetBird()->GetPlayerjob()] << "입니다.\n";
				current->GetBird()->Skill(bird_list);
			}

		}
		current = current->GetNext();
	}

	current = bird_list->GetHead();
	while (current != NULL)
	{
		if (current->GetBird()->checkdead() == false)
		{
			if (current->GetBird()->GetPlayerjob() == 5)	//거위일 때
			{
				cout << current->GetBird()->GetPlayerName() << "님 당신은 " << BirdRoleName[current->GetBird()->GetPlayerjob()] << "입니다.\n";
				current->GetBird()->Skill(bird_list);
			}

		}
		current = current->GetNext();
	}

	current = bird_list->GetHead();
	while (current != NULL)
	{
		if (current->GetBird()->checkdead() == false)
		{
			if (current->GetBird()->GetPlayerjob() == 6)	//도도새일 때
			{
				cout << current->GetBird()->GetPlayerName() << "님 당신은 " << BirdRoleName[current->GetBird()->GetPlayerjob()] << "입니다.\n";
				current->GetBird()->Skill(bird_list);
			}

		}
		current = current->GetNext();
	}
	
	int abstain = 0;		//무효표 수
	current = bird_list->GetHead();
	while (current != NULL)
	{
		if (current->GetBird()->checkdead() == false)
		{
			if (current->GetBird()->GetPlayerjob() == 0)		//송골매의 자동 무효표
			{
				cout << current->GetBird()->GetPlayerName() << "님은 송골매이므로 무효표에 자동 투표됩니다.\n";
				abstain += 1;
			}
			else
			{
				string select;	//유저 입력
				BirdNode* electedcurrent = bird_list->GetHead();
				cout << current->GetBird()->GetPlayerName() << "님은 투표를 하시겠습니까? [Y/N]: ";
				cin >> select;

				if (select == "Y")		//투표 사용
				{
					cout << "투표하고 싶은 플레이어의 이름을 입력하세요: ";
					cin >> select;
					while (electedcurrent != NULL)
					{
						if (electedcurrent->GetBird()->GetPlayerName() == select)
						{
							electedcurrent->GetBird()->elected();
							break;
						}
						electedcurrent = electedcurrent->GetNext();
					}
				}
				else if (select == "N")	//투표 미사용
				{
					abstain += 1;	//무효표 추가
				}
				else;
			}
		}
		current = current->GetNext();
	}

	BirdNode* mostelected = NULL;
	current = bird_list->GetHead();
	mostelected = current;
	while (current != NULL)
	{
		if (current->GetBird()->checkdead() == false)
		{
			if (mostelected->GetBird()->checkelect() < current->GetBird()->checkelect())	//가장 많은 투표를 받은 새 search
			{
				mostelected = current;
			}
		}
		current = current->GetNext();
	}
	mostelected->GetBird()->electpointed();

	current = bird_list->GetHead();
	while (current != NULL)
	{
		if (current->GetBird()->checkdead() == false)
		{
			if (mostelected->GetBird()->checkelect() == current->GetBird()->checkelect()  && current->GetBird()->checkpointed() == false)	//가장 많은 투표를 받은 새와 동일 표 수를 받은 새가 있는 경우
			{
				cout << "전체 메시지: 이번 투표에서는 아무 조류도 당첨되지 않았습니다.\n";
				count += 1;
				current = bird_list->GetHead();
				while (current != NULL)
				{
					current->GetBird()->resetelect();
					current->GetBird()->change_kill();
					current->GetBird()->resetpointed();
					current = current->GetNext();
				}
				return;
			}

			else if (abstain >= mostelected->GetBird()->checkelect())	//무효표가 더 많을 경우
			{
				cout << "전체 메시지: 이번 투표에서는 아무 조류도 당첨되지 않았습니다.\n";
				count += 1;
				current = bird_list->GetHead();
				while (current != NULL)
				{
					current->GetBird()->resetelect();
					current->GetBird()->change_kill();
					current->GetBird()->resetpointed();
					current = current->GetNext();
				}
				return;
			}
		}
		current = current->GetNext();
	}

	cout << "전체 메시지: " << mostelected->GetBird()->GetPlayerName() << "은(는) 더 좋은 곳으로 갔습니다.\n";		//투표로 의한 추방
	mostelected->GetBird()->GoDead();
	if (mostelected->GetBird()->GetPlayerjob() == 2 || mostelected->GetBird()->GetPlayerjob() == 1) cout << "전체 메시지: 만세 " << mostelected->GetBird()->GetPlayerName() << "은(는) 오리입니다!!\n";
	else cout << "전체 메시지: 맙소사 " << mostelected->GetBird()->GetPlayerName() << "은(는) 오리가 아닙니다!!\n";
	if (mostelected->GetBird()->GetPlayerjob() == 6)		//추방당한 새가 도도새일 경우
	{
		mostelected->GetBird()->windead();

	}
	count += 1;		//라운드 추가
	current = bird_list->GetHead();
	while (current != NULL)			//많은 득표를 당한 새 여부, 살조 여부, 득표 당한 횟수 초기화
	{
		current->GetBird()->resetelect();
		current->GetBird()->change_kill();
		current->GetBird()->resetpointed();
		current = current->GetNext();
	}
}

bool GGD::IsGameOver() {		//게임이 끝났는지 확인
	bool res = false;
	int Duck_count = 0;
	int Goose_count = 0;
	int Falcon_count = 0;
	int dodobird_count = 0;
	BirdNode* current = bird_list->GetHead();

	while (current != NULL)
	{
		if (current->GetBird()->checkelectdead())		//도도새의 승리
		{
			res = true;
			return res;
		}
		if (current->GetBird()->checkdead() == false)		//살아있는 모든 새 카운트
		{
			if (current->GetBird()->GetPlayerjob() == 5 || current->GetBird()->GetPlayerjob() == 4 || current->GetBird()->GetPlayerjob() == 3) Goose_count += 1;
			else if (current->GetBird()->GetPlayerjob() == 2 || current->GetBird()->GetPlayerjob() == 1) Duck_count += 1;
			else if (current->GetBird()->GetPlayerjob() == 0) Falcon_count += 1;
			else dodobird_count += 1;
		}
		current = current->GetNext();
		
	}

	if ((Falcon_count + Duck_count) == 0)	//거위의 승리
	{
		res = true;
	}

	else if (Duck_count >= 1 && Duck_count >= (Falcon_count + Goose_count + dodobird_count))	//오리의 승리
	{
		res = true;
	}

	else if (Falcon_count = 1 && (Duck_count + Goose_count + dodobird_count) <= 1)		//송골매의 승리
	{
		res = true;
	}
	return res;
}

void GGD::PrintGameResult() {		//승리 출력
	using namespace std;
	int Duck_count = 0;
	int Goose_count = 0;
	int Falcon_count = 0;
	int dodobird_count = 0;
	BirdNode* current = bird_list->GetHead();

	while (current != NULL)
	{
		if (current->GetBird()->checkelectdead())	//도도새 승리 출력
		{
			cout << "전체 메시지: 도도새의 승리입니다!";
			return;
		}
		if (current->GetBird()->checkdead() == false)	//살아있는 모든 새 카운트
		{
			if (current->GetBird()->GetPlayerjob() == 5 || current->GetBird()->GetPlayerjob() == 4 || current->GetBird()->GetPlayerjob() == 3) Goose_count += 1;
			else if (current->GetBird()->GetPlayerjob() == 2 || current->GetBird()->GetPlayerjob() == 1) Duck_count += 1;
			else if (current->GetBird()->GetPlayerjob() == 0) Falcon_count += 1;
			else dodobird_count += 1;
		}
		current = current->GetNext();
	}

	if ((Falcon_count + Duck_count) == 0)		//거위의 승리 출력
	{
		cout << "전체 메시지: 거위의 승리입니다!";
	}

	else if (Duck_count >= 1 && Duck_count >= (Falcon_count + Goose_count + dodobird_count))
	{
		if ((Falcon_count + Goose_count + dodobird_count + Duck_count) == 2 && Duck_count == 1 && Falcon_count == 1)	//송골매의 승리 출력
		{
			cout << "전체 메시지: 송골매의 승리입니다!";
		}
		else	//오리의 승리 출력
		{
			cout << "전체 메시지: 오리의 승리입니다!";
		}
	}

	else if (Falcon_count = 1 && (Duck_count + Goose_count + dodobird_count) <= 1)		//송골매의 승리 출력
	{
		cout << "전체 메시지: 송골매의 승리입니다!";
	}
}

void GGD::AddPlayer() {		//플레이어 추가
	BirdNode* newplayer = new BirdNode();

	std::string player_name;		//플레이어 이름
	std::cout << "플레이어의 이름을 입력해주세요: ";
	std::cin >> player_name;

	int role_code;		//역할 번호
	Bird* newrole = NULL;
	std::cout << "역할 번호를 입력해주세요: ";
	std::cin >> role_code;
	switch (BirdRoleCode(role_code)) {		//역할번호에 따른 플레이어 추가
	case BirdRoleCode::kFalcon:
		newrole = new Falcon();
		break;
	case BirdRoleCode::kAssassinDuck:
		newrole = new AssassinDuck();
		break;
	case BirdRoleCode::kDuck:
		newrole = new Duck();
		break;
	case BirdRoleCode::kDetectiveGoose:
		newrole = new DetectiveGoose();
		break;
	case BirdRoleCode::kMorticianGoose:
		newrole = new MorticianGoose();
		break;
	case BirdRoleCode::kGoose:
		newrole = new Goose();
		break;
	case BirdRoleCode::kDodoBird:
		newrole = new DodoBird();
		break;
	default:
		break;
	}
	newplayer->SetBird(newrole);
	newplayer->GetBird()->SetPlayerName(player_name);
	bird_list->AddBirdNode(newplayer);
}

void GGD::Changekillnumber()	//라운드 당 오리의 살조 횟수 변경
{
	int select;		//유저 입력
	std::cout << "값을 입력하세요: ";
	std::cin >> select;
	killability = select;
}
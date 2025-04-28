#include <iostream>
#include <string>
#include "GGD.h"
#include "Macro.h"

GGD::GGD() {
	bird_list = new BirdList();		//�� ����Ʈ �����Ҵ�
	killability = 1;				//������ ���� ���� Ƚ��
}
GGD::~GGD() {

}
void GGD::GameStart() {
	int select;						//���� ����
	bool game_start = false;		//���� ���� ��ȣ
	int Duck_count;					//���� ��
	int Goose_count;				//���� ��
	int Falcon_count;				//�۰�� ��
	int dodobird_count;				//������ ��
	BirdNode* current;

	while (!game_start) {

		std::cout << "------------���� ���� �޴�-------------\n";
		std::cout << "1. �÷��̾� �߰�\n";
		std::cout << "2. ����� ���� ���� ���� ���� Ƚ�� ����\n";
		std::cout << "3. ���� �����ϱ�!\n";
		std::cout << "---------------------------------------\n";
		std::cout << "�޴� ��ȣ�� �Է��ϼ���: ";
		std::cin >> select;

		switch (select)
		{
		case 1:				//�÷��̾� �߰�
			AddPlayer();
			break;
		case 2:				//������ ���� Ƚ�� ����
			Changekillnumber();
			break;
		case 3:				//���� ����
			if (bird_list->GetHead() == NULL)		//�÷��̾ ���� ��
			{
				std::cout << "������ ������ �� �����ϴ�!!\n";
				break;
			}

			current = bird_list->GetHead();			//���� �� �ʱ�ȭ
			Duck_count = 0;
			Goose_count = 0;
			Falcon_count = 0;
			dodobird_count = 0;
			
			while (current != NULL)	//���� �� ī��Ʈ
			{
				if (current->GetBird()->GetPlayerjob() == 5 || current->GetBird()->GetPlayerjob() == 4 || current->GetBird()->GetPlayerjob() == 3) Goose_count += 1;
				else if (current->GetBird()->GetPlayerjob() == 2 || current->GetBird()->GetPlayerjob() == 1) Duck_count += 1;
				else if (current->GetBird()->GetPlayerjob() == 0) Falcon_count += 1;
				else dodobird_count += 1;
				current = current->GetNext();
			}

			if ((Falcon_count + Duck_count) == 0)	//������ �¸��� ��
			{
				std::cout << "������ ������ �� �����ϴ�!!\n";
				break;
			}

			else if (Duck_count >= 1 && Duck_count >= (Falcon_count + Goose_count + dodobird_count))	//������ �¸��� ��
			{
				std::cout << "������ ������ �� �����ϴ�!!\n";
				break;
			}

			else if (Falcon_count = 1 && (Duck_count + Goose_count + dodobird_count) <= 1)		//�۰���� �¸��� ��
			{
				std::cout << "������ ������ �� �����ϴ�!!\n";
				break;
			}

			else {
				std::cout << "���ӽ���!!\n";
				game_start = true;
				break;
			}
				
		default:
			break;
		}
	}
}
void GGD::RoundProgress() {		//���� ����
	using namespace std;
	static int count = 1;		//���� ī��Ʈ
	int game_killability = killability;	//���� �� ������ ���� Ƚ�� �ʱ�ȭ

	BirdNode* current = bird_list->GetHead();
	while(current != NULL)		//������ ���� ���� Ƚ�� �ʱ�ȭ
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
			if (current->GetBird()->GetPlayerjob() == 0)	//�۰���� ��
			{
				cout << current->GetBird()->GetPlayerName() << "�� ����� " << BirdRoleName[current->GetBird()->GetPlayerjob()] << "�Դϴ�.\n";
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
			if (current->GetBird()->GetPlayerjob() == 1)	//�ϻ��� ������ ��
			{
				cout << current->GetBird()->GetPlayerName() << "�� ����� " << BirdRoleName[current->GetBird()->GetPlayerjob()] << "�Դϴ�.\n";
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
			if (current->GetBird()->GetPlayerjob() == 2)	//������ ��
			{
				cout << current->GetBird()->GetPlayerName() << "�� ����� " << BirdRoleName[current->GetBird()->GetPlayerjob()] << "�Դϴ�.\n";
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
		if (current->GetBird()->checkdead() == false)	//Ž�� ������ ��
		{
			if (current->GetBird()->GetPlayerjob() == 3)
			{
				cout << current->GetBird()->GetPlayerName() << "�� ����� " << BirdRoleName[current->GetBird()->GetPlayerjob()] << "�Դϴ�.\n";
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
			if (current->GetBird()->GetPlayerjob() == 4)	//���ǻ� ������ ��
			{
				cout << current->GetBird()->GetPlayerName() << "�� ����� " << BirdRoleName[current->GetBird()->GetPlayerjob()] << "�Դϴ�.\n";
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
			if (current->GetBird()->GetPlayerjob() == 5)	//������ ��
			{
				cout << current->GetBird()->GetPlayerName() << "�� ����� " << BirdRoleName[current->GetBird()->GetPlayerjob()] << "�Դϴ�.\n";
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
			if (current->GetBird()->GetPlayerjob() == 6)	//�������� ��
			{
				cout << current->GetBird()->GetPlayerName() << "�� ����� " << BirdRoleName[current->GetBird()->GetPlayerjob()] << "�Դϴ�.\n";
				current->GetBird()->Skill(bird_list);
			}

		}
		current = current->GetNext();
	}
	
	int abstain = 0;		//��ȿǥ ��
	current = bird_list->GetHead();
	while (current != NULL)
	{
		if (current->GetBird()->checkdead() == false)
		{
			if (current->GetBird()->GetPlayerjob() == 0)		//�۰���� �ڵ� ��ȿǥ
			{
				cout << current->GetBird()->GetPlayerName() << "���� �۰���̹Ƿ� ��ȿǥ�� �ڵ� ��ǥ�˴ϴ�.\n";
				abstain += 1;
			}
			else
			{
				string select;	//���� �Է�
				BirdNode* electedcurrent = bird_list->GetHead();
				cout << current->GetBird()->GetPlayerName() << "���� ��ǥ�� �Ͻðڽ��ϱ�? [Y/N]: ";
				cin >> select;

				if (select == "Y")		//��ǥ ���
				{
					cout << "��ǥ�ϰ� ���� �÷��̾��� �̸��� �Է��ϼ���: ";
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
				else if (select == "N")	//��ǥ �̻��
				{
					abstain += 1;	//��ȿǥ �߰�
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
			if (mostelected->GetBird()->checkelect() < current->GetBird()->checkelect())	//���� ���� ��ǥ�� ���� �� search
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
			if (mostelected->GetBird()->checkelect() == current->GetBird()->checkelect()  && current->GetBird()->checkpointed() == false)	//���� ���� ��ǥ�� ���� ���� ���� ǥ ���� ���� ���� �ִ� ���
			{
				cout << "��ü �޽���: �̹� ��ǥ������ �ƹ� ������ ��÷���� �ʾҽ��ϴ�.\n";
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

			else if (abstain >= mostelected->GetBird()->checkelect())	//��ȿǥ�� �� ���� ���
			{
				cout << "��ü �޽���: �̹� ��ǥ������ �ƹ� ������ ��÷���� �ʾҽ��ϴ�.\n";
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

	cout << "��ü �޽���: " << mostelected->GetBird()->GetPlayerName() << "��(��) �� ���� ������ �����ϴ�.\n";		//��ǥ�� ���� �߹�
	mostelected->GetBird()->GoDead();
	if (mostelected->GetBird()->GetPlayerjob() == 2 || mostelected->GetBird()->GetPlayerjob() == 1) cout << "��ü �޽���: ���� " << mostelected->GetBird()->GetPlayerName() << "��(��) �����Դϴ�!!\n";
	else cout << "��ü �޽���: ���һ� " << mostelected->GetBird()->GetPlayerName() << "��(��) ������ �ƴմϴ�!!\n";
	if (mostelected->GetBird()->GetPlayerjob() == 6)		//�߹���� ���� �������� ���
	{
		mostelected->GetBird()->windead();

	}
	count += 1;		//���� �߰�
	current = bird_list->GetHead();
	while (current != NULL)			//���� ��ǥ�� ���� �� ����, ���� ����, ��ǥ ���� Ƚ�� �ʱ�ȭ
	{
		current->GetBird()->resetelect();
		current->GetBird()->change_kill();
		current->GetBird()->resetpointed();
		current = current->GetNext();
	}
}

bool GGD::IsGameOver() {		//������ �������� Ȯ��
	bool res = false;
	int Duck_count = 0;
	int Goose_count = 0;
	int Falcon_count = 0;
	int dodobird_count = 0;
	BirdNode* current = bird_list->GetHead();

	while (current != NULL)
	{
		if (current->GetBird()->checkelectdead())		//�������� �¸�
		{
			res = true;
			return res;
		}
		if (current->GetBird()->checkdead() == false)		//����ִ� ��� �� ī��Ʈ
		{
			if (current->GetBird()->GetPlayerjob() == 5 || current->GetBird()->GetPlayerjob() == 4 || current->GetBird()->GetPlayerjob() == 3) Goose_count += 1;
			else if (current->GetBird()->GetPlayerjob() == 2 || current->GetBird()->GetPlayerjob() == 1) Duck_count += 1;
			else if (current->GetBird()->GetPlayerjob() == 0) Falcon_count += 1;
			else dodobird_count += 1;
		}
		current = current->GetNext();
		
	}

	if ((Falcon_count + Duck_count) == 0)	//������ �¸�
	{
		res = true;
	}

	else if (Duck_count >= 1 && Duck_count >= (Falcon_count + Goose_count + dodobird_count))	//������ �¸�
	{
		res = true;
	}

	else if (Falcon_count = 1 && (Duck_count + Goose_count + dodobird_count) <= 1)		//�۰���� �¸�
	{
		res = true;
	}
	return res;
}

void GGD::PrintGameResult() {		//�¸� ���
	using namespace std;
	int Duck_count = 0;
	int Goose_count = 0;
	int Falcon_count = 0;
	int dodobird_count = 0;
	BirdNode* current = bird_list->GetHead();

	while (current != NULL)
	{
		if (current->GetBird()->checkelectdead())	//������ �¸� ���
		{
			cout << "��ü �޽���: �������� �¸��Դϴ�!";
			return;
		}
		if (current->GetBird()->checkdead() == false)	//����ִ� ��� �� ī��Ʈ
		{
			if (current->GetBird()->GetPlayerjob() == 5 || current->GetBird()->GetPlayerjob() == 4 || current->GetBird()->GetPlayerjob() == 3) Goose_count += 1;
			else if (current->GetBird()->GetPlayerjob() == 2 || current->GetBird()->GetPlayerjob() == 1) Duck_count += 1;
			else if (current->GetBird()->GetPlayerjob() == 0) Falcon_count += 1;
			else dodobird_count += 1;
		}
		current = current->GetNext();
	}

	if ((Falcon_count + Duck_count) == 0)		//������ �¸� ���
	{
		cout << "��ü �޽���: ������ �¸��Դϴ�!";
	}

	else if (Duck_count >= 1 && Duck_count >= (Falcon_count + Goose_count + dodobird_count))
	{
		if ((Falcon_count + Goose_count + dodobird_count + Duck_count) == 2 && Duck_count == 1 && Falcon_count == 1)	//�۰���� �¸� ���
		{
			cout << "��ü �޽���: �۰���� �¸��Դϴ�!";
		}
		else	//������ �¸� ���
		{
			cout << "��ü �޽���: ������ �¸��Դϴ�!";
		}
	}

	else if (Falcon_count = 1 && (Duck_count + Goose_count + dodobird_count) <= 1)		//�۰���� �¸� ���
	{
		cout << "��ü �޽���: �۰���� �¸��Դϴ�!";
	}
}

void GGD::AddPlayer() {		//�÷��̾� �߰�
	BirdNode* newplayer = new BirdNode();

	std::string player_name;		//�÷��̾� �̸�
	std::cout << "�÷��̾��� �̸��� �Է����ּ���: ";
	std::cin >> player_name;

	int role_code;		//���� ��ȣ
	Bird* newrole = NULL;
	std::cout << "���� ��ȣ�� �Է����ּ���: ";
	std::cin >> role_code;
	switch (BirdRoleCode(role_code)) {		//���ҹ�ȣ�� ���� �÷��̾� �߰�
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

void GGD::Changekillnumber()	//���� �� ������ ���� Ƚ�� ����
{
	int select;		//���� �Է�
	std::cout << "���� �Է��ϼ���: ";
	std::cin >> select;
	killability = select;
}
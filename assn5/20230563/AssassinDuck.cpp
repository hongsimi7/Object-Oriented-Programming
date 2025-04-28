#include "AssassinDuck.h"
#include <iostream>

AssassinDuck::AssassinDuck() : Bird(){	//�ϻ��� ���� ������
	job = 1;
	killability = 1;
	assassinability = 2;
}

AssassinDuck::~AssassinDuck() {		//�ϻ��� ���� �Ҹ���

}

void AssassinDuck::Skill(BirdList* birdlist) {		//�ϻ��� ���� ��ų
	using namespace std;
	string select;		//���� �Է�

	cout << "�ϻ��� ����ϰڽ��ϱ�? [Y/N]: ";
	cin >> select;
	if (select == "Y")		//�ϻ� ����
	{
		if (assassinability == 0)	//�ϻ� �Ұ���
		{
			cout << "�� �̻� �ϻ� �ɷ��� ����� �� �����ϴ�!\n";
		}
		else				//�ϻ� ����
		{
			int killjob;	//�ϻ��ϰ� ���� ���� ��ȣ
			cout << "�ϻ��ϰ� ���� �÷��̾��� �̸��� �Է��ϼ���: ";
			cin >> select;
			cout << "�ϻ��ϰ� ���� �÷��̾��� ���� ��ȣ�� �Է��ϼ���: ";
			cin >> killjob;
			BirdNode* current = birdlist->GetHead();
			while (current != NULL)
			{
				if (current->GetBird()->GetPlayerName() == select)	//�ϻ��ϰ� ���� ���� �̸��� ã���� ���
				{
					if (current->GetBird()->GetPlayerjob() == killjob)	//�ϻ��ϰ� ���� ���� ������ �˸´� ���(�ϻ� ����)
					{
						cout <<  "��ü �޽���: " << select << "��(��) ������ ���ش��Ͽ����ϴ�..\n";
						current->GetBird()->GoDead();	//�� ���
						assassinability -= 1;
						kill = true;	
						break;
					}
					else				//�ϻ��ϰ� ���� ���� ������ �˸��� ���� ���(�ϻ� ����)
					{
						cout << "��ü �޽���: " << GetPlayerName() << "��(��) �ش��� ������ �Ͽ����ϴ�.\n";
						this->GoDead();		//�ϻ��� ���� ���
						return;
					}
				}
				current = current->GetNext();
			}
		}
	}

	cout << "������ ����ϰڽ��ϱ�? [Y/N]: ";
	cin >> select;
	if (select == "Y")		//���� ����
	{
		if (killability == 0)	//���� �Ұ���
		{
			cout << "����� ���� ������ ���� ���� Ƚ���� �����Ͽ����ϴ�.\n";
			return;
		}

		BirdNode* current = birdlist->GetHead();		//���� ����
		cout << "�����ϰ� ���� �÷��̾��� �̸��� �Է��ϼ���: ";
		cin >> select;
		while (current != NULL)
		{
			if (current->GetBird()->GetPlayerName() == select)	//�����ϰ� ���� ���� �̸��� ã���� ���
			{
				cout << "��ü �޽���: " << select << "��(��) ������ ���ش��Ͽ����ϴ�..\n";
				current->GetBird()->GoDead();	//�� ���
				killability -= 1;
				kill = true;
				return;
			}
			current = current->GetNext();
		}

	}
	else if (select == "N") return;	//���� �̻��
	else;
}
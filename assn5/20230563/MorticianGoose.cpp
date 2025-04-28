#include "MorticianGoose.h"

#include <iostream>

MorticianGoose::MorticianGoose() : Bird() {		//���ǻ� ���� ������
	job = 4;
}

MorticianGoose::~MorticianGoose() {				//���ǻ� ���� �Ҹ���

}

void MorticianGoose::Skill(BirdList*birdlist) {		//���ǻ� ���� ��ų
	using namespace std;
	string select;
	cout << "������ ����Ͻðڽ��ϱ�? [Y/N]: ";
	cin >> select;
	if (select == "Y")				//���� ���
	{
		BirdNode* current = birdlist->GetHead();
		while (current != NULL)
		{
			if (current->GetBird()->checkdead())	//����� ���� �� ������ ���� ���(���� ����)
			{
				BirdNode * findcurrent = birdlist->GetHead();
				cout << "�����ϰ� ���� �÷��̾��� �̸��� �Է��ϼ���: ";		//�����ϰ� ���� �� �Է�
				cin >> select;
				while (findcurrent != NULL)
				{
					if (findcurrent->GetBird()->GetPlayerName() == select)		//�����ϰ� ���� ���� ã�� ���
					{
						cout << select << "�� ������ " << BirdRoleName[findcurrent->GetBird()->GetPlayerjob()] << "�Դϴ�.\n";	//���� ���
						return;
					}
					findcurrent = findcurrent->GetNext();
				}
			}
			current = current->GetNext();
		}

		cout << "���� ���� ����� �����ϴ�.\n";		//���� �Ұ���
		return;
	}
	else if (select == "N") return;	//���� �̻��
	else;
}
#include "Falcon.h"

#include <iostream>

Falcon::Falcon() : Bird() {		//�۰�� ������
	job = 0;
}

Falcon::~Falcon() {			//�۰�� �Ҹ���

}

void Falcon::Skill(BirdList* birdlist) {		//�۰�� ��ų
	using namespace std;
	string select;	//���� �Է�
	cout << "������ ����ϰڽ��ϱ�? [Y/N]: ";
	cin >> select;
	if (select == "Y")		//���� ����
	{
		BirdNode* current = birdlist->GetHead();
		cout << "�����ϰ� ���� �÷��̾��� �̸��� �Է��ϼ���: ";
		cin >> select;
		while (current != NULL)
		{
			if (current->GetBird()->GetPlayerName() == select)	//�����ϰ� ���� ���� �̸��� ã���� ���
			{
				cout <<  "��ü �޽���: " << select << "��(��) ������ ���ش��Ͽ����ϴ�..\n";
				current->GetBird()->GoDead();
				kill = true;
				return;
			}
			current = current->GetNext();
		}
		
	}
	else if (select == "N") return;		//���� �̻��
	else;
}
#include "Duck.h"

#include <iostream>

Duck::Duck() : Bird() {		//���� ������
	job = 2;
	killability = 1;
}

Duck::~Duck() {				//���� �Ҹ���

}

void Duck::Skill(BirdList* birdlist) {		//���� ��ų
	using namespace std;
	string select;			//���� �Է�
	cout << "������ ����ϰڽ��ϱ�? [Y/N]: ";
	cin >> select;
	if (select == "Y")		//���� ����
	{
		if (killability == 0) //���� �Ұ���
		{
			cout << "����� ���� ������ ���� ���� Ƚ���� �����Ͽ����ϴ�.\n";
			return;
		}

		BirdNode* current = birdlist->GetHead();		//���� ����
		cout << "�����ϰ� ���� �÷��̾��� �̸��� �Է��ϼ���: ";
		cin >> select;
		while (current != NULL)
		{
			if (current->GetBird()->GetPlayerName() == select)		//�����ϰ� ���� ���� �̸��� ã���� ���
			{
				cout <<  "��ü �޽���: " << select << "��(��) ������ ���ش��Ͽ����ϴ�..\n";
				killability -= 1;
				current->GetBird()->GoDead();		//�� ���
				kill = true;
				killability -= 1;
				return;
			}
			current = current->GetNext();
		}
		
	}
	else if (select == "N") return;		//���� �̻��
	else;
}
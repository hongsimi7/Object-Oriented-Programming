#include "DetectiveGoose.h"
#include <iostream>


DetectiveGoose::DetectiveGoose() : Bird() {		//Ž�� ���� ������
	job = 3;
}

DetectiveGoose::~DetectiveGoose() {				//Ž�� ���� �Ҹ���

}

void DetectiveGoose::Skill(BirdList* birdlist) {		//Ž�� ���� ��ų
	using namespace std;
	string select;		//���� �Է�
	cout << "���縦 ����Ͻðڽ��ϱ�? [Y/N]: ";
	cin >> select;
	if (select == "Y")		//���� ���
	{
		BirdNode* current = birdlist->GetHead();
		cout << "�����ϰ� ���� �÷��̾��� �̸��� �Է��ϼ���: ";
		cin >> select;
		while (current != NULL)
		{
			if (current->GetBird()->GetPlayerName() == select)		//�����ϰ� ���� ���� ã���� ���
			{
				if (current->GetBird()->GetPlayerKill())	cout << select << "��(��) �̹� ���忡 �������� ������ �����Ͽ����ϴ�..!\n";		//������ ���
				else cout <<  select << "��(��) �̹� ���忡 �ƹ��� ��ġ�� �ʾҽ��ϴ�.\n";			//�������� ���� ���
				return;
			}
			current = current->GetNext();
		}
	}
	else if (select == "N")	return;		//���� �̻��
	else;
}
#include <iostream>

int main()
{
	using namespace std;

	char name[100];		//�̸� ���� ����(99�ڰ� ���� �����Ƿ� �˸°� �Ҵ�)//
	int birth;			//��� ���� ���� ����//
	int stuid;			//�й� ���� ����//

	cin >> name;					//�̸� �Է�//
	cin >> birth >> stuid;			//��� ���� �� �й� �Է�//
	cout << "My name is " << name << "." << endl;						//����� �� �̸� ���//
	cout << "I am " << 2024 - birth + 1 << " years old." << endl;		//�ѱ��� ���� ���//
	cout << "My student ID is " << stuid << ".";						//�й� ���//

	return 0;
}
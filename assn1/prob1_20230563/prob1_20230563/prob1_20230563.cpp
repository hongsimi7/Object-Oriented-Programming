#include <iostream>

int main()
{
	using namespace std;

	char name[100];		//이름 변수 생성(99자가 넘지 않으므로 알맞게 할당)//
	int birth;			//출생 연도 변수 생성//
	int stuid;			//학번 변수 생성//

	cin >> name;					//이름 입력//
	cin >> birth >> stuid;			//출생 연도 및 학번 입력//
	cout << "My name is " << name << "." << endl;						//영어로 된 이름 출력//
	cout << "I am " << 2024 - birth + 1 << " years old." << endl;		//한국식 나이 출력//
	cout << "My student ID is " << stuid << ".";						//학번 출력//

	return 0;
}
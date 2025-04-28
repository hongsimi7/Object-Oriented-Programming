#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	int choice;						//유저의 입력(선택)
	int error;						//오류 여부

	struct stu_info					//학생 정보
	{
		int id;						//학생 아이디
		char name[21];				//학생 이름
		int midterm_exam_score;		//중간 점수
		int final_exam_score;		//기말 점수
		int retake;					//재수강 여부
		char grade = 'D';			//학점
	};

	stu_info stu_list[500];			//학생 리스트
	int count = 0;					//학생 수 카운트
	

	while (true)
	{
		cout << "----------MENU----------\n";
		cout << "1. Add a student\n";
		cout << "2. Edit the score of a student\n";
		cout << "3. Print avaerage score\n";
		cout << "4. Print scores list\n";
		cout << "5. Print grades list\n";
		cout << "6. Exit\n";
		cout << "------------------------\n";
		cout << "Selection: ";
		cin >> choice;

		if (choice == 1)		//학생 추가를 입력 받았을 때
		{
			error = 0;			//오류 여부 초기화
			stu_info stu;		//학생 생성

			cout << "Student id: ";
			cin >> stu.id;									//아이디 입력
			if (stu.id < 10000000 || stu.id > 99999999)		//아이디 오류일 때
			{
				cout << "Failed to add: invalid student id!\n";
				continue;
			}

			cout << "Name: ";
			cin >> stu.name;								//이름 입력
			if (strlen(stu.name) >= 10)						//이름 오류일 때(10자 초과)
			{
				cout << "Failed to add: invalid name!\n";
				continue;
			}

			for (int i = 0; i < strlen(stu.name); i++)		//이름 오류일 때(알파벳 X)
			{
				if (int(stu.name[i]) < 65)
				{
					cout << "Failed to add: invalid name!\n";
					error = 1;
					break;
				}
				else if (int(stu.name[i]) > 90 && int(stu.name[i]) < 97)
				{
					cout << "Failed to add: invalid name!\n";
					error = 1;
					break;
				}
				else if (int(stu.name[i]) > 122)
				{
					cout << "Failed to add: invalid name!\n";
					error = 1;
					break;
				}

			}

			if (error == 1)								//오류일 때, 입력 중단
			{
				continue;
			}
			
			cout << "Midterm exam score: ";
			cin >> stu.midterm_exam_score;				//중간 점수 입력
			if (stu.midterm_exam_score < 0 || stu.midterm_exam_score > 100)		//중간 점수 오류일 때
			{
				cout << "Failed to add: invalid midterm exam score!\n";
				continue;
			}

			cout << "Final exam score: ";
			cin >> stu.final_exam_score;				//기말 점수 입력
			if (stu.final_exam_score < 0 || stu.final_exam_score > 100)			//기말 점수 오류일 때
			{
				cout << "Failed to add: invalid final exam score!\n";
				continue;
			}
			
			cout << "Retake: ";
			cin >> stu.retake;							//재수강 여부 입력
			if (!(stu.retake == 0) && !(stu.retake == 1))					//재수강 여부 오류일 때
			{
				cout << "Failed to add: invalid retake value\n";
				continue;
			}

			cout << "The student is added!\n";
			stu_list[count] = stu;						//학생 추가
			count++;									//학생 수 카운트

		}

		else if (choice == 2)		//점수 편집을 입력받았을 때
		{
			int edit_score;			//편집할 점수
			error = 1;				//오류 여부 초기화

			cout << "--------Function--------\n";
			cout << "1. Edit the midterm exam score\n";
			cout << "2. Edit the final exam score\n";
			cout << "------------------------\n";
			cout << "Selection: ";
			cin >> choice;			//유저 입력

			if (choice == 1)		//중간 점수 편집
			{
				cout << "Student id: ";
				cin >> choice;		//학생 ID 입력
				if (choice < 10000000 || choice > 99999999)		//학생 ID 오류일 때
				{
					cout << "Failed to edit: invalid student id!\n";
					continue;
				}
				for (int i = 0; i < count; i++)					//학생 찾기
				{
					if (choice == stu_list[i].id)				//학생을 찾았을 때
					{
						cout << "Score: ";
						cin >> edit_score;			
						if (edit_score > 100 || edit_score < 0)		//점수 입력 오류
						{
							cout << "Failed to edit: invalid exam score!\n";
							error = 1;
							break;
						}
						stu_list[i].midterm_exam_score = edit_score;	//점수 편집
						cout << "Score editing done!\n";
						error = 0;
						break;
					}
				}
			}

			else if (choice == 2)	//기말 점수 편집
			{
				cout << "Student id: ";
				cin >> choice;		//학생 ID 입력
				if (choice < 10000000 || choice > 99999999)		//학생 ID 오류일 때
				{
					cout << "Failed to edit: invalid student id!\n";
					continue;
				}
				for (int i = 0; i < count; i++)				//학생 찾기
				{
					if (choice == stu_list[i].id)			//학생을 찾았을 때
					{
						cout << "Score: ";
						cin >> edit_score;			
						if (edit_score > 100 || edit_score < 0)		//점수 입력 오류
						{
							cout << "Failed to edit: invalid exam score!\n";
							error = 1;
							break;
						}
						stu_list[i].final_exam_score = edit_score;	//점수 편집
						cout << "Score editing done!\n";
						error = 0;
						break;
					}				
				}
			}
			if (error == 1) cout << "Can't find the student id: " << choice << endl;	//학생을 찾지 못했을 때
		}

		else if (choice == 3)		//평균 점수 출력을 선택했을 때
		{
			int all_score = 0;		//전체 점수
			double avr_score = 0;	//평균 점수
			double sd = 0;			//표준 편차
			int sd_all_score = 0;	//표준 편차를 계산을 위한 시그마값

			if (count == 0)			//학생 수가 0명일 때
			{
				cout << "Average score: " << avr_score << endl;
				cout << "Standard deviation: " << sd << endl;
				continue;
			}
			for (int i = 0; i < count; i++)		//전체 점수 계산
			{
				all_score += stu_list[i].midterm_exam_score + stu_list[i].final_exam_score;
			}
			avr_score = all_score / count;		//평균 점수 계산
			
			for (int i = 0; i < count; i++)		//sd_all_score 계산
			{
				sd_all_score += ((stu_list[i].midterm_exam_score + stu_list[i].final_exam_score) - avr_score) * ((stu_list[i].midterm_exam_score + stu_list[i].final_exam_score) - avr_score);
			}
			sd = sqrt(sd_all_score / count);	//표준 편차 계산
			cout.precision(5);					//소수점 5자리까지 제한
			cout << "Average score: " << avr_score << endl;		//평균 출력
			cout << "Standard deviation: " << sd << endl;		//표준 편차 출력
		}

		else if (choice == 4)		//점수표 출력을 선택했을 때
		{		
			for (int i = 0; i < count - 1; i++)		
			{
				for (int j = 0; j < count - i - 1; j++)		//bubble sort를 통해 내림차순으로 정렬
				{
					if ((stu_list[j].midterm_exam_score + stu_list[j].final_exam_score) < (stu_list[j + 1].midterm_exam_score + stu_list[j + 1].final_exam_score))	//내림차순으로 정렬
					{
						stu_info temp = stu_list[j];
						stu_list[j] = stu_list[j + 1];
						stu_list[j + 1] = temp;
					}
					else if ((stu_list[j].midterm_exam_score + stu_list[j].final_exam_score) == (stu_list[j + 1].midterm_exam_score + stu_list[j + 1].final_exam_score) && stu_list[j].id  > stu_list[j+1].id)		//점수가 같을 때, 학번 기준으로 오름차순 정렬
					{
						stu_info temp = stu_list[j];
						stu_list[j] = stu_list[j + 1];
						stu_list[j + 1] = temp;
					}
				}
			}

			for (int i = 0; i < count; i++) cout << stu_list[i].id << " " << stu_list[i].name << " " << stu_list[i].midterm_exam_score << " " << stu_list[i].final_exam_score << " " << stu_list[i].midterm_exam_score + stu_list[i].final_exam_score << endl; //정렬된 결과 출력
			cout << "Finished printing the list!" << endl;
		}

		else if (choice == 5)								//등급표 출력을 선택했을 때
		{
			for (int i = 0; i < count - 1; i++)				//bubble sort를 통한 내림차순 정렬
			{
				for (int j = 0; j < count - i - 1; j++)
				{
					if ((stu_list[j].midterm_exam_score + stu_list[j].final_exam_score) < (stu_list[j + 1].midterm_exam_score + stu_list[j + 1].final_exam_score))
					{
						stu_info temp = stu_list[j];
						stu_list[j] = stu_list[j + 1];
						stu_list[j + 1] = temp;
					}
				}
			}

			for (int i = 0; i < count; i++)
			{
				if ((stu_list[i].midterm_exam_score + stu_list[i].final_exam_score) > 150)	//총점 150점 초과
				{
					if (double(count) * 0.3 < 1 && i == 0) stu_list[i].grade = 'A';			//학생 수 * 0.3이 1미만일 경우, 상위 1등 'A'

					else if (i+1 <= double(count) * 0.3) stu_list[i].grade = 'A';			//상위 30% 이내인 경우
				}
				if ((stu_list[i].midterm_exam_score + stu_list[i].final_exam_score) > 100 && stu_list[i].grade != 'A')	//총점 100점 초과이고 학점이 A가 아닌 경우
				{
					if (double(count) * 0.7 < 2 && i == 1) stu_list[i].grade = 'B';			//학생 수 * 0.7이 2미만일 경우, 상위 2등 'B'

					else if (i+1 <= double(count) * 0.7) stu_list[i].grade = 'B';			//상위 70% 이내인 경우
				}
				if ((stu_list[i].midterm_exam_score + stu_list[i].final_exam_score) > 50 && stu_list[i].grade != 'A' && stu_list[i].grade != 'B')	//총점 50점 초과 학점이 A와 B가 아닌 경우
				{
					if (double(count) * 0.9 < 3 && i == 2) stu_list[i].grade = 'C';			//학생 수 * 0.9가 3미만일 경우 3등 'C'

					else if (i + 1 < double(count) * 0.9) stu_list[i].grade = 'C';			//하위 10% 이내가 아닐 경우
				}
				if (stu_list[i].retake == 1)	//재수강했을 때, 다운그레이드
				{
					if (stu_list[i].grade == 'A') stu_list[i].grade = 'B';
					else if (stu_list[i].grade == 'B') stu_list[i].grade = 'C';
					else if (stu_list[i].grade == 'C') stu_list[i].grade = 'D';
				}
			}
			for (int i = 0; i < count; i++) cout << stu_list[i].id << " " << stu_list[i].name << " " << stu_list[i].midterm_exam_score + stu_list[i].final_exam_score << " " << stu_list[i].retake << " " << stu_list[i].grade << endl;		//등급표 출력
		}

		else		//프로그램 종료를 할 때
		{
			cout << "Good Bye!";
			break;
		}
	}
	return 0;
}
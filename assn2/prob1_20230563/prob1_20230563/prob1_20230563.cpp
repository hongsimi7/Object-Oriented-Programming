#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;

	int choice;						//������ �Է�(����)
	int error;						//���� ����

	struct stu_info					//�л� ����
	{
		int id;						//�л� ���̵�
		char name[21];				//�л� �̸�
		int midterm_exam_score;		//�߰� ����
		int final_exam_score;		//�⸻ ����
		int retake;					//����� ����
		char grade = 'D';			//����
	};

	stu_info stu_list[500];			//�л� ����Ʈ
	int count = 0;					//�л� �� ī��Ʈ
	

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

		if (choice == 1)		//�л� �߰��� �Է� �޾��� ��
		{
			error = 0;			//���� ���� �ʱ�ȭ
			stu_info stu;		//�л� ����

			cout << "Student id: ";
			cin >> stu.id;									//���̵� �Է�
			if (stu.id < 10000000 || stu.id > 99999999)		//���̵� ������ ��
			{
				cout << "Failed to add: invalid student id!\n";
				continue;
			}

			cout << "Name: ";
			cin >> stu.name;								//�̸� �Է�
			if (strlen(stu.name) >= 10)						//�̸� ������ ��(10�� �ʰ�)
			{
				cout << "Failed to add: invalid name!\n";
				continue;
			}

			for (int i = 0; i < strlen(stu.name); i++)		//�̸� ������ ��(���ĺ� X)
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

			if (error == 1)								//������ ��, �Է� �ߴ�
			{
				continue;
			}
			
			cout << "Midterm exam score: ";
			cin >> stu.midterm_exam_score;				//�߰� ���� �Է�
			if (stu.midterm_exam_score < 0 || stu.midterm_exam_score > 100)		//�߰� ���� ������ ��
			{
				cout << "Failed to add: invalid midterm exam score!\n";
				continue;
			}

			cout << "Final exam score: ";
			cin >> stu.final_exam_score;				//�⸻ ���� �Է�
			if (stu.final_exam_score < 0 || stu.final_exam_score > 100)			//�⸻ ���� ������ ��
			{
				cout << "Failed to add: invalid final exam score!\n";
				continue;
			}
			
			cout << "Retake: ";
			cin >> stu.retake;							//����� ���� �Է�
			if (!(stu.retake == 0) && !(stu.retake == 1))					//����� ���� ������ ��
			{
				cout << "Failed to add: invalid retake value\n";
				continue;
			}

			cout << "The student is added!\n";
			stu_list[count] = stu;						//�л� �߰�
			count++;									//�л� �� ī��Ʈ

		}

		else if (choice == 2)		//���� ������ �Է¹޾��� ��
		{
			int edit_score;			//������ ����
			error = 1;				//���� ���� �ʱ�ȭ

			cout << "--------Function--------\n";
			cout << "1. Edit the midterm exam score\n";
			cout << "2. Edit the final exam score\n";
			cout << "------------------------\n";
			cout << "Selection: ";
			cin >> choice;			//���� �Է�

			if (choice == 1)		//�߰� ���� ����
			{
				cout << "Student id: ";
				cin >> choice;		//�л� ID �Է�
				if (choice < 10000000 || choice > 99999999)		//�л� ID ������ ��
				{
					cout << "Failed to edit: invalid student id!\n";
					continue;
				}
				for (int i = 0; i < count; i++)					//�л� ã��
				{
					if (choice == stu_list[i].id)				//�л��� ã���� ��
					{
						cout << "Score: ";
						cin >> edit_score;			
						if (edit_score > 100 || edit_score < 0)		//���� �Է� ����
						{
							cout << "Failed to edit: invalid exam score!\n";
							error = 1;
							break;
						}
						stu_list[i].midterm_exam_score = edit_score;	//���� ����
						cout << "Score editing done!\n";
						error = 0;
						break;
					}
				}
			}

			else if (choice == 2)	//�⸻ ���� ����
			{
				cout << "Student id: ";
				cin >> choice;		//�л� ID �Է�
				if (choice < 10000000 || choice > 99999999)		//�л� ID ������ ��
				{
					cout << "Failed to edit: invalid student id!\n";
					continue;
				}
				for (int i = 0; i < count; i++)				//�л� ã��
				{
					if (choice == stu_list[i].id)			//�л��� ã���� ��
					{
						cout << "Score: ";
						cin >> edit_score;			
						if (edit_score > 100 || edit_score < 0)		//���� �Է� ����
						{
							cout << "Failed to edit: invalid exam score!\n";
							error = 1;
							break;
						}
						stu_list[i].final_exam_score = edit_score;	//���� ����
						cout << "Score editing done!\n";
						error = 0;
						break;
					}				
				}
			}
			if (error == 1) cout << "Can't find the student id: " << choice << endl;	//�л��� ã�� ������ ��
		}

		else if (choice == 3)		//��� ���� ����� �������� ��
		{
			int all_score = 0;		//��ü ����
			double avr_score = 0;	//��� ����
			double sd = 0;			//ǥ�� ����
			int sd_all_score = 0;	//ǥ�� ������ ����� ���� �ñ׸���

			if (count == 0)			//�л� ���� 0���� ��
			{
				cout << "Average score: " << avr_score << endl;
				cout << "Standard deviation: " << sd << endl;
				continue;
			}
			for (int i = 0; i < count; i++)		//��ü ���� ���
			{
				all_score += stu_list[i].midterm_exam_score + stu_list[i].final_exam_score;
			}
			avr_score = all_score / count;		//��� ���� ���
			
			for (int i = 0; i < count; i++)		//sd_all_score ���
			{
				sd_all_score += ((stu_list[i].midterm_exam_score + stu_list[i].final_exam_score) - avr_score) * ((stu_list[i].midterm_exam_score + stu_list[i].final_exam_score) - avr_score);
			}
			sd = sqrt(sd_all_score / count);	//ǥ�� ���� ���
			cout.precision(5);					//�Ҽ��� 5�ڸ����� ����
			cout << "Average score: " << avr_score << endl;		//��� ���
			cout << "Standard deviation: " << sd << endl;		//ǥ�� ���� ���
		}

		else if (choice == 4)		//����ǥ ����� �������� ��
		{		
			for (int i = 0; i < count - 1; i++)		
			{
				for (int j = 0; j < count - i - 1; j++)		//bubble sort�� ���� ������������ ����
				{
					if ((stu_list[j].midterm_exam_score + stu_list[j].final_exam_score) < (stu_list[j + 1].midterm_exam_score + stu_list[j + 1].final_exam_score))	//������������ ����
					{
						stu_info temp = stu_list[j];
						stu_list[j] = stu_list[j + 1];
						stu_list[j + 1] = temp;
					}
					else if ((stu_list[j].midterm_exam_score + stu_list[j].final_exam_score) == (stu_list[j + 1].midterm_exam_score + stu_list[j + 1].final_exam_score) && stu_list[j].id  > stu_list[j+1].id)		//������ ���� ��, �й� �������� �������� ����
					{
						stu_info temp = stu_list[j];
						stu_list[j] = stu_list[j + 1];
						stu_list[j + 1] = temp;
					}
				}
			}

			for (int i = 0; i < count; i++) cout << stu_list[i].id << " " << stu_list[i].name << " " << stu_list[i].midterm_exam_score << " " << stu_list[i].final_exam_score << " " << stu_list[i].midterm_exam_score + stu_list[i].final_exam_score << endl; //���ĵ� ��� ���
			cout << "Finished printing the list!" << endl;
		}

		else if (choice == 5)								//���ǥ ����� �������� ��
		{
			for (int i = 0; i < count - 1; i++)				//bubble sort�� ���� �������� ����
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
				if ((stu_list[i].midterm_exam_score + stu_list[i].final_exam_score) > 150)	//���� 150�� �ʰ�
				{
					if (double(count) * 0.3 < 1 && i == 0) stu_list[i].grade = 'A';			//�л� �� * 0.3�� 1�̸��� ���, ���� 1�� 'A'

					else if (i+1 <= double(count) * 0.3) stu_list[i].grade = 'A';			//���� 30% �̳��� ���
				}
				if ((stu_list[i].midterm_exam_score + stu_list[i].final_exam_score) > 100 && stu_list[i].grade != 'A')	//���� 100�� �ʰ��̰� ������ A�� �ƴ� ���
				{
					if (double(count) * 0.7 < 2 && i == 1) stu_list[i].grade = 'B';			//�л� �� * 0.7�� 2�̸��� ���, ���� 2�� 'B'

					else if (i+1 <= double(count) * 0.7) stu_list[i].grade = 'B';			//���� 70% �̳��� ���
				}
				if ((stu_list[i].midterm_exam_score + stu_list[i].final_exam_score) > 50 && stu_list[i].grade != 'A' && stu_list[i].grade != 'B')	//���� 50�� �ʰ� ������ A�� B�� �ƴ� ���
				{
					if (double(count) * 0.9 < 3 && i == 2) stu_list[i].grade = 'C';			//�л� �� * 0.9�� 3�̸��� ��� 3�� 'C'

					else if (i + 1 < double(count) * 0.9) stu_list[i].grade = 'C';			//���� 10% �̳��� �ƴ� ���
				}
				if (stu_list[i].retake == 1)	//��������� ��, �ٿ�׷��̵�
				{
					if (stu_list[i].grade == 'A') stu_list[i].grade = 'B';
					else if (stu_list[i].grade == 'B') stu_list[i].grade = 'C';
					else if (stu_list[i].grade == 'C') stu_list[i].grade = 'D';
				}
			}
			for (int i = 0; i < count; i++) cout << stu_list[i].id << " " << stu_list[i].name << " " << stu_list[i].midterm_exam_score + stu_list[i].final_exam_score << " " << stu_list[i].retake << " " << stu_list[i].grade << endl;		//���ǥ ���
		}

		else		//���α׷� ���Ḧ �� ��
		{
			cout << "Good Bye!";
			break;
		}
	}
	return 0;
}
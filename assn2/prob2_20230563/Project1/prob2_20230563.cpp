#include <iostream>
#include <iomanip>
#include <string>

int main()
{
	using namespace std;

	string code;				//������ ����
	string text;				//�Է¹��� ����
	char ch;					//�Է¹��� �ܾ� �� ��
	int dot_count = 0;			//������ ����
	int word_count = 0;			//�ܾ��� ����
	int noise_count = 0;		//�������� ����

	cout << "Enter a cyphertext\n";

	while (cin.get(ch))			//�ܾ� �ޱ� ����
	{
		

		text += ch;				//�ܾ ���忡 �߰�
		word_count++;			//�ܾ��� �� �߰�

		if (ch == '.')			//������ �޾��� ��
		{
			dot_count += 1;		//������ �� �߰�
			if (dot_count == 2) break;		//������ ���� 2�����, �ܾ� �ޱ� ����.
		}
		else if (dot_count == 1) dot_count = 0;		//������ ���� �ʰ�, ������ ���� 1����� ������ �� 0���� �ʱ�ȭ

		if (ch == '#' || ch == '$' || ch == '%' || ch == '&' || ch == '*') noise_count++;				//�������� �� �߰�
		if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == 'A' || ch == 'B' || ch == 'C' || ch == 'D' || ch == 'E' || ch == 'F') code += ch;	//������ ���忡 �߰�
	}

	cout.precision(5);		//�Ҽ��� 5��° �ڸ������� ����
	cout << "Ciphertext noise rate: " << (double(noise_count) /double(word_count) * 100) << "%\n";		//������ ���� ���
	int error = 0;		//���� ���� ����

	if (code.length() == 0) cout << "Undercryptable: where are the hexadecimal digits!\n";			//������ ������ ���� ��

	else if (code.length() % 2 == 1)		//������ ������ �ܾ� ���� Ȧ���� ��
	{
		cout << "Hexadecimal digits: " << code << endl;
		cout << "Undecryptable: the number of hexadecimal digits is odd!\n";
	}

	else									//������ ������ �ܾ� ���� ¦���� ��
	{
		cout << "Hexadecimal digits: " << code << endl;			//������ ���� ���
		string decoding_text;									//������ ���� ����

		for (int i = 0; i < code.length(); i += 2)				//���� ����
		{
			int decoding = stoi(code.substr(i, 2), nullptr, 16);
			if (decoding < 0 || decoding >127)
			{
				cout << "Undecryptable: invalid hexadecimal digits pair!\n";		//�ƽ�Ű �ڵ�ǥ�� ���� �Ѿ�� ��
				error = 1;										//���� �߻� ����
				break;
			}
			decoding_text += decoding;
		}
		
		if (error == 0) cout << "Decryption result: " << decoding_text << endl;		//������ ���� ���
		
	}
	cout << "Decryptor turn off!";
	return 0;

}
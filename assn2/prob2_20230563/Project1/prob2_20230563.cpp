#include <iostream>
#include <iomanip>
#include <string>

int main()
{
	using namespace std;

	string code;				//번역할 문장
	string text;				//입력받은 문장
	char ch;					//입력받은 단어 한 개
	int dot_count = 0;			//온점의 개수
	int word_count = 0;			//단어의 개수
	int noise_count = 0;		//노이즈의 개수

	cout << "Enter a cyphertext\n";

	while (cin.get(ch))			//단어 받기 진행
	{
		

		text += ch;				//단어를 문장에 추가
		word_count++;			//단어의 수 추가

		if (ch == '.')			//온점을 받았을 때
		{
			dot_count += 1;		//온점의 수 추가
			if (dot_count == 2) break;		//온점의 수가 2개라면, 단어 받기 멈춤.
		}
		else if (dot_count == 1) dot_count = 0;		//온점을 받지 않고, 온점의 수가 1개라면 온점의 수 0으로 초기화

		if (ch == '#' || ch == '$' || ch == '%' || ch == '&' || ch == '*') noise_count++;				//노이즈의 수 추가
		if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' || ch == 'A' || ch == 'B' || ch == 'C' || ch == 'D' || ch == 'E' || ch == 'F') code += ch;	//번역할 문장에 추가
	}

	cout.precision(5);		//소수점 5번째 자리까지로 제한
	cout << "Ciphertext noise rate: " << (double(noise_count) /double(word_count) * 100) << "%\n";		//노이즈 비율 출력
	int error = 0;		//오류 감지 변수

	if (code.length() == 0) cout << "Undercryptable: where are the hexadecimal digits!\n";			//번역할 문장이 없을 때

	else if (code.length() % 2 == 1)		//번역할 문장의 단어 수가 홀수일 때
	{
		cout << "Hexadecimal digits: " << code << endl;
		cout << "Undecryptable: the number of hexadecimal digits is odd!\n";
	}

	else									//번역할 문장의 단어 수가 짝수일 때
	{
		cout << "Hexadecimal digits: " << code << endl;			//번역할 문장 출력
		string decoding_text;									//번역된 문장 변수

		for (int i = 0; i < code.length(); i += 2)				//번역 진행
		{
			int decoding = stoi(code.substr(i, 2), nullptr, 16);
			if (decoding < 0 || decoding >127)
			{
				cout << "Undecryptable: invalid hexadecimal digits pair!\n";		//아스키 코드표의 수를 넘어갔을 때
				error = 1;										//에러 발생 감지
				break;
			}
			decoding_text += decoding;
		}
		
		if (error == 0) cout << "Decryption result: " << decoding_text << endl;		//번역된 문장 출력
		
	}
	cout << "Decryptor turn off!";
	return 0;

}
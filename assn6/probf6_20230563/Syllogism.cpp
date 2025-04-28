#include <iostream>
#include "MultiHeadList.h"

using namespace std;

class Syllogism {
private :
	MultiHeadList<pair<string,string>>syl;
public :
	void put(const pair<string, string>& argument) 
	{
		for (int i = 0; i != syl.headSize(); ++i)
		{
			if (syl.begin(i).curr->data.first == argument.second)	//맨 앞에 삽입
			{
				syl.push_front(argument, i);
				for (int j = 0; j != syl.headSize(); ++j)
				{
					if (j != i && syl.rbegin(j).curr->data.second == argument.first)	//A->B / B-> C 병합
					{
						syl.merge(j, i);
						return;
					}
				}
				return;
			}

			else if (syl.rbegin(i).curr->data.second == argument.first)		//맨 뒤에 삽입
			{
				syl.push_back(argument, i);
				for (int j = 0; j != syl.headSize(); ++j)
				{
					if (j != i && syl.begin(j).curr->data.first == argument.second)	//A->B / B-> C 병합
					{
						syl.merge(i, j);
						return;
					}
				}
				return;
			}
		}
		syl.push_front(argument);		//새로 삽입
	}
	void qna(const string& q) 
	{
		for (int i = 0; i != syl.headSize(); ++i)		//전제 찾기
		{
			MultiHeadList<pair<string, string>>::Iterator it = syl.begin(i);	//iterator 생성
			for (auto ar = syl.begin(i); ar != syl.end(); ++ar)
			{
				if (ar.curr->data.first == q) break;		//전제를 찾았을 때
				else ++it;
			}
			if (it != syl.end())		//전제를 찾았을 때
			{
				MultiHeadList<pair<string, string>>::ReverseIterator ri = syl.rbegin(i);
				cout << "If " << it.curr->data.first << ", then " << ri.curr->data.second << endl;	//논리 출력
				break;
			}
		}
	}
	void print() {
		cout << "=============" << endl;
		for (int i = 0; i != syl.headSize(); i++) {
			cout << i << " : ";
			for (auto it = syl.begin(i); it != syl.end(); it++) {
				if (it == syl.begin(i)) {
					cout << (*it).first << "->" << (*it).second;
				}
				else {
					cout << "->" << (*it).second;
				}
			}
			cout << endl;
		}
	}
};
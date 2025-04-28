#pragma once
#include <vector>
#include <string>
#include <iostream>

class Map
{
private:
	std::vector<std::vector<std::string>> element;		//맵의 요소
	std::vector<std::vector<std::string>> condition;	//맵의 개척 현황
	int char_row;	//캐릭터의 위치(row)
	int char_col;	//캐릭터의 위치(column)

public:
	Map();			//맵 생성자
	~Map() {};		//맵 소멸자

	int w_move();	//위로 캐릭터가 이동할 수 있는지 확인하는 메서드
	int a_move();	//왼쪽으로 캐릭터가 이동할 수 있는지 확인하는 메서드
	int s_move();	//아래로 캐릭터가 이동할 수 있는지 확인하는 메서드
	int d_move();	//오른쪽으로 캐릭터가 이동할 수 있는지 확인하는 메서드

	int check_map();	//이동 칸의 이벤트를 확인하는 메서드

	void make_empty();	//빈칸으로 만드는 메서드
	void show();		//맵을 보여주는 메서드

	int manhattan_dist();	//출발점으로부터 거리를 출력하는 메서드초
};
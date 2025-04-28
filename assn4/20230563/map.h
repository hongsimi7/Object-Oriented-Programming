#pragma once
#include <vector>
#include <string>
#include <iostream>

class Map
{
private:
	std::vector<std::vector<std::string>> element;		//���� ���
	std::vector<std::vector<std::string>> condition;	//���� ��ô ��Ȳ
	int char_row;	//ĳ������ ��ġ(row)
	int char_col;	//ĳ������ ��ġ(column)

public:
	Map();			//�� ������
	~Map() {};		//�� �Ҹ���

	int w_move();	//���� ĳ���Ͱ� �̵��� �� �ִ��� Ȯ���ϴ� �޼���
	int a_move();	//�������� ĳ���Ͱ� �̵��� �� �ִ��� Ȯ���ϴ� �޼���
	int s_move();	//�Ʒ��� ĳ���Ͱ� �̵��� �� �ִ��� Ȯ���ϴ� �޼���
	int d_move();	//���������� ĳ���Ͱ� �̵��� �� �ִ��� Ȯ���ϴ� �޼���

	int check_map();	//�̵� ĭ�� �̺�Ʈ�� Ȯ���ϴ� �޼���

	void make_empty();	//��ĭ���� ����� �޼���
	void show();		//���� �����ִ� �޼���

	int manhattan_dist();	//��������κ��� �Ÿ��� ����ϴ� �޼�����
};
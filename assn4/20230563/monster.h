#pragma once
#include <string>
class Monster
{
private:
	int attack;
	int defense;
	int curr_hp;
	int max_hp;
	int reward;
	std::string type;

public:
	Monster();			//���� ������
	Monster(int dist);	//�Ϲ� ���� ������
	~Monster() {};		//���� �Ҹ���

	void show();		//������ ���� ��� �޼���
	int show_defense();					//������ ���� ��� �޼���
	int show_hp();						//������ HP ��� �޼���
	int show_reward();					//������ ���� ��� �޼���
	std::string show_type();			//������ Ÿ�� ��� �޼���

	int monster_attack(int char_def);	//ĳ���� ���¿� ���� ������ ���� ������ ��� �޼���
	void lost_hp(int damage);			//ĳ������ �������� ���� ������ HP ���� �޼���
};


#include "monster.h"
#include <cstdlib>
#include <iostream>

Monster::Monster()	//���� ������
{
	max_hp = 200;
	curr_hp = max_hp;
	attack = 30;
	defense = 10;
	reward = 0;

	int rand_type = rand();
	if (rand_type % 4 == 0) type = "fire";
	else if (rand_type % 4 == 1) type = "water";
	else if (rand_type % 4 == 2) type = "grass";
	else type = "normal";
}
Monster::Monster(int dist)	//�Ϲ� ���� ������
{
	max_hp = 50 + (dist * 5);
	curr_hp = max_hp;
	attack = 5 + (dist * 2);
	defense = 2 + (dist / 2);
	reward = 100 + (dist * 10);
	
	int rand_type = rand();
	if (rand_type % 4 == 0) type = "fire";
	else if (rand_type % 4 == 1) type = "water";
	else if (rand_type % 4 == 2) type = "grass";
	else type = "normal";
}

void Monster::show()	//������ ���� ��� �޼���
{
	std::cout << "Monster status\n";
	std::cout << "Attack: " << attack << std::endl;
	std::cout << "Defense: " << defense << std::endl;
	std::cout << "HP: " << curr_hp << " / " << max_hp << std::endl;
}

void Monster::lost_hp(int damage)			//ĳ������ �������� ���� ������ HP ���� �޼���
{
	curr_hp -= damage;
	if (curr_hp < 0) curr_hp = 0;
}

int Monster::monster_attack(int char_def)	//ĳ���� ���¿� ���� ������ ���� ������ ��� �޼���
{
	int damage = attack - char_def;
	return damage;
}

int Monster::show_defense()	//������ ���� ��� �޼���
{
	return defense;
}

std::string Monster::show_type()	//������ Ÿ�� ��� �޼���
{
	return type;
}

int Monster::show_hp()	//������ HP ��� �޼���
{
	return curr_hp;
}

int Monster::show_reward()	//������ ���� ��� �޼���
{
	return reward;
}
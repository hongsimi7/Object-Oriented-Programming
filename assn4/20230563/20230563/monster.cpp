#include "monster.h"
#include <cstdlib>
#include <iostream>

Monster::Monster()	//보스 생성자
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
Monster::Monster(int dist)	//일반 몬스터 생성자
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

void Monster::show()	//몬스터의 상태 출력 메서드
{
	std::cout << "Monster status\n";
	std::cout << "Attack: " << attack << std::endl;
	std::cout << "Defense: " << defense << std::endl;
	std::cout << "HP: " << curr_hp << " / " << max_hp << std::endl;
}

void Monster::lost_hp(int damage)			//캐릭터의 공격으로 인한 몬스터의 HP 감소 메서드
{
	curr_hp -= damage;
	if (curr_hp < 0) curr_hp = 0;
}

int Monster::monster_attack(int char_def)	//캐릭터 방어력에 대한 몬스터의 공격 데미지 출력 메서드
{
	int damage = attack - char_def;
	return damage;
}

int Monster::show_defense()	//몬스터의 방어력 출력 메서드
{
	return defense;
}

std::string Monster::show_type()	//몬스터의 타입 출력 메서드
{
	return type;
}

int Monster::show_hp()	//몬스터의 HP 출력 메서드
{
	return curr_hp;
}

int Monster::show_reward()	//몬스터의 보상 출력 메서드
{
	return reward;
}
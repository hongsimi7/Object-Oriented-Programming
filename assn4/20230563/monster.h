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
	Monster();			//보스 생성자
	Monster(int dist);	//일반 몬스터 생성자
	~Monster() {};		//몬스터 소멸자

	void show();		//몬스터의 상태 출력 메서드
	int show_defense();					//몬스터의 방어력 출력 메서드
	int show_hp();						//몬스터의 HP 출력 메서드
	int show_reward();					//몬스터의 보상 출력 메서드
	std::string show_type();			//몬스터의 타입 출력 메서드

	int monster_attack(int char_def);	//캐릭터 방어력에 대한 몬스터의 공격 데미지 출력 메서드
	void lost_hp(int damage);			//캐릭터의 공격으로 인한 몬스터의 HP 감소 메서드
};


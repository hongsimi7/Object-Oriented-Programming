#pragma once
class Character
{
private:
	int attack;		//공격력
	int defense;	//방어력
	int gold;		//골드
	int level;		//레벨
	int max_hp;		//최대 HP
	int curr_hp;	//현재 HP
	int max_mp;		//최대 MP
	int curr_mp;	//현재 MP
	int max_exp;	//최대 경험치
	int curr_exp;	//현재 경험치

public:
	Character();		//캐릭터 생성자
	~Character() {};	//캐릭터 소멸자

	int attack_basic(int mon_def);	//일반 공격으로 데미지를 출력하는 메서드
	int attack_skill(int mon_def);	//스킬 공격으로 데미지를 출력하는 메서드
	int attack_fire(int mon_def, std::string mon_type);		//불속성 공격으로 데미지를 출력하는 메서드
	int attack_grass(int mon_def, std::string mon_type);	//풀속성 공격으로 데미지를 출력하는 메서드
	int attack_water(int mon_def, std::string mon_type);	//물속성 공격으로 데미지를 출력하는 함수

	void random_char();		//캐릭터가 랜덤칸에 갔을 때 일어난 일을 적용하는 메서드
	void shop_char(int x);	//상점에서 산 아이템을 캐릭터에 적용하는 메서드
	void reward_gold(int reward);	//몬스터를 물리쳤을 때 받는 골드를 더하는 메서드
	void lost_hp(int damage);	//캐릭터가 몬스터로부터 받은 데미지를 계산하는 메서드

	void show();			//캐릭터의 상태를 출력하는 메서드
	int show_gold();		//캐릭터의 골드를 출력하는 메서드
	int show_defense();		//캐릭터의 방어력을 출력하는 메서드
	int show_mp();			//캐릭터의 MP를 출력하는 메서드
	int show_hp();			//캐릭터의 HP를 출력하는 메서드
	
	void level_up(int exp);	//경험치 획득을 통해 캐릭터가 레벨업하는 메서드
	void attack_up(int atk_plus);	//상점에서 산 공격업 아이템이 적용된 모습을 출력하는 메서드
	void defense_up(int def_plus);	//상점에서 산 방어업 아이템이 적용된 모습을 출력하는 메서드
	void exp_up(int exp);	//상점에서 산 경험치업 아이템이 적용된 모습을 출력하는 메서드
	void restore_hp();	//상점에서 산 HP회복 아이템이 적용된 모습을 출력하는 메서드
	void restore_mp();	//상점에서 산 MP회복 아이템이 적용된 모습을 출력하는 메서드
};
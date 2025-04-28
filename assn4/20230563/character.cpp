#include <iostream>
#include <cstdlib>
#include "character.h"

int Rounds(double x)				//�ݿø��ϴ� �޼���
{
	int decimal = x - int(x);
	if (decimal < 0.5) return int(x);
	else return (int(x) + 1);

}

Character::Character()	//ĳ���� ������
{
	attack = 10;
	defense = 2;
	gold = 0;
	level = 1;
	max_hp = 100;
	curr_hp = 100;
	max_mp = 20;
	curr_mp = 20;
	max_exp = 100;
	curr_exp = 0;
}

void Character::show()	//ĳ������ ���¸� ����ϴ� �޼���
{
	std::cout << std::endl << "Level: " << level << std::endl;
	std::cout << "Attack: " << attack << std::endl;
	std::cout << "Defense: " << defense << std::endl;
	std::cout << "Gold: " << gold << std::endl;
	std::cout << "HP: " << curr_hp << " / " << max_hp << std::endl;
	std::cout << "MP: " << curr_mp << " / " << max_mp << std::endl;
	std::cout << "EXP: " << curr_exp << " / " << max_exp << std::endl;
}

void Character::random_char()	//ĳ���Ͱ� ����ĭ�� ���� �� �Ͼ ���� �����ϴ� �޼���
{
	int randdomNum = rand();

	if (randdomNum % 4 == 0)			//Hp 30% ����
	{
		curr_hp = Rounds(double(curr_hp) * 0.7);
		std::cout << "You lost HP...\n";
	}
	else if (randdomNum % 4 == 1)		//Hp 30% ȸ��
	{
		curr_hp = Rounds(double(curr_hp) * 1.3);
		if (curr_hp > max_hp) curr_hp = max_hp;	//Hp�� �ִ�ġ�� �ʰ����� ��
		std::cout << "You restored HP\n";
	}
	else if (randdomNum % 4 == 2)		//100��� ȹ��
	{
		gold += 100;
		std::cout << "You found 100 golds\n";
	}
	else std::cout << "Nothing happened...\n";	//�ƹ� �ϵ� �Ͼ�� ����
}

int Character::show_gold()		//ĳ������ ��带 ����ϴ� �޼���
{
	return gold;
}

int Character::show_mp()		//ĳ������ MP�� ����ϴ� �޼���
{
	return curr_mp;
}

void Character::shop_char(int x)	//�������� �� �������� ĳ���Ϳ� �����ϴ� �޼���
{
	if (x == 1)	attack += 10;
	else if (x == 2) defense += 5;
	else if (x == 3)
	{
		curr_exp += 100;
	}

	else if (x == 4) curr_hp = max_hp;
	else curr_mp = max_mp;
}

int Character::attack_basic(int mon_def)	//�Ϲ� �������� �������� ����ϴ� �޼���
{
	int damage = attack - mon_def;
	if (damage < 0) damage = 0;
	return damage;
}
int Character::attack_skill(int mon_def)	//��ų �������� �������� ����ϴ� �޼���
{
	curr_mp -= 15;
	int damage = attack * 1.5 - mon_def;
	if (damage < 0) damage = 0;
	return damage;
}
int Character::attack_fire(int mon_def, std::string mon_type)	//�ҼӼ� �������� �������� ����ϴ� �޼���
{
	int damage;
	curr_mp -= 15;
	if (mon_type == "grass") damage = attack * 2 - mon_def;
	else damage = attack - mon_def;
	if (damage < 0) damage = 0;
	return damage;
}
int Character::attack_grass(int mon_def, std::string mon_type)	//Ǯ�Ӽ� �������� �������� ����ϴ� �޼���
{
	int damage;
	curr_mp -= 15;
	if (mon_type == "water") damage = attack * 2 - mon_def;
	else damage = attack - mon_def;
	if (damage < 0) damage = 0;
	return damage;
}
int Character::attack_water(int mon_def, std::string mon_type)	//���Ӽ� �������� �������� ����ϴ� �޼���
{
	int damage;
	curr_mp -= 15;
	if (mon_type == "fire") damage = attack * 2 - mon_def;
	else damage = attack - mon_def;
	if (damage < 0) damage = 0;
	return damage;
}

void Character::lost_hp(int damage)		//ĳ���Ͱ� ���ͷκ��� �������� ����ϴ� �޼���
{
	curr_hp -= damage;
	if (curr_hp < 0) curr_hp = 0;
}

int Character::show_defense()	//ĳ������ ������ ����ϴ� �޼���
{
	return defense;
}

int Character::show_hp()		//ĳ������ HP�� ����ϴ� �޼���
{
	return curr_hp;
}

void Character::level_up(int exp)		//����ġ ȹ���� ���� ĳ���Ͱ� �������ϴ� �޼���
{	
	int before_level = level;
	int before_attack = attack;
	int before_defense = defense;
	int before_curr_hp = curr_hp;
	int before_max_hp = max_hp;
	int before_curr_mp = curr_mp;
	int before_max_mp = max_mp;
	int before_curr_exp = curr_exp + exp;
	int before_max_exp = max_exp;
	int check_level_up = 0;

	curr_exp += exp;

	while (true)
	{
		if (curr_exp >= max_exp)
		{
			check_level_up = 1;
			curr_exp -= max_exp;
			level += 1;
			attack += 3;
			defense += 1;
			max_hp += 50;
			max_mp += 10;
			max_exp = level * 100;
		}

		else break;
	}
	if (check_level_up == 1)
	{
		curr_hp = max_hp;
		curr_mp = max_mp;

		std::cout << "Level up!\n";
		std::cout << "=======================================\n";
		std::cout << "Character status\n";
		std::cout << "Level: " << before_level << " => " << level << std::endl;
		std::cout << "Attack: " << before_attack << " => " << attack << std::endl;
		std::cout << "Defense: " << before_defense << " => " << defense << std::endl;
		std::cout << "HP: " << before_curr_hp << " / " << before_max_hp << " => " << curr_hp << " / " << max_hp << std::endl;
		std::cout << "MP: " << before_curr_mp << " / " << before_max_mp << " => " << curr_mp << " / " << max_mp << std::endl;
		std::cout << "EXP: " << before_curr_exp << " / " << before_max_exp << " => " << curr_exp << " / " << max_exp << std::endl;
		std::cout << "=======================================\n";
	}
}

void Character::attack_up(int atk_plus)	//�������� �� ���ݾ� �������� ����� ����� ����ϴ� �޼���
{
	attack += atk_plus;
	std::cout << "=======================================\n";
	std::cout << std::endl << "Level: " << level << std::endl;
	std::cout << "Attack: " << attack - atk_plus << " => " << attack << std::endl;
	std::cout << "Defense: " << defense << std::endl;
	std::cout << "Gold: " << gold << std::endl;
	std::cout << "HP: " << curr_hp << " / " << max_hp << std::endl;
	std::cout << "MP: " << curr_mp << " / " << max_mp << std::endl;
	std::cout << "EXP: " << curr_exp << " / " << max_exp << std::endl << std::endl;
	std::cout << "=======================================\n";
}



void Character::defense_up(int def_plus)	//�������� �� ���� �������� ����� ����� ����ϴ� �޼���
{
	defense += def_plus;
	std::cout << "=======================================\n";
	std::cout << std::endl << "Level: " << level << std::endl;
	std::cout << "Attack: " << attack << std::endl;
	std::cout << "Defense: " << defense - def_plus << " => " << defense << std::endl;
	std::cout << "Gold: " << gold << std::endl;
	std::cout << "HP: " << curr_hp << " / " << max_hp << std::endl;
	std::cout << "MP: " << curr_mp << " / " << max_mp << std::endl;
	std::cout << "EXP: " << curr_exp << " / " << max_exp << std::endl << std::endl;
	std::cout << "=======================================\n";
}

void Character::restore_hp()	//�������� �� HPȸ�� �������� ����� ����� ����ϴ� �޼���
{
	int before_hp = curr_hp;
	curr_hp = max_hp;
	std::cout << "=======================================\n";
	std::cout << std::endl << "Level: " << level << std::endl;
	std::cout << "Attack: " << attack << std::endl;
	std::cout << "Defense: " << defense << std::endl;
	std::cout << "Gold: " << gold << std::endl;
	std::cout << "HP: " << before_hp<< " => " << curr_hp << " / " << max_hp << std::endl;
	std::cout << "MP: " << curr_mp << " / " << max_mp << std::endl;
	std::cout << "EXP: " << curr_exp << " / " << max_exp << std::endl << std::endl;
	std::cout << "=======================================\n";
}

void Character::restore_mp()	//�������� �� MPȸ�� �������� ����� ����� ����ϴ� �޼���
{
	int before_mp = curr_mp;
	curr_mp = max_mp;
	std::cout << "=======================================\n";
	std::cout << std::endl << "Level: " << level << std::endl;
	std::cout << "Attack: " << attack << std::endl;
	std::cout << "Defense: " << defense << std::endl;
	std::cout << "Gold: " << gold << std::endl;
	std::cout << "HP: "  << curr_hp << " / " << max_hp << std::endl;
	std::cout << "MP: " << before_mp << " => " << curr_mp << " / " << max_mp << std::endl;
	std::cout << "EXP: " << curr_exp << " / " << max_exp << std::endl << std::endl;
	std::cout << "=======================================\n";
}

void Character::exp_up(int exp)	//�������� �� ����ġ�� �������� ����� ����� ����ϴ� �޼���
{
	curr_exp += exp;
	std::cout << "=======================================\n";
	std::cout << std::endl << "Level: " << level << std::endl;
	std::cout << "Attack: " << attack << std::endl;
	std::cout << "Defense: " << defense << std::endl;
	std::cout << "Gold: " << gold << std::endl;
	std::cout << "HP: " << curr_hp << " / " << max_hp << std::endl;
	std::cout << "MP: " <<  curr_mp << " / " << max_mp << std::endl;
	std::cout << "EXP: " << curr_exp - exp << " => " << curr_exp << " / " << max_exp << std::endl << std::endl;
	std::cout << "=======================================\n";
	level_up(0);
}

void Character::reward_gold(int reward)	//���͸� �������� �� �޴� ��带 ���ϴ� �޼���
{
	gold += reward;
}

#pragma once
class Character
{
private:
	int attack;		//���ݷ�
	int defense;	//����
	int gold;		//���
	int level;		//����
	int max_hp;		//�ִ� HP
	int curr_hp;	//���� HP
	int max_mp;		//�ִ� MP
	int curr_mp;	//���� MP
	int max_exp;	//�ִ� ����ġ
	int curr_exp;	//���� ����ġ

public:
	Character();		//ĳ���� ������
	~Character() {};	//ĳ���� �Ҹ���

	int attack_basic(int mon_def);	//�Ϲ� �������� �������� ����ϴ� �޼���
	int attack_skill(int mon_def);	//��ų �������� �������� ����ϴ� �޼���
	int attack_fire(int mon_def, std::string mon_type);		//�ҼӼ� �������� �������� ����ϴ� �޼���
	int attack_grass(int mon_def, std::string mon_type);	//Ǯ�Ӽ� �������� �������� ����ϴ� �޼���
	int attack_water(int mon_def, std::string mon_type);	//���Ӽ� �������� �������� ����ϴ� �Լ�

	void random_char();		//ĳ���Ͱ� ����ĭ�� ���� �� �Ͼ ���� �����ϴ� �޼���
	void shop_char(int x);	//�������� �� �������� ĳ���Ϳ� �����ϴ� �޼���
	void reward_gold(int reward);	//���͸� �������� �� �޴� ��带 ���ϴ� �޼���
	void lost_hp(int damage);	//ĳ���Ͱ� ���ͷκ��� ���� �������� ����ϴ� �޼���

	void show();			//ĳ������ ���¸� ����ϴ� �޼���
	int show_gold();		//ĳ������ ��带 ����ϴ� �޼���
	int show_defense();		//ĳ������ ������ ����ϴ� �޼���
	int show_mp();			//ĳ������ MP�� ����ϴ� �޼���
	int show_hp();			//ĳ������ HP�� ����ϴ� �޼���
	
	void level_up(int exp);	//����ġ ȹ���� ���� ĳ���Ͱ� �������ϴ� �޼���
	void attack_up(int atk_plus);	//�������� �� ���ݾ� �������� ����� ����� ����ϴ� �޼���
	void defense_up(int def_plus);	//�������� �� ���� �������� ����� ����� ����ϴ� �޼���
	void exp_up(int exp);	//�������� �� ����ġ�� �������� ����� ����� ����ϴ� �޼���
	void restore_hp();	//�������� �� HPȸ�� �������� ����� ����� ����ϴ� �޼���
	void restore_mp();	//�������� �� MPȸ�� �������� ����� ����� ����ϴ� �޼���
};
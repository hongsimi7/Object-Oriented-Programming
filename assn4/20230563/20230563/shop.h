#pragma once
class Shop
{
private:
	int attack_plus;	//���ݾ��� ���	
	int defense_plus;	//������ ���
	int exp_plus;		//����ġ���� ���

public:
	Shop();			//���� ������
	~Shop() {};		//���� �Ҹ���

	void show_list();	//���� ��� �� ��Ȳ�� �����ִ� �޼���
	int stock_attack();	//���ݾ��� ��� Ȯ�� �޼���
	int stock_defense();	//������ ��� Ȯ�� �޼���
	int stock_exp();	//����ġ���� ��� Ȯ�� �޼���
	void sold_item(int x); //��� �� ���̴� �޼���
};
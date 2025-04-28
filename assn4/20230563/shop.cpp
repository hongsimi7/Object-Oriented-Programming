#include "shop.h"
#include <iostream>

Shop::Shop()			//���� ������
{
	attack_plus = 1;
	defense_plus = 1;
	exp_plus = 1;
}

void Shop::show_list()	//���� ��� �� ��Ȳ�� �����ִ� �޼���
{
	using namespace std;
	cout << "1. Attack +10 (700 Gold) ";
	if (attack_plus == 1) cout << "(Available)\n";
	else cout << "(Sold out)\n";

	cout << "2. Defense +5 (700 Gold) ";
	if (defense_plus == 1) cout << "(Available)\n";
	else cout << "(Sold out)\n";

	cout << "3. Exp +300 (700 Gold) ";
	if (exp_plus == 1) cout << "(Available)\n";
	else cout << "(Sold out)\n";

	cout << "4. Restore HP (500 Gold) (Always Available)\n";
	cout << "5. Restore MP (500 Gold) (Always Available)\n";
}

int  Shop::stock_attack()	//���ݾ��� ��� Ȯ�� �޼���
{
	return attack_plus;
}

int  Shop::stock_defense()	//������ ��� Ȯ�� �޼���
{
	return defense_plus;
}

int  Shop::stock_exp()		//����ġ���� ��� Ȯ�� �޼���
{
	return exp_plus;
}

void Shop::sold_item(int x)		//��� �� ���̴� �޼���
{
	using namespace std;
	if (x == 1)
	{
		attack_plus -= 1;
		cout << "1. Attack +10 (700 Gold) (Available) => (Sold out)\n";

		cout << "2. Defense +5 (700 Gold) ";
		if (defense_plus == 1) cout << "(Available)\n";
		else cout << "(Sold out)\n";

		cout << "3. Exp +300 (700 Gold) ";
		if (exp_plus == 1) cout << "(Available)\n";
		else cout << "(Sold out)\n";

		cout << "4. Restore HP (500 Gold) (Always Available)\n";
		cout << "5. Restore MP (500 Gold) (Always Available)\n";
		cout << "=======================================\n\n";
	}

	else if (x == 2)
	{
		defense_plus -= 1;
		cout << "1. Attack +10 (700 Gold) ";
		if (attack_plus == 1) cout << "(Available)\n";
		else cout << "(Sold out)\n";

		cout << "2. Defense +5 (700 Gold) (Available) => (Sold out)\n";

		cout << "3. Exp +300 (700 Gold) ";
		if (exp_plus == 1) cout << "(Available)\n";
		else cout << "(Sold out)\n";

		cout << "4. Restore HP (500 Gold) (Always Available)\n";
		cout << "5. Restore MP (500 Gold) (Always Available)\n";
		cout << "=======================================\n\n";
	}
	else
	{
		exp_plus -= 1;
		cout << "1. Attack +10 (700 Gold) ";
		if (attack_plus == 1) cout << "(Available)\n";
		else cout << "(Sold out)\n";

		cout << "2. Defense +5 (700 Gold) ";
		if (defense_plus == 1) cout << "(Available)\n";
		else cout << "(Sold out)\n";

		cout << "3. Exp +300 (700 Gold) (Available) => (Sold out)\n";

		cout << "4. Restore HP (500 Gold) (Always Available)\n";
		cout << "5. Restore MP (500 Gold) (Always Available)\n";
		cout << "=======================================\n\n";
	}
}
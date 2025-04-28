#include "shop.h"
#include <iostream>

Shop::Shop()			//상점 생성자
{
	attack_plus = 1;
	defense_plus = 1;
	exp_plus = 1;
}

void Shop::show_list()	//상점 재고 및 현황을 보여주는 메서드
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

int  Shop::stock_attack()	//공격업의 재고 확인 메서드
{
	return attack_plus;
}

int  Shop::stock_defense()	//방어업의 재고 확인 메서드
{
	return defense_plus;
}

int  Shop::stock_exp()		//경험치업의 재고 확인 메서드
{
	return exp_plus;
}

void Shop::sold_item(int x)		//재고 수 줄이는 메서드
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
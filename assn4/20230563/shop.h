#pragma once
class Shop
{
private:
	int attack_plus;	//공격업의 재고	
	int defense_plus;	//방어업의 재고
	int exp_plus;		//경험치업의 재고

public:
	Shop();			//상점 생성자
	~Shop() {};		//상점 소멸자

	void show_list();	//상점 재고 및 현황을 보여주는 메서드
	int stock_attack();	//공격업의 재고 확인 메서드
	int stock_defense();	//방어업의 재고 확인 메서드
	int stock_exp();	//경험치업의 재고 확인 메서드
	void sold_item(int x); //재고 수 줄이는 메서드
};
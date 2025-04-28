#pragma once
#include "BirdList.h"
#include "AssassinDuck.h"
#include "DetectiveGoose.h"
#include "Duck.h"
#include "Goose.h"
#include "MorticianGoose.h"
#include "DodoBird.h"
#include "Falcon.h"

class GGD
{
private:
	BirdList* bird_list;
	int killability;		//오리의 살조 가능 횟수
public:
	// Do not change any function declaration from here //
	GGD();
	~GGD();
	void GameStart();
	void RoundProgress();
	bool IsGameOver();
	void PrintGameResult();
	// Do not change any function declaration to here //

	void AddPlayer(); // You can change the function declaration
	void Changekillnumber();	//살조 가능 횟수 변경
};
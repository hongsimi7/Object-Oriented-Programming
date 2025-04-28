#pragma once
#include "Macro.h"
#include <string>

class BirdList;

class Bird
{
protected:
	std::string player_name;		//새의 이름
	bool kill;						//살조 여부
	bool dead;						//사망 여부
	int job;						//직업 번호
	int elect;						//투표 당한 횟수
	int killability;				//살조 가능 횟수
	bool electeddead;				//투표사 여부
	bool pointed;					//가장 많은 투표를 당한 새 여부

public:
	Bird();							//새 생성자
	virtual ~Bird();				//가상 새 소멸자
	void SetPlayerName(std::string);	//새의 이름 세팅

	std::string GetPlayerName() const;		//새의 이름 리턴
	bool GetPlayerKill() const;				//새의 살조 여부 리턴
	int GetPlayerjob() const;				//새의 직업 리턴
	
	void elected();		//투표당한 횟수 +1
	void resetelect();	//투표당한 횟수 리셋
	int checkelect();	//투표당한 횟수 리턴

	void GoDead();		//새 사망
	bool checkdead();	//새 사망 여부 리턴
	void windead();		//투표사
	bool checkelectdead();	//투표사 여부 리턴

	int check_killability();	//살조 가능 횟수 리턴
	void change_killability(int);	//살조 가능 회수 변경
	void change_kill();		//살조 여부 리셋
		
	void electpointed();	//가장 많은 투표를 당한 경우
	void resetpointed();	//가장 많은 투표를 당한 경우 여부 리셋
	bool checkpointed();	//가장 많은 투표를 당했는지 여부 리턴

	virtual void Skill(BirdList*) = 0;		//새 가상 스킬
};


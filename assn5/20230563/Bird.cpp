#include "Bird.h"
#include "BirdList.h"

#include <iostream>

Bird::Bird() {			//새 생성자
	kill = false;
	dead = false;
	electeddead = false;
	elect = 0;
	pointed = false;
}

Bird::~Bird() {			//새 소멸자

}

void Bird::SetPlayerName(std::string name) {	//새의 이름 세팅
	player_name = name;
}
std::string Bird::GetPlayerName() const {		//새의 이름 리턴
	return this->player_name;
}
bool Bird::GetPlayerKill() const {				//새의 살조 여부 리턴
	return this->kill;
}
int Bird::GetPlayerjob() const {				//새의 직업 리턴
	return this->job;
}

void Bird::GoDead() {							//새 사망
	dead = true;
}

bool Bird::checkdead() {						//새 사망 여부 리턴
	return dead;
}

void Bird::elected()							//투표당한 횟수 +1
{
	elect += 1;
}
void Bird::resetelect()							//투표당한 횟수 리셋
{
	elect = 0;
}

int Bird::checkelect()							//투표당한 횟수 리턴
{
	return elect;
}

void Bird::windead()							//투표사 
{
	electeddead = true;
}

bool Bird::checkelectdead()						//투표사 여부 리턴
{
	return electeddead;
}

int Bird::check_killability()					//살조 가능 횟수 리턴
{
	return killability;
}

void Bird::change_killability(int x)			//살조 가능 회수 변경
{
	killability = x;
}

void Bird::change_kill()						//살조 여부 리셋
{
	kill = false;
}

void Bird::electpointed()						//가장 많은 투표를 당한 경우
{
	pointed = true;
}

void Bird::resetpointed()						//가장 많은 투표를 당한 경우 여부 리셋
{
	pointed = false;
}

bool Bird::checkpointed()						//가장 많은 투표를 당했는지 여부 리턴
{
	return pointed;
}
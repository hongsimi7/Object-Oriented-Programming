#include "Bird.h"
#include "BirdList.h"

#include <iostream>

Bird::Bird() {			//�� ������
	kill = false;
	dead = false;
	electeddead = false;
	elect = 0;
	pointed = false;
}

Bird::~Bird() {			//�� �Ҹ���

}

void Bird::SetPlayerName(std::string name) {	//���� �̸� ����
	player_name = name;
}
std::string Bird::GetPlayerName() const {		//���� �̸� ����
	return this->player_name;
}
bool Bird::GetPlayerKill() const {				//���� ���� ���� ����
	return this->kill;
}
int Bird::GetPlayerjob() const {				//���� ���� ����
	return this->job;
}

void Bird::GoDead() {							//�� ���
	dead = true;
}

bool Bird::checkdead() {						//�� ��� ���� ����
	return dead;
}

void Bird::elected()							//��ǥ���� Ƚ�� +1
{
	elect += 1;
}
void Bird::resetelect()							//��ǥ���� Ƚ�� ����
{
	elect = 0;
}

int Bird::checkelect()							//��ǥ���� Ƚ�� ����
{
	return elect;
}

void Bird::windead()							//��ǥ�� 
{
	electeddead = true;
}

bool Bird::checkelectdead()						//��ǥ�� ���� ����
{
	return electeddead;
}

int Bird::check_killability()					//���� ���� Ƚ�� ����
{
	return killability;
}

void Bird::change_killability(int x)			//���� ���� ȸ�� ����
{
	killability = x;
}

void Bird::change_kill()						//���� ���� ����
{
	kill = false;
}

void Bird::electpointed()						//���� ���� ��ǥ�� ���� ���
{
	pointed = true;
}

void Bird::resetpointed()						//���� ���� ��ǥ�� ���� ��� ���� ����
{
	pointed = false;
}

bool Bird::checkpointed()						//���� ���� ��ǥ�� ���ߴ��� ���� ����
{
	return pointed;
}
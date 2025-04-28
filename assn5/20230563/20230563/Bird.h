#pragma once
#include "Macro.h"
#include <string>

class BirdList;

class Bird
{
protected:
	std::string player_name;		//���� �̸�
	bool kill;						//���� ����
	bool dead;						//��� ����
	int job;						//���� ��ȣ
	int elect;						//��ǥ ���� Ƚ��
	int killability;				//���� ���� Ƚ��
	bool electeddead;				//��ǥ�� ����
	bool pointed;					//���� ���� ��ǥ�� ���� �� ����

public:
	Bird();							//�� ������
	virtual ~Bird();				//���� �� �Ҹ���
	void SetPlayerName(std::string);	//���� �̸� ����

	std::string GetPlayerName() const;		//���� �̸� ����
	bool GetPlayerKill() const;				//���� ���� ���� ����
	int GetPlayerjob() const;				//���� ���� ����
	
	void elected();		//��ǥ���� Ƚ�� +1
	void resetelect();	//��ǥ���� Ƚ�� ����
	int checkelect();	//��ǥ���� Ƚ�� ����

	void GoDead();		//�� ���
	bool checkdead();	//�� ��� ���� ����
	void windead();		//��ǥ��
	bool checkelectdead();	//��ǥ�� ���� ����

	int check_killability();	//���� ���� Ƚ�� ����
	void change_killability(int);	//���� ���� ȸ�� ����
	void change_kill();		//���� ���� ����
		
	void electpointed();	//���� ���� ��ǥ�� ���� ���
	void resetpointed();	//���� ���� ��ǥ�� ���� ��� ���� ����
	bool checkpointed();	//���� ���� ��ǥ�� ���ߴ��� ���� ����

	virtual void Skill(BirdList*) = 0;		//�� ���� ��ų
};


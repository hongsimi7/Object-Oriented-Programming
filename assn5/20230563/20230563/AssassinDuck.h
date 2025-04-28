#pragma once
#include "Bird.h"
#include "BirdNode.h"
#include "BirdList.h"

class AssassinDuck :
    public Bird
{
protected:
    int assassinability;        //�ϻ� ���� Ƚ��
private:

public:
    AssassinDuck();             //�ϻ��� ���� ������
    ~AssassinDuck();            //�ϻ��� ���� �Ҹ���
    void Skill(BirdList*);      //�ϻ��� ���� ��ų
};


#pragma once
#include "Bird.h"
#include "BirdNode.h"
#include "BirdList.h"

class Falcon :
    public Bird
{
protected:

private:

public:
    Falcon();       //�۰�� ������
    ~Falcon();      //�۰�� �Ҹ���
    void Skill(BirdList*);      //�۰�� ��ų
};


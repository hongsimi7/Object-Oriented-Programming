#pragma once
#include "Bird.h"
#include "BirdNode.h"
#include "BirdList.h"

class Duck :
    public Bird
{
protected:
    
private:

public:
    Duck();     //���� ������
    ~Duck();    //���� �Ҹ���
    void Skill(BirdList*);     //���� ��ų
};


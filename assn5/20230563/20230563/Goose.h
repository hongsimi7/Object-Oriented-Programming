#pragma once
#include "Bird.h"
#include "BirdNode.h"
#include "BirdList.h"

class Goose :
    public Bird
{
protected:

private:

public:
    Goose();    //���� ������
    ~Goose();   //���� �Ҹ���
    void Skill(BirdList*);  //���� ��ų
};


#pragma once
#include "Bird.h"
#include "BirdNode.h"
#include "BirdList.h"

class DetectiveGoose :
    public Bird
{
protected:

private:

public:
    DetectiveGoose();       //Ž�� ���� ������
    ~DetectiveGoose();      //Ž�� ���� �Ҹ���
    void Skill(BirdList*);     //Ž�� ���� ��ų
};
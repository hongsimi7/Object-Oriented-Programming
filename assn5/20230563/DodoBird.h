#pragma once
#include "Bird.h"
#include "BirdNode.h"
#include "BirdList.h"

class DodoBird :
    public Bird
{
protected:
    
private:

public:
    DodoBird();     //������ ������
    ~DodoBird();    //������ �Ҹ���
    void Skill(BirdList*);  //������ ��ų
};


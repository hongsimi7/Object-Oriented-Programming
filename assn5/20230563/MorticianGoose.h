#pragma once
#include "Bird.h"
#include "BirdNode.h"
#include "BirdList.h"

class MorticianGoose :
    public Bird
{
protected:

private:

public:
    MorticianGoose();       //���ǻ� ���� ������
    ~MorticianGoose();      //���ǻ� ���� �Ҹ���
    void Skill(BirdList*);  //���ǻ� ���� ��ų
};

#pragma once

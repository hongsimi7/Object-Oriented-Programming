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
    MorticianGoose();       //장의사 거위 생성자
    ~MorticianGoose();      //장의사 거위 소멸자
    void Skill(BirdList*);  //장의사 거위 스킬
};

#pragma once

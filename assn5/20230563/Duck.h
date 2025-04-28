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
    Duck();     //오리 생성자
    ~Duck();    //오리 소멸자
    void Skill(BirdList*);     //오리 스킬
};


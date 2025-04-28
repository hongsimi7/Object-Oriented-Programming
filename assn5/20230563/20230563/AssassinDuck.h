#pragma once
#include "Bird.h"
#include "BirdNode.h"
#include "BirdList.h"

class AssassinDuck :
    public Bird
{
protected:
    int assassinability;        //암살 가능 횟수
private:

public:
    AssassinDuck();             //암살자 오리 생성자
    ~AssassinDuck();            //암살자 오리 소멸자
    void Skill(BirdList*);      //암살자 오리 스킬
};


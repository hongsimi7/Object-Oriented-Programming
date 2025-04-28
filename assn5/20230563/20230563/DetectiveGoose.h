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
    DetectiveGoose();       //탐정 오리 생성자
    ~DetectiveGoose();      //탐정 오리 소멸자
    void Skill(BirdList*);     //탐정 오리 스킬
};
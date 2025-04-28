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
    Goose();    //거위 생성자
    ~Goose();   //거위 소멸자
    void Skill(BirdList*);  //거위 스킬
};


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
    DodoBird();     //도도새 생성자
    ~DodoBird();    //도도새 소멸자
    void Skill(BirdList*);  //도도새 스킬
};


#include "DodoBird.h"

#include <iostream>

DodoBird::DodoBird() : Bird() {		//도도새 생성자
	job = 6;
}

DodoBird::~DodoBird() {				//도도새 소멸자

}

void DodoBird::Skill(BirdList*) {	//도도새 스킬
	std::cout << "당신은 능력이 없는 조류입니다." << std::endl;
}


#include "Goose.h"

#include <iostream>

Goose::Goose() :Bird() {		//거위 생성자
	job = 5;
}

Goose::~Goose() {				//거위 소멸자

}

void Goose::Skill(BirdList*) {		//거위 스킬
	std::cout << "당신은 능력이 없는 조류입니다." << std::endl;
}
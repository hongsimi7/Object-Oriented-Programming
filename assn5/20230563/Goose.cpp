#include "Goose.h"

#include <iostream>

Goose::Goose() :Bird() {		//���� ������
	job = 5;
}

Goose::~Goose() {				//���� �Ҹ���

}

void Goose::Skill(BirdList*) {		//���� ��ų
	std::cout << "����� �ɷ��� ���� �����Դϴ�." << std::endl;
}
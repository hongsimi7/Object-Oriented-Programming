#include "DodoBird.h"

#include <iostream>

DodoBird::DodoBird() : Bird() {		//������ ������
	job = 6;
}

DodoBird::~DodoBird() {				//������ �Ҹ���

}

void DodoBird::Skill(BirdList*) {	//������ ��ų
	std::cout << "����� �ɷ��� ���� �����Դϴ�." << std::endl;
}


#include "Boublik.h"
#include <iostream>

Boublik::Boublik(int c, int x, int  y, float r1, float r2) : Figure(c, x, y)
{
	this->r1 = r1;
	this->r2 = r2;

}

void Boublik::setSizes(float r1, float r2) //���������� ������� ������
{
	this->r1 = r1;
	this->r2 = r2;
	draw();

}


void Boublik::calcParams(float& perimeter, float& area) const
{
	perimeter = 3.14*(r2 + r1);
	area = 3.14 * (r2*r2-r1*r1);

}

void Boublik::draw() const
{
	if (isVisible()) 
	{
		std::cout << "������ ������!\n"<<"���� �����: "<<getBorderColor()<<std::endl;
		std::cout << "����� �������: ( " << this->x << ", " << this->y << ")\n";
		std::cout << "������ r1= "<<r1<<" r2= "<<r2<< std::endl;


	}

	else {
		std::cout << "������ �� ���b��!\n";
	}

}


Boublik::~Boublik()
{
	std::cout << "������ ������ Boublik ������!\n";
}
#include "Boublik.h"
#include <iostream>

Boublik::Boublik(int c, int x, int  y, float r1, float r2) : Figure(c, x, y)
{
	this->r1 = r1;
	this->r2 = r2;

}

void Boublik::setSizes(float r1, float r2) //измменение размера фигуры
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
		std::cout << "Фигура видима!\n"<<"Цвет линии: "<<getBorderColor()<<std::endl;
		std::cout << "Центр бублика: ( " << this->x << ", " << this->y << ")\n";
		std::cout << "Радиус r1= "<<r1<<" r2= "<<r2<< std::endl;


	}

	else {
		std::cout << "Фигура не видbма!\n";
	}

}


Boublik::~Boublik()
{
	std::cout << "Объект класса Boublik удален!\n";
}
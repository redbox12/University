#include "FilledBoublik.h"
#include <iostream>
using namespace std;

FilledBoublik::FilledBoublik(int filled_c, int c, int x, int y, float r1, float r2): Boublik(c, x, y, r1, r2)
{
	this->filled_c = filled_c;

}

void FilledBoublik::draw() const
{
	if (isVisible())
	{
		std::cout << "Фигура видима!\n" << "Цвет линии: " << getBorderColor() << std::endl;
		std::cout << "Цвет Boublik: " << getFilled_c()<<endl;
		std::cout << "Центр бублика: ( " << this->x << ", " << this->y << ")\n";
		std::cout << "Радиус r1= " << r1 << " r2= " << r2 << std::endl;
	}

	else 
	{
		std::cout << "Фигура не видема!\n";
	}


}

FilledBoublik::~FilledBoublik()
{
	cout << "Объек класса FilledBoublick\n";
}

void FilledBoublik::setFillcolor(int filled_c)// изменения цвета заполнения фигуры 7.
{
	if (isVisible())
	{
		this-> filled_c = filled_c;
		draw();
	}
}

void FilledBoublik::setBorderColor(int c) // изменения цвета границы
{
	if (c != filled_c && isVisible())
	{
		Boublik::setBorderColor(c);
	}


}

int FilledBoublik::getFilled_c() const //вывести цвет закрашенный фигуры
{
	return this->filled_c;
}

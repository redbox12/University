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
		std::cout << "������ ������!\n" << "���� �����: " << getBorderColor() << std::endl;
		std::cout << "���� Boublik: " << getFilled_c()<<endl;
		std::cout << "����� �������: ( " << this->x << ", " << this->y << ")\n";
		std::cout << "������ r1= " << r1 << " r2= " << r2 << std::endl;
	}

	else 
	{
		std::cout << "������ �� ������!\n";
	}


}

FilledBoublik::~FilledBoublik()
{
	cout << "����� ������ FilledBoublick\n";
}

void FilledBoublik::setFillcolor(int filled_c)// ��������� ����� ���������� ������ 7.
{
	if (isVisible())
	{
		this-> filled_c = filled_c;
		draw();
	}
}

void FilledBoublik::setBorderColor(int c) // ��������� ����� �������
{
	if (c != filled_c && isVisible())
	{
		Boublik::setBorderColor(c);
	}


}

int FilledBoublik::getFilled_c() const //������� ���� ����������� ������
{
	return this->filled_c;
}

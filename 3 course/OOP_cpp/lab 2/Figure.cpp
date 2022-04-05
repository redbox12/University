#include "Figure.h"
#include<iostream>

using std::cout;
using std::endl;

Figure::Figure(int c, int x, int y) { //�����������
    
    this->visible = true;
    this->c = c;
    this->x = x;
    this->y = y;
}

Figure::~Figure() {}

void Figure::move(int dx, int dy) { 
    
    if (isVisible()) 
    {
        this->x = this->x + dx;
        this->y = this->y + dy;
        draw();
    }
    
} // �������� ������ �� (dx,dy) � ������ �������

void Figure::setBorderColor(int c) {
    if (isVisible())
    {
        this->c = c;
        draw();
    }
}// ���������� ���� ������ � ������ �������

int Figure::getBorderColor() const { return this->c; } // �������� ����

void Figure::setVisible(bool isVisible) {
    visible = isVisible;
    draw();
}    // ��������/�������� ������
bool Figure::isVisible() const { return this->visible; } // ������� ���������

    
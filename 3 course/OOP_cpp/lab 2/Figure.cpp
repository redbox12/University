#include "Figure.h"
#include<iostream>

using std::cout;
using std::endl;

Figure::Figure(int c, int x, int y) { //конструктор
    
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
    
} // сместить фигуру на (dx,dy) – только видимую

void Figure::setBorderColor(int c) {
    if (isVisible())
    {
        this->c = c;
        draw();
    }
}// установить цвет фигуры – только видимой

int Figure::getBorderColor() const { return this->c; } // получить цвет

void Figure::setVisible(bool isVisible) {
    visible = isVisible;
    draw();
}    // показать/спрятать фигуру
bool Figure::isVisible() const { return this->visible; } // признак видимости

    
#pragma once
#include "Boublik.h"
class FilledBoublik : public Boublik
{
private:
	int filled_c; //цвет закрашенной фигуры 6.
	
protected:
	void draw() const;

public:
	
	FilledBoublik(int filled_c, int c, int x, int y, float r1, float r2);
	virtual ~FilledBoublik();
	void setFillcolor(int c); //поменять цвет заливки
	void setBorderColor(int c); // изменения цвета границы фигуры
	int getFilled_c() const;

};


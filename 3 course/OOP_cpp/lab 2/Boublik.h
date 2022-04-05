#pragma once
#include "Figure.h"

class Boublik : public Figure
{
protected:
	float r1;
	float r2;
	void draw() const;

public:
	
	Boublik(int c, int x, int  y, float r1, float r2);
	void setSizes(float r1, float r2);
	virtual ~Boublik();
	void calcParams(float& perimeter, float& area) const; // вычислить периметр и площадь фигуры

};


#pragma once
class Figure
{

	int c; // цвет
	bool visible;//состояние существования

	protected:
	int x, y; // базовая точка
	virtual void draw() const = 0; //рисует фигуру

	public:
	Figure(int c, int x, int y);
	virtual ~Figure();
	void move(int dx, int dy); // сместить фигуру на (dx,dy) – только видимую
	virtual void setBorderColor(int c); // установить цвет фигуры – только видимой
	int getBorderColor() const ; // получить цвет
	void setVisible(bool isVisible = true);    // показать/спрятать фигуру
	bool isVisible() const; // признак видимости
	
	virtual void calcParams(float& perimeter, float& area) const = 0;
	// вычислить периметр и площадь фигуры
   



};


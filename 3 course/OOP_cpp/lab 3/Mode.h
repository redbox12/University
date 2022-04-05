#pragma once
class Mode
{
private:
	int resultMod; //результат от деления
	int basis; //на что делим
	bool checkOnEqualentBase(int basis); //проверка делителей
public:

	Mode();
	Mode(const Mode& d); //конструктор копирования

	Mode(int value, int basis);

	Mode operator+(Mode d); // прегрузка оператора +
	Mode operator-(Mode d); // прегрузка оператора - 
	bool operator==(Mode d); // прегрузка оператора ==
	bool operator!=(Mode d); // прегрузка оператора !=

	int getResultMod() { return resultMod; }
	int getBasis() { return basis; }

};


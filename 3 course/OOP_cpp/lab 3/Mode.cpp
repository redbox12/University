#include "Mode.h"
#include <iostream>


bool Mode::checkOnEqualentBase(int basis) //проверка делителей
{
	if (this->basis != basis)
		return false;
	else
		return true;
}
Mode::Mode()
{
	resultMod = 0;
	basis = 0;
}

Mode::Mode(const Mode& d) //конструктор копирования
{
	this->resultMod = d.resultMod;
	this->basis = d.basis;
}

Mode::Mode(int value, int basis)
{
	resultMod = value % basis;
	this->basis = basis;
}

Mode Mode::operator+(Mode d) // прегрузка оператора +
{
	Mode newObj;

	if (checkOnEqualentBase(d.basis))
	{
		if (resultMod + d.resultMod < 0) {
			Mode newObj1((-1 * (resultMod + d.resultMod)) % basis, basis); // умножаю на -1, т.к. остаток не может быть отрицательным
			newObj = newObj1;
		}
		else {
			Mode newObj2((resultMod + d.resultMod) % basis, basis);
			newObj = newObj2;
		}

		return newObj;
	}

	std::cerr << "Ответ: Разные базисы!!!\n";
}

Mode Mode::operator-(Mode d) // прегрузка оператора - 
{
	Mode newObj;

	if (checkOnEqualentBase(d.basis))
	{
		if (resultMod - d.resultMod < 0) {
			Mode newObj1((-1 * (resultMod - d.resultMod)) % basis, basis); // умножаю на -1, т.к. остаток не может быть отрицательным
			newObj = newObj1;
		}
		else {
			Mode newObj2((resultMod - d.resultMod) % basis, basis);
			newObj = newObj2;
		}

		return newObj;
	}

	std::cerr << "Ответ: Разные базисы!!!\n";
}

bool Mode::operator==(Mode d) // прегрузка оператора ==
{
	if (resultMod == d.resultMod && basis == d.basis)
		return true;

	return false;
}

bool Mode::operator!=(Mode d) // прегрузка оператора !=
{
	if (resultMod != d.resultMod && basis != d.basis)
		return true;

	return false;
}

#include <iostream>
#include "ASet.h"

using std::cout;
using std::endl;


ASet::ASet(int sizeD) //конструктор
{
	this->size = sizeD; //инициализирую поле size класса ASet
	container = new double[size]; //инициализирую поле container класса ASet
	this->filled_size = 0;	//инициализирую поле filled_size класса ASet

}

void ASet::incl(double new_value)  // включить число в множество, если такое число уже есть, то ничего не делать
{
	if (!contain(new_value))	//проверка есть ли new_value в массиве
	{
		if (filled_size < size) {
			container[filled_size] = new_value;
			filled_size++;
		}
		else {
			std::cerr << "ћесто нет\n";
		}

	}

}



void ASet::excl(double delete_value)	// исключить эл-т из мн-ва
{
	if (contain(delete_value)) {	// проверка есть ли delete_value 
		bool control_filledsize = false;	//это переменна€ нужна, чтобы удалить 1-ий эл-т
		for (int i = 0; i < this->filled_size; i++) {

			if (container[i] == delete_value) {
				container[i] = container[i + 1];
				i++;
				control_filledsize = true;
			}

			if (control_filledsize) { //если убрать это усл-е, то последний эл-т будет затиратьс€  
				container[i] = container[i + 1];
			}

		}

		filled_size--;
	}

	else { std::cerr << "“акой элемент не возможно удалить\nS"; }

}


bool ASet::contain(double search_value)// содержитс€ в множестве? 
{
	bool flag = false;

	for (int i = 0; i < filled_size; i++)
	{
		if (container[i] == search_value) {
			flag = true;
			break;
		}
	}
	return flag;
}

void ASet::print()  // распечатать состо€ние объекта
{
	std::cout << "{ ";
	for (int i = 0; i < filled_size - 1; i++)
	{
		std::cout << container[i] << ", ";
	}

	if (filled_size != 0) {
		std::cout << container[filled_size - 1];
	}

	cout << " }";


}

ASet::~ASet() //деструктор
{
	delete[] container;
}



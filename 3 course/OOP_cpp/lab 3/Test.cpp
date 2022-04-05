#include "Mode.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Mode obj1(29, 3); // 1 объект
 	Mode obj2(28, 3); // 2 объект

	cout << "Программа, которая умеет складывать и вычитать остатки от деления!" << endl << endl << "Данно: \n";
	cout << "obj1: " << obj1.getResultMod() << ", " << obj1.getBasis() << endl;
	cout << "obj2: " << obj2.getResultMod() << ", " << obj2.getBasis() << endl;
	cout << endl;

	//демонстрация работы переопределенного оператора +
	cout << "Вопрос: obj3 = obj1 + obj2 ?\n"; 
	Mode obj3 = obj1 + obj2; 
	if (obj2.getBasis() == obj1.getBasis())
		cout << "Ответ: obj3: " << obj3.getResultMod() << ", " << obj3.getBasis() << endl;
	
	cout << endl;

	//демонстрация работы переопределенного оператора -
	cout << "Вопрос: obj3 = obj1 - obj2 ?\n";
	obj3 = obj1 - obj2;
	if (obj2.getBasis() == obj1.getBasis())
		cout << "Ответ: obj3: " << obj3.getResultMod() << ", " << obj3.getBasis() << endl;
	
	cout << endl;

	//демонстрация работы переопределенного оператора ==
	cout << "Вопрос: obj1 == obj2 ?\n";
	cout << "Ответ: ";
	if (obj1 == obj2) {
		cout << "obj1 равен obj2 \n";
	}
	else
		cout << "obj1 не равен obj2\n";
	
	cout << endl;

	//демонстрация работы переопределенного оператора !=
	
	cout << "Вопрос: obj1 != obj2 ?\n";
	cout << "Ответ: ";
	if (obj1 != obj2) {
		cout << "obj1 не равен obj2 \n";
	}
	else
		cout << "obj1 равен obj2";

	cout << endl;

	return 0;
}

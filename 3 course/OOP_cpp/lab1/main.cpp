#include <iostream>
#include "ASet.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int switch_on;


	cout << " \nПривет! Моя программа может работать со множеством вещественных чисел.\n\nЧто программа умеет:" <<
		"\n\t 0. Остановить программу \n\t 1. Создать мн-во вещественных чисел\n\t 2. Удалить объект мн-в вещественных чисел\n\t 3. Добавить число во мн-во" <<
		"\n\t 4. Удалить число из мн-ва\n\t 5. Проверить есть ли число во мн-ве\n\t 6. Вывести на экран мн-во\n";

	ASet* obj1 = NULL;// объявляю объект
	int size_setA; // размер передаваемый пользователем
	double element_ASet = 0; //перменная которая будет передаваться в switch

	do {

		cout << "\nЧто вы хотите сделать: ";
		cin >> switch_on;

		switch (switch_on)
		{

		case 1: // cоздать мн - во вещественных чисел
			if (obj1 != NULL) {
				cout << "Вы уже создали мн-во!\n";
				continue;
			}
			else
			{
				cout << "Какой размер будет у мн-ва: ";
				cin >> size_setA;
				obj1 = new ASet(size_setA);
			}
			break;

		case 2: // yдалить объект мн-в вещественных чисел
			if (obj1 != NULL)
			{
				delete obj1;
				obj1 = NULL;
			}
			else {
				cout << "У вас пустое мн-во!";
				continue;
			}
			break;

		case 3: // Добавить число во мн-во

			if (obj1 != NULL) {
				cout << "Введите число: ";
				cin >> element_ASet;
				(*obj1).incl(element_ASet);
			}
			else {
				cout << "У вас пустое мн-во\n";
				continue;
			}

			break;

		case 4: // Удалить число из мн-ва

			if (obj1 != NULL) {
				cout << "Введите число: ";
				cin >> element_ASet;
				obj1->excl(element_ASet);

			}

			else
			{
				cout << "У вас пустое мн-во\n";
				continue;
			}

			break;



		case 5: //  Проверить есть ли число во мн-ве

			if (obj1 != NULL)
			{
				cout << "Введите число: ";
				cin >> element_ASet;

				if (obj1->contain(element_ASet)/*obj1.contain(element_ASet)*/)
				{
					cout << "Число: " << element_ASet << " cуществует!\n";
				}

				else cout << "Число: " << element_ASet << " НЕ cуществует!\n";

			}

			else
			{
				cout << "У вас пустое мн-во\n";
				continue;
			}

			break;



		case 6: // Вывести на экран мн-во
			if (obj1 != NULL)
			{
				obj1->print();
				cout << endl;
			}

			else
			{
				cout << "У вас пустое мн-во\n";
				continue;
			}

			break;

		default:
			if (switch_on == 0)
				cout << endl;
			else
				cout << "\n\nЧто вы хотите сделать: ";
			break;
		}

	} while (switch_on != 0);

	delete obj1;

	return 0;
}


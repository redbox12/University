#include <iostream>
#include "ASet.h"

using std::cout;
using std::endl;


ASet::ASet(int sizeD) //ПАВЕЛ 
{
	this->size = sizeD; //������������� ���� size ������ ASet
	container = new double[size]; //������������� ���� container ������ ASet
	this->filled_size = 0;	//������������� ���� filled_size ������ ASet

}

void ASet::incl(double new_value)  // �������� ����� � ���������, ���� ����� ����� ��� ����, �� ������ �� ������
{
	if (!contain(new_value))	//�������� ���� �� new_value � �������
	{
		if (filled_size < size) {
			container[filled_size] = new_value;
			filled_size++;
		}
		else {
			std::cerr << "����� ���\n";
		}

	}

}



void ASet::excl(double delete_value)	// ��������� ��-� �� ��-��
{
	if (contain(delete_value)) {	// �������� ���� �� delete_value 
		bool control_filledsize = false;	//��� ���������� �����, ����� ������� 1-�� ��-�
		for (int i = 0; i < this->filled_size; i++) {

			if (container[i] == delete_value) {
				container[i] = container[i + 1];
				i++;
				control_filledsize = true;
			}

			if (control_filledsize) { //���� ������ ��� ���-�, �� ��������� ��-� ����� ����������  
				container[i] = container[i + 1];
			}

		}

		filled_size--;
	}

	else { std::cerr << "����� ������� �� �������� �������\nS"; }

}


bool ASet::contain(double search_value)// ���������� � ���������? 
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

void ASet::print()  // ����������� ��������� �������
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

ASet::~ASet() //����������
{
	delete[] container;
}



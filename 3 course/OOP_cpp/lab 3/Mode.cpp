#include "Mode.h"
#include <iostream>


bool Mode::checkOnEqualentBase(int basis) //�������� ���������
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

Mode::Mode(const Mode& d) //����������� �����������
{
	this->resultMod = d.resultMod;
	this->basis = d.basis;
}

Mode::Mode(int value, int basis)
{
	resultMod = value % basis;
	this->basis = basis;
}

Mode Mode::operator+(Mode d) // ��������� ��������� +
{
	Mode newObj;

	if (checkOnEqualentBase(d.basis))
	{
		if (resultMod + d.resultMod < 0) {
			Mode newObj1((-1 * (resultMod + d.resultMod)) % basis, basis); // ������� �� -1, �.�. ������� �� ����� ���� �������������
			newObj = newObj1;
		}
		else {
			Mode newObj2((resultMod + d.resultMod) % basis, basis);
			newObj = newObj2;
		}

		return newObj;
	}

	std::cerr << "�����: ������ ������!!!\n";
}

Mode Mode::operator-(Mode d) // ��������� ��������� - 
{
	Mode newObj;

	if (checkOnEqualentBase(d.basis))
	{
		if (resultMod - d.resultMod < 0) {
			Mode newObj1((-1 * (resultMod - d.resultMod)) % basis, basis); // ������� �� -1, �.�. ������� �� ����� ���� �������������
			newObj = newObj1;
		}
		else {
			Mode newObj2((resultMod - d.resultMod) % basis, basis);
			newObj = newObj2;
		}

		return newObj;
	}

	std::cerr << "�����: ������ ������!!!\n";
}

bool Mode::operator==(Mode d) // ��������� ��������� ==
{
	if (resultMod == d.resultMod && basis == d.basis)
		return true;

	return false;
}

bool Mode::operator!=(Mode d) // ��������� ��������� !=
{
	if (resultMod != d.resultMod && basis != d.basis)
		return true;

	return false;
}

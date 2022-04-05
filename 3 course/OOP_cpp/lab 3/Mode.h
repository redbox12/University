#pragma once
class Mode
{
private:
	int resultMod; //��������� �� �������
	int basis; //�� ��� �����
	bool checkOnEqualentBase(int basis); //�������� ���������
public:

	Mode();
	Mode(const Mode& d); //����������� �����������

	Mode(int value, int basis);

	Mode operator+(Mode d); // ��������� ��������� +
	Mode operator-(Mode d); // ��������� ��������� - 
	bool operator==(Mode d); // ��������� ��������� ==
	bool operator!=(Mode d); // ��������� ��������� !=

	int getResultMod() { return resultMod; }
	int getBasis() { return basis; }

};


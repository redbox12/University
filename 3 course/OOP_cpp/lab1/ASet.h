#pragma once
class ASet
{
private:
	int size;           // ������ �������
	double* container;  //������ �����
	int filled_size;    //������ ������ ����������� �������

public:
	ASet() : ASet(10) {} //���������� ������������
	ASet(int size);  // size - ������������ ���������� ����� � ���������   

	void incl(double new_value);  // �������� ����� � ���������, ���� ����� ����� ��� ����, �� ������ �� ������     

	void excl(double delet_value);  // ��������� ��-� �� ��-��   

	inline bool contain(double search_value); // ���������� � ���������?    

	void print();  // ����������� ��������� �������

	~ASet();    //�e�������� 

};


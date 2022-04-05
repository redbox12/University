#pragma once
class ASet
{
private:
	int size;           // размер массива
	double* container;  //массив чисел
	int filled_size;    //хранит размер заполненого массива

public:
	ASet() : ASet(10) {} //перегрузка конструктора
	ASet(int size);  // size - максимальное количество чисел в множестве   

	void incl(double new_value);  // включить число в множество, если такое число уже есть, то ничего не делать     

	void excl(double delet_value);  // исключить эл-т из мн-ва   

	inline bool contain(double search_value); // содержится в множестве?    

	void print();  // распечатать состояние объекта

	~ASet();    //дeструктор 

};


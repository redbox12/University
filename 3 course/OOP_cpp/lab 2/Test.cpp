#include <iostream>
#include "FilledBoublik.h"
using namespace std;

int main() {

    setlocale(LC_ALL, "");

    cout << "Создаем объект obj1 без цвета заливки" << endl;
    Boublik* obj1 = new Boublik(12, 0, 0, 5, 7);
    Figure* obj_figure = obj1; //полиморфизм
    cout << endl;

    cout << "Показываем obj1:" << endl;
    obj_figure->setVisible();
    cout << endl;
    

    cout << "\nСмещаем фигуру на (9; 9):" << endl;
    obj_figure->move(9, 9);
    cout << endl;

    cout << "Устанавливаем цвет границы фигуры:" << endl;
    obj_figure->setBorderColor(28);
    cout << endl;

    cout << "Вычисляем периметр и площадь фигуры:" << endl;
    float area_obj1;
    float perimeter_obj1;
    
    obj_figure->calcParams(perimeter_obj1, area_obj1);
    cout << "Периметр фигуры: " << perimeter_obj1 << endl;
    cout << "Площадь фигуры: " << area_obj1 << endl;

   

    delete obj_figure;
    obj1 = nullptr;
    cout << endl;
   
    cout << "//////////////////////////////////////////" << endl<< endl;

    cout << "Создаем объект obj_filledBoublik c цветом заливки" << endl;
    FilledBoublik* obj_filledBoublik = new FilledBoublik(15, 89, 0, 0, 8, 12);
    obj_figure = obj_filledBoublik; //полиморфизм 

    cout << "Показываем obj_filledBoublik:" << endl;
    obj_figure->setVisible();
    cout << endl;

    cout << "Устанавливаем цвет фигуры:" << endl;
    obj_filledBoublik->setFillcolor(88);
    //obj_figure->setFillcolor(88);
    cout << endl;

    cout << "Смещаем фигуру на (3;-2):" << endl;
    obj_figure->move(3, -2);
    cout << endl;

    cout << "Устанавливаем цвет границ фигуры:" << endl;
    obj_figure->setBorderColor(567);
    cout << endl;

    cout << "!!! Устанавливаем цвет границ фигуры: !!! " << endl;
    obj_figure->setBorderColor(88);
    cout << endl;

    cout << "Вычисляем периметр и площадь фигуры:" << endl;
    float area_obj_figure;
    float perimeter_obj_figure;

    obj_figure->calcParams(perimeter_obj_figure, area_obj_figure);
    cout << "Периметр фигуры: " << perimeter_obj_figure << endl;
    cout << "Площадь фигуры: " << area_obj_figure << endl;

    delete obj_figure;
    obj_figure = NULL;

    return 0;
}
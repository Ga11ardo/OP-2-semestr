#pragma once
#include <iostream>
using namespace std;

class Point {
	//Атрибути класа точки за осями
private:
	double X;
	double Y;

public:
	//Гетери та Сетери
	void SetX(double);


	double GetX();

	void SetY(double);

	double GetY();

	int GetQuadrant();
	//Конструктор за замовчуванням
	Point();
	//З параметрами
	Point(double, double);
	//Конструктор за чвертю
	Point(int);

	//Функції перевантаження операторів
	friend double operator - (Point, Point);
	Point& operator++();
	Point operator++(int);

};

//Виведення масиву трьох точок
void Show(Point[]);  
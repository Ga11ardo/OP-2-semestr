#include <iostream>
#include "Point.h"


int main() {

	cout << "Enter X of T1 Point: ";
	double X;
	cin >> X;
	cout << "Enter Y of T1 Point: ";
	double Y;
	cin >> Y;

	cout << "Enter quadrant of T2 Point: ";
	int quadrant;
	cin >> quadrant;
	//Створення об'єктів класу точки за допомогою різних конструкторів
	Point T1(X, Y), T2(quadrant), T3;
	Point points[]{ T1,T2,T3 };
	cout << "------------------------------------------" << endl;
	cout << "Points before changing" << endl;
	Show(points);   //Виведення точок перед зміною за допомогою операторів 
	//Використання перевантажених операторів інкременту
	++points[0];
	points[1]++;
	cout << "------------------------------------------" << endl;
	cout << "Points after changing" << endl;
	Show(points); //Виведення після зміни
	cout << "------------------------------------------" << endl;
	//Використання перевантаженого оператору віднімання для знаходження відстані
	cout << "The distance between T1 and T2 points is " << points[0] - points[1] << endl;

	cout << "Quadrant of point T3 is " << T3.GetQuadrant() << endl;


}
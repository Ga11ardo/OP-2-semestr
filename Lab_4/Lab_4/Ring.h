#pragma once
#include <iostream>
#include <string>
using namespace std;

class Ring {
    double r;
    double R;
    double centerX;
    double centerY;
public:
    Ring();
    Ring(double r1, double R1, double x1, double y1);
    Ring(string);
    double get_r() const;
    double get_R() const;
    double getCenterX() const;
    double getCenterY() const;
    double widthCalculation();
    Ring& operator++(); // �������-��� "++"
    Ring operator++(int); // ����������� "++"
    Ring& operator*=(int); // "*="
    void print();
};
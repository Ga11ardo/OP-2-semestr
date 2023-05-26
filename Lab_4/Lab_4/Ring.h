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
    Ring& operator++(); // префікс-ний "++"
    Ring operator++(int); // постфіксний "++"
    Ring& operator*=(int); // "*="
    void print();
};
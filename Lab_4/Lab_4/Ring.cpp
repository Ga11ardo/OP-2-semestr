#include "Ring.h";

Ring::Ring() {
    r = 1;
    R = 2;
    centerX = 1;
    centerY = 1;
}

Ring::Ring(double r1, double R1, double x1, double y1) {
    r = r1;
    R = R1;
    centerX = x1;
    centerY = y1;
}

Ring::Ring(string values)
{
    int space1, space2, space3;
    space1 = values.find(" ");
    space2 = values.find(" ", space1 + 1);
    space3 = values.find(" ", space2 + 1);
    r = stod(values.substr(0, space1));
    R = stod(values.substr(space1, space2));
    centerX = stod(values.substr(space2, space3));
    centerY = stod(values.substr(space3, values.size()));
}

double Ring::get_r() const {
    return r;
}

double Ring::get_R() const {
    return R;
}

double Ring::getCenterX() const {
    return centerX;
}

double Ring::getCenterY() const {
    return centerY;
}

double Ring::widthCalculation() {
    double result;
    result = R - r;
    return result;
}

Ring& Ring::operator++() { // префікс-ний "++"
    r+=1;
    if (r > R) { cout << "--------Incorect!!!------\n"; }
    cout << "Prefix_r++\n";
    return *this;
}

Ring Ring::operator++(int) { // постфіксний "++"
    Ring temp = *this;
    R+=1;
    cout << "Postix_r++\n";
    return temp;
}

Ring& Ring::operator*=(int num) { // "*="
    R = R * num;
    if (r > R) { cout << "--------Incorect!!!------\n"; }
    cout << "Operator*=\n";
    return *this;
}

void Ring::print() {
    cout << "r = " << r;
    cout << "\tR = " << R;
    cout << "\tCenter = " << centerX << ", " << centerY << endl;
}
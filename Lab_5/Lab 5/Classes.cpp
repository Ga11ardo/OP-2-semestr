#include "Classes.h"

void TIntNumber::set_number(string line) {
    this->number = line;
}
void TIntNumber::set_base(int value) {
    this->base = value;
}
int TIntNumber::ToDecimal() {
    int new_number = stoi(number, nullptr, base);
    return new_number;
}
void TIntNumber::print() {
    cout << this->number << "  ";
}


TIntNumber2::TIntNumber2() {
    this->set_number("");
    this->set_base(2);
}
string TIntNumber2::ToBin(int num) {
    int temp = num;
    string r = "";
    while (num != 0)
    {
        r = (num % 2 == 0 ? "0" : "1") + r; num /= 2;
    }
    if (temp < 0)
        r = "-" + r;
    if (temp == 0)
        r = "0";
    return r;
}
TIntNumber2::TIntNumber2(string num) {
    this->set_number(num);
    this->set_base(2);
}
void TIntNumber2::operator++() {
    int new_number = ToDecimal();
    new_number++;
    this->set_number(ToBin(new_number));
}
void TIntNumber2::operator--() {
    int new_number = ToDecimal();
    new_number--;
    this->set_number(ToBin(new_number));
}


TIntNumber8::TIntNumber8() {
    this->set_number("");
    this->set_base(8);
}
string TIntNumber8::ToOct(int num)
{
    string str;
    int temp = (num <= 0 ? (-num) : num);
    while (temp != 0) {
        str = to_string(temp % 8) + str;
        temp /= 8;
    }
    if (num < 0)
        str = "-" + str;
    if (num == 0)
        str = "0";
    return str;
}
TIntNumber8::TIntNumber8(string num) {
    this->set_number(num);
    this->set_base(8);
}
void TIntNumber8::operator--() {
    int new_number = ToDecimal();
    new_number--;
    this->set_number(ToOct(new_number));
}
void TIntNumber8::operator++() {
    int new_number = ToDecimal();
    new_number++;
    this->set_number(ToOct(new_number));
}
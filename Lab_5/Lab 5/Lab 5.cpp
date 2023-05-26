#include "Functions.h"

int main()
{
    int m, n;
    cout << "Enter the amount of binary nums: ";
    input(m);
    cout << "Enter the amount of octal nums: ";
    input(n);
    cout << endl << "Binary: ";
    TIntNumber* Binary = InputBinNumbers(m);
    cout << endl << "Octal: ";
    TIntNumber* Octal = InputOctNumbers(n);
    cout << endl << "Binary:" << endl;
    PrintArray(Binary, m);
    cout << endl << "Octal:" << endl;
    PrintArray(Octal, n);
    cout << endl;
    Operations(Binary, Octal, m, n);
    cout << "All the numbers in decimal:" << endl;
    PrintArrayAll(Binary, Octal, m, n);
    cout << "The smallest number in decimal system: " << FindTheSmallestDecNumber(Binary, Octal, m, n) << endl << endl;
    return 0;
}
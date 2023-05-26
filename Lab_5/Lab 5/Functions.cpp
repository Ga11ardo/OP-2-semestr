#include "Functions.h"

void input(int& val) {
    cin >> val;
    while (val <= 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Incorrect input: ";
        cin >> val;
    };
}

int isInputCorrect(int val, int base) {
    while (val != NULL) {
        val = (val <= 0 ? (-val) : val);
        if (val % 10 < base) {
            val = val / 10;
        }
        else {
            return 0;
        }
    }
    return 1;
}

int correctInput(int base) {
    cout << "\nInput number: ";
    int val;
    cin >> val;
    while (isInputCorrect(val, base) == 0) {
        cout << "\n---!!!Incorrect input!!!---";
        cout << "\nTry again please, input: ";
        cin >> val;
    }
    return val;
}

TIntNumber* InputBinNumbers(int m) {
    TIntNumber* array = new TIntNumber2[m];
    TIntNumber2 object;
    for (int i = 0; i < m; i++)
    {
        object.set_number(to_string(correctInput(2)));
        array[i] = object;
    }
    return array;
}

TIntNumber* InputOctNumbers(int n) {
    TIntNumber* array = new TIntNumber8[n];
    TIntNumber8 object;
    for (int i = 0; i < n; i++)
    {
        object.set_number(to_string(correctInput(8)));
        array[i] = object;
    }
    return array;
}


void Operations(TIntNumber* Binary, TIntNumber* Octal, int m, int n) {
    cout << "Incremented binary numbers:" << endl;
    for (int i = 0; i < m; i++)
    {
        ++Binary[i];
        cout << Binary[i].get_number() << "  ";
    }cout << endl;
    cout << "Decremented octal numbers:" << endl;
    for (int i = 0; i < n; i++)
    {
        --Octal[i];
        cout << Octal[i].get_number() << "  ";
    }
    cout << endl;
}
void PrintArrayAll(TIntNumber* Binary, TIntNumber* Octal, int m, int n) {

    for (int i = 0; i < m; i++)
    {
        cout << Binary[i].ToDecimal() << "  ";
    }
    for (int i = 0; i < n; i++)
    {
        cout << Octal[i].ToDecimal() << "  ";
    }cout << endl;
}
void PrintArray(TIntNumber* arr, int size) {

    for (int i = 0; i < size; i++)
    {
        arr[i].print();
    }cout << endl;
}
int FindTheSmallestDecNumber(TIntNumber* Binary, TIntNumber* Octal, int m, int n) {
    int min = Binary[0].ToDecimal();
    for (int i = 0; i < m; i++)
    {
        if (Binary[i].ToDecimal() < min)
            min = Binary[i].ToDecimal();
    }
    for (int i = 0; i < n; i++)
    {
        if (Octal[i].ToDecimal() < min)
            min = Octal[i].ToDecimal();
    }
    return min;
}
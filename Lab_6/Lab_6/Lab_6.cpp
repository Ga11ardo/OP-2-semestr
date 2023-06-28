#include <iostream>
#include <conio.h>
#include "Mnozhyna.h"
using namespace std;

int main() {
    do {
        setlocale(LC_ALL, "ukr");
        int type = choice();
        if (type == 1) {
            Set<int> A = createAndFillSet<int>();
            Task(A);
        }
        else if (type == 2) {
            Set<float> A = createAndFillSet<float>();
            Task(A);
        }
        else if (type == 3) {
            Set<char> A = createAndFillSet<char>();
            Task(A);
        }
        else if (type == 4) {
            Set<string> A = createAndFillSet<string>();
            Task(A);
        }
        else {
            cerr << "Некоректний ввiд даних!" << endl;
        }
        cout << endl << "Нажмiть Esc, щоб завершити роботу програми" << endl;
    } while (_getch() == 13);
    return 0;
}
#include "Functions.h";

void MAX_width_ring(Ring C1, Ring C2, Ring C3) {
	if (C1.widthCalculation() > C2.widthCalculation() && C1.widthCalculation() > C3.widthCalculation())
		cout << "Max width ring is C1: width = " << C1.widthCalculation() << "\n";
	else if (C2.widthCalculation() > C3.widthCalculation())
		cout << "Max width ring is C2: width = " << C2.widthCalculation() << "\n";
	else
		cout << "Max width ring is C3: width = " << C3.widthCalculation() << "\n";
}

void printAll(Ring C1, Ring C2, Ring C3) {
	cout << "\nRing 1:\t";
	C1.print();
	cout << "Ring 2:\t";
	C2.print();
	cout << "Ring 3:\t";
	C3.print();
	cout << "\n";
}
#include "Functions.h";

int main()
{
	Ring First(3, 5, 4.8, 9.6);
	Ring Second("5 7 2.2 3.1");
	Ring Third;
	printAll(First, Second, Third);
	MAX_width_ring(First, Second, Third);
	++First;
	Second++;
	Third *= 2;
	printAll(First, Second, Third);
	MAX_width_ring(First, Second, Third);
	return 0;
}
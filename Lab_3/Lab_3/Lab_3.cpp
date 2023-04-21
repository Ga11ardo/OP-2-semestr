#include "Text.h";
#include "Functions.h";

int main()
{
	Text* Texts = new Text[one_text];
	int count_texts;
	cout << "How many texts do you want to write: ";
	cin >> count_texts;
	cin.ignore();
	Texts = inputText(Texts, count_texts);
	printText(Texts, count_texts);
	addText(Texts, count_texts);
	countVowels(Texts, count_texts);
	delete[] Texts;
}
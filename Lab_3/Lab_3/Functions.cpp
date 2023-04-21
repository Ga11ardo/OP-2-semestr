#include "Functions.h"
using namespace std;

//ввід текстів
Text* inputText(Text* text_assembly, int number) {
	Text* temp;
	int size = one_text;
	for (int i = 0; i < number; i++)
	{
		if (i > size - 1) {
			temp = new Text[size];
			for (int j = 0; j < i; j++)
				temp[j].set_text(text_assembly[j].get_text(), text_assembly[j].get_lines());
			delete[] text_assembly;

			text_assembly = new Text[size += 1];
			for (int j = 0; j < i; j++)
				text_assembly[j].set_text(temp[j].get_text(), temp[j].get_lines());
			delete[] temp;
		}
		cout << "\nText " << i + 1 << " (To stop input use Ctrl + R):\n";
		text_assembly[i].input();
	}
	return text_assembly;
}

//вивід текстів на екран
void printText(Text* text_assembly, int number) {
	for (int i = 0; i < number; i++) {
		cout << "Text " << i + 1 << " :\n";
		text_assembly[i].print();
	}
}

//функція додавання рядків до тексту
void addText(Text* text_assembly, int number) {
	int add_pointer;
	char answer, answer2;
	void printIncorectAnswer();
answer_point:
	cout << "Do you want to add text (y/n): ";
	cin >> answer;
	cin.ignore();
	if (answer == 'y' || answer == 'Y') {
	add_point:
		cout << "Input to which text you want to add strings: ";
		cin >> add_pointer;
		cout << "\n";
		if (add_pointer < 1 || add_pointer > number) {
			printIncorectAnswer();
			cout << "--------Please, try again!-----------";
			goto add_point;
		}
		cin.ignore();
		text_assembly[add_pointer - 1].add();

	answer2_point:
		cout << "Do you want to add some strings again(y/n): ";
		cin >> answer2;
		cin.ignore();
		if (answer2 == 'y' || answer2 == 'Y') {
			goto add_point;
		}
		else if (answer2 == 'n' || answer2 == 'N') {}
		else {
			printIncorectAnswer();
			goto answer2_point;
		}
	}
	else if (answer == 'n' || answer == 'N') {}
	else {
		printIncorectAnswer();
		goto answer_point;
	}
	cout << "\nTexts after add:\n";
	cout << "-------------------------------------------\n";
	printText(text_assembly, number);
	cout << "-------------------------------------------\n";
}

//функція обрахування голосних в текстах
void countVowels(Text* text_assembly, int number) {
	int text_pointer = 0;
	int max_vowels = 0;
	for (int i = 0; i < number; i++) {
		int count_vowewls = text_assembly[i].counter_vowels();
		if (count_vowewls >= max_vowels) {
			max_vowels = count_vowewls;
			text_pointer = i;
		}
	}
	cout << "Text " << text_pointer + 1 << " has got " << max_vowels << " vowels, this is maximum\n";
	text_assembly[text_pointer].print();
}

//функція для некоректного вводу
void printIncorectAnswer() {
	cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
	cout << "!!!Uncorect answer, please try again!!!\n";
	cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";
}
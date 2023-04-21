#include "Text.h"

//функція введення тексту
void Text::input() {
	string line, * temp;
	int i = 0;
	int size = start_line;
	while (getline(cin, line) && (line.find(18) == string::npos)) {
		if (i > size - 1) {
			temp = new string[size];
			for (int j = 0; j < i; j++)
				temp[j] = text[j];
			delete[] text;

			text = new string[size += 1];
			for (int j = 0; j < i; j++)
				text[j] = temp[j];
			delete[] temp;
		}
		text[i++] = line;
	}
	lines = i;
}

//функція додавання рядків до тексту
void Text::add() {
	string line, * temp;
	int count = lines;
	int size = lines;
	cout << "To stop input use Ctrl+R \n";
	while (getline(cin, line) && (line.find(18) == string::npos)) {
		if (count > size - 1) {
			temp = new string[size];
			for (int j = 0; j < count; j++)
				temp[j] = text[j];
			delete[] text;

			size += 1;
			text = new string[size];
			for (int j = 0; j < count; j++)
				text[j] = temp[j];
			delete[] temp;
		}
		text[count++] = line;
	}
	lines = count;
}

//обрахування голосних
int Text::counter_vowels() const {
	int count = 0;
	for (int i = 0; i < lines; i++) {
		int lenght = text[i].length();
		for (int j = 0; j < lenght; j++) {
			char c = text[i][j];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
				c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
				count++;
			}
		}
	}
	return count;
}

string* Text::get_text() {
	string* temp = new string[lines];
	for (int i = 0; i < lines; i++) {
		temp[i] = text[i];
	}
	return temp;
}

void Text::set_text(string* new_text, int new_lines) {
	delete[] text;
	text = new_text;
	lines = new_lines;
}

//вивід на екран
void Text::print() const {
	for (int i = 0; i < lines; i++) {
		cout << text[i] << "\n";
	}
	cout << "\n";
}

int Text::get_lines() const {
	return lines;
}

Text::~Text() {
	delete[] text;
}
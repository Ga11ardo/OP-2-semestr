#include "file_stream_functions.h"

//Запис у файл
void input(string name) {
	string line = "a";

	cout << "Input file contents bellow (empty line to stop writing): \n";
	fstream input_file(name, ios::out | ios::trunc);
	while (true) {
		getline(cin, line);
		if (line.empty())
			break;
		input_file << line << " \n";
	}
	input_file.close();

}

//Читання з файлу
void read(string name) {
	string line;

	cout << "File contents: \n";
	fstream file(name, ios::in);
	while (true) {
		getline(file, line);
		if (file.eof())
			break;
		cout << line << "\n";
	}
	cout << "\n";
	file.close();
}

//Додавання тексту до файлу
void add_input(string name) {
	string line = "a";
	cout << "Add line to end of file bellow(empty line to stop writing): \n";
	fstream input_file(name, ios::out | ios::app);
	while (true) {
		getline(cin, line);
		if (line.empty())
			break;
		input_file << line << " \n";
	}
	input_file.close();
}

//Зміна слова-маски
void edit_mask(string& mask) {
	int mask_test;

	cout << "Input mask (previous mask = \"" << mask << "\"): ";
	while (true) {
		cin >> mask;
		mask_test = mask.find("*");
		if (mask.find("*", mask_test + 1) == string::npos) {
			cout << "\n";
			break;
		}
		else if (!mask.find("*")) cout << "Wrong mask format\n";
		else
			cout << "Wrong mask format\n";
	}
}

//Визначає чи підходить слово до маски, повертає false якщо не підїодить
bool check_mask(string word, string mask) {
	int mask_pos;
	string compare, compare_add;

	if (mask == "*") {
		return true;
	}
	else if (mask.find("*") == string::npos) {
		if (word == mask)
			return true;
	}
	else if (mask[0] == '*') {
		compare = mask.substr(1, mask.length());
		if (word.rfind(compare) == word.length() - mask.length() + 1)
			return true;
	}
	else if (mask[mask.length() - 1] == '*') {
		compare = mask.substr(0, mask.length() - 1);
		if (word.find(compare) == 0)
			return true;
	}
	else {
		mask_pos = mask.find('*');
		compare = mask.substr(0, mask_pos);
		compare_add = mask.substr(mask_pos + 1, mask.length());
		if (word.find(compare) == 0 && word.rfind(compare_add) == word.length() - compare_add.length())
			return true;
	}

	return false;
}

//Редаговання рядка за допомогою маски
string edit_line(string line, string mask) {
	bool check_mask(string, string);

	bool edited = false;
	int start = 0;
	int	end = 0;
	string word;

	while (true) {
		start = line.find_first_not_of(SEPARATORS, end);
		end = line.find_first_of(SEPARATORS, start);
		if (start < 0)
			break;
		word = line.substr(start, end - start);

		if (check_mask(word, mask) && word[0] != '(' && word[word.length() - 1] != ')') {
			line.erase(start, word.length()+1);
			line.append("(" + word + ") ");
			end = start;

			edited = true;
		}
		start = end;
	}
	if (edited)
		return line;
	else
		return "";
}

//Пошук слів за маскою та вивід у файл виводу
void find_mask(string input_name, string output_name, string mask) {
	string edit_line(string, string);
	fstream input_file(input_name, ios::in);
	fstream output_file(output_name, ios::out | ios::trunc);
	string line, new_line;

	while (!input_file.eof()) {
		getline(input_file, line);
		new_line = edit_line(line, mask);
		if (!new_line.empty())
			output_file << new_line << " \n";
	}
	input_file.close();
	output_file.close();
}

void incorect_answers() {
	cout << "!!!Incorect answer!!!\n";
    cout << "Please, input answer in the right format: \n";
}
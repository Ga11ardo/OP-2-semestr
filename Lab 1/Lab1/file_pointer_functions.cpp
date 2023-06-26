#include "file_pointer_functions.h"

//Запис у файл
void input(char* name) {
	char line[MAXLEN] = "a";
	FILE* fp;
	fopen_s(&fp, name, "w");

	while (true) {
		fgets(line, MAXLEN, stdin);
		if (strlen(line) == 1) {
			break;
		}
		fputs(line, fp);
	}
	fclose(fp);
}

//Читання з файлу
void read(char* name) {
	char line[MAXLEN];

	FILE* fp;
	fopen_s(&fp, name, "r");

	cout << "File contents: \n";
	while (true) {
		if (fgets(line, MAXLEN, fp) == NULL) {
			break;
		}
		fputs(line, stdout);
	}
	cout << "\n";
	fclose(fp);
}

//Додавання тексту до файлу
void add_input(char* name) {
	char line[MAXLEN] = "a";
	FILE* fp;
	fopen_s(&fp, name, "a");

	while (true) {
		fgets(line, MAXLEN, stdin);
		if (strlen(line) == 1) {
			break;
		}
		fputs(line, fp);
	}
	fclose(fp);
}

//Зміна слова-маски
void edit_mask(char* mask) {
	char* mask_test;

	cout << "Input mask (previous mask = \"" << mask << "\"): ";
	while (true) {
		cin >> mask;
		mask_test = strchr(mask, '*');
		if (mask_test == NULL || strchr(mask_test + 1, '*') == NULL) {
			cout << "\n";
			break;
		}
		else
			cout << "Wrong mask format\n";
	}
}

//Визначає чи підходить слово до маски, повертає false якщо не підїодить
bool check_mask(char* word, char* mask) {
	char compare[MAXLEN];
	char* temp;
	int pos;

	if (!strcmp(mask, "*")) {
		return true;
	}
	else if (strchr(mask, '*') == NULL) {
		if (!strcmp(mask, word)) {
			return true;
		}
	}
	else if (mask[0] == '*') {
		for (int i = 0; i < strlen(mask); i++) {
			compare[i] = mask[i + 1];
		}
		while ((temp = strstr(word, compare)) != NULL) {
			if (temp + strlen(compare) == word + strlen(word)) {
				return true;
			}
		}
	}
	else if (mask[strlen(mask) - 1] == '*') {
		strcpy_s(compare, mask);
		compare[strlen(compare) - 1] = '\0';
		if (strstr(word, compare) == word) {
			return true;
		}
	}
	else {
		pos = strchr(mask, '*') - mask;

		strcpy_s(compare, mask);
		compare[strlen(compare) - pos - 1] = '\0';

		if (strstr(word, compare) == word) {
			for (int i = 0; i < strlen(mask); i++) {
				compare[i] = mask[i + pos + 1];
			}

			while ((temp = strstr(word, compare)) != NULL) {
				if (temp + strlen(compare) == word + strlen(word)) {
					return true;
				}
			}
		}
	}
	return false;
}

//Редаговання рядка за допомогою маски
bool edit_line(char* line, char* mask) {
	bool check_mask(char*, char*);

	bool edited = false;
	char word[MAXLEN];
	char* start, * current;
	int len;

	line[strlen(line) - 1] = '\0';
	current = line;
	while (*current != '\0') {
		while (strchr(SEPARATORS, *current)) {
			current++;
		}

		start = current;
		while (!strchr(SEPARATORS, *current)) {
			current++;
		}
		len = current - start;

		strncpy_s(word, start, len);
		if ((word[0] != '(' || word[strlen(word) - 1] != ')') && check_mask(word, mask)) {
			for (int i = start - line; i < MAXLEN - 1; i++) {
				line[i] = line[i + len + 1];
			}
			strcat_s(line, sizeof(word), " (");
			strcat_s(line, sizeof(word), word);
			strcat_s(line, sizeof(word), ")");

			current -= len;
			edited = true;
		}
	}
	if (strlen(line) < MAXLEN) {
		*current++ = '\n';
		*current = '\0';
	}
	return edited;
}

//Пошук слів за маскою та вивід у файл виводу
void find_mask(char* input_name, char* output_name, char* mask) {
	bool edit_line(char*, char*);
	char line[MAXLEN];

	FILE* fw;
	fopen_s(&fw, output_name, "w");
	FILE* fr;
	fopen_s(&fr, input_name, "r");

	while (true) {
		if (fgets(line, MAXLEN, fr) == NULL) {
			break;
		}
		if (edit_line(line, mask)) {
			fputs(line, fw);
		}
	}
	fclose(fr);
	fclose(fw);
}

void incorect_answer() {
	cout << "!!!Incorect answer!!!\n";
	cout << "Please, input answer in the right format: \n";
}
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Text {
	const int start_line = 1;                                     //начальне значення для масиву тексту
	int lines;                                                    //значення рядків у тексті
	string* text;                                                 //масив рядків тексту

public:
	Text() : lines(0), text(new string[start_line]) {};
	~Text();
	void input();												//функція введення тексту
	void add();													//функція додавання рядків до тексту
	void set_text(string*, int);
	string* get_text();
	int counter_vowels() const;									//обрахування голосних
	int get_lines() const;
	void print() const;											//вивід на екран
};

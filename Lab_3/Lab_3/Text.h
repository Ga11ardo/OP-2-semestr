#pragma once
#include <iostream>
#include <string>
using namespace std;

class Text {
	const int start_line = 1;                                     //�������� �������� ��� ������ ������
	int lines;                                                    //�������� ����� � �����
	string* text;                                                 //����� ����� ������

public:
	Text() : lines(0), text(new string[start_line]) {};
	~Text();
	void input();												//������� �������� ������
	void add();													//������� ��������� ����� �� ������
	void set_text(string*, int);
	string* get_text();
	int counter_vowels() const;									//����������� ��������
	int get_lines() const;
	void print() const;											//���� �� �����
};

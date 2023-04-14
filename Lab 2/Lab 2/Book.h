#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_LETTERS = 200;

struct Book {
	char title[MAX_LETTERS];
	char author[MAX_LETTERS];
	char language[MAX_LETTERS];
	int year_of_publication;
	int num_of_copies;
};

void createKatalog(string); //������� ��������� ��������
void printKatalog(string); //������� ������ �������� �� �����
void addBooksToKatalog(string); //������� ��������� ���� �� ��������
void findAuthor(string, string); //������� ����������� ���� ������ ������ � ����� �� �� ��������
void sortAuthor(string, string); //������� ���������� ���� ������ ������ �� ��������� �������� ���� ���� � ����� ������������ ���� � ����� �������

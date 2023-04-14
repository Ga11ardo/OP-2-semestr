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

void createKatalog(string); //функція створення каталогу
void printKatalog(string); //функція виводу каталогу на екран
void addBooksToKatalog(string); //функція додавання книг до каталогу
void findAuthor(string, string); //функція знаходжкння книг одного автора і запис їх до каталогу
void sortAuthor(string, string); //функція сортування книг одного автора за алфавітним порядком назв книг і запис відсортованих книг в новий каталог

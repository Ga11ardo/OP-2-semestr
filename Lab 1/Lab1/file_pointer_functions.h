#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MAXLEN 1000
const char SEPARATORS[] = " ,.;";           //Символи-роздільники

void input(char*);                          //Запис у файл
void read(char*);                           //Читання з файлу
void add_input(char*);                      //Додавання тексту до файлу
void edit_mask(char*);                      //Зміна слова-маски
void find_mask(char*, char*, char*);        //Пошук слів за маскою та вивід у файл виводу
void incorect_answer();						//Видача помилки
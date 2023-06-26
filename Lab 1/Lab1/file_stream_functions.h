#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const char SEPARATORS[] = " ,.;";          //Символи-роздільники

void input(string);                        //Запис у файл
void read(string);                         //Читання з файлу
void add_input(string);                    //Додавання тексту до файлу
void edit_mask(string&);                   //Зміна слова-маски
void find_mask(string, string, string);    //Пошук слів за маскою та вивід у файл виводу
void incorect_answers();				   //Видача помилки
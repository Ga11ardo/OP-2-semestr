#pragma once
#include "Text.h"

const int one_text = 1;              //початкове значення для масиву текстів

Text* inputText(Text*, int);         //ввід текстів
void printText(Text*, int);          //вивід текстів на екран
void addText(Text*, int);            //функція додавання рядків до тексту
void countVowels(Text*, int);        //функція обрахування голосних в текстах
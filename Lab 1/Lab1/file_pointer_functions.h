#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MAXLEN 1000
const char SEPARATORS[] = " ,.;";           //�������-����������

void input(char*);                          //����� � ����
void read(char*);                           //������� � �����
void add_input(char*);                      //��������� ������ �� �����
void edit_mask(char*);                      //���� �����-�����
void find_mask(char*, char*, char*);        //����� ��� �� ������ �� ���� � ���� ������
void incorect_answer();						//������ �������
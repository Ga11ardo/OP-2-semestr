#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const char SEPARATORS[] = " ,.;";          //�������-����������

void input(string);                        //����� � ����
void read(string);                         //������� � �����
void add_input(string);                    //��������� ������ �� �����
void edit_mask(string&);                   //���� �����-�����
void find_mask(string, string, string);    //����� ��� �� ������ �� ���� � ���� ������
void incorect_answers();				   //������ �������
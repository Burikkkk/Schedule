#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include<iomanip>
#include "Class.h"
#include "Admin.h"
#include "User.h"

const char ESC = 27;
const char UP = 72;
const char DOWN = 80;
const char ENTER = 13;

using namespace std;

enum ConsoleColor // ���� ������
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void StartMenu(); // ���� ������� ������
void UserMenu(); // ���� ������������
void AdminMenu(); // ���� ��������������
void FunctionsUser(); // ������� ������������
void FunctionsAdmin(); // ������� ��������������
void FunRoutes(); // ������� �������������� ��� ������ � ����������
void FunBuses(); // ������� �������������� ��� ������ � ����������
void FunUsers(); // ������� �������������� ��� ������ � �������� ��������
void LoginMenu(int status, int x, int y); // ���� ��� ����������� (��������� 0 ��� �������� ������������, 1 - ��� ��������������)

void GoToXY(short x, short y); // ������ � ����� x,y 
void ConsoleCursorVisible(bool show, short size); // ��������� � ������� �������
void SetColor(ConsoleColor text, ConsoleColor background); // ��������� ����� ������


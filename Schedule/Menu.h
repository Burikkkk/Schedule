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

enum ConsoleColor // Цвет текста
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

void StartMenu(); // Меню первого уровня
void UserMenu(); // Меню пользователя
void AdminMenu(); // Меню администратора
void FunctionsUser(); // Функции пользователя
void FunctionsAdmin(); // Функции администратора
void FunRoutes(); // Функции администратора для работы с маршрутами
void FunBuses(); // Функции администратора для работы с автобусами
void FunUsers(); // Функции администратора для работы с учетными записями
void LoginMenu(int status, int x, int y); // Меню для регистрации (принимает 0 для создания пользователя, 1 - для администратора)

void GoToXY(short x, short y); // Курсор в точку x,y 
void ConsoleCursorVisible(bool show, short size); // Видимость и размеры курсора
void SetColor(ConsoleColor text, ConsoleColor background); // Установка цвета текста


#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <iomanip>  
#include <ctime>
#include "Menu.h"
using namespace std;

void Encrypt(string& pass); // Зашифровка
void Decrypt(string& pass); // Расшифровка

int Length_file(string name); // Получение размера файла для "user.txt" и для "bus.txt"
int Count_route(string name); // Получение размера файла для "route.txt"

// Проверки
int CinIntErrorCheck(int min, int max); // Проверка целых чисел в заданном диапазоне
double CinDoubleErrorCheck(double min, double max); // Проверка дробных чисел в заданном диапазоне
int CinIntErrorCheck(); // Проверка целых чисел
bool CinBoolErrorCheck(); // Проверка булевых значений 
string CinStringSymAngErrorCheck(int &x, int &y); // Проверка строк (принимается только латиница)
string CinStringSymRusErrorCheck(); // Проверка строк (принимается только кириллица)
string CinNomerErrorCheck(); // Проверка номеров автобусов

class Bus_Stop
{
private:
	string name;
	int kol_time;
	double time[300];
public:
	int GetKolTime() { return kol_time; };
	void SetKolTime (int kol) { kol_time = kol; };
	string GetName() { return name; }
	double GetTime(int i) { return time[i]; }
	void SetName(string name) { this->name = name; }
	void SetTime(int i, double time) { this->time[i] = time; }
};

class Route 
{
private:
	int number;
	int kol_ost;
	Bus_Stop bus_stop[10];

public:
	int GetNumber() { return number; }
	void SetNumber(int number) { this->number = number; }
	int GetKolost() { return kol_ost; }
	string GetBusStopName(int i) { return bus_stop[i].GetName(); }

	void NewBusStop(); // Создание новых остановок
	friend void NewRoutes(); // Создание нового маршрута
	void OutputRoute(); // Вывод всех маршрутов
	void InFileRoute(); // Запись данных в файл "route.txt"
	friend void OutFileRoute(Route* (&arr_route), int kol_route); // Получение данных из файла "route.txt"
	void Copy(Route &arr_route); // Копирование полей одного маршрута в другой
	void SearchTime(int j); // Расчет времени до прибытия ближайшего автобуса
};

void OutFileRoute(Route* (&arr_route), int kol_route); // Получение данных из файла "route.txt"

void NewRoutes(); // Создание нового маршрута

class Bus
{
private:
	string id;
	string FIO;
	int number;
	bool repair;
public:
	string GetID() { return id; };
	string GetFIO() { return FIO; };
	int GetNumber() { return number; };
	bool GetRepair() { return repair; };
	void SetID(string id) { this->id = id; };
	void SetFIO(string FIO) { this->FIO = FIO; };
	void SetNumber(int number) { this->number = number; };
	void SetRepair(bool repair) { this->repair = repair; };

	void InFileBus(); // Запись данных в файл "bus.txt"
	friend void OutFileBus(Bus* (&arr_buses)); // Получение данных из файла "bus.txt"
	void NewBus(); // Создание нового автобуса
	void OutputBus(); // Вывод всех автобусов
	void CopyBus(Bus& arr); // Копирование полей одного автобуса в другой
};

void OutFileBus(Bus* (&arr_buses)); // Получение данных из файла "bus.txt"

class User
{
private:
	string login;
	string password;
	int status; // Пользователь-0; администратор-1
public:
	void Password(); // Ввод пароля для входа

	void SetLogin(string login) { this->login = login; } 
	void SetPassword(string password) { this->password = password; }; 
	void SetStatus(int status) { this->status = status; }; 
	string GetLogin() { return login; } 
	string GetPassword() { return password; } 
	int GetStatus() { return status; }

	void InFileUser(); // Запись данных в файл "user.txt"
	friend void OutFileUser(User* (&arr_users)); // Получение данных из файла "user.txt"
	void OutputUser(); // Вывод всех учетных записей пользователей
};

void OutFileUser(User* (&arr_users)); // Получение данных из файла "user.txt"


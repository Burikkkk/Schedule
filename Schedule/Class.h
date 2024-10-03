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

void Encrypt(string& pass); // ����������
void Decrypt(string& pass); // �����������

int Length_file(string name); // ��������� ������� ����� ��� "user.txt" � ��� "bus.txt"
int Count_route(string name); // ��������� ������� ����� ��� "route.txt"

// ��������
int CinIntErrorCheck(int min, int max); // �������� ����� ����� � �������� ���������
double CinDoubleErrorCheck(double min, double max); // �������� ������� ����� � �������� ���������
int CinIntErrorCheck(); // �������� ����� �����
bool CinBoolErrorCheck(); // �������� ������� �������� 
string CinStringSymAngErrorCheck(int &x, int &y); // �������� ����� (����������� ������ ��������)
string CinStringSymRusErrorCheck(); // �������� ����� (����������� ������ ���������)
string CinNomerErrorCheck(); // �������� ������� ���������

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

	void NewBusStop(); // �������� ����� ���������
	friend void NewRoutes(); // �������� ������ ��������
	void OutputRoute(); // ����� ���� ���������
	void InFileRoute(); // ������ ������ � ���� "route.txt"
	friend void OutFileRoute(Route* (&arr_route), int kol_route); // ��������� ������ �� ����� "route.txt"
	void Copy(Route &arr_route); // ����������� ����� ������ �������� � ������
	void SearchTime(int j); // ������ ������� �� �������� ���������� ��������
};

void OutFileRoute(Route* (&arr_route), int kol_route); // ��������� ������ �� ����� "route.txt"

void NewRoutes(); // �������� ������ ��������

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

	void InFileBus(); // ������ ������ � ���� "bus.txt"
	friend void OutFileBus(Bus* (&arr_buses)); // ��������� ������ �� ����� "bus.txt"
	void NewBus(); // �������� ������ ��������
	void OutputBus(); // ����� ���� ���������
	void CopyBus(Bus& arr); // ����������� ����� ������ �������� � ������
};

void OutFileBus(Bus* (&arr_buses)); // ��������� ������ �� ����� "bus.txt"

class User
{
private:
	string login;
	string password;
	int status; // ������������-0; �������������-1
public:
	void Password(); // ���� ������ ��� �����

	void SetLogin(string login) { this->login = login; } 
	void SetPassword(string password) { this->password = password; }; 
	void SetStatus(int status) { this->status = status; }; 
	string GetLogin() { return login; } 
	string GetPassword() { return password; } 
	int GetStatus() { return status; }

	void InFileUser(); // ������ ������ � ���� "user.txt"
	friend void OutFileUser(User* (&arr_users)); // ��������� ������ �� ����� "user.txt"
	void OutputUser(); // ����� ���� ������� ������� �������������
};

void OutFileUser(User* (&arr_users)); // ��������� ������ �� ����� "user.txt"


#include "Menu.h"

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // �������� ���������� �������

void GoToXY(short x, short y) // ������ � ����� x,y
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void SetColor(ConsoleColor text, ConsoleColor background) // ��������� ����� ������
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
 
void ConsoleCursorVisible(bool show, short size) // ��������� � ������� �������
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show; // �������� ��������� �������
	structCursorInfo.dwSize = size;   // �������� ������ �������
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}


void StartMenu()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle(L"���������� ��������� ��������� ������ ");
	ConsoleCursorVisible(false, 100);
	int y=10, x=35;
	SetColor(Yellow, Black);
	GoToXY(x, y); y++;
	cout << "        �����������������������������       "; GoToXY(x, y); y++;
	cout << "       ���   ��     ���     ���     ��      "; GoToXY(x, y); y++;
	cout << "       ���   ��     ���     ���     ��      "; GoToXY(x, y); y++;
	cout << "       ��    ��     ���     ���     ��      "; GoToXY(x, y); y++;
	cout << "       ��    �������������������������      "; GoToXY(x, y); y++;
	cout << "      ��������������������������������      "; GoToXY(x, y); y++;
	cout << "      ��������������������������������      "; GoToXY(x, y); y++;
	cout << "      �����     ������������     �����      "; GoToXY(x, y); y++;
	cout << "       ��� ����� ���������� ����� ���       "; GoToXY(x, y); y++;
	cout << "          ���0���          ���0���          "; GoToXY(x, y); y+=2;
	cout << "           �����            �����           "; GoToXY(x, y); 
	cout << "                  ��������.                 "; GoToXY(x, y); 
	Sleep(500);
	cout << "                  ��������..                "; GoToXY(x, y); y += 2;
	Sleep(500);
	cout << "                  ��������...               "; GoToXY(x, y);
	Sleep(1000);
	cout << "    ������� ����� ������� ��� �����������   "; GoToXY(x, y);
	_getch();
	system("CLS");
	string m[] = { "����� ��� ������������", "����� ��� �������������", "�����������", "�����" };
	int active_menu = 0; // ��� ��������� ������ ����
	char ch; // ��� ���� ������� �������
	while (true)
	{
		x = 45, y = 12;
		GoToXY(x, y);
		for (int i = 0; i < size(m); i++)
		{
			if (i == active_menu) 	SetColor(LightMagenta,Black);
			else 	SetColor(Yellow, Black);
			GoToXY(x, y++);
			cout << m[i] << endl;
		}
		ch = _getch();
		if (ch == -32) ch = _getch(); // ��������� ���� ������� �������
		switch (ch)
		{
		case ESC:
			system("CLS");
			exit(0);
			
		case UP:
			if (active_menu > 0)
				active_menu--;
			else
				active_menu = size(m) - 1;
			break;
		case DOWN:
			if (active_menu < size(m) - 1)
				active_menu++;
			else
				active_menu = 0;
			break;
		case ENTER:
			switch (active_menu)
			{
			case 0: 
				system("CLS");
				GoToXY(45,12);
				SetColor(Yellow, Black);
				UserMenu();
				break;
			case 1:
				system("CLS");
				GoToXY(45, 12);
				SetColor(Yellow, Black);
				AdminMenu();
				break;
			case 2:
				system("CLS");
				SetColor(Yellow, Black);
				LoginMenu(0, 45, 12);
				_getch();
				system("CLS");
				break;
			case 3:
				system("CLS");
				GoToXY(45,13);
				SetColor(Yellow, Black);
				cout << "����� �� ���������...";
				_getch();
				system("CLS");
				GoToXY(0,0);
				exit(0);
			default:
				cout << "����������� �������" << endl;
				_getch();
				system("CLS");
			}
			break;
		default:
			GoToXY(45, 17);
			cout << "����������� �������" << endl;
			_getch();
			system("CLS");

		}
	}
}

void UserMenu()
{
	User temp;
	string log;
	bool st=0,l=0, p=0;
	int y = 13, x=45, k=0;
	temp.SetStatus(0);
	SetColor(LightMagenta, Black);
	cout << "������� �����: ";
	SetColor(Yellow, Black);
	log = CinStringSymAngErrorCheck(x,y);
	temp.SetLogin(log);
	int size = Length_file("user.txt");
	User* arr_users=new User[size];
	OutFileUser(arr_users);
	for (int i = 0; i < size; i++)
	{
		if (arr_users[i].GetStatus() == temp.GetStatus())
		{
			st = 1;
			if (arr_users[i].GetLogin() == temp.GetLogin())
			{
				l = 1;
				GoToXY(x, y++);
				cout << "������� ������ �������.";
				GoToXY(x, y++);
				SetColor(LightMagenta, Black);
				cout << "������� ������: ";
				SetColor(Yellow, Black);
				while (k != 5) 
				{
					GoToXY(x, y++);
					temp.Password();
					while (temp.GetPassword() == "NOPASSWORD")
					{
						cout << "�� �� ����� ������, ���������� ��� ���" << endl;
						GoToXY(x, y++);
						temp.Password();
					}
					if (arr_users[i].GetPassword() == temp.GetPassword())
					{
						delete[]arr_users;
						p = 1;
						GoToXY(x, y++);
						cout << "���� ��������.";
						_getch();
						system("CLS");
						FunctionsUser();
						break;
					}
					else if(k == 3)
					{
						GoToXY(x, y++);
						cout << "��� ��������� ������� ����� ������.";
						GoToXY(x, y++);
						cout << "������ ��������� � ���������� ��� ���";
						k++;
					}
					else if (k == 4)
					{
						GoToXY(x, y++);
						cout << "�������� ������.";
						k++;
					}
					else
					{
						GoToXY(x, y++);
						cout << "�������� ������. ���������� ��� ���";
						k++;
					}
			
				}			
			}
		}
	}
	if (st == 0 || l == 0)
	{
		delete[]arr_users;
		GoToXY(x, y++);
		cout << "������� ������ � ����� ������ �� �������";
		_getch();
		system("CLS");
	}
	else if (p == 0)
	{
		delete[]arr_users;
		y++;
		GoToXY(x, y++);
		cout << ".............................................";
		GoToXY(x, y++);
		cout << "�� 5 ��� ����� ������������ ������.";
		GoToXY(x, y++);
		cout << "��������� 3 ������ ����� ��������� ��������...";
		Sleep(7000);
		_getch();
		system("CLS");
	}
	
}

void AdminMenu()
{
	User temp;
	string log;
	bool st = 0, l = 0, p = 0;
	int y = 13, x = 45, k = 0;
	temp.SetStatus(1);
	SetColor(LightMagenta, Black);
	cout << "������� �����: ";
	SetColor(Yellow, Black);
	log=CinStringSymAngErrorCheck(x,y);
	temp.SetLogin(log);
	int size = Length_file("user.txt");
	User* arr_users = new User[size];
	OutFileUser(arr_users);
	for (int i = 0; i < size; i++)
	{
		if (arr_users[i].GetStatus() == temp.GetStatus())
		{
			st = 1;
			if (arr_users[i].GetLogin() == temp.GetLogin())
			{
				l = 1;
				GoToXY(x, y++);
				cout << "������� ������ �������.";
				GoToXY(x, y++);
				SetColor(LightMagenta, Black);
				cout << "������� ������: ";
				SetColor(Yellow, Black);
				while (k != 3)
				{
					GoToXY(x, y++);
					temp.Password();
					while (temp.GetPassword() == "NOPASSWORD")
					{
						cout << "�� �� ����� ������, ���������� ��� ���" << endl;
						GoToXY(x, y++);
						temp.Password();
					}
					if (arr_users[i].GetPassword() == temp.GetPassword())
					{
						delete[]arr_users;
						p = 1;
						GoToXY(x, y++);
						cout << "���� ��������.";
						_getch();
						system("CLS");
						
						FunctionsAdmin();
						break;
					}
					else if (k == 1)
					{
						GoToXY(x, y++);
						cout << "��� ��������� ������� ����� ������.";
						k++;
					}
					else if (k == 2)
					{
						GoToXY(x, y++);
						cout << "�������� ������.";
						k++;
					}
					else
					{
						GoToXY(x, y++);
						cout << "�������� ������. ���������� ��� ���";
						k++;
					}
				}
			}
		}
	}
	if (st == 0 || l == 0)
	{
		delete[]arr_users;
		GoToXY(x, y++);
		cout << "������� ������ � ����� ������ �� �������";
		_getch();
		system("CLS");
		
	}
	else if (p == 0)
	{
		delete[]arr_users;
		y++;
		GoToXY(x, y++);
		cout << ".............................................";
		GoToXY(x, y++);
		cout << "�� 3 ���� ����� ������������ ������.";
		GoToXY(x, y++);
		cout << "��������� 3 ������ ����� ��������� ��������...";
		Sleep(7000);
		_getch();
		system("CLS");

	}
	
}

void LoginMenu(int status, int x, int y)
{
	User temp, temp_pass;
	string log;
	bool st=1, p=0;
	int k=0;
	temp.SetStatus(status);
	GoToXY(x, y++);
	SetColor(LightMagenta, Black);
	cout << "������� �����: ";
	SetColor(Yellow, Black);
	rewind(stdin);
	log = CinStringSymAngErrorCheck(x,y);
	int size = Length_file("user.txt");
	User* arr_users = new User[size];
	OutFileUser(arr_users);
	for (int i = 0; i < size; i++)
	{
		if (arr_users[i].GetLogin() == log)
			st = 0;
	}
	if (st==1)
	{
		st = 1;
		temp.SetLogin(log);
		GoToXY(x, y++);
		SetColor(LightMagenta, Black);
		cout << "������� ������: ";
		SetColor(Yellow, Black);
		GoToXY(x, y++);
		temp.Password();
		while (temp.GetPassword() == "NOPASSWORD")
		{
			cout << "�� �� ����� ������, ���������� ��� ���" << endl;
			GoToXY(x, y++);
			temp.Password();
		}
		GoToXY(x, y++);
		cout << "����������� ������: ";
		while (k != 3)
		{
			GoToXY(x, y++);
			temp_pass.Password();
			while (temp_pass.GetPassword() == "NOPASSWORD")
			{
				cout << "�� �� ����� ������, ���������� ��� ���" << endl;
				GoToXY(x, y++);
				temp_pass.Password();
			}
			if (temp.GetPassword() == temp_pass.GetPassword())
			{
				delete[]arr_users;
				p = 1;
				GoToXY(x, y++);
				cout << "������� ������ �������";
				GoToXY(x, y++);
				temp.InFileUser();
				break;
			}
			else if (k == 1)
			{
				GoToXY(x, y++);
				cout << "��� ��������� ������� ����� ������.";
				k++;
			}
			else if (k == 2)
			{
				GoToXY(x, y++);
				cout << "�������� ������.";
				k++;
			}
			else
			{
				GoToXY(x, y++);
				cout << "�������� ������. ���������� ��� ���";
				k++;
			}
		}
	}
	else
	{
		delete[]arr_users;
		GoToXY(x, y++);
		cout << "������� ������ � ����� ������ ��� ����������";
		p = 1;
	}
	if (p == 0)
	{
		delete[]arr_users;
		y++;
		GoToXY(x, y++);
		cout << ".............................................";
		GoToXY(x, y++);
		cout << "�� 3 ���� ����� ������������ ������.";
		GoToXY(x, y++);
		cout << "������� ����������� ������.";
		_getch;
	}
		
}

void FunctionsUser()
{
	char ch;
	string b[] = { 
		"����������� ��� ��������", 
		"����������",
		"����� �������� �� ������", 
		"������ ������� �� �������� ���������� ��������",
		"�����",
		"�����" };
	int active_menu = 0;
	while (true)
	{
		GoToXY(0, 0);
		for (int i = 0; i < size(b); i++)
		{
			if (i == active_menu) 	SetColor(LightMagenta, Black);
			else 	SetColor(Yellow, Black);
			cout << b[i] << endl;
		}
		ch = _getch();
		if (ch == -32) ch = _getch(); 
		Route* arr_route = new Route[0];
		int size_route;
		switch (ch)
		{
		case ESC:
			delete[]arr_route;
			system("CLS");
			return;

		case UP:
			if (active_menu > 0)
				active_menu--;
			else
				active_menu = size(b) - 1;
			break;
		case DOWN:
			if (active_menu < size(b) - 1)
				active_menu++;
			else
				active_menu = 0;
			break;
		case ENTER:
			switch (active_menu)
			{
			case 0:
				system("CLS");
				size_route = Count_route("route.txt");
				arr_route = new Route[size_route];
				OutFileRoute(arr_route, size_route);
				for (int i = 0; i < size_route; i++)
				{
					arr_route[i].OutputRoute();
				}
				_getch();
				system("CLS");

				break;
			case 1:
				system("CLS");
				SorteRoute();
				_getch();
				system("CLS");
				break;
			case 2:
				system("CLS");
				Search();
				break;
			case 3:
				system("CLS");
				Time();
				_getch();
				system("CLS");
				break;
			case 4:
				system("CLS");
				delete[]arr_route;
				return;
			case 5:
				system("CLS");
				delete[]arr_route;
				GoToXY(45, 13);
				SetColor(Yellow, Black);
				cout << "����� �� ���������...";
				_getch();
				system("CLS");
				GoToXY(0, 0);
				exit(0);
			default:
				GoToXY(0, 7);
				cout << "����������� �������" << endl;
				_getch();
				system("CLS");
			}
			break;
		default:
			GoToXY(0, 7);
			cout << "����������� �������" << endl;
			_getch();
			system("CLS");
		}
	}
}

void FunctionsAdmin()
{
	char ch;
	string a[] = {
		"���������� ����������",
		"��������� ����������",
		"���������� �������� �������� �������������",
		"�����",
		"�����" };
	int active_menu = 0;
	while (true)
	{
		GoToXY(0, 0);
		for (int i = 0; i < size(a); i++)
		{
			if (i == active_menu) 	SetColor(LightMagenta, Black);
			else 	SetColor(Yellow, Black);
			cout << a[i] << endl;
		}
		ch = _getch();
		if (ch == -32) ch = _getch();
		switch (ch)
		{
		case ESC:
			system("CLS");
			return;

		case UP:
			if (active_menu > 0)
				active_menu--;
			else
				active_menu = size(a) - 1;
			break;
		case DOWN:
			if (active_menu < size(a) - 1)
				active_menu++;
			else
				active_menu = 0;
			break;
		case ENTER:
			switch (active_menu)
			{
			case 0:

				system("CLS");
				FunRoutes();
				break;
			case 1:

				system("CLS");
				FunBuses();
				break;
			case 2:

				system("CLS");
				FunUsers();
				break;
			case 3:
				system("CLS");
				return;
			case 4:
				system("CLS");
				GoToXY(45, 13);
				SetColor(Yellow, Black);
				cout << "����� �� ���������...";
				_getch();
				system("CLS");
				GoToXY(0, 0);
				exit(0);
			default:
				GoToXY(0, 6);
				cout << "����������� �������" << endl;
				_getch();
				system("CLS");
			}
			break;
		default:
			GoToXY(0, 6);
			cout << "����������� �������" << endl;
			_getch();
			system("CLS");
		}
	}
}

void FunRoutes()
{
	char ch;
	string a[] = {
		"����������� ��� ��������",
		"���������� ������ ��������",
		"�������������� ��������",
		"�������� ��������",
		"����������",
		"�����",
		"�����" };
	int active_menu = 0;
	while (true)
	{
		GoToXY(0, 0);
		for (int i = 0; i < size(a); i++)
		{
			if (i == active_menu) 	SetColor(LightMagenta, Black);
			else 	SetColor(Yellow, Black);
			cout << a[i] << endl;
		}
		ch = _getch();
		if (ch == -32) ch = _getch();
		Route* arr_route = new Route[0];
		int size_route = 0;
		switch (ch)
		{
		case ESC:
			delete[]arr_route;
			system("CLS");
			return;

		case UP:
			if (active_menu > 0)
				active_menu--;
			else
				active_menu = size(a) - 1;
			break;
		case DOWN:
			if (active_menu < size(a) - 1)
				active_menu++;
			else
				active_menu = 0;
			break;
		case ENTER:
			switch (active_menu)
			{
			case 0:
				system("CLS");
				size_route = Count_route("route.txt");
				arr_route = new Route[size_route];
				OutFileRoute(arr_route, size_route);
				for (int i = 0; i < size_route; i++)
				{
					arr_route[i].OutputRoute();
				}
				_getch();
				system("CLS");
				break;
			case 1:
				system("CLS");
				NewRoutes();
				_getch();
				system("CLS");
				break;
			case 2:
				system("CLS");
				ChangeRoute();
				_getch();
				system("CLS");
				break;
			case 3:
				system("CLS");
				DeleteRoute();
				_getch();
				system("CLS");
				break;
			case 4:
				system("CLS");
				SorteRoute();
				_getch();
				system("CLS");
				break;
			case 5:
				delete[]arr_route;
				system("CLS");
				return;
			case 6:
				delete[]arr_route;
				system("CLS");
				GoToXY(45, 13);
				SetColor(Yellow, Black);
				cout << "����� �� ���������...";
				_getch();
				system("CLS");
				GoToXY(0, 0);
				exit(0);
			default:
				GoToXY(0, 8);
				cout << "����������� �������" << endl;
				_getch();
				system("CLS");
			}
			break;
		default:
			GoToXY(0, 8);
			cout << "����������� �������" << endl;
			_getch();
			system("CLS");
		}
	}
}

void FunBuses()
{
	char ch;
	string a[] = {
		"�������� ���������� �� ���������",
		"�������� ������ �� ��������",
		"��������� ���������� �� ���������",
		"������� ������ �� ��������",
		"��������� �������� � ������",
		"����������",
		"�����",
		"�����" };
	int active_menu = 0;
	while (true)
	{
		GoToXY(0, 0);
		for (int i = 0; i < size(a); i++)
		{
			if (i == active_menu) 	SetColor(LightMagenta, Black);
			else 	SetColor(Yellow, Black);
			cout << a[i] << endl;
		}
		ch = _getch();
		if (ch == -32) ch = _getch();
		int size_bus = 0;
		Bus* arr_buses = new Bus[0];
		switch (ch)
		{
		case ESC:
			delete[]arr_buses;
			system("CLS");
			return;

		case UP:
			if (active_menu > 0)
				active_menu--;
			else
				active_menu = size(a) - 1;
			break;
		case DOWN:
			if (active_menu < size(a) - 1)
				active_menu++;
			else
				active_menu = 0;
			break;
		case ENTER:
			switch (active_menu)
			{
			case 0:
				system("CLS");
				size_bus = Length_file("bus.txt");
				arr_buses = new Bus[size_bus];
				OutFileBus(arr_buses);
				cout << "+----------+-------------------------------+--------+-------+" << endl;
				cout << "|" << setw(11) << "���.�����|" << setw(32) << "��� ��������|" << setw(9) << "�������|" << setw(8) << "������|" << endl;
				for (int i = 0; i < size_bus; i++)
				{
					arr_buses[i].OutputBus();
				}
				cout << "+----------+-------------------------------+--------+-------+" << endl;
				_getch();
				system("CLS");
				break;
			case 1:
				system("CLS");
				int size_bus;
				cout << "������� ���������� ���������" << endl;
				size_bus=CinIntErrorCheck(1,50);
				arr_buses = new Bus[size_bus];
				for (int i = 0; i < size_bus; i++)
				{
					arr_buses[i].NewBus();
				}
				_getch();
				system("CLS");
				break;
			case 2:
				system("CLS");
				ChangeBus();
				_getch();
				system("CLS");
				break;
			case 3:
				system("CLS");
				DeleteBus();
				_getch();
				system("CLS");
				break;
			case 4:
				system("CLS");
				Repair();
				_getch();
				system("CLS");
				break;
			case 5:
				system("CLS");
				SorteBus();
				_getch();
				system("CLS");
				break;
			case 6:
				delete[]arr_buses;
				system("CLS");
				return;
			case 7:
				delete[]arr_buses;
				system("CLS");
				GoToXY(45, 13);
				SetColor(Yellow, Black);
				cout << "����� �� ���������...";
				_getch();
				system("CLS");
				GoToXY(0, 0);
				exit(0);
			default:
				GoToXY(0, 9);
				cout << "����������� �������" << endl;
				_getch();
				system("CLS");
			}
			break;
		default:
			GoToXY(0, 9);
			cout << "����������� �������" << endl;
			_getch();
			system("CLS");
		}
	}
}

void FunUsers()
{
	char ch;
	string a[] = {
		"�������� ���� ������� ������� �������������",
		"����������� ������ ��������������",
		"��������� ������� ������������",
		"�����",
		"�����" };
	int active_menu = 0;
	while (true)
	{
		GoToXY(0, 0);
		for (int i = 0; i < size(a); i++)
		{
			if (i == active_menu) 	SetColor(LightMagenta, Black);
			else 	SetColor(Yellow, Black);
			cout << a[i] << endl;
		}
		ch = _getch();
		if (ch == -32) ch = _getch();
		int size_us = 0;
		User* arr_us = new User[0];
		switch (ch)
		{
		case ESC:
			delete[]arr_us;
			system("CLS");
			return;

		case UP:
			if (active_menu > 0)
				active_menu--;
			else
				active_menu = size(a) - 1;
			break;
		case DOWN:
			if (active_menu < size(a) - 1)
				active_menu++;
			else
				active_menu = 0;
			break;
		case ENTER:
			switch (active_menu)
			{
			case 0:
				system("CLS");
				size_us = Length_file("user.txt");
				arr_us = new User[size_us];
				OutFileUser(arr_us);
				cout << "+-------------------+-------------------+--------+" << endl;
				cout << "|" << setw(20) << "�����|" << setw(20)  << "������|" << setw(9) << "������|" << endl;
				for (int i = 0; i < size_us; i++)
					arr_us[i].OutputUser();
				cout << "+-------------------+-------------------+--------+" << endl;
				_getch();
				system("CLS");
				break;
			case 1:
				system("CLS");
				LoginMenu(1, 0, 0);
				_getch();
				system("CLS");
				break;
			case 2:
				system("CLS");
				ChangeStatus();
				_getch();
				system("CLS");
				break;
			case 3:
				delete[]arr_us;
				system("CLS");
				return;
			case 4:
				delete[]arr_us;
				system("CLS");
				GoToXY(45, 13);
				SetColor(Yellow, Black);
				cout << "����� �� ���������...";
				_getch();
				system("CLS");
				GoToXY(0, 0);
				exit(0);
			default:
				GoToXY(0, 6);
				cout << "����������� �������" << endl;
				_getch();
				system("CLS");
			}
			break;
		default:
			GoToXY(0, 6);
			cout << "����������� �������" << endl;
			_getch();
			system("CLS");
		}
	}
}

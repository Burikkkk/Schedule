#include "Menu.h"

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // Получает дескриптор консоли

void GoToXY(short x, short y) // Курсор в точку x,y
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}

void SetColor(ConsoleColor text, ConsoleColor background) // Установка цвета текста
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
 
void ConsoleCursorVisible(bool show, short size) // Видимость и размеры курсора
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = show; // изменяет видимость курсора
	structCursorInfo.dwSize = size;   // изменяет размер курсора
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}


void StartMenu()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleTitle(L"Расписание маршрутов автобусов города ");
	ConsoleCursorVisible(false, 100);
	int y=10, x=35;
	SetColor(Yellow, Black);
	GoToXY(x, y); y++;
	cout << "        ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶       "; GoToXY(x, y); y++;
	cout << "       ¶¶¶   ¶¶     ¶¶¶     ¶¶¶     ¶¶      "; GoToXY(x, y); y++;
	cout << "       ¶¶¶   ¶¶     ¶¶¶     ¶¶¶     ¶¶      "; GoToXY(x, y); y++;
	cout << "       ¶¶    ¶¶     ¶¶¶     ¶¶¶     ¶¶      "; GoToXY(x, y); y++;
	cout << "       ¶¶    ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶      "; GoToXY(x, y); y++;
	cout << "      ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶      "; GoToXY(x, y); y++;
	cout << "      ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶      "; GoToXY(x, y); y++;
	cout << "      ¶¶¶¶¶     ¶¶¶¶¶¶¶¶¶¶¶¶     ¶¶¶¶¶      "; GoToXY(x, y); y++;
	cout << "       ¶¶¶ ¶¶¶¶¶ ¶¶¶¶¶¶¶¶¶¶ ¶¶¶¶¶ ¶¶¶       "; GoToXY(x, y); y++;
	cout << "          ¶¶¶0¶¶¶          ¶¶¶0¶¶¶          "; GoToXY(x, y); y+=2;
	cout << "           ¶¶¶¶¶            ¶¶¶¶¶           "; GoToXY(x, y); 
	cout << "                  Загрузка.                 "; GoToXY(x, y); 
	Sleep(500);
	cout << "                  Загрузка..                "; GoToXY(x, y); y += 2;
	Sleep(500);
	cout << "                  Загрузка...               "; GoToXY(x, y);
	Sleep(1000);
	cout << "    Нажмите любую клавишу для продолжения   "; GoToXY(x, y);
	_getch();
	system("CLS");
	string m[] = { "Войти как пользователь", "Войти как администратор", "Регистрация", "Выход" };
	int active_menu = 0; // Для подсветки пункта меню
	char ch; // Для кода нажатой клавиши
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
		if (ch == -32) ch = _getch(); // Получение кода нажатой стрелки
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
				cout << "Выход из программы...";
				_getch();
				system("CLS");
				GoToXY(0,0);
				exit(0);
			default:
				cout << "Используйте стрелки" << endl;
				_getch();
				system("CLS");
			}
			break;
		default:
			GoToXY(45, 17);
			cout << "Используйте стрелки" << endl;
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
	cout << "Введите логин: ";
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
				cout << "Учетная запись найдена.";
				GoToXY(x, y++);
				SetColor(LightMagenta, Black);
				cout << "Введите пароль: ";
				SetColor(Yellow, Black);
				while (k != 5) 
				{
					GoToXY(x, y++);
					temp.Password();
					while (temp.GetPassword() == "NOPASSWORD")
					{
						cout << "Вы не ввели пароль, попробуйте еще раз" << endl;
						GoToXY(x, y++);
						temp.Password();
					}
					if (arr_users[i].GetPassword() == temp.GetPassword())
					{
						delete[]arr_users;
						p = 1;
						GoToXY(x, y++);
						cout << "Вход выполнен.";
						_getch();
						system("CLS");
						FunctionsUser();
						break;
					}
					else if(k == 3)
					{
						GoToXY(x, y++);
						cout << "Это последняя попытка ввода пароля.";
						GoToXY(x, y++);
						cout << "Хорошо подумайте и попробуйте еще раз";
						k++;
					}
					else if (k == 4)
					{
						GoToXY(x, y++);
						cout << "Неверный пароль.";
						k++;
					}
					else
					{
						GoToXY(x, y++);
						cout << "Неверный пароль. Попробуйте еще раз";
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
		cout << "Учетной записи с таким именем не найдено";
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
		cout << "Вы 5 раз ввели неправильный пароль.";
		GoToXY(x, y++);
		cout << "Подождите 3 минуты перед следующей попыткой...";
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
	cout << "Введите логин: ";
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
				cout << "Учетная запись найдена.";
				GoToXY(x, y++);
				SetColor(LightMagenta, Black);
				cout << "Введите пароль: ";
				SetColor(Yellow, Black);
				while (k != 3)
				{
					GoToXY(x, y++);
					temp.Password();
					while (temp.GetPassword() == "NOPASSWORD")
					{
						cout << "Вы не ввели пароль, попробуйте еще раз" << endl;
						GoToXY(x, y++);
						temp.Password();
					}
					if (arr_users[i].GetPassword() == temp.GetPassword())
					{
						delete[]arr_users;
						p = 1;
						GoToXY(x, y++);
						cout << "Вход выполнен.";
						_getch();
						system("CLS");
						
						FunctionsAdmin();
						break;
					}
					else if (k == 1)
					{
						GoToXY(x, y++);
						cout << "Это последняя попытка ввода пароля.";
						k++;
					}
					else if (k == 2)
					{
						GoToXY(x, y++);
						cout << "Неверный пароль.";
						k++;
					}
					else
					{
						GoToXY(x, y++);
						cout << "Неверный пароль. Попробуйте еще раз";
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
		cout << "Учетной записи с таким именем не найдено";
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
		cout << "Вы 3 раза ввели неправильный пароль.";
		GoToXY(x, y++);
		cout << "Подождите 3 минуты перед следующей попыткой...";
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
	cout << "Введите логин: ";
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
		cout << "Введите пароль: ";
		SetColor(Yellow, Black);
		GoToXY(x, y++);
		temp.Password();
		while (temp.GetPassword() == "NOPASSWORD")
		{
			cout << "Вы не ввели пароль, попробуйте еще раз" << endl;
			GoToXY(x, y++);
			temp.Password();
		}
		GoToXY(x, y++);
		cout << "Подтвердите пароль: ";
		while (k != 3)
		{
			GoToXY(x, y++);
			temp_pass.Password();
			while (temp_pass.GetPassword() == "NOPASSWORD")
			{
				cout << "Вы не ввели пароль, попробуйте еще раз" << endl;
				GoToXY(x, y++);
				temp_pass.Password();
			}
			if (temp.GetPassword() == temp_pass.GetPassword())
			{
				delete[]arr_users;
				p = 1;
				GoToXY(x, y++);
				cout << "Учетная запись создана";
				GoToXY(x, y++);
				temp.InFileUser();
				break;
			}
			else if (k == 1)
			{
				GoToXY(x, y++);
				cout << "Это последняя попытка ввода пароля.";
				k++;
			}
			else if (k == 2)
			{
				GoToXY(x, y++);
				cout << "Неверный пароль.";
				k++;
			}
			else
			{
				GoToXY(x, y++);
				cout << "Неверный пароль. Попробуйте еще раз";
				k++;
			}
		}
	}
	else
	{
		delete[]arr_users;
		GoToXY(x, y++);
		cout << "Учетная запись с таким именем уже существует";
		p = 1;
	}
	if (p == 0)
	{
		delete[]arr_users;
		y++;
		GoToXY(x, y++);
		cout << ".............................................";
		GoToXY(x, y++);
		cout << "Вы 3 раза ввели неправильный пароль.";
		GoToXY(x, y++);
		cout << "Начните регистрацию заново.";
		_getch;
	}
		
}

void FunctionsUser()
{
	char ch;
	string b[] = { 
		"Просмотреть все маршруты", 
		"Сортировка",
		"Поиск маршрута по номеру", 
		"Расчет времени до прибытия ближайшего автобуса",
		"Назад",
		"Выход" };
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
				cout << "Выход из программы...";
				_getch();
				system("CLS");
				GoToXY(0, 0);
				exit(0);
			default:
				GoToXY(0, 7);
				cout << "Используйте стрелки" << endl;
				_getch();
				system("CLS");
			}
			break;
		default:
			GoToXY(0, 7);
			cout << "Используйте стрелки" << endl;
			_getch();
			system("CLS");
		}
	}
}

void FunctionsAdmin()
{
	char ch;
	string a[] = {
		"Управление маршрутами",
		"Упрвление автобусами",
		"Управление учетными записями пользователей",
		"Назад",
		"Выход" };
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
				cout << "Выход из программы...";
				_getch();
				system("CLS");
				GoToXY(0, 0);
				exit(0);
			default:
				GoToXY(0, 6);
				cout << "Используйте стрелки" << endl;
				_getch();
				system("CLS");
			}
			break;
		default:
			GoToXY(0, 6);
			cout << "Используйте стрелки" << endl;
			_getch();
			system("CLS");
		}
	}
}

void FunRoutes()
{
	char ch;
	string a[] = {
		"Просмотреть все маршруты",
		"Добавление нового маршрута",
		"Редактирование маршрута",
		"Удаление маршрута",
		"Сортировка",
		"Назад",
		"Выход" };
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
				cout << "Выход из программы...";
				_getch();
				system("CLS");
				GoToXY(0, 0);
				exit(0);
			default:
				GoToXY(0, 8);
				cout << "Используйте стрелки" << endl;
				_getch();
				system("CLS");
			}
			break;
		default:
			GoToXY(0, 8);
			cout << "Используйте стрелки" << endl;
			_getch();
			system("CLS");
		}
	}
}

void FunBuses()
{
	char ch;
	string a[] = {
		"Просмотр информации об автобусах",
		"Добавить запись об автобусе",
		"Изменение информации об автобусах",
		"Удалить данные об автобусе",
		"Отправить автобусы в ремонт",
		"Сортировка",
		"Назад",
		"Выход" };
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
				cout << "|" << setw(11) << "Рег.номер|" << setw(32) << "ФИО водителя|" << setw(9) << "Маршрут|" << setw(8) << "Ремонт|" << endl;
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
				cout << "Введите количество автобусов" << endl;
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
				cout << "Выход из программы...";
				_getch();
				system("CLS");
				GoToXY(0, 0);
				exit(0);
			default:
				GoToXY(0, 9);
				cout << "Используйте стрелки" << endl;
				_getch();
				system("CLS");
			}
			break;
		default:
			GoToXY(0, 9);
			cout << "Используйте стрелки" << endl;
			_getch();
			system("CLS");
		}
	}
}

void FunUsers()
{
	char ch;
	string a[] = {
		"Просмотр всех учетных записей пользователей",
		"Регистрация нового администратора",
		"Изменение статуса пользователя",
		"Назад",
		"Выход" };
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
				cout << "|" << setw(20) << "Логин|" << setw(20)  << "Пароль|" << setw(9) << "Статус|" << endl;
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
				cout << "Выход из программы...";
				_getch();
				system("CLS");
				GoToXY(0, 0);
				exit(0);
			default:
				GoToXY(0, 6);
				cout << "Используйте стрелки" << endl;
				_getch();
				system("CLS");
			}
			break;
		default:
			GoToXY(0, 6);
			cout << "Используйте стрелки" << endl;
			_getch();
			system("CLS");
		}
	}
}

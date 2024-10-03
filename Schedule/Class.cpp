#include "Class.h"

void Encrypt(string &pass)
{
	int number = pass.size(), k;
	char* temp = new char[number];
	k = 7;
	for(int i=0; i<number; i++)
	{
		int symbol = pass[i];
		symbol += k;
		temp[i] = symbol;
	}
	for (int i = 0; i < number; i++)
	{
		pass[i] = temp[i];
	}
	delete[]temp;
}

void Decrypt(string& pass)
{
	int number = pass.size(), k;
	char* temp = new char[number];
	k = 7;
	for (int i = 0; i < number; i++)
	{
		int symbol = pass[i];
		symbol -= k;
		temp[i] = symbol;
	}
	for (int i = 0; i < number; i++)
	{
		pass[i] = temp[i];
	}
	delete[]temp;
}


int Length_file(string name)
{
	ifstream f;
	f.open(name, ios::in);
	int i = 0;
	if (!f.is_open())
		cout << "Ошибка открытия файла" << endl;
	else
	{
		char a;
		while (!f.eof())
		{
			f.get(a);
			if (a == '\n') i++;
		}
	}
	f.close();
	return i - 1;
}

int Count_route(string name)
{
	ifstream f;
	f.open(name, ios::in);
	int k = 1;
	if (!f.is_open())
		cout << "Ошибка открытия файла" << endl;
	else
	{
		int i = 1, number[100], b;
		f >> number[0];
		char a;
		while (!f.eof())
		{
			f.get(a);
			if (a == '\n')
			{
				f >> b;
				if (number[i - 1] != b)
				{
					k++;
					number[i] = b;
					i++;
				}
			}
		}
	}
	f.close();
	return k;
}

int CinIntErrorCheck(int min, int max) {
	int wcheck;
	cin >> wcheck;
	while (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' ') || wcheck < min || wcheck > max) {
		rewind(stdin);
		cin.clear();
		//cin.ignore(100, '\n');
		cout << "Ошибка. Попробуйте ещё раз.\n";
		cin >> wcheck;
	}
	rewind(stdin);
	return wcheck;
}

double CinDoubleErrorCheck(double min, double max) {
	double wcheck;
	cin >> wcheck;
	while (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' ') || wcheck < min || wcheck > max) {
		rewind(stdin);
		cin.clear();
		//cin.ignore(100, '\n');
		cout << "Ошибка. Попробуйте ещё раз.\n";
		cin >> wcheck;
	}
	rewind(stdin);
	return wcheck;
}

bool CinBoolErrorCheck() {
	bool wcheck;
	cin >> wcheck;
	while (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' ')) {
		rewind(stdin);
		cin.clear();
		//cin.ignore(100, '\n');
		cout << "Ошибка. Попробуйте ещё раз.\n";
		cin >> wcheck;
	}
	rewind(stdin);
	return wcheck;
}

int CinIntErrorCheck() {
	int wcheck;
	cin >> wcheck;
	while (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' ')) {
		rewind(stdin);
		cin.clear();
		//cin.ignore(100, '\n');
		cout << "Ошибка. Попробуйте ещё раз.\n";
		cin >> wcheck;
	}
	rewind(stdin);
	return wcheck;
}

string CinStringSymAngErrorCheck(int &x, int &y) {
	string wcheck;
	int n, ch;
	bool a = 0;
	if(x!=0 && y!=0)
		GoToXY(x, y++); 
	cin >> wcheck;
	rewind(stdin);
	n = wcheck.size();
	do {

		for (int i = 0; i < n; i++)
		{
			if ((!(wcheck[i] >= 'a' && wcheck[i] <= 'z') && !(wcheck[i] >= 'A' && wcheck[i] <= 'Z')) && (wcheck[i] < '0' || wcheck[i] > '9'))
			{
				a = 0;
				if (x != 0 && y != 0)
					GoToXY(x, y++);
				cout << "Ошибка. Попробуйте ещё раз." << endl;
				if (x != 0 && y != 0)
					GoToXY(x, y++);
				cin >> wcheck;
				rewind(stdin);
				n = wcheck.size();
				break;
			}
			else a = 1;
		}
	} while (a == 0);
	return wcheck;
}

string CinStringSymRusErrorCheck() {
	string wcheck;
	int n, ch;
	bool a = 0;
	cin >> wcheck;
	rewind(stdin);
	n = wcheck.size();
	do {

		for (int i = 0; i < n; i++)
		{
			if (!(wcheck[i] >= 'а' && wcheck[i] <= 'я') && !(wcheck[i] >= 'А' && wcheck[i] <= 'Я'))
			{
				a = 0;
				cout << "Ошибка. Попробуйте ещё раз." << endl;
				cin >> wcheck;
				rewind(stdin);
				n = wcheck.size();
				break;
			}
			else a = 1;
		}
	} while (a == 0);
	return wcheck;
}

string CinNomerErrorCheck() {
	string wcheck, t="ABEIKMHOPCTX";
	int n, ch;
	bool a = 0, b=0;
	do {
		cin >> wcheck;
		rewind(stdin);
		n = wcheck.size();
		if (n == 6)
		{
			for (int i = 0; i < 2; i++)
			{
				b = 0;
				for (int j = 0; j < 13; j++)
				{
					if (wcheck[i] == t[j])
					{
						b = 1;
						break;
					}
				}
				if (b == 0)
				{
					a = 0;
					cout << "Ошибка. Попробуйте ещё раз." << endl;
					n = 0;
					break;
				}
			}
			for (int i = 2; i < n; i++)
			{
				if (wcheck[i] < '0' || wcheck[i] > '9')
				{
					a = 0;
					cout << "Ошибка. Попробуйте ещё раз." << endl;
					n = 0;
					break;
				}
				else a = 1;
			}
		}
		else
			cout << "Некорректное количество символов" << endl;
	} while (n != 6);
	return wcheck;
}


void User::InFileUser()
{
	string name = "user.txt";
	ofstream f;
	f.open(name, ios::app);
	if (!f.is_open())
		cout << "Ошибка открытия файла" << endl;
	else
	{
		Encrypt(password);
		f << login << "\t" << password << "\t" << status<<"\n";
	}
	f.close();
}

void OutFileUser(User *(&arr_users))
{
	string name = "user.txt";
	ifstream f;
	f.open(name, ios::in);
	if (!f.is_open())
		cout << "Ошибка открытия файла" << endl;
	else
	{
		int size = Length_file("user.txt");
		string log, pass;
		int stat;
		for (int i = 0; i < size; i++)
		{
			f >> log >> pass >> stat;
			Decrypt(pass);
			arr_users[i].login = log;
			arr_users[i].password = pass;
			arr_users[i].status = stat;
		}
	}
	f.close();
}

void User::Password()
{
	int ch = 0;
	string pass;
	while (true)
	{
		ch = _getch();
		if (ch == 13)
		{
			break;
		}
		else if (ch == 32)
		{
			break;
		}
		else if (ch == 8) // Удаление последнего введенного символа
		{

			if (!pass.empty())
			{
				cout << (char)8 << ' ' << (char)8; // Удаление из консоли
				pass.erase(pass.length() - 1); // Удаление из памяти
			}
		}
		else
		{
			cout << '*';
			pass = pass + (char)ch;
		}
	}
	if (!pass.empty())
		password = pass;
	else
		password = "NOPASSWORD";
}

void User::OutputUser()
{
	cout << "+-------------------+-------------------+--------+" << endl;
	cout <<"|" << setw(19) << login << "|" << setw(19) << password << "|" << setw(8) << status <<"|" << endl;
}


void NewRoutes()
{
	int n;
	cout << "Введите количество маршрутов: " << endl;
	n = CinIntErrorCheck(1,50);
	int interval, time_start, h, m, kol = 10, p;
	double time_h, time_m;
	int size = Count_route("route.txt");
	bool r=0;
	Route* routes = new Route[size];
	OutFileRoute(routes, size);
	Route* temps = new Route[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Введите номер маршрута: " << endl;
		temps[i].number= CinIntErrorCheck(1, 999);
		r = 0;
		for (int j = 0; j < size; j++)
		{
			if (routes[j].GetNumber() == temps[i].number)
			{
				r = 1;
				break;
			}
		}
		if (r == 0)
		{
			temps[i].NewBusStop();
			temps[i].InFileRoute();
			cout << "Данные были записаны в базу данных" << endl;
		}
		else
			cout << "Маршрут с таким номером уже существует" << endl;
	}		
	delete[]temps;
	delete[]routes;
}

void Route::NewBusStop()
{
	int interval, time_start, h, m, kol = 10, p;
	double time_h, time_m;
	string name;
	cout << "Введите количество остановок (минимум две): " << endl;
	kol = CinIntErrorCheck(2, 10);
	kol_ost = kol;
	double* time = new double[kol + 1];
	time[0] = 0;
	bool first = true;
	for (int j = 0, l = 1; j < kol; j++, l++)
	{

		cout << "Введите название остановки: " << endl;
		name=CinStringSymRusErrorCheck();
		bus_stop[j].SetName(name);
		bool in = true;
		do {
			cout << "Введите время начала движения" << endl;
			time[l]= CinDoubleErrorCheck(4, 21);
			if (time[l] > time[l - 1])
			{
				in = false;
				if (first)
				{
					cout << "Введите интервал движения в минутах " << endl;
					interval= CinIntErrorCheck(5, 120);
					first = false;
				}
				time_h = (int)time[l];
				time_m = (time[l] - (int)time[l]) * 100;
				time_start = time_h * 60 + time_m;
				p = 0;
				for (int k = time_start; k < 24 * 60; k += interval, p++)
				{
					h = k / 60 % 24;
					m = k % 60;
					bus_stop[j].SetTime(p, h + m / 100.);
				}
				bus_stop[j].SetKolTime(p);
			}
			else
				cout << "Вы ввели некорректное время начала движения на этой остановке" << endl;
		} while (in);

	}
	delete[]time;
}

void Route::InFileRoute()
{
	string name = "route.txt";
	ofstream f;
	f.open(name, ios::app);
	if (!f.is_open())
		cout << "Ошибка открытия файла" << endl;
	else

	{
		int k = 0, i, j;
		for (i = 0; i < kol_ost; i++)
		{
			f << number << "\t" << bus_stop[i].GetName() << "\t";
			for (j = 0; j < bus_stop[i].GetKolTime()-1 ; j++)
			{
				f << bus_stop[i].GetTime(j) << " ";
			}
			f << bus_stop[i].GetTime(j);
			k++;
			f << "\n";
		}
		
	}
	f.close();
}

void OutFileRoute(Route* (&arr_route), int kol_route)
{
	string name = "route.txt";
	ifstream f;
	f.open(name, ios::in);
	if (!f.is_open())
		cout << "Ошибка открытия файла" << endl;
	else
	{
		int number;
		string ost;
		char a;
		int j = 0, k = 0, i = 0;
		double time;
		f >> number >> ost;
		arr_route[i].number = number;
		arr_route[i].bus_stop[j].SetName(ost);
		f.get(a);
		while (a != '\n')
		{
			f >> time;
			arr_route[i].bus_stop[j].SetTime(k, time);
			k++;
			f.get(a);
		}
		arr_route[i].bus_stop[j].SetKolTime(k);
		arr_route[i].kol_ost = j + 1;
		while (f.good())
		{
			i++;
			f >> number >> ost;
			f.get(a);
			if (a=='\n')
			{
				break;
			}
			if (arr_route[i-1].number==number&&a!='\n')
			{
				i--;
				j++;
				arr_route[i].kol_ost = j + 1;
				
			}
			else if(a != '\n')
			{
				arr_route[i].number = number;
				j = 0;
				arr_route[i].kol_ost = j + 1;
				
			}
			k = 0;
			
			arr_route[i].bus_stop[j].SetName(ost);
			
			while (a != '\n')
			{
				f >> time;
				arr_route[i].bus_stop[j].SetTime(k, time);
				k++;
				f.get(a);
			}
			arr_route[i].bus_stop[j].SetKolTime(k);
		}		
	}
	f.close();
}

void Route::OutputRoute()
{
	int ostatok, t;
	
	cout << "+----------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "|" << setw(60);
	SetColor(LightMagenta, Black);
	cout << number;
	SetColor(Yellow, Black);
	cout << setw(59) << "|" << endl;
	cout << "+---------------------+------------------------------------------------------------------------------------------------+" << endl;
	cout << "|" << setw(22) << "Название остановки|" << " Время движения" << setw(82) << "|";
	for (int i = 0; i < kol_ost; i++)
	{
		
		cout << "+---------------------+------------------------------------------------------------------------------------------------+" << endl;
		cout << "|" << setw(21) << bus_stop[i].GetName() << "|";
		ostatok = bus_stop[i].GetKolTime()-(bus_stop[i].GetKolTime()/16)*16;
		t = 16 - ostatok;
		for (int j = 0; j < bus_stop[i].GetKolTime(); j++)
		{
			cout << fixed << setprecision(2) << setw(6) <<bus_stop[i].GetTime(j);
			if ((j+1) % 16 == 0 && j!=0)
			{
				cout << "|" << endl << "|                     |";
			}
		}
		cout << setw(t*6+1) << "|" << endl;
	}
	cout << "+---------------------+------------------------------------------------------------------------------------------------+" << endl;
	cout.unsetf(ios::fixed);

}

void Route::Copy(Route& arr_route)
{
	number = arr_route.number;
	kol_ost = arr_route.kol_ost;
	for (int i = 0; i < kol_ost; i++)
	{
		bus_stop[i].SetName(arr_route.bus_stop[i].GetName());
		bus_stop[i].SetKolTime(arr_route.bus_stop[i].GetKolTime());
		int size_time = arr_route.bus_stop[i].GetKolTime();
		for (int j = 0; j < size_time; j++)
		{
			bus_stop[i].SetTime(j, arr_route.bus_stop[i].GetTime(j));
		}
	}
}

void Route::SearchTime(int j)
{
	double timenow;
	int kol = bus_stop[j].GetKolTime();
	time_t now = time(0);
	tm* ltm = localtime(&now);

	/*cout << "Текущее время: " << setfill('0')<< setw(2) << ltm->tm_hour << ":" 
		<< setfill('0') << setw(2) << ltm->tm_min << ":" 
		<< setfill('0') << setw(2) << ltm->tm_sec << endl;*/

	timenow = ltm->tm_hour + ltm->tm_min / 100.;
	cout << "Текущее время: " << fixed << setprecision(2) << timenow<<endl;

	if (timenow > bus_stop[j].GetTime(kol - 1) || timenow < bus_stop[j].GetTime(0))
	{
		cout << "В это время данный автобус не ходит" << endl;
		return;
	}
	
	for (int i = 0; i < kol; i++)
	{
		if (bus_stop[j].GetTime(i) > timenow)
		{
			cout << "Ближайший автобус приедет в " << fixed << setprecision(2)<< bus_stop[j].GetTime(i);
			if (i+1<kol)
			{
				cout << ", " << bus_stop[j].GetTime(i + 1);
				if(i + 2 < kol)
				{ 
					cout << ", " << bus_stop[j].GetTime(i + 2) << endl;
				}
			}
			cout.unsetf(ios::fixed);
			return;
		}
	}
}


void Bus::NewBus()
{
	bool a=0, f=0, n=0;
	string FIO, id;
	int size= Count_route("route.txt");
	Route* arr = new Route[size];
	OutFileRoute(arr, size);
	int size_b = Length_file("bus.txt");
	Bus* temp = new Bus[size_b];
	OutFileBus(temp);
	cout << "Введите номер маршрута, по которому ездит автобус" << endl;
	number=CinIntErrorCheck(1,999);
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetNumber() == number)
		{
			a = 1;
			cout << "Введите регистрационный номер автобуса (XX0000)" << endl;
			id=CinNomerErrorCheck();
			cout << "Введите ФИО водителя через пробелы" << endl;
			string f, i, o, name;
			char c = ' ';
			cout << "Введите фамилию:" << endl;
			f = CinStringSymRusErrorCheck();
			cout << "Введите имя:" << endl;
			i = CinStringSymRusErrorCheck();
			cout << "Введите отчество:" << endl;
			o = CinStringSymRusErrorCheck();
			name.append(f);
			name.push_back(c);
			name.append(i);
			name.push_back(c);
			name.append(o);
			FIO = name;
			for (int j = 0; j < size_b; j++)
			{
				if (temp[j].GetFIO() == FIO)
				{
					f = 1;
				}
				if (temp[j].GetID() == id)
				{
					n = 1;
				}
			}
		}
	}
	if (a == 0)
	{
		cout << "Такого маршрута не найдено" << endl;

	}
	else if (f == 1)
		cout << "Водитель уже ездит на другом автобусе" << endl;
	else if (n == 1)
		cout << "Автобус с таким регистрационным номером уже существует" << endl;
	else
	{
		this->id = id;
		this->FIO = FIO;
		cout << "0-Не требуется ремонт\t1-Требуется ремонт" << endl;
		repair= CinBoolErrorCheck();
		InFileBus();
		cout << "Данные были занесены в базу данных" << endl;
	}
	
	delete[]temp;
	delete[]arr;
}

void Bus::InFileBus()
{
	string name = "bus.txt";
	ofstream f;
	f.open(name, ios::app);
	if (!f.is_open())
		cout << "Ошибка открытия файла" << endl;
	else
	{
		f << id << "\t" << FIO << "\t" << number << "\t" << repair << "\n";
	}
	f.close();
}

void OutFileBus(Bus* (&arr_buses))
{
	string name = "bus.txt";
	ifstream f;
	f.open(name, ios::in);
	if (!f.is_open())
		cout << "Ошибка открытия файла" << endl;
	else
	{
		int len = Count_route("route.txt");
		Route* arr = new Route[len];
		OutFileRoute(arr, len);
		char a, p=' ';
		int size = Length_file("bus.txt");
		string id, FIO, temp;
		int number;
		
		bool repair, num=0;
		for (int i = 0; i < size; i++)
		{
			f >> id >> temp;
			arr_buses[i].id = id;
			FIO = temp;
			f.get(a);
			while (a != '\t')
			{
				f >> temp;
				FIO.push_back(p);
				FIO.append(temp);
				f.get(a);	
			}
			arr_buses[i].FIO = FIO;
			f >> number >> repair;
			for (int j = 0; j < len; j++)
			{
				num = 0;
				if (arr[j].GetNumber() == number)
				{
					arr_buses[i].number = number;
					num = 1;
					break;
				}
			}
			if (num == 0)
			{
				arr_buses[i].number = 0;
			}
			arr_buses[i].repair = repair;
			

		}
		delete[]arr;
	}
	f.close();
}

void Bus::OutputBus()
{
	cout << "+----------+-------------------------------+--------+-------+" << endl;
	cout << "|" << setw(10) << id << "|" << setw(31) << FIO << "|" << setw(8);
	if (number == 0)
		cout << " - " << "|" << setw(7) << repair << "|" << endl;
	else
		cout << number << "|" << setw(7) << repair << "|" << endl;
}

void Bus::CopyBus(Bus& arr)
{
	id = arr.id;
	FIO = arr.FIO;
	number = arr.number;
	repair = arr.repair;
}
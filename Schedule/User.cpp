#include "User.h"

void SorteRoute()
{
	int size = Count_route("route.txt");
	Route* arr = new Route[size], temp;
	OutFileRoute(arr, size);
	int min, a;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j].GetNumber() < arr[min].GetNumber())
				min = j;
		}
		temp.Copy(arr[i]);
		arr[i].Copy(arr[min]);
		arr[min].Copy(temp);
	}
	cout << "Маршруты отсортированы" << endl
		<< "Просмотреть отсортированные данные?" << endl
		<< "1-Да\t2-Нет" << endl;
	a = CinIntErrorCheck(1, 2);;
	if (a == 1)
	{
		for (int s = 0; s < size; s++)
			arr[s].OutputRoute();
	}
	ofstream file;
	file.open("route.txt");
	file.close();
	for (int k = 0; k < size; k++)
	{
		arr[k].InFileRoute();
	}
	cout << "Данные были записаны в базу данных" << endl;
	delete[]arr;
}

void Search() {
	char ch;
	int size = Count_route("route.txt"), nomer;
	Route* arr = new Route[size];
	OutFileRoute(arr, size);
	cout << "Выберите номер маршрута:" << endl;
	int active_menu = 0;
	while (true)
	{
		GoToXY(0, 1);
		
		for (int i = 0; i < size; i++)
		{
			if (i == active_menu) 	SetColor(LightMagenta, Black);
			else 	SetColor(Yellow, Black);
			cout << arr[i].GetNumber() << endl;
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
				active_menu = size - 1;
			break;
		case DOWN:
			if (active_menu < size - 1)
				active_menu++;
			else
				active_menu = 0;
			break;
		case ENTER:
			system("CLS");
			SetColor(Yellow, Black);
			arr[active_menu].OutputRoute();
			cout << endl;
			_getch();
			system("CLS");
			return;
		default:
			GoToXY(0, size+2);
			SetColor(Yellow, Black);
			cout << "Используйте стрелки" << endl;
			_getch();
			system("CLS");
			GoToXY(0, 0);
			SetColor(Yellow, Black);
			cout << "Выберите номер маршрута:" << endl;
		}
	}
}

void SearchStop()
{
	bool n = 0;
	int size = Count_route("route.txt"), kol;
	string name;
	Route* arr = new Route[size];
	OutFileRoute(arr, size);
	cout << "Введите остановку искомого маршрута: " << endl;
	name=CinStringSymRusErrorCheck();
	for (int i = 0; i < size; i++)
	{
		kol = arr[i].GetKolost();
		for (int j = 0; j < kol; j++)
		{
			if (arr[i].GetBusStopName(j) == name)
			{
				n = 1;
				cout << "Остановка найдена" << endl;
				arr[i].OutputRoute();
				cout << endl;
			}
		}
	}
	if (n == 0)
	{
		delete[]arr;
		cout << "Маршрута с такими остановками не найдено" << endl;
		return;
	}
	delete[]arr;
}

void Time()
{
	bool n = 0, o = 0;
	int size = Count_route("route.txt"), nomer, kol;
	string name;
	Route* arr = new Route[size];
	OutFileRoute(arr, size);
	cout << "Введите номер искомого маршрута: " << endl;
	nomer=CinIntErrorCheck(1,999);
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetNumber() == nomer)
		{
			n = 1;
			cout << "Введите остановку искомого маршрута: " << endl;
			name = CinStringSymRusErrorCheck();
			kol = arr[i].GetKolost();
			for (int j = 0; j < kol; j++)
			{
				if (arr[i].GetBusStopName(j) == name)
				{
					o = 1;
					arr[i].SearchTime(j);

				}
			}

		}
	}
	if (n == 0)
	{
		delete[]arr;
		cout << "Маршрута с таким номером не найдено" << endl;
		return;
	}
	else if (o == 0)
	{
		delete[]arr;
		cout << "Маршрута с такой остановкой не найдено" << endl;
		return;
	}
	delete[]arr;
}

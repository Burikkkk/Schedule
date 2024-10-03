#include "Admin.h"

void ChangeStatus()
{
	int x = 0, y = 0;
	User temp;
	string log;
	bool l = 0;
	int stat;
	int size = Length_file("user.txt");
	User* arr = new User[size];
	OutFileUser(arr);
	cout << "Просмотреть существующие записи?" << endl
		<< "1-Да\t2-Нет" << endl;
	int choice;
	choice=CinIntErrorCheck(1,2);
	if (choice == 1) {
		cout << "+-------------------+-------------------+--------+" << endl;
		cout << "|" << setw(20) << "Логин|" << setw(20) << "Пароль|" << setw(9) << "Статус|" << endl;
		for (int s = 0; s < size; s++)
			arr[s].OutputUser();
		cout << "+-------------------+-------------------+--------+" << endl;
	}
	cout << "\nВведите логин: " << endl;
	log=CinStringSymAngErrorCheck(x,y);
	temp.SetLogin(log);
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetLogin() == temp.GetLogin())
		{
			l = 1;
			cout << "Учетная запись найдена" << endl;
			cout << "Введите новый статус пользователя: 0-Пользователь, 1-Администратор" << endl;
			stat=CinBoolErrorCheck();
			temp.SetStatus(stat);
			if (arr[i].GetStatus() != temp.GetStatus())
			{
				arr[i].SetStatus(stat);
				cout << "Статус изменен" << endl;
				ofstream file;
				file.open("user.txt");
				file.close();
				for (int j = 0; j < size; j++)
				{
					arr[j].InFileUser();
				}
			}
			else
			{
				cout << "Статусы совпадают" << endl;
				break;
			}
		}
	}
	if (l == 0)
	{
		cout << "Учетной записи с таким именем не найдено" << endl;
	}
	delete[]arr;
}

void ChangeRoute()
{
	bool n = 0;
	string name;
	int size = Count_route("route.txt"), nomer;
	Route* arr = new Route[size];
	OutFileRoute(arr, size);
	cout << "Просмотреть существующие маршруты?" << endl
		<< "1-Да\t2-Нет" << endl;
	int choice;
	choice = CinIntErrorCheck(1, 2);
	if (choice == 1) {
		for (int s = 0; s < size; s++)
			arr[s].OutputRoute();
	}
	cout << "\nВведите номер изменяемого маршрута: " << endl;
	nomer=CinIntErrorCheck(1,999);
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetNumber() == nomer)
		{
			n = 1;
			cout << "Маршрут найден" << endl;
			arr[i].NewBusStop();

			break;
		}
	}
	if (n == 0)
	{
		delete[]arr;
		cout << "Маршрута с таким номером не найдено" << endl;
		return;
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

void DeleteRoute()
{
	bool n = 0;
	string name;
	int size = Count_route("route.txt"), nomer, j = 0;
	Route* arr = new Route[size];
	OutFileRoute(arr, size);
	cout << "Просмотреть существующие маршруты?" << endl
		<< "1-Да\t2-Нет" << endl;
	int choice;
	choice = CinIntErrorCheck(1, 2);
	if (choice == 1) {
		for (int s = 0; s < size; s++)
			arr[s].OutputRoute();
	}
	cout << "\nВведите номер удаляемого маршрута: " << endl;
	nomer=CinIntErrorCheck(1,999);
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetNumber() == nomer)
		{
			n = 1;
		}
	}
	if (n == 0)
	{
		delete[]arr;
		cout << "Маршрута с таким номером не найдено" << endl;
		return;
	}
	cout << "Маршрут удален" << endl;
	ofstream file;
	file.open("route.txt");
	file.close();
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetNumber() != nomer)
		{
			arr[i].InFileRoute();
		}
	}
	delete[]arr;
}


void ChangeBus()
{
	bool l = 0, f = 0, n = 0;
	string nomer, FIO;
	int size = Length_file("bus.txt"), i, number;
	Bus* arr = new Bus[size];
	OutFileBus(arr);
	int size_r = Count_route("route.txt");
	Route* arr_route = new Route[size_r];
	OutFileRoute(arr_route, size_r);
	cout << "Просмотреть существующие записи?" << endl
		<< "1-Да\t2-Нет" << endl;
	int choice;
	choice = CinIntErrorCheck(1, 2);
	
	if (choice == 1) {
		cout << "+----------+-------------------------------+--------+-------+" << endl;
		cout << "|" << setw(11) << "Рег.номер|" << setw(32) << "ФИО водителя|" << setw(9) << "Маршрут|" << setw(8) << "Ремонт|" << endl;
		for (int s = 0; s < size; s++)
			arr[s].OutputBus();
		cout << "+----------+-------------------------------+--------+-------+" << endl;
	}

	int a;
	bool repair;
	string fam, im, ot, name;
	char c = ' ';
	cout << "\nВведите регистрационным номер (XX0000): " << endl;
	nomer=CinNomerErrorCheck();
	for (i = 0; i < size; i++)
	{
		if (arr[i].GetID() == nomer)
		{
			l = 1;
			cout << "Автобус найден" << endl;
			FIO = arr[i].GetFIO();
			number = arr[i].GetNumber();
			repair = arr[i].GetRepair();
			do {
				cout << "\nИзменить:" << endl
					<< "1-ФИО водителя" << endl
					<< "2-Номер маршрута" << endl
					<< "3-Требование ремонта" << endl
					<< "0-Назад\n" << endl;
				a = CinIntErrorCheck(0, 4);
				switch (a)
				{
				case 1:
					cout << "Введите фамилию:" << endl;
					fam = CinStringSymRusErrorCheck();
					cout << "Введите имя:" << endl;
					im = CinStringSymRusErrorCheck();
					cout << "Введите отчество:" << endl;
					ot = CinStringSymRusErrorCheck();
					name.append(fam);
					name.push_back(c);
					name.append(im);
					name.push_back(c);
					name.append(ot);
					FIO = name;
					for (int j = 0; j < size; j++)
					{
						if (arr[j].GetFIO() == FIO)
							f = 1;
					}
					break;
				case 2:
					cout << "Введите номер маршрута, по которому ездит автобус" << endl;
					number = CinIntErrorCheck(1, 999);
					
					break;
				case 3:
					cout << "0-Не требуется ремонт\t1-Требуется ремонт" << endl;
					repair = CinBoolErrorCheck();
					break;

				case 0: break;
				}
			} while (a!=0);
			for (int j = 0; j < size_r; j++)
			{
				if (arr_route[j].GetNumber() == number)
				{
					n = 1;
					break;
				}
			}
			break;
		}
	}

	if (l == 0)
		cout << "Автобуса с таким регистрационным номером не найдено" << endl;
	else if (f == 1)
		cout << "Водитель уже ездит на другом автобусе" << endl;
	else if (n == 0)
	{
		do {
			cout << "Такого маршрута не существует, попробуйте снова" << endl;
			cout << "Введите номер маршрута, по которому ездит автобус" << endl;
			number = CinIntErrorCheck(1, 999);
			for (int j = 0; j < size_r; j++)
			{
				if (arr_route[j].GetNumber() == number)
				{
					n = 1;
					break;
				}
			}
		} while (n == 0);
	}
	if(n==1 && l==1 && f==0)
	{
		
		arr[i].SetID(nomer);
		arr[i].SetFIO(FIO);
		arr[i].SetNumber(number);
		
		arr[i].SetRepair(repair);
		ofstream file;
		file.open("bus.txt");
		file.close();
		for (int j = 0; j < size; j++)
		{
			arr[j].InFileBus();
		}
		cout << "Данные были занесены в базу данных" << endl;
	}
	
	delete[]arr;
	delete[]arr_route;
	return;
}

void DeleteBus()
{
	bool n = 0;
	string nomer;
	int size = Length_file("bus.txt"), j = 0;
	Bus* arr = new Bus[size];
	OutFileBus(arr);
	cout << "Просмотреть данные об автобусах?" << endl
		<< "1-Да\t2-Нет" << endl;
	int choice;
	choice = CinIntErrorCheck(1, 2);
	if (choice == 1) {
		cout << "+----------+-------------------------------+--------+-------+" << endl;
		cout << "|" << setw(11) << "Рег.номер|" << setw(32) << "ФИО водителя|" << setw(9) << "Маршрут|" << setw(8) << "Ремонт|" << endl;
		for (int s = 0; s < size; s++)
			arr[s].OutputBus();
		cout << "+----------+-------------------------------+--------+-------+" << endl;
	}
	cout << "\nВведите регистрационный номер удаляемого автобуса: " << endl;
	nomer=CinNomerErrorCheck();
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetID() == nomer)
		{
			n = 1;
		}
	}
	if (n == 0)
		cout << "Автобуса с таким номером не найдено" << endl;
	else
	{
		cout << "Автобус удален" << endl;
		ofstream file;
		file.open("bus.txt");
		file.close();
		for (int i = 0; i < size; i++)
		{
			if (arr[i].GetID() != nomer)
			{
				arr[i].InFileBus();
			}
		}
	}
	delete[]arr;
}

void Repair()
{
	bool l = 0;
	int size = Length_file("bus.txt"), j = 0;
	Bus* arr = new Bus[size];
	OutFileBus(arr);
	cout << "Просмотреть данные об автобусах?" << endl
		<< "1-Да\t2-Нет" << endl;
	int choice;
	choice = CinIntErrorCheck(1, 2);
	if (choice == 1) {
		cout << "+----------+-------------------------------+--------+-------+" << endl;
		cout << "|" << setw(11) << "Рег.номер|" << setw(32) << "ФИО водителя|" << setw(9) << "Маршрут|" << setw(8) << "Ремонт|" << endl;
		for (int s = 0; s < size; s++)
			arr[s].OutputBus();
		cout << "+----------+-------------------------------+--------+-------+" << endl;
	}
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetRepair() == 1)
		{
			l = 1;
			arr[i].SetRepair(0);
		}
	}
	if (l == 0)
	{
		cout << "\nВсе автобусы исправны" << endl;
	}
	else
	{
		cout << "\nАвтобусы были отремонтированы" << endl;
		ofstream file;
		file.open("bus.txt");
		file.close();
		for (int i = 0; i < size; i++)
		{
			arr[i].InFileBus();
		}
	}
	delete[]arr;
}

void SorteBus()
{
	cout << "Выберите способ сортировки:" << endl
		<< "1-Сортировка по номеру автобуса" << endl
		<< "2-Сортировка по номеру маршрута" << endl
		<< "3-Сортировка по фамилии водителя" << endl;
	int size = Length_file("bus.txt"), b = 0, min, a;
	Bus* arr = new Bus[size], temp;
	OutFileBus(arr);
	b=CinIntErrorCheck(1,3);
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			switch (b)
			{
			case 1:
				if (arr[j].GetID() < arr[min].GetID())
					min = j;
				break;
			case 2:
				if (arr[j].GetNumber() < arr[min].GetNumber())
					min = j;
				break;
			case 3:
				if (arr[j].GetFIO() < arr[min].GetFIO())
					min = j;
				break;
			}
		}
		temp.CopyBus(arr[i]);
		arr[i].CopyBus(arr[min]);
		arr[min].CopyBus(temp);
	}
	cout << "Маршруты отсортированы" << endl
		<< "Просмотреть отсортированные данные?" << endl
		<< "1-Да\t2-Нет" << endl;
	a = CinIntErrorCheck(1, 2);
	if (a == 1)
	{
		cout << "+----------+-------------------------------+--------+-------+" << endl;
		cout << "|" << setw(11) << "Рег.номер|" << setw(32) << "ФИО водителя|" << setw(9) << "Маршрут|" << setw(8) << "Ремонт|" << endl;
		for (int s = 0; s < size; s++)
			arr[s].OutputBus();
		cout << "+----------+-------------------------------+--------+-------+" << endl;
	}
	ofstream file;
	file.open("bus.txt");
	file.close();
	for (int i = 0; i < size; i++)
	{
		arr[i].InFileBus();
	}
	cout << "\nДанные были записаны в базу данных" << endl;
	delete[]arr;
}

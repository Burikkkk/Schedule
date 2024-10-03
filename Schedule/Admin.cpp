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
	cout << "����������� ������������ ������?" << endl
		<< "1-��\t2-���" << endl;
	int choice;
	choice=CinIntErrorCheck(1,2);
	if (choice == 1) {
		cout << "+-------------------+-------------------+--------+" << endl;
		cout << "|" << setw(20) << "�����|" << setw(20) << "������|" << setw(9) << "������|" << endl;
		for (int s = 0; s < size; s++)
			arr[s].OutputUser();
		cout << "+-------------------+-------------------+--------+" << endl;
	}
	cout << "\n������� �����: " << endl;
	log=CinStringSymAngErrorCheck(x,y);
	temp.SetLogin(log);
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetLogin() == temp.GetLogin())
		{
			l = 1;
			cout << "������� ������ �������" << endl;
			cout << "������� ����� ������ ������������: 0-������������, 1-�������������" << endl;
			stat=CinBoolErrorCheck();
			temp.SetStatus(stat);
			if (arr[i].GetStatus() != temp.GetStatus())
			{
				arr[i].SetStatus(stat);
				cout << "������ �������" << endl;
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
				cout << "������� ���������" << endl;
				break;
			}
		}
	}
	if (l == 0)
	{
		cout << "������� ������ � ����� ������ �� �������" << endl;
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
	cout << "����������� ������������ ��������?" << endl
		<< "1-��\t2-���" << endl;
	int choice;
	choice = CinIntErrorCheck(1, 2);
	if (choice == 1) {
		for (int s = 0; s < size; s++)
			arr[s].OutputRoute();
	}
	cout << "\n������� ����� ����������� ��������: " << endl;
	nomer=CinIntErrorCheck(1,999);
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetNumber() == nomer)
		{
			n = 1;
			cout << "������� ������" << endl;
			arr[i].NewBusStop();

			break;
		}
	}
	if (n == 0)
	{
		delete[]arr;
		cout << "�������� � ����� ������� �� �������" << endl;
		return;
	}
	ofstream file;
	file.open("route.txt");
	file.close();
	for (int k = 0; k < size; k++)
	{
		arr[k].InFileRoute();
	}
	cout << "������ ���� �������� � ���� ������" << endl;
	delete[]arr;
}

void DeleteRoute()
{
	bool n = 0;
	string name;
	int size = Count_route("route.txt"), nomer, j = 0;
	Route* arr = new Route[size];
	OutFileRoute(arr, size);
	cout << "����������� ������������ ��������?" << endl
		<< "1-��\t2-���" << endl;
	int choice;
	choice = CinIntErrorCheck(1, 2);
	if (choice == 1) {
		for (int s = 0; s < size; s++)
			arr[s].OutputRoute();
	}
	cout << "\n������� ����� ���������� ��������: " << endl;
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
		cout << "�������� � ����� ������� �� �������" << endl;
		return;
	}
	cout << "������� ������" << endl;
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
	cout << "����������� ������������ ������?" << endl
		<< "1-��\t2-���" << endl;
	int choice;
	choice = CinIntErrorCheck(1, 2);
	
	if (choice == 1) {
		cout << "+----------+-------------------------------+--------+-------+" << endl;
		cout << "|" << setw(11) << "���.�����|" << setw(32) << "��� ��������|" << setw(9) << "�������|" << setw(8) << "������|" << endl;
		for (int s = 0; s < size; s++)
			arr[s].OutputBus();
		cout << "+----------+-------------------------------+--------+-------+" << endl;
	}

	int a;
	bool repair;
	string fam, im, ot, name;
	char c = ' ';
	cout << "\n������� ��������������� ����� (XX0000): " << endl;
	nomer=CinNomerErrorCheck();
	for (i = 0; i < size; i++)
	{
		if (arr[i].GetID() == nomer)
		{
			l = 1;
			cout << "������� ������" << endl;
			FIO = arr[i].GetFIO();
			number = arr[i].GetNumber();
			repair = arr[i].GetRepair();
			do {
				cout << "\n��������:" << endl
					<< "1-��� ��������" << endl
					<< "2-����� ��������" << endl
					<< "3-���������� �������" << endl
					<< "0-�����\n" << endl;
				a = CinIntErrorCheck(0, 4);
				switch (a)
				{
				case 1:
					cout << "������� �������:" << endl;
					fam = CinStringSymRusErrorCheck();
					cout << "������� ���:" << endl;
					im = CinStringSymRusErrorCheck();
					cout << "������� ��������:" << endl;
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
					cout << "������� ����� ��������, �� �������� ����� �������" << endl;
					number = CinIntErrorCheck(1, 999);
					
					break;
				case 3:
					cout << "0-�� ��������� ������\t1-��������� ������" << endl;
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
		cout << "�������� � ����� ��������������� ������� �� �������" << endl;
	else if (f == 1)
		cout << "�������� ��� ����� �� ������ ��������" << endl;
	else if (n == 0)
	{
		do {
			cout << "������ �������� �� ����������, ���������� �����" << endl;
			cout << "������� ����� ��������, �� �������� ����� �������" << endl;
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
		cout << "������ ���� �������� � ���� ������" << endl;
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
	cout << "����������� ������ �� ���������?" << endl
		<< "1-��\t2-���" << endl;
	int choice;
	choice = CinIntErrorCheck(1, 2);
	if (choice == 1) {
		cout << "+----------+-------------------------------+--------+-------+" << endl;
		cout << "|" << setw(11) << "���.�����|" << setw(32) << "��� ��������|" << setw(9) << "�������|" << setw(8) << "������|" << endl;
		for (int s = 0; s < size; s++)
			arr[s].OutputBus();
		cout << "+----------+-------------------------------+--------+-------+" << endl;
	}
	cout << "\n������� ��������������� ����� ���������� ��������: " << endl;
	nomer=CinNomerErrorCheck();
	for (int i = 0; i < size; i++)
	{
		if (arr[i].GetID() == nomer)
		{
			n = 1;
		}
	}
	if (n == 0)
		cout << "�������� � ����� ������� �� �������" << endl;
	else
	{
		cout << "������� ������" << endl;
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
	cout << "����������� ������ �� ���������?" << endl
		<< "1-��\t2-���" << endl;
	int choice;
	choice = CinIntErrorCheck(1, 2);
	if (choice == 1) {
		cout << "+----------+-------------------------------+--------+-------+" << endl;
		cout << "|" << setw(11) << "���.�����|" << setw(32) << "��� ��������|" << setw(9) << "�������|" << setw(8) << "������|" << endl;
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
		cout << "\n��� �������� ��������" << endl;
	}
	else
	{
		cout << "\n�������� ���� ���������������" << endl;
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
	cout << "�������� ������ ����������:" << endl
		<< "1-���������� �� ������ ��������" << endl
		<< "2-���������� �� ������ ��������" << endl
		<< "3-���������� �� ������� ��������" << endl;
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
	cout << "�������� �������������" << endl
		<< "����������� ��������������� ������?" << endl
		<< "1-��\t2-���" << endl;
	a = CinIntErrorCheck(1, 2);
	if (a == 1)
	{
		cout << "+----------+-------------------------------+--------+-------+" << endl;
		cout << "|" << setw(11) << "���.�����|" << setw(32) << "��� ��������|" << setw(9) << "�������|" << setw(8) << "������|" << endl;
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
	cout << "\n������ ���� �������� � ���� ������" << endl;
	delete[]arr;
}

#include <functions/functions.h>

#include <cstdlib>
#include <iostream>
#include <locale.h>

using namespace figure;
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int choise = 8;
	Storage figures;
	do {
		cout << " ___________________________________________________________________" << endl;
		cout << " |                              ����                                |" << endl;
		cout << " ___________________________________________________________________" << endl;
		cout << " | 1 - �������� ������ �� �������                                   |" << endl;
		cout << " | 2 - ��������� ������ �� �������                                  |" << endl;
		cout << " | 3 - ������� ������ �� �������                                    |" << endl;
		cout << " | 4 - ���������� �������                                           |" << endl;
		cout << " | 5 - ���������� �����                                             |" << endl;
		cout << " | 6 - ����� � ������ ������ ������ � ������������ �������          |" << endl;
		cout << " | 7 - ������� ������ �����                                         |" << endl;
		cout << " | 8 - ����� �� �������                                             |" << endl;
		cout << " -------------------------------------------------------------------" << endl;
	    cout << "��������, ��� �� ������ �������: ";
		cin >> choise;
		cout << "\n";
		switch (choise)
		{
		case 1: {
			int _index;
			int _type;
			Figure _figure;
			Point _points[3];
			int d = 0;
			cout << "������� ������ ������, �� �������� ������ �������� ������: ";
			cin >> _index;
			while (_index < 0 || _index > figures.get_size())
			{
				cout << "������� ������ ������. ������� ������: ";
				cin >> _index;
			}
			cout << "\n";
			do {
				cout << "������� ������, ������� ������ ��������: \n1) ����� \n2) ������� \n3) �������������� \n��� �����: ";
				cin >> _type;
				cout << "\n";
				switch (_type) {
				case 1: {
					cout << "������� ���������� ����� ����� ������: ";
					for (int i = 0; i < 2; ++i)
					{
						cin >> _points[i].x;
						cin >> _points[i].y;
						cin >> _points[i].z;
					}
					while (!(*_figure.create_sphere(_points)).chek_points())
					{
						cout << "������� ������� ����������. ��������� �������: ";
						for (int i = 0; i < 2; ++i)
						{
							cin >> _points[i].x;
							cin >> _points[i].y;
							cin >> _points[i].z;
						}
					}
					cout << "\n";
					const auto ptr = _figure.create_sphere(_points);
					figures.insert_figure(ptr, _index);
					d = 1;
				}break;
				case 2: {
					cout << "������� ���������� �������� ����� ������: ";
					for (int i = 0; i < 3; ++i)
					{
						cin >> _points[i].x;
						cin >> _points[i].y;
						cin >> _points[i].z;
					}
					while (!(*_figure.create_cylinder(_points)).chek_points())
					{
						cout << "������� ������� ����������. ��������� �������: ";
						for (int i = 0; i < 3; ++i)
						{
							cin >> _points[i].x;
							cin >> _points[i].y;
							cin >> _points[i].z;
						}
					}
					cout << "\n";
					const auto ptr = _figure.create_cylinder(_points);
					figures.insert_figure(ptr, _index);
					d = 1;
				}break;
				case 3: {
					cout << "������� ���������� ��������������� ����� ������: ";
					for (int i = 0; i < 2; ++i)
					{
						cin >> _points[i].x;
						cin >> _points[i].y;
						cin >> _points[i].z;
					}
					while (!(*_figure.create_parallelepiped(_points)).chek_points())
					{
						cout << "������� ������� ����������� ��������� �������: ";
						for (int i = 0; i < 2; ++i)
						{
							cin >> _points[i].x;
							cin >> _points[i].y;
							cin >> _points[i].z;
						}
					}
					cout << "\n";
					const auto ptr = _figure.create_parallelepiped(_points);
					figures.insert_figure(ptr, _index);
					d = 1;
				}break;
				}
			} while (d == 0);
		}break;
		case 2: {
			int _index;
			int _type;
			Figure _figure;
			Point _points[3];
			int d = 0;
			cout << "������� ������ ������, �� �������� ������ ���������� ������: ";
			cin >> _index;
			while (_index < 0 || _index > figures.get_size())
			{
				cout << "������� ������ ������. ��������� �������: ";
				cin >> _index;
			}
			cout << "\n";
			do
			{
				cout << "������� ������, ������� ������ ����������: \n1)�����  \n2)�������  \n3)�������������� \n��� �����: ";
				cin >> _type;
				cout << "\n";
				switch (_type)
				{
				case 1:
				{
					cout << "������� ���������� ����� ����� ������: ";
					for (int i = 0; i < 2; ++i)
					{
						cin >> _points[i].x;
						cin >> _points[i].y;
						cin >> _points[i].z;
					}
					while (!(*_figure.create_sphere(_points)).chek_points())
					{
						cout << "�������� ������� ����������. ��������� �������: ";
						for (int i = 0; i < 2; ++i)
						{
							cin >> _points[i].x;
							cin >> _points[i].y;
							cin >> _points[i].z;
						}
					}
					cout << "\n";
					const auto ptr = _figure.create_sphere(_points);
					figures.install_figure(ptr, _index);
					d = 1;
				}break;
				case 2:
				{
					cout << ": ";
					for (int i = 0; i < 3; ++i)
					{
						cin >> _points[i].x;
						cin >> _points[i].y;
						_points[i].z;
					}
					while (!(*_figure.create_cylinder(_points)).chek_points())
					{
						cout << "������� ������� ����������. ��������� �������: ";
						for (int i = 0; i < 3; ++i)
						{
							cin >> _points[i].x;
							cin >> _points[i].y;
							cin >>_points[i].z;
						}
					}
					cout << "\n";
					const auto ptr = _figure.create_cylinder(_points);
					figures.install_figure(ptr, _index);
					d = 1;
				}break;
				case 3:
				{
					cout << "������� ���������� ��������������� ����� ������: ";
					for (int i = 0; i < 2; ++i)
					{
						cin >> _points[i].x;
						cin >> _points[i].y;
						cin >> _points[i].z;
					}
					while (!(*_figure.create_parallelepiped(_points)).chek_points())
					{
						cout << "������� ������� ����������� ��������� �������: ";
						for (int i = 0; i < 2; ++i)
						{
							cin >> _points[i].x;
							cin >> _points[i].y;
							cin >> _points[i].z;
						}
					}
					cout << "\n";
					const auto ptr = _figure.create_parallelepiped(_points);
					figures.insert_figure(ptr, _index);
					d = 1;
				}break;
				}
			} while (d == 0);
		}break;
		case 3: {
			if (figures.get_size() <= 0)
			{
				cout << "������� �������� ������.\n";
			}
			else
			{
				int index;
				cout << "������� ������ ������, �������� �� ������ �������: ";
				cin >> index;
				while (index < 0 || index > figures.get_size())
				{
					cout << "������� ������ ������. ������� ������: ";
					cin >> index;
				}
				figures.del_item(index);
			}
		}break;
		case 4:
		{
			if (figures.get_size() <= 0)
			{
				cout << "������� �������� ������.\n";
			}
			else
			{
				int index;
				cout << "������� ������ ������, ������� ������� �� ������ �����: ";
				cin >> index;
				while (index < 0 || index > figures.get_size())
				{
					cout << "������� ������ ������. ��������� �������: ";
					cin >> index;
				}
				cout << "������� ������ �����: " << figures.get_index(index)->compute_area();
				cout << "\n";
			}
		}break;
		case 5:
		{
			if (figures.get_size() <= 0)
			{
				cout << "������� �������� ������.\n";
			}
			else
			{
				int index;
				cout << "������� ������ ������, ����� ������� �� ������ �����: ";
				cin >> index;
				while (index < 0 || index > figures.get_size())
				{
					cout << "������� ������ ������. ��������� �������: ";
					cin >> index;
				}
				cout << "����� ������ �����: " << figures.get_index(index)->compute_volume();
				cout << "\n";
			}
		}break;
		case 6:
		{
			if (figures.get_size() <= 0)
			{
				cout << "������� �������� ������.\n";
			}
			else
			{
				Figure max_figure = figures.IndexOfMaxVolume();
				cout << ": " << max_figure;
				cout << "\n";
			}
		}break;
		case 7: {
			if (figures.get_size() <= 0) {
				cout << "������� �������� ������.\n";
			}
			else {
				cout << figures;
			}
		}break;
		}
	} while (choise != 8);
	return 0;
}
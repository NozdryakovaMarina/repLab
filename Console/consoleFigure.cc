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
		cout << " |                              Меню                                |" << endl;
		cout << " ___________________________________________________________________" << endl;
		cout << " | 1 - добавить фигуру по индексу                                   |" << endl;
		cout << " | 2 - установка фигуры по индексу                                  |" << endl;
		cout << " | 3 - удалить фигуру по индексу                                    |" << endl;
		cout << " | 4 - рассчитать площадь                                           |" << endl;
		cout << " | 5 - рассчитать объем                                             |" << endl;
		cout << " | 6 - поиск в наборе первой фигуры с максимальным объемом          |" << endl;
		cout << " | 7 - вывести список фигур                                         |" << endl;
		cout << " | 8 - выйти из системы                                             |" << endl;
		cout << " -------------------------------------------------------------------" << endl;
	    cout << "Выберите, что вы хотите сделать: ";
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
			cout << "Укажите индекс фигуры, по которому хотите вставить фигуру: ";
			cin >> _index;
			while (_index < 0 || _index > figures.get_size())
			{
				cout << "Неверно введен индекс. Введите заново: ";
				cin >> _index;
			}
			cout << "\n";
			do {
				cout << "Введите фигуру, которую хотите добавить: \n1) Сфера \n2) Цилиндр \n3) Параллелепипед \nВаш выбор: ";
				cin >> _type;
				cout << "\n";
				switch (_type) {
				case 1: {
					cout << "Введите координаты сферы через пробел: ";
					for (int i = 0; i < 2; ++i)
					{
						cin >> _points[i].x;
						cin >> _points[i].y;
						cin >> _points[i].z;
					}
					while (!(*_figure.create_sphere(_points)).chek_points())
					{
						cout << "Неверно введены координаты. Повторите попытку: ";
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
					cout << "Введите координаты цилиндра через пробел: ";
					for (int i = 0; i < 3; ++i)
					{
						cin >> _points[i].x;
						cin >> _points[i].y;
						cin >> _points[i].z;
					}
					while (!(*_figure.create_cylinder(_points)).chek_points())
					{
						cout << "Неверно введены координаты. Повторите попытку: ";
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
					cout << "Введите координаты параллелепипеда через пробел: ";
					for (int i = 0; i < 2; ++i)
					{
						cin >> _points[i].x;
						cin >> _points[i].y;
						cin >> _points[i].z;
					}
					while (!(*_figure.create_parallelepiped(_points)).chek_points())
					{
						cout << "Неверно введены координатыю Повторите попытку: ";
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
			cout << "Укажите индекс фигуры, по которому хотите установить фигуру: ";
			cin >> _index;
			while (_index < 0 || _index > figures.get_size())
			{
				cout << "Неверно введен индекс. Повторите попытку: ";
				cin >> _index;
			}
			cout << "\n";
			do
			{
				cout << "Введите фигуру, которую хотите установить: \n1)Сфера  \n2)Цилиндр  \n3)Параллелепипед \nВаш выбор: ";
				cin >> _type;
				cout << "\n";
				switch (_type)
				{
				case 1:
				{
					cout << "Введите координаты сферы через пробел: ";
					for (int i = 0; i < 2; ++i)
					{
						cin >> _points[i].x;
						cin >> _points[i].y;
						cin >> _points[i].z;
					}
					while (!(*_figure.create_sphere(_points)).chek_points())
					{
						cout << "Неверное введены координаты. Повторите попытку: ";
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
						cout << "Неверно введены координаты. Повторите попытку: ";
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
					cout << "Введите координаты параллелепипеда через пробел: ";
					for (int i = 0; i < 2; ++i)
					{
						cin >> _points[i].x;
						cin >> _points[i].y;
						cin >> _points[i].z;
					}
					while (!(*_figure.create_parallelepiped(_points)).chek_points())
					{
						cout << "Неверно введены координатыю Повторите попытку: ";
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
				cout << "Сначала добавьте фигуры.\n";
			}
			else
			{
				int index;
				cout << "Укажите индекс фигуры, которыцю вы хотите удалить: ";
				cin >> index;
				while (index < 0 || index > figures.get_size())
				{
					cout << "Неверно указан индекс. Введите заново: ";
					cin >> index;
				}
				figures.del_item(index);
			}
		}break;
		case 4:
		{
			if (figures.get_size() <= 0)
			{
				cout << "Сначала добавьте фигуры.\n";
			}
			else
			{
				int index;
				cout << "Укажите индекс фигуры, площадь которой вы хотите найти: ";
				cin >> index;
				while (index < 0 || index > figures.get_size())
				{
					cout << "Неверно указан индекс. Повторите попытку: ";
					cin >> index;
				}
				cout << "Площадь фигуры равна: " << figures.get_index(index)->compute_area();
				cout << "\n";
			}
		}break;
		case 5:
		{
			if (figures.get_size() <= 0)
			{
				cout << "Сначала добавьте фигуры.\n";
			}
			else
			{
				int index;
				cout << "Укажите индекс фигуры, объем которой вы хотите найти: ";
				cin >> index;
				while (index < 0 || index > figures.get_size())
				{
					cout << "Неверно указан индекс. Повторите попытку: ";
					cin >> index;
				}
				cout << "Объем фигуры равен: " << figures.get_index(index)->compute_volume();
				cout << "\n";
			}
		}break;
		case 6:
		{
			if (figures.get_size() <= 0)
			{
				cout << "Сначала добавьте фигуры.\n";
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
				cout << "Сначала добавьте фигуры.\n";
			}
			else {
				cout << figures;
			}
		}break;
		}
	} while (choise != 8);
	return 0;
}
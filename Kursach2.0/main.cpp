#include <iostream>
#include <windows.h> 
#include "Shkola.h"
#include "Storage.h"

Shkola* menu;

Storage file("C:/Users/asuna/OneDrive/Рабочий стол/лщз/Kursov.txt");

int Check() 
{
	int num;
	while (!(std::cin >> num))
	{
		std::cin.clear();						
		while (std::cin.get() != '\n');			
		std::cout << "Ошибка ввода\n";
	}
	return num;
}

void addclas() 
{
	std::string name;
	menu->show();
	std::cout << "Введите имя нового класса: ";
	std::cin >> name;
	if (menu->addclas(name))
	{
		std::cout << "\nКласс добавлен\n ";
	}
	else {
		std::cout << "\nКласс не добавлен (очередь заполнена)\n";
	}
	menu->show();
}

void findclas() 
{
	std::string name;
	menu->show();
	std::cout << "Введите название класса, который нужно найти: ";
	std::cin >> name;
	if (menu->findclas(name))
		std::cout << "\nКласс найден\n";
	else
		std::cout << "\nКласс не найден\n";
}

void delclas() 
{
	if (menu->delclas()) 
	{
		std::cout << "\nКласс удален\n";
		menu->show();
	}
	else
		std::cout << "\nНечего удалять\n";
}

void adduchen() 
{
	int otvet = -1;
	std::string name, uchenik;
	std::string dr,li;
	menu->show();
	std::cout << "Введите имя класса, в которое необходимо добавить ученика: ";
	std::cin >> name;
	if (menu->findclas(name)) 
	{
		if (menu->chik(name))
		{
			std::cout << "\nВведите имя ученика: ";
			std::cin >> uchenik;
			std::cout << "\nВведите дату рождения: ";
			std::cin >> dr;
			if (menu->adduchen1(name, uchenik, dr))
			{
				std::cout << "\nУченик добавлен\n";
				menu->show();
			}
		}
		else 
		{
			std::cout << " Куда добавить нового ученика?\n 0 - Перед заданным именем\n 1 - После заданного имени\n";
			std::cin >> otvet;
			if (otvet == 0)
			{
				std::cout << "\n Перед каким элементом хотите поставить вводимый элемент?\n ";
				std::cin >> li;
				if (menu->finduchen(li))
				{
					std::cout << "\nУченик найден\n";
					std::cout << "\nВведите имя ученика: ";
					std::cin >> uchenik;
					std::cout << "\nВведите дату рождения: ";
					std::cin >> dr;
					if (menu->adduchen2(name, uchenik, dr,li))
					{
						std::cout << "\nУченик добавлен\n";
						menu->show();
					}
				}
				else
				{
					std::cout << "\nУченик не найден\n";
				}
			}
			else if (otvet == 1)
			{
				std::cout << "\nПосле какого элемента хотите поставить вводимый элемент?\n ";
				std::cin >> li;
				if (menu->finduchen(li))
				{
					std::cout << "\nУченик найден\n";
					std::cout << "\nВведите имя ученика: ";
					std::cin >> uchenik;
					std::cout << "\nВведите дату рождения: ";
					std::cin >> dr;
					if (menu->adduchen3(name, uchenik, dr,li))
					{
						std::cout << "\nУченик добавлен\n";
						menu->show();
					}
				}
				else
				{
					std::cout << "\nУченик не найден\n";
				}

			}

		}
		
		
	}
	else
		std::cout << "\nТакого класса не существует\n";
}

void finduchen()
{
	std::string _text;
	menu->show();
	std::cout << "\nВведите имя ученика, которого необходимо найти: ";
	std::cin >> _text;
	if (menu->finduchen(_text))
		std::cout << "\nУченик найден\n";
	else
		std::cout << "\nУченик не найден\n";
}

void deluchen()
{
	std::string _text;
	menu->show();
	std::cout << "Введите имя ученика,информацию о котором хотите удалить: ";
	std::cin >> _text;
	if (menu->deluchen(_text)) 
	{
		std::cout << "\nИнформация об ученике удалена\n";
		menu->show();
	}
}

void mainMenu() 
{
	menu = new Shkola();
	std::string headline = "";
	if (!file.InputData(menu)) 
	{
		std::cout << "Файл не найден\n";
		std::cout << "Введите номер школы:\n ";
		std::cin >> headline;
		menu->setHead(headline);
	}
	menu->show();
	int n;
	while (true) 
	{
		std::cout << "1. Добавить новый класс\n";
		std::cout << "2. Найти необходимый класс\n";
		std::cout << "3. Удалить класс\n";
		std::cout << "4. Добавить ученика\n";
		std::cout << "5. Найти ученика\n";
		std::cout << "6. Удалить ученика\n";
		std::cout << "7. Изменить номер школы\n";
		std::cout << "8. Очистить школьный список\n";
		std::cout << "0. Выход из программы\n";
		std::cout << "Выберите необходимую цифру:\n";
		n = Check();
		while (n < 0 || n > 8) 
		{
			std::cout << "Ошибка ввода\nВыберите необходимую цифру:\n";
			n = Check();
		}
		if (n == 1)
			addclas();
		else if (n == 2)
			findclas();
		else if (n == 3)
			delclas();
		else if (n == 4)
		{
			adduchen();		
		}
		else if (n == 5)
			finduchen();
		else if (n == 6)
			deluchen();
		else if (n == 7) 
		{
			std::cout << "Введите новый номер школы:\n ";
			std::cin >> headline;
			menu->setHead(headline);
			menu->show();
		}
		else if (n == 8) 
		{
			delete menu;
			std::cout << "Школьный список удален!";
			std::cout << "Введите номер школы, для которой хотите создать список классов и учеников:\n ";
			std::cin >> headline;
			menu = new Shkola(headline);
			menu->show();
		}
		else if (n == 0) {
			std::cout << "Сохранить изменения в файл? (1 - да, 0 - нет)\n";
			n = Check();
			while ((n < 0) || (n > 1)) {
				std::cout << "Ошибка ввода\n Введите вновь: ";
				n = Check();
			}
			std::cout << "\n";
			if (n == 1) {
				if (file.OutputData(menu))
					std::cout << "Данные успешно записаны в файл\n";
				else
					std::cout << "Ошибка сохранения в файл\n";
			}
			break;
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	mainMenu();
}

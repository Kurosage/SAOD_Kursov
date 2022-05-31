#pragma once
#pragma warning(disable:4996)
#include "Shkola.h"
#include <fstream>
#include <iostream>

class Storage
{
	private:
		std::string address;
	public:
		Storage(std::string _address) 
		{
			address = _address;
		};

		bool InputData(Shkola* _menu) 
		{
			std::string text, name,dr;
			char buffer[100];
			char* str;
			std::ifstream file(address);

			if (!file.is_open())
				return false;

			if (!file.eof()) 
			{				
				file.getline(buffer, 100);	
				text = buffer;
				_menu->setHead(text);
			}
			else 
			{
				std::cout << "Файл пуст\n";
				return false;
			}
			while (!file.eof()) 
			{
				file.getline(buffer, 100);	
				str = strtok(buffer, " ");	
				if (str == NULL)			
					continue; 
				if (str)
					name = str;
				_menu->addclas(name);	
				str = strtok(NULL, " ");	
				while (str) 
				{				
					if (str)
						text = str;
					str = strtok(NULL, " ");	
					if ((str))
						dr = str;
					else
						return false;
					_menu->adduchen(name, text, dr);   
					str = strtok(NULL, " ");			
				}
			}
			file.close();
			return true;
		}

		bool OutputData(Shkola* _menu) {
			std::ofstream file(address);
			if (!file.is_open())
				return false;
			file << _menu->GetString();
			file.close();
			return true;
		};

		~Storage() { };
};


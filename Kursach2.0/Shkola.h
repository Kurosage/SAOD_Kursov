#pragma once
#include <iostream>
#include "compclas.h"

class Shkola {
	private:
		compclas Classes;
		std::string nomer;
	public:
		Shkola() 
		{
			nomer = "15";
		}

		Shkola(std::string _head) 
		{
			nomer = _head;
		}

		void setHead(std::string _head) 
		{
			nomer = _head;
		}

		std::string getHead() 
		{
			return nomer;
		}

		bool addclas(std::string _text) 
		{
			return Classes.addclas(_text);
		}

		bool findclas(std::string _text) 
		{
			return Classes.findclas(_text);
		}
		bool chik(std::string _text)
		{
			return Classes.chik(_text);
		}
	
		bool delclas() 
		{
			return Classes.delclas();
		}
	
		bool adduchen(std::string _name, std::string _text, std::string _dr)
		{
			return Classes.adduchen(_name, _text, _dr);
		}
		bool adduchen1(std::string _name, std::string _text, std::string _dr)
		{
			return Classes.adduchen1(_name, _text, _dr);
		}
		bool adduchen2(std::string _name, std::string _text, std::string _dr,std::string _li)
		{
			return Classes.adduchen2(_name, _text, _dr,_li);
		}
		bool adduchen3(std::string _name, std::string _text, std::string _dr, std::string _li)
		{
			return Classes.adduchen3(_name, _text, _dr, _li);
		}
		bool finduchen(std::string _text) 
		{
			return Classes.finduchen(_text);
		}

		bool deluchen(std::string _text) 
		{
			return Classes.deluchen(_text);
		}

		void show() { 
			std::cout << "\n|___________________________________________________________|\n";
			std::cout << "|         Школа № " << nomer << "";
			std::cout << "\n|___________________________________________________________|";
			std::cout << "\n|   Имя класса  |" << "    ФИО           Дата рождения \n";
			Classes.showclasses();
			std::cout << "|___________________________________________________________|\n";
		}

		std::string GetString() { 
			return nomer + '\n' + Classes.GetString();
		};

	~Shkola() {};
};


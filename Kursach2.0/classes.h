#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Uchenik.h"

const int maxuch = 10;					

class classs 
{
private:
	struct classsData
	{
		std::string text;					
		uchenik ucheniki[maxuch];			
		int count = 0;						
	}etclass;
public:
	classs() 
	
	{
		etclass.ucheniki[0].setData("<ПУСТО>", " ");
		etclass.text = "<ПУСТО>";
	}

	classs(std::string _text) 
	{
		etclass.ucheniki[0].setData("<ПУСТО>", " ");
		etclass.text = _text;
	}

	void setText(std::string _text)
	{
		etclass.text = _text;
	}

	std::string getText() 
	{
		return etclass.text;
	}
	bool adduchen(std::string _text, std::string _dr)
	{
		bool flag = true;
		int i = 1;
		if (etclass.count >= maxuch - 1)
		{
			std::cout << "Добавление невозможно, список заполнен\n";
			return false;
		}
		else {
			if (etclass.ucheniki[0].getText() == "<ПУСТО>")
			{
				etclass.ucheniki[0].setData(_text, _dr);
			}
			else
			{
				etclass.ucheniki[etclass.count].setData(_text, _dr);
			}
			etclass.count++;
			return true;
		}
	}
	bool adduchen1(std::string _text, std::string  _dr) 
	{		
		etclass.ucheniki[0].setData(_text, _dr);
		etclass.count++;
		return true;
	}
	bool adduchen2(std::string _text, std::string  _dr, std::string _li)
	{
		if (etclass.count >= maxuch - 1)
		{
			std::cout << "Добавление невозможно, список заполнен\n";
			return false;
		}
		else
		{
			for (int i = 0; i < etclass.count; i++)
			{
				if (_li == etclass.ucheniki[i].getText())
				{
					for (int j = etclass.count; j > i; j--)
					{		
						etclass.ucheniki[j].setData(etclass.ucheniki[j - 1].getText(), etclass.ucheniki[j - 1].getdr());
					}
					etclass.ucheniki[i].setData(_text, _dr);	
					break;
				}
			}
			etclass.count++;
			return true;
		}
	}
	bool adduchen3(std::string _text, std::string  _dr, std::string _li)
	{
	
		if (etclass.count >= maxuch - 1)
		{
			std::cout << "Добавление невозможно, список заполнен\n";
			return false;
		}
		else
		{
			for (int i = 0; i < etclass.count; i++)
			{
				if (_li == etclass.ucheniki[i].getText())
				{
					for (int j = etclass.count; j > i+1; j--)
					{
						etclass.ucheniki[j].setData(etclass.ucheniki[j - 1].getText(), etclass.ucheniki[j - 1].getdr());
					}
					etclass.ucheniki[i+1].setData(_text, _dr);
					break;
				}
			}
			etclass.count++;
			return true;
		}
	}
	bool chik()
	{
		if (etclass.count == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool finduchen(std::string _text) 
	{
		for (int i = 0; i < etclass.count; i++) 
		{
			if (_text == etclass.ucheniki[i].getText())
			{
				return true;
			}
		}
		return false;
	}

	bool deluchen(std::string _text) 
	{
		if (etclass.count == 0) 
		{										
			std::cout << "Удаление невозможно, список пуст\n";
			return false;
		}
		else 
		{
			for (int i = 0; i < etclass.count; i++)
			{
				if (etclass.ucheniki[i].getText() == _text) 
				{
					for (int j = i; j < etclass.count; j++) 
					{			
						etclass.ucheniki[j].setData(etclass.ucheniki[j + 1].getText(), etclass.ucheniki[j + 1].getdr());
					}
					etclass.count--;
					return true;
				}
			}
		}
		return false;
	}

	bool showUchenik()
	{
		if (etclass.count == 0)
		{										
			return false;
		}
		else {
			for (int i = 0; i < etclass.count; i++)
			{
				if (i >= 1)
					std::cout << "|" << std::setw(16) << std::right << "|";
				std::cout << std::setw(20) << std::left << etclass.ucheniki[i].getText() << "  " << std::right << etclass.ucheniki[i].getdr() << "\n";
			}
		}
		return true;
	}

	std::string GetString() 
	{
		std::string str = "";
		for (int i = 0; i < etclass.count; i++)
		{
			std::stringstream ss;
			ss << etclass.ucheniki[i].getText();
			str += " ";
			str += ss.str();
			str += " ";
			str += etclass.ucheniki[i].getdr();
		}
		return str;
	};

	~classs() {};
};


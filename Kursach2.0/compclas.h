#pragma once
#include <iostream>
#include "classes.h"

const int maxcl = 10;				

class compclas
{
private:
	classs classes[maxcl];		
	int first, last, count = 0;	
public:
	compclas()
	{
		last = 0;
		first = 0;
	}
	bool addclas(std::string _text) 
	{
		if (count == maxcl - 1) 
		{		
			return false;
		}
		else 
		{
			classes[last].setText(_text);
			last++;
			count++;
			return true;
		}
	}

	bool findclas(std::string _text)
 {
		for (int i = 0; i < count; i++) 
		{
			if (_text == classes[i].getText())
				return true;
		}
		return false;
	}

	bool delclas() 
	{
		if (count == 0) 
		{				
			return false;
		}
		else {
			for (int i = 0; i < last; i++) 
			{
				classes[i] = classes[i + 1];
			}
			last--;
			count--;
			return true;
		}
	}
	bool adduchen(std::string _name, std::string _text, std::string _dr) 
	{
		int i;
		for (i = 0; i < count; i++) 
		{				
			if (_name == classes[i].getText()) 
			{
				break;
			}
		}
		if (classes[i].adduchen(_text, _dr)) 
		{	
			return true;
		}
		return false;
	}
	bool adduchen1(std::string _name, std::string _text, std::string _dr)
	{
		int i;
		for (i = 0; i < count; i++)
		{
			if (_name == classes[i].getText())
			{
				break;
			}
		}
		if (classes[i].adduchen1(_text, _dr))
		{
			return true;
		}
		return false;
	}
	bool adduchen2(std::string _name, std::string _text, std::string _dr, std::string _li)
	{
		int i;
		for (i = 0; i < count; i++)
		{
			if (_name == classes[i].getText())
			{
				break;
			}
		}
		if (classes[i].adduchen2(_text, _dr,_li))
		{
			return true;
		}
		return false;
	}
	bool adduchen3(std::string _name, std::string _text, std::string _dr, std::string _li)
	{
		int i;
		for (i = 0; i < count; i++)
		{
			if (_name == classes[i].getText())
			{
				break;
			}
		}
		if (classes[i].adduchen3(_text, _dr,_li))
		{
			return true;
		}
		return false;
	}
	bool chik(std::string _name)
	{
		int i;
		for (i = 0; i < count; i++)
		{
			if (_name == classes[i].getText())
			{
				break;
			}
		}
		if (classes[i].chik())
		{
			return true;
		}
		return false;
	}
	bool finduchen(std::string _text) 
	{
		for (int i = 0; i < count; i++) 
		{
			if (classes[i].finduchen(_text))		
				return true;
		}
		return false;
	}

	bool deluchen(std::string _text) 
	{
		for (int i = 0; i < count; i++) 
		{
			if (classes[i].deluchen(_text))		
				return true;
		}
		return false;
	}

	void showclasses()
	{
		if (count == 0) 
		{
			return;
		}
		for (int i = 0; i < count; i++) 
		{
			std::cout << "|___________________________________________________________|\n";
			std::cout << "|" << std::setw(8) << classes[i].getText() << std::setw(8) << "|";
			if (!(classes[i].showUchenik()))
				std::cout << "\n";
		}
	}
	std::string GetString()
	{
		std::string str = "";
		for (int i = 0; i < count; i++)
		{
			std::stringstream ss;
			ss << classes[i].getText();
			str += ss.str();
			str += classes[i].GetString();
			str += '\n';
		}
		return str;
	}

	~compclas() {}
};


#pragma once
#include <iostream>

class uchenik 
{
private:
	struct uchenikData 
	{
		std::string text;						
		std::string dr;
	}etuchenik;
public:
	uchenik()
	{
		etuchenik.text = "<осярн>";
		etuchenik.dr = ' ';
	}

	uchenik(std::string _text, std::string _dr)
	{
		etuchenik.text = _text;
		etuchenik.dr = _dr;
	}

	void setData(std::string _text, std::string _dr)
	{
		etuchenik.text = _text;
		etuchenik.dr = _dr;
	}

	std::string getText() 
	{
		return etuchenik.text;
	}

	std::string getdr()
	{
		return etuchenik.dr;
	}

	~uchenik() {}
};


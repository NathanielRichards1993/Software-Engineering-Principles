#include "Menu.h"


Menu::Menu(void)
{
	numItems = 0;
}


Menu::~Menu(void)
{
}

void Menu::addItem(string item)
{
	if (numItems != 2) //checks if the array has reach its limit
	{
		items[numItems] = item;
		numItems++;
	}
	else
	{
		cout<<"Max items reached\n";
	}
}

void Menu::input(char* c)
{

}
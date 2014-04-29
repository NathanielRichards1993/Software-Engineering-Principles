#pragma once
#include <iostream>
using namespace std;
//#define MAX_ITEMS 2; Temporarily commented out due to bugs

class Menu
{
public:
	int selection;
	string items[2];
	int numItems;

	Menu(void);
	~Menu(void);
	void input(char* c);
	virtual void draw(){};
	void addItem(string item);
};


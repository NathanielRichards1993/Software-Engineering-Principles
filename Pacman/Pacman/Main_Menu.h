#pragma once

#include<string>
using namespace std;

class Main_Menu
{
public:
	Main_Menu(void);
	~Main_Menu(void);
	void update(void);
	void draw(void);
	void input(char*);
	void addItem(string);
};


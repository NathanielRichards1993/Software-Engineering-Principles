#pragma once
#include "menu.h"
class Main_Menu :
	public Menu
{
public:
	Main_Menu(void);
	~Main_Menu(void);
	void update();
	void draw();
};


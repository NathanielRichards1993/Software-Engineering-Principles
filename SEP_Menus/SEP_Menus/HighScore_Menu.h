#pragma once
#include "menu.h"
class HighScore_Menu :
	public Menu
{
public:
	HighScore_Menu(void);
	~HighScore_Menu(void);
	void update();
	void draw();
};


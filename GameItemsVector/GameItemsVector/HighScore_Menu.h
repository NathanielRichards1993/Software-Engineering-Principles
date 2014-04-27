#pragma once
class HighScore_Menu
{
public:
	HighScore_Menu(void);
	~HighScore_Menu(void);
	void update(void);
	void draw(void);
	void input(char*);
	void addItem(string);
};


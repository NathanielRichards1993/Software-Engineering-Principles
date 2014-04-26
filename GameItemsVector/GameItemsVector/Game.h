#pragma once
#pragma once

#include<string>

#include"Item.h"
#include"Player.h"
#include"Enemy.h"
#include"Main_Menu.h"
#include"HighScore_Menu.h"

#define MAX_ITEMS 244
#define MAX_ENEMIES 4

using namespace std;

class Game
{
private:
	// score should never go below 0.
	unsigned int score;

	//Pointers to access/use enemies, items, player, main menu and highscore menu.
	Enemy* enemies[MAX_ITEMS];
	Item* items[MAX_ITEMS];
	Player* pPlayer;
	Main_Menu* main;
	HighScore_Menu* highScore;

public:
	Game(void);
	~Game(void);

	int getScore(void);
	void loadLevel(string);
	void update();
};

